#include<stdio.h>
#include<conio.h>
#include<dos.h>
int nhap0x1()
{
	int x;
	union REGS regs;
	regs.h.ah=1;
	int86(0x21,&regs,&regs);
	x=regs.h.al;
	x-=0x30;
	return x;
}
void xuat0x2(int x)
{
	union REGS regs;
	x+=0x30;
	regs.h.ah=2;
	regs.h.dl=x;
	int86(0x21,&regs,&regs);
}
int nhap0x8()
{
	int x;
	union REGS regs;
	regs.h.ah=8;
	int86(0x21,&regs,&regs);
	x=regs.h.al;
	x-=0x30;
	return x;
}
void xuat0x9(const char *String)
{
	union REGS regs;
	struct SREGS segreg;
	regs.h.ah=0x09;
	regs.x.dx=FP_OFF(String);
	segreg.ds=FP_SEG(String);
	int86x(0x21,&regs,&regs,&segreg);
}
const char * nhap0x10()
{
	const char *String;
	union REGS regs;
	struct SREGS segreg;
	regs.h.ah=0x10;
	regs.x.dx=FP_OFF(String);
	segreg.ds=FP_SEG(String);
	int86x(0x21,&regs,&regs,&segreg);
	return String;
}
int main()
{
	clrscr();
	printf("Nhap vao 1 so nguyen/ki tu: ");
	int x = nhap0x1();
	printf("\nSo/Ki tu vua nhap la: ");
	xuat0x2(x);
	printf("\nNhap vao 1 so nguyen/ki tu: ");
	x = nhap0x8();
	printf("\nSo/Ki tu vua nhap la: ");
	xuat0x2(x);
	xuat0x9("\nNhap vao 1 chuoi: $");
	const char *s=nhap0x10();

	getch();
	return 0;
}
