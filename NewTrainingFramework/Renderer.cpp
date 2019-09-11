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
	//glUniformMatrix4fv(R_Shaders->GetUniforms().worldMatrix, 1, GL_FALSE, *ObjectRender->m_Ptransform->GetWorldMatrix().m);
	wvp = (ObjectRender->m_Ptransform->GetWorldMatrix()) * CameraRender->GetViewMatrix() * CameraRender->GetProjectionMatrix();
	glUniformMatrix4fv(R_Shaders->GetUniforms().worldMatrix, 1, GL_FALSE, *wvp.m);

}
void Renderer::SetLightColor(GLfloat r, GLfloat g, GLfloat b) {
	glUniform3f(R_Shaders->GetUniforms().lightColor, r, g, b);
}
void Renderer::SetObjectColor(GLfloat r, GLfloat g, GLfloat b) {
	glUniform3f(R_Shaders->GetUniforms().objectColor, r, g, b);
}
void Renderer::SetModel(GLfloat x, GLfloat y, GLfloat z) {
	model.SetTranslation(x,y,z);
	model.SetScale(0.2,0.2,0.2);
}
void Renderer::DoDraw() {
	UseVBO();
	GetTextureId();
	UseIBO();
	glUniformMatrix4fv(R_Shaders->GetUniforms().model, 1, GL_FALSE, *model.m);
	glDrawElements(GL_TRIANGLES, R_Model->m_indicesCount, GL_UNSIGNED_INT, 0);
}
void Renderer::SetLightPos(GLfloat x, GLfloat y, GLfloat z) {
	glUniform3f(R_Shaders->GetUniforms().lightPos, x,y,z);
}
