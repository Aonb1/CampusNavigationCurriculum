/*
   ����:У԰������ѯϵͳV1.0
   ���ʱ��:2022��5��22��16:37:25
   �Ŷӣ����Ŀ� ����� �Ű���
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<windows.h>
using namespace std;
#define Maxint 1000     //���㲻��ͨ�ĳ���
const int Max_n=1000;   //�������
class Meau
{
  public:
		int number;						 //ѡ��
		int index_temp_admin = 0;		 //�����˻��Ƿ���ȷ��־
		char Admin_temp[10];			 //�û�������˺�
		char Admin_insert_flie[10];		 //�����ļ����û���
		//���˵�
		void meau_main(void)
		{
            cout<<"�γ��������:У԰������ѯϵͳ  �汾V1.0"<<endl<<endl;
			printf("          ���봰��    \n");
			printf("     >>1.���������˻�\n");
			printf("     >>2.�������˻�\n");
			printf("     >>3.�˳�\n");
			//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
			cout<<"     PLEASE YOU CHIOCE:";
		}
		void input_Admin_insert_flie()
		{
			FILE *fp;
			char str[102] = {0};
			if ((fp = fopen("D:\\login_Management_admin.txt", "a+")) == NULL)
			{
				puts("Fail to open file!");
				exit(0);
			}
			//�˻�����Ҫ���ļ��д�������ȡ
			strcat(str, "\n");
			strcat(str, Admin_insert_flie);
			fputs(str, fp);
			fclose(fp);
			return;
		}
		void readfile_admin(void)
		{
			FILE *fp;
			char File_user_admin[100][10] = {0};
			int flag = 0;
			if ((fp = fopen("D:\\login_Management_admin.txt", "r")) == NULL)
			{
				cout << "\nδ�������˻�" << endl;
				cout << "�봴���˻�....." << endl;
				system("PAUSE");
				system("cls");
			}
			// fscanf(fp,"%d",n);  //���ļ��ж����˻�����
			for (int i = 0; i < 100; i++)
			{
				fscanf(fp, "%s", &File_user_admin[i]); //���ļ��ж��û�id
			}
			for (int i = 0; i < 100; i++)
			{
				if (strcmp(Admin_temp, File_user_admin[i]) == 0) //�û��˺�����ɹ�
				{
					index_temp_admin = 1;
					break;
				}
			}
			fclose(fp);
		}
		//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
		void choic_abc()
		{
			cin>>number;
				switch (number)
			{
			 case 1:
			{
				cout<<"Admin:";
				cin>>Admin_temp;
				readfile_admin();
				if(index_temp_admin==1) 
				{
					system("cls");
					cout<<"��ϲ�� ����ɹ���"<<endl;
				}
				break;
			}
			case 2:
			{
				 cout<<"�������˺ţ�";
				 cin>>Admin_insert_flie;
				 input_Admin_insert_flie();
				 cout<<"�����ɹ���"<<endl;
				 Sleep(2000);
				 system("cls");
				 meau_main();
				 cin>>number;
				 cout<<"Admin:";
				cin>>Admin_temp;
				readfile_admin();
				system("cls");
				if(index_temp_admin==1) 
				cout<<"��ϲ�� ����ɹ���"<<endl;
				break;
			}
			case 3:
			      {
					  cout<<">>���˳����봰��";
					  exit(0);
					  system("pause");
					  break;
				  }
			default:
				break;
			}
			
		}
};
typedef struct 
{
	char name[Max_n];       //��������
	char number[Max_n];     //�������
	char Introduce[Max_n];  //���ܼ��
}DataType;//���������Ϣ

typedef struct
{
	int num;          //���
	DataType data;   //�����Ϣ
}ScSpot;//����

typedef struct 
{
	ScSpot Scspot[13];//ʮ��������,0��λ�ò�ʹ��
	int D[13][13];    //�����ڽӾ���,�����ľ���
}UDG;                 //������Ͱ����˸�������Ĺ�ϵ,��������Ļ�����Ϣ

UDG G;              
int Path[12][12];
int D[12][12];
//ȫ�ֱ���

/*��ʼ��������Ϣ*/
void InitMes()
{
	//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
	int count=1;
	G.Scspot[count].num=1;
	strcpy(G.Scspot[count].data.number,"num.001");
	strcpy(G.Scspot[count].data.name,"������");
	strcpy(G.Scspot[count].data.Introduce,"ѧУ�Ĺؼ����֮һ");
	count++;
	G.Scspot[count].num=2;
	strcpy(G.Scspot[count].data.number,"num.002");
	strcpy(G.Scspot[count].data.name,"��������ABC��");
	strcpy(G.Scspot[count].data.Introduce,"˯��");
	count++;
	G.Scspot[count].num=3;
	strcpy(G.Scspot[count].data.number,"num.003");
	strcpy(G.Scspot[count].data.name,"��ѧ¥");
	strcpy(G.Scspot[count].data.Introduce,"ѧУĿǰ����Ҫ��ѧ¥");
	count++;
	G.Scspot[count].num=4;
	strcpy(G.Scspot[count].data.number,"num.004");
	strcpy(G.Scspot[count].data.name,"����¥");
	strcpy(G.Scspot[count].data.Introduce,"��һ�㻹��һ��СС��ͼ���");
	count++;
	G.Scspot[count].num=5;
	strcpy(G.Scspot[count].data.number,"num.005");
	strcpy(G.Scspot[count].data.name,"�˶���");
	strcpy(G.Scspot[count].data.Introduce,"PLAY!");
	count++;
	//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
	G.Scspot[count].num=6;
	strcpy(G.Scspot[count].data.number,"num.006");
	strcpy(G.Scspot[count].data.name,"Ů������");
	strcpy(G.Scspot[count].data.Introduce,"˯��");
	count++;
	G.Scspot[count].num=7;
	strcpy(G.Scspot[count].data.number,"num.007");
	strcpy(G.Scspot[count].data.name,"��");
	strcpy(G.Scspot[count].data.Introduce,"�˵ط羰����!");
	count++;
	G.Scspot[count].num=8;
	strcpy(G.Scspot[count].data.number,"num.008");
	strcpy(G.Scspot[count].data.name,"�ٳ�");
	strcpy(G.Scspot[count].data.Introduce,"������ͨ ���壡");
	count++;
	G.Scspot[count].num=9;
	strcpy(G.Scspot[count].data.number,"num.009");
	strcpy(G.Scspot[count].data.name,"ʳ��");
	strcpy(G.Scspot[count].data.Introduce,"�ɷ�");
	count++;
	G.Scspot[count].num=10;
	strcpy(G.Scspot[count].data.number,"num.010");
	strcpy(G.Scspot[count].data.name,"D����������");
	strcpy(G.Scspot[count].data.Introduce,"˯��");
	count++;
	G.Scspot[count].num=11;
	strcpy(G.Scspot[count].data.number,"num.011");
	strcpy(G.Scspot[count].data.name,"С����");
	strcpy(G.Scspot[count].data.Introduce,"ȡ��� �������ĵص�");
	count++;
	strcpy(G.Scspot[count].data.number,"num.012");
	strcpy(G.Scspot[count].data.name,"����");
	strcpy(G.Scspot[count].data.Introduce,"��������Ʒ��ʳ��");
	count++;
	for(int i=1;i<=12;i++)
    {
		for(int j=1;j<=12;j++)
        {
			if(i==j)
            {
				G.D[i][j]=0;
				D[i][j]=0;
			}
			else
            {
				G.D[i][j]=Maxint;
				D[i][j]=Maxint;
			}
		}
	}
    //·����ʼ����       -->������ ˫����
	G.D[1][2]=100;       G.D[2][1]=100;
	G.D[1][3]=80;        G.D[3][1]=80;
	G.D[1][5]=110;       G.D[5][1]=110;
	G.D[1][6]=160;       G.D[6][1]=160;
	G.D[8][11]=200;      G.D[11][8]=200;
	G.D[6][9]=100;       G.D[9][6]=100;
	G.D[6][8]=150;       G.D[8][6]=150;
	G.D[4][7]=30;        G.D[7][4]=30;
	G.D[3][7]=120;       G.D[7][3]=120;
	G.D[7][9]=60;        G.D[9][7]=60;
	G.D[9][10]=100;      G.D[9][10]=100;
	G.D[3][4]=50;        G.D[4][3]=50;
	G.D[9][12]=30;       G.D[12][9]=30;
	G.D[12][10]=60;      G.D[12][10]=60;
}
/*�޸ľ�����Ϣ*/
void ChangeSpeMes(int i)//���޸�ʱ������벻��ͻ����Ϣ
{
	printf("------------------------------\n");
	printf("1.�������\n");
	printf("2.��������\n");
	printf("3.������\n");
	printf("------------------------------\n");
	printf(">>��ѡ����Ҫ�޸ĵľ�����Ϣ:");
	int chose;
	scanf("%d",&chose);
	if(chose==1)
	{
		printf("��ֱ�������޸ĺ�ľ����ľ������:");
		scanf("%s",G.Scspot[i].data.number);
	}
	//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
	else if(chose==2)
	{
		printf("��ֱ�������޸ĺ�ľ����ľ�������:");
		scanf("%s",G.Scspot[i].data.name);
	}
	else if(chose==3)
	{
		printf("��ֱ�������޸ĺ�ľ����ľ�����:");
		scanf("%s",G.Scspot[i].data.Introduce);
	}
	else
	{
		printf("�������,��������ȷ��ѡ��.");
		ChangeSpeMes(i);
	}
	printf("�޸ĳɹ�,�޸ĺ�ľ�����ϢΪ:\n");
	printf("------------------------------\n");
	printf("�������:%s\n",G.Scspot[i].data.number);
	printf("��������:%s\n",G.Scspot[i].data.name);
	printf("������:%s\n",G.Scspot[i].data.Introduce);
	printf("------------------------------\n");
	system("pause");
	system("cls");
}
/*�޸ľ�����Ϣ*/
void  ChangeMes()
{
	printf(">>��������Ҫ�޸ĵľ���ı��:");
	int chose;
	scanf("%d",&chose);
	ChangeSpeMes(chose);
}
/*�鿴У԰ƽ��ͼ*/
void View()
{
	//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
    printf("                                                                                   ��\n");
    printf("                                                                                   |\n"); 
    printf("                                                                                   |\n"); 
    printf("                                                                                   |------>��\n");       
	printf("---------------------------�Ϸ�ʦ��ѧԺУ԰ƽ��ͼ-------------------------------\n");
	printf(" *********************************************************************************\n");
    printf(" **          10.D����������_                                                    **\n");
	printf(" **          |            |      <δ֪>ʩ����                                   **\n");
	printf(" **          |__12.����___|                                                     **\n");
	printf(" **          |            |                       3.��ѧ¥D��________           **\n");
    printf(" **          |____________|____________________________|            |           **\n");
	printf(" **          |            |    |                       |_______3.��ѧ¥C��      **\n");
	printf(" **          |___9.ʳ��___|    |                       |           |            **\n");
	printf(" **          |            |    |_____________________3.��ѧ¥B��   |            **\n");
	printf(" ** 8.�ٳ�___|____________|________|  7.��      |       |          |            **\n");
	printf(" **          |            |        |____________|       |          |<δ֪>ʩ����**\n");
	printf(" **          |            |           |         |__3.��ѧ¥A��_____|            **\n");
	printf(" **          |            |           |            |                            **\n");
	printf(" **          |            |      4.����¥          |                            **\n");
	printf(" **          |    6.Ů������_______________________|___________2.(ABC)����������**\n");
	printf(" **          |                 |       |           |                            **\n");
	printf(" **          |                5.�˶�������         |                            **\n");
	printf(" **          |                                     |                            **\n");
	printf(" **       11.С����                           1.������                          **\n");
	printf(" *********************************************************************************\n");
	printf(">>Enter�������������������ѡ��\n");
	system("pause");
	system("cls");
}
/*�鿴������Ϣ*/
void ViewSpeMes(int i)
{

	printf("���Ϊ%d�ľ������ϢΪ:\n",i);
	printf("---------------------------------------------\n");
	printf("�������:%s\n",G.Scspot[i].data.number);
	printf("��������:%s\n",G.Scspot[i].data.name);
	printf("������:%s\n",G.Scspot[i].data.Introduce);
	printf("---------------------------------------------\n");
}
/*��ѯ������Ϣ*/
void ViewMes()
{           
	printf("                                                                                   ��\n");
    printf("                                                                                   |\n"); 
    printf("                                                                                   |\n"); 
    printf("                                                                                   |------>��\n");       
	printf("---------------------------�Ϸ�ʦ��ѧԺУ԰ƽ��ͼ-------------------------------\n");
	printf(" *********************************************************************************\n");
    printf(" **          10.D����������_                                                    **\n");
	printf(" **          |            |      <δ֪>ʩ����                                   **\n");
	printf(" **          |__12.����___|                                                     **\n");
	printf(" **          |            |                       3.��ѧ¥D��________           **\n");
    printf(" **          |____________|____________________________|            |           **\n");
	printf(" **          |            |    |                       |_______3.��ѧ¥C��      **\n");
	printf(" **          |___9.ʳ��___|    |                       |           |            **\n");
	printf(" **          |            |    |_____________________3.��ѧ¥B��   |            **\n");
	printf(" ** 8.�ٳ�___|____________|________|  7.��      |       |          |            **\n");
	printf(" **          |            |        |____________|       |          |<δ֪>ʩ����**\n");
	printf(" **          |            |           |         |__3.��ѧ¥A��_____|            **\n");
	printf(" **          |            |           |            |                            **\n");
	printf(" **          |            |      4.����¥          |                            **\n");
	printf(" **          |    6.Ů������_______________________|___________2.(ABC)����������**\n");
	printf(" **          |                 |       |           |                            **\n");
	printf(" **          |                5.�˶�������         |                            **\n");
	printf(" **          |                                     |                            **\n");
	printf(" **       11.С����                           1.������                          **\n");
	printf(" *********************************************************************************\n");                   
	//��֤����Ϸ�
	printf("��������Ҫ�鿴�ľ�����Ϣ�ı��:");
	int chose;
	scanf("%d",&chose);
	ViewSpeMes(chose);
	printf("��ѯ���!�Ƿ������ѯ?(Y/N)");
	char b;
	scanf(" %c",&b);
	//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
	if(b=='Y')
	{
		printf("��ѡ���˼�����ѯ!\n");
		ViewMes();
	}
	printf(">>��ѯ����,Enter������������\n");
	system("pause");
	system("cls");
}
/*�����������֮�����̾���*/
void ShortestPath_Floyd()
{
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=12;j++)
		{
			D[i][j]=G.D[i][j];
			if(D[i][j]<Maxint&&i!=j)  Path[i][j]=j;  //��������·,�����Ϊj
			else Path[i][j]=-1;
		}
	}
	for(int k=1;k<=12;k++)
	{
		for(int i=1;i<=12;i++)
		{
			for(int j=1;j<=12;j++)
			{
				if(D[i][k]+D[k][j]<D[i][j])     //���ڸ��̵�·��
				{   
					D[i][j]=D[i][k]+D[k][j];    //����ֵ
					Path[i][j]=Path[i][k];      //����i�ĺ��Ϊk
				}
			}
		}
		//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
	}
}

