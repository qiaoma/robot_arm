/*
*Name: Qiao Ma
*CIN: 302599315
*/
#include <windows.h>  //suitable when using Windows 95/98/NT
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <iostream>


#include "HW2.h"

void myInit()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); 
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(1.0f, 1.0f, 1.0f,0.0f);  // background is white
		
	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-3.5*worldWidth/worldHeight, 3.5*worldWidth/worldHeight, -3.5, 3.5, 0.1, 100);
}


void drawAxes()
{
	glBegin(GL_LINES);
		//x
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0,0,0);
		glVertex3f(100,0,0);
		//y
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0,0,0);
		glVertex3f(0,100,0);
		//z
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0,0,0);
		glVertex3f(0,0,100);
	glEnd();
}

void drawHi(){
	glColor3f(1.0f, 0.0f, 1.0f);
	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, y_hi, 0.2);

	glScaled(1, 5, 1);
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, y_hi, 0.1);

	glScaled(2, 1, 1);
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, y_hi, 0);

	glScaled(1, 5, 1);
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	glPopMatrix();
			
	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, y_hi, -0.15);

	glScaled(1, 5, 1);
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	glPopMatrix();
}

void drawHand()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	float zPos = -0.12;
	for (int i = 0; i < 4; i++){
		glPushMatrix();
		glTranslated(tx, ty, tz);
		glTranslated(0, -0.7, 0);
		glRotated(angle_upperArm, 0, 0, 1);

		glRotated(angle_rotate_y, 0, 1, 0);
		glRotated(angle_rotate_x, 1, 0, 0);

		glTranslated(0, 1.6, zPos);

		glRotated(angle_lowerArm, 0, 0, 1);
		glTranslated(1.1, 0, 0);

		glRotated(angle_hand, 0, 0, 1);

		glTranslated(0.2, 0, 0);

		glScaled(3, 0.5, 0.4);
		if (wireframe){
			glutWireCube(0.1);
		}
		else{
			glutSolidCube(0.1);
		}
		glPopMatrix();
		zPos += 0.06;
	}

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, -0.85, 0);
	glRotated(angle_upperArm, 0, 0, 1);

	glRotated(angle_rotate_y, 0, 1, 0);
	glRotated(angle_rotate_x, 1, 0, 0);

	glTranslated(0, 1.6, 0.1);

	glRotated(angle_lowerArm, 0, 0, 1);
	glTranslated(1.1, 0, 0);

	glRotated(angle_thumb, 0, 0, 1);

	glTranslated(0.2, 0, 0);

	glScaled(3, 0.5, 0.8);
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	glPopMatrix();

}

void drawHandJoint()
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, -0.8, 0);
	glRotated(angle_upperArm, 0, 0, 1);

	glRotated(angle_rotate_y, 0, 1, 0);
	glRotated(angle_rotate_x, 1, 0, 0);

	glTranslated(0, 1.6, 0);
	glRotated(angle_lowerArm, 0, 0, 1);
	glTranslated(1.1, 0, 0);

	if (wireframe){
		glutWireSphere(0.2, 20, 8);
	}
	else{
		glutSolidSphere(0.2, 20, 8);
	}
	glPopMatrix();
}


void drawLowerArm()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, -0.8, 0);
	glRotated(angle_upperArm, 0, 0, 1);

	glRotated(angle_rotate_y, 0, 1, 0);
	glRotated(angle_rotate_x, 1, 0, 0);

	glTranslated(0.0, 1.6, 0);

	glRotated(angle_lowerArm, 0, 0, 1);
	glTranslated(0.6, 0, 0);

	glScaled(12, 2, 1);
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	glPopMatrix();
}

void drawArmJoint()
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, -0.8, 0);
	glRotated(angle_upperArm, 0, 0, 1);

	glRotated(angle_rotate_y, 0, 1, 0);
	glRotated(angle_rotate_x, 1, 0, 0);

	glTranslated(0, 1.6, 0);
	if (wireframe){
		glutWireSphere(0.23, 20, 8);
	}
	else{
		glutSolidSphere(0.23, 20, 8);
	}
	glPopMatrix();
}

