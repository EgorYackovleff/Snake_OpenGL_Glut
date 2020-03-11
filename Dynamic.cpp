#include "Header.h" 

extern int bestResult;
extern int actionButton, actionButtonTwo;
extern int numPlace;
extern int dir;
extern СApple app[KOL_APPELS];
extern int power;
extern CPlace place[50];
extern coordinateSnake snakeCo[600];
extern snake Snake;

void Command(int key, int a, int b) {
	switch (key)
	{
	case 100: if (dir != 1) dir = 2;
		break;
	case 101: if (dir != 4) dir = 3;
		break;
	case 102: if (dir != 2) dir = 1;
		break;
	case 103: if (dir != 3) dir = 4;
		break;
	case GLUT_KEY_END: actionButtonTwo = GLUT_KEY_END;
		break;
	}
};

void commandSecond(unsigned char key, int a, int b) {
	switch (key) {
	case 27: if (actionButton == 27) actionButtonTwo = 27; actionButton = 27;
		break;
	case 13: actionButtonTwo = 13;
		break;

	}
}

void diesnake() {
	Beep(700, 700);
	Beep(700, 700);
	Beep(1000, 3000);
	if (Snake.ReturnNum() > bestResult) bestResult = Snake.ReturnNum();
	dir = 3;
	Snake.initHeap(2);
}

void NewApple(int j) {
	int sch = 0;
	if (Snake.ReturnNum() + KOL_APPELS < 20 * 30) do {
		sch = 0;
		app[j].newApple();
		for (int k = 0; k < Snake.ReturnNum(); ++k)
			if (Snake.ReturnX(k) == app[j].x && Snake.ReturnY(k) == app[j].y)
				++sch;
	} while (sch != 0);
}

void Tick() {
	if (actionButton != 27) {
		if (Snake.ReturnNum() - Snake.ReturnLen() > 0) {
			for (int j = 0; j < KOL_APPELS; ++j)
				if ((Snake.ReturnX(Snake.ReturnLen() - 1) == app[j].x) && (Snake.ReturnY(Snake.ReturnLen() - 1) == app[j].y)) { Snake.LenPlas(); NewApple(j); break; }
		}

		for (int j = 0; j < KOL_APPELS; ++j)
			if ((Snake.ReturnX(0) == app[j].x) && (Snake.ReturnY(0) == app[j].y)) {
				Beep(200, 65);
				Snake.NumPlas();
				if (Snake.ReturnNum() > bestResult) bestResult = Snake.ReturnNum();
			}
		Snake.tickSnake();

		if (Snake.ReturnX(0) < 0 || Snake.ReturnY(0) < 0 || Snake.ReturnX(0) >= 30 || Snake.ReturnY(0) >= 20) // удар об стенку 
			diesnake();

		for (int i = 0; i < numPlace; ++i)
			if (Snake.ReturnX(0) == place[i].x && Snake.ReturnY(0) == place[i].y) // удар об камни 
				diesnake();

		int sch = 0;
		for (int t = 0; t < Snake.ReturnLen(); ++t) { //удар об себя 
			for (int p = 0; p < Snake.ReturnLen(); ++p)
				if ((p != t) && (Snake.ReturnX(t) == Snake.ReturnX(p)) && (Snake.ReturnY(t) == Snake.ReturnY(p)))
					++sch;
		}
		if (sch != 0)


			diesnake();
	}
}

void timer(int) {

	display();
	if (Snake.Returnlife() == 0) {
		display();
		Beep(294, 1000 / 8);
		Beep(440, 1000 / 4);
		Beep(262 * 2, 1000 / 4);
		Beep(330 * 2, 1000 / 4);
		Beep(415, 1000 / 8);
		Beep(440, 1000);
		Beep(294, 1000 / 8);
		Beep(440, 1000 / 4);
		Beep(262 * 2, 1000 / 4);
		Beep(330 * 2, 1000 / 4);
		Beep(415, 1000 / 8);
		Beep(440, 1000);
		Beep(294, 1000 / 8);
		Beep(440, 1000 / 4);
		Beep(262 * 2, 1000 / 4);
		Beep(330 * 2, 1000 / 4);
		Beep(415, 1000 / 8);
		Beep(440, 1000);
		addNewRecord();
		console();
	}

	Tick();
	glutTimerFunc(power, timer, 0);
}