#define widthnodeD 50
#define heightnodeD 50
#define WspaceD 20
#define stopDelXD x4dqueue + 200
#define stopDelXrD x1dqueue - 200
#define stopDelYD y4dqueue + 100
#include "graphics.h"
#include <dos.h>
#include <windows.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodeDeQueue
{
	string value;
	int x, y;
	bool hide;
	bool ins;
};
//
int x1dqueue = 450, y1dqueue = 400, x4dqueue = 1000, y4dqueue = 500, x3dqueue = x1dqueue, y3dqueue = y4dqueue, x2dqueue = x4dqueue, y2dqueue = y1dqueue;
//int n, nCur;
int ESPr = x4dqueue - 50, ESPf = x4dqueue - 50;
nodeDeQueue arrD[10];
int DeQueue[10];
int FrontD = 0, RearD = 0;
//int choose;

void createDeQueue()
{
	setcolor(1);
	line(x1dqueue, y1dqueue, x2dqueue, y2dqueue);
	line(x3dqueue, y3dqueue, x4dqueue, y4dqueue);
}
void createNodeD(int x, int y, const char* value)
{
	rectangle(x - 25, y - 25, x + 25, y + 25);
	drawText(x - 15, y - 10, value);
}

void createValueD()
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	nCur = n;
	system("cls");
	cout << "Nhap gia tri: ";
	cin >> arrD[0].value;
	arrD[0].x = 80;
	arrD[0].y = 250;
	arrD[0].hide = false;
	arrD[0].ins = false;
	for (int i = 1; i < n; i++)
	{
		cin >> arrD[i].value;
		arrD[i].x = arrD[i - 1].x + widthnodeD + WspaceD;
		arrD[i].y = arrD[0].y;
		arrD[i].hide = false;
		arrD[0].ins = false;
	}
}
void showNodeD()
{
	for (int i = 0; i < n; i++)
	{
		if (!arrD[i].hide)
			createNodeD(arrD[i].x, arrD[i].y, arrD[i].value.c_str());
	}
}

void TriangleFrontD(int x, int  y)
{
	setcolor(4);
	int x1 = x - 40, y1 = y + 50, x2 = x + 40, y2 = y1, x3 = x, y3 = y1 - 40;
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
	drawText(((x1 + x2 + x3) / 3) - 25, ((y1 + y2 + y3) / 3) - 10, "Front");
	setcolor(7);
}
void TriangleRearD(int x, int y)
{
	setcolor(4);
	int x1 = x - 40, y1 = y - 50, x2 = x + 40, y2 = y1, x3 = x, y3 = y1 + 40;
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
	drawText(((x1 + x2 + x3) / 3) - 25, ((y1 + y2 + y3) / 3) - 10, "Rear");
	setcolor(7);
}