void drawUpperArm()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	
	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, -0.8, 0.1);
	glRotated(angle_upperArm, 0, 0, 1);

	glRotated(angle_rotate_y, 0, 1, 0);
	glRotated(angle_rotate_x, 1, 0, 0);

	glTranslated(0, 0.8, 0);
	glScaled(2, 15, 1);
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	
	glPopMatrix();

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0, -0.8, -0.1);
	glRotated(angle_upperArm, 0, 0, 1);

	glRotated(angle_rotate_y, 0, 1, 0);
	glRotated(angle_rotate_x, 1, 0, 0);
	glTranslated(0, 0.8, 0);
	
	glScaled(2, 15, 1);	
	if (wireframe){
		glutWireCube(0.1);
	}
	else{
		glutSolidCube(0.1);
	}
	glPopMatrix();
}

void drawShoulderJoint()
{
	glColor3f(1.0f, green, 0.0f);
	glPushMatrix();
		glTranslated(tx, ty, tz);
		glTranslated(0, -0.8, 0);
		if (wireframe){
			glutWireSphere(0.3, 20, 8);
		}
		else{
			glutSolidSphere(0.3, 20, 8);
		}
		
	glPopMatrix();
}

void drawBase()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glTranslated(tx, ty, tz);
		glTranslated(0, -1, 0);
		glScaled(10, 1, 10);

		if (wireframe){
			glutWireCube(0.2);
		}
		else{
			glutSolidCube(0.2);
		}
		
	glPopMatrix();
}

