#pragma once
#include "../Utilities/utilities.h"
class Model
{
public:
	Model();
	~Model();
	void InitModel(char * filename);
	GLuint m_vboId, m_iboID;
	int CounterVertices;
	unsigned int m_indicesCount;
	Vertex * verticesData;
	unsigned int *indices;
	int TotalVertices;
	unsigned int TotalIndices;
	char c;
};

