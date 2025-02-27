#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Sporters 224
static struct information
{
	char name[10];//����
	char gender[10];//�Ա�
	int stuID;//ѧ��
	int proID;//��Ŀ���
	double score;//�ɼ�
	int points;//�÷�
}sporters[Max_Sporters];

void Handle();//ҵ�����
void Schedule();//���̰���
void Project_male();//��Ŀ��ţ��У�
void Project_female();//��Ŀ��ţ�Ů��
void Application(char* pname_temp, char* pgender_temp, int* pstuID_temp,
	int* pproID_temp, int* total);//¼�뱨����Ϣ
void Revise(int* total);//�޸ı�����Ϣ
void Delete(int* total);//ɾ��������Ϣ
void Total_Sporters(int* total);//��ӡ�����˶�Ա����Ϣ
void Score(int*total);//¼��ɼ�
int Points(int num_sporter ,int rank);//����÷�
void Rank(int* total);//�鿴�÷֣�����
void Format();//�鿴����
void Div_line();//��ӡ�ָ���

int main()
{   
	printf("��ӭʹ��У԰�˶������ϵͳ\n");
	char ch = '0';
	int i = 0;
	int* total = &i;
	Handle();//��ʾҵ����
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
				printf("���������������޷���������\n");
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
			printf("��Ч������\n");
			system("pause");
			break;
		}
		Handle();//��ʾҵ����
		while (getchar() != '\n');//���������еĻ��з������������ַ�
	}

	printf("\n��лʹ�ø��˶�Ա����ϵͳ\n");
	return 0;
}

