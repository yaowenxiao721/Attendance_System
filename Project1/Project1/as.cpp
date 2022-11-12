#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<easyx.h>
#include<time.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define MB_OK                       0x00000000L
#pragma warning(disable:4996)
#define maxsize 30
#define maxnum 1000

void FirstPage();
void StudentsPage();
void TeachersPage();
void Find();
void find1();
void find2();
void find3();
void printAll(int n, int y);
void save();
void Change();
void Print();
void Statistics();

typedef struct {
	char Student_ID[maxsize];
	char Name[maxsize];
	char Class_Number[maxsize];
	char Attandance_date[maxsize];
	char Attandance_Result[maxsize];
	float date;
	int sec;
} student;

student Students[maxnum];

int num = 0, numbers = 0, time_start;
char buf[maxsize];
char time_teacher[20] = { 0 };
char t[20] = { 0 };
TCHAR style1[] = _T("楷体");
TCHAR style2[] = "黑体";

void button_f_s(int x, int y, int w, int h, TCHAR* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(128, 128, 128));
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(50, 0, style2);
	settextcolor(BLACK);
	TCHAR s[50] = "hello";

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);
}

void button_t(int x, int y, int w, int h, TCHAR* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(128, 128, 128));
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(25, 0, style2);
	settextcolor(BLACK);
	TCHAR s[50] = "hello";

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);

}

void printAll(int n, int y) {
	

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	outtextxy(550, 25, "班 级");
	outtextxy(800, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");


	settextstyle(25, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, y, Students[n].Student_ID);
	outtextxy(300, y, Students[n].Name);
	outtextxy(550, y, Students[n].Class_Number);
	outtextxy(800, y, Students[n].Attandance_date);
	outtextxy(1050, y, Students[n].Attandance_Result);

	
	/*
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					find1();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					find2();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					find3();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 700 && msg.y <= 700 + 75)
				{
					TeachersPage();
				}
				break;
			default:
				break;
			}
		}
	}
	*/
	system("pause");
	//getchar();
	closegraph();
}

void find1() {
	char information[maxsize];
	char in[10];

	int flag = 0;
	InputBox(in, 10, "请输入学生的学号：");
	strcpy(information, in);
	
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	outtextxy(550, 25, "班 级");
	outtextxy(800, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");

	for (int i = 0; i < num; i++) {
		if (strcmp(information, Students[i].Student_ID) == 0) {
			//printAll(i, 75+flag*50);
			//printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);

			settextstyle(25, 0, style1);
			settextcolor(BLACK);
			outtextxy(50, 75 + flag * 25, Students[i].Student_ID);
			outtextxy(300, 75 + flag * 25, Students[i].Name);
			outtextxy(550, 75 + flag * 25, Students[i].Class_Number);
			outtextxy(800, 75 + flag * 25, Students[i].Attandance_date);
			outtextxy(1050, 75 + flag * 25, Students[i].Attandance_Result);
			flag++;
		}

	}
	
	TCHAR b[] = _T("返回");
	button_f_s(1300, 25, 100, 50, b);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1300 && msg.x <= 1300 + 100 && msg.y >= 25 && msg.y <= 25 + 50)
				{
					Find();
				}
				break;
			default:
				break;
			}
		}
	}
	
	closegraph();
}

void find2() {
	char information[maxsize];
	char in[10];

	int flag = 0;
	InputBox(in, 10, "请输入学生的姓名：");
	strcpy(information, in);

	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	outtextxy(550, 25, "班 级");
	outtextxy(800, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");

	for (int i = 0; i < num; i++) {
		if (strcmp(information, Students[i].Name) == 0) {
			//printAll(i, 75+flag*50);
			//printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);

			settextstyle(25, 0, style1);
			settextcolor(BLACK);
			outtextxy(50, 75 + flag * 25, Students[i].Student_ID);
			outtextxy(300, 75 + flag * 25, Students[i].Name);
			outtextxy(550, 75 + flag * 25, Students[i].Class_Number);
			outtextxy(800, 75 + flag * 25, Students[i].Attandance_date);
			outtextxy(1050, 75 + flag * 25, Students[i].Attandance_Result);
			flag++;
		}

	}

	TCHAR b[] = _T("返回");
	button_f_s(1300, 25, 100, 50, b);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1300 && msg.x <= 1300 + 100 && msg.y >= 25 && msg.y <= 25 + 50)
				{
					Find();
				}
				break;
			default:
				break;
			}
		}
	}

	closegraph();
}

