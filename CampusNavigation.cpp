/*
   课设:校园导游咨询系统V1.0
   完成时间:2022年5月22日16:37:25
   团队：敖文康 孙佳乐 张安齐
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<windows.h>
using namespace std;
#define Maxint 1000     //两点不连通的常量
const int Max_n=1000;   //最大数量
class Meau
{
  public:
		int number;						 //选择
		int index_temp_admin = 0;		 //登入账户是否正确标志
		char Admin_temp[10];			 //用户输入的账号
		char Admin_insert_flie[10];		 //插入文件的用户名
		//主菜单
		void meau_main(void)
		{
            cout<<"课程设计主题:校园导游咨询系统  版本V1.0"<<endl<<endl;
			printf("          登入窗口    \n");
			printf("     >>1.登入已有账户\n");
			printf("     >>2.创建新账户\n");
			printf("     >>3.退出\n");
			//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
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
			//账户数量要从文件中创建并读取
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
				cout << "\n未创建新账户" << endl;
				cout << "请创建账户....." << endl;
				system("PAUSE");
				system("cls");
			}
			// fscanf(fp,"%d",n);  //从文件中读入账户数量
			for (int i = 0; i < 100; i++)
			{
				fscanf(fp, "%s", &File_user_admin[i]); //从文件中读用户id
			}
			for (int i = 0; i < 100; i++)
			{
				if (strcmp(Admin_temp, File_user_admin[i]) == 0) //用户账号输入成功
				{
					index_temp_admin = 1;
					break;
				}
			}
			fclose(fp);
		}
		//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
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
					cout<<"恭喜你 登入成功！"<<endl;
				}
				break;
			}
			case 2:
			{
				 cout<<"请输入账号：";
				 cin>>Admin_insert_flie;
				 input_Admin_insert_flie();
				 cout<<"创建成功！"<<endl;
				 Sleep(2000);
				 system("cls");
				 meau_main();
				 cin>>number;
				 cout<<"Admin:";
				cin>>Admin_temp;
				readfile_admin();
				system("cls");
				if(index_temp_admin==1) 
				cout<<"恭喜你 登入成功！"<<endl;
				break;
			}
			case 3:
			      {
					  cout<<">>已退出登入窗口";
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
	char name[Max_n];       //景点名称
	char number[Max_n];     //景点代号
	char Introduce[Max_n];  //介绍简称
}DataType;//景点相关信息

typedef struct
{
	int num;          //编号
	DataType data;   //相关信息
}ScSpot;//景点

typedef struct 
{
	ScSpot Scspot[13];//十二个景点,0号位置不使用
	int D[13][13];    //构建邻接矩阵,景点间的距离
}UDG;                 //这个类型包含了各个景点的关系,各个景点的基本信息

UDG G;              
int Path[12][12];
int D[12][12];
//全局变量

/*初始化景点信息*/
void InitMes()
{
	//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
	int count=1;
	G.Scspot[count].num=1;
	strcpy(G.Scspot[count].data.number,"num.001");
	strcpy(G.Scspot[count].data.name,"东大门");
	strcpy(G.Scspot[count].data.Introduce,"学校的关键入口之一");
	count++;
	G.Scspot[count].num=2;
	strcpy(G.Scspot[count].data.number,"num.002");
	strcpy(G.Scspot[count].data.name,"男生宿舍ABC栋");
	strcpy(G.Scspot[count].data.Introduce,"睡觉");
	count++;
	G.Scspot[count].num=3;
	strcpy(G.Scspot[count].data.number,"num.003");
	strcpy(G.Scspot[count].data.name,"博学楼");
	strcpy(G.Scspot[count].data.Introduce,"学校目前的主要教学楼");
	count++;
	G.Scspot[count].num=4;
	strcpy(G.Scspot[count].data.number,"num.004");
	strcpy(G.Scspot[count].data.name,"铭传楼");
	strcpy(G.Scspot[count].data.Introduce,"第一层还有一个小小的图书馆");
	count++;
	G.Scspot[count].num=5;
	strcpy(G.Scspot[count].data.number,"num.005");
	strcpy(G.Scspot[count].data.name,"运动区");
	strcpy(G.Scspot[count].data.Introduce,"PLAY!");
	count++;
	//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
	G.Scspot[count].num=6;
	strcpy(G.Scspot[count].data.number,"num.006");
	strcpy(G.Scspot[count].data.name,"女生宿舍");
	strcpy(G.Scspot[count].data.Introduce,"睡觉");
	count++;
	G.Scspot[count].num=7;
	strcpy(G.Scspot[count].data.number,"num.007");
	strcpy(G.Scspot[count].data.name,"湖");
	strcpy(G.Scspot[count].data.Introduce,"此地风景美好!");
	count++;
	G.Scspot[count].num=8;
	strcpy(G.Scspot[count].data.number,"num.008");
	strcpy(G.Scspot[count].data.name,"操场");
	strcpy(G.Scspot[count].data.Introduce,"跑艺体通 冲冲冲！");
	count++;
	G.Scspot[count].num=9;
	strcpy(G.Scspot[count].data.number,"num.009");
	strcpy(G.Scspot[count].data.name,"食堂");
	strcpy(G.Scspot[count].data.Introduce,"干饭");
	count++;
	G.Scspot[count].num=10;
	strcpy(G.Scspot[count].data.number,"num.010");
	strcpy(G.Scspot[count].data.name,"D栋男生宿舍");
	strcpy(G.Scspot[count].data.Introduce,"睡觉");
	count++;
	G.Scspot[count].num=11;
	strcpy(G.Scspot[count].data.number,"num.011");
	strcpy(G.Scspot[count].data.name,"小东门");
	strcpy(G.Scspot[count].data.Introduce,"取快递 拿外卖的地点");
	count++;
	strcpy(G.Scspot[count].data.number,"num.012");
	strcpy(G.Scspot[count].data.name,"超市");
	strcpy(G.Scspot[count].data.Introduce,"买生活用品和食物");
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
    //路径初始化区       -->由题意 双向区
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
/*修改景点信息*/
void ChangeSpeMes(int i)//在修改时务必输入不冲突的信息
{
	printf("------------------------------\n");
	printf("1.景点代号\n");
	printf("2.景点名称\n");
	printf("3.景点简介\n");
	printf("------------------------------\n");
	printf(">>请选择您要修改的景点信息:");
	int chose;
	scanf("%d",&chose);
	if(chose==1)
	{
		printf("请直接输入修改后的景点后的景点代号:");
		scanf("%s",G.Scspot[i].data.number);
	}
	//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
	else if(chose==2)
	{
		printf("请直接输入修改后的景点后的景点名称:");
		scanf("%s",G.Scspot[i].data.name);
	}
	else if(chose==3)
	{
		printf("请直接输入修改后的景点后的景点简介:");
		scanf("%s",G.Scspot[i].data.Introduce);
	}
	else
	{
		printf("输入错误,请输入正确的选择.");
		ChangeSpeMes(i);
	}
	printf("修改成功,修改后的景点信息为:\n");
	printf("------------------------------\n");
	printf("景点代号:%s\n",G.Scspot[i].data.number);
	printf("景点名称:%s\n",G.Scspot[i].data.name);
	printf("景点简介:%s\n",G.Scspot[i].data.Introduce);
	printf("------------------------------\n");
	system("pause");
	system("cls");
}
/*修改景点信息*/
void  ChangeMes()
{
	printf(">>请输入您要修改的景点的编号:");
	int chose;
	scanf("%d",&chose);
	ChangeSpeMes(chose);
}
/*查看校园平面图*/
void View()
{
	//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
    printf("                                                                                   北\n");
    printf("                                                                                   |\n"); 
    printf("                                                                                   |\n"); 
    printf("                                                                                   |------>东\n");       
	printf("---------------------------合肥师范学院校园平面图-------------------------------\n");
	printf(" *********************************************************************************\n");
    printf(" **          10.D栋男生宿舍_                                                    **\n");
	printf(" **          |            |      <未知>施工区                                   **\n");
	printf(" **          |__12.超市___|                                                     **\n");
	printf(" **          |            |                       3.博学楼D区________           **\n");
    printf(" **          |____________|____________________________|            |           **\n");
	printf(" **          |            |    |                       |_______3.博学楼C区      **\n");
	printf(" **          |___9.食堂___|    |                       |           |            **\n");
	printf(" **          |            |    |_____________________3.博学楼B区   |            **\n");
	printf(" ** 8.操场___|____________|________|  7.湖      |       |          |            **\n");
	printf(" **          |            |        |____________|       |          |<未知>施工区**\n");
	printf(" **          |            |           |         |__3.博学楼A区_____|            **\n");
	printf(" **          |            |           |            |                            **\n");
	printf(" **          |            |      4.铭传楼          |                            **\n");
	printf(" **          |    6.女生宿舍_______________________|___________2.(ABC)栋男生宿舍**\n");
	printf(" **          |                 |       |           |                            **\n");
	printf(" **          |                5.运动体育区         |                            **\n");
	printf(" **          |                                     |                            **\n");
	printf(" **       11.小东门                           1.东大门                          **\n");
	printf(" *********************************************************************************\n");
	printf(">>Enter键返回主界面继续进行选择\n");
	system("pause");
	system("cls");
}
/*查看景点信息*/
void ViewSpeMes(int i)
{

	printf("编号为%d的景点的信息为:\n",i);
	printf("---------------------------------------------\n");
	printf("景点代号:%s\n",G.Scspot[i].data.number);
	printf("景点名称:%s\n",G.Scspot[i].data.name);
	printf("景点简介:%s\n",G.Scspot[i].data.Introduce);
	printf("---------------------------------------------\n");
}
/*查询景点信息*/
void ViewMes()
{           
	printf("                                                                                   北\n");
    printf("                                                                                   |\n"); 
    printf("                                                                                   |\n"); 
    printf("                                                                                   |------>东\n");       
	printf("---------------------------合肥师范学院校园平面图-------------------------------\n");
	printf(" *********************************************************************************\n");
    printf(" **          10.D栋男生宿舍_                                                    **\n");
	printf(" **          |            |      <未知>施工区                                   **\n");
	printf(" **          |__12.超市___|                                                     **\n");
	printf(" **          |            |                       3.博学楼D区________           **\n");
    printf(" **          |____________|____________________________|            |           **\n");
	printf(" **          |            |    |                       |_______3.博学楼C区      **\n");
	printf(" **          |___9.食堂___|    |                       |           |            **\n");
	printf(" **          |            |    |_____________________3.博学楼B区   |            **\n");
	printf(" ** 8.操场___|____________|________|  7.湖      |       |          |            **\n");
	printf(" **          |            |        |____________|       |          |<未知>施工区**\n");
	printf(" **          |            |           |         |__3.博学楼A区_____|            **\n");
	printf(" **          |            |           |            |                            **\n");
	printf(" **          |            |      4.铭传楼          |                            **\n");
	printf(" **          |    6.女生宿舍_______________________|___________2.(ABC)栋男生宿舍**\n");
	printf(" **          |                 |       |           |                            **\n");
	printf(" **          |                5.运动体育区         |                            **\n");
	printf(" **          |                                     |                            **\n");
	printf(" **       11.小东门                           1.东大门                          **\n");
	printf(" *********************************************************************************\n");                   
	//保证输入合法
	printf("请输入您要查看的景点信息的编号:");
	int chose;
	scanf("%d",&chose);
	ViewSpeMes(chose);
	printf("查询完毕!是否继续查询?(Y/N)");
	char b;
	scanf(" %c",&b);
	//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
	if(b=='Y')
	{
		printf("您选择了继续查询!\n");
		ViewMes();
	}
	printf(">>查询结束,Enter键进入主界面\n");
	system("pause");
	system("cls");
}
/*求出任意两点之间的最短距离*/
void ShortestPath_Floyd()
{
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=12;j++)
		{
			D[i][j]=G.D[i][j];
			if(D[i][j]<Maxint&&i!=j)  Path[i][j]=j;  //两顶点有路,后继置为j
			else Path[i][j]=-1;
		}
	}
	for(int k=1;k<=12;k++)
	{
		for(int i=1;i<=12;i++)
		{
			for(int j=1;j<=12;j++)
			{
				if(D[i][k]+D[k][j]<D[i][j])     //存在更短的路径
				{   
					D[i][j]=D[i][k]+D[k][j];    //更新值
					Path[i][j]=Path[i][k];      //更改i的后继为k
				}
			}
		}
		//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
	}
}