void setUpDeQueue()
{
	showNodeD();
	createDeQueue();
	if (FrontD != RearD)
	{
		TriangleFrontD(x4dqueue - 60, y4dqueue);
		TriangleRearD(x1dqueue + 50, y1dqueue);
	}
}
void insertArrD(int arr[],int n,int value)
{
	for (int i = n + 1; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = value;
	n++;
}
void insertNodeRear()
{
	if (nCur > 0)
	{
		for (int i = arrD[nCur - 1].x; i < x1dqueue - 40; i += 10)
		{
			clrscr();
			arrD[nCur - 1].x = i;
			setUpDeQueue();
			Sleep(15);
		}
		for (int i = arrD[nCur - 1].y; i < y4dqueue - 40; i += 10)
		{

			clrscr();
			arrD[nCur - 1].y = i;
			setUpDeQueue();
			Sleep(15);
		}
		for (int i = arrD[nCur - 1].x; i <= ESPr; i += 10)
		{
			clrscr();
			arrD[nCur - 1].x = i;
			setUpDeQueue();
			Sleep(15);
		}
		arrD[nCur-1].ins = true;

		DeQueue[RearD] = nCur;
		RearD++;

		nCur--;
		ESPr -= widthnodeD + WspaceD;
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
void updateDeQueue(int& k)
{
	if (k < 7)
	{
		for (int i = FrontD + 1; i < RearD; i++)
		{
			arrD[DeQueue[i] - 1].x -= 10;
		}
		k++;
	}
}
void insertNodeFront()
{
	if (nCur > 0)
	{
		for (int i = arrD[nCur - 1].x; i < x4dqueue + 30; i += 10)
		{
			clrscr();
			arrD[nCur - 1].x = i;
			setUpDeQueue();
			Sleep(15);
		}
		for (int i = arrD[nCur - 1].y; i < y4dqueue - 40; i += 10)
		{

			clrscr();
			arrD[nCur - 1].y = i;
			setUpDeQueue();
			Sleep(15);
		}
		for (int i = arrD[nCur - 1].x; i > (ESPr + RearD * 70); i -= 10)
		{
			clrscr();
			arrD[nCur - 1].x = i;
			for (int j = 0; j < n; j++)
			{
				if (arrD[j].ins)
				{
					arrD[j].x -= 10;
				}
			}
			setUpDeQueue();
			Sleep(15);
		}
		arrD[nCur - 1].ins = true;

		for (int i = RearD + 1; i > 0; i--)
		{
			DeQueue[i] = DeQueue[i - 1];
		}
		DeQueue[0] = nCur;
		RearD++;

		nCur--;
		ESPr -= widthnodeD + WspaceD;
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
void logicDeleteFront(int& x, int& y)
{
	if (x < stopDelXD)
	{
		x += 10;
	}
	else if (y < stopDelYD)
	{
		y += 10;
	}
}
void updateQueueD(int& k)
{
	if (k < 7)
	{
		for (int i = FrontD + 1; i < RearD; i++)
		{
			arrD[DeQueue[i] - 1].x += 10;
		}
		k++;
	}
}
void deleteNodeFront()
{
	if (FrontD < RearD)
	{
		int k = 0;
		while (arrD[DeQueue[FrontD] - 1].x < stopDelXD || arrD[DeQueue[FrontD] - 1].y < stopDelYD)
		{
			logicDeleteFront(arrD[DeQueue[FrontD] - 1].x, arrD[DeQueue[FrontD] - 1].y);
			updateQueueD(k);
			setUpDeQueue();
			Sleep(15);
			clrscr();
		}
		arrD[DeQueue[FrontD] - 1].hide = true;
		ESPr += widthnodeD + WspaceD;
		FrontD++;
	}
	else
	{
		setfontcolor(2);
		char s[] = "QUEUE EMPTY!";
		outtextxy(250, 100, s);
		char s1[] = "\tPress ENTER to continute";
		outtextxy(250, 110, s1);
		setfontcolor(7);
		_getch();
		system("cls");
	}
}
void logicDeleteRear(int& x, int& y)
{
	if (x > stopDelXrD)
	{
		x -= 10;
	}
	else if (y < stopDelYD)
	{
		y += 10;
	}
}
void deleteNodeRear()
{
	if (FrontD < RearD)
	{
		int k = 0;
		while (arrD[DeQueue[RearD-1]-1].x > stopDelXrD || arrD[DeQueue[RearD - 1] - 1].y < stopDelYD)
		{
			logicDeleteRear(arrD[DeQueue[RearD - 1] - 1].x, arrD[DeQueue[RearD - 1] - 1].y);
			setUpDeQueue();
			Sleep(15);
			clrscr();
		}
		arrD[DeQueue[RearD - 1] - 1].hide = true;
		ESPr += widthnodeD + WspaceD;
		RearD--;
	}
	else
	{
		setfontcolor(2);
		char s[] = "QUEUE EMPTY!";
		outtextxy(250, 100, s);
		char s1[] = "\tPress ENTER to continute";
		outtextxy(250, 110, s1);
		setfontcolor(7);
		_getch();
		system("cls");
	}
}
void menu()
{
Menu:

	system("cls");
	setUpDeQueue();
	cout << "1. Insert Front\n";
	cout << "2. Insert Rear\n";
	cout << "3.Delete Front\n";
	cout << "4.Delete Rear\n";
	cout << "5. Exit\n";
	cout << "Choose: ";
	cin >> choose;
	switch (choose)
	{
	default:
		cout << "Nhap lua chon tu 1-3";
		system("cls");
		goto Menu;
	case 1:
		insertNodeFront();
		goto Menu;
	case 2:
		insertNodeRear();
		goto Menu;
	case 3:
		deleteNodeFront();
		goto Menu;
	case 4:
		deleteNodeRear();
		goto Menu;
	case 5:
		break;
	case 6:
		for (int i = 0; i < RearD; i++)
			cout << DeQueue[i] << " ";
		cout << "\nRear: " << RearD;
		system("pause");
		goto Menu;
	}
}
void DeQueueRun()
{
	system("cls");
	cout << "\t\t\t\t\t ==== DEQUE SIMULATION====";
	_getch();
	initgraph();
	createValueD();
	setUpDeQueue();
	menu();
	_getch();
}