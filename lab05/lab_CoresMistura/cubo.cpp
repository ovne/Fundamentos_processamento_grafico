 /**
 * Nome: Vinícius Souza de Oliveira
 * RA: 11201920654
 * Data: 11/10/2022
 * Programa: Elabore um programa para gerar o cubo de cores (ver o material da aula teórica).
 * cmd para execução: (copiar e colar terminal linux) 
 *   gcc -o gl_quads lab02-ex4-GL_QUADS.cpp -lglut -lGL -lGLU && ./gl_quads
*/

#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep
#include <string.h> // needed to strlen func above
#include <stdio.h>

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window; 

/* rotation angle for the triangle. */
float rtri = 0.0;

/* rotation angle for the quadrilateral. */
float rquad = 0.0;
float xrot = 1.0, yrot = 1.0, zrot = 1.0; 

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0, 0.0, 0.0, 0.0);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);		        // Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0,(GLfloat)Width/(GLfloat)Height,0.1,100.0);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(50.0,(GLfloat)Width/(GLfloat)Height,0.1, 100.0);
  glMatrixMode(GL_MODELVIEW);
}

void drawCube(void) {
   glBegin(GL_QUADS);				// start drawing the cube.
  
  // top of cube
  glColor3f(1.0,0.0,0.0);			// red
  glVertex3f( 1.0, 1.0,-1.0);		// Top Right Of The Quad (Top)A
  glColor3f(1.0,1.0,0.0);       //yellow
  glVertex3f(-1.0, 1.0,-1.0);		// Top Left Of The Quad (Top) B
  glColor3f(0.0, 1.0, 0.0);     //green
  glVertex3f(-1.0, 1.0, 1.0);		// Bottom Left Of The Quad (Top) C
  glColor3f(0.0, 0.0, 0.0);     //black
  glVertex3f( 1.0, 1.0, 1.0);		// Bottom Right Of The Quad (Top) D

  // bottom of cube 
  glColor3f(0.7, 0.0, 1.0);			// dark magenta
  glVertex3f( 1.0,-1.0, 1.0);		// Top Right Of The Quad (Bottom) D'
  glColor3f(0.0, 1.0, 1.0);     // cyan   
  glVertex3f(-1.0,-1.0, 1.0);		// Top Left Of The Quad (Bottom) C'
  glColor3f(1.0, 1.0, 1.0);     // white
  glVertex3f(-1.0,-1.0,-1.0);		// Bottom Left Of The Quad (Bottom) B'
  glColor3f(1.0, 0.0, 1.0);     // magenta
  glVertex3f( 1.0,-1.0,-1.0);		// Bottom Right Of The Quad (Bottom) A'

  // front of cube
  glColor3f(0.0,0.0,0.0);			// black
  glVertex3f( 1.0, 1.0, 1.0);		// Top Right Of The Quad (Front) B
  glColor3f(0.0, 1.0, 0.0);     // green
  glVertex3f(-1.0, 1.0, 1.0);		// Top Left Of The Quad (Front) C
  glColor3f(0.0, 1.0, 1.0);     // cyan
  glVertex3f(-1.0,-1.0, 1.0);		// Bottom Left Of The Quad (Front) C'
  glColor3f(0.7, 0.0, 1.0);     // dark magenta
  glVertex3f( 1.0,-1.0, 1.0);		// Bottom Right Of The Quad (Front) D'

  // back of cube.
  glColor3f(1.0,0.0,1.0);			// magenta
  glVertex3f( 1.0,-1.0,-1.0);		// Top Right Of The Quad (Back) A'
  glColor3f(1.0, 1.0, 1.0);     // white
  glVertex3f(-1.0,-1.0,-1.0);		// Top Left Of The Quad (Back) B'
  glColor3f(1.0, 1.0, 0.0);     // yellow
  glVertex3f(-1.0, 1.0,-1.0);		// Bottom Left Of The Quad (Back) B
  glColor3f(1.0, 0.0, 0.0);     // red
  glVertex3f( 1.0, 1.0,-1.0);		// Bottom Right Of The Quad (Back) A

  // left of cube
  glColor3f(0.0,1.0,0.0);			// green
  glVertex3f(-1.0, 1.0, 1.0);		// Top Right Of The Quad (Left) C
  glColor3f(1.0, 1.0, 0.0);     // yellow
  glVertex3f(-1.0, 1.0,-1.0);		// Top Left Of The Quad (Left) B
  glColor3f(1.0, 1.0, 1.0);     // white
  glVertex3f(-1.0,-1.0,-1.0);		// Bottom Left Of The Quad (Left) B'
  glColor3f(0.0, 1.0, 1.0);     //cyan
  glVertex3f(-1.0,-1.0, 1.0);		// Bottom Right Of The Quad (Left) C'

  // Right of cube
  glColor3f(1.0,0.0,0.0);			// red
  glVertex3f( 1.0, 1.0,-1.0);	   // Top Right Of The Quad (Right) A
  glColor3f(0.0, 0.0, 0.0);     // black
  glVertex3f( 1.0, 1.0, 1.0);		// Top Left Of The Quad (Right) D
  glColor3f(0.7, 0.0, 1.0);     // dark magenta
  glVertex3f( 1.0,-1.0, 1.0);		// Bottom Left Of The Quad (Right) D'
  glColor3f(1.0, 0.0, 1.0);     // magenta
  glVertex3f( 1.0,-1.0,-1.0);		// Bottom Right Of The Quad (Right) A'
  glEnd();					// Done Drawing The Cube
}

