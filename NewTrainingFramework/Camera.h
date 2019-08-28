#pragma once
#include "../Utilities/utilities.h"
#include "Object3D.h"
#include "Camera.h"
class Camera:public Object3D {
public:
	GLfloat m_nearPlane;
	GLfloat m_farPlane;
	GLfloat m_fovY;
	Camera();
	~Camera();
	Camera(GLfloat NearPlane, GLfloat FarPlane, GLfloat Fov);
	Matrix GetViewMatrix();
	Matrix GetProjectionMatrix();
	void SetPos(float x, float y, float z);
	void SetRot(float x, float y, float z);
};