/*��ӡ·���ĺ���*/
void OutPath(int s,int e)
{
	int next=s;
	printf(">>·��Ϊ:\n");
	while(next!=e)
    {
		printf("%s-->",G.Scspot[next].data.name);
		next=Path[next][e];//��ǰ�ĺ�̵�ı��
	}
	printf("%s\n",G.Scspot[e].data.name);
}
/*��ӡ���·������̾���*/
void PrintPath()
{
	ShortestPath_Floyd();//Ԥ�������е����·��
	printf("                                                                                   ��\n");
    printf("                                                                                   |\n"); 
    printf("                                                                                   |\n"); 
    printf("                                                                                   |------>��\n");       
	printf("-------------------------------�Ϸ�ʦ��ѧԺУ԰ƽ��ͼ-------------------------------\n");
	printf(" *********************************************************************************\n");
    printf(" **          10.D����������_                                                    **\n");
	printf(" **          |            |      <δ֪>ʩ����                                   **\n");
	printf(" **          |__12.����___|                                                     **\n");
	printf(" **          |            |                       3.��ѧ¥D��________           **\n");
    printf(" **          |____________|____________________________|            |           **\n");
	printf(" **          |            |    |                       |_______3.��ѧ¥C��      **\n");
	printf(" **          |___9.ʳ��___|    |                       |           |            **\n");
	printf(" **          |            |    |_____________________3.��ѧ¥B��   |            **\n");
	printf(" ** 8.�ٳ�___|____________|________|  7.��      |       |          |            **\n");
	printf(" **          |            |        |____________|       |          |<δ֪>ʩ����**\n");
	printf(" **          |            |           |         |__3.��ѧ¥A��_____|            **\n");
	printf(" **          |            |           |            |                            **\n");
	printf(" **          |            |      4.����¥          |                            **\n");
	printf(" **          |    6.Ů������_______________________|___________2.(ABC)����������**\n");
	printf(" **          |                 |       |           |                            **\n");
	printf(" **          |                5.�˶�������         |                            **\n");
	printf(" **          |                                     |                            **\n");
	printf(" **       11.С����                           1.������                          **\n");
	printf(" *********************************************************************************\n");
	printf("����У԰ƽ��ͼ,��������ǰ���ھ��㼰��Ҫȥ�ľ���ı��:");
	int s,e;
	scanf("%d%d",&s,&e);
	if(s<=12&&s>=0&&e<=12&&e>=0){
		printf(">>%s��%s�����·������Ϊ: %dm\n",G.Scspot[s].data.name,G.Scspot[e].data.name,D[s][e]);
		OutPath(s,e);
		printf(">>��Enter������������");
		system("pause");
		system("cls");
	}else{
		printf("����������,������������ȷ�ľ�����!\n");
		printf("��Enter����������");
		system("pause");
		system("cls");
		PrintPath();
	}

}
void Menu()
{
	printf("------------��ӭ�����ʦУ԰����ϵͳV1.0------------\n");
	printf("\n----------------------------------------------------\n");
	printf("1.�鿴У԰ƽ��ͼ\n");
	printf("2.�޸ľ�����Ϣ\n");
	printf("3.�鿴���������Ϣ\n");
	printf("4.���·����ѯ\n");
	printf("5.�˳�\n");
	printf("----------------------------------------------------\n");
	printf(">>��������Ҫѡ��Ĺ���:");
	int chose;
	scanf("%d",&chose);
	switch(chose)
	{
		case 1: 
		{
			View();
			Menu();
		}
		//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
		case 2: 
		{
			ChangeMes();
			Menu();
		}
		case 3: 
		{
			ViewMes();
			Menu();
		}
		case 4: 
		{
			PrintPath();
			Menu();
		}
		case 5:
		 {
			exit(0);
			//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
		}
		default : 
		{
			printf("����ѡ������,������ѡ��!");
			Menu();
		}
	}
}