void find3() {
	char information[10];
	char in[10];

	int flag = 0;

	
	InputBox(in, 10, "请输入日期(月、日）：");

	strcpy(information, in);

	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	outtextxy(550, 25, "班 级");
	outtextxy(800, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");

	for (int i = 0; i < num; i++) {
		char date_f[10] = {""};
		char date[10] = {""};
		sprintf(date, "%f", Students[i].date);
		strncpy(date_f, date, 5);
		if (strcmp(information, date_f) == 0) {
			//printAll(i, 75+flag*50);
			//printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);

			settextstyle(25, 0, style1);
			settextcolor(BLACK);
			outtextxy(50, 75 + flag * 25, Students[i].Student_ID);
			outtextxy(300, 75 + flag * 25, Students[i].Name);
			outtextxy(550, 75 + flag * 25, Students[i].Class_Number);
			outtextxy(800, 75 + flag * 25, Students[i].Attandance_date);
			outtextxy(1050, 75 + flag * 25, Students[i].Attandance_Result);
			flag++;
		}

	}

	TCHAR b[] = _T("返回");
	button_f_s(1300, 25, 100, 50, b);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1300 && msg.x <= 1300 + 100 && msg.y >= 25 && msg.y <= 25 + 50)
				{
					Find();
				}
				break;
			default:
				break;
			}
		}
	}

	closegraph();
}

void Find() {

	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)按学号查找");
	TCHAR op2[] = _T("(2)按姓名查找");
	TCHAR op3[] = _T("(3)按日期查找");
	TCHAR op4[] = _T("(4)返回");
	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);
	button_f_s(550, 700, 350, 75, op4);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{										
					find1();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{					
					find2();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					find3();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 700 && msg.y <= 700 + 75)
				{
					TeachersPage();
				}
				break;
			default:
				break;
			}
		}
	}

	/*
	int i, op, flag = -1;
	char information[maxsize];
	printf("<1>按学号查找  <2>按姓名查找  <3>按考勤日期查找\n");
	scanf("%d", &op);
	if (op == 1) {
		printf("请输入该生学号：");
		scanf("%s", information);
		for (i = 0; i < num; i++) {
			if (strcmp(information, Students[i].Student_ID) == 0)
				printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;

		}
	}
	else if (op == 2) {
		printf("请输入该生姓名：");
		scanf("%s", information);
		for (i = 0; i < num; i++) {
			if (strcmp(information, Students[i].Name) == 0)
				printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;
		}
	}
	else {
		printf("请输入考勤日期：");
		scanf("%s", information);
		for (i = 0; i < num; i++) {
			if (strcmp(information, Students[i].Attandance_date) == 0)
				printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;;
		}
	}
	if (flag == -1)
		printf("不存在此信息！\n");
	printf("按回车键返回\n");
	*/
}

void change(int n) {
	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)修改学号");
	TCHAR op2[] = _T("(2)修改姓名");
	TCHAR op3[] = _T("(3)修改考勤结果");
	TCHAR op4[] = _T("(4)返回");

	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);
	button_f_s(550, 700, 350, 75, op4);

	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					printf("%d", n);
					char information[maxsize];
					InputBox(information, 10, "请输入修改的学生学号：");
					strcpy(Students[n].Student_ID, information);
					save();
					HWND hwndInput1 = GetHWnd();
					int isok = MessageBox(hwndInput1, "修改成功！", "提示", MB_OK);
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					char information[maxsize];
					InputBox(information, 10, "请输入修改的学生姓名：");
					strcpy(Students[n].Name, information);
					save();
					HWND hwndInput1 = GetHWnd();
					int isok = MessageBox(hwndInput1, "修改成功！", "提示", MB_OK);
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					char information[maxsize];
					InputBox(information, 10, "请输入修改的考勤结果：");
					strcpy(Students[n].Attandance_Result, information);
					save();
					HWND hwndInput1 = GetHWnd();
					int isok = MessageBox(hwndInput1, "修改成功！", "提示", MB_OK);
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 700 && msg.y <= 700 + 75)
				{
					Change();
				}

				break;
			default:
				break;
			}
		}
	}
}

