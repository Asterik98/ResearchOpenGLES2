#include "stdafx.h"
#include "Model.h"
#include <list>
#include <iostream>
using namespace std;
Model::Model()
{
	CounterVertices = 0;
	TotalVertices = 0;
	TotalIndices = 0;
	c = 'c';
	m_indicesCount = 0;
}


Model::~Model()
{

}
void Model::InitModel(char* filename) {
	FILE* pFile = fopen(filename, "r");

	fscanf_s(pFile, "NrVertices: %d", &TotalVertices);
	verticesData = new Vertex[TotalVertices];
	while (fscanf_s(pFile, "%c", &c) != EOF) {
		if (fscanf_s(pFile, "pos:[%f, %f, %f]; uv:[%f, %f];", &verticesData[CounterVertices].pos.x, &verticesData[CounterVertices].pos.y, &verticesData[CounterVertices].pos.z,
			&verticesData[CounterVertices].uv.x, &verticesData[CounterVertices].uv.y) > 0) {
			if (CounterVertices + 1 == TotalVertices) {
				break;
			}
			else {
				CounterVertices++;
			}
		}
	}
	while (fscanf_s(pFile, "%c", &c) != EOF) {
		if (fscanf_s(pFile, "NrIndices: %d", &TotalIndices) > 0) {
			if (TotalIndices != 0) {
				break;
			}
		}
	}
	indices = new unsigned int[TotalIndices];

	while (fscanf_s(pFile, "%c", &c) != EOF) {
			if (fscanf_s(pFile, "   %*d.    %d,    %d,    %d", &indices[m_indicesCount], &indices[m_indicesCount + 1], &indices[m_indicesCount + 2]) > 0) {
				if (m_indicesCount + 2 == TotalIndices) {
					break;
				}
				else {
					m_indicesCount = m_indicesCount + 3;
				}
			}
	}
	fclose(pFile);

	glGenBuffers(1, &m_vboId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*TotalVertices, verticesData, GL_STATIC_DRAW);

	glGenBuffers(1, &m_iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)* TotalIndices, indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete verticesData;
	delete indices;

}

