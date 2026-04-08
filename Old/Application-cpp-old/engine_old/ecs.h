/**
 * @file ecs.h
 * This file is part of the GodHunter Engine
 *
 * This file declare an Entity Component System.
 *
 * MIT License
 *
 * Copyright (c) 2024 GeoffroiHenquin
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
#include <cassert> // assert
#include <cstddef> // std::size_t
#include <functional> // std::function
#include <memory> // std::shared_ptr
#include <string> // std::string
#include <typeindex> // std::type_index
#include <unordered_map> // std::unordered_map
#include <vector> // std::vector

// Third party libraries headers

// Project headers

// Exceptions

#ifndef GODHUNTER_SRC_GODHUNTER_ECS_H_
#define GODHUNTER_SRC_GODHUNTER_ECS_H_

namespace godhunter
{

    // Data manager
    class DataManager
    {
    private:
        std::unordered_map<std::string, void*> m_data;
    public:
        template <typename T>
        void registerData(const std::string& data_name_, T& data_)
        {
			m_data[data_name_] = &data_;
        }

        template <typename T>
        T& getData(const std::string& data_name_)
        {
			return *static_cast<T*>(m_data[data_name_]);
        }
    };

	// Entity
	using Entity = std::size_t;

	// Entity Manager
    class EntityManager
    {
    private:
        godhunter::Entity m_next_entity;
        std::vector<godhunter::Entity> m_free_list;
    public:
        EntityManager();
        ~EntityManager();

        godhunter::Entity create();
        void destroy(godhunter::Entity entity_);
        void clear();
    };

    // Component array
    template <typename T>
    class ComponentArray
    {
    private:
        std::vector<T> m_components;
        std::unordered_map<godhunter::Entity, std::size_t> m_entity_to_index;
        std::unordered_map<std::size_t, godhunter::Entity> m_index_to_entity;
        std::size_t m_size = 0;
    public:
        void addComponent(godhunter::Entity entity_, T component_) { // void cannot be used as a parameter
            assert(m_entity_to_index.find(entity_) == m_entity_to_index.end() && "Entity already has this component!");
            if (m_size >= m_components.size()) m_components.push_back(component_);
            else m_components[m_size] = component_;
            m_entity_to_index[entity_] = m_size;
            m_index_to_entity[m_size] = entity_;
            ++m_size;
        }

        void removeComponent(godhunter::Entity entity_) {
            assert(m_entity_to_index.find(entity_) != m_entity_to_index.end() && "Entity does not have this component!");
            std::size_t index = m_entity_to_index[entity_];
            std::size_t last_index = --m_size;
            m_components[index] = m_components[last_index];
            godhunter::Entity last_entity = m_index_to_entity[last_index];
            m_entity_to_index[last_entity] = index;
            m_index_to_entity[index] = last_entity;
            m_entity_to_index.erase(entity_);
            m_index_to_entity.erase(last_index);
        }

        T& getComponent(godhunter::Entity entity_) { // Cannot create reference to void
            assert(m_entity_to_index.find(entity_) != m_entity_to_index.end() && "Entity does not have this component!");
            return m_components[m_entity_to_index[entity_]];
        }

        bool hasComponent(godhunter::Entity entity_) const {
            return m_entity_to_index.find(entity_) != m_entity_to_index.end();
        }

        std::vector<T>& getAllComponents() { return m_components; }

        godhunter::Entity getEntity(T& component_) const { return m_index_to_entity.at(m_entity_to_index.at(component_)); } // Cannot create reference to void

        void clear() {
			m_components.clear();
			m_entity_to_index.clear();
			m_index_to_entity.clear();
			m_size = 0;
		}
    };

    // Component manager
    class ComponentManager {
        std::unordered_map<std::type_index, std::shared_ptr<void>> m_component_arrays;

    public:
        template <typename T>
        void registerComponent() {
            m_component_arrays[typeid(T)] = std::make_shared<godhunter::ComponentArray<T>>();
        }

        template <typename T>
        void addComponent(godhunter::Entity entity_, T component_) {
            getComponentArray<T>()->addComponent(entity_, component_);
        }

        template <typename T>
        void removeComponent(godhunter::Entity entity_) {
            getComponentArray<T>()->removeComponent(entity_);
        }

        void removeAllComponents(godhunter::Entity entity_) {
            for (auto& component_array : m_component_arrays) {
                auto component_ptr = std::static_pointer_cast<ComponentArray<void*>>(component_array.second);
                if (component_ptr->hasComponent(entity_))
                {
                    component_ptr->removeComponent(entity_);
                }
            }
        }

        void clear() {
            for (auto& component_array : m_component_arrays) {
                auto component_ptr = std::static_pointer_cast<ComponentArray<void*>>(component_array.second);
                component_ptr->clear();
            }
        }

        template <typename T>
        T& getComponent(godhunter::Entity entity_) {
            return getComponentArray<T>()->getComponent(entity_);
        }

        template <typename T>
        bool hasComponent(godhunter::Entity entity_) const {
            return getComponentArray<T>()->hasComponent(entity_);
        }

        template <typename T>
        std::vector<T>& getAllComponents() {
            return getComponentArray<T>()->getAllComponents();
        }

        template <typename T>
        godhunter::Entity getEntity(T& component_) {
            return getComponentArray<T>()->getEntity(component_);
        }

    private:
        template <typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray() const {
            return std::static_pointer_cast<godhunter::ComponentArray<T>>(m_component_arrays.at(typeid(T)));
        }
    };

    // System manager
    class SystemManager {
        std::vector<std::function<void(godhunter::ComponentManager&)>> m_update_systems;
        std::vector<std::function<void(godhunter::ComponentManager&)>> m_render_systems;

    public:
        template <typename T>
        void registerSystem(T& system_) {
            m_update_systems.push_back([&system_](godhunter::ComponentManager& cm) { system_.update(cm); });
            m_render_systems.push_back([&system_](godhunter::ComponentManager& cm) { system_.render(cm); });
        }

        template <typename T>
        void registerUpdateSystem(T& system_) {
            m_update_systems.push_back([&system_](godhunter::ComponentManager& cm) { system_.update(cm); });
        }

        template <typename T>
        void registerRenderSystem(T& system_) {
            m_render_systems.push_back([&system_](godhunter::ComponentManager& cm) { system_.render(cm); });
        }

        void runUpdateSystems(godhunter::ComponentManager& component_manager_);

        void runRenderSystems(godhunter::ComponentManager& component_manager_);
    };

    // Prefab manager
    class PrefabManager
    {
    
    };

    // Scene manager
    class SceneManager
    {
    private:
		std::unordered_map<std::string, std::function<void()>> m_scenes;
    public:
        void registerScene(const std::string& scene_name_, std::function<void()> load_scene_function_);
        void loadScene(const std::string& scene_name_);
    };

    // ECS
    struct EntityComponentSystem {
        godhunter::DataManager data_manager;
		godhunter::EntityManager entity_manager;
		godhunter::ComponentManager component_manager;
		godhunter::SystemManager system_manager;
        godhunter::PrefabManager prefab_manager;
        godhunter::SceneManager scene_manager;
	} inline g_ecs;

    inline godhunter::EntityComponentSystem& world() { return godhunter::g_ecs; }

    // Macros
#define GODHUNTER_COMPONENT(TYPE, KIND) \
    KIND TYPE; \
    inline struct TYPE##_Registrar { \
        TYPE##_Registrar() { godhunter::world().component_manager.registerComponent<TYPE>(); } \
    } TYPE##_registrar; \
    KIND TYPE

#define GODHUNTER_SCENE(NAME) \
    void NAME(); \
    inline struct NAME##_Registrar { \
        NAME##_Registrar() { godhunter::world().scene_manager.registerScene(NAME##, NAME); } \
    } NAME##_registrar; \
    void NAME()

    // TODO:
    // - Fix and cleanup the ECS
    // - Modify the engine to use the new ECS
    // - Add and test Macros
    // - Add a way to activate component and systems depending on what is used
    // - Create a Prefab manager
    // - Create if possible a view component system
    // - Add ways to use Lua components, systems, prefabs and scenes

} // namespace godhunter

#endif // GODHUNTER_SRC_GODHUNTER_ECS_H_