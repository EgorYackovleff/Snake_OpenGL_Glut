#include "Header.h" 

int bestResult = 2;
int actionButton = 0, actionButtonTwo = 0;
HWND hWnd; //дискриптор окна 
int numPlace;//количество "стенок" 
int dir = 3;
СApple app[KOL_APPELS];
char ptr[5] = { '_','.','.','.','.' };
int power;
CPlace place[50];
int myIDGlutWindow;
coordinateSnake snakeCo[600];
snake Snake;

int main(int argc, char** argv) {
	glutInit(&argc, argv);//инициализация контекста OpenGL 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(weight, height + 25);
	int myGlutWindow = glutCreateWindow("My Snake");
	myIDGlutWindow = myGlutWindow;
	glutPositionWindow(130, 170);
	glutReshapeWindow(800, 550);
	hWnd = FindWindow(NULL, _T("My Snake"));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, weight, 0, height + 25);
	console();
	glutDisplayFunc(display);//установка функции прорисовки 
	glutTimerFunc(power, timer, 0);
	glutSpecialFunc(Command);
	glutKeyboardFunc(commandSecond);
	glutMainLoop();
	system("pause");
	return 0;

}