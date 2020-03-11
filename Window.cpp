#include "Header.h" 

extern int bestResult;
extern int actionButton, actionButtonTwo;
extern HWND hWnd;
extern int numPlace;
extern СApple app[KOL_APPELS];
extern CPlace place[50];
extern coordinateSnake snakeCo[600];
extern snake Snake;

void console() {
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	ShowWindow(hWnd, SW_HIDE);
	Snake.initHeap()
		for (int i = 0; i < KOL_APPELS; ++i)
			app[i].newApple();
	processFirstMenu();
	processSecondMenu();
	processPlaceMenu();
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	ShowWindow(hWnd, SW_SHOW);
	SetForegroundWindow(hWnd);

}

void DrawField() {
	glColor3f(25.0, 15.0, 0.0);
	glBegin(GL_LINES);
	for (int i = 0; i < weight; i += 25) {
		glVertex2f(i, 0); glVertex2f(i, height);
	}
	for (int i = 0; i < height + 1; i += 25) {
		glVertex2f(0, i); glVertex2f(weight, i);
	}
	glEnd();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT); // установка фона 

	if (actionButton == 27) {
		glClearColor(255, 255, 255, 1);
		glColor3f(0.0, 0.0, 0.0);
		view_text("press \"enter\" for continue", 540, 5 - 180, 13);
		view_text("press \"end\" for exit", 500, 5 - 260, 13);
		if (actionButtonTwo == 13) {
			glClearColor(0, 0, 0, 1);
			actionButton = 0;
			actionButtonTwo = 0;
		}
		else if (actionButtonTwo == 27) {
			glClearColor(0, 0, 0, 1);
			actionButton = 0;
			actionButtonTwo = 0;
			console();
		}

	}
	else
		if (Snake.Returnlife() == 0) {
			glColor3f(0.0, 1.0, 0.0);
			view_text("You", 400, 5 - 200);
			view_text("are", 400, -10 - 200);
			view_text("lose", 410, -25 - 200);

		}
		else {
			DrawField();
			Snake.WindowDrawSnake();
			for (int i = 0; i < KOL_APPELS; ++i)
				app[i].drawApple();
			for (int i = 0; i < numPlace; ++i) {
				place[i].drawThisBlock();
			}
			glColor3f(1.0, 1.0, 1.0);
			view_text("Your lifes:", 150, 5);
			view_text("Your score:", 750, 5);
			glRasterPos2f(weight - 630, height + 5);//вывод очков 
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ((Snake.ReturnNum() - 2) / 100) + 48);
			glRasterPos2f(weight - 620, height + 5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (((Snake.ReturnNum() - 2) / 10) % 10) + 48);
			glRasterPos2f(weight - 610, height + 5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ((Snake.ReturnNum() - 2) % 10) + 48);
			glRasterPos2f(weight - 597, height + 5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ((int)'|'));
			glRasterPos2f(weight - 590, height + 5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ((bestResult - 2) / 100) + 48);
			glRasterPos2f(weight - 580, height + 5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (((bestResult - 2) / 10) % 10) + 48);
			glRasterPos2f(weight - 570, height + 5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ((bestResult - 2) % 10) + 48);
			for (int i = 10; i <= Snake.Returnlife() * 10; i += 10) { //вывод жизней 
				glRasterPos2f(weight - 50 + i, height + 5);
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 223);
			}

		}
	glFlush();
}