int main()
{
	Meau A;
	A.meau_main();
	A.choic_abc();
	if(A.index_temp_admin==1)
	{
	int abc;
	printf(">>��ѡ�����µ�ͼ��ʼ��(Ŀǰ���кϷ�ʦ��ѧԺ�ļ�Լ����ͼ��������ϵͳ����)\n");
	printf("1.�Ϸ�ʦ��ѧԺУ԰����ͼ\n");
	printf("2.�����ڴ�����������\n");
	printf("3.�����ڴ�����������\n");
	printf("PLease you chioce:");
    scanf("%d",&abc);
	if(abc==1)
	{
     	InitMes();
	    printf("��ʼ����");
		for(int i=1;i<=5;i++)
		{
            printf(".");
			Sleep(500);
		}
		printf("\n");
	    printf("������Ϣ��ʼ���ɹ�,����������\n");
		Sleep(2000);
		system("cls");
	    Menu();
	}
	else
	{
		printf("��ʼ����");
		for(int i=1;i<=5;i++)
		{
            printf(".");
			Sleep(600);
		}
		//�Ŷӣ����Ŀ� ����� �Ű���
			//��Ҫ�����ˣ����Ŀ�
			//Qq:1025181600
		printf("\n");
		printf("������Ϣ��ʼ��ʧ��\n");
		Sleep(2000);
		system("cls");
	    printf(">>������ѡ�����µ�ͼ��ʼ��(Ŀǰ���кϷ�ʦ��ѧԺ�ļ�Լ����ͼ��������ϵͳ����)\n");
	    printf("1.�Ϸ�ʦ��ѧԺУ԰����ͼ\n");
	    printf("2.�����ڴ�����������\n");
	    printf("3.�����ڴ�����������\n");
	    printf("PLease you chioce:");
	    scanf("%d",&abc);
	   if(abc==1)
	 {
     	 InitMes();
		printf("��ʼ����");
		for(int i=1;i<=5;i++)
		{
            printf(".");
			Sleep(500);
		}
		 printf("\n");
     	 printf("������Ϣ��ʼ���ɹ�,����������\n");
		 Sleep(2000);
		 system("cls");
	     Menu();
	}
}
	}
	else
	{
		cout<<endl<<"��Ǹ ����ʧ�ܣ�"<<endl;
		cout<<"ԭ���˺Ų����ڻ��˺��������"<<endl;
		system("pause");
	}
	return 0;
}



