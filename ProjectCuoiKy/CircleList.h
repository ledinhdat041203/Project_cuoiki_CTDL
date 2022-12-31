#include "graphics.h"
#include <dos.h>
#include <windows.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define widthNode 100
#define Wspace 20

struct nodeCList
{
	string value;
	int x, y;
	bool dlte;
};
nodeCList CList[10];
int nList = 0;
void arrow(int x, int y, bool dlte)
{
	if (!dlte)
	{
		line(x, y, x + 51, y);
		line(x + 46, y - 5, x + 51, y);
		line(x + 46, y + 5, x + 51, y);
	}
}
void arrowUp(int x, int y)
{
	line(x, y, x, y-51);
	line(x, y-51 , x -5, y-45);
	line(x , y -51, x +5, y-45);
}
void createNodeCircle(int x, int y, const char* mess, bool dlte)
{
	setcolor(0);
	rectangle(x - 40, y - 20, x + 40, y + 20);
	line(x + 15, y - 21, x + 15, y + 19);
	setcolor(2);
	circle(x + 27, y, 6);
	arrow(x + 27, y, dlte);
	drawText(x - 25, y - 10, mess);
	setcolor(0);
}
void createCircle()
{
	int x = CList[nList - 1].x, y = CList[nList - 1].y;
	if (nList > 0)
	{
		setcolor(6);
		circle(x + 83, y, 6);
		line(x + 83, y, x + 83, y + 71);
		line(x + 83, y + 71, CList[0].x-10, y+71);
		arrowUp(CList[0].x-10, y + 71);
		setcolor(0);
	}
}
void showNodeCL()
{
	if (nList > 0)
	{
		for (int i = 0; i < nList; i++)
		{
			createNodeCircle(CList[i].x, CList[i].y, CList[i].value.c_str(), CList[i].dlte);
		}
	}

}
void insertArrCL(int k, string value)
{
	for (int i = nList - 1; i >= k; i--)
	{
		CList[i + 1] = CList[i];
	}
	CList[k].value = value;
	CList[k].y = 160;
	nList++;
}
void logicInsCL(int k, int& z)
{
	if (z < 6)
	{
		for (int j = nList - 1; j > k; j--)
		{
			CList[j].x += 20;
		}
		z++;
	}
}
void insertNodeCL()
{
	string value;
	int k;
	cout << "Nhap Node: ";
	cin >> value;
	cout << "Position: ";
	cin >> k;
	if (nList == 0 || k >= nList)
	{
		CList[nList].value = value;
		if (nList == 0)
			CList[nList].x = 150 + nList * (widthNode + Wspace);
		else
		{
			CList[nList].x = CList[nList - 1].x + (widthNode + Wspace);
		}
		CList[nList].y = 160;
		CList[nList].dlte = false;
		nList++;
		for (int i = CList[nList - 1].y; i < 220; i += 10)
		{
			clrscr();
			CList[nList - 1].y = i;
			showNodeCL();
			Sleep(15);
		}
		createCircle();
	}
	else
	{
		insertArrCL(k, value);
		int z = 0;
		for (int i = CList[k].y; i < 220; i += 10)
		{
			//system("cls");
			clrscr();
			CList[k].y = i;
			logicInsCL(k, z);
			showNodeCL();
			Sleep(15);
		}
		createCircle();
	}
}
void deleteArrCL(int k)
{
	for (int i = k; i < nList - 1; i++)
	{
		CList[i] = CList[i + 1];
	}
	nList--;
}
void logicDelCL(int k, int& z)
{
	if (z < 6)
	{
		for (int i = k + 1; i < nList; i++)
		{
			CList[i].x -= 20;
		}
		z++;
	}
}
void deleteNodeCL()
{

	if (nList > 0)
	{
		int k;
		cout << "Delete Node: ";
		cin >> k;
		if (k >= nList)	k = nList - 1;
		CList[k].dlte = true;
		int z = 0;
		for (int i = CList[k].y; i < 340; i += 20)
		{
			clrscr();
			CList[k].y = i;
			logicDelCL(k, z);
			showNodeCL();
			Sleep(15);
		}

		deleteArrCL(k);
		createCircle();
	}
	else
	{
		setfontcolor(2);
		char s[] = "LINKEDLIST EMPTY!";
		outtextxy(250, 100, s);
		char s1[] = "Press ENTER to continute";
		outtextxy(220, 110, s1);
		setfontcolor(7);
		_getch();
		system("cls");
	}
}
void CircleListRun()
{

	system("cls");
	cout << "\t\t\t\t\t ==== CIRCLELIST SIMULATION====";
	_getch();
	initgraph();
Menu:

	system("cls");
	showNodeCL();
	createCircle();
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
		insertNodeCL();
		goto Menu;
	case 2:
		deleteNodeCL();
		goto Menu;
	case 3:
		break;
	}
	_getch();
}