void Change() {
	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)按学号修改");
	TCHAR op2[] = _T("(2)按姓名修改");
	TCHAR op3[] = _T("(3)返回");

	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);

	int flag = 0;

	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					char information[maxsize];
					char in[10];

					InputBox(in, 10, "请输入学生的学号：");
					strcpy(information, in);

					for (int i = 0; i < num; i++) {
						if (strcmp(information, Students[i].Student_ID) == 0) {
							change(i);
							flag = 1;
						}
					}
					if (flag == 0)
					{
						HWND hwndInput1 = GetHWnd();
						int isok = MessageBox(hwndInput1, "查无此人,请重新输入！", "提示", MB_OK);
					}
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					char information[maxsize];
					char in[10];

					InputBox(in, 10, "请输入学生的姓名：");
					strcpy(information, in);

					for (int i = 0; i < num; i++) {
						if (strcmp(information, Students[i].Name) == 0) {
							change(i);
							flag = 1;
						}
					}
					if (flag == 0)
					{
						HWND hwndInput1 = GetHWnd();
						int isok = MessageBox(hwndInput1, "查无此人,请重新输入！", "提示", MB_OK);
					}
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					TeachersPage();
				}
				
				break;
			default:
				break;
			}
		}
	}
}

void copy(student* a, student* b) {
	strcpy(a->Student_ID, b->Student_ID);
	strcpy(a->Name, b->Name);
	strcpy(a->Class_Number, b->Class_Number);
	strcpy(a->Attandance_Result, b->Attandance_Result);
	strcpy(a->Attandance_date, b->Attandance_date);
	a->date = b->date;
}

void ch_Delete(int n) {
	for (int j = n + 1; j < num; j++) {
		copy(&Students[n], &Students[j]);
	}
	num--;
	save();
	HWND hwndInput1 = GetHWnd();
	int isok = MessageBox(hwndInput1, "修改成功！", "提示", MB_OK);
}

void Delete() {
	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)按学号删除");
	TCHAR op2[] = _T("(2)按姓名删除");
	TCHAR op3[] = _T("(3)返回");

	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);

	int flag = 0;

	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					char information[maxsize];
					char in[10];

					InputBox(in, 10, "请输入学生的学号：");
					strcpy(information, in);

					for (int i = 0; i < num; i++) {
						if (strcmp(information, Students[i].Student_ID) == 0) {
							ch_Delete(i);
							flag = 1;
						}
					}
					if (flag == 0)
					{
						HWND hwndInput1 = GetHWnd();
						int isok = MessageBox(hwndInput1, "查无此人,请重新输入！", "提示", MB_OK);
					}
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					char information[maxsize];
					char in[10];

					InputBox(in, 10, "请输入学生的姓名：");
					strcpy(information, in);

					for (int i = 0; i < num; i++) {
						if (strcmp(information, Students[i].Name) == 0) {
							ch_Delete(i);
							flag = 1;
						}
					}
					if (flag == 0)
					{
						HWND hwndInput1 = GetHWnd();
						int isok = MessageBox(hwndInput1, "查无此人,请重新输入！", "提示", MB_OK);
					}
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					TeachersPage();
				}

				break;
			default:
				break;
			}
		}
	}
}

void PrintPartInformation() {
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	//outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	//outtextxy(550, 25, "班 级");
	outtextxy(600, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");

	for (int i = 0; i < num; i++) {

		//printAll(i, 75+flag*50);
		//printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);

		settextstyle(25, 0, style1);
		settextcolor(BLACK);
		//outtextxy(50, 75 + i * 25, Students[i].Student_ID);
		outtextxy(300, 75 + i * 25, Students[i].Name);
		//outtextxy(550, 75 + i * 25, Students[i].Class_Number);
		outtextxy(600, 75 + i * 25, Students[i].Attandance_date);
		outtextxy(1050, 75 + i * 25, Students[i].Attandance_Result);
	}
	TCHAR b[] = _T("返回");
	button_f_s(1300, 25, 100, 50, b);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1300 && msg.x <= 1300 + 100 && msg.y >= 25 && msg.y <= 25 + 50)
				{
					Print();
				}
				break;
			default:
				break;
			}
		}
	}
}

