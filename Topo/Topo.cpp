#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
using namespace std;
struct Node {
    int count=0,data;
    int suc=0;
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
void Input(node* arrnode, int n);
void NhapDanhSach(Node &node,int i,int n);
bool ktNode(int x, int n, node p);
void TopoSort(Node* arrnode, int n);
void XoaDoiTuong(int i, node* arrnode, int n);
int main()
{
    int n;   
    cout << "Nhap So doi tuong: ";
    cin >> n;
    Node *arrNode = (node*)malloc(n * sizeof(node));
    Input(arrNode, n);
    TopoSort(arrNode, n);
    return 0;
}
void Input(node *arrnode, int n)
{
    for (int i = 1; i <= n; i++)
    {
        arrnode[i].init();
        arrnode[i].data = i;
        cout << "Nhap cac cong viec can thuc hien truoc doi tuong " << i <<" (nhap 0 de ket thuc danh sach): ";
        NhapDanhSach(arrnode[i], i, n);
    }
}
void NhapDanhSach(Node &node,int i,int n)
{
    int x, d = 0;;
    do
    {
        cin >> x;
        if (x == 0)
            break;
        if (ktNode(x,n,node))
            {
                d++;
                node.suc = d;
                node.top[d] = x;
            }
        else
            cout << "Nhap doi tuong tu 1 den " << n << "va khong trung lap"<< endl;
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
void TopoSort(Node* arrnode, int n){
    int arrsort[100], k = 0;
    bool kt, visit[100];
    for (int i = 1; i <= n; i++) visit[i] = true;
   while(k<n){
        kt = false;
        for (int i = 1; i <= n; i++)
        {
            if (arrnode[i].count == 0 && !(arrnode[i].visit))
            {
                arrnode[i].visit = true;
                kt = true; k++; arrsort[k] = i;
                XoaDoiTuong(i,arrnode,n);
            }
        }
        if (kt == false && k <n)
        {
            cout << "Khong co thu tu Topo !" << endl;
            return;
        }
    }
   cout << "Topo sort: ";
   for (int i = 1; i <= n; i++) 
       cout << arrsort[i] << " ";
}
void XoaDoiTuong(int i, node* arrnode,int n)
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