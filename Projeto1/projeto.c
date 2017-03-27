#include<GL\glut.h>

void Draw(void){ 
  
  // Define cor de fundo da cena
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  // Pinta a tela com a cor definida acima
  glClear(GL_COLOR_BUFFER_BIT);

  // Define vermelho como cor inicial de desenho
  glColor3f(0.6f, 0.2f, 0.2f);  

  // Define os vértices de um quadrado
  glBegin(GL_TRIANGLES);
    glVertex2f(3.0f, -15.0f);
    glVertex2f(10.0f, -19.0f);
    glVertex2f(9.0f, -16.0f);                  
  glEnd();

  glColor3f(0.6f, 0.6f, 0.2f);

  // Define os vértices de um triângulo
  glBegin(GL_TRIANGLES);
    glVertex2f(65.0f, -19.0f);
    glVertex2f(71.0f, -15.0f);
    glVertex2f(65.0f, -16.0f);
  glEnd();

  glColor3f(0.1f, 0.2f, 0.5f);

  // Define os vértices de um triângulo
  glBegin(GL_TRIANGLES);
	glVertex2f(125.0f, -19.0f);
	glVertex2f(126.0f, -15.0f);
	glVertex2f(119.0f,  -16.0f);
  glEnd();

  glFlush();     
}

void mouse(int botao, int estado, int x, int y) {

	if (botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
		//Faz ele andar pra esse lugar x e y aqui 
	}
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Projeto 1");
	glutMouseFunc(mouse);
    glutDisplayFunc(Draw);

    gluOrtho2D(0, 130, 20, -20);
        
    glutMainLoop();
}