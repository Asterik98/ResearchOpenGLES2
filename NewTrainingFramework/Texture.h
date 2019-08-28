#pragma once
#include "../Utilities/utilities.h"
#include "Shaders.h"
class Texture
{
public:
	GLuint textureID;
	GLint iWidth, iHeight, iBpp;
	Texture();
	~Texture();
	void InitTexture(char * filename);
};

