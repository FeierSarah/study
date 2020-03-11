//#include <stdio.h>
//#include <string.h>
//
//void func(char str_arg[100])
//{
//	printf("\nstr_arg = %s\n", str_arg);
//	printf("sizeof(str_arg) = %d\n", sizeof(str_arg));
//	printf("strlen(str_arg) = %d\n", strlen(str_arg));
//}
//
//
//int main()
//{
//	char str[] = "Hello";//注意和char * str = "Hello";是不一样的结果
//	printf("str = %s\n", str);
//	printf("sizeof(str) = %d\n", sizeof(str));
//	printf("strlen(str) = %d\n", strlen(str));
//
//	char * p = str;
//
//	printf("\np = %s\n", p);
//	printf("sizeof(p) = %d\n", sizeof(p));//linux 64位系统下，指针的长度是8字节，但是windows 64位系统下，指针的长度是4字节
//	printf("strlen(p) = %d\n", strlen(p));
//
//	func(str);
//
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#define MY_BUFSIZE 1024
HWND GetConsoleHwnd(void)
{
	HWND hwndFound;
	char pszNewWindowTitle[MY_BUFSIZE];
	char pszOldWindowTitle[MY_BUFSIZE];
	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);
	wsprintf(pszNewWindowTitle, "%d/%d",
		GetTickCount(),
		GetCurrentProcessId());
	SetConsoleTitle(pszNewWindowTitle);
	Sleep(40);
	hwndFound = FindWindow(NULL, pszNewWindowTitle);
	SetConsoleTitle(pszOldWindowTitle);
	return(hwndFound);
}
void drawXY()
{
	HWND hWnd = GetConsoleHwnd();
	HDC hDC = GetDC(hWnd);
	COORD dwSize;
	HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	HANDLE Hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(Hout, &bInfo);
	dwSize = bInfo.dwMaximumWindowSize;
	dwSize.X *= 8;
	dwSize.Y *= 8;
	SetBkMode(hDC, TRANSPARENT); SetTextColor(hDC, 255 * 255);
	TextOut(hDC, dwSize.X - 15, dwSize.Y / 2 - 15, "X", 1);
	TextOut(hDC, dwSize.X / 2, 0, "Y", 1);
	MoveToEx(hDC, 0, dwSize.Y / 2, NULL);
	LineTo(hDC, dwSize.X, dwSize.Y / 2);
	MoveToEx(hDC, dwSize.X / 2, 0, NULL);
	LineTo(hDC, dwSize.X / 2, dwSize.Y);
	ReleaseDC(hWnd, hDC);
}
void draw(double p)
{
	int i;
	double x, y;
	HWND hWnd = GetConsoleHwnd();
	HDC hDC = GetDC(hWnd);
	COORD dwSize;
	HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hOldPen = (HPEN)SelectObject(hDC, hNewPen);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	HANDLE Hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(Hout, &bInfo);
	dwSize = bInfo.dwMaximumWindowSize;
	dwSize.X *= 8;
	dwSize.Y *= 8;
	for (i = -180; i <= 180; i++)
	{
		x = 16 * pow(sin(i*3.1415926 / 180), 3.0)*p;
		y = (13 * cos(i*3.1415926 / 180) - 5 * cos(2 * i*3.1415926 / 180) - 2 * cos(3 * i*3.1415926 / 180) - cos(4 * i*3.1415926 / 180))*p;
		x = (x + 16)*dwSize.X / 32 / 2 + dwSize.X / 4;
		y = -y / 16 * dwSize.Y / 2.3 + dwSize.Y / 2;
		x = x;
		y = y;
		MoveToEx(hDC, x, y, NULL);
		LineTo(hDC, x + 1, y + 1);
	}
}

int main(void)
{
	double p;
	system("color 0c");
	//drawXY();
	for (p = 0.6; p <= 1; p = p + 0.01)
		draw(p);
	system("PAUSE");
}