/**
 * @file ecs.h
 * This file is part of the GodHunter Engine
 *
 * This file implement the features of an Entity Component System.
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
#include "ecs.h"

// C system headers

// C++ standard library headers

// Third party libraries headers

// Project headers

// Exceptions

// Entity manager
godhunter::EntityManager::EntityManager() : m_next_entity(1)
{

}

godhunter::EntityManager::~EntityManager()
{

}

godhunter::Entity godhunter::EntityManager::create()
{
    if (!m_free_list.empty())
    {
        godhunter::Entity entity = m_free_list.back();
        m_free_list.pop_back();
        return entity;
    }
    return m_next_entity++;
}

void godhunter::EntityManager::destroy(godhunter::Entity entity_)
{
    godhunter::world().component_manager.removeAllComponents(entity_);
    m_free_list.push_back(entity_);
}

void godhunter::EntityManager::clear()
{
    godhunter::world().component_manager.clear();
    m_free_list.clear();
	m_next_entity = 1;
}

// System manager
void godhunter::SystemManager::runUpdateSystems(godhunter::ComponentManager& component_manager_)
{
    for (auto& system : m_update_systems) system(component_manager_);
}

void godhunter::SystemManager::runRenderSystems(godhunter::ComponentManager& component_manager_)
{
    for (auto& system : m_render_systems) system(component_manager_);
}

// Scene manager
void godhunter::SceneManager::registerScene(const std::string& scene_name_, std::function<void()> load_scene_function_)
{
    this->m_scenes[scene_name_] = load_scene_function_;
}

void godhunter::SceneManager::loadScene(const std::string& scene_)
{
    this->m_scenes[scene_]();
}