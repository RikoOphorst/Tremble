#include "pch.h"
#include "command_allocator_pool.h"

#include "../get.h"
#include "device.h"
#include "renderer.h"

namespace engine
{
	//------------------------------------------------------------------------------------------------------
	CommandAllocatorPool::CommandAllocatorPool(D3D12_COMMAND_LIST_TYPE type) :
		type_(type)
	{

	}
	
	//------------------------------------------------------------------------------------------------------
	CommandAllocatorPool::~CommandAllocatorPool()
	{
		for (size_t i = 0; i < allocator_pool_.size(); i++)
		{
			allocator_pool_[i]->Release();
		}

		allocator_pool_.clear();
	}
	
	//------------------------------------------------------------------------------------------------------
	ID3D12CommandAllocator* CommandAllocatorPool::RequestAllocator(uint64_t completed_fence_value)
	{
		ID3D12CommandAllocator* allocator = nullptr;

		if (!available_allocators_.empty())
		{
			auto pair = available_allocators_.front();

			if (pair.first <= completed_fence_value)
			{
				allocator = pair.second;
				CHECKHR(allocator->Reset());
				available_allocators_.pop();
			}
		}

		if (allocator == nullptr)
		{
			CHECKHR(Get::Renderer()->GetDevice().Get()->CreateCommandAllocator(type_, IID_PPV_ARGS(&allocator)));
			wchar_t AllocatorName[32];
			swprintf(AllocatorName, 32, L"CommandAllocator %zu", allocator_pool_.size());
			allocator->SetName(AllocatorName);
			allocator_pool_.push_back(allocator);
		}

		return allocator;
	}

	//------------------------------------------------------------------------------------------------------
	void CommandAllocatorPool::DiscardAllocator(uint64_t fence_value, ID3D12CommandAllocator* allocator)
	{
		available_allocators_.push(std::make_pair(fence_value, allocator));
	}
}