/*
*Name: Qiao Ma
*CIN: 302599315
*/

#ifndef HW2_H
#define HW2_H


#define PI 3.1415


//Global Variables
const int screenWidth = 500;	   // width of screen window in pixels
const int screenHeight = 500;	   // height of screen window in pixels

const float worldWidth = 500.0;
const float worldHeight = 500.0; 

// Initial values
GLdouble scale=1.0;
GLdouble tx=0.0, ty=0.0, tz=0.0, y_hi = 5;
GLdouble angle_upperArm = 0.0, angle_lowerArm = 0.0, angle_hand = 0.0, 
		angle_thumb = 0.0, angle_rotate_x = 0.0, angle_rotate_y = 0.0, 
		angle_animate = 0.0, rotation_angle_camera = 0.0;

// global values for camera
GLdouble eyex=25.0, eyey=25.0, eyez=25.0;
GLdouble lookx=0.0, looky=0.0, lookz=0.0;

int view=0;
float green = 0;
bool wireframe = false, cameraMove = false, displayAxes = false, animate = false;

// global values for shading
GLfloat ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat diffuse[] = {0.6f, 0.6f, 0.6f, 1.0f};
GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat shininess[] = {50.0f};

GLfloat position[] = {2.0f, 6.0f, 3.0f, 0.0f};
GLfloat lightIntensity[] = {0.7f, 0.7f, 0.7f, 1.0f};



#endif