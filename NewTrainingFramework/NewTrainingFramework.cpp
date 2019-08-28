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

Model* myModel=new Model;


Object3D* myObj;

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


	return 0;
}

void Draw( ESContext *esContext )
{

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glUseProgram(myShaders->GetProgram());




	eglSwapBuffers( esContext->eglDisplay, esContext->eglSurface );
}

void Update( ESContext *esContext, float deltaTime )
{

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

