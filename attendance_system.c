#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#define maxsize 30
#define maxnum 1000
 
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
char time_teacher[20] = {0};
char t[20] = {0};

/*实现每次输入结束最后输入回车退出的功能，更好的实现与用户的交互 */
void wait_for_Enter() {
	getchar();
	getchar();
}
char * getTime(){
    time_t timep;
    time(&timep);

    struct tm *p;
    p = gmtime(&timep);

    snprintf(t, 20, "%d-%d-%d,%d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);

    return t;
}

//11月9日就用double类型的11.9来表示
float getDate(){
	time_t timep;
    time(&timep);

    struct tm *p;
    p = gmtime(&timep);

	float date = 1 + p->tm_mon + (float)p->tm_mday/100;

	return date;
}
void getNums(){
	srand(time(0));
	int r = rand() % 9000 + 1000;
	numbers = r;
	time_start = time((time_t *)NULL);
	strcpy(time_teacher, getTime());
	printf("考勤暗号为：%d\n", r);
	printf("暗号已生成，按回车继续：");

	wait_for_Enter();
}

void copy(student *a,student *b) {
	strcpy(a->Student_ID , b->Student_ID);
	strcpy(a->Name , b->Name);
	strcpy(a->Class_Number , b->Class_Number);
	strcpy(a->Attandance_Result , b->Attandance_Result);
	strcpy(a->Attandance_date , b->Attandance_date);
	a->date = b->date;
}

/*输入函数，为了简化代码*/
void setInfo(char pinfo[], char desinfo[]) {
	printf("%s：", pinfo);
	scanf("%s", desinfo);
}

/*输出每个学生的详细信息*/
void PrintAllInformation() {
	int i;
	printf("------------------------------------\n");
	for (i = 0; i < num; i++)
		printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	wait_for_Enter();
}

/*输出每个学生的部分信息*/
void PrintPartInformation() {
	int i;
	printf("------------------------------------\n");
	for (i = 0; i < num; i++)
		printf("姓名:%s 日期:%s 考勤结果:%s\n", Students[i].Name, Students[i].Attandance_date, Students[i].Attandance_Result);
	printf("------------------------------------\n");
	printf("打印成功！按回车键返回\n");
	wait_for_Enter();
}

void AskForLeave(){
    char ID[maxsize];
    char leave[10] = "请假";

    printf("请输入学号：");
	scanf("%s", ID);
    strcpy(Students[num].Student_ID, ID);
	setInfo("请输入学生的姓名", Students[num].Name);
	setInfo("请输入学生的班级", Students[num].Class_Number);

	printf("请输入学生请假的日期(月、日):");	
	scanf("%f", &Students[num].date);

	sprintf(Students[num].Attandance_date, "%.2f", Students[num].date);

	strcpy(Students[num].Attandance_Result, leave);

	num++;//同学人数加一
	printf("按回车键返回\n");
	wait_for_Enter();
}

void add_s(char *result, char *ID){
	strcpy(Students[num].Student_ID, ID);
	setInfo("请输入学生的姓名", Students[num].Name);
	setInfo("请输入学生的班级", Students[num].Class_Number);
	strcpy(Students[num].Attandance_date, getTime());
	strcpy(Students[num].Attandance_Result, result);
	Students[num].date = getDate();
										
	num++;//同学人数加一
	printf("考勤成功！按回车键返回\n");
	wait_for_Enter();
}

void ADD_s(int nums){
	char ID[maxsize];
	char attendance[10] = "出勤";
	char late[10] = "迟到";
	char truancy[10] = "旷课";
	
	if (nums == numbers)
	{
		char ID[maxsize];
		printf("请输入学号：");
		scanf("%s", ID);
		Students[num].sec = time((time_t *)NULL);
		if (Students[num].sec-time_start <= 900)//15分钟
		{
			add_s(attendance, ID);
		}
		else if (Students[num].sec-time_start <= 2700)//45分钟
		{
			add_s(late, ID);
		}
		else
		{
			add_s(truancy, ID);
		}		
	}
	else
	{
		int a;
		printf("输入的课堂码错误，请重新输入:\n");
		scanf("%d", &a);
		ADD_s(a);
	}
	
}

/*该函数实现的是查找的功能，可以按学号，姓名，考勤日期进行查找*/
void Find() {
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
	} else if (op == 2) {
		printf("请输入该生姓名：");
		scanf("%s", information);
		for (i = 0; i < num; i++) {
			if (strcmp(information, Students[i].Name) == 0) 
				printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;
		}
	} else {
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
	wait_for_Enter();
}
/*该函数实现的是对系统中已经存在的信息进行修改，类似上面的查找，也可以根据不同的信息选择想要修改的信息进行修改*/
void Change() {
	int i, j = -1;
	char op[2], information[maxsize], find[maxsize];
	printf("<1>按学号修改                 <2>按姓名修改\n");
	scanf("%s", op);
	if (op[0] == '1') 
		setInfo("请输入该生学号", information);
	else if (op[0] == '2') 
		setInfo("请输入该生姓名", information);
	strcpy(find, information);
	if(op[0]=='1')
		for (i = 0; i < num; i++) {
			if (strcmp(find, Students[i].Student_ID) == 0) 
				j = i;
		}
	else if(op[0]=='2')
		for (i = 0; i < num; i++) {
			if (strcmp(find, Students[i].Name) == 0) 
				j = i;
		}
	if (j == -1) {
		printf("不存在要找的信息！\n");
		printf("按回车键返回\n");
		wait_for_Enter();
		return;
	}
	setInfo("<1>修改学号  <2>修改姓名  <3>修改考勤结果", op);
	if (op[0] == '1') {
		setInfo("请输入修改后的新学号", information);
		strcpy(Students[j].Student_ID, information);
	} else if (op[0] == '2') {
		setInfo("请输入修改后的新姓名", information);
		strcpy(Students[j].Name, information);
	} 
	else{
		setInfo("请输入修改后的新考勤结果", information);
		strcpy(Students[j].Attandance_Result, information);
	}
	printf("按回车键返回！\n");
	wait_for_Enter();
}

/*该函数实现的是对已经存在于系统种的同学的信息进行删除操作，具体想法是学生人数num--，后面所有人的信息前移一个位置，实现信息的覆盖*/
void Delete() {
	int i, j,flag = -1;
	char op[2],information[maxsize];
	setInfo("请输入：<1>按学号删除       <2>按姓名删除", op);
	if (op[0] == '1') {
		setInfo("请输入学号", information);
		for (i = 0; i < num; i++) {
			if (strcmp(Students[i].Student_ID, information) == 0) {
				flag = 1;
				for (j = i + 1; j < num; j++) {
					copy(&Students[i], &Students[j]);
				}
			}
		}
	} else {
		setInfo("请输入姓名", information);
		for (i = 0; i < num; i++) {
			if (strcmp(Students[i].Name, information) == 0) {
				flag = 1;
				for (j = i + 1; j < num; j++) {
					copy(&Students[i], &Students[j]);
				}
			}
		}
	}
	if (flag == -1) {
		printf("不存在此信息！\n");
		printf("按回车键返回\n");
		wait_for_Enter();
		return ;
	}
	num--;
	wait_for_Enter();
}

/*此函数实现的是功能5 对系统中已经存在的信息进行输出*/
void Print() {
	int op;
	printf("请选择\n<1>部分打印（输出学生姓名和考勤日期和考勤情况）\n<2>全部打印（输出所有学生的所有信息）：");
	scanf("%d", &op);
	if (op == 1) 
		PrintPartInformation();
	else 
		PrintAllInformation();
 
}

/*交换两个变量的所有成员的数值，因为成员都是char数组，所以用到了strcmp函数。此函数主要是为排序进行服务，采用指针进行交换*/
void exchange(student *a, student *b) {
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
/*实现功能6排序，可以按学号，姓名，考勤日期进行排序，使用的是冒泡排序对所要求的信息进行排序*/
void Order() {
	int op, i, j;
	char tmp[maxsize];
	printf("请输入：<1>按学号从小到大排序 <2>按学生姓名ASCLL码排序 <3>按考勤日期从小到大排序：\n");
	scanf("%d", &op);
	if (op == 1) {
		for (i = 0; i < num; i++) {
			for (j = i+1; j < num; j++) {
				if (strcmp(Students[i].Student_ID, Students[j].Student_ID) > 0) {
					exchange(&Students[i], &Students[j]);
				}
			}
		}
	} else if (op == 2) {
		for (i = 0; i < num; i++) {
			for (j = i+1; j < num; j++) {
				if (strcmp(Students[i].Name, Students[j].Name) > 0) {
					exchange(&Students[i], &Students[j]);
				}
			}
		}
	} else {
		for (i = 0; i < num; i++) {
			for (j = i+1; j < num; j++) {
				if (Students[i].date > Students[j].date) {
					exchange(&Students[i], &Students[j]);
				}
			}
		}		
	}
	printf("排序成功！按回车键返回\n");
	wait_for_Enter();
}

/*输出考勤明细表*/ 
void Detail_Print() {
	int i, j;
	char tmp[maxsize];
	int month_1, month_2, day_1, day_2;
	
	printf("------------------------------------\n");
	printf("考勤明细表：\n");
	printf("%s：\n", Students[0].Attandance_date);
	printf("学号:%s 姓名:%s 班级:%s 考勤结果:%s\n", Students[0].Student_ID, Students[0].Name, Students[0].Class_Number, Students[0].Attandance_Result);
	strcmp(tmp, Students[0].Attandance_date);
	for (i = 1; i < num; i++) {
		if (strcmp(Students[i].Attandance_date, tmp) != 0) {
			printf("%s：\n", Students[i].Attandance_date);
			strcmp(tmp, Students[i].Attandance_date);
		}
		printf("学号:%s 姓名:%s 班级:%s 考勤结果:%s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_Result);
	}
	printf("------------------------------------\n");
	printf("按回车键返回\n");
	wait_for_Enter();
}

/*考勤日报表*/ 
void Daily_Print() {
	int i, flag = 0;
	float information;

	printf("请输入要查看的日期:\n");
	scanf("%f", &information);
	printf("------------------------------------\n");
	printf("%.2f的考勤情况：\n", information);
	for (i = 0; i < num; i++) {
		if (information == Students[i].date){
			printf("学号:%s 姓名:%s 班级:%s 考勤结果:%s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_Result);
			flag = 1;
		}  
	}
	if (flag == 0)
	{
		printf("无当天考勤信息\n");
	}
	printf("------------------------------------\n");
	printf("按回车键返回\n");
	wait_for_Enter();
}

/*考勤异常表，输出所有不是 ‘出勤 ’的人的信息*/ 
void Informal_Print() {
	int i, cnt = 0;
	printf("------------------------------------\n");
	printf("考勤异常表：\n");
	for (i = 0; i < num; i++) {
		if (strcmp(Students[i].Attandance_Result, "出勤") != 0)
			printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), cnt++;
	}
	printf("考勤异常人数：%d人\n", cnt);
	printf("------------------------------------\n");
	printf("按回车键返回\n");
	wait_for_Enter();
}

/*请假异常表，输出所有请假的人的信息*/ 
void AskForLeave_Print() {
	int i, cnt = 0;
	printf("------------------------------------\n");
	printf("请假异常表\n");
	for (i = 0; i < num; i++) {
		if (strcmp(Students[i].Attandance_Result, "请假") == 0 || strcmp(Students[i].Attandance_Result, "○") == 0)
			printf("学号:%s 姓名:%s 班级:%s 日期:%s 考勤结果:%s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), cnt++;
	}
	printf("请假人数：%d人\n", cnt);
	printf("------------------------------------\n");
	printf("按回车键返回\n");
	wait_for_Enter();
}
/*事项功能7进行数据统计*/ 
void Statistics() {
	char op[2];
	setInfo("请选择\n<1>考勤明细表\n<2>考勤日报表\n<3>考勤异常表\n<4>请假汇总表",op);
	if (op[0] == '1') {
		Detail_Print();
	} else if (op[0] == '2') {
		Daily_Print();
	} else if (op[0] == '3') {
		Informal_Print();
	} else {
		AskForLeave_Print();
	}
}
 
int main() {
	int i, a, q = 1, t = 1, s = 1, a1, a2, nums;
	FILE *fp= fopen("Manage.txt", "at+");
	if (!fp) {
		printf("错误！未能打开文件\n");
		exit(0);
	}
	fscanf(fp, "%d", &num);
	printf("当前系统中储存的记录个数：%d人\n", num);
	for (i = 0; i < num; i++) {
		fscanf(fp, "%s%s%s%s%f%s", &Students[i].Student_ID, &Students[i].Name, &Students[i].Class_Number, &Students[i].Attandance_date, &Students[i].date, &Students[i].Attandance_Result);
	}
	fclose(fp);
	while (q != 0) {
		printf("==============================================================================\n\n");
		printf("                          大学生考勤系统\n\n");
		printf("==============================================================================\n\n");
		printf("请选择用户\n");
		printf("<1> 老师                      <2> 学生                    <3> 保存并退出     \n");
		scanf("%d", &a);
		switch (a)
		{	
		case 1:
			while (t != 0)
			{
				printf("==============================================================================\n\n");
				printf("                          大学生考勤系统\n\n");
				printf("==============================================================================\n\n");
				printf("<1> 生成考勤暗号         <2> 查找学生数据             <3> 修改学生记录     \n");
				printf("<4> 删除学生记录         <5> 显示学生考勤的数据列表    <6> 对指定数据进行排序 \n");
				printf("<7> 进行数据统计         <8> 退出当前用户      \n\n");
				scanf("%d", &a1);
				switch (a1) {
					case 1:
						getNums();
						break;
					case 2:
						Find();
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
						printf("已退出当前用户\n");
						t = 0;
						break;
				}
				system("cls");
				
			}
			t = 1;
			break;
			
		case 2:
			while (s != 0 )
			{
				printf("==============================================================================\n\n");
				printf("                          大学生考勤系统\n\n");
				printf("==============================================================================\n\n");
				printf("<1> 考勤                      <2> 请假                         <3> 退出当前用户\n\n");
				scanf("%d", &a2);
				switch (a2)
				{
				case 1:
					if (numbers == 0)
					{
						printf("老师还没有给出考勤暗号：\n");
					}
					else
					{
						printf("输入考勤暗号:");
						scanf("%d", &nums);
						ADD_s(nums);
					}
					break;
                case 2:
                    AskForLeave();
					break;
				case 3:
					printf("已退出当前用户\n");
					s = 0;
					break;
				}
			}
			s = 1;
			break;

		case 3:
			printf("已保存并退出");
			q = 0;		
		}
	}
	FILE *F=fopen("Manage.txt","wt");
	fprintf(F, "%d\n", num);
	for (int i = 0; i < num; i++) {
		fprintf(F, "%s %s %s %s %.2f %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].date, Students[i].Attandance_Result);
	}
	fclose(F);

	return 0;
}
