#include "graphics.h"
#include <dos.h>
#include <windows.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "LinkedList.h"
#include "CircleList.h"
#include"topo.h"


void DrawMenu(int x, int y)
{

	initgraph();
	clrscr();
	//system("pause");
	setfontcolor(2);
	rectangle(x - 50, y - 25, x + 50, y + 25);
	rectangle(x - 50, y + 35, x + 50, y + 85);
	rectangle(x - 50, y + 95, x + 50, y + 145);
	rectangle(x - 50, y + 155, x + 50, y + 205);
	rectangle(x - 50, y + 215, x + 50, y + 265);
	rectangle(x - 50, y + 275, x + 50, y + 325);
	rectangle(x - 50, y + 335, x + 50, y + 385);
	rectangle(x - 50, y + 395, x + 50, y + 435);


	textcolor(6);
	char a[] = "Menu";
	char b[] = "1. Stack";
	char c[] = "2. Queue";
	char d[] = "3. DeQueue";
	char e[] = "4. Linked List";
	char f[] = "5. Circle List";
	char g[] = "6. Topo Sort";
	char h[] = "7. Exit";



	drawText(x - 32, y - 15, a);
	drawText(x - 40, y + 45, b);
	drawText(x - 40, y + 105, c);
	drawText(x - 45, y + 165, d);
	drawText(x - 50, y + 225, e);
	drawText(x - 50, y +285, f);
	drawText(x - 50, y + 345, g);
	drawText(x - 40, y + 400, h);
}
void Menu()
{
	/*cout << "1. Stack\n";
	cout << "2. Queue\n";
	cout << "3. DeQueue\n";
	cout << "4. Linked List\n";
	cout << "5. Circle List\n";
	cout << "6. Topo Sort\n";
	cout << "7. Exit\n";*/
Menu:
	DrawMenu(450, 50);
	cout << "Choose: ";
	int chooseMenu;
	cin >> chooseMenu;
	switch (chooseMenu)
	{
	default:
		cout << "Nhap lua chon tu 1-7\n";
		goto Menu;
	case 1:
		StackRun();
		goto Menu;
	case 2:
		QueueRun();
		goto Menu;
	case 3:
		DeQueueRun();
		goto Menu;

	case 4:
		LinkedListRun();
		goto Menu;

	case 5:
		CircleListRun();
		goto Menu;

	case 6:
		RunTopo();
		goto Menu;

	case 7:
		break;
	}
}
void RunSimulation()
{
	Menu();
	_getch();

}