void PrintAllInformation() {
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	outtextxy(550, 25, "班 级");
	outtextxy(800, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");

	for (int i = 0; i < num; i++) {
		
		//printAll(i, 75+flag*50);
		//printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);

		settextstyle(25, 0, style1);
		settextcolor(BLACK);
		outtextxy(50, 75 + i * 25, Students[i].Student_ID);
		outtextxy(300, 75 + i * 25, Students[i].Name);
		outtextxy(550, 75 + i * 25, Students[i].Class_Number);
		outtextxy(800, 75 + i * 25, Students[i].Attandance_date);
		outtextxy(1050, 75 + i * 25, Students[i].Attandance_Result);
	}
	TCHAR b[] = _T("返回");
	button_f_s(1300, 25, 100, 50, b);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1300 && msg.x <= 1300 + 100 && msg.y >= 25 && msg.y <= 25 + 50)
				{
					Print();
				}
				break;
			default:
				break;
			}
		}
	}
}

void Print() {
	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)部分打印");
	TCHAR op2[] = _T("(2)全部打印");
	TCHAR op3[] = _T("(3)返回");

	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);

	int flag = 0;

	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					PrintPartInformation();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					PrintAllInformation();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					TeachersPage();
				}

				break;
			default:
				break;
			}
		}
	}
}

void exchange(student* a, student* b) {
	char tmp[maxsize];
	strcpy(tmp, a->Student_ID);
	strcpy(a->Student_ID, b->Student_ID);
	strcpy(b->Student_ID, tmp);

	strcpy(tmp, a->Name);
	strcpy(a->Name, b->Name);
	strcpy(b->Name, tmp);

	strcpy(tmp, a->Class_Number);
	strcpy(a->Class_Number, b->Class_Number);
	strcpy(b->Class_Number, tmp);

	strcpy(tmp, a->Attandance_Result);
	strcpy(a->Attandance_Result, b->Attandance_Result);
	strcpy(b->Attandance_Result, tmp);

	strcpy(tmp, a->Attandance_date);
	strcpy(a->Attandance_date, b->Attandance_date);
	strcpy(b->Attandance_date, tmp);

	float t;
	t = a->date;
	a->date = b->date;
	b->date = t;

	return;
}

void Order() {
	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)按学号排序");
	TCHAR op2[] = _T("(2)按姓名排序");
	TCHAR op3[] = _T("(3)按日期排序");
	TCHAR op4[] = _T("(4)返回");
	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);
	button_f_s(550, 700, 350, 75, op4);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					int i, j;
					for (i = 0; i < num; i++) {
						for (j = i + 1; j < num; j++) {
							if (strcmp(Students[i].Student_ID, Students[j].Student_ID) > 0) {
								exchange(&Students[i], &Students[j]);
							}
						}
					}
					save();
					HWND hwndInput1 = GetHWnd();
					int isok = MessageBox(hwndInput1, "排序成功！", "提示", MB_OK);
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					int i, j;
					for (i = 0; i < num; i++) {
						for (j = i + 1; j < num; j++) {
							if (strcmp(Students[i].Name, Students[j].Name) > 0) {
								exchange(&Students[i], &Students[j]);
							}
						}
					}
					save();
					HWND hwndInput1 = GetHWnd();
					int isok = MessageBox(hwndInput1, "排序成功！", "提示", MB_OK);
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					int i, j;
					for (i = 0; i < num; i++) {
						for (j = i + 1; j < num; j++) {
							if (Students[i].date > Students[j].date) {
								exchange(&Students[i], &Students[j]);
							}
						}
					}
					save();
					HWND hwndInput1 = GetHWnd();
					int isok = MessageBox(hwndInput1, "排序成功！", "提示", MB_OK);
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 700 && msg.y <= 700 + 75)
				{
					TeachersPage();
				}
				break;
			default:
				break;
			}
		}
	}
}

