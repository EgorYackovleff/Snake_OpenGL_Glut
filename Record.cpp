#include "Header.h" 

extern int bestResult;
extern int actionButtonTwo;
extern HWND hWnd;

void sortTableOfRecord(int* ownRecord, string* namesPeopleWhoScoreRecords, int quantEle - ment) {
	int swapInt = 0;
	string swapString = "";
	for (int i = 0; i < quantElement - 1; ++i) {
		for (int j = 0; j < quantElement - i - 1; ++j) {
			if (*(ownRecord + j) < *(ownRecord + j + 1)) {
				swapInt = *(ownRecord + j);
				*(ownRecord + j) = *(ownRecord + j + 1);
				*(ownRecord + j + 1) = swapInt;
				swapString = *(namesPeopleWhoScoreRecords + j);
				*(namesPeopleWhoScoreRecords + j) = *(namesPeopleWhoScoreRecords + j + 1);
				*(namesPeopleWhoScoreRecords + j + 1) = swapString;
			}
		}
	}
}
void addNewRecord() {
	system("cls");
	actionButtonTwo = 0;
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	ShowWindow(hWnd, SW_HIDE);
	ifstream fopen("own_records.txt");
	ifstream fTwoOpen("names_people_who_score_records.txt");;
	int flag = 0;
	string namePlayer;
	bool parametr = true;
	int quantElement = 0;
	int* ownRecord = (int*)malloc(sizeof(int) * (flag + 1));
	while (!fopen.eof()) {
		++flag;
		ownRecord = (int*)realloc(ownRecord, sizeof(int) * (flag + 1));
		fopen >> *(ownRecord + flag - 1);
	}
	quantElement = flag;
	string* namesPeopleWhoScoreRecords = new string[quantElement + 2];
	for (int i = 0; i < quantElement; ++i) {
		fTwoOpen >> *(namesPeopleWhoScoreRecords + i);
	}
	cout << "if you do not want to go down in history instead of a place '-'. . ." << endl;
	cout << "Please select your name: ";
	cin >> namePlayer;
	if (namePlayer == "-") return;
	for (int i = 0; i < quantElement; ++i)
		if (namePlayer == *(namesPeopleWhoScoreRecords + i)) {
			parametr = false;
			break;
		}
	if (parametr == true) cout << "Thank you";
	while (parametr != true) {
		system("cls");
		cout << "This name exists. . . please try again: ";
		cin >> namePlayer;
		if (namePlayer == "-") return;
		parametr = true;
		for (int i = 0; i < quantElement; ++i)
			if (namePlayer == *(namesPeopleWhoScoreRecords + i)) {
				parametr = false;
				break;
			}
	}
	if (parametr == true) cout << "Thank you";
	++quantElement;
	ownRecord = (int*)realloc(ownRecord, sizeof(int) * (quantElement + 1));
	*(ownRecord + quantElement - 1) = bestResult - 2;
	*(namesPeopleWhoScoreRecords + quantElement - 1) = namePlayer;
	sortTableOfRecord(ownRecord, namesPeopleWhoScoreRecords, quantElement);
	ofstream fOneWrite("own_records.txt");
	ofstream fTwoWrite("names_people_who_score_records.txt");
	for (int i = 0; i < quantElement; ++i) {
		if (i != (quantElement - 1))
			fOneWrite << *(ownRecord + i) << endl;
		else fOneWrite << *(ownRecord + i);
		if (i != (quantElement - 1))
			fTwoWrite << *(namesPeopleWhoScoreRecords + i) << endl;
		else fTwoWrite << *(namesPeopleWhoScoreRecords + i);
	}
	fOneWrite.close();
	fTwoWrite.close();
	fopen.close();
	fTwoOpen.close();
	free(ownRecord);
	delete[quantElement + 2] namesPeopleWhoScoreRecords;
}