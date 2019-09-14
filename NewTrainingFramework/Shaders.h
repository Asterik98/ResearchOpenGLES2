#pragma once
#include "../Utilities/utilities.h"

class Shaders 
{
public:
	struct Attributes
	{
		GLint position;
		GLint color;
		GLint norm;
		GLint uv;
	};

	struct Uniforms
	{
		GLint NewPos;
		GLint NewScale;
		GLint iTextureLoc;
		GLint worldMatrix;
		GLint model;
		GLint invModel;
		GLint lightColor;
		GLint lightPos;
		GLint viewPos;
		GLint view;
		GLint objectColor;
	};

private:
	GLuint		m_program;
	GLuint		m_vertexShader; 
	GLuint		m_fragmentShader;

	Attributes	m_attributes;
	Uniforms	m_uniforms;

public:
	int			Init( char * fileVertexShader, char * fileFragmentShader );
	
	// Getters
	GLuint		GetProgram() const;
	Attributes	GetAttributes() const;
	Uniforms	GetUniforms() const;
	
	~Shaders();
};