void Handle()//ҵ�����
{
	Div_line();
	printf("��ѡ����Ҫ�����ҵ��\n");
	printf("0.�˳�ϵͳ\n1.�鿴����\n2.�鿴��Ŀ���\n3.������Ŀ��Ϣ¼��\n4.�޸ı�����Ŀ��Ϣ\n");
	printf("5.ɾ��������Ŀ��Ϣ\n6.��ѯ�˶�Ա������Ŀ��Ϣ\n7.¼��ɼ�\n8.�����÷ֲ�ѯ\n9.�鿴����\n");
	printf("��������Ҫ�����ҵ���ţ�");
}
void Schedule()//���̰���
{
	Div_line();
	printf("�˶������̰��ű�");
	Div_line();
	printf("ʱ��\t\t�ص�\t\t��Ŀ\v");
	printf("12��4��\n");
	printf("07:30-08:00\t�ﾶ��\t\t��Ļʽ\v");
	printf("08:30-10:00\t�ܵ�\t\t50m��(��)\v");
	printf("08:30-10:00\t�ܵ�\t\t50m��(Ů)\v");
	printf("08:30-10:00\t�ﳡ\t\t��������(��)\v");
	printf("08:30-10:00\t�ﳡ\t\t��������(Ů)\v");
	printf("10:30-12:00\t�ܵ�\t\t100m��(��)\v");
	printf("10:30-12:00\t�ܵ�\t\t100m��(Ů)\v");
	printf("10:30-12:00\t�ﳡ\t\t����(��)\v");
	printf("10:30-12:00\t�ﳡ\t\t����(Ů)\v");
	printf("14:30-16:00\t�ܵ�\t\t200m��(��)\v");
	printf("14:30-16:00\t�ܵ�\t\t200m��(Ů)\v");
	printf("14:30-16:00\t�ﳡ\t\t������Զ(��)\v");
	printf("14:30-16:00\t�ﳡ\t\t������Զ(Ů)\v");
	printf("16:00-17:30\t�ܵ�\t\t1000m��(��)\v");
	printf("16:00-17:30\t�ܵ�\t\t800m��(Ů)\v");
	printf("16:00-17:30\t�ܵ�\t\t4*100m������(��)\v");
	printf("16:00-17:30\t�ܵ�\t\t4*100m������(Ů)\v");
	printf("12��5��\n");
	printf("08:30-10:00\t�ܵ�\t\t5000m��(��)\v");
	printf("08:30-10:00\t�ܵ�\t\t5000m��(Ů)\v");
	printf("08:30-10:00\t�ﳡ\t\tǦ��(��)\v");
	printf("08:30-10:00\t�ﳡ\t\tǦ��(Ů)\v");
	printf("10:30-12:00\t�ܵ�\t\t110m����(��)\v");
	printf("10:30-12:00\t�ܵ�\t\t100m����(Ů)\v");
	printf("10:30-12:00\t�ﳡ\t\t��Զ(��)\v");
	printf("10:30-12:00\t�ﳡ\t\t��Զ(Ů)\v");
	printf("14:30-16:00\t�ﳡ\t\t�Ÿ���(��)\v");
	printf("14:30-16:00\t�ﳡ\t\t�Ÿ���(Ů)\v");
	printf("14:30-16:00\t�ﳡ\t\t��ǹ(��)\v");
	printf("14:30-16:00\t�ﳡ\t\t��ǹ(Ů)\v");
	printf("16:30-17:00\t�ﾶ��\t\t��Ļʽ\v");
	printf("********************************");
	printf("********************************");
	printf("********************************\n");
	system("pause");
}
void Project_male()
{
	printf("���\tʱ��\t\t�ص�\t\t��Ŀ\v");
	printf("\t12��4��\n");
	printf("\t07:30-08:00\t�ﾶ��\t\t��Ļʽ\v");
	printf("1\t08:30-10:00\t�ܵ�\t\t50m��(��)\v");
	printf("3\t08:30-10:00\t�ﳡ\t\t��������(��)\v");
	printf("5\t10:30-12:00\t�ܵ�\t\t100m��(��)\v");
	printf("7\t10:30-12:00\t�ﳡ\t\t����(��)\v");
	printf("9\t14:30-16:00\t�ܵ�\t\t200m��(��)\v");
	printf("11\t14:30-16:00\t�ﳡ\t\t������Զ(��)\v");
	printf("13\t16:00-17:30\t�ܵ�\t\t1000m��(��)\v");
	printf("\t12��5��\n");
	printf("15\t08:30-10:00\t�ܵ�\t\t5000m��(��)\v");
	printf("17\t08:30-10:00\t�ﳡ\t\tǦ��(��)\v");
	printf("19\t10:30-12:00\t�ܵ�\t\t110m����(��)\v");
	printf("21\t10:30-12:00\t�ﳡ\t\t��Զ(��)\v");
	printf("23\t14:30-16:00\t�ﳡ\t\t�Ÿ���(��)\v");
	printf("25\t14:30-16:00\t�ﳡ\t\t��ǹ(��)\v");
	printf("\t16:30-17:00\t�ﾶ��\t\t��Ļʽ\v");
	printf("\n");
}
void Project_female()
{
	printf("���\tʱ��\t\t�ص�\t\t��Ŀ\v");
	printf("\t12��4��\n");
	printf("2\t08:30-10:00\t�ܵ�\t\t50m��(Ů)\v");
	printf("4\t08:30-10:00\t�ﳡ\t\t��������(Ů)\v");
	printf("6\t10:30-12:00\t�ܵ�\t\t100m��(Ů)\v");
	printf("8\t10:30-12:00\t�ﳡ\t\t����(Ů)\v");
	printf("10\t14:30-16:00\t�ܵ�\t\t200m��(Ů)\v");
	printf("12\t14:30-16:00\t�ﳡ\t\t������Զ(Ů)\v");
	printf("14\t16:00-17:30\t�ܵ�\t\t800m��(Ů)\v");
	printf("\t12��5��\n");
	printf("16\t08:30-10:00\t�ܵ�\t\t5000m��(Ů)\v");
	printf("18\t08:30-10:00\t�ﳡ\t\tǦ��(Ů)\v");
	printf("20\t10:30-12:00\t�ܵ�\t\t100m����(Ů)\v");
	printf("22\t10:30-12:00\t�ﳡ\t\t��Զ(Ů)\v");
	printf("24\t14:30-16:00\t�ﳡ\t\t�Ÿ���(Ů)\v");
	printf("26\t14:30-16:00\t�ﳡ\t\t��ǹ(Ů)\v");
	system("pause");
	printf("\n");
}
void Application(char* pname_temp, char* pgender_temp, int* pstuID_temp,
	int* pproID_temp, int* total)//������Ϣ¼��
{
	Div_line();
	int con;
	printf("�ѽ��뱨����Ϣ¼��ϵͳ\n");
	printf("��ȷ�����Ƿ�֪����Ҫ��������Ŀ���\n");
	printf("���������0������������������0�򷵻�\n�����룺");
	scanf("%d", &con);
	if (con == 0)
		return;
	printf("�����������˶�Ա������\n");
	scanf("%19s", pname_temp);
	printf("�������˶�Ա���Ա�\n");
	scanf("%9s", pgender_temp);
	printf("�������˶�Ա��ѧ��\n");
	scanf("%d", pstuID_temp);
	printf("�������˶�Ա������Ŀ�ı��\n");
	scanf("%d", pproID_temp);
	if ((*pproID_temp) >= 1 && (*pproID_temp) <= 26)
	{
		printf("�����ɹ�����������ҵ�����\n");
		(*total)++;
		printf("���˶�Ա���Ϊ%d\n", *total);
		sporters[*total].score = 0;
	}
	else
	{
		printf("����ʧ�ܣ���������ҵ�����\n");
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
	printf("�ѽ��뱨����Ϣ�޸�ϵͳ\n");
	printf("��ȷ�����Ƿ�֪��Ŀ���˶�Ա�ı��\n");
	printf("���������0�����޸ļ���������0�򷵻�\n�����룺");
	scanf("%d", &con);
	if (con == 0)
		return;
	printf("��������Ҫ�޸ı�����Ϣ���˶�Ա��ţ�");
	scanf("%d", &a);
	if (a > 0 && a <= *total)
	{	
		printf("��Ҫ�޸ĸ��˶�Ա��\n1.����2.�Ա�3.ѧ��4.��Ŀ���\n");
		while (getchar() != '\n');
		scanf("%c", &k);
		switch (k)
		{
		case '1':
			printf("�޸�Ϊ��");
			scanf("%s", r);
			strcpy(sporters[a - 1].name, r);
			printf("�޸ĳɹ�\n");
			break;
		case '2':
			printf("�޸�Ϊ��");
			scanf("%s", r);
			strcpy(sporters[a - 1].gender, r);
			printf("�޸ĳɹ�\n");
			break;
		case '3':
			printf("�޸�Ϊ��");
			scanf("%d", &s);
			sporters[a - 1].stuID = s;
			printf("�޸ĳɹ�\n");
			break;
		case '4':
			printf("�޸�Ϊ��");
			scanf("%d", &s);
			sporters[a - 1].proID = s;
			printf("�޸ĳɹ�\n");
			break;
		default:
			printf("��Ч������\n");
			system("pause");
			break;
		}
	}
	else 
	{
		printf("Ŀ���˶�Ա�����ڣ���������������\n");
	}
}
void Delete(int* total)
{
	Div_line();
	int con, a;
	printf("�ѽ��뱨����Ϣɾ��ϵͳ\n");
	printf("��ȷ�����Ƿ�֪��Ҫɾ��������Ϣ���˶�Ա���\n");
	printf("���������0�����������У�����0�򷵻�\n�����룺");
	scanf("%d", &con);
	if (con == 0)
		return;
	printf("��������Ҫɾ��������Ϣ���˶�Ա��ţ�");
	scanf("%d", &a);
	if (a > 0 && a <= *total) 
	{
		for (int i = a - 1; i < *total - 1; i++) 
		{
			sporters[i] = sporters[i + 1];
		}
		printf("ɾ���ɹ�\n");
		(*total)--;
	}
	else 
	{
		printf("ɾ��ʧ�ܣ����˶�Ա������\n");
	}
	system("pause");

}
void Total_Sporters(int* total)//��ӡ�����˶�����Ϣ
{
	Div_line();
	printf("���б����˶�Ա��Ϣ����\n");
	printf("���\t����\t\t�Ա�\tѧ��\t\t������Ŀ���\n");
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
	printf("�ѽ���ɼ�¼��ϵͳ\n");
	int ID;
	int rank;
	printf("��ҪΪĿ���˶�Ա¼��ɼ����˶�Ա���Ϊ��");
	scanf("%d", &ID);
	if (ID > 0 && ID <= *total)
	{
		printf("\n���˶�Ա�ڱ��Ϊ%d����Ŀ���óɼ�Ϊ��", sporters[ID - 1].proID);
		scanf("%f", &sporters[ID - 1].score);
		printf("\n¼��ɹ�\n");
	}
	else
	{
		printf("Ŀ���˶�Ա������\n");
	}

	for (int i = 0; i < *total; i++) 
	{
		int pro_num_sporters[26] = { 0 };  //��¼ÿ����Ŀ�Ĳ�������
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
	printf("���б����˶�Ա�÷���Ϣ����\n");
	printf("����\t����\t\t�÷�\n");
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
		printf("��%d��\t%s\t\t%d\n", (p + 1), sporters[p].name, sporters[p].points);
	}
	system("pause");
}
void Format()//�鿴����
{
	Div_line();
	printf("��Ŀ�����������������˵�һ������֣��ڶ������ķ֣�������������\n");
	printf("��Ŀ���������������˵�һ�������֣��ڶ����ö��֣���������һ��\n");
	system("pause");
}
void Div_line()//��ӡ�ָ���
{
	printf("********************************");
	printf("********************************");
	printf("********************************\n");
}