void Informal_Print() {
	int flag = 0;

	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	outtextxy(550, 25, "班 级");
	outtextxy(800, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");

	for (int i = 0; i < num; i++) {
		char date_f[10] = { "" };
		char date[10] = { "" };
		sprintf(date, "%f", Students[i].date);
		strncpy(date_f, date, 5);
		if (strcmp(Students[i].Attandance_Result, "出勤") != 0) {
			//printAll(i, 75+flag*50);
			//printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);

			settextstyle(25, 0, style1);
			settextcolor(BLACK);
			outtextxy(50, 75 + flag * 25, Students[i].Student_ID);
			outtextxy(300, 75 + flag * 25, Students[i].Name);
			outtextxy(550, 75 + flag * 25, Students[i].Class_Number);
			outtextxy(800, 75 + flag * 25, Students[i].Attandance_date);
			outtextxy(1050, 75 + flag * 25, Students[i].Attandance_Result);
			flag++;
		}

	}

	TCHAR b[] = _T("返回");
	button_f_s(1300, 25, 100, 50, b);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1300 && msg.x <= 1300 + 100 && msg.y >= 25 && msg.y <= 25 + 50)
				{
					Statistics();
				}
				break;
			default:
				break;
			}
		}
	}
}

void AskForLeave_Print() {
	int flag = 0;

	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(50, 25, "学 号");
	outtextxy(300, 25, "姓 名");
	outtextxy(550, 25, "班 级");
	outtextxy(800, 25, "日 期");
	outtextxy(1050, 25, "考勤结果");

	for (int i = 0; i < num; i++) {
		char date_f[10] = { "" };
		char date[10] = { "" };
		sprintf(date, "%f", Students[i].date);
		strncpy(date_f, date, 5);
		if (strcmp(Students[i].Attandance_Result, "请假") == 0) {
			//printAll(i, 75+flag*50);
			//printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);

			settextstyle(25, 0, style1);
			settextcolor(BLACK);
			outtextxy(50, 75 + flag * 25, Students[i].Student_ID);
			outtextxy(300, 75 + flag * 25, Students[i].Name);
			outtextxy(550, 75 + flag * 25, Students[i].Class_Number);
			outtextxy(800, 75 + flag * 25, Students[i].Attandance_date);
			outtextxy(1050, 75 + flag * 25, Students[i].Attandance_Result);
			flag++;
		}

	}

	TCHAR b[] = _T("返回");
	button_f_s(1300, 25, 100, 50, b);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1300 && msg.x <= 1300 + 100 && msg.y >= 25 && msg.y <= 25 + 50)
				{
					Statistics();
				}
				break;
			default:
				break;
			}
		}
	}
}

void Statistics() {
	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)考勤日报表");
	TCHAR op2[] = _T("(2)考勤异常表");
	TCHAR op3[] = _T("(3)请假汇总表");
	TCHAR op4[] = _T("(4)返回");
	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);
	button_f_s(550, 700, 350, 75, op4);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					find3();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					Informal_Print();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					AskForLeave_Print();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 700 && msg.y <= 700 + 75)
				{
					TeachersPage();
				}
				break;
			default:
				break;
			}
		}
	}
}

