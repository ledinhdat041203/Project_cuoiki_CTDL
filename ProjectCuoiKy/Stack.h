#define widthrecS 50
#define heightrecS 50
#define hspaceS 10
#define wspacaeS 20
#define	stopxS x2stack - 40
#define stopyS y2stack - 40
#define stopxDeleteS 700
#define stopyDeleteS y1stack -30
#include "graphics.h"
#include <dos.h>
#include <windows.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int x1stack = 510, y1stack = 280, x2stack = 590, y2stack = 600;
int  nStack = 0;
//int n, nCur, ESP, choose;
int Stack[10];


struct nodeStack
{
	string value;
	int x, y;
	bool hide;
};

void createStack()
{
	setcolor(7);
	int x1 = x1stack, y1 = y1stack, x2 = x2stack, y2 = y2stack;
	line(x1, y1, x1, y2);
	line(x2, y1, x2, y2);
	line(x1, y2, x2, y2);
}
void createNodeS(int x, int y, const char* value)
{
	rectangle(x - 25, y - 25, x + 25, y + 25);
	drawText(x - 15, y - 10, value);
}
void logicInsertS(int& x, int& y)
{
	if (x < stopxS)
	{
		x += 10;
	}
	else if (y < stopyS)
	{
		y += 10;
	}
}
void logicDeleteS(int& x, int& y)
{
	if (y > stopyDeleteS)
		y -= 10;
	else if (x < stopxDeleteS)
	{
		x += 10;
	}
}

void showNodeS(nodeStack arr[])
{
	for (int i = 0; i < n; i++)
	{
		if (!arr[i].hide)
			createNodeS(arr[i].x, arr[i].y, arr[i].value.c_str());
	}
}
void setUpStack(nodeStack arr[])
{
	showNodeS(arr);
	createStack();
}
void insertNodeStack(nodeStack arr[])
{
	if (nCur > 0)
	{

		while (arr[nCur - 1].x != stopxS || arr[nCur - 1].y < ESP)
		{

			clrscr();
			setcolor(2);
			logicInsertS(arr[nCur - 1].x, arr[nCur - 1].y);
			if (arr[nCur - 1].y == stopyS) setcolor(0);
			setUpStack(arr);
			Sleep(10);
			//		//system("cls");
		}

		if (nCur > 0) {
			nStack++;
			Stack[nStack] = nCur;
		}
		nCur--;
		ESP -= heightrecS + hspaceS;
	}
	else
	{
		setfontcolor(2);
		char s[] = "KHONG CON PHAN TU DE INSERT";
		outtextxy(250, 100, s);
		char s1[] = "\tPress ENTER to continute";
		outtextxy(250, 110, s1);
		setfontcolor(7);
		_getch();
		system("cls");
	}
}

void deleteNodeStack(nodeStack arr[])
{
	if (nStack > 0)
	{
		while (arr[Stack[nStack] - 1].y > stopyDeleteS || arr[Stack[nStack] - 1].x != stopxDeleteS)
		{
			clrscr();
			logicDeleteS(arr[Stack[nStack] - 1].x, arr[Stack[nStack] - 1].y);
			setUpStack(arr);
			Sleep(10);
			//		//system("cls");
		}
		arr[Stack[nStack] - 1].hide = true;
		nStack--;
		ESP += heightrecS + hspaceS;
	}
	else
	{
		setfontcolor(2);
		char s[] = "KHONG CON PHAN TU TRONG STACK";
		outtextxy(250, 100, s);
		char s1[] = "\tPress ENTER to continute";
		outtextxy(250, 110, s1);
		setfontcolor(7);
		_getch();
		system("cls");
	}
}
void menuS(nodeStack arr[])
{
Menu:

	system("cls");
	setUpStack(arr);
	cout << "1. Insert\n";
	cout << "2. Delete\n";
	cout << "3. Exit\n";
	cout << "Choose: ";
	cin >> choose;
	switch (choose)
	{
	default:
		cout << "Nhap lua chon tu 1-3";
		_getch();
		goto Menu;
	case 1:
		insertNodeStack(arr);
		goto Menu;
	case 2:
		deleteNodeStack(arr);
		goto Menu;
	case 3:
		break;
	}

}
void StackRun()
{
	system("cls");
	cout << "\t\t\t\t\t ==== STACK SIMULATION====";
	_getch();
	ESP = stopyS;
	initgraph();
	cout << "Nhap so phan tu: ";
	cin >> n;
	nCur = n;
	system("cls");
	nodeStack arr[10];
	arr[0].x = 100;
	arr[0].y = 250;
	arr[0].hide = false;
	cout << "Nhap gia tri: ";
	cin >> arr[0].value;
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i].value;
		arr[i].x = arr[i - 1].x + widthrecS + wspacaeS;
		arr[i].y = arr[0].y;
		arr[i].hide = false;
	}
	menuS(arr);
}