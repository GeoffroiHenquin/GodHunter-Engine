/**
 * @file ecs.h
 * This file is part of the GodHunter Engine
 *
 * This file declare an Entity Component System.
 *
 * MIT License
 *
 * Copyright (c) 2025 GeoffroiHenquin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

// Related header

// C system headers

// C++ standard library headers
#include <array> // std::array
#include <cassert> // assert
#include <cstddef> // std::size_t
#include <cstring> // memset
#include <functional> // std::function
#include <map> // std::map
#include <memory> // std::shared_ptr
#include <tuple> // std::tuple
#include <type_traits>
#include <typeindex> // std::type_index
#include <unordered_map> // std::unordered_map
#include <vector> // std::vector

// Third party libraries headers

// Project headers

// Exceptions

#ifndef GODHUNTER_ENGINE_ECS_H_
#define GODHUNTER_ENGINE_ECS_H_

namespace godhunter
{

    // ECS Size ----------------------------------------------------------------

    enum Size
	{
        DYNAMIC = -1,
		MAX_COMPONENTS = 32,
		MAX_ENTITIES = 5000
	};

    // Entity ------------------------------------------------------------------

    // Entity (Entity is represented by an index)
    typedef std::size_t entity_t;

    // Entity Manager (Dynamic)
    class EntityManager
    {
    private:
        godhunter::entity_t m_next_entity;
        std::vector<godhunter::entity_t> m_free_list;
#ifndef NDEBUG
        std::unordered_map<godhunter::entity_t, bool> m_free_list_checked;
#endif // !NDEBUG
    public:
        EntityManager() : m_next_entity(0)
        {

        }
        ~EntityManager()
        {

        }

        godhunter::entity_t create()
        {
            if (!m_free_list.empty())
            {
                godhunter::entity_t entity = m_free_list.back();
#ifndef NDEBUG
                m_free_list_checked[entity] = false;
#endif // !NDEBUG
                m_free_list.pop_back();
                return entity;
            }
            return m_next_entity++;
        }
        void destroy(godhunter::entity_t entity_)
        {
            assert(entity_ >= 0 && "The entity manager cannot destroy this entity.");
#ifndef NDEBUG
            assert(!(m_free_list_checked[entity_]) && "This entity is already destroyed.");
            m_free_list_checked[entity_] = true;
#endif // !NDEBUG
            m_free_list.push_back(entity_);
        }
        void reserve(std::size_t size_)
        {
            m_free_list.reserve(size_);
#ifndef NDEBUG
			m_free_list_checked.reserve(size_);
#endif // !NDEBUG
        }
        void clear()
        {
            m_next_entity = 0;
            m_free_list.clear();
#ifndef NDEBUG
            m_free_list_checked.clear();
#endif // !NDEBUG
        }
    };

    // Component --------------------------------------------------------

    // Component Array (Dynamic)
    template <typename T>
    class ComponentArray
    {
    private:
        std::vector<T> m_components;
        std::map<godhunter::entity_t, std::size_t> m_entity_to_index;
        std::unordered_map<std::size_t, godhunter::entity_t> m_index_to_entity;

    public:
        void addComponent(godhunter::entity_t entity_, T component_)
        {
            m_components.push_back(component_);
            m_entity_to_index[entity_] = m_components.size() - 1;
            m_index_to_entity[m_components.size() - 1] = entity_;
        }
        void removeComponent(godhunter::entity_t entity_)
        {
            // Step 1: Place last element in the removed element's place
			std::size_t index = m_entity_to_index[entity_];
			std::size_t last_index = m_components.size() - 1;
			m_components[index] = m_components[last_index];

            // Step 2: Remove the last element
            m_components.pop_back();

            // Step 3: Find the entity with the highest value in the map

            godhunter::entity_t entity_with_highest_value = m_index_to_entity[last_index];

            // Step 4: Replace the value of the element with the highest value with the value of the removed element
			m_entity_to_index[entity_with_highest_value] = index;

            // Step 5: Remove the entity from the map
            m_entity_to_index.erase(entity_);

            // Step 6: Remove the entity from the unordered_map
            m_index_to_entity[index] = entity_with_highest_value;
            m_index_to_entity.erase(last_index);
        }
        bool hasComponent(godhunter::entity_t entity_) const
        {
            return m_entity_to_index.find(entity_) != m_entity_to_index.end();
        }

        T& getComponent(godhunter::entity_t entity_)
        {
            return m_components[m_entity_to_index[entity_]];
        }
        godhunter::entity_t getEntityFromComponent(T& component_) const
        {
            for (std::size_t i = 0; i < m_components.size(); i++)
            {
				if (&m_components[i] == &component_)
				{
                    return m_index_to_entity.at(i);
				}
            }
            return -1;
        }
        godhunter::entity_t getEntityFromIndex(std::size_t& index_) const
        {
            return m_index_to_entity.at(index_);
        }

        std::vector<T>& getAllComponents()
        {
            return m_components;
        }
        std::size_t size() const
        {
            return m_components.size();
        }
        void reserve(std::size_t size_)
        {
            m_components.reserve(size_);
        }
        void clear()
        {
            m_components.clear();
            m_entity_to_index.clear();
            m_index_to_entity.clear();
        }
    };

    // Component Manager
    class ComponentManager
    {
    private:
        std::unordered_map<std::type_index, std::shared_ptr<void>> m_component_arrays;
        std::vector<std::function<void(godhunter::entity_t)>> m_remove_component_functions;
    public:
        template <typename T>
        void registerComponent()
        {
            m_component_arrays[typeid(T)] = std::make_shared<godhunter::ComponentArray<T>>();

			godhunter::ComponentArray<T>& component_array = *static_cast<godhunter::ComponentArray<T>*>(m_component_arrays[typeid(T)].get());
            m_remove_component_functions.push_back([&component_array](godhunter::entity_t entity_) { component_array.removeComponent(entity_); });
        }

        template <typename T>
        void addComponent(godhunter::entity_t entity_, T component_)
        {
            getComponentArray<T>().addComponent(entity_, component_);
        }

        template <typename T>
        void removeComponent(godhunter::entity_t entity_)
        {
            getComponentArray<T>().removeComponent(entity_);
        }

        void removeAllComponents(godhunter::entity_t entity_) // TODO: Fix this function
        {
            for (auto& delete_function : m_remove_component_functions) delete_function(entity_);
        }

        void clear()
        {
            for (auto& component_array : m_component_arrays) {
                auto component_ptr = std::static_pointer_cast<ComponentArray<void*>>(component_array.second);
                component_ptr->clear();
            }
        }

        template <typename T>
        T& getComponent(godhunter::entity_t entity_)
        {
            return getComponentArray<T>().getComponent(entity_);
        }

        template <typename T>
        bool hasComponent(godhunter::entity_t entity_)
        {
            return getComponentArray<T>().hasComponent(entity_);
        }

		template <typename T>
        godhunter::ComponentArray<T>& getComponentArray()
        {
            return *static_cast<godhunter::ComponentArray<T>*>(m_component_arrays[typeid(T)].get());
        }
    };

    // System ------------------------------------------------------------------

	// System helper to check if a class has a method (init)
    template <typename, typename = std::void_t<>>
    struct HasInitMethod
    {
        static constexpr bool value = false;
    };
    template <typename T>
    struct HasInitMethod<T, std::void_t<decltype(std::declval<T>().init(std::declval<godhunter::ComponentManager&>()))>>
    {
        static constexpr bool value = true;
    };

    // System helper to check if a class has a method (update)
    template <typename, typename = std::void_t<>>
    struct HasUpdateMethod
    {
        static constexpr bool value = false;
    };
    template <typename T>
    struct HasUpdateMethod<T, std::void_t<decltype(std::declval<T>().update(std::declval<godhunter::ComponentManager&>()))>>
    {
        static constexpr bool value = true;
    };

    // System helper to check if a class has a method (render)
    template <typename, typename = std::void_t<>>
    struct HasRenderMethod
    {
        static constexpr bool value = false;
    };
    template <typename T>
    struct HasRenderMethod<T, std::void_t<decltype(std::declval<T>().render(std::declval<godhunter::ComponentManager&>()))>>
    {
        static constexpr bool value = true;
    };

	// System Manager
    class SystemManager {
        std::vector<std::function<void(godhunter::ComponentManager&)>> m_init_systems;
        std::vector<std::function<void(godhunter::ComponentManager&)>> m_update_systems;
        std::vector<std::function<void(godhunter::ComponentManager&)>> m_render_systems;

    public:
        template <typename T>
        void registerSystem(T& system_)
        {
			if constexpr (HasInitMethod<T>::value)
            {
                m_init_systems.push_back([&system_](godhunter::ComponentManager& cm) { system_.init(cm); });
			}

            if constexpr (HasUpdateMethod<T>::value)
            {
                m_update_systems.push_back([&system_](godhunter::ComponentManager& cm) { system_.update(cm); });
            }

            if constexpr (HasRenderMethod<T>::value)
            {
                m_render_systems.push_back([&system_](godhunter::ComponentManager& cm) { system_.render(cm); });
            }
        }

        void runInitSystems(godhunter::ComponentManager& component_manager_)
        {
            for (auto& system : m_init_systems) system(component_manager_);
        }

        void runUpdateSystems(godhunter::ComponentManager& component_manager_)
        {
            for (auto& system : m_update_systems) system(component_manager_);
        }

        void runRenderSystems(godhunter::ComponentManager& component_manager_)
        {
            for (auto& system : m_render_systems) system(component_manager_);
        }
    };

	// Entity Component System --------------------------------------------------

	class EntityComponentSystem
	{
    private:
        godhunter::EntityManager m_entity_manager;
        godhunter::ComponentManager m_component_manager;
		godhunter::SystemManager m_system_manager;

    public:
		// --- Constructors & Destructors ---
        EntityComponentSystem()
        {
        }
        ~EntityComponentSystem()
        {
        }

        // --- Getters ---
        godhunter::EntityManager& getEntityManager()
        {
            return m_entity_manager;
		}
        godhunter::ComponentManager& getComponentManager()
        {
            return m_component_manager;
        }
        godhunter::SystemManager& getSystemManager()
        {
            return m_system_manager;
		}

        // --- Entity methods ---
        godhunter::entity_t createEntity()
        {
            return m_entity_manager.create();
        }

		// --- Component methods ---
        template <typename T>
        void registerComponent()
        {
            m_component_manager.registerComponent<T>();
        }
        template <typename T>
        void addComponent(godhunter::entity_t entity_, T component_)
        {
            m_component_manager.addComponent<T>(entity_, component_);
        }
        template <typename T>
        void removeComponent(godhunter::entity_t entity_)
        {
            m_component_manager.removeComponent<T>(entity_);
        }
        template <typename T>
        T& getComponent(godhunter::entity_t entity_)
        {
            return m_component_manager.getComponent<T>(entity_);
        }
        template <typename T>
        bool hasComponent(godhunter::entity_t entity_)
        {
            return m_component_manager.hasComponent<T>(entity_);
        }

		// --- System methods ---
        template <typename T>
        void registerSystem(T& system_)
        {
            m_system_manager.registerSystem<T>(system_);
        }
        void runInitSystems()
        {
            m_system_manager.runInitSystems(m_component_manager);
        }
        void runUpdateSystems()
        {
            m_system_manager.runUpdateSystems(m_component_manager);
        }
        void runRenderSystems()
        {
            m_system_manager.runRenderSystems(m_component_manager);
		}

		// --- ECS methods ---
        void destroyEntity(godhunter::entity_t entity_)
        {
            m_component_manager.removeAllComponents(entity_);
            m_entity_manager.destroy(entity_);
        }
        void clear()
        {
            m_entity_manager.clear();
            m_component_manager.clear();
        }
	};

} // namespace godhunter

#endif // GODHUNTER_ENGINE_ECS_H_