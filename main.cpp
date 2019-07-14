#include <windows.h>
#include <GL/glut.h>
#include<math.h>
#define PI 2*acos(0.0)
#include<bits/stdc++.h>

using namespace std;

GLfloat h;
GLfloat m;
GLfloat s;

void display();

void idle();

void drawGrid();

void drawQuad(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);
void drawLine(GLfloat , GLfloat , GLfloat , GLfloat);
void drawTriangle(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);

void drawCircle(GLfloat,GLfloat,GLfloat);

void drawDigits(GLfloat,GLfloat,GLfloat);

void drawBitmapText(char *str,float x,float y,float z);



void idle()
{
    glutPostRedisplay();
}

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


void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
    glBegin(GL_LINES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glEnd();
}

void drawTriangle(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glEnd();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(38, 38, 38);

	drawCircle(0.0f,0.0f,0.8f);

	glColor3ub(153, 153, 255);

	drawCircle(0.0f,0.0f,0.75f);

	//drawGrid();// makes a 2D grid
	glColor3ub(38, 38, 38);

	drawDigits(-0.02,0.0,0.65);


	//rotate hour pointer
	glPushMatrix();
    glRotatef(h,0,0,1);
	glColor3ub(230, 230, 0);//hour pointer
	drawQuad(0.2,0.055, -0.10,0.0, 0.2,-0.055, 0.48,00);
	glLoadIdentity();
	glPopMatrix();

//rotate minute pointer
	glPushMatrix();
    glRotatef(m,0,0,1);
	glColor3ub(179, 0, 0);//minute pointer
	drawQuad(0.0,0.6 , -0.055,0.35, 0.0,-0.13, 0.055,0.35);
	glLoadIdentity();
	glPopMatrix();

//rotate second pointer

    glPushMatrix();
    glRotatef(s,0,0,1);
	glColor3ub(38,38,38);//minute pointer
	drawQuad(0.02,0.60, -0.02,0.60, -0.02,-0.15 ,0.02,-0.15);
	glLoadIdentity();
	glPopMatrix();



//	pointer holder

	glColor3ub(153, 0, 0);
	drawCircle(0.0f,0.0f,0.050f);
	glColor3ub(230, 0, 115);
	drawCircle(0.0f,0.0f,0.035f);

	//decrement
	s-=0.0044;
	m-=0.00044;
	h-=0.000044;
	glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(420, 420);
    glutInitWindowPosition(1920/2 - 210,1080/2 - 210);
    glutCreateWindow("Test");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