void drawWheels(){
	glColor3f(1.0f, 1.0, 0.0f);
	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0.9, -1.2, 0.9);
	if (wireframe){
		glutWireSphere(0.1, 20, 8);
	}
	else{
		glutSolidSphere(0.1, 20, 8);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(-0.9, -1.2, 0.9);
	if (wireframe){
		glutWireSphere(0.1, 20, 8);
	}
	else{
		glutSolidSphere(0.1, 20, 8);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(0.9, -1.2, -0.9);
	if (wireframe){
		glutWireSphere(0.1, 20, 8);
	}
	else{
		glutSolidSphere(0.1, 20, 8);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glTranslated(-0.9, -1.2, -0.9);
	if (wireframe){
		glutWireSphere(0.1, 20, 8);
	}
	else{
		glutSolidSphere(0.1, 20, 8);
	}
	glPopMatrix();
}

void drawFloor(){
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glTranslated(0, -1.3, 0);
	glScaled(30, 1, 25);

	if (wireframe){
		glutWireCube(0.2);
	}
	else{
		glutSolidCube(0.2);
	}

	glPopMatrix();
}

void reset(){
	angle_upperArm = 0.0;
	angle_lowerArm = 0.0;
	angle_hand = 0.0;
	angle_thumb = 0.0;
	angle_rotate_x = 0.0;
	angle_rotate_y = 0.0;
	rotation_angle_camera = 0.0;
	view = 0;
	green = 0;
	wireframe = false;
	cameraMove = false;
	displayAxes = false;
	animate = false;
	eyex = 25.0, eyey = 25.0, eyez = 25.0;
	lookx = 0.0, looky = 0.0, lookz = 0.0;
	y_hi = 5;
}

void myIdle()
{
	if (cameraMove){
		eyex = 25 * cos(rotation_angle_camera);
		eyez = 25 * sin(rotation_angle_camera);
		rotation_angle_camera += 0.001;
	}
	if (animate){

		if (y_hi > 2.3){
			y_hi-=0.001;
		}
		if (angle_upperArm < 0){
			angle_upperArm+=0.05;
		}
		else if (angle_upperArm > 0){
			angle_upperArm-=0.05;
		}
		if (angle_lowerArm < 90){
			angle_lowerArm+=0.05;
		}
		else if (angle_lowerArm > 90){
			angle_lowerArm-=0.05;
		}
		if (angle_hand < 30){
			angle_hand += 0.05;
		}
		else if (angle_hand > 10){
			angle_hand -= 0.05;
		}
		if (angle_thumb < -30){
			angle_thumb += 0.05;
		}
		else if (angle_thumb > -10){
			angle_thumb -= 0.05;
		}
		//angle_lowerArm = 0;
		tx = 2 * cos(angle_animate);
		tz = 1.5 * sin(angle_animate);
		angle_animate += 0.001;
	}
	glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< displayWire >>>>>>>>>>>>>>>>>>>>>>
void displaySystem()
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen 
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, lookx, looky, lookz, 0.0, 1.0, 0.0);//(lookx, looky, lookz)camera look at the sun, (eyex, eyey, eyez)change camera location, 
	if (displayAxes){
		drawAxes();	
	}

	drawHi();
	drawHand();
	drawHandJoint();
	drawLowerArm();
	drawArmJoint();
	drawUpperArm();
	drawShoulderJoint();
	drawBase();
	drawWheels();
	drawFloor();
	glutSwapBuffers();
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
		case 'v':
			view++;
			view %= 3;
			if (view == 0) {
				eyex = 25;
				eyey = 25;
				eyez = 25;
			}
			else if (view == 1) {
				eyex = 25;
				eyey = 0;
				eyez = 0;
			}
			else if (view == 2) {
				eyex = 0;
				eyey = 25;
				eyez = 25;
			}
			break;
		//lift up / down the upper arm
		case 'i':
			if (green == 1 && angle_upperArm < 90){
				angle_upperArm += 1;
			}
			break;
		case 'I':
			if (green == 1 && angle_upperArm > -90){
				angle_upperArm -= 1;
			}
			break;
		//lift up / down the lower arm
		case 'j':
			if (green == 1 && angle_lowerArm < 250){
				angle_lowerArm += 1;
			}
			break;
		case 'J':
			if (green == 1 && angle_lowerArm > -70){
				angle_lowerArm -= 1;
			}
			break;
		//lift up/down hand (i.e. fingers)
		case 'n':
			if (green == 1 && angle_hand < 80){
				angle_hand += 1;
				angle_thumb = angle_hand;
			}
			break;
		case 'N':
			if (green == 1 && angle_hand > -80){
				angle_hand -= 1;
				angle_thumb = angle_hand;
			}
			break;
		//open and close hand(i.e.fingers)
		case 'm':
			if (green == 1 && angle_hand < 80 && angle_thumb > -80){
				angle_hand += 1;
				angle_thumb -= 1;
			}
			break;
		case 'M':
			if (green == 1 && angle_hand > -80 && angle_thumb < 80){
				angle_hand -= 1;
				angle_thumb += 1;
			}
			break;
		//rotate the entire arm (i.e. robot shoulder) in counter-clockwise/clockwise.
		case 'r':
			if (green == 1){
				if (angle_rotate_x < 45){
					angle_rotate_x += 1;
				}
				else{
					angle_rotate_x = 45;
				}
				angle_rotate_y += 1;
			}
			break;
		case 'R':
			if (green == 1){
				if (angle_rotate_x > -45){
					angle_rotate_x -= 1;
				}
				else{
					angle_rotate_x = -45;
				}
				angle_rotate_y -= 1;
			}
			break;
		//toggle between activation and deactivation of robot arm.
		case 'o':
			if (green == 0){
				green = 1;		
			}
			else if (green == 1){
				green = 0;
			}
			
			break;
		//toggle between displaying wireframe and solid models
		case 'u':
			if (wireframe){
				wireframe = false;
			}
			else{
				wireframe = true;
			}
			break;
		//toggle between turning on and off displaying coordinate system
		case 'c':
			if (displayAxes){
				displayAxes = false;
			}
			else{
				displayAxes = true;
			}
			break;
		//animate the robot
		case 'a':
			if (animate){
				animate = false;
			}
			else{
				animate = true;
				green = 1;
			}
			break;
		//move the camera along a fixed path such that the program can show the robot arm from various angles.
		case 's':
			if (cameraMove){
				cameraMove = false;
			}
			else{
				cameraMove = true;
			}
			break;
		case 27:
			reset();
			break;
		//exit the program
		case 'q':
			exit(0);
			break;
		case 'Q':
			exit(0);
			break;
		default:
			break;
	}	

	glutPostRedisplay();
	
}

void mySpecialKeyboard(int theKey, int mouseX, int mouseY)
{
	switch (theKey) {
		//robot moves forward on the floor
		case GLUT_KEY_UP:
			if (green == 1 && tx < 2){
				tx += 0.1;
			}			
			break;
		//robot moves backward on the floor
		case GLUT_KEY_DOWN:
			if (green == 1 && tx > -2){
				tx -= 0.1;
			}
			
			break;
		case GLUT_KEY_LEFT:
			if (green == 1 && tz < 1.5){
				tz += 0.1;
			}

			break;
		case GLUT_KEY_RIGHT:
			if (green == 1 && tz > -1.5){
				tz -= 0.1;
			}
			
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char **argv)
{	
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Homework2 - Robot Arm"); // open the screen window
	
	myInit();

	glutDisplayFunc(displaySystem);	
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialKeyboard);
	glutIdleFunc(myIdle);
	glutMainLoop();

	return( 0 );
}
