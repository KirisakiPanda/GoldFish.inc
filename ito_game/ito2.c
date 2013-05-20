/*
����ѥ�����ˡ��
gcc ito2.c -o ito2 -O3 -I/usr/X11R6/include -L/usr/X11R6/lib -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
 */

#include <stdlib.h>
#include <stdio.h>
#include <GLUT/glut.h>
//#include <GLUT/gl.h>
//#include <GLUT/glu.h>
#include <math.h>
#define ESCKEY 27  /* Esc�����Υ����� */
#define N 50
#define SPEED 0.0008

double absolute(double);
int equal(double, double);

double movey = 0., sy = 0., ay = -0.000001;
double ito[N], harix = 2.0, hariy = 0.0;
int chien = 0, count = 0, flag = 1;
  /* global�ѿ��Ȥ������ */

void display( void ){ /* ������� */
  int i;
  char str[100];
  void *font = GLUT_BITMAP_HELVETICA_18;

  glClear( GL_COLOR_BUFFER_BIT );  /* ���̤Υ��ꥢ */

  glColor3f( 1.0, 1.0, 1.0 ); /* ������� */
  glBegin( GL_LINE_STRIP ); 
  for(i = 0; i < N-1; i++){
    glVertex2d( i*-1.0/N, ito[i] );
  }
  glEnd(); 

  glColor3f( 0.5, 0.5, 0.5 ); /* ���迧��r=1,g=1,b=1(�Ĥޤ���)������ */
  glBegin( GL_POLYGON ); /* �ݥꥴ������賫�� */
    glVertex3f( harix+0.01, hariy+0.1, 0.0 ); /* ����ĺ�� */
    glVertex3f( harix-0.01, hariy+0.1, 0.0 ); /* ����ĺ�� */
    glVertex3f( harix-0.01, -1.0, 0.0 ); /* ����ĺ�� */
    glVertex3f( harix+0.01, -1.0, 0.0 ); /* ����ĺ�� */
    /* x,y��ɸ�Τ�����(z=0)����2�����޷���ɽ�� */
  glEnd(); /* �ݥꥴ������轪λ */

  glColor3f( 0.0, 0.0, 0.0 ); /* ���迧��r=1,g=1,b=1(�Ĥޤ���)������ */
  glBegin( GL_POLYGON ); /* �ݥꥴ������賫�� */
    glVertex3f( harix+0.005, hariy+0.08, 0.0 ); /* ����ĺ�� */
    glVertex3f( harix-0.005, hariy+0.08, 0.0 ); /* ����ĺ�� */
    glVertex3f( harix-0.005, hariy-0.08, 0.0 ); /* ����ĺ�� */
    glVertex3f( harix+0.005, hariy-0.08, 0.0 ); /* ����ĺ�� */
    /* x,y��ɸ�Τ�����(z=0)����2�����޷���ɽ�� */
  glEnd(); /* �ݥꥴ������轪λ */

  sprintf(str, "count:%03d", count);
  glColor3f( 1.0, 1.0, 1.0 ); /* ������� */
  glRasterPos3f(0.0, 0.9, 0.0);
  {
    char* p = str;
    while(*p){
      glutBitmapCharacter(font, *p);
      ++p;
    }
  }
  glutSwapBuffers(); /* ���������λ�����������оݥե졼��Хåե�������
			(�����ǽ��Ʋ��̤�ɽ�������) */
}

void idle( void ){  /* ������������Ƥ��ʤ����ν��� */
  int i;

  sy += ay;
  movey += sy;
  if(equal(harix, 0) && flag){
    count++;
    flag = 0;
  }
  if(sy < -SPEED) sy = -SPEED;
  if(sy >  SPEED) sy =  SPEED;
  if(harix < -1.0){
    harix = 1.0;
    hariy = -sy*1000;
    flag = 1;
  }
  if(movey < -1 || movey > 1 ||
     (equal(harix, 0) && absolute(movey-hariy) > 0.08)){
    for(i = 0; i < N; i++) ito[i] = 0;
    sy = 0;
    harix = 2.;
    hariy = 0.;
    movey = 0.;
    count = 0;
    flag = 1;
  }

  ito[0] = movey;
  chien++;
  if(chien == 3000/N){
    chien = 0;
    for(i = N-2; i >= 0; i--)
      ito[i+1] = ito[i];
    harix-=1.0/N;
  }
  
  glutPostRedisplay(); /* ������̿�� */
}


void myKbd( unsigned char key, int x, int y ){ /* �����ܡ��ɳ����ߤν��� */
  switch( key ){ /* key�������줿�����ܡ��ɤΥ����ɤ�ɽ�� */
    case ESCKEY: /* Esc�����������줿��� */
      exit(0);
    case 'r': /* r�����������줿��� */
      ay = -ay;
  }
  
  glutPostRedisplay(); /* ������̿�� */
}


void myKbdup( unsigned char key, int x, int y ){ /* �����ܡ��ɳ����ߤν��� */
  switch( key ){
    case 'r':
      ay = -ay;
  }
  
  glutPostRedisplay(); /* ������̿�� */
}


void myInit ( char *progname ){ /* ���襦����ɥ����ν������ */
  int width = 500, height = 500; /* ������ɥ����������ѿ� */
  int i;
  for(i = 0; i < N; i++)
    ito[i] = 0.0;

  glutInitWindowPosition( 0, 0 ); /* ������ɥ��κ���ΰ��� */
  glutInitWindowSize( width, height ); /* ������ɥ��Υԥ������(������) */
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA ); 
    /* ������ɥ��Υ⡼��(���֥�Хåե���RGBA) */
  glutCreateWindow( progname ); /* ������ɥ��򥪡��ץ󤹤�ؿ� */
  glClearColor ( 0.0, 0.0, 0.0, 1.0 ); /* ������ɥ����طʿ�������(��) */
  glutKeyboardFunc( myKbd ); 
  glutKeyboardUpFunc( myKbdup ); 
    /* �����ܡ��ɳ����ߤ����ä����μ¹Դؿ�(mykbd)�λ��� */

  glMatrixMode( GL_PROJECTION ); /* ����⡼�� */
  glLoadIdentity();
  glOrtho( -1.0, 1.0, -1.0, 1.0, -1.0, 1.0 ); /* �����ϰϡ�(-1,1)��(1,-1) */

  glutIgnoreKeyRepeat(GL_TRUE);
}

double absolute(double a){
  if(a < 0.0)
    return -a;
  else return  a;
}

int equal(double a, double b){
  if(absolute(b-a) < 1.0e-7)
    return 1;
  else return 0;
}

int main( int argc, char** argv ){
  glutInit( &argc, argv ); /* �����ƥ����� */
  myInit( argv[0] ); /* �桼������ν���� */
  glutDisplayFunc( display ); /* ����(1��) */
  glutIdleFunc( idle ); /* ���������ߤ��ʤ����ν�������� */
  glutMainLoop(); /* ̵�¥롼��(�����������Ԥ�) */
  return( 0 );
}
