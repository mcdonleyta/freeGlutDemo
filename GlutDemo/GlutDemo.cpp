// GlutDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>

using namespace std;
int width = 800;
int height = 600;

void drawRect(float x, float y, float w, float h)
{
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
}

void switch2D()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();                                   //Reset position

	glDisable(GL_DEPTH_TEST);
}

void draw()
{
	//Clear the screen (Color and depth buffers)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Draw 2D stuff
	switch2D();

	//Points / Squares
	glColor4f(1, 0, 0, 1);
	drawRect(0, 0, 50, 50);
	glColor4f(0, 1, 0, 1);
	drawRect(50, 50, 50, 50);
	glColor4f(0, 0, 1, 0.5);
	drawRect(25, 25, 50, 50);


	glutSwapBuffers();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	width = w;
	height = h;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutCreateWindow("freeGlut Demo!");
	
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);						//Enable 3D Alpha Blending
	glEnable(GL_BLEND);

	glutReshapeFunc(resize);
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutMainLoop();

    return 0;
}

