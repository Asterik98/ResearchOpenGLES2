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
Model* myModel=new Model;
Model* myModel2 = new Model;
Texture* myTexture=new Texture;
Texture* myTexture2 = new Texture;


Object3D* myObj;
Object3D* myObj2;
Renderer * myRender;
Camera* myCamera;
float degree=0.0f;
float degree2 = 0.0f;
float degree3 = 0.0f;
float degree4 = 0.0f;
bool isPressed=false;
unsigned char TheKey;
int Init( ESContext *esContext )
{
	glClearColor(0.3f, 0.5f, 0.3f, 0.0f );

	myModel->InitModel("../Resources/Models/Woman1.nfg");
	myModel2->InitModel("../Resources/Models/Woman2.nfg");

	myShaders->Init("../Resources/Shaders/TextureShaderVS.vs", "../Resources/Shaders/TextureShaderFS.fs");
	myShaders2->Init("../Resources/Shaders/TextureShaderVS.vs", "../Resources/Shaders/LightShaderFS.fs");

	myTexture->InitTexture("../Resources/Textures/Woman1.tga");
	myTexture2->InitTexture("../Resources/Textures/Woman2.tga");

	myCamera = new Camera(0.1, 10,2);
	myObj = new Object3D(myModel, myShaders, myTexture);
	myObj2 = new Object3D(myModel2, myShaders, myTexture2);

	myRender = new Renderer;
	myCamera->SetPos(0.0, 0.3, 0.9);
	myCamera->SetRot(-0.4, 0.0, 0.0);
	return 0;
}

void Draw( ESContext *esContext )
{

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glUseProgram(myShaders->GetProgram());


	myRender->Render(myObj,myCamera);
	myObj->SetPos(-0.5, -0.5, 0.0);
	myObj->SetSca(0.5, 0.5, 0.5);
	myObj->SetRot(0.0, degree, 0.0);
	degree+=0.01;
	myRender->DoDraw();

	myRender->Render(myObj2, myCamera);
	myObj2->SetPos(0.5, -0.5, 0.0);
	myObj2->SetSca(0.5, 0.5, 0.5);
	myObj2->SetRot(0.0, degree2, 0.0);
	degree2 -= 0.01;
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

