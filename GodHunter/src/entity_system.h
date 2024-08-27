/**
 * @file entity_system.h
 * This file is part of the GodHunter Engine
 *
 * This file contain all that is needed for the engine's ECS (or just ES) such as GameObjects and others.
 *
 * MIT License
 *
 * Copyright (c) 2023 GeoffroiHenquin
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
#include <map>
#include <vector>

// Third party libraries headers

// Project headers
#include "assets.h"
#include "human_interface_devices.h"

// Exceptions

#ifndef GODHUNTER_SRC_ENTITY_SYSTEM_H_
#define GODHUNTER_SRC_ENTITY_SYSTEM_H_

namespace godhunter
{
	// https://stackoverflow.com/questions/3643681/how-do-flags-work-in-c
	
	// https://en.cppreference.com/w/cpp/language/union

	class Transform2D
	{
	public:
		float position[2] = { 0, 0 };
	};

	class PhysicsComponent
	{
	public:
		float speed[2] = { 0, 0 };
		float acceleration[2] = { 0, 0 };
	};
	
	class ColliderComponent
	{
	public:
		float size[2] = { 0, 0 }; // Width and height
		float relative_position[2] = { 0, 0 }; // Center of collider
	};

	class SpriteComponent
	{
	public:
		int z_position = 0;
		MonoChromeSprite* image;
	};

	class AnimationComponent
	{
		std::map<int, MonoChromeSprite*> animations;
	};

	enum EntityFlags
	{
		entity_flag_active = 1 << 0,
		entity_flag_physic = 1 << 1,
		entity_flag_collider = 1 << 2,
		entity_flag_sprite = 1 << 3,
		entity_flag_animator = 1 << 4,
		entity_flag_camera = 1 << 5,
		entity_flag_player_behaviour = 1 << 6
	};

	struct Entity
	{
		unsigned long long int flags;

		Transform2D transform;

		PhysicsComponent physic;
		ColliderComponent collider;
		SpriteComponent sprite;
		AnimationComponent animator;
	};

	class EntitySystem
	{
	private:
		std::vector<Entity> m_entities;
	public:
		void deleteAllEntity();
		void loadScene(int scene_id_);

		void handleGameLogic(EventSystem& event_system_);
		void renderFrame(GUIWindow& window_);
	};

} // namespace godhunter

#endif // GODHUNTER_SRC_ENTITY_SYSTEM_H_