#include <glut.h>


char title[] = "[CG] Bulaev NSTU Lab 1";
GLfloat angleForCubeRotate = 0.0f;     
int rm = 15;

void initGL() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); 
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);				      
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-0.5f, 0.0f, -7.0f);
	glRotatef(angleForCubeRotate, 1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);		// Select your own color
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	// YYYYYYY
	glColor3f(0.0f, 0.0f, 0.0f);		// Select your own color
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	// ZZZZZZZZ
	glColor3f(0.0f, 0.0f, 0.0f);		// Select your own color
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	// -ZZZZZZZ
	glColor3f(0.0f, 0.0f, 0.0f);		// Select your own color
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	// -XXXXXXX
	glColor3f(0.0f, 0.0f, 0.0f);		// Select your own color
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// XXXXXXXX
	glColor3f(0.0f, 0.0f, 0.0f);		// Select your own color
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glutSwapBuffers();
	angleForCubeRotate += 0.2f;
}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(rm, timer, 0);
}

void reshape(GLsizei width, GLsizei height) { 
	if (height == 0) {
		height = 1;
	}
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);         
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}
