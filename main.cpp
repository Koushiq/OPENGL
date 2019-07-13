#include <windows.h>
#include <GL/glut.h>
#include<math.h>
#define PI 2*acos(0.0)
#include<bits/stdc++.h>

using namespace std;


void display();

void drawGrid();

void drawQuad();

void drawCircle(GLfloat,GLfloat,GLfloat);

void drawDigits(GLfloat,GLfloat,GLfloat);

void drawBitmapText(char *str,float x,float y,float z);

void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);

	for (c=str ; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}


void drawCircle(GLfloat x,GLfloat y,GLfloat radius)
{
	int i;
	int lineAmount = 100;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	//glColor3ub(255, 0, 191);
		for(i = 0; i <= lineAmount;i++)
        {
			glVertex2f(x + (radius * cos(i *  twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)));

		}
	glEnd();
}




void drawDigits(float x,float y,float radius)
{
    char digits[12][3]={"3","2","1","12","11","10","9","8","7","6","5","4"};
	int i;
	int lineAmount = 12;
	float twicePi = 2.0f * PI;
	//glColor3ub(255, 0, 191);
		for(i = 0; i < 12;i++)
        {
			drawBitmapText(digits[i],x + (radius * cos(i *  twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)),0.0);

		}
	glEnd();

}

void drawGrid()
{
    glColor3ub(128,128,128);
	glBegin(GL_LINES);
	for(double i=1.0;i>=-1.0;i-=0.2)
    {
        glVertex2f(1.0,(i));
        glVertex2f(-1.0,(i));
    }
    for(double i=1.0;i>=-1.0;i-=0.2)
    {
        glVertex2f((i),1.0);
        glVertex2f((i),-1.0);
    }
    glColor3ub(0, 102, 255);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);
	glEnd();
}


void drawQuad(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3)
{
    glBegin(GL_QUADS);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glVertex2f(x3,y3);

    glEnd();
}



void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(38, 38, 38);

	drawCircle(0.0f,0.0f,0.8f);

	glColor3ub(230, 230, 230);

	drawCircle(0.0f,0.0f,0.75f);

	drawGrid();// makes a 2D grid
	glColor3ub(38, 38, 38);
	drawDigits(-0.02,0.0,0.65);

	glFlush();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(420, 420);
    glutInitWindowPosition(1920/2 - 210,1080/2 - 210);
    glutCreateWindow("Test");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
