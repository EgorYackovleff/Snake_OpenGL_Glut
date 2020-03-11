#ifndef HEDER_H_ 
#define HEDER_H_ 
#include <tchar.h> 
#include <fstream> 
#include <time.h> 
#include <windows.h> 
#include <iostream> 
#include <conio.h> 
#include <GL/glut.h> 
#include <string> 

#define weight 750 
#define height 500 
#define KOL_APPELS 20 
using namespace std;

class CPlace {
public:
	int x;
	int y;
public:
	void newBlock(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void drawThisBlock() {
		glColor3f(1.0, 1.0, 1.0);
		glRectf((this->x + 0.1) * 25, (this->y + 0.1) * 25, (this->x + 0.9) * 25, (this->y + 0.9) * 25);
	}
};

class СApple {
public:
	int x;
	int y;
public:
	void newApple() {
		x = rand() % 30;
		y = rand() % 20;
	}
	void drawApple() {
		glColor3f(1.0, 0.0, 0.0);
		glRectf((x + 0.12) * 25, (y + 0.12) * 25, (x + 0.88) * 25, (y + 0.88) * 25);
	}
};

struct coordinateSnake
{
	int x;
	int y;
	int thisPos;
	int next;
	int pred;
};

class snake {
public:
	snake() {
		if (isExist) {
			throw std::exception("Obj cannot be created.");
		}
		else {
			isExist = true;
		}
	}
	~snake() {
		isExist = false;
	}

	int end();
	void tickSnake();
	void initHeap(int a = 1);
	void WindowDrawSnake();
	int ReturnX(int i); int ReturnY(int i); int Returnlife(); int ReturnLen(); int Re - turnNum();
	void LenPlas(); void NumPlas();
private:
	static bool isExist;
	int lifeSnake;
	int Prima;
	int length;
	int number;
	int Head;
	int End;
	coordinateSnake Heap[600];

};


void SetColor(int text, int background);

void processFirstMenu();// 1 меню 
void processSecondMenu();//2 меню 
void processPlaceMenu();//3 меню 

void printFirstMenu();// вывод 1 меню 
void printSecondMenu();// вывод 2 меню 
void printPlaceMenu();//вывод 3 меню 

void processRecordTable();// вывод меню рекордов 
void sortTableOfRecord(int* ownRecord, string* namesPeopleWhoScoreRecords, int quantEle - ment);//сортировка рекордов 
void addNewRecord();//добавление новых рекордов 

void view_text(string s, int x, int y, int sh = 10); // вывод текста 

void console();//первоначальное поле 
void DrawField();//отрисовка матрицы 
void display();//отрисока всего 

void Command(int key, int a, int b);
void commandSecond(unsigned char key, int a, int b);

void Tick();//шаг 
void timer(int = 0);//таймер #endif 