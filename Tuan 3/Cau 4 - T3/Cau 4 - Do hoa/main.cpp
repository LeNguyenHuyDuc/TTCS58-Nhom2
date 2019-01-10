#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<winbgim.h>
using namespace std;
fstream f("dothi.txt");
fstream g("caykhungmin.txt");
/*Khai bao kieu du lieu canh*/
struct canh{
	int dinhdau, dinhcuoi;
	int trongso;
};
/*
	Ham nhap vao cac canh cua do thi vo huong
	Input: E[100] - mang luu tru cac canh
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Du lieu cac canh cua do thi duoc nhap vao mang E[100]
*/
void NhapCanh (canh E[100], int ndinh, int &ncanh)
{
	int tam;
	int i = 0;
	int flag = 0;
	do
	{
		cout<<"Nhap dinh thu nhat cua canh, dung khi nhap <=0 hoac >"<<ndinh<<": ";
		cin>>tam;
		if (tam > 0 && tam <= ndinh)
		{
			E[i].dinhdau = tam;
			do
			{
				cout<<"Nhap dinh thu hai cua canh: ";
				cin>>E[i].dinhcuoi;
			}
			while (E[i].dinhcuoi <= 0 || E[i].dinhcuoi > ndinh || E[i].dinhcuoi == E[i].dinhdau);
			do
			{
				cout<<"Nhap trong so cua canh: ";
				cin>>E[i].trongso;
			}
			while (E[i].trongso <= 0);
			for (int j = 0; j < i; j++)
				if ((E[i].dinhdau == E[j].dinhdau && E[i].dinhcuoi == E[j].dinhcuoi) || (E[i].dinhdau == E[j].dinhcuoi && E[i].dinhcuoi == E[j].dinhdau))
				{
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				ncanh++;
				i++;
			}
			else
				flag = 0;
			cout<<endl;
		}
	}
	while (tam > 0 && tam <= ndinh);
}
/*
	Ham luu do thi vao file
	Input: E[100] - mang luu tru cac canh
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Du lieu cac canh va so luong dinh duoc dua vao file
*/
void GhiCanh (canh E[100], int ndinh, int ncanh)
{
	f<<ndinh<<endl;
	for (int i = 0; i < ncanh; i++)
		f<<E[i].dinhdau<<"-"<<E[i].dinhcuoi<<": "<<E[i].trongso<<endl;
}
/*
	Ham doc do thi tu file
	Input: E[100] - mang luu tru cac canh
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Du lieu cua do thi duoc doc vao
*/
void DocCanh (canh E[100], int &ndinh, int &ncanh)
{
	int i = 0;
	string s;
	stringstream ss;
	getline(f,s);	ndinh = atoi(s.c_str());
	while (!f.eof())
	{
		string line;
		stringstream ss;
		getline(f,line);
		ss.str(line);
		getline(ss,s,'-'); 	E[i].dinhdau = atoi(s.c_str());
		getline(ss,s,':'); 	E[i].dinhcuoi = atoi(s.c_str());
		getline(ss,s,':'); 	E[i].trongso = atoi(s.c_str());
		i++;
	}
	ncanh = i - 1;	
}
/*
	Ham sap xep cac canh cua do thi theo thu tu tang dan trong so
	Input: E[100] - mang luu tru cac canh
		   ncanh - so luong canh cua do thi
	Output: Cac canh cua do thi duoc sap xep theo thu tu tang dan trong so
*/
void Sapxep (canh E[100], int ncanh)
{
	for (int i = 0; i < ncanh - 1; i++)
		for (int j = i + 1; j < ncanh; j++)
			if (E[i].trongso > E[j].trongso)
				swap (E[i],E[j]);
}
/*
	Ham lay toa do cua 1 dinh
	Input: dinh - so hieu cua dinh dang xet
		   x - toa do x cua dinh dang xet
		   y - toa do y cua dinh dang xet
	Output: Gan toa do cua dinh dang xet vao 2 bien x va y
*/
void LayToaDo (int dinh, int &x, int &y)
{
	switch(dinh)
	{
		case 1:
			x = 400;
			y = 350;
			break;
		case 2:
			x = 500;
			y = 250;
			break;
		case 3:
			x = 650;
			y = 250;
			break;
		case 4:
			x = 750;
			y = 350;
			break;
		case 5:
			x = 650;
			y = 450;
			break;
		case 6:
			x = 500;
			y = 450;
			break;
	}
}
/*
	Ham tim cay khung be nhat cua do thi
	Input: E[100] - mang luu tru cac canh
		   goc[100] - mang luu tru dinh goc cua moi dinh trong do thi
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Xuat ra cac canh cua cay khung be nhat va tong trong so cua cay khung vao file
*/
int Caykhungmin (canh E[100], int goc[100], int ndinh, int ncanh)
{
	int sum = 0;
	int dem = 0;
	int nT = 0;
	int xdau, ydau;
	int xcuoi, ycuoi;
	canh T[100];
	for (int i = 1; i <= ndinh; i++)
		goc[i] = i;
	for (int i = 0; i < ncanh; i++)
	{
		cout<<"B"<<i+1<<": ";
		int x = E[i].dinhdau, y = E[i].dinhcuoi;
		if (goc[x] != goc[y])
		{
			int tam1 = goc[x];
			int tam2 = goc[y];
			for (int j = 1; j <= ndinh; j++)
				if (goc[j] == tam2)
					goc[j] = tam1;
			LayToaDo(E[i].dinhdau,xdau,ydau);
			LayToaDo(E[i].dinhcuoi,xcuoi,ycuoi);
			line(xdau,ydau,xcuoi,ycuoi);		//Ve canh duoc lay tren man hinh do hoa
			cout<<E[i].dinhdau<<"-"<<E[i].dinhcuoi<<": "<<E[i].trongso<<"\tLay\t";
			T[nT] = E[i];
			nT++;			
			g<<E[i].dinhdau<<"-"<<E[i].dinhcuoi<<": "<<E[i].trongso<<endl;
			sum += E[i].trongso;
			dem++;
		}
		else
		{
			cout<<E[i].dinhdau<<"-"<<E[i].dinhcuoi<<": "<<E[i].trongso<<"\tKo lay\t";			
		}
		cout<<"T = {";
			for (int k = 0; k < nT; k++)
				if (k == nT - 1)
					cout<<T[k].dinhdau<<"-"<<T[k].dinhcuoi;
				else
					cout<<T[k].dinhdau<<"-"<<T[k].dinhcuoi<<", ";
		cout<<"}"<<endl;
		delay(1000);
		if (dem == ndinh - 1)
			break;
	}
	return sum;
}
int main()
{
	
	int ndinh;
	int ncanh = 0;
	canh E[100];
	int goc[100];
	int key;
	cout<<"Nhap key de chon cach dua do thi vao:"<<endl;
	cout<<"1. Nhap do thi tu ban phim"<<endl;
	cout<<"2. Doc do thi tu file"<<endl;
	cin>>key;
	switch(key)
	{
		case 1:
			cout<<"Nhap so dinh: ";
			cin>>ndinh;
			NhapCanh(E,ndinh,ncanh);
			GhiCanh(E,ndinh,ncanh);
	 		break;
		case 2:
			DocCanh(E,ndinh,ncanh);
			break;
	}
	cout<<endl<<"Sap xep cac canh theo thu tu tang dan trong so: "<<endl;	
	Sapxep(E,ncanh);
	for (int i = 0; i < ncanh; i++)
		cout<<E[i].dinhdau<<"-"<<E[i].dinhcuoi<<": "<<E[i].trongso<<endl;
	g<<"Cac canh cua cay khung be nhat: "<<endl;
	cout<<endl<<"Lay cac canh co trong so tang dan sao cho khong tao thanh chu trinh, dung khi du "<<ndinh-1<<" canh: "<<endl;
	initwindow(1280, 700);
    cleardevice();
    setcolor(10);
    settextstyle(10, 0, 5);
    circle(400,350,10);		//Dinh 1
    setcolor(9);
    outtextxy(350,350,"1");
    setcolor(10);
    circle(500,250,10);		//Dinh 2
    setcolor(9);
    outtextxy(500,190,"2");
    setcolor(10);
    circle(650,250,10);		//Dinh 3
    setcolor(9);
    outtextxy(650,190,"3");
    setcolor(10);
    circle(750,350,10);		//Dinh 4
    setcolor(9);
    outtextxy(775,350,"4");
    setcolor(10);
    circle(650,450,10);		//Dinh 5
    setcolor(9);
    outtextxy(650,460,"5");
    setcolor(10);
    circle(500,450,10);		//Dinh 6
    setcolor(9);
    outtextxy(500,460,"6");
	setcolor(12);	
	int sum = Caykhungmin(E,goc,ndinh,ncanh);
	g<<"Tong trong so cua cay khung be nhat: "<<sum;		
	while(!kbhit()) delay(1);
    return 0;
}
