/**
 * @file ecs.tests.cpp
 * This file is part of the GodHunter Engine
 *
 * This file runs tests on the ECS.
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

// Third party libraries headers
#include <gtest/gtest.h>
#include <godhunter/ecs.h>

// Project headers

// Exceptions

TEST(ECS_EntityManager, CreateEntities)
{
	// Create 3 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}

	// Create 5 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(5);
		for (int i = 0; i < 5; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}

	// Create 1000 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}
}

TEST(ECS_EntityManager, DestroyEntities)
{
	// Destroy 3 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			entity_manager.create();
		}
		for (int i = 0; i < 3; i++)
		{
			entity_manager.destroy(i);
		}
		for (int i = 2; i >= 0; i--)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}

	// Destroy 5 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(5);
		for (int i = 0; i < 5; i++)
		{
			entity_manager.create();
		}
		for (int i = 0; i < 5; i++)
		{
			entity_manager.destroy(i);
		}
		for (int i = 4; i >= 0; i--)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}

	// Destroy 1000 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			entity_manager.create();
		}
		for (int i = 0; i < 1000; i++)
		{
			entity_manager.destroy(i);
		}
		for (int i = 999; i >= 0; i--)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}
}

TEST(ECS_EntityManager, ClearEntities)
{
	// Clear 3 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
		entity_manager.clear();
		for (int i = 0; i < 3; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}

	// Clear 5 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(5);
		for (int i = 0; i < 5; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
		entity_manager.clear();
		for (int i = 0; i < 5; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}

	// Clear 1000 entity
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
		entity_manager.clear();
		for (int i = 0; i < 1000; i++)
		{
			godhunter::entity_t entity = entity_manager.create();
			EXPECT_EQ(entity, i);
		}
	}
}

TEST(ECS_EntityManager, PerformanceTest)
{
	{
		godhunter::EntityManager entity_manager;
		entity_manager.reserve(100000);

		for (int i = 0; i < 100000; i++)
		{
			entity_manager.create();
		}

		for (int incrementation = 1; incrementation < 100000; incrementation++)
		{
			for (int i = 0; i < 100000; i += incrementation)
			{
				entity_manager.destroy(i);
			}
			for (int i = 0; i < 100000; i += incrementation)
			{
				entity_manager.create();
			}
		}
		EXPECT_TRUE(true);
	}
}

TEST(ECS_ComponentArray, CreateComponent)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 3; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			EXPECT_EQ(component.x, i);
			EXPECT_EQ(component.y, i);
			EXPECT_EQ(component.z, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 20; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			EXPECT_EQ(component.x, i);
			EXPECT_EQ(component.y, i);
			EXPECT_EQ(component.z, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 1000; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			EXPECT_EQ(component.x, i);
			EXPECT_EQ(component.y, i);
			EXPECT_EQ(component.z, i);
		}
	}
}

TEST(ECS_ComponentArray, RemoveComponent)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 3; i++)
		{
			EXPECT_TRUE(component_array.hasComponent(i));
		}
		for (int i = 0; i < 3; i++)
		{
			component_array.removeComponent(i);
		}
		for (int i = 0; i < 3; i++)
		{
			EXPECT_FALSE(component_array.hasComponent(i));
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 20; i++)
		{
			EXPECT_TRUE(component_array.hasComponent(i));
		}
		for (int i = 0; i < 20; i++)
		{
			component_array.removeComponent(i);
		}
		for (int i = 0; i < 20; i++)
		{
			EXPECT_FALSE(component_array.hasComponent(i));
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 1000; i++)
		{
			EXPECT_TRUE(component_array.hasComponent(i));
		}
		for (int i = 0; i < 1000; i++)
		{
			component_array.removeComponent(i);
		}
		for (int i = 0; i < 1000; i++)
		{
			EXPECT_FALSE(component_array.hasComponent(i));
		}
	}
}

TEST(ECS_ComponentArray, HasComponent)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i += 2)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 3; i++)
		{
			if (i % 2 == 0)
			{
				EXPECT_TRUE(component_array.hasComponent(i));
			}
			else
			{
				EXPECT_FALSE(component_array.hasComponent(i));
			}
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i += 2)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 20; i++)
		{
			if (i % 2 == 0)
			{
				EXPECT_TRUE(component_array.hasComponent(i));
			}
			else
			{
				EXPECT_FALSE(component_array.hasComponent(i));
			}
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i += 2)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 1000; i++)
		{
			if (i % 2 == 0)
			{
				EXPECT_TRUE(component_array.hasComponent(i));
			}
			else
			{
				EXPECT_FALSE(component_array.hasComponent(i));
			}
		}
	}
}

TEST(ECS_ComponentArray, GetComponent)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 3; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			component.y++;
		}
		for (int i = 0; i < 3; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			EXPECT_EQ(component.x, i);
			EXPECT_EQ(component.y, i + 1);
			EXPECT_EQ(component.z, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 20; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			component.y++;
		}
		for (int i = 0; i < 20; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			EXPECT_EQ(component.x, i);
			EXPECT_EQ(component.y, i + 1);
			EXPECT_EQ(component.z, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 1000; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			component.y++;
		}
		for (int i = 0; i < 1000; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			EXPECT_EQ(component.x, i);
			EXPECT_EQ(component.y, i + 1);
			EXPECT_EQ(component.z, i);
		}
	}
}

TEST(ECS_ComponentArray, GetEntityFromComponent)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 3; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			godhunter::entity_t entity = component_array.getEntityFromComponent(component);
			EXPECT_EQ(entity, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 20; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			godhunter::entity_t entity = component_array.getEntityFromComponent(component);
			EXPECT_EQ(entity, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 1000; i++)
		{
			TestComponent& component = component_array.getComponent(i);
			godhunter::entity_t entity = component_array.getEntityFromComponent(component);
			EXPECT_EQ(entity, i);
		}
	}
}

TEST(ECS_ComponentArray, GetEntityFromIndex)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 3; i++)
		{
			std::size_t index = static_cast<std::size_t>(i);
			godhunter::entity_t entity = component_array.getEntityFromIndex(index);
			EXPECT_EQ(entity, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 20; i++)
		{
			std::size_t index = static_cast<std::size_t>(i);
			godhunter::entity_t entity = component_array.getEntityFromIndex(index);
			EXPECT_EQ(entity, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 1000; i++)
		{
			std::size_t index = static_cast<std::size_t>(i);
			godhunter::entity_t entity = component_array.getEntityFromIndex(index);
			EXPECT_EQ(entity, i);
		}
	}
}

TEST(ECS_ComponentArray, GetAllComponents)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		std::vector<TestComponent> components = component_array.getAllComponents();
		for (int i = 0; i < components.size(); i++)
		{
			EXPECT_EQ(components[i].x, i);
			EXPECT_EQ(components[i].y, i);
			EXPECT_EQ(components[i].z, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		std::vector<TestComponent> components = component_array.getAllComponents();
		for (int i = 0; i < components.size(); i++)
		{
			EXPECT_EQ(components[i].x, i);
			EXPECT_EQ(components[i].y, i);
			EXPECT_EQ(components[i].z, i);
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		std::vector<TestComponent> components = component_array.getAllComponents();
		for (int i = 0; i < components.size(); i++)
		{
			EXPECT_EQ(components[i].x, i);
			EXPECT_EQ(components[i].y, i);
			EXPECT_EQ(components[i].z, i);
		}
	}
}

TEST(ECS_ComponentArray, Size)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		EXPECT_EQ(component_array.size(), 0);
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		EXPECT_EQ(component_array.size(), 0);
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		EXPECT_EQ(component_array.size(), 0);
	}
}

TEST(ECS_ComponentArray, Clear)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(3);
		for (int i = 0; i < 3; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 3; i++)
		{
			EXPECT_TRUE(component_array.hasComponent(i));
		}
		component_array.clear();
		for (int i = 0; i < 3; i++)
		{
			EXPECT_FALSE(component_array.hasComponent(i));
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 20; i++)
		{
			EXPECT_TRUE(component_array.hasComponent(i));
		}
		component_array.clear();
		for (int i = 0; i < 20; i++)
		{
			EXPECT_FALSE(component_array.hasComponent(i));
		}
	}

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(1000);
		for (int i = 0; i < 1000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}
		for (int i = 0; i < 1000; i++)
		{
			EXPECT_TRUE(component_array.hasComponent(i));
		}
		component_array.clear();
		for (int i = 0; i < 1000; i++)
		{
			EXPECT_FALSE(component_array.hasComponent(i));
		}
	}
}

TEST(ECS_ComponentArray, Performance)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_array;
		component_array.reserve(78000);
		for (int i = 0; i < 78000; i++)
		{
			component_array.addComponent(i, TestComponent{ i, i, i });
		}

		for (int incrementation = 1; incrementation < 100; incrementation++)
		{
			for (int i = 0; i < 78000; i += incrementation)
			{
				component_array.removeComponent(i);
			}
			for (int i = 0; i < 78000; i++)
			{
				if (component_array.hasComponent(i))
				{
					component_array.getComponent(i).x++;
				}
			}
			for (int i = 0; i < 78000; i += incrementation)
			{
				component_array.addComponent(i, TestComponent{ i, i, i });
			}
		}
	}
	EXPECT_TRUE(true);
}

TEST(ECS_ComponentArray, RealisticPerformanceTest_InitScene)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_arrays[32];

		// Init all component arrays
		for (int i = 0; i < 32; i++)
		{
			component_arrays[i].reserve(10000);
			for (int j = 0; j < 10000; j += (i + 1))
			{
				component_arrays[i].addComponent(j, TestComponent{ j, j, j });
			}
		}

		EXPECT_TRUE(true);
	}
}

TEST(ECS_ComponentArray, RealisticPerformanceTest_Play1Frame)
{
	struct TestComponent
	{
		int x, y, z;
	};

	{
		godhunter::ComponentArray<TestComponent> component_arrays[32];

		// Init all component arrays
		for (int i = 0; i < 32; i++)
		{
			component_arrays[i].reserve(10000);
			for (int j = 0; j < 10000; j += (i + 1))
			{
				component_arrays[i].addComponent(j, TestComponent{ j, j, j });
			}
		}

		// Play 1 frame
		for (int i = 0; i < 32; i++)
		{
			std::vector<TestComponent> components = component_arrays[i].getAllComponents();
			for (int j = 0; j < component_arrays[i].size(); j++)
			{
				components[j].x++;
			}
		}

		EXPECT_TRUE(true);
	}
}

TEST(ECS_ComponentManager, RegisterComponent)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		component_manager.addComponent(0, Position{ 0, 0, 0 });
		component_manager.addComponent(0, Health{ 100, 100 });
		component_manager.addComponent(0, EnemyAI{ nullptr, false });

		EXPECT_EQ(component_manager.getComponent<Position>(0).x, 0);
		EXPECT_EQ(component_manager.getComponent<Health>(0).max_hp, 100);
		EXPECT_EQ(component_manager.getComponent<EnemyAI>(0).is_aggro, false);
	}
}

TEST(ECS_ComponentManager, AddComponent)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		for (int i = 0; i < 1000; i++)
		{
			if (i % 2 == 0)
			{
				component_manager.addComponent(i, Position{ (float)i, (float)i + 1, (float)i + 2 });
			}

			if (i % 3 == 0)
			{
				component_manager.addComponent(i, Health{ i * 2, i });
			}

			if (i % 5 == 0)
			{
				component_manager.addComponent(0, EnemyAI{ nullptr, true });
			}
		}

		for (int i = 0; i < 1000; i++)
		{
			if (i % 2 == 0)
			{
				EXPECT_EQ(component_manager.getComponent<Position>(i).x, (float)i);
				EXPECT_EQ(component_manager.getComponent<Position>(i).y, (float)i + 1);
				EXPECT_EQ(component_manager.getComponent<Position>(i).z, (float)i + 2);
			}

			if (i % 3 == 0)
			{
				EXPECT_EQ(component_manager.getComponent<Health>(i).max_hp, i * 2);
				EXPECT_EQ(component_manager.getComponent<Health>(i).hp, i);
			}

			if (i % 5 == 0)
			{
				EXPECT_EQ(component_manager.getComponent<EnemyAI>(0).target, nullptr);
				EXPECT_EQ(component_manager.getComponent<EnemyAI>(0).is_aggro, true);
			}
		}
	}
}

TEST(ECS_ComponentManager, RemoveComponent)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		for (int i = 0; i < 1000; i++)
		{
			component_manager.addComponent(i, Position{ 0, 0, 0 });
			component_manager.addComponent(i, Health{ 100, 100 });
			component_manager.addComponent(i, EnemyAI{ nullptr, false });
		}

		for (int i = 0; i < 1000; i += 2)
		{
			component_manager.removeComponent<Health>(i);
		}

		EXPECT_EQ(component_manager.getComponentArray<Position>().size(), 1000);
		EXPECT_EQ(component_manager.getComponentArray<Health>().size(), 500);
		EXPECT_EQ(component_manager.getComponentArray<EnemyAI>().size(), 1000);
	}
}

TEST(ECS_ComponentManager, RemoveAllComponents)
{
	struct Position
	{
		float x, y, z, w;
	};

	struct Health
	{
		int max_hp;
		int hp;
		int poison;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
		int health;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		for (int i = 0; i < 100; i++)
		{
			component_manager.addComponent(i, Position{ (float)i, (float)i, (float)i, (float)i });
			component_manager.addComponent(i, Health{ i * 2, i, i });
			component_manager.addComponent(i, EnemyAI{ nullptr, true, i });
		}

		EXPECT_EQ(component_manager.getComponentArray<Position>().size(), 100);
		EXPECT_EQ(component_manager.getComponentArray<Health>().size(), 100);
		EXPECT_EQ(component_manager.getComponentArray<EnemyAI>().size(), 100);

		for (int i = 0; i < 100; i += 2)
		{
			component_manager.removeAllComponents(i);
		}

		EXPECT_EQ(component_manager.getComponentArray<Position>().size(), 50);
		EXPECT_EQ(component_manager.getComponentArray<Health>().size(), 50);
		EXPECT_EQ(component_manager.getComponentArray<EnemyAI>().size(), 50);
	}
}

TEST(ECS_ComponentManager, ClearComponent)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		for (int i = 0; i < 1000; i++)
		{
			component_manager.addComponent(i, Position{ 0, 0, 0 });
			component_manager.addComponent(i, Health{ 100, 100 });
			component_manager.addComponent(i, EnemyAI{ nullptr, false });
		}

		EXPECT_EQ(component_manager.getComponentArray<Position>().size(), 1000);
		EXPECT_EQ(component_manager.getComponentArray<Health>().size(), 1000);
		EXPECT_EQ(component_manager.getComponentArray<EnemyAI>().size(), 1000);

		component_manager.clear();

		EXPECT_EQ(component_manager.getComponentArray<Position>().size(), 0);
		EXPECT_EQ(component_manager.getComponentArray<Health>().size(), 0);
		EXPECT_EQ(component_manager.getComponentArray<EnemyAI>().size(), 0);
	}
}

TEST(ECS_ComponentManager, GetComponent)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		component_manager.addComponent(0, Position{ 0, 0, 0 });
		component_manager.addComponent(0, Health{ 100, 100 });
		component_manager.addComponent(0, EnemyAI{ nullptr, false });

		EXPECT_EQ(component_manager.getComponent<Position>(0).x, 0);
		EXPECT_EQ(component_manager.getComponent<Health>(0).max_hp, 100);
		EXPECT_EQ(component_manager.getComponent<EnemyAI>(0).is_aggro, false);
	}
}

TEST(ECS_ComponentManager, HasComponent)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		component_manager.addComponent(0, Position{ 0, 0, 0 });
		component_manager.addComponent(0, Health{ 100, 100 });
		component_manager.addComponent(0, EnemyAI{ nullptr, false });

		EXPECT_EQ(component_manager.getComponent<Position>(0).x, 0);
		EXPECT_EQ(component_manager.getComponent<Health>(0).max_hp, 100);
		EXPECT_EQ(component_manager.getComponent<EnemyAI>(0).is_aggro, false);
	}
}

TEST(ECS_ComponentManager, GetComponentArray)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		component_manager.addComponent(0, Position{ 0, 0, 0 });
		component_manager.addComponent(0, Health{ 100, 100 });
		component_manager.addComponent(0, EnemyAI{ nullptr, false });

		EXPECT_EQ(component_manager.getComponent<Position>(0).x, 0);
		EXPECT_EQ(component_manager.getComponent<Health>(0).max_hp, 100);
		EXPECT_EQ(component_manager.getComponent<EnemyAI>(0).is_aggro, false);
	}
}

TEST(ECS_ComponentManager, Performance)
{
	struct Position
	{
		float x, y, z;
	};

	struct Health
	{
		int max_hp;
		int hp;
	};

	struct EnemyAI
	{
		void* target;
		bool is_aggro;
	};

	{
		godhunter::ComponentManager component_manager;

		component_manager.registerComponent<Position>();
		component_manager.registerComponent<Health>();
		component_manager.registerComponent<EnemyAI>();

		component_manager.addComponent(0, Position{ 0, 0, 0 });
		component_manager.addComponent(0, Health{ 100, 100 });
		component_manager.addComponent(0, EnemyAI{ nullptr, false });

		EXPECT_EQ(component_manager.getComponent<Position>(0).x, 0);
		EXPECT_EQ(component_manager.getComponent<Health>(0).max_hp, 100);
		EXPECT_EQ(component_manager.getComponent<EnemyAI>(0).is_aggro, false);
	}
}

TEST(ECS_SystemManager, RegisterSystem)
{
	class SystemA
	{
	public:
		void init(godhunter::ComponentManager& cm)
		{
			initialized = true;
		}
		void update(godhunter::ComponentManager& cm)
		{
			updated = true;
		}
		void render(godhunter::ComponentManager& cm)
		{
			rendered = true;
		}
		bool initialized = false;
		bool updated = false;
		bool rendered = false;
	};

	class SystemB
	{
	public:
		void update(godhunter::ComponentManager& cm)
		{
			updated = true;
		}
		void render(godhunter::ComponentManager& cm)
		{
			rendered = true;
		}
		bool updated = false;
		bool rendered = false;
	};

	class SystemC
	{
	public:
		void init(godhunter::ComponentManager& cm)
		{
			initialized = true;
		}
		void render(godhunter::ComponentManager& cm)
		{
			rendered = true;
		}
		bool initialized = false;
		bool rendered = false;
	};

	// Create 3 entity
	{
		godhunter::SystemManager system_manager;

		SystemA system_a;
		SystemB system_b;
		SystemC system_c;
		system_manager.registerSystem(system_a);
		system_manager.registerSystem(system_b);
		system_manager.registerSystem(system_c);

		godhunter::ComponentManager component_manager;
		system_manager.runInitSystems(component_manager);
		system_manager.runUpdateSystems(component_manager);
		system_manager.runRenderSystems(component_manager);
		EXPECT_TRUE(system_a.initialized);
		EXPECT_TRUE(system_a.updated);
		EXPECT_TRUE(system_a.rendered);

	}
}
