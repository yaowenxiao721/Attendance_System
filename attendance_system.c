#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student 
{
	char ID[20];
	char Name[20];
	char Class[20];
	int date;
	char Attandance[20];
} student;

student Students[500];

int num = 0;

/*合并printf和scanf的功能*/
void fs(char a[], char b[])
{
	printf("%s：", a);
	scanf("%s", b);
}

/*学号唯一*/
int judge(char* ID)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (strcmp(Students[i].ID, ID) == 0)
			return 0;
	}
	return 1;
}

/*添加同学信息*/
void ADD()
{
	char ID[20];
	printf("请输入学生的学号：");
	scanf("%s", ID);
	if (!judge(ID))
	{
		printf("不可重复添加！请按回车键返回\n");
		getchar();
		getchar();
		return;
	}
	strcpy(Students[num].ID, ID);
	fs("请输入学生的姓名", Students[num].Name);
	fs("请输入学生的班级", Students[num].Class);
	printf("请输入学生的考勤日期:");
	scanf("%d", &Students[num].date);
	fs("请输入学生的考勤结果出 勤 √   旷 课 X   事 假 △   病 假 ○   迟 到 +   早 退 –", Students[num].Attandance);
	printf("添加成功!按回车键返回\n");
	num++;
	getchar();
	getchar();
}

