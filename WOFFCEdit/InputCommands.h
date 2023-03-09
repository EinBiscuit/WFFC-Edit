#pragma once

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;
	bool Up;
	bool Down;
	DirectX::SimpleMath::Vector2 YawPitch;
	bool FreeCam;
};
