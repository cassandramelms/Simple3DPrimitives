/*
 * Cube.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: Cassandra Melms
 */

#include <GL/glut.h> //Include the freeglut header file

/* Depth and tessellation settings */
void applyDepthSetting(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to the black and opaque
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

/* Implement Display Callback Handler*/
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears color and depth buffers
	glMatrixMode(GL_MODELVIEW); // Activates the Model-View matrix

	glLoadIdentity();  // Reset the model-view matrix
	glTranslatef(-0.0f, 0.0f, -8.0f);  // Move model to the center of the world with a z depth of -7
	glRotatef(45.0f, 0.4f, -1.0f, -0.1f);  // Rotate the model on x, y, and z


	/*Create the Cube*/
	glBegin(GL_QUADS);

		// Set Front face color (Red) and vertex coordinates
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		// Set Right face color (Green) and vertex coordinates
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		// Set Top face color (Blue) and vertex coordinates
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		// Set Left face color (Yellow) and vertex coordinates
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		// Set Back face color (Dull Green) and vertex coordinates
		glColor3f(0.0f, 0.5f, 0.4f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		// Set Bottom face color (Grey) and vertex coordinates
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd(); //Ending delimiter for Cube primitive

	glutSwapBuffers(); // Swap front and back frame buffers (similar to glFlush)
}

void reshape(GLsizei width, GLsizei height){

	if (height == 0) height = 1;
		GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION); // Create a Projection matrix
	glLoadIdentity(); // Reset Projection Matrix

	// Set perspective projection, foy, aspect, zNear and zFar clipping
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3D Cube");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	applyDepthSettings();
	glutMainLoop();
	return 0;
}



