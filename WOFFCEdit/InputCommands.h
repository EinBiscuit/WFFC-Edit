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

	DirectX::SimpleMath::Vector3 CameraPos;
	DirectX::SimpleMath::Vector3 YawPitchRoll;

	bool FreeCam;

};
