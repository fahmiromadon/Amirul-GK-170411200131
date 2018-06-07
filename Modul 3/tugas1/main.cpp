#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <Math.h>
#endif

void display(void)
{
/* bersihkan layar */
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 0.0);
float t = 0.0;
glBegin(GL_POINTS);
for(t = -1.0; t<=1.0; t+=0.01){
/* x(t): 0.5 - t; y(t) = 1 + 2t */
glVertex3f (0.5 - t, 1.0 + 2.0*t, 0.0);
}
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
glutMainLoop();
return 0;
}
