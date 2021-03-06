#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
boolean diff = true, spec = true, amb = true;


float d = 0;
float x2 = 0;
float y2 = 0;
float z2 = 0;

void kubus(float s)
{
    float x1=(s/2);
    float y1=(s/2);
    float z1=(s/2);
    glColor3d(0,0.5,1);
    glBegin(GL_POLYGON);
    glVertex3d(-x1,y1,z1);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,-y1,z1);
    glVertex3d(-x1,-y1,z1);
    glEnd();
    glColor3d(0,0.5,1);
    glBegin(GL_POLYGON);
    glVertex3d(-x1,y1,-z1);
    glVertex3d(x1,y1,-z1);
    glVertex3d(x1,-y1,-z1);
    glVertex3d(-x1,-y1,-z1);
    glEnd();
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y1,-z1);
    glVertex3d(x1,-y1,-z1);
    glVertex3d(x1,-y1,z1);
    glEnd();
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3d(-x1,-y1,z1);
    glVertex3d(-x1,-y1,-z1);
    glVertex3d(-x1,y1,-z1);
    glVertex3d(-x1,y1,z1);
    glEnd();
    glColor3d(1,0,1);
    glBegin(GL_POLYGON);
    glVertex3d(-x1,y1,z1);
    glVertex3d(-x1,y1,-z1);
    glVertex3d(x1,y1,-z1);
    glVertex3d(x1,y1,z1);
    glEnd();
    glColor3d(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3d(-x1,-y1,z1);
    glVertex3d(-x1,-y1,-z1);
    glVertex3d(x1,-y1,-z1);
    glVertex3d(x1,-y1,z1);
    glEnd();

}

void kotak(float m, float n , float o){

    glBegin(GL_POLYGON);
    glColor3f(m,n,o);
    glVertex3d(0,-6,9.1 );
    glVertex3d(0,-1,9.1);
    glVertex3d(3,-1,9.1);
    glVertex3d(3,-6,9.1);
    glEnd();
}

void huruf(float p, float q, float r){

    glBegin(GL_POLYGON);
	glColor3f(p,q,r);
    glVertex3f(1.0,1.9,0);
    glVertex3f(1.5,1.1,0);
    glVertex3f(1.3,1.1,0);
    glVertex3f(1.2,1.4,0);
    glVertex3f(0.8,1.4,0);
    glVertex3f(0.7,1.1,0);
    glVertex3f(0.5,1.1,0);
	glEnd();
}

void segitiga(float s, float t, float u){
	glBegin(GL_TRIANGLES);
	glColor3f(s,t,u);
    glVertex3f(1.0,1.7,0);
    glVertex3f(1.1,1.5,0);
    glVertex3f(0.9,1.5,0);
	glEnd();
}

void nim(float e, float f, float g){
	glBegin(GL_POLYGON);
	glColor3f(e,f,g);
    glVertex3d(-1.5,1.0,0);
    glVertex3d(-1.0,1.0,0);
    glVertex3d(-1.0,-0.5,0);
    glVertex3d(-1.5,-0.5,0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(e,f,g);
    glVertex3d(-0.7,1.0,0);
    glVertex3d(0.5,1.0,0);
    glVertex3d(0.5,0.7,0);
    glVertex3d(-0.7,0.7,0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(e,f,g);
    glVertex3d(-0.7,0.4,0);
    glVertex3d(0.5,0.4,0);
    glVertex3d(0.5,0.1,0);
    glVertex3d(-0.7,0.1,0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(e,f,g);
    glVertex3d(-0.7,-0.2,0);
    glVertex3d(0.5,-0.2,0);
    glVertex3d(0.5,-0.5,0);
    glVertex3d(-0.7,-0.5,0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(e,f,g);
    glVertex3d(0.2,1.0,0);
    glVertex3d(0.5,1.0,0);
    glVertex3d(0.5,-0.5,0);
    glVertex3d(0.2,-0.5,0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(e,f,g);
    glVertex3d(0.8,1.0,0);
    glVertex3d(1.3,1.0,0);
    glVertex3d(1.3,-0.5,0);
    glVertex3d(0.8,-0.5,0);
	glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(10);
    glRotated(d,x2,y2,z2);

GLfloat mat_specular[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_shininess[] = { 10.0 };
GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    glPushMatrix();
    glTranslated(-7.0,-18.0,-9.1);
    glScaled(7.0,7.0,0);
    huruf(1,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.0,-18.0,-9.2);
    glScaled(7.0,7.0,0);
    segitiga(0,0.5,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(9.1,-9.0,-1);
    glScaled(5.0,5.0,5);
    glRotated(90,0,1,0);
    nim(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.5,0);
    glBegin(GL_POLYGON);
    glVertex3d(-9,-15,9.1);
    glVertex3d(9,-15,9.1);
    glVertex3d(25,-25,9.1);
    glVertex3d(-25,-25,9.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-2,0);
    glColor3f(0.9,0.7,0.2);
    glScaled(0.8, 1.0, 0.8);
    glRotated(45, 0, 1, 0);
    glRotated(-90, 1, 0, 0);
    //glutWireCone(2,3,4,1);
    glutSolidCone(24,15,4,24);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-6,0);
    kubus(18);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glTranslated(-15,-15,25);
    glScaled(0.5,7,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glTranslated(15,-15,25);
    glScaled(0.5,7,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-15,-6.7,25);
    glScaled(0.5,0.5,1);
    glutSolidSphere(3,7,9);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(15,-6.7,25);
    glScaled(0.5,0.5,1);
    glutSolidSphere(3,7,9);
    glPopMatrix();

    // pintu
    glPushMatrix();
    glTranslated(-2.0,-4,0);
    glScaled(1.5,1.8,1);
    kotak(1,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.0,-11,0.1);
    glScaled(0.25,0.125,1);
    kotak(0,0,0);
    glPopMatrix();

    //jendela
    glPushMatrix();
    glTranslated(-13.6,-5.5,8);
    glScaled(0.5,0.3,1);
    glRotated(90,0,1,0);
    kotak(0,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-13.6,-5.5,2);
    glScaled(0.5,0.3,1);
    glRotated(90,0,1,0);
    kotak(0,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-13.6,-5.5,-4);
    glScaled(0.5,0.3,1);
    glRotated(90,0,1,0);
    kotak(0,1,0);
    glPopMatrix();

    glFlush();
}

void kunci(unsigned char key, int x, int y)
{
    switch (key)
    {

//    case 27 :
    case 'q':
        exit(0);
        break;
    case 'a':
        d=1;
        x2=1;
        y2=0;
        z2=0;
        glutPostRedisplay();
        break;
    case 's':
        d=1;
        x2=0;
        y2=1;
        z2=0;
        glutPostRedisplay();
        break;
    case 'd':
        d=1;
        x2=0;
        y2=0;
        z2=1;
        glutPostRedisplay();
        break;
    }
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

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glOrtho(-25.0,25.0,-25.0,25.0,-25.0,25.0);
GLfloat light_position_diff[] = { -1.0, 1.0, 1.0, 0.0 };
GLfloat diffuse_light[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat light_position_spec[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat specular_light[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
glEnable(GL_LIGHTING);
glEnable(GL_DEPTH_TEST);
glShadeModel (GL_SMOOTH);
glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Kubus");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(kunci);
    glutMainLoop();
    return 0;
}
