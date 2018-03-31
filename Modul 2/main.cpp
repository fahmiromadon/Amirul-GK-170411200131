#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
//kotak 2x2
	glBegin(GL_QUADS);
	glColor3f(0.0,0.0,1.0);
    glVertex2f(-2.0,2.0);
    glVertex2f(0.0,2.0);
    glVertex2f(0.0,1.0);
    glVertex2f(-2.0,1.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
    glVertex2f(-2.0,1.0);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,0.0);
    glVertex2f(-2.0,0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
    glVertex2f(0.0,2.0);
    glVertex2f(2.0,2.0);
    glVertex2f(2.0,1.0);
    glVertex2f(0.0,1.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0,0.0,1.0);
    glVertex2f(0.0,1.0);
    glVertex2f(2.0,1.0);
    glVertex2f(2.0,0.0);
    glVertex2f(0.0,0.0);
	glEnd();

//Huruf A
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
    glVertex2f(1.0,1.9);
    glVertex2f(1.5,1.1);
    glVertex2f(1.3,1.1);
    glVertex2f(1.2,1.4);
    glVertex2f(0.8,1.4);
    glVertex2f(0.7,1.1);
    glVertex2f(0.5,1.1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,1.0);
    glVertex2f(1.0,1.7);
    glVertex2f(1.1,1.5);
    glVertex2f(0.9,1.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,1.0);
    glVertex2f(-2.0,-0.0);
    glVertex2f(2.0,-0.0);
	glEnd();
//kotak rectf
	glRectf(-2.0,0.0,0.0,-1.0);
	glColor3f(1.0,1.0,1.0);
	glRectf(-2.0,-1.0,0.0,-2.0);
	glColor3f(1.0,1.0,1.0);
	glRectf(0.0,0.0,2.0,-1.0);
	glColor3f(0.0,0.0,1.0);
	glRectf(0.0,-1.0,2.0,-2.0);
//huruf A rectf
    glRectf(0.5,-0.2,1.5,-0.3);
    glRectf(0.5,-0.2,0.7,-0.8);
    glRectf(1.3,-0.2,1.5,-0.8);
    glRectf(0.5,-0.4,1.5,-0.5);
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Segitiga Siku-Siku");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