char* getTime() {
	time_t timep;
	time(&timep);

	struct tm* p;
	p = gmtime(&timep);

	snprintf(t, 20, "%d-%d-%d,%d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);

	return t;
}

void getNums() {
	srand(time(0));
	int r = rand() % 9000 + 1000;
	char n[5];
	char destin[30] = "考 勤 暗 号 为：";
	numbers = r;
	sprintf(n, "%d", r);
	time_start = time((time_t*)NULL);
	strcpy(time_teacher, getTime());
	char* newStr = strncat(destin, n, 30);
	//settextstyle(100, 0, style1);
	//outtextxy(200, 350, "考 勤 暗 号 为：");
	//outtextxy(1000, 350, n);
	HWND hwndInput1 = GetHWnd();
	int isok = MessageBox(hwndInput1, destin, "提示", MB_OK);
}

float getDate() {
	time_t timep;
	time(&timep);

	struct tm* p;
	p = gmtime(&timep);

	float date = 1 + p->tm_mon + (float)p->tm_mday / 100;

	return date;
}

void add(char* result, char* ID) {
	strcpy(Students[num].Student_ID, ID);
	//setInfo("请输入学生的姓名", Students[num].Name);
	char Name[10];
	InputBox(Name, 10, "请输入学生的姓名：");
	strcpy(Students[num].Name, Name);
	//setInfo("请输入学生的班级", Students[num].Class_Number);
	char cl[10];
	InputBox(cl, 10, "请输入学生的班级：");
	strcpy(Students[num].Class_Number, cl);
	strcpy(Students[num].Attandance_date, getTime());
	strcpy(Students[num].Attandance_Result, result);
	Students[num].date = getDate();

	num++;//同学人数加一
	HWND hwndInput2 = GetHWnd();
	int isok = MessageBox(hwndInput2, "考勤成功", "提示", MB_OK);
	save();
}

void Add(char *nums) {
	char ID[maxsize];
	char attendance[10] = "出勤";
	char late[10] = "迟到";
	char truancy[10] = "旷课";
	char s_num[5];

	sprintf(s_num, "%d", numbers);

	if (strcmp(nums, s_num) == 0)
	{
		char ID[maxsize];
		//printf("请输入学号：");
		//scanf("%s", ID);
		InputBox(ID, 10, "请输入学号：");
		strcpy(Students[num].Student_ID, ID);
		Students[num].sec = time((time_t*)NULL);
		if (Students[num].sec - time_start <= 900)//15分钟
		{
			add(attendance, ID);
		}
		else if (Students[num].sec - time_start <= 2700)//45分钟
		{
			add(late, ID);
		}
		else
		{
			add(truancy, ID);
		}
	}
	else
	{
		HWND hwndInput2 = GetHWnd();
		int isok = MessageBox(hwndInput2, "考勤暗号错误，请重新输入考勤暗号：", "提示", MB_OK);
		StudentsPage();
	}
}

void AskForLeave() {
	char ID[maxsize];
	char leave[10] = "请假";

	//printf("请输入学号：");
	//scanf("%s", ID);
	InputBox(ID, 10, "请输入学号：");
	strcpy(Students[num].Student_ID, ID);
	//setInfo("请输入学生的姓名", Students[num].Name);
	char Name[10];
	InputBox(Name, 10, "请输入学生的姓名：");
	strcpy(Students[num].Name, Name);
	//setInfo("请输入学生的班级", Students[num].Class_Number);
	char cl[10];
	InputBox(cl, 10, "请输入学生的班级：");
	strcpy(Students[num].Class_Number, cl);

	//printf("请输入学生的考勤日期(月份、日期):");
	//scanf("%f", &Students[num].date);
	char date_s[10];
	InputBox(date_s, 10, "请输入学生请假的日期(月、日):");
	float ds = atof(date_s);
	Students[num].date = ds;

	sprintf(Students[num].Attandance_date, "%.2f", Students[num].date);

	strcpy(Students[num].Attandance_Result, leave);

	num++;//同学人数加一

	HWND hwndInput2 = GetHWnd();
	int isok = MessageBox(hwndInput2, "请 假 成 功！", "提示", MB_OK);
	save();
}

void TeachersPage(){
	//2.创建一个窗口,确定窗口大小,show_console(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR f1[] = _T("(1)生成考勤暗号");
	TCHAR f2[] = _T("(2)查找学生数据");
	TCHAR f3[] = _T("(3)修改学生记录");
	TCHAR f4[] = _T("(4)删除学生记录");
	TCHAR f5[] = _T("(5)显示学生考勤数据列表");
	TCHAR f6[] = _T("(6)对指定数据进行排序");
	TCHAR f7[] = _T("(7)进行数据统计");
	TCHAR f8[] = _T("(8)返回");
	button_t(100, 250, 300, 100, f1);
	button_t(600, 250, 300, 100, f2);
	button_t(1100, 250, 300, 100, f3);
	button_t(100, 400, 300, 100, f4);
	button_t(600, 400, 300, 100, f5);
	button_t(1100, 400, 300, 100, f6);
	button_t(100, 550, 300, 100, f7);
	button_t(600, 550, 300, 100, f8);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 100 && msg.x <= 100 + 300 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					getNums();
				}
				if (msg.x >= 600 && msg.x <= 600 + 300 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					Find();
				}
				if (msg.x >= 1100 && msg.x <= 1100 + 300 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					Change();
				}
				if (msg.x >= 100 && msg.x <= 100 + 300 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					Delete();
				}
				if (msg.x >= 600 && msg.x <= 600 + 300 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					Print();
				}
				if (msg.x >= 1100 && msg.x <= 1100 + 300 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					Order();
				}
				if (msg.x >= 100 && msg.x <= 100 + 300 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					Statistics();
				}
				if (msg.x >= 600 && msg.x <= 600 + 300 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					FirstPage();
				}
				break;
			default:
				break;
			}
		}
	}
	getNums();
}

