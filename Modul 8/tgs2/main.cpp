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
void display(void) {
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glRotatef(spin, 0.0, 0.0, 1.0);
glColor3f(1.0, 1.0, 0);
glRectf(-25.0, -25.0, 25.0, 25.0);
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
glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void mouse(int button, int state, int x, int y) {
switch (button)
{
case GLUT_LEFT_BUTTON: //apabila di klik kiri maka objek akan berotasi
if (state == GLUT_DOWN)
glRotatef(spin, 0.0, 0.0, 1.0);
break;
case GLUT_MIDDLE_BUTTON: //apabila di klik tengah maka objek akan berhenti berotasi
if (state == GLUT_DOWN)
glRotatef(spin, 0.0, 1.0, 0.0);
break;
case GLUT_RIGHT_BUTTON: //apabila di klik kanan maka objek akan berhenti berotasi
if (state == GLUT_DOWN)
glRotatef(spin, 1.0, 0.0, 0.0);
break;
default:
break;
}
}
void kuncikeyboard (unsigned char key, int x, int y) {
switch (key)
{
case 'r': //Untuk Menjalankan Putaran
glutIdleFunc(spinDisplay);
break;
case 's': //Untuk Menghentikan Putaran
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
glutCreateWindow ("Kubus Putar");
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(kuncikeyboard);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}
