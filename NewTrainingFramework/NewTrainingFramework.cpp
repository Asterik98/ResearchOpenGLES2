// NewTrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Vertex.h"
#include "Shaders.h"
#include "Globals.h"
#include "Model.h"
#include "Texture.h"
#include "Object3D.h"
#include "Camera.h"
#include "Renderer.h"
#include <conio.h>

Shaders*myShaders=new Shaders;
Shaders*myShaders2=new Shaders;
Shaders*myShaders3=new Shaders;
Shaders*myShaders4=new Shaders;
Shaders*myShaders5=new Shaders;
Model* myModel=new Model;
Texture* myTexture=new Texture;
Object3D* myObj;
Object3D* myObj2;

Renderer* myRender;
Camera* myCamera;
float degree = 0.0;
float degree2 = 0.0;
bool isPressed=false;
unsigned char TheKey;
int Init( ESContext *esContext )
{
	glClearColor(0.3f, 0.5f, 0.3f, 0.0f );

	myModel->InitModel("../Resources/Models/Cube2.nfg");
	myShaders->Init("../Resources/Shaders/ColorShaderVS.vs", "../Resources/Shaders/AmbientShaderFS.fs");
	myShaders3->Init("../Resources/Shaders/ColorShaderVS.vs", "../Resources/Shaders/DiffuseShaderFS.fs");
	myShaders4->Init("../Resources/Shaders/ColorShaderVS.vs", "../Resources/Shaders/SpecularShaderFS.fs");
	myShaders5->Init("../Resources/Shaders/ColorShaderVS.vs", "../Resources/Shaders/PhongShaderFS.fs");
	myShaders2->Init("../Resources/Shaders/LampShaderVS.vs", "../Resources/Shaders/LampShaderFS.fs");
	myCamera = new Camera(0.1, 10,2);
	myObj = new Object3D(myModel, myShaders);
	myObj2 = new Object3D(myModel, myShaders2);
	myRender = new Renderer;
	myCamera->SetPos(0.0, 0.3, 0.9);
	myCamera->SetRot(-0.4, 0.0, 0.0);
	return 0;
}

void Draw( ESContext *esContext )
{

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glUseProgram(myShaders2->GetProgram());
	myRender->Render(myObj2, myCamera);
	myObj2->SetPos(0.5, 0.5, 0.5);
	myObj2->SetSca(0.2, 0.2, 0.2);
	myObj2->SetRot(0.0,0.0, 0.0);
	//degree2 -= 0.01;
	myRender->SetLightPos(1.2f, 1.0f, 2.0f);
	myRender->SetModel(1.2f, 1.0f, 2.0f);
	myRender->DoDraw();

	glUseProgram(myObj->getShader()->GetProgram());

	myRender->Render(myObj,myCamera);
	myObj->SetPos(0, 0, 0.0);
	myObj->SetSca(1, 1, 1);
	myObj->SetRot(0.0, degree, 0.0);
	degree += 0.00;
	myRender->SetLightColor(1.0, 1.0, 1.0);
	myRender->SetObjectColor(1.0, 0.5, 0.31);
	myRender->InitInverseModel(1.2f, 1.0f, 2.0f);
	myRender->SetModel(1.2f, 1.0f, 2.0f);
	myRender->SetLightPos(1.2f, 1.0f, 2.0f);
	myRender->DoDraw();


	eglSwapBuffers( esContext->eglDisplay, esContext->eglSurface );
}

void Update( ESContext *esContext, float deltaTime )
{
	Vector3 mov;
	deltaTime = 0.01;
	if (isPressed) {
		if (TheKey == 'W') {
			mov = Vector3(0, 0, -deltaTime);
		}
		if (TheKey == 'S') {
			mov = Vector3(0, 0, deltaTime);
		}
		if (TheKey == 'D') {
			mov = Vector3(deltaTime, 0, 0);
		}
		if (TheKey == 'A') {
			mov = Vector3(-deltaTime, 0, 0);
		}
		if (TheKey == 'E') {
			mov = Vector3(0, deltaTime, 0);
		}
		if (TheKey == 'C') {
			mov = Vector3(0, -deltaTime, 0);
		}
		if (TheKey == '&') {
			myCamera->m_Ptransform->RotXPlus(deltaTime);
		}
		if (TheKey == '(') {
			myCamera->m_Ptransform->RotXMin(deltaTime);
		}
		if (TheKey == '%') {
			myCamera->m_Ptransform->RotYPlus(deltaTime);
		}
		if (TheKey == '\'') {
			myCamera->m_Ptransform->RotYMin(deltaTime);
		}
		if (TheKey == 'Q') {
			myCamera->m_Ptransform->RotZPlus(deltaTime);
		}
		if (TheKey == 'Z') {
			myCamera->m_Ptransform->RotZMin(deltaTime);
		}
		if (TheKey == '1') {
			myObj->m_pShader(myShaders);
		}
		if (TheKey == '2') {
			myObj->m_pShader(myShaders3);
		}
		if (TheKey == '3') {
			myObj->m_pShader(myShaders4);
		}
		if (TheKey == '4') {
			myObj->m_pShader(myShaders5);
		}

	}
	Vector4 newPos = myCamera->m_Ptransform->Position + mov;
	newPos = Vector4(mov, 1)* myCamera->m_Ptransform->GetWorldMatrix();
	myCamera->m_Ptransform->Position.x = newPos.x;
	myCamera->m_Ptransform->Position.y = newPos.y;
	myCamera->m_Ptransform->Position.z = newPos.z;
}

void Key( ESContext *esContext, unsigned char key, bool bIsPressed )
{  
	
	cout << key <<endl;
	TheKey = key;
	isPressed = bIsPressed;
}  

void CleanUp()
{
	//Cleaning up the buffers
	//glDeleteBuffers( 1, &vboId );
	//glDeleteBuffers( 1, &iboId );

	delete myCamera;
	delete myObj;
	delete myObj2;
	delete myRender;
}

int _tmain( int argc, _TCHAR* argv[] )
{
	ESContext esContext;

	esInitContext( &esContext );

	esCreateWindow( &esContext, "Hello OpenGLES 2", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH );

	if( Init( &esContext ) != 0 )
		return 0;

	esRegisterDrawFunc( &esContext, Draw );
	esRegisterUpdateFunc( &esContext, Update );
	esRegisterKeyFunc( &esContext, Key );

	esMainLoop( &esContext );

	//releasing OpenGL resources
	CleanUp();

	//identifying memory leaks
	MemoryDump();
	printf( "Press any key...\n" );
	_getch();

	return 0;
}

