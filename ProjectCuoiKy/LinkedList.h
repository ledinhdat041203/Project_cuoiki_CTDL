#include "graphics.h"
#include <dos.h>
#include <windows.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define widthNodeL 100
#define WspaceL 20

struct nodeLList
{
	string value;
	int x, y;
	bool dlte;
};

nodeLList LList[10];
int nLList = 0;
//int choose;
void arrowLL(int x, int y, bool dlte)
{
	if (!dlte)
	{
		line(x, y, x + 51, y);
		line(x + 46, y - 5, x + 51, y);
		line(x + 46, y + 5, x + 51, y);
	}
}
void createNodeLinked(int x, int y, const char* mess, bool dlte)
{
	setcolor(0);
	rectangle(x - 40, y - 20, x + 40, y + 20);
	line(x + 15, y - 21, x + 15, y + 19);
	setcolor(2);
	circle(x + 27, y, 6);
	arrowLL(x + 27, y, dlte);
	drawText(x - 25, y - 10, mess);
	setcolor(0);
}
void createNull()
{
	int x = LList[nLList - 1].x, y = LList[nLList - 1].y;
	if (nLList > 0)
	{
		setcolor(4);
		int x1 = x - 40 + widthNodeL + WspaceL, x2 = x + 40 + widthNodeL + WspaceL, y1 = y - 20, y2 = y + 20;
		rectangle(x1, y1, x2, y2);
		drawText(x - 25 + +widthNodeL + WspaceL, y - 10, "NULL");
		setcolor(0);
	}
}
void showNodeLL()
{
	if (nLList > 0)
	{
		for (int i = 0; i < nLList; i++)
		{
			createNodeLinked(LList[i].x, LList[i].y, LList[i].value.c_str(), LList[i].dlte);
		}
	}

}
void insertArrLL(int k, string value)
{
	for (int i = nLList - 1; i >= k; i--)
	{
		LList[i + 1] = LList[i];
	}
	LList[k].value = value;
	LList[k].y = 160;
	nLList++;
}
void logicInsLL(int k, int& z)
{
	if (z < 6)
	{
		for (int j = nLList - 1; j > k; j--)
		{
			LList[j].x += 20;
		}
		z++;
	}
}
void insertNodeLL()
{
	string value;
	int k;
	cout << "Nhap Node: ";
	cin >> value;
	cout << "Position: ";
	cin >> k;
	if (nLList == 0 || k >= nLList)
	{
		LList[nLList].value = value;
		if (nLList == 0)
			LList[nLList].x = 150 + nLList * (widthNodeL + WspaceL);
		else
		{
			LList[nLList].x = LList[nLList - 1].x + (widthNodeL + WspaceL);
		}
		LList[nLList].y = 160;
		LList[nLList].dlte = false;
		nLList++;
		for (int i = LList[nLList - 1].y; i < 220; i += 10)
		{
			//system("cls");
			clrscr();
			LList[nLList - 1].y = i;
			showNodeLL();
			Sleep(15);
		}
		createNull();
	}
	else
	{
		insertArrLL(k, value);
		int z = 0;
		for (int i = LList[k].y; i < 220; i += 10)
		{
			//system("cls");
			clrscr();
			LList[k].y = i;
			logicInsLL(k, z);
			showNodeLL();
			Sleep(15);
		}
		createNull();
	}
}
void deleteArrLL(int k)
{
	for (int i = k; i < nLList - 1; i++)
	{
		LList[i] = LList[i + 1];
	}
	nLList--;
}
void logicDelLL(int k, int& z)
{
	if (z < 6)
	{
		for (int i = k + 1; i < nLList; i++)
		{
			LList[i].x -= 20;
		}
		z++;
	}
}
void deleteNodeLL()
{

	if (nLList > 0)
	{
		int k;
		cout << "Delete Position: ";
		cin >> k;
		if (k >= nLList)	k = nLList - 1;
		LList[k].dlte = true;
		int z = 0;
		for (int i = LList[k].y; i < 280; i += 10)
		{
			clrscr();
			LList[k].y = i;
			logicDelLL(k, z);
			showNodeLL();
			Sleep(15);
		}

		deleteArrLL(k);
		createNull();
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
void LinkedListRun()
{

	system("cls");
	cout << "\t\t\t\t\t ==== LINKEDLIST SIMULATION====";
	_getch();
	initgraph();
Menu:

	system("cls");
	showNodeLL();
	createNull();
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
		insertNodeLL();
		goto Menu;
	case 2:
		deleteNodeLL();
		goto Menu;
	case 3:
		break;
	}

	_getch();
}