/*按学号，姓名，考勤日期查找学生*/
void Search()
{
	int i, op, flag = 0, d;
	char infor[20];
	printf("[1]按学号查找  [2]按姓名查找  [3]按考勤日期查找\n");
	scanf("%d", &op);
	if (op == 1)
	{
		printf("请输入该生学号：");
		scanf("%s", infor);
		for (i = 0; i < num; i++)
		{
			if (strcmp(infor, Students[i].ID) == 0)
			{
				printf("%s %s %s %d %s\n\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].date, Students[i].Attandance);
				flag = 1;
			}

		}
	}
	else if (op == 2)
	{
		printf("请输入该生姓名：");
		scanf("%s", infor);
		for (i = 0; i < num; i++)
		{
			if (strcmp(infor, Students[i].Name) == 0)
			{
				printf("%s %s %s %d %s\n\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].date, Students[i].Attandance);
				flag = 1;
			}
		}
	}
	else
	{
		printf("请输入考勤日期：");
		scanf("%d", &d);
		for (i = 0; i < num; i++)
		{
			if (Students[i].date == d)
			{
				printf("%s %s %s %d %s\n\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].date, Students[i].Attandance);
				flag = 1;
			}
		}
	}
	if (flag == 0)
		printf("不存在此信息！按回车键返回\n");
	getchar();
	getchar();
}

/*该按学号，姓名，考勤日期修改信息*/
void Change()
{
	int i, op, j = -1, a, b;
	char infor[20];
	printf("[1]按学号修改  [2]按姓名修改  [3]按考勤日期修改\n");
	scanf("%d", &op);
	if (op == 1)
	{
		fs("请输入该生学号", infor);
		for (i = 0; i < num; i++)
			if (strcmp(infor, Students[i].ID) == 0) j = i;
	}
	else if (op == 2)
	{
		fs("请输入该生姓名", infor);
		for (i = 0; i < num; i++)
			if (strcmp(infor, Students[i].Name) == 0) j = i;
	}
	else 
{
		printf("请输入考勤日期:");
		scanf("%d", &a);
		for (i = 0; i < num; i++)
			if (Students[i].date == a) j = i;
	}
	if (j == -1)
	{
		printf("不存在要找的信息！按回车键返回\n");
		getchar();
		getchar();
		return;
	}

	printf("[1]修改学号  [2]修改姓名  [3]修改考勤日期\n");
	scanf("%d", &op);
	if (op == 1)
	{
		fs("请输入修改后的新学号", infor);
		strcpy(Students[j].ID, infor);
	}
	else if (op == 2)
	{
		fs("请输入修改后的新姓名", infor);
		strcpy(Students[j].Name, infor);
	}
	else
	{
		printf("请输入修改后的新考勤日期:");
		scanf("%d", &b);
		Students[j].date = b;
	}
	printf("修改完成！按回车键返回！\n");
	getchar();
	getchar();
}

/*将b学生的信息复制到a学生*/
void copy(student* a, student* b)
{
	strcpy(a->ID, b->ID);
	strcpy(a->Name, b->Name);
	strcpy(a->Class, b->Class);
	strcpy(a->Attandance, b->Attandance);
	a->date = b->date;
}

/*删除已经录入的学生信息*/
void Delete()
{
	int i, j, op, flag = 0;
	char  infor[20];
	printf("请输入：[1]按学号删除[2]按姓名删除");
	scanf("%d", &op);
	if (op == 1)
	{
		fs("请输入学号", infor);
		for (i = 0; i < num; i++)
		{
			if (strcmp(Students[i].ID, infor) == 0)
			{

				for (j = i + 1; j < num; j++)
				{
					copy(&Students[i], &Students[j]);
					flag = 1;
				}
			}
		}
	}
	else
	{
		fs("请输入姓名", infor);
		for (i = 0; i < num; i++)
		{
			if (strcmp(Students[i].Name, infor) == 0)
			{ 	
flag = 1;
				for (j = i + 1; j < num; j++)
					copy(&Students[i], &Students[j]);
			}
		}
	}
	if (flag == 0)
	{
		printf("不存在此信息！按回车键返回\n");
		getchar();
		getchar();
		return;
	}
	num--;
	printf("删除成功！按回车键返回\n");
	getchar();
	getchar();
}

//输出全部信息//
void Printall()
{
	int i;
	printf("------------------------------------\n");
	for (i = 0; i < num; i++)
		printf("%s %s %s %d %s\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].date, Students[i].Attandance);
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	getchar();
	getchar();
}

//输出部分信息//
void Printpart()
{
	int i;
	printf("------------------------------------\n");
	for (i = 0; i < num; i++)
		printf("%s %d %s\n", Students[i].Name, Students[i].date, Students[i].Attandance);
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	getchar();
	getchar();
}

void Print()
{
	int op;
	printf("请选择\n[1]部分打印\n[2]全部打印：");
	scanf("%d", &op);
	if (op == 1) Printpart();
	else Printall();
}

/*交换学生信息*/
void exchange(student* a, student* b)
{
	char tmp[20];
	int c;
	strcpy(tmp, a->ID);
	strcpy(a->ID, b->ID);
	strcpy(b->ID, tmp);

	strcpy(tmp, a->Name);
	strcpy(a->Name, b->Name);
	strcpy(b->Name, tmp);

	strcpy(tmp, a->Class);
	strcpy(a->Class, b->Class);
	strcpy(b->Class, tmp);

	strcpy(tmp, a->Attandance);
	strcpy(a->Attandance, b->Attandance);
	strcpy(b->Attandance, tmp);

	c = a->date;
	a->date = b->date;
	b->date, c;
	return;
}

/*按学号，姓名，考勤日期进行排序*/
void Order()
{
	int op, i, j;
	printf("请输入：[1]按学号从小到大排序 [2]按学生姓名ASCLL码排序 [3]按考勤日期从小到大排序：\n");
	scanf("%d", &op);
	if (op == 1)
	{
		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				if (strcmp(Students[i].ID, Students[j].ID) > 0)
					exchange(&Students[i], &Students[j]);
			}
		}
	}
	else if (op == 2)
	{
		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				if (strcmp(Students[i].Name, Students[j].Name) > 0)
					exchange(&Students[i], &Students[j]);
			}
		}
	}
	else {
		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				if (Students[i].date > Students[j].date)
					exchange(&Students[i], &Students[j]);
			}
		}
	}
	printf("排序成功！按回车键返回\n");
	getchar();
	getchar();
}
/*输出考勤明细表*/
void Detail()
{
	int i, j;
	printf("------------------------------------\n");
	printf("考勤明细表：\n");
	for (i = 0; i <= 1231; i++)
	{
		for (j = 0; j <= num - 1; j++)
		{
			if (i == Students[j].date)
			{
				printf("%d：\n", Students[j].date);
				printf("%s %s %s %s\n", Students[j].ID, Students[j].Name, Students[j].Class, Students[j].Attandance);
			}
		}
	}
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	getchar();
	getchar();
}

