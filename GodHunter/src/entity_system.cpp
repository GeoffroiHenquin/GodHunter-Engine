/**
 * @file entity_system.cpp
 * This file is part of the GodHunter Engine
 *
 * This file implement the functions declared in entity_system.h.
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
#include "entity_system.h"

// C system headers

// C++ standard library headers
#include <iostream>

// Third party libraries headers

// Project headers
#include "human_interface_devices.h"

// Exceptions

namespace godhunter
{

	void EntitySystem::deleteAllEntity()
	{
		this->m_entities.clear();
	}

	void EntitySystem::loadScene(int scene_id_)
	{
		this->deleteAllEntity();
		// TODO: create a scene system
		switch (scene_id_)
		{
		case 0:
		{
			// TODO: create a few objects (main menu scene)

			// Create a texture for the first object
			MonoChromeSprite* image_1 = new MonoChromeSprite();
			image_1->color[0] = 255;
			image_1->color[1] = 255;
			image_1->color[2] = 0;
			image_1->color[3] = 255;
			image_1->width = 16;
			image_1->height = 16;
			image_1->grid = new bool[image_1->width * image_1->height]
				{
					0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1,
						0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1,
						0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
						1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
						1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
						1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
						0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0,
						0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0,
						0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0
				};

			// Create a texture for the second object
			MonoChromeSprite* image_2 = new MonoChromeSprite();
			image_2->color[0] = 0;
			image_2->color[1] = 255;
			image_2->color[2] = 0;
			image_2->color[3] = 255;
			image_2->width = 32;
			image_2->height = 8;
			image_2->grid = new bool[image_2->width * image_2->height]
				{
					1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
				};

			// Create the first object
			Entity entity_1;
			entity_1.flags = entity_flag_active | entity_flag_collider | entity_flag_physic | entity_flag_sprite | entity_flag_camera | entity_flag_player_behaviour;
			entity_1.transform.position[0] = 0;
			entity_1.transform.position[1] = 0;
			entity_1.collider.relative_position[0] = 0;
			entity_1.collider.relative_position[1] = 0;
			entity_1.collider.size[0] = 1;
			entity_1.collider.size[1] = 1;
			entity_1.physic.speed[0] = 0;
			entity_1.physic.speed[1] = 0;
			entity_1.physic.acceleration[0] = 0;
			entity_1.physic.acceleration[0] = 0;
			entity_1.sprite.image = image_1;

			// Create the second object
			Entity entity_2;
			entity_2.flags = entity_flag_active | entity_flag_collider | entity_flag_sprite;
			entity_2.transform.position[0] = 1;
			entity_2.transform.position[1] = -1;
			entity_2.collider.relative_position[0] = 0;
			entity_2.collider.relative_position[1] = 0;
			entity_2.collider.size[0] = 2;
			entity_2.collider.size[1] = 0.5;
			entity_2.sprite.image = image_2;

			// Add entities to ES
			m_entities.push_back(entity_1);

			// Greate ground
			for (int i = -20; i < 20; i++)
			{
				entity_2.transform.position[0] = i * 2;
				m_entities.push_back(entity_2);
			}
			
			break;
		}
		case 1:
		{
			// TODO: create a few objects (gameplay scene)
			break;
		}
		case 2:
		{
			// TODO: create a few objects (game over scene)
			break;
		}
		default:
		{
			break;
		}
		}
	}

	void EntitySystem::handleGameLogic(EventSystem& event_system_)
	{
		//std::cout << "Called EntitySystem::handleGameLogic()\n";
		for (int i = 0; i < m_entities.size(); ++i)
		{
			//std::cout << "Working on game object: " << (int)i << "\n";
			// Get a ref to the entity
			Entity& entity = m_entities[i];
			if (!(entity.flags & entity_flag_active)) continue;

			// Handle the collision for the entity
			if (entity.flags & entity_flag_collider)
			{
				for (int j = i + 1; j < m_entities.size(); ++j)
				{
					//std::cout << "Checking collision between objects " << (int)i << " and " << (int)j << "\n";
					// Get a ref to the other entity
					Entity& other_entity = m_entities[j];
					//if (!(other_entity.flags & entity_flag_active)) continue;
					
					// Get positions of each sides of the two colliders
					float center_x_1 = entity.transform.position[0] + entity.collider.relative_position[0];
					float center_y_1 = entity.transform.position[1] + entity.collider.relative_position[1];
					float center_x_2 = other_entity.transform.position[0] + other_entity.collider.relative_position[0];
					float center_y_2 = other_entity.transform.position[1] + other_entity.collider.relative_position[1];

					float half_x_1 = 0.5 * entity.collider.size[0];
					float half_y_1 = 0.5 * entity.collider.size[1];
					float half_x_2 = 0.5 * other_entity.collider.size[0];
					float half_y_2 = 0.5 * other_entity.collider.size[1];

					float left_1 = center_x_1 - half_x_1;
					float right_1 = center_x_1 + half_x_1;
					float bottom_1 = center_y_1 - half_y_1;
					float top_1 = center_y_1 + half_y_1;

					float left_2 = center_x_2 - half_x_2;
					float right_2 = center_x_2 + half_x_2;
					float bottom_2 = center_y_2 - half_y_2;
					float top_2 = center_y_2 + half_y_2;

					// Compare the positions of the sides
					if (left_1 > right_2 || left_2 > right_1 || bottom_1 > top_2 || bottom_2 > top_1) continue;
					
					//std::cout << "The objects should be colliding\n";
					// Apply physics
					//entity.physic.acceleration[0] += other_entity.physic.speed[0];
					//entity.physic.acceleration[1] += other_entity.physic.speed[1];
					//other_entity.physic.acceleration[0] += entity.physic.speed[0];
					//other_entity.physic.acceleration[1] += entity.physic.speed[1];
					entity.physic.speed[0] = 0;
					entity.physic.speed[1] = 0.01;
					other_entity.physic.speed[0] = 0;
					other_entity.physic.speed[1] = 0.01;
				}
			}

			// Handle the behaviour
			if (entity.flags & entity_flag_player_behaviour)
			{
				if (event_system_.m_keyboard.getEventKeyDown('w'))
				{
					entity.physic.speed[1] += 0.2;
				}

				if (event_system_.m_keyboard.getEventKeyPressed('a'))
				{
					entity.physic.speed[0] = -0.1;
				}

				if (event_system_.m_keyboard.getEventKeyPressed('d'))
				{
					entity.physic.speed[0] = 0.1;
				}
			}

			// Handle the physic and movement
			if (entity.flags & entity_flag_physic)
			{
				// add gravity
				entity.physic.speed[1] -= 0.01;
				
				// Modify the position
				entity.transform.position[0] += entity.physic.speed[0];
				entity.transform.position[1] += entity.physic.speed[1];

				// Modify the acceleration
				entity.physic.speed[0] *= 0.8;
				entity.physic.speed[1] *= 0.8;
			}

			// Handle the displayed sprite
			if (entity.flags & entity_flag_animator)
			{
				// TODO: Change the sprite when required
			}
		}
	}

	void EntitySystem::renderFrame(GUIWindow& window_)
	{
		// Get camera position
		int camera_position[2] = { 0, 0 };
		for (int i = 0; i < m_entities.size(); ++i)
		{
			if (m_entities[i].flags & entity_flag_camera)
			{
				camera_position[0] = m_entities[i].transform.position[0];
				camera_position[1] = m_entities[i].transform.position[1];
			}
		}

		for (int i = 0; i < m_entities.size(); ++i)
		{
			if (m_entities[i].flags & entity_flag_sprite)
			{
				// TODO: display the sprite
				int size_ratio = 8; // 1 pixel will be displayed as 1 pixel on screen.
				int base_object_size = 16;
				Entity& entity = m_entities[i];

				// Get the start position for the sprite drawing
				int start_position[2] = {
					(int)((entity.transform.position[0] - camera_position[0]) * size_ratio * base_object_size + window_.getWidth() * 0.5 - (entity.sprite.image->width * size_ratio * 0.5)),
					(int)(-(entity.transform.position[1] - camera_position[1]) * size_ratio * base_object_size + window_.getHeight() * 0.5 - (entity.sprite.image->height * size_ratio * 0.5))
				};

				// draw the sprite
				for (int x = 0; x < entity.sprite.image->width; ++x)
				{
					for (int y = 0; y < entity.sprite.image->height; ++y)
					{
						// display the pixel on the screen
						if (!entity.sprite.image->grid[(y * entity.sprite.image->width) + x]) continue;

						window_.drawRect(start_position[0]+(x*size_ratio), start_position[1] + (y * size_ratio), size_ratio, entity.sprite.image->color);
					}
				}
			}
		}
	}
}