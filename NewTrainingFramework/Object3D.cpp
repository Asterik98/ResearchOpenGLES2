#include "stdafx.h"
#include "Object3D.h"


Object3D::Object3D()
{
	m_Ptransform = new Transform;
}


Object3D::~Object3D()
{
	delete m_Ptransform;
}

Object3D::Object3D(Model * myModel, Shaders * myShader, Texture * myTexture)
{
	m_pShader(myShader);
	m_pModel(myModel);
	m_pTexture(myTexture);

	m_Ptransform = new Transform;
}

void Object3D::m_pShader(Shaders * myShader)
{
	m_Shader = myShader;
}

void Object3D::m_pModel(Model * myModel)
{
	m_Model = myModel;
}

void Object3D::m_pTexture(Texture * myTexture)
{
	m_Texture = myTexture;
}

void Object3D::m_Transform(Transform * _Transform)
{
	m_Ptransform = _Transform;

}

void Object3D::SetPos(float x, float y, float z)
{
	m_Ptransform->ChangePos(x, y, z);
}

void Object3D::SetRot(float x, float y, float z)
{
	m_Ptransform->ChangeRot(x, y, z);
}

void Object3D::SetSca(float x, float y, float z)
{
	m_Ptransform->ChangeSca(x, y, z);
}



