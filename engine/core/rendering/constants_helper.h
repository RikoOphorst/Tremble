#pragma once

#include "../../pch.h"
#include "constant_buffers.h"
#include "../utilities/timer.h"

namespace engine
{
	template<typename T>
	class UploadBuffer;

	class Camera;
	struct Material;
	class Renderable;
	class Timer;
	class Light;

	class ConstantsHelper
	{
	public:
		static void UpdatePassConstants(
			UploadBuffer<PassConstants>* buffer,
			const DirectX::XMFLOAT2& render_target_size,
			Timer* timer,
			Camera* camera
		);

		static void UpdateObjectConstants(
			UploadBuffer<ObjectConstants>* buffer, 
			const std::vector<Renderable*>& renderables, 
			Camera* camera
		);

		static void UpdateMaterialConstants(
			UploadBuffer<MaterialConstants>* buffer, 
			const std::vector<Material*>& materials
		);
	};
}