#pragma once
#include "../Utilities/utilities.h"
#include "Shaders.h"
#include "Model.h"
#include "Texture.h"
#include "Object3D.h"
#include "Camera.h"
#include <iostream>
using namespace std;
class Renderer
{
public:
	char Input;
	char id;
	Shaders *R_Shaders;
	Model *R_Model;
	Texture *R_Texture;
	Object3D * ObjectRender;
	Camera * CameraRender;
	Renderer();
	~Renderer();
	void Render(Object3D* myObject,Camera* myCamera);
	void UseVBO();
	void UseIBO();
	void DoDraw();
	void GetTextureId();
	void SetLightColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	void SetObjectColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
};

