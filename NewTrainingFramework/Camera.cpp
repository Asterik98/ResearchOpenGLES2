#include "stdafx.h"
#include "Camera.h"


Camera::Camera(): Object3D()
{
	
}


Camera::~Camera()
{

}

Camera::Camera(GLfloat NearPlane, GLfloat FarPlane, GLfloat Fov):Object3D()
{
	m_nearPlane = NearPlane;
	m_farPlane = FarPlane;
	m_fovY = Fov;

}

Matrix Camera::GetViewMatrix()
{
	Matrix rotZInv, rotXInv, rotYInv, transInv;
	Matrix View;
	float PosX= m_Ptransform->Position.x;
	float PosY = m_Ptransform->Position.y;
	float PosZ = m_Ptransform->Position.z;
	transInv.SetTranslation((-1)*PosX, (-1)*PosY, (-1)*PosZ);
	rotXInv.SetRotationX((-1)*m_Ptransform->Rotation.x);
	rotYInv.SetRotationY((-1)*m_Ptransform->Rotation.y);
	rotZInv.SetRotationZ((-1)*m_Ptransform->Rotation.z);
	View = transInv*rotYInv*rotXInv*rotZInv;
	return View;
}

Matrix Camera::GetProjectionMatrix()
{
	Matrix Persp;
	Persp.SetPerspective(m_fovY, 1, m_nearPlane, m_farPlane);
	return Persp;
}

void Camera::SetPos(float x, float y, float z)
{
	m_Ptransform->ChangePos(x, y, z);
}

void Camera::SetRot(float x, float y, float z)
{
	m_Ptransform->ChangeRot(x, y, z);
}

