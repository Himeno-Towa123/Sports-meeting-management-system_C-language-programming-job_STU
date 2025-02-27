#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Sporters 224
static struct information
{
	char name[10];//姓名
	char gender[10];//性别
	int stuID;//学号
	int proID;//项目编号
	double score;//成绩
	int points;//得分
}sporters[Max_Sporters];

void Handle();//业务办理
void Schedule();//赛程安排
void Project_male();//项目编号（男）
void Project_female();//项目编号（女）
void Application(char* pname_temp, char* pgender_temp, int* pstuID_temp,
	int* pproID_temp, int* total);//录入报名信息
void Revise(int* total);//修改报名信息
void Delete(int* total);//删除报名信息
void Total_Sporters(int* total);//打印所有运动员的信息
void Score(int*total);//录入成绩
int Points(int num_sporter ,int rank);//计算得分
void Rank(int* total);//查看得分，名次
void Format();//查看赛制
void Div_line();//打印分割线

int main()
{   
	printf("欢迎使用校园运动会管理系统\n");
	char ch = '0';
	int i = 0;
	int* total = &i;
	Handle();//提示业务处理
	while ((scanf("%c",&ch)==1))
	{	

		if (ch == '0')
			break;
		switch (ch) 
		{
		case '1':
			Schedule();
			break;
		case '2':
			Project_male();
			Project_female();
			break;
		case '3':
			if (i < Max_Sporters)
			{
				Application(&sporters[i].name, &sporters[i].gender,
					 &sporters[i].stuID, &sporters[i].proID, total);
			}
			else
				printf("报名人数已满，无法继续报名\n");
			break;
		case '4':
			Revise(total);
			break;
		case '5':
			Delete(total);
			break;
		case '6':
			Total_Sporters(total);
			break;
		case '7':
			Score(total);
			break;
		case '8':
			Rank(total);
			break;
		case '9':
			Format();
			break;
		default:
			printf("无效的输入\n");
			system("pause");
			break;
		}
		Handle();//提示业务处理
		while (getchar() != '\n');//清理缓冲区中的换行符或其他无用字符
	}

	printf("\n感谢使用该运动员管理系统\n");
	return 0;
}

