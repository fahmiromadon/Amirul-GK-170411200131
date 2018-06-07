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

float colourA = 1.1;
float colourB =0.0;
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (colourA, 1.0, colourB);
glBegin(GL_POLYGON);
glVertex2f(0.0, -0.35);
glVertex2f(-0.7, 0.2);
glVertex2f(0.7, 0.2);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(0.0, 0.7);
glVertex2f(0.5, -0.7);
glVertex2f(0.0, -0.35);
glVertex2f(-0.5, -0.7);
glEnd();
glutSwapBuffers();
}
void kuncikeyboard (GLint key, GLint x, GLint y) {
switch (key)
{
case GLUT_KEY_DOWN:
colourA = 1.0;
colourB = 0.1;
glutPostRedisplay();
break;
case GLUT_KEY_UP:
colourA = 1.0;
colourB = 1.0;
glutPostRedisplay();
break;
default:
break;
}
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Warna");
glutDisplayFunc(display);
glutSpecialFunc(kuncikeyboard);
glutMainLoop();
return 0;
}
