#include "pch.h"
#include "flying.h"

namespace engine
{
	void Flying::Update()
	{

		float move_speed = 10.0f * static_cast<float>(GetNode()->GetGameManager()->GetDeltaT());
		float rot_speed = 2.0f * static_cast<float>(GetNode()->GetGameManager()->GetDeltaT());

		Vector3 movement;
		Vector3 rotation_radians;

		if (GetKeyState(VK_SHIFT) & 0x8000 || GetKeyState(VK_MENU) & 0x8000)
		{
			move_speed *= 3.0f;
		}

		if (Get::InputManager()->GetKeyDown(TYPE_KEY_W))
		{
			movement += GetNode()->GetForwardVectorWorld() * move_speed;
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_S))
		{
			movement -= GetNode()->GetForwardVectorWorld() * move_speed;
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_A))
		{
			movement -= GetNode()->GetRightVectorWorld() * move_speed;
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_D))
		{
			movement += GetNode()->GetRightVectorWorld() * move_speed;
		}

		if (Get::InputManager()->GetKeyDown(TYPE_KEY_LEFT))
		{
			GetNode()->RotateYRadians(Scalar(-rot_speed));
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_RIGHT))
		{
			GetNode()->RotateYRadians(Scalar(rot_speed));
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_UP))
		{
			GetNode()->RotateXRadians(Scalar(-rot_speed));
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_DOWN))
		{
			GetNode()->RotateXRadians(Scalar(rot_speed));
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_Q))
		{
			GetNode()->RotateZRadians(Scalar(-rot_speed));
		}
		if (Get::InputManager()->GetKeyDown(TYPE_KEY_E))
		{
			GetNode()->RotateZRadians(Scalar(rot_speed));
		}
		GetNode()->RotateRadians(rotation_radians);
		GetNode()->Move(movement);
	}
}