void Handle()//业务办理
{
	Div_line();
	printf("请选择你要办理的业务\n");
	printf("0.退出系统\n1.查看赛程\n2.查看项目编号\n3.报名项目信息录入\n4.修改报名项目信息\n");
	printf("5.删除报名项目信息\n6.查询运动员报名项目信息\n7.录入成绩\n8.比赛得分查询\n9.查看赛制\n");
	printf("请输入你要办理的业务编号：");
}
void Schedule()//赛程安排
{
	Div_line();
	printf("运动会赛程安排表");
	Div_line();
	printf("时间\t\t地点\t\t项目\v");
	printf("12月4日\n");
	printf("07:30-08:00\t田径场\t\t开幕式\v");
	printf("08:30-10:00\t跑道\t\t50m跑(男)\v");
	printf("08:30-10:00\t跑道\t\t50m跑(女)\v");
	printf("08:30-10:00\t田场\t\t引体向上(男)\v");
	printf("08:30-10:00\t田场\t\t仰卧起坐(女)\v");
	printf("10:30-12:00\t跑道\t\t100m跑(男)\v");
	printf("10:30-12:00\t跑道\t\t100m跑(女)\v");
	printf("10:30-12:00\t田场\t\t跳高(男)\v");
	printf("10:30-12:00\t田场\t\t跳高(女)\v");
	printf("14:30-16:00\t跑道\t\t200m跑(男)\v");
	printf("14:30-16:00\t跑道\t\t200m跑(女)\v");
	printf("14:30-16:00\t田场\t\t三级跳远(男)\v");
	printf("14:30-16:00\t田场\t\t三级跳远(女)\v");
	printf("16:00-17:30\t跑道\t\t1000m跑(男)\v");
	printf("16:00-17:30\t跑道\t\t800m跑(女)\v");
	printf("16:00-17:30\t跑道\t\t4*100m接力跑(男)\v");
	printf("16:00-17:30\t跑道\t\t4*100m接力跑(女)\v");
	printf("12月5日\n");
	printf("08:30-10:00\t跑道\t\t5000m跑(男)\v");
	printf("08:30-10:00\t跑道\t\t5000m跑(女)\v");
	printf("08:30-10:00\t田场\t\t铅球(男)\v");
	printf("08:30-10:00\t田场\t\t铅球(女)\v");
	printf("10:30-12:00\t跑道\t\t110m跨栏(男)\v");
	printf("10:30-12:00\t跑道\t\t100m跨栏(女)\v");
	printf("10:30-12:00\t田场\t\t跳远(男)\v");
	printf("10:30-12:00\t田场\t\t跳远(女)\v");
	printf("14:30-16:00\t田场\t\t撑杆跳(男)\v");
	printf("14:30-16:00\t田场\t\t撑杆跳(女)\v");
	printf("14:30-16:00\t田场\t\t标枪(男)\v");
	printf("14:30-16:00\t田场\t\t标枪(女)\v");
	printf("16:30-17:00\t田径场\t\t闭幕式\v");
	printf("********************************");
	printf("********************************");
	printf("********************************\n");
	system("pause");
}
void Project_male()
{
	printf("编号\t时间\t\t地点\t\t项目\v");
	printf("\t12月4日\n");
	printf("\t07:30-08:00\t田径场\t\t开幕式\v");
	printf("1\t08:30-10:00\t跑道\t\t50m跑(男)\v");
	printf("3\t08:30-10:00\t田场\t\t引体向上(男)\v");
	printf("5\t10:30-12:00\t跑道\t\t100m跑(男)\v");
	printf("7\t10:30-12:00\t田场\t\t跳高(男)\v");
	printf("9\t14:30-16:00\t跑道\t\t200m跑(男)\v");
	printf("11\t14:30-16:00\t田场\t\t三级跳远(男)\v");
	printf("13\t16:00-17:30\t跑道\t\t1000m跑(男)\v");
	printf("\t12月5日\n");
	printf("15\t08:30-10:00\t跑道\t\t5000m跑(男)\v");
	printf("17\t08:30-10:00\t田场\t\t铅球(男)\v");
	printf("19\t10:30-12:00\t跑道\t\t110m跨栏(男)\v");
	printf("21\t10:30-12:00\t田场\t\t跳远(男)\v");
	printf("23\t14:30-16:00\t田场\t\t撑杆跳(男)\v");
	printf("25\t14:30-16:00\t田场\t\t标枪(男)\v");
	printf("\t16:30-17:00\t田径场\t\t闭幕式\v");
	printf("\n");
}
void Project_female()
{
	printf("编号\t时间\t\t地点\t\t项目\v");
	printf("\t12月4日\n");
	printf("2\t08:30-10:00\t跑道\t\t50m跑(女)\v");
	printf("4\t08:30-10:00\t田场\t\t仰卧起坐(女)\v");
	printf("6\t10:30-12:00\t跑道\t\t100m跑(女)\v");
	printf("8\t10:30-12:00\t田场\t\t跳高(女)\v");
	printf("10\t14:30-16:00\t跑道\t\t200m跑(女)\v");
	printf("12\t14:30-16:00\t田场\t\t三级跳远(女)\v");
	printf("14\t16:00-17:30\t跑道\t\t800m跑(女)\v");
	printf("\t12月5日\n");
	printf("16\t08:30-10:00\t跑道\t\t5000m跑(女)\v");
	printf("18\t08:30-10:00\t田场\t\t铅球(女)\v");
	printf("20\t10:30-12:00\t跑道\t\t100m跨栏(女)\v");
	printf("22\t10:30-12:00\t田场\t\t跳远(女)\v");
	printf("24\t14:30-16:00\t田场\t\t撑杆跳(女)\v");
	printf("26\t14:30-16:00\t田场\t\t标枪(女)\v");
	system("pause");
	printf("\n");
}
void Application(char* pname_temp, char* pgender_temp, int* pstuID_temp,
	int* pproID_temp, int* total)//报名信息录入
{
	Div_line();
	int con;
	printf("已进入报名信息录入系统\n");
	printf("请确认你是否知道所要报名的项目编号\n");
	printf("输入任意非0的数报名继续，输入0则返回\n请输入：");
	scanf("%d", &con);
	if (con == 0)
		return;
	printf("现在请输入运动员的姓名\n");
	scanf("%19s", pname_temp);
	printf("请输入运动员的性别\n");
	scanf("%9s", pgender_temp);
	printf("请输入运动员的学号\n");
	scanf("%d", pstuID_temp);
	printf("请输入运动员所报项目的编号\n");
	scanf("%d", pproID_temp);
	if ((*pproID_temp) >= 1 && (*pproID_temp) <= 26)
	{
		printf("报名成功，即将返回业务办理处\n");
		(*total)++;
		printf("该运动员编号为%d\n", *total);
		sporters[*total].score = 0;
	}
	else
	{
		printf("报名失败，即将返回业务办理处\n");
		*pname_temp = "";
		*pgender_temp = "";
		*pstuID_temp = NULL;
		*pproID_temp = NULL;
	}
	system("pause");
	printf("\n");
}
void Revise(int*total)
{
	Div_line();
	int con, a;
	int s;
	char r[20];
	char k;
	printf("已进入报名信息修改系统\n");
	printf("请确认你是否知道目标运动员的编号\n");
	printf("输入任意非0的数修改继续，输入0则返回\n请输入：");
	scanf("%d", &con);
	if (con == 0)
		return;
	printf("请输入你要修改报名信息的运动员编号：");
	scanf("%d", &a);
	if (a > 0 && a <= *total)
	{	
		printf("你要修改该运动员的\n1.姓名2.性别3.学号4.项目编号\n");
		while (getchar() != '\n');
		scanf("%c", &k);
		switch (k)
		{
		case '1':
			printf("修改为：");
			scanf("%s", r);
			strcpy(sporters[a - 1].name, r);
			printf("修改成功\n");
			break;
		case '2':
			printf("修改为：");
			scanf("%s", r);
			strcpy(sporters[a - 1].gender, r);
			printf("修改成功\n");
			break;
		case '3':
			printf("修改为：");
			scanf("%d", &s);
			sporters[a - 1].stuID = s;
			printf("修改成功\n");
			break;
		case '4':
			printf("修改为：");
			scanf("%d", &s);
			sporters[a - 1].proID = s;
			printf("修改成功\n");
			break;
		default:
			printf("无效的输入\n");
			system("pause");
			break;
		}
	}
	else 
	{
		printf("目标运动员不存在，即将返回主界面\n");
	}
}
void Delete(int* total)
{
	Div_line();
	int con, a;
	printf("已进入报名信息删除系统\n");
	printf("请确认你是否知道要删除报名信息的运动员编号\n");
	printf("输入任意非0的数继续进行，输入0则返回\n请输入：");
	scanf("%d", &con);
	if (con == 0)
		return;
	printf("请输入你要删除报名信息的运动员编号：");
	scanf("%d", &a);
	if (a > 0 && a <= *total) 
	{
		for (int i = a - 1; i < *total - 1; i++) 
		{
			sporters[i] = sporters[i + 1];
		}
		printf("删除成功\n");
		(*total)--;
	}
	else 
	{
		printf("删除失败，该运动员不存在\n");
	}
	system("pause");

}
void Total_Sporters(int* total)//打印所有运动的信息
{
	Div_line();
	printf("所有报名运动员信息如下\n");
	printf("编号\t姓名\t\t性别\t学号\t\t报名项目编号\n");
	for (int j = 0; j < (*total); j++)
	{
		printf("%d\t%s\t\t%s\t%-15d\t%d\n", (j + 1), sporters[j].name,
			sporters[j].gender, sporters[j].stuID, sporters[j].proID);
	}
	system("pause");
}
void Score(int*total)
{	
	Div_line();
	printf("已进入成绩录入系统\n");
	int ID;
	int rank;
	printf("你要为目标运动员录入成绩的运动员编号为：");
	scanf("%d", &ID);
	if (ID > 0 && ID <= *total)
	{
		printf("\n该运动员在编号为%d的项目所得成绩为：", sporters[ID - 1].proID);
		scanf("%f", &sporters[ID - 1].score);
		printf("\n录入成功\n");
	}
	else
	{
		printf("目标运动员不存在\n");
	}

	for (int i = 0; i < *total; i++) 
	{
		int pro_num_sporters[26] = { 0 };  //记录每个项目的参赛人数
		int rank = 1;
		for (int j = 0; j < *total; j++) 
		{
			if (sporters[j].proID == sporters[i].proID) 
			{
				pro_num_sporters[sporters[j].proID]++;
				if (sporters[j].proID == 1 || sporters[j].proID == 2 || sporters[j].proID == 5 ||
					sporters[j].proID == 6 || sporters[j].proID == 9 || sporters[j].proID == 10 ||
					sporters[j].proID == 13 || sporters[j].proID == 14 || sporters[j].proID == 15 ||
					sporters[j].proID == 16 || sporters[j].proID == 19 || sporters[j].proID == 20 )
				{
					if (sporters[j].score < sporters[i].score)
					{
						rank++;
					}
					else;
				}
				else
				{
					if (sporters[j].score > sporters[i].score)
					{
						rank++;
					}
				}
			}
		}
		sporters[i].points = Points(pro_num_sporters[sporters[i].proID], rank);
	}
	system("pause");
}
int Points(int num_sporter ,int rank)
{
	if (num_sporter > 5)
	{
		switch (rank)
		{
		case 1:
			return 5;
		case 2:
			return 4;
		case 3:
			return 3;
		default :
			return 0;
		}
	}
	else
	{
		switch (rank)
		{
		case 1:
			return 3;
		case 2:
			return 2;
		case 3:
			return 1;
		default:
			return 0;
		}
	}
}
void Rank(int*total)
{
	Div_line();
	printf("所有报名运动员得分信息如下\n");
	printf("名次\t姓名\t\t得分\n");
	for (int i = 0; i < *total - 1; i++)
	{
		for (int j = 0; j < *total - 1 - i; j++)
		{
			if (sporters[j].points < sporters[j + 1].points)
			{
				struct information temp = sporters[j];
				sporters[j] = sporters[j + 1];
				sporters[j + 1] = temp;
			}
		}
	}
	for (int p = 0; p < *total; p++)
	{
		printf("第%d名\t%s\t\t%d\n", (p + 1), sporters[p].name, sporters[p].points);
	}
	system("pause");
}
void Format()//查看赛制
{
	Div_line();
	printf("项目所报人数不少于五人第一名得五分，第二名得四分，第三名得三分\n");
	printf("项目所报人数少于五人第一名得三分，第二名得二分，第三名得一分\n");
	system("pause");
}
void Div_line()//打印分割线
{
	printf("********************************");
	printf("********************************");
	printf("********************************\n");
}