void drawSmoothPyramid(void){
   // draw a pyramid (in smooth coloring mode)
  glBegin(GL_POLYGON);				// start drawing a pyramid

  // front face of pyramid
  glColor3f(1.0,0.0,0.0);			// Set The Color To Red
  glVertex3f(0.0, 1.0, 0.0);		        // Top of triangle (front)
  glColor3f(0.0,1.0,0.0);			// Set The Color To Green
  glVertex3f(-1.0,-1.0, 1.0);		// left of triangle (front)
  glColor3f(0.0,0.0,1.0);			// Set The Color To Blue
  glVertex3f(1.0,-1.0, 1.0);		        // right of traingle (front)	

  // right face of pyramid
  glColor3f(1.0,0.0,0.0);			// Red
  glVertex3f( 0.0, 1.0, 0.0);		// Top Of Triangle (Right)
  glColor3f(0.0,0.0,1.0);			// Blue
  glVertex3f( 1.0,-1.0, 1.0);		// Left Of Triangle (Right)
  glColor3f(0.0,1.0,0.0);			// Green
  glVertex3f( 1.0,-1.0, -1.0);		// Right Of Triangle (Right)

  // back face of pyramid
  glColor3f(1.0,0.0,0.0);			// Red
  glVertex3f( 0.0, 1.0, 0.0);		// Top Of Triangle (Back)
  glColor3f(0.0,1.0,0.0);			// Green
  glVertex3f( 1.0,-1.0, -1.0);		// Left Of Triangle (Back)
  glColor3f(0.0,0.0,1.0);			// Blue
  glVertex3f(-1.0,-1.0, -1.0);		// Right Of Triangle (Back)

  // left face of pyramid.
  glColor3f(1.0,0.0,0.0);			// Red
  glVertex3f( 0.0, 1.0, 0.0);		// Top Of Triangle (Left)
  glColor3f(0.0,0.0,1.0);			// Blue
  glVertex3f(-1.0,-1.0,-1.0);		// Left Of Triangle (Left)
  glColor3f(0.0,1.0,0.0);			// Green
  glVertex3f(-1.0,-1.0, 1.0);		// Right Of Triangle (Left)

  glEnd();					// Done Drawing The Pyramid
}

// source: https://stackoverflow.com/a/2185753
void printText(int x, int y, float r, float g, float b, void *font, char *string)
{
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// reset the view

  glTranslatef(0.0, 0.0, -7.0);		// Move back into the screen 7 units
  glRotatef(rquad,xrot,yrot,zrot);		// Rotate The Cube On X, Y, and Z
  drawCube();

  //rtri+=15.0;					// Increase The Rotation Variable For The Pyramid
  rquad-=1.0;					// Decrease The Rotation Variable For The Cube

  // swap the buffers to display, since double buffering is used.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y) 
{
  /* avoid thrashing this call */
  usleep(100);
  
  switch (key)
  {
  case 'X':
  case 'x':
    xrot = xrot * -1;
    glutPostRedisplay();
    break;
  case 'Y':
  case 'y':
    yrot = yrot * -1;
    glutPostRedisplay();
    break;
  case 'Z':
  case 'z':
    zrot = zrot * -1;
    glutPostRedisplay();
    break;
  case ESCAPE:
    glutDestroyWindow(window);
    exit(0);
    break;
  default:
    break;
  }
}


int main(int argc, char **argv) 
{  
  /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
  glutInit(&argc, argv);  

  /* Select type of Display mode:   
     Double buffer 
     RGBA color
     Alpha components supported 
     Depth buffered for automatic clipping */  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

  /* get a 640 x 480 window */
  glutInitWindowSize(640, 480);  

  /* the window starts at the upper left corner of the screen */
  glutInitWindowPosition(0, 0);  

  /* Open a window */  
  window = glutCreateWindow("lab05 - Vinicius Oliveira");  

  /* Register the function to do all our OpenGL drawing. */
  glutDisplayFunc(&DrawGLScene);  

  /* Go fullscreen.  This is as soon as possible. */
  //glutFullScreen();

  /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(&DrawGLScene);

  /* Register the function called when our window is resized. */
  glutReshapeFunc(&ReSizeGLScene);

  /* Register the function called when the keyboard is pressed. */
  glutKeyboardFunc(&keyPressed);

  /* Initialize our window. */
  InitGL(640, 480);
  
  /* Start Event Processing Engine */  
  glutMainLoop();  

  return 1;
}