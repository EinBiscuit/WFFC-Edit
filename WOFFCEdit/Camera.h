#pragma once
#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX;

class Camera
{
protected:
	SimpleMath::Vector3 Position;
	SimpleMath::Vector3 Rotation;
	
	SimpleMath::Vector3 Forward;
	SimpleMath::Vector3 Right;

	float speed;
	float rotSpeed;

	float Near;
	float Far;
	float FOV;

	XMMATRIX ProjectionMatrix;
	XMMATRIX ViewMatrix;

	  

public:

	Camera();

	void setSpeed(float s)  { speed = s; };
	void addSpeed(float Ds) { speed += Ds; }

	void setPos(SimpleMath::Vector3 pos) { Position = pos; };
	void setRot(SimpleMath::Vector3 rot) { Rotation = rot; };
			
	void addPos(SimpleMath::Vector3 Dpos) { Position += Dpos; };
	void addRot(SimpleMath::Vector3 Drot) { Rotation += Drot; }

	void update();

	void recalculateProjection(RECT outSize);

	SimpleMath::Vector3 getForward() { return Forward; }
	SimpleMath::Vector3 getRight()   { return Right; }

	XMMATRIX GetViewMatrix() { return ViewMatrix; };
};

