#include "stdafx.h"
#include "Renderer.h"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{

}
void Renderer::Render(Object3D * myObject, Camera * myCamera)
{
	ObjectRender = myObject;
	CameraRender = myCamera;
	R_Shaders= ObjectRender->m_Shader;
	R_Model= ObjectRender->m_Model;
	R_Texture= ObjectRender->m_Texture;

}

void Renderer::UseVBO() {
	glBindBuffer(GL_ARRAY_BUFFER, ObjectRender->m_Model->m_vboId);
	glEnableVertexAttribArray(ObjectRender->m_Shader->GetAttributes().position);
	glVertexAttribPointer(ObjectRender->m_Shader->GetAttributes().position, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(R_Shaders->GetAttributes().uv);
	glVertexAttribPointer(R_Shaders->GetAttributes().uv, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (char*)(6 * sizeof(float)));
	
}
void Renderer::UseIBO() {

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, R_Model->m_iboID);

}
void Renderer::GetTextureId() {
	Matrix wvp;
	glBindTexture(GL_TEXTURE_2D, R_Texture->textureID);
	glUniform1i(R_Shaders->GetUniforms().iTextureLoc,0);
	
	//glUniformMatrix4fv(R_Shaders->GetUniforms().worldMatrix, 1, GL_FALSE, *ObjectRender->m_Ptransform->GetWorldMatrix().m);
	wvp = (ObjectRender->m_Ptransform->GetWorldMatrix()) * CameraRender->GetViewMatrix() * CameraRender->GetProjectionMatrix();
	glUniformMatrix4fv(R_Shaders->GetUniforms().worldMatrix, 1, GL_FALSE, *wvp.m);
}

void Renderer::DoDraw() {
	UseVBO();
	GetTextureId();
	UseIBO();
	glDrawElements(GL_TRIANGLES, R_Model->m_indicesCount, GL_UNSIGNED_INT, 0);
}
