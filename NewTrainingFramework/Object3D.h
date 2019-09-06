#pragma once
#include "../Utilities/Math.h"
#include "Shaders.h"
#include "Model.h"
#include "Texture.h" 
#include <math.h>

struct Transform {
	Vector3  Position;
	Vector3  Rotation;
	Vector3  Scale;
	Transform() {
		Position = Vector3(1.0, 1.0, 1.0);
		Rotation = Vector3(0.0, 0.0, 0.0);
		Scale = Vector3(1.0, 1.0, 1.0);
	}

	Matrix GetWorldMatrix() {
		Matrix rotZ, rotX, rotY, trans, scale;
		Matrix world;
		//rotX.SetIdentity();
		//rotY.SetIdentity();
		//rotZ.SetIdentity();
		//scale.SetIdentity();
		//trans.SetIdentity();
		
		trans.SetTranslation(Position.x, Position.y, Position.z);
		rotX.SetRotationX(Rotation.x);
		rotY.SetRotationY(Rotation.y);
		rotZ.SetRotationZ(Rotation.z);
		scale.SetScale(Scale.x, Scale.y, Scale.z);

		world = scale * rotZ * rotX * rotY * trans;
		return world;
	}
	void ChangePos(float x, float y,float z) {
		Position = Vector3(x, y, z);
	}
	void ChangeRot(float x, float y, float z) {
		Rotation = Vector3(x, y, z);
	}
	void ChangeSca(float x, float y, float z) {
		Scale = Vector3(x, y, z);
	}
		void RotXPlus(float x) {
		Rotation.x += x;
	}
	void RotXMin(float x) {
		Rotation.x -= x;
	}
	void RotYPlus(float y) {
		Rotation.y += y;
	}
	void RotYMin(float y) {
		Rotation.y -= y;
	}
	void RotZPlus(float z) {
		Rotation.z +=z;
	}
	void RotZMin(float z) {
		Rotation.z -= z;
	}

};

class Object3D
{
	
public:
	Shaders* m_Shader;
	Model* m_Model;
	Transform *m_Ptransform;
public:
	Object3D();
	~Object3D();
	Object3D(Model * myModel, Shaders * myShader);
	void m_pShader(Shaders* myShader);
	void m_pModel(Model* myModel);
	void m_Transform(Transform * _Transform);
	void SetPos(float x, float y, float z);
	void SetRot(float x, float y, float z);
	void SetSca(float x, float y, float z);

};

