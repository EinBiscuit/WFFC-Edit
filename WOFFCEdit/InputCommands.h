#pragma once

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;
	bool Up;
	bool Down;

	bool LMsb;
	bool RMsb;

	DirectX::SimpleMath::Vector2 MPos;

	DirectX::SimpleMath::Vector2 YawPitch;
	bool FreeCam;

};
