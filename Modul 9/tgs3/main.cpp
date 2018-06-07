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

boolean diff = true, spec = true, amb = true;
float theta = 0.0;
float a = 0;
float b = 0;
void display() {
glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
glPushMatrix();
//glLoadIdentity();
GLfloat mat_specular[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_shininess[] = { 10.0 };
GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glRotatef(theta, 0.0, 0.0, 1.0);
glPushMatrix();
glTranslated(a, 0, b);
glPushMatrix();
glColor3d(1.0,0.0,0.0); //kanan
glScaled(0.25, 1.2, 0.25);
glTranslated(-5.5, 1.3, 0);
glutSolidCube (2.0);
glPopMatrix();
glPushMatrix(); //3
glColor3d(1.0,0.0,0.0); //kanan
glScaled(0.25, 1, 0.25);
glTranslated(2, 1.7, 0);
glutSolidCube (2.0);
glPopMatrix();
glPushMatrix(); //3
glColor3d(1.0,0.0,0.0); //tengah
glScaled(0.75, 0.25, 0.25);
glTranslated(0, 6, 0);
glutSolidCube (2.0);
glPopMatrix();
glPushMatrix();
glColor3d(1.0,0.0,0.0); //bawah
glScaled(0.75, 0.25, 0.25);
glTranslated(0, 2.5, 0);
glutSolidCube (2.0);
glPopMatrix();
glPushMatrix(); //atas
glColor3d(1.0,0.0,0.0);
glScaled(0.75, 0.25, 0.25);
glTranslated(0, 10, 0);
glutSolidCube (2.0);
glPopMatrix();
//1
glPushMatrix(); //kanan
glColor3d(1.0,0.0,0.0); //kanan
glScaled(0.25, 1.2, 0.25);
glTranslated(5.5, 1.3, 0);
glutSolidCube (2.0);
glPopMatrix();
// garis bawah
glPopMatrix();
glPopMatrix();
glFlush();
glutSwapBuffers();
}
void reshape (int w, int h) {
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity();
if (w <= h)
glOrtho (-4, 4, -4*(GLfloat)h/(GLfloat)w, 4*(GLfloat)h/(GLfloat)w, - 10.0, 10.0);
else
glOrtho (-4*(GLfloat)w/(GLfloat)h, 4*(GLfloat)w/(GLfloat)h, -4, 4, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void myinit() {
glClearColor (1.0, 0.0, 1.0, 1.0);
glColor3f(1.0, 1.0, 1.0);
GLfloat light_position_diff[] = { -1.0, 1.0, 1.0, 0.0 };
GLfloat light_position_diff_1[] = { 1.0, -1.0, -1.0, 0.0 };
GLfloat diffuse_light[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat diffuse_light_1[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat light_position_spec[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat light_position_spec_3[] = { 1.0, 1.0, 0.0, 0.0 };
GLfloat specular_light[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat specular_light_3[] = { 1.0, 0.0, 0.0, 0.0 };
GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
glLightfv(GL_LIGHT1, GL_POSITION, light_position_diff_1);
glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
glLightfv(GL_LIGHT2, GL_POSITION, light_position_spec);
glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light);
glLightfv(GL_LIGHT3, GL_POSITION, light_position_spec);
glLightfv(GL_LIGHT3, GL_SPECULAR, specular_light);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
glEnable(GL_LIGHTING);
glEnable(GL_DEPTH_TEST);
glShadeModel (GL_SMOOTH);
glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
glEnable(GL_LIGHT2);
glEnable(GL_LIGHT3);
}
void myIdle() {
theta +=0.03;
display();
}
void kuncikeyboard(unsigned char key, int mouseX, int mouseY){
if (key=='1'){
if (amb == true){
GLfloat ambient_light[] = { 0.3, 0.3, 0.3, 1.0 };
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
amb = false;
}
else{
GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
amb = true;
}
}
if (key=='2'){
if (diff == true){
glDisable(GL_LIGHT0);
diff = false;
}
else{
glEnable(GL_LIGHT0);
diff = true;
}
}
if (key=='3'){
if (spec == true){
glDisable(GL_LIGHT1);
spec = false;
}
else{
glEnable(GL_LIGHT1);
spec = true;
}
}
display();
}
void mouse(int button, int state, int x, int y) {
switch (button)
{
case GLUT_LEFT_BUTTON: //apabila di klik kiri maka objek akan berotasi
if (state == GLUT_DOWN)
glRotatef(theta, 0.0, 0.0, 1.0);
break;
case GLUT_MIDDLE_BUTTON: //apabila di klik tengah maka objek akan berhenti berotasi
if (state == GLUT_DOWN)
glRotatef(theta, 0.0, 1.0, 0.0);
break;
case GLUT_RIGHT_BUTTON: //apabila di klik kanan maka objek akan berhenti berotasi
if (state == GLUT_DOWN)
glRotatef(theta, 1.0, 0.0, 0.0);
break;
default:
break;
}
}
int main(int argc, char* argv[]) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(400,400);
glutInitWindowPosition(100,100);
glutCreateWindow("170411200131 Putar");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutIdleFunc(myIdle);
glutKeyboardFunc(kuncikeyboard);
myinit();
glutMainLoop();
return 0;
}
