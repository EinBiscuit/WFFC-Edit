#include "Camera.h"

Camera::Camera()
{
	Position = SimpleMath::Vector3(3.7f, -3.5f, 0);
	Rotation = SimpleMath::Vector3(0,0,0);
	Forward	 = SimpleMath::Vector3(0,0,0);
	Right	 = SimpleMath::Vector3(0,0,0);

	Near = 0.01f;
	Far = 1000.f;
	FOV = 90;

	XMMATRIX ProjectionMatrix = XMMatrixIdentity();
	XMMATRIX ViewMatrix = XMMatrixIdentity();
}

void Camera::update()
{
	//TODO  any more complex than this, and the camera should be abstracted out to somewhere else
//camera motion is on a plane, so kill the 7 component of the look direction
	SimpleMath::Vector3 planarMotionVector = Forward;
	planarMotionVector.y = 0.0;

	//create look direction from Euler angles in m_camOrientation
	Forward.x = cos(Rotation.x * 3.1415 / 180) * cos(Rotation.y * 3.1415 / 180);
	Forward.y = sin(Rotation.y * 3.1415 / 180);
	Forward.z = sin(Rotation.x * 3.1415 / 180) * cos(Rotation.y * 3.1415 / 180);

	Forward.Normalize();

	//create right vector from look Direction
	Forward.Cross(SimpleMath::Vector3::UnitY, Right);

	//update lookat point
	SimpleMath::Vector3 LookAt = Position + Forward;

	//apply camera vectors
	ViewMatrix = SimpleMath::Matrix::CreateLookAt(Position, LookAt, SimpleMath::Vector3::UnitY);
}

void Camera::recalculateProjection(RECT outSize)
{
	float aspectRatio = float(outSize.right) / float(outSize.bottom);
	float fovAngleY = FOV * XM_PI / 180.0f;

	// This is a simple example of change that can be made when the app is in
	// portrait or snapped view.
	if (aspectRatio < 1.0f)
	{
		fovAngleY *= 2.0f;
	}

	// This sample makes use of a right-handed coordinate system using row-major matrices.
	ProjectionMatrix = SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		fovAngleY,
		aspectRatio,
		Near,
		Far
	);
}

