#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
#include <dos.h>
#include <windows.h>
#include <Windows.h>
#include <conio.h>
#include "graphics.h"
#include <sstream>
using namespace std;

struct Node {
    int count = 0, data;
    int suc = 0, Ox, Oy;
    int top[100];
    bool visit;
    void init()
    {
        count = 0;
        data = 0;
        suc = 0;
        visit = false;
    }
};
typedef Node node;
#define stemp 10;
Node* arrNode = (node*)malloc(100 * sizeof(node));
string value[20];
int arrsort[100];
int radius = 70, space = 10;
int ESP = 1500;

void Input(node* arrnode, int n);
void NhapDanhSach(Node& node, int i, int n);
bool ktNode(int x, int n, node p);
void TopoSort(Node* arrnode, int n);
void XoaDoiTuong(int i, node* arrnode, int n);
void TopoRun(node* arrnode, int n);
void Setup(node* arrnode, int n);
void updataXY(int n);
void Vecung(node a, node b, int mau);
void createCir(int x, int y, int mau, string st, int i);
void XoaCung(int i, node* arrnode, int n, node x);
void createListNode(int n);
void createLine(int n, int mau);
void hideNode(int x, int y);
void createQueue();
void DiChuyenNode(int i);
void forcus(int k);
void hideListCount();
void DanhSachCount(int n);
int main()
{
    int n;
    initgraph();
    cout << "Nhap So doi tuong: ";
    cin >> n;
    TopoRun(arrNode, n);
    _getch();
    return 0;
}
void Input(node* arrnode, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        arrnode[i].init();
        value[i] = to_string(j);
        arrnode[i].data = i;
        cout << "Nhap cac cong viec can thuc hien truoc doi tuong " << i << " (nhap 0 de ket thuc danh sach): ";
        NhapDanhSach(arrnode[i], i, n);

    }
    gotoxy(300, 400);
    system("pause");
    system("cls");
}
void NhapDanhSach(Node& node, int i, int n)
{
    int x, d = 0;;
    do
    {
        cin >> x;
        if (x == 0)
            break;
        if (ktNode(x, n, node) && x != i)
        {
            d++;
            node.suc = d;
            node.top[d] = x;
        }
        else
            cout << "Nhap doi tuong tu 1 den " << n << "va khong trung lap" << endl;
    } while (x != 0);
    node.count = d;
}
bool ktNode(int x, int n, Node p)
{
    if (x > n || x < 0)
        return false;
    for (int i = 1; i <= p.suc; i++)
        if (x == p.top[i])
            return false;
    return true;
}
void TopoSort(Node* arrnode, int n) {
    int  k = 0;
    bool kt, visit[100];
    char s2[] = "FRONT";
    char s3[] = "REAR";
    for (int i = 1; i <= n; i++) visit[i] = true;
    while (k < n) {
        kt = false;
        for (int i = 1; i <= n; i++)
        {
            if (arrnode[i].count == 0 && visit[i])
            {
                visit[i] = false;
                kt = true; k++; arrsort[k] = i;
                //forcus(i);
                Sleep(1000);
                XoaDoiTuong(i, arrnode, n);
                node temp = arrnode[i];
                DiChuyenNode(i);
                XoaCung(i, arrnode, n, temp);
                createListNode(n);
                //  DanhSachCount(n);
                ESP = ESP - radius - space;
                if (k == 1)
                {
                    drawText(ESP + 60, 730, s2);
                }
                else
                {
                    hideNode(ESP + 160, 605);
                    drawText(ESP + 40, 610, s3);
                }
            }
        }
        if (kt == false && k < n)
        {
            cout << "Khong co thu tu Topo !" << endl;
            return;
        }
    }
    cout << "Topo sort: ";
    for (int i = 1; i <= n; i++)
        cout << arrsort[i] << " ";
}
void XoaDoiTuong(int i, node* arrnode, int n)
{
    for (int k = 1; k <= n; k++)
    {
        Node p = arrnode[k];
        for (int j = 1; j <= p.suc; j++)
            if (p.top[j] == i)
                p.count--;
        arrnode[k] = p;
    }
}