/*考勤日报表*/
void Daily()
{
	int i, a;
	printf("输入要查看的日期：\n");
	scanf("%d", &a);
	printf("------------------------------------\n");
	printf("%d的考勤情况：\n", a);
	for (i = 0; i < num; i++)
	{
		if (a == Students[i].date) printf("%s %s %s %s\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].Attandance);
	}
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	getchar();
	getchar();
}

/*考勤异常表*/
void Informal_Print()
{
	int i, j = 0;
	printf("------------------------------------\n");
	printf("考勤异常表：\n");
	for (i = 0; i < num; i++)
	{
		if (strcmp(Students[i].Attandance, "√") != 0)
			printf("%s %s %s %d %s\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].date, Students[i].Attandance), j++;
	}
	printf("考勤异常人数：%d人\n", j);
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	getchar();
	getchar();
}
/*考勤汇总表*/
void AllDaily_Print()
{
	int i, j = 0, k = 0;
	printf("------------------------------------\n");
	for (i = 0; i < num; i++)
	{
		if (strcmp(Students[i].Attandance, "√") == 0)
			j++;
		else
			k++;
	}
	printf("出勤人数为:%d\n缺勤人数为:%d\n",j, k);
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	getchar();
	getchar();
}

/*请假汇总表*/
void AskForLeave_Print()
{
	int i, j = 0;
	printf("------------------------------------\n");
	printf("请假汇总表\n");
	for (i = 0; i < num; i++) 
{
		if (strcmp(Students[i].Attandance, "○") == 0 || strcmp(Students[i].Attandance, "△") == 0)
			printf("%s %s %s %d %s\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].date, Students[i].Attandance), j++;
	}
	printf("请假人数：%d人\n", j);
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	getchar();
	getchar();
}

/*数据统计*/
void Statistics()
{
	int op;
	printf("请选择\n[1]考勤明细表\n[2]考勤日报表\n[3]考勤异常表\n[4]考勤汇总表\n[5]请假汇总表\n");
	scanf("%d", &op);
	if (op == 1)
		Detail();
	else if (op == 2)
		Daily();
	else if (op == 3)
		Informal_Print();
	else if (op == 4)
		AllDaily_Print();
	else if (op == 5)
		AskForLeave_Print();
}

int main()
{
	int i, a, b = 1;
	FILE* fp = fopen("Manage.txt", "at+");
	if (!fp)
	{
		printf("错误！未能打开文件\n");
		exit(0);
	}
	fscanf(fp, "%d", &num);
	printf("当前系统中储存的学生个数：%d人\n", num);
	for (i = 0; i < num; i++)
	{
		fscanf(fp, "%s%s%s%d%s", &Students[i].ID, &Students[i].Name, &Students[i].Class, &Students[i].date, &Students[i].Attandance);
	}
	fclose(fp);
	while (b != 0) 
{
		printf("--------------------------------------------------------------------------------\n\n");
		printf("                          大学生考勤系统\n\n");
		printf("--------------------------------------------------------------------------------\n\n");
		printf("[1] 新增学生数据        [2] 查找学生数据             [3]修改学生记录     \n");
		printf("[4]删除学生记录         [5] 显示学生考勤的数据列表   [6] 对指定数据进行排序 \n");
		printf("[7]进行数据统计         [8] 退出\n\n");
		scanf("%d", &a);
		switch (a) 
{
		case 1:
			ADD();
			break;
		case 2:
			Search();
			break;
		case 3:
			Change();
			break;
		case 4:
			Delete();
			break;
		case 5:
			Print();
			break;
		case 6:
			Order();
			break;
		case 7:
			Statistics();
			break;
		case 8:
			printf("已退出\n");
			b = 0;
			break;
	  }
		system("cls");//清屏函数 
	}
	FILE* F = fopen("Manage.txt", "wt");
	fprintf(F, "%d\n", num);
	for (int i = 0; i < num; i++) 
{
		fprintf(F, "%s %s %s %d %s\n", Students[i].ID, Students[i].Name, Students[i].Class, Students[i].date, Students[i].Attandance);
	}
	fclose(F);
	return 0;
}
