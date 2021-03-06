#pragma once

#include "config/config_manager.h"

namespace engine
{
	class GameManager;
	class Renderer;
	class CommandManager;
	class CommandContextManager;
	class MemoryManager;
	class InputManager;
	class ResourceManager;
	class SGNode;
	class PhysicsManager;
	class Window;
	class SwapChain;
	class Device;
	class DescriptorHeap;
	class BufferManager;
	class ComponentManager;

	class Get
	{
	private:
		Get(GameManager* game_manager);

		static GameManager* game_manager_;

	public:
		static bool Create(GameManager* game_manager);
		
		static GameManager* Manager();
		static MemoryManager* MemoryManager();
		static InputManager* InputManager();
		static ResourceManager* ResourceManager();
		static Renderer* Renderer();
		static CommandManager* CommandManager();
		static CommandContextManager* CommandContextManager();
		static SGNode* Scene();
		static PhysicsManager* PhysicsManager();
		static ComponentManager* ComponentManager();
		static Window* Window();
		static float DeltaT();
		static float TimeSinceStartup();
		static const Config& Config();
		static ConfigManager* ConfigManager();
		static SwapChain& SwapChain();
		static Device& Device();
		static DescriptorHeap& CbvSrvUavHeap();
		static DescriptorHeap& RtvHeap();
		static DescriptorHeap& DsvHeap();
		static DescriptorHeap& SamplerHeap();
		static BufferManager& BufferManager();
	};
}