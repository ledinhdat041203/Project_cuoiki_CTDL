#define widthnodeQ 50
#define heightnodeQ 50
#define WspaceQ 20
#define stopDelXQ x4queue + 200
#define stopDelYQ y4queue + 100
#include "graphics.h"
#include <dos.h>
#include <windows.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodeQueue
{
	string value;
	int x, y;
	bool hide;
};
///
int x1queue = 450, y1queue = 400, x4queue = 1000, y4queue = 500, x3queue = x1queue, y3queue = y4queue, x2queue = x4queue, y2queue = y1queue;
//int n, nCur;
//int ESP = x4queue - 50;
nodeQueue arrQ[10];
int Queue[10];
int FrontQ = 0, RearQ = 0;
//int choose;
void createQueue()
{
	setcolor(1);
	line(x1queue, y1queue, x2queue, y2queue);
	line(x3queue, y3queue, x4queue, y4queue);
}
void createNodeQ(int x, int y, const char* value)
{
	rectangle(x - 25, y - 25, x + 25, y + 25);
	drawText(x - 15, y - 10, value);
}
void createValueQ()
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	nCur = n;
	ESP = x4queue - 50;
	system("cls");
	cout << "Nhap gia tri: ";
	cin >> arrQ[0].value;
	arrQ[0].x = 80;
	arrQ[0].y = 250;
	arrQ[0].hide = false;
	for (int i = 1; i < n; i++)
	{
		cin >> arrQ[i].value;
		arrQ[i].x = arrQ[i - 1].x + widthnodeQ + WspaceQ;
		arrQ[i].y = arrQ[0].y;
		arrQ[i].hide = false;
	}
}
void showNodeQ()
{
	for (int i = 0; i < n; i++)
	{
		if (!arrQ[i].hide)
			createNodeQ(arrQ[i].x, arrQ[i].y, arrQ[i].value.c_str());
	}
}
void TriangleFrontQ(int x, int  y)
{
	setcolor(4);
	int x1 = x - 40, y1 = y + 50, x2 = x + 40, y2 = y1, x3 = x, y3 = y1 - 40;
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
	drawText(((x1 + x2 + x3) / 3) - 25, ((y1 + y2 + y3) / 3) - 10, "Front");
	setcolor(7);
}
void TriangleRearQ(int x, int y)
{
	setcolor(4);
	int x1 = x - 40, y1 = y - 50, x2 = x + 40, y2 = y1, x3 = x, y3 = y1 + 40;
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
	drawText(((x1 + x2 + x3) / 3) - 25, ((y1 + y2 + y3) / 3) - 10, "Rear");
	setcolor(7);
}
void setUpQueue()
{
	showNodeQ();
	createQueue();
	if (FrontQ != RearQ)
	{
		TriangleFrontQ(x4queue - 60, y4queue);
		TriangleRearQ(arrQ[Queue[RearQ-1]-1].x, arrQ[Queue[RearQ-1]-1].y-50);
	}
}

void updateQueue(int& k)
{
	if (k < 7)
	{
		for (int i = FrontQ + 1; i < RearQ; i++)
		{
			arrQ[Queue[i] - 1].x += 10;
		}
		k++;
	}
}
void insertNodeQ()
{
	if (nCur > 0)
	{
		for (int i = arrQ[nCur - 1].x; i < x1queue - 40; i += 10)
		{
			clrscr();
			arrQ[nCur - 1].x = i;
			setUpQueue();
			Sleep(15);
		}
		for (int i = arrQ[nCur - 1].y; i < y4queue - 40; i += 10)
		{

			clrscr();
			arrQ[nCur - 1].y = i;
			setUpQueue();
			Sleep(15);
		}
		for (int i = arrQ[nCur - 1].x; i < ESP; i += 10)
		{
			clrscr();
			arrQ[nCur - 1].x = i;
			setUpQueue();
			Sleep(15);
		}

		Queue[RearQ] = nCur;
		RearQ++;

		clrscr();
		setUpQueue();
		nCur--;
		ESP -= widthnodeQ + WspaceQ;
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
void logicDeleteQ(int& x, int& y)
{
	if (x < stopDelXQ)
	{
		x += 10;
	}
	else if (y < stopDelYQ)
	{
		y += 10;
	}
}
void deleteNodeQ()
{
	if (FrontQ < RearQ)
	{
		int k = 0;
		while (arrQ[Queue[FrontQ] - 1].x < stopDelXQ || arrQ[Queue[FrontQ] - 1].y < stopDelYQ)
		{
			clrscr();
			logicDeleteQ(arrQ[Queue[FrontQ] - 1].x, arrQ[Queue[FrontQ] - 1].y);
			updateQueue(k);
			setUpQueue();
			Sleep(5);
		}
		arrQ[Queue[FrontQ] - 1].hide = true;
		ESP += widthnodeQ + WspaceQ;
		FrontQ++;

		clrscr();
		setUpQueue();

	}
	else
	{
		setfontcolor(2);
		char s[] = "\tQUEUE EMPTY!";
		outtextxy(250, 100, s);
		char s1[] = "\tPress ENTER to continute";
		outtextxy(250, 110, s1);
		setfontcolor(7);
		_getch();
		system("cls");
	}
}
void menuQ()
{
Menu:

	system("cls");
	setUpQueue();
	cout << "1. Insert\n";
	cout << "2. Delete\n";
	cout << "3. Exit\n";
	cout << "Choose: ";
	cin >> choose;
	switch (choose)
	{
	default:
		cout << "Nhap lua chon tu 1-3";
		system("cls");
		goto Menu;
	case 1:
		insertNodeQ();
		goto Menu;
	case 2:
		deleteNodeQ();
		goto Menu;
	case 3:
		break;
	}
}
void QueueRun()
{
	system("cls");
	cout << "\t\t\t\t\t ==== QUEUE SIMULATION====";
	_getch();
	initgraph();
	createValueQ();
	setUpQueue();
	menuQ();
	_getch();
}
