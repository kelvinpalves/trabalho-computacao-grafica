/*
Integrantes:
- Henrique Canterle Fava
- Kelvin Pereira Alves
- Renato dos Santos Machado Júnior
- Wesley Arthur Batista

3. Utilizando o programa braco.c como referência, implemente um programa braco-garra.c. Este
programa deverá acrescente ao braço robótico uma garra com três dedos, sendo um indicador, um médio e um
polegar, como mostra a figura a seguir. O usuário deverá poder rotacionar o dedo indicador com as teclas i e I,
nos sentidos horário e anti-horário. Da mesma forma, as teclas p P deverão rotacionar o polegar, e teclas m M,
o dedo médio do robô.
*/

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, point = 0, thumb = 0, middle = 0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
	//inicializa
  	glClear (GL_COLOR_BUFFER_BIT);
  	glPushMatrix();

  	// ombro
  	glTranslatef (-1.0, 0.0, 0.0);
  	glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
  	
  	glTranslatef (1.0, 0.0, 0.0);
  	glPushMatrix();
 	glScalef (2.0, 0.4, 1.0);
  	glutWireCube (1.0);
  	glPopMatrix();

	// cotovelo
  	glTranslatef (1.0, 0.0, 0.0);
  	glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  	glTranslatef (1.0, 0.0, 0.0);

  	glPushMatrix();
  	glScalef (2.0, 0.4, 1.0);
  	glutWireCube (1.0);
  	glPopMatrix();
  	
   	// indicador
   	glPushMatrix();
   	glTranslatef (1.0, 0.2, 0.5);
   	glRotatef ((GLfloat) point, 0.0, 0.0, 1.0);
   	glTranslatef (0.3, 0.0, 0.0);
   	
   	glPushMatrix();
   	glScalef (0.6, 0.2, 0.2);
   	glutWireCube (1.0);
   	glPopMatrix();
   	glPopMatrix();
   	
   	// polegar
   	glPushMatrix();
   	glTranslatef (1.0, -0.2, 0.0);
   	glRotatef ((GLfloat) thumb, 0.0, 0.0, 1.0);
   	glTranslatef (0.3, 0.0, 0.0);
   
   	glPushMatrix();
   	glScalef (0.6, 0.2, 0.2);
   	glutWireCube (1.0);
   	glPopMatrix();
   	glPopMatrix();
   	
   	// medio
   	glPushMatrix();
   	glTranslatef (1.0, 0.2, -0.5);
   	glRotatef ((GLfloat) middle, 0.0, 0.0, 1.0);
   	glTranslatef (0.3, 0.0, 0.0);
   
   	glPushMatrix();
   	glScalef (0.6, 0.2, 0.2);
   	glutWireCube (1.0);
   	glPopMatrix();
   	glPopMatrix();
   	
   	// volta para as coordenadas iniciais
  	glPopMatrix();
  	glutSwapBuffers();
}

void reshape (int w, int h){
  	glViewport (0, 0, (GLsizei) w, (GLsizei) h);

  	glMatrixMode (GL_PROJECTION);
  	glLoadIdentity ();
  	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);

  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  	glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
  	switch (key) {
  		case 's':
    		shoulder = (shoulder + 5) % 360;
    		glutPostRedisplay();
    		break;
  		case 'S':
    		shoulder = (shoulder - 5) % 360;
    		glutPostRedisplay();
    		break;
  		case 'e':
    		elbow = (elbow + 5) % 360;
    		glutPostRedisplay();
    		break;
  		case 'E':
    		elbow = (elbow - 5) % 360;
    		glutPostRedisplay();
    		break;
    	case 'i':
	    	point = (point + 5) % 360;
         	glutPostRedisplay();
         	break;
      	case 'I':
         	point = (point - 5) % 360;
         	glutPostRedisplay();
         	break;
    	case 'p':
         	thumb = (thumb + 5) % 360;
         	glutPostRedisplay();
         	break;
      	case 'P':
         	thumb = (thumb - 5) % 360;
         	glutPostRedisplay();
         	break;
      	case 'm':
         	middle = (middle + 5) % 360;
         	glutPostRedisplay();
         	break;
      	case 'M':
         	middle = (middle - 5) % 360;
         	glutPostRedisplay();
         	break;         	
  		case 27:
    		exit(0);
    		break;
  		default:
    		break;
  	}
}

int main(int argc, char** argv){
  	glutInit(&argc, argv);
  	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  	glutInitWindowSize (1920, 1080); 
  	glutInitWindowPosition (100, 100);
  	glutCreateWindow (argv[0]);
  	init ();
  	glutDisplayFunc(display); 
  	glutReshapeFunc(reshape);
 	glutKeyboardFunc(keyboard);
  	glutMainLoop();
  	return 0;
}

