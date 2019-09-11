#include "stdafx.h"
#include "Shaders.h"

int Shaders::Init( char * fileVertexShader, char * fileFragmentShader )
{
	m_vertexShader = esLoadShader( GL_VERTEX_SHADER, fileVertexShader );

	if( m_vertexShader == 0 )
	{
		return -1;
	}

	m_fragmentShader = esLoadShader( GL_FRAGMENT_SHADER, fileFragmentShader );

	if( m_fragmentShader == 0 )
	{
		glDeleteShader( m_vertexShader );
		return -2;
	}

	m_program = esLoadProgram( m_vertexShader, m_fragmentShader );

	m_attributes.position = glGetAttribLocation( m_program, "a_posL" );
	m_attributes.color = glGetAttribLocation(m_program, "a_VColor");
	m_attributes.uv = glGetAttribLocation(m_program, "a_uv");
	m_attributes.norm = glGetAttribLocation(m_program, "a_norm");

	//m_uniforms.NewPos=glGetUniformLocation(m_program,"u_pos");
	//m_uniforms.NewScale = glGetUniformLocation(m_program, "u_sca");
	m_uniforms.worldMatrix= glGetUniformLocation(m_program, "u_worldMatrix");
	m_uniforms.model= glGetUniformLocation(m_program, "u_model");
	m_uniforms.lightColor= glGetUniformLocation(m_program, "lightColor");
	m_uniforms.objectColor= glGetUniformLocation(m_program, "objectColor");
	return 0;
}

GLuint Shaders::GetProgram() const
{
	return m_program;
}

Shaders::Attributes Shaders::GetAttributes() const
{
	return m_attributes;
}

Shaders::Uniforms Shaders::GetUniforms() const
{
	return m_uniforms;
}

Shaders::~Shaders()
{
	glDeleteProgram( m_program );
	glDeleteShader( m_vertexShader );
	glDeleteShader( m_fragmentShader );
}