void FirstPage()
{
	//2.创建一个窗口,确定窗口大小,EW_SHOWCONSOLE(显现控制台)
	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 250, "请 选 择 用 户:");
	TCHAR s[] = _T("学 生");
	TCHAR t[] = _T("老 师");
	button_f_s(400, 350, 200, 100, s);
	button_f_s(800, 350, 200, 100, t);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 400 && msg.x <= 400 + 200 && msg.y >= 350 && msg.y <= 350 + 100)
				{					
					StudentsPage();
					
				}
				if (msg.x >= 800 && msg.x <= 800 + 200 && msg.y >= 350 && msg.y <= 350 + 100)
				{
					TeachersPage();
				}
				break;
			default:
				break;
			}
		}
	}
}

void StudentsPage() {	

	initgraph(1500, 800);
	//设置背景颜色，one，two两步才能设置背景颜色，位置不能颠倒
	setbkcolor(WHITE);
	cleardevice();//清屏，初始化,清楚原来背景

	//主页面：
	settextstyle(50, 0, style1);
	settextcolor(BLACK);
	outtextxy(400, 50, "大 学 生 考 勤 管 理 系 统");

	//用户选择：
	settextstyle(50, 0, style1);
	outtextxy(550, 150, "请 选 择 功 能:");
	TCHAR op1[] = _T("(1)考 勤");
	TCHAR op2[] = _T("(2)请 假");
	TCHAR op3[] = _T("(3)返 回");

	button_f_s(550, 250, 350, 100, op1);
	button_f_s(550, 400, 350, 100, op2);
	button_f_s(550, 550, 350, 100, op3);

	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 250 && msg.y <= 250 + 100)
				{
					if (numbers == 0)
					{
						HWND hwndInput2 = GetHWnd();
						int isok = MessageBox(hwndInput2, "老 师 还 没 有 给 出 考 勤 暗 号：", "提示", MB_OK);
						StudentsPage();
					}
					else
					{
						//printf("输入考勤暗号:");
						//scanf("%d", &nums);
						//ADD_s(nums);
						char nums[10];
						InputBox(nums, 10, "请输入考勤暗号：");
						Add(nums);
					}
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 400 && msg.y <= 400 + 100)
				{
					AskForLeave();
				}
				if (msg.x >= 550 && msg.x <= 550 + 350 && msg.y >= 550 && msg.y <= 550 + 100)
				{
					FirstPage();
				}

				break;
			default:
				break;
			}
		}
	}
}

void save() {
	FILE* F = fopen("Manage.txt", "wt");
	fprintf(F, "%d\n", num);
	for (int i = 0; i < num; i++) {
		fprintf(F, "%s %s %s %s %.2f %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].date, Students[i].Attandance_Result);
	}
	fclose(F);
}

int main() {
	
	int i;
	FILE* fp = fopen("Manage.txt", "at+");
	/*
	 if (!fp) {
		printf("错误！未能打开文件\n");
		exit(0);
	}
	*/
	
	fscanf_s(fp, "%d", &num);
	//printf("当前系统中储存的学生个数：%d人\n", num);
	for (i = 0; i < num; i++) {
		fscanf(fp, "%s%s%s%s%f%s", &Students[i].Student_ID, &Students[i].Name, &Students[i].Class_Number, &Students[i].Attandance_date, &Students[i].date, &Students[i].Attandance_Result);
	}
	//getchar();
	FirstPage();
	//Find();
	//printAll(1, 75);
	//closegraph();
	/*
	char n[5];
	sprintf(n, "%d", num);
	HWND hwndInput3 = GetHWnd();
	int isok = MessageBox(hwndInput3, n, "提示", MB_OK);
	*/
	
	return 0;
}