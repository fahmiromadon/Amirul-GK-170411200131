#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <Math.h>
#endif
void myinit()
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1.0, 10.0, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
}
void display(void)
{
/* bersihkan layar */
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 0.0);
float x = 0.0;
float A = 3;
float B = 4;
float C = 0.5;
float D = 2;
glBegin(GL_LINE_STRIP);
//perhitungan sudut di openGL menggunakan radian, bukan derajat
for(x=0.0; x<=6.28; x+=0.1)
{
glVertex2f(x,A*cos(B*x + C) + D);
}
glEnd();
glBegin(GL_LINES);
glVertex3f(-10.0,0.0,0.0);
glVertex3f(10.0,0.0,0.0);
glVertex3f(0.0,-10.0,0.0);
glVertex3f(0.0,10.0,0.0);
glEnd();
glFlush ();
}
void kunci(unsigned char key, int x, int y)
{
switch (key)
{
/* aplikasi berhenti ketika tombol q ditekan */
case 27 :
case 'q':
exit(0);
break;
}
glutPostRedisplay();
}
int main(int argc, char *argv[])
{
glutInitWindowSize(400,400);
glutInitWindowPosition(100,100);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Primitif");
glutDisplayFunc(display);
glutKeyboardFunc(kunci);
myinit();
glutMainLoop();
return 0;
}
