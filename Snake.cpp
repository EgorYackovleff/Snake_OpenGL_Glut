#include "Header.h" 
extern int dir;

bool snake::isExist = false;

int snake::end()
{
	int pre = Prima;

	for (int i = 1; i < length; i++)
		pre = Heap[pre].next;
	return pre;
}

void snake::initHeap(int a)
{
	for (int i = 2; i <= length; i++) {
		Heap[i].x = 0;
		Heap[i].y = 0;
	}

	length = 2; number = 2;
	if (a == 1) lifeSnake = 3; else lifeSnake--;

	for (int i = 0; i < 600; i++) {
		Heap[i].next = -1;
		Heap[i].thisPos = i;
		Heap[i].pred = -1;
	}
	Heap[0].next = 1;
	Heap[1].pred = 0;
	Heap[2].pred = 1;
	Heap[1].next = 2;
	Heap[0].x = 0;
	Heap[0].y = 0;
	Heap[1].x = 0;
	Heap[1].y = 1;
	Head = 0; End = length;

	Prima = 1;
}

void snake::tickSnake() {
	End = length;
	int k = Heap[End].pred;
	while (Heap[k].thisPos != Head) {
		Heap[k].x = Heap[Heap[k].pred].x;
		Heap[k].y = Heap[Heap[k].pred].y;
		k = Heap[k].pred;
	}

	switch (dir) {
	case 1: ++Heap[Head].x;
		break;
	case 2: --Heap[Head].x;
		break;
	case 3: ++Heap[Head].y;
		break;
	case 4: --Heap[Head].y;
		break;
	}

}

void snake::WindowDrawSnake() {
	glColor3f(0.0, 0.0, 1.0);
	int k = Head;
	do {
		glRectf((ReturnX(k) + 0.1) * 25, (ReturnY(k) + 0.1) * 25, (ReturnX(k) + 0.9) * 25, (ReturnY(k) + 0.9) * 25);
		k = Heap[k].next;
	} while (Heap[k].thisPos != End);
}

int snake::ReturnX(int i) {
	int k = Head;
	while (Heap[k].thisPos != i) {
		k = Heap[k].next;
	}
	return Heap[k].x;
}

int snake::ReturnY(int i) {
	int k = Head;
	while (Heap[k].thisPos != i) {
		k = Heap[k].next;
	}
	return Heap[k].y;
}

int snake::Returnlife() {
	return lifeSnake;
}

int snake::ReturnLen() {
	return length;
}

int snake::ReturnNum() {
	return number;
}

void snake::LenPlas() {
	Heap[End].next = End + 1;
	Heap[End + 1].pred = End;
	length++;
}

void snake::NumPlas() {
	number++;
}