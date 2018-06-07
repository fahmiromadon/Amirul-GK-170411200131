/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static GLfloat spin = 0.0;
void kotak1() {
glColor3f(0,0,1);
glRectd(-2,-3,-1,-2);
glRectd(1,-3,2,-2);
glRectd(-3,-2,-2,-1);
glRectd(0,-2,1,-1);
glRectd(-4,-1,-3,0);
glRectd(-1,-1,0,0);
glRectd(2,-1,3,0);
glRectd(-2,0,-1,1);
glRectd(1,0,2,1);
glRectd(-3,1,-2,2);
glRectd(0,1,1,2);
glRectd(-4,2,-3,3);
glRectd(-1,2,0,3);
glRectd(2,2,3,3);
glRectd(-2,3,-1,4);
glRectd(1,3,2,4);
}
void kotak2() {
glColor3f(0.0,1.0,1.0);
glRectd(-4,-3,-3,-2);
glRectd(-1,-3,0,-2);
glRectd(2,-3,3,-2);
glRectd(-2,-2,-1,-1);
glRectd(1,-2,2,-1);
glRectd(-3,-1,-2,0);
glRectd(0,-1,1,0);
glRectd(-4,0,-3,1);
glRectd(-1,0,0,1);
glRectd(2,0,3,1);
glRectd(-2,1,-1,2);
glRectd(1,1,2,2);
glRectd(-3,2,-2,3);
glRectd(0,2,1,3);
glRectd(-4,3,-3,4);
glRectd(-1,3,0,4);
glRectd(2,3,3,4);
}
void kotak3() {
glColor3f(1,1,0);
glRectd(-3,-3,-2,-2);
glRectd(0,-3,1,-2);
glRectd(-4,-2,-3,-1);
glRectd(-1,-2,0,-1);
glRectd(2,-2,3,-1);
glRectd(-2,-1,-1,0);
glRectd(1,-1,2,0);
glRectd(-3,0,-2,1);
glRectd(0,0,1,1);
glRectd(-4,1,-3,2);
glRectd(-1,1,0,2);
glRectd(2,1,3,2);
glRectd(-2,2,-1,3);
glRectd(1,2,2,3);
glRectd(-3,3,-2,4);
glRectd(0,3,1,4);
}
void display(void) {
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glRotatef(spin, 0.0, 0.0, 1.0);
kotak1();
kotak2();
kotak3();
glPopMatrix();
glutSwapBuffers();
}
void spinDisplay(void) {
spin = spin + 0.01;
if (spin > 360.0)
spin = spin - 360.0;
glutPostRedisplay();
}
void init(void) {
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void reshape(int w, int h) {
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-7.0, 7.0, -7.0, 7.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void mouse(int button, int state, int x, int y) {
switch (button)
{
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN)
glutIdleFunc(spinDisplay);
break;
case GLUT_MIDDLE_BUTTON:
case GLUT_RIGHT_BUTTON:
if (state == GLUT_DOWN)
glutIdleFunc(NULL);
break;
default:
break;
}
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (400, 400);
glutInitWindowPosition (100, 100);
glutCreateWindow ("CheckerBoard Putar");
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}