void TopoRun(node* arrnode, int n)
{
    Input(arrnode, n);
    Setup(arrnode, n);
    system("pause");
    TopoSort(arrNode, n);
}
void Setup(node* arrnode, int n)
{
    updataXY(n);
    createLine(n, 10);
    hideNode(arrNode[3].Ox, arrNode[3].Oy);
    createListNode(n);

    createQueue();
}
void createCir(int x, int y, int mau, string st, int i)
{
    setcolor(mau);
    circle(x, y, radius);
    if (arrNode[i].count != 0)
        circle(x, y, radius - 20);
    drawText(x - 20, y - 20, st.c_str());
    setcolor(10);
}
void updataXY(int n)
{
    arrNode[1].Oy = 400;
    arrNode[1].Ox = 150;
    int k = 4, d = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            d++;
            arrNode[i].Ox = arrNode[1].Ox + d * (space + 2 * radius);
            arrNode[i].Oy = arrNode[1].Oy + k * radius - space - (100 - k * 10);
        }
        else
        {
            arrNode[i].Ox = arrNode[1].Ox + d * (space + 2 * radius);
            arrNode[i].Oy = arrNode[1].Oy - k * radius - space + (100 - k * 10);
            k--;
        }

    }
}
void createListNode(int n)
{
    for (int i = 1; i <= n; i++)
        if (arrNode[i].visit == false)
            createCir(arrNode[i].Ox, arrNode[i].Oy, 2, value[i], i);
}
void createLine(int n, int mau)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= arrNode[i].suc; j++)
            Vecung(arrNode[i], arrNode[arrNode[i].top[j]], mau);
    }
}
void Vecung(node a, node b, int mau)
{
    setcolor(mau);
    line(a.Ox, a.Oy, b.Ox, b.Oy);
    setcolor(10);
}
void hideNode(int x, int y)
{
    setcolor(0);
    int t = radius - 35;
    for (int i = -t; i <= t; i++)
        line(x - t, y + i, x + t, y + i);
    setcolor(10);
}
void createQueue()
{
    char s4[] = "QUEUE";
    drawText(1150, 530, s4);
    line(800, 650, ESP + 50, 650);
    line(800, 730, ESP + 50, 730);
}
void DiChuyenNode(int i)
{
    if (i % 2 == 1 && i != 1)
    {
        do
        {
            hideNode(arrNode[i].Ox, arrNode[i].Oy);
            arrNode[i].Oy -= stemp;
            createCir(arrNode[i].Ox, arrNode[i].Oy, 2, value[i], i);
            Sleep(30);
        } while (arrNode[i].Oy > 70);
        do
        {
            hideNode(arrNode[i].Ox, arrNode[i].Oy);
            arrNode[i].Ox -= stemp;
            createCir(arrNode[i].Ox, arrNode[i].Oy, 2, value[i], i);
            Sleep(30);
        } while (arrNode[i].Ox > 50);
    }
    do
    {
        hideNode(arrNode[i].Ox, arrNode[i].Oy);
        arrNode[i].Oy += stemp;
        createCir(arrNode[i].Ox, arrNode[i].Oy, 2, value[i], i);
        Sleep(30);
    } while (arrNode[i].Oy < 690);
    do
    {
        hideNode(arrNode[i].Ox, arrNode[i].Oy);
        arrNode[i].Ox += stemp;
        createCir(arrNode[i].Ox, arrNode[i].Oy, 2, value[i], i);
        Sleep(30);
    } while (arrNode[i].Ox < ESP);
}
void forcus(int k)
{
    for (int i = 2; i <= 9; i++)
    {
        createCir(arrNode[k].Ox, arrNode[k].Oy, i, value[k], i);
        Sleep(170);
    }
}
void XoaCung(int i, node* arrnode, int n, node x)
{
    for (int k = 1; k <= n; k++)
    {
        Node p = arrnode[k];
        for (int j = 1; j <= p.suc; j++)
            if (p.top[j] == i)
                Vecung(p, x, 0);
    }
}
void DanhSachCount(int n)
{
    // gotoxy(300, 200);
    hideListCount();
    for (int i = 1; i <= n; i++)
    {
        // cout << "Cac doi tuong can hoan thanh truoc doi tuong " << i << " : ";
        for (int j = 1; j <= arrNode[i].suc; j++)
            //  cout << arrNode[i].top[j] << " ";
            cout << endl;
    }
    // gotoxy(0, 0);
}
void hideListCount()
{
    setcolor(2);
    for (int i = 350; i <= 600; i++)
        line(400, i, 700, i);
}