/*打印路径的函数*/
void OutPath(int s,int e)
{
	int next=s;
	printf(">>路径为:\n");
	while(next!=e)
    {
		printf("%s-->",G.Scspot[next].data.name);
		next=Path[next][e];//当前的后继点的编号
	}
	printf("%s\n",G.Scspot[e].data.name);
}
/*打印最短路径及最短距离*/
void PrintPath()
{
	ShortestPath_Floyd();//预处理所有的最短路径
	printf("                                                                                   北\n");
    printf("                                                                                   |\n"); 
    printf("                                                                                   |\n"); 
    printf("                                                                                   |------>东\n");       
	printf("-------------------------------合肥师范学院校园平面图-------------------------------\n");
	printf(" *********************************************************************************\n");
    printf(" **          10.D栋男生宿舍_                                                    **\n");
	printf(" **          |            |      <未知>施工区                                   **\n");
	printf(" **          |__12.超市___|                                                     **\n");
	printf(" **          |            |                       3.博学楼D区________           **\n");
    printf(" **          |____________|____________________________|            |           **\n");
	printf(" **          |            |    |                       |_______3.博学楼C区      **\n");
	printf(" **          |___9.食堂___|    |                       |           |            **\n");
	printf(" **          |            |    |_____________________3.博学楼B区   |            **\n");
	printf(" ** 8.操场___|____________|________|  7.湖      |       |          |            **\n");
	printf(" **          |            |        |____________|       |          |<未知>施工区**\n");
	printf(" **          |            |           |         |__3.博学楼A区_____|            **\n");
	printf(" **          |            |           |            |                            **\n");
	printf(" **          |            |      4.铭传楼          |                            **\n");
	printf(" **          |    6.女生宿舍_______________________|___________2.(ABC)栋男生宿舍**\n");
	printf(" **          |                 |       |           |                            **\n");
	printf(" **          |                5.运动体育区         |                            **\n");
	printf(" **          |                                     |                            **\n");
	printf(" **       11.小东门                           1.东大门                          **\n");
	printf(" *********************************************************************************\n");
	printf("对照校园平面图,输入您当前所在景点及您要去的景点的编号:");
	int s,e;
	scanf("%d%d",&s,&e);
	if(s<=12&&s>=0&&e<=12&&e>=0){
		printf(">>%s到%s的最短路径长度为: %dm\n",G.Scspot[s].data.name,G.Scspot[e].data.name,D[s][e]);
		OutPath(s,e);
		printf(">>按Enter键返回主界面");
		system("pause");
		system("cls");
	}else{
		printf("编号输入错误,请重新输入正确的景点编号!\n");
		printf("按Enter键重新输入");
		system("pause");
		system("cls");
		PrintPath();
	}

}
void Menu()
{
	printf("------------欢迎进入合师校园导航系统V1.0------------\n");
	printf("\n----------------------------------------------------\n");
	printf("1.查看校园平面图\n");
	printf("2.修改景点信息\n");
	printf("3.查看景点基本信息\n");
	printf("4.最短路径查询\n");
	printf("5.退出\n");
	printf("----------------------------------------------------\n");
	printf(">>请输入您要选择的功能:");
	int chose;
	scanf("%d",&chose);
	switch(chose)
	{
		case 1: 
		{
			View();
			Menu();
		}
		//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
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
			//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
		}
		default : 
		{
			printf("您的选择有误,请重新选择!");
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
	printf(">>请选择以下地图初始化(目前仅有合肥师范学院的简约景点图，待后续系统更新)\n");
	printf("1.合肥师范学院校园景点图\n");
	printf("2.敬请期待·····\n");
	printf("3.敬请期待·····\n");
	printf("PLease you chioce:");
    scanf("%d",&abc);
	if(abc==1)
	{
     	InitMes();
	    printf("初始化中");
		for(int i=1;i<=5;i++)
		{
            printf(".");
			Sleep(500);
		}
		printf("\n");
	    printf("景点信息初始化成功,进入主界面\n");
		Sleep(2000);
		system("cls");
	    Menu();
	}
	else
	{
		printf("初始化中");
		for(int i=1;i<=5;i++)
		{
            printf(".");
			Sleep(600);
		}
		//团队：敖文康 孙佳乐 张安齐
			//主要负责人：敖文康
			//Qq:1025181600
		printf("\n");
		printf("景点信息初始化失败\n");
		Sleep(2000);
		system("cls");
	    printf(">>请重新选择以下地图初始化(目前仅有合肥师范学院的简约景点图，待后续系统更新)\n");
	    printf("1.合肥师范学院校园景点图\n");
	    printf("2.敬请期待·····\n");
	    printf("3.敬请期待·····\n");
	    printf("PLease you chioce:");
	    scanf("%d",&abc);
	   if(abc==1)
	 {
     	 InitMes();
		printf("初始化中");
		for(int i=1;i<=5;i++)
		{
            printf(".");
			Sleep(500);
		}
		 printf("\n");
     	 printf("景点信息初始化成功,进入主界面\n");
		 Sleep(2000);
		 system("cls");
	     Menu();
	}
}
	}
	else
	{
		cout<<endl<<"抱歉 登入失败！"<<endl;
		cout<<"原因：账号不存在或账号输入错误"<<endl;
		system("pause");
	}
	return 0;
}



