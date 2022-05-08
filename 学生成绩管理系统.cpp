//头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//成绩结构体
struct score
{
	char snum[9];
	char sname[11];
	int cs;//c语言成绩 
	int gs;//高数成绩 
	int ys;//英语成绩 
	int sumcj;//成绩总数 
	int rank;//排名 
}sco[100];
int count=0;

//函数声明 
void Sta_avg();//求成绩的平均分 
void Sta_min();//求成绩的最小值 
void Sta_max();//求成绩最大值 
void Welcome(void);//欢迎界面
void Password(void);//密码输入
void showmenu(void);//菜单 
int xg(int);//修改成绩   
void lr(int);//录入成绩 
void cx(int);//查询成绩 
void xhcx(int);//学号查询 
void xmcx(int n);//姓名查询
void allrankcx(int);//排名查询 
void showcxmenu(void);//二级菜单，查询菜单 
void xs(int);//成绩显示 
void jspm(int);//计算排名 
int sc(int);//删除成绩 
void bccj(void);//保存成绩并退出
//main函数 
int main()
{   
    Welcome();
    Password();
    
	int flag,n=0,count=0;//flag标志位,count计数,当前总人数
	//-------------判断文件里面有多少条记录--------------------//
	FILE *fp;
	fp=fopen("cj.txt","a+");
	if(fp==NULL)
	{
		printf("打开文件失败,请重试！\n");
		getch(); 
		fclose(fp);  
		exit(0);
	} 
	int c = 0;
	while(!feof(fp))
	{
		char cc = fgetc(fp);
		if(cc==EOF)
        {
        	break;
        }
        //输出字符
//        putchar(cc);
		c++;
	}
	count = c/14;
//	printf("%d", count); 
//	getch();
	fclose(fp);
	//---------------------------------//
	do
	{
		showmenu();
		scanf("%d",&flag);//选择操作 
		switch(flag)
		{
			case 1: printf("请输入您要录入的人数：");
					scanf("%d",&n);
				    lr(n);
					count += n;break;
			case 2: count=sc(count);break;
			case 3: xg(count);break;
			case 4: cx(count);break;
			case 5: jspm(count);break;
		    case 6: xs(count);break;
		    case 7: Sta_max();break;
		    case 8:Sta_min();break;
		    case 9:Sta_avg(); break;
		    case 0: bccj();break; 
		    default:printf("输入错误，请重试！\n");getch(); 
		} 
	}while(flag!=0);
	getch();
	return 0;
}
//欢迎界面
void Welcome() 
{
 system("title 程序设计课程设计"); //设置会话的窗口标题为"程序设计课程设计"
 system("color F4");  //设置背景色为亮白色，字体颜色为红色
 system("cls");	//清屏
 printf("\n\n\t\t|----------------------------------------|\n");
 printf("\t\t    |----------------------------------------|\n");
 printf("\t\t    |        《程序设计》课程设计            |\n");
 printf("\t\t|   |          学生成绩管理系统              |\n");
 printf("\t\t    |----------------------------------------|\n");
 printf("\t\t    |----------------------------------------|\n");
 printf("\n\t\t	         程序设计：新工科产业学院            ");
 printf("\n\t\t          班级：11班\n"); 
 printf("\n\t\t          姓名：林梓铭\n");
 printf("\n\t\t          学号：202012901124\n");
 printf("\n\t\t            2021年3月9号\n");
 printf("\n\t\t\t 请您输入登入密码：");
 }
//密码输入
void Password()
{ char xx[10];
 scanf("%s",&xx);
  if(strcmp("24",xx)==0)
	showmenu();
  else {
  printf("\n密码错误！请重新输入：");
     Password();
  }
     
}
   
//0显示菜单
void showmenu()
{
	system("cls"); //清屏 
	printf("\t*----------------------------------------------------*\n");
	printf("\t*               欢迎使用学生成绩管理系统             *\n");
	printf("\t*----------------------------------------------------*\n"); 
	printf("\t*               1： 录入成绩                         *\n");
	printf("\t*               2： 删除成绩                         *\n");
	printf("\t*               3： 修改成绩                         *\n");
	printf("\t*               4： 成绩查询                         *\n");
	printf("\t*               5： 成绩计算并排名                   *\n");
	printf("\t*               6： 显示成绩信息                     *\n");
	printf("\t*               7： 求成绩的最大值                   *\n");
	printf("\t*               8： 求成绩的最小值                   *\n");
	printf("\t*               9： 求成绩的平均分                   *\n");
	printf("\t*               0： 保存信息并退出系统               *\n");
	printf("\t*----------------------------------------------------*\n");
	printf("\t 选择操作<0-6>                                        \n");
	return;                                         
	
}
//1录入成绩 
void lr(int n)
 {  count=n;
 	struct score sco[100];
 	FILE *fp;
 	fp=fopen("cj.txt","a+");
 	if(fp==NULL)
 	{
		printf("打开文件失败,请重试！\n");
		getch(); 
		fclose(fp);
		exit(0);
	}
 	printf("请输入全部学生的学号，姓名，c语言成绩，高数成绩，英语成绩；\n"); 
 	int i;
 	for(i=0;i<n;i++)
 	{	
 		printf("----第%d个学生----\n", i+1);
		printf("学号:");
		scanf("%s",&sco[i].snum);
		
		printf("姓名：");
		scanf("%s,",&sco[i].sname);
		
		printf("c语言成绩：");
		scanf("%d",&sco[i].cs);
		
		printf("高数成绩：");
		scanf("%d",&sco[i].gs);
		
		printf("英语成绩：");
		scanf("%d",&sco[i].ys);
		
		sco[i].sumcj=0;
		sco[i].rank=0;	
		//写入数据 
		fprintf(fp,"%s %s %d %d %d %d %d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);} 
	 	fclose(fp);
	 	printf("添加学生成功,请按任意键返回\n");
	 	getch();
	 	return;
 }
//2删除成绩                                    
int sc(int n)
{
	struct score sco[100];
	struct score sub[99];//删除后的结构体数组 
	char stnum[9];//学号
	int find=0;
	printf("请输入你要删除的学生学号:"); 
	scanf("%s", &stnum);
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败,请联系管理员\n");
		getch(); 
		return -1;   
	}
	int c=0;
	int index=0;//用于记录目标序号 
	while(!feof(fp))//不为空
	{ 
		fscanf(fp,"%s %s %d %d %d %d %d\n", &sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		if(strcmp(stnum,sco[c].snum)==0)
		{
			find = 1;//根据学号查找，找到赋值为1 
			index = c;//记录编号
		} 
		c++;
	}
	fclose(fp);
	if(n==0)
	{
		printf("已经没有学生成绩信息了,请按任意键返回\n");
		getch();  
		showmenu();
		return n;
	}
	if(find==0)
	{
		printf("没有该学生成绩信息,请按任意键返回\n");
		getch();  
		showmenu();
		return n;
	}
	else 
	{
		int i;
		//删除 
		for(i=0;i<c;i++)
		{
			if(i < index)
			{
				sub[i] = sco[i];
			}
			else
			{
				sub[i] = sco[i+1];
			}
		}
		
		fp=fopen("cj.txt","w");
		//写入数据 
		for(i=0;i<c-1;i++)
		{
			fprintf(fp,"%s %s %d %d %d %d %d\n",sub[i].snum,sub[i].sname,sub[i].cs,sub[i].gs,sub[i].ys,sub[i].sumcj,sub[i].rank); 	
		} 
		fclose(fp);
		printf("学号为%s的学生成绩删除成功,请按任意键返回\n",stnum);
		getch();
		showmenu();
		return n-1;
	}     
}
//3修改成绩
int xg(int n) 
{	
	struct score sco[100];
 	FILE *fp;
 	char stnum[9];
 	int find=0;  
 	printf("请输入要修改的学生学号:");
 	scanf("%s",stnum);
 	fp=fopen("cj.txt","r");
 	if(fp==NULL)
 	{
	  	printf("文件打开失败,请联系管理员\n");
	  	getch();
	  	return -1;	
 	}
 	int c=0;
 	while(!feof(fp))
	{
	 	fscanf(fp,"%s %s %d %d %d %d %d\n",&sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
	 	if(strcmp(stnum,sco[c].snum)==0)	
		{
		 	find=1;
		 	//修改操作 
		 	printf("找到你要修改成绩的同学,请输入他的成绩:\n");
		 	printf("c语言成绩: %d,新成绩为:",sco[c].cs);
		 	scanf("%d",&sco[c].cs);
		 	printf("高数成绩: %d,新成绩为:",sco[c].gs); 
		 	scanf("%d",&sco[c].gs);
		 	printf("英语成绩: %d,新成绩为:",sco[c].ys);
		 	scanf("%d",&sco[c].ys);
 		}
  		c++;	
 	}
	fclose(fp);
	if(find==0)
	{
		printf("没有找到要删除的学生记录,请按任意键退出\n");
		getch(); 
	} 
	else
 	{
	  	fp=fopen("cj.txt","w");
	  	int i; 
	   	for(i=0;i<n;i++)
	   	{
	   		//更新数据 
		    fprintf(fp,"%s %s %d %d %d %d %d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);	
	   	}
		fclose(fp);	 
		printf("学号为%s同学的成绩已经修改成功,请按任意键返回",stnum);
 		getch(); 
 	}
  	showmenu();
  	return 1; 
}
//4成绩查询
void cx(int n) //n全班人数 
{
	int k;
	do
	{
		showcxmenu();
		scanf("%d",&k); 
		switch(k)
		{ 
			case 1:xhcx(n);break;//学号查询 
			case 2:xmcx(n);break;//姓名查询 
			case 3:allrankcx(n);break;//全班排名查询
			case 0:break;
			default:printf("输入错误，请重新选择\n");getch();
		} 
	}while(k!=0);
	return;		
}

//4.0查询菜单
void showcxmenu() 
{
	system("cls");
	printf("*----------------------------------------------------*\n");
	printf("*                    成绩查询菜单                    *\n");
	printf("*----------------------------------------------------*\n"); 
	printf("*               1： 按学号查询                       *\n");
	printf("*               2： 按姓名查询                       *\n");
	printf("*               3： 全班排名查询                     *\n");
	printf("*               0： 退出查询系统，返回主系统         *\n");
	printf("*----------------------------------------------------*\n");
	printf("选择操作<0-3>                                         \n");
}
//4.1学号查询
void xhcx(int n)
{   
	struct score sco[100];
	char snum[9];
	printf("请输入你要查询学生的学号：");
	scanf("%s",&snum);
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0); 
	}
	int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n",&sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		c++;
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(snum,sco[i].snum)==0)
		{
			printf("学号\t姓名\tc语言\t高数\t英语\t总分\t名次\n");
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
			printf("按任意键返回\n");
			getch();
			fclose(fp);
			return;			
		}
	}
	printf("未找到要查询学生的成绩，请重试！\n");
	getch();
	fclose(fp);
	return;
}  
//4.2姓名查询
void xmcx(int n)
{
  	struct score sco[100];	
	char sname[11];
	printf("请输入你要查询学生的姓名：");
	scanf("%s",&sname);
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0); 
	}
	int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n\n",&sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		c++;
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(sname,sco[i].sname)==0)
		{
			printf("学号\t姓名\tc语言\t高数\t英语\t总分\t名次\n");
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
			printf("按任意键返回\n");
			getch();
			fclose(fp);
			return;
		}
	}
	printf("未找到要查询学生的成绩，请重试！\n");
	getch();
	fclose(fp);
	return;     
}
//4.3全班排名查询
void allrankcx(int n)
{
  	struct score sco[100];	
  	struct score temp;	
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0); 
	}
	int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n",&sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		c++;
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		if(sco[i].rank == 0){
			printf("请先进行成绩计算进行排名！！\n");
			getch();
			fclose(fp);
			return;	
		}
		sco[i].sumcj = sco[i]. cs+ sco[i].gs + sco[i].ys;
		//冒泡排序算法：进行 n-1 轮比较
	    for(i=0; i<n-1; i++){
	        //每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
	        for(j=0; j<n-1-i; j++){
	            if(sco[j].sumcj > sco[j+1].sumcj){
	                temp = sco[j];
	                sco[j] = sco[j+1];
	                sco[j+1] = temp;
	            }
	        }
	    }
	    printf("学号\t姓名\tc语言\t高数\t英语\t总分\t名次\n");
	    for(i=0;i<n;i++)
	    {
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
		}
		printf("按任意键返回\n");
		getch();
		fclose(fp);
		return;
	}
	printf("查询失败，请重试！\n");
	getch();
	fclose(fp);
	return;     
}
//5计算排名函数 
void jspm(int n)
{
	struct score sco[100];
	int i,j,temp;
	int count;
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0);
	}
    int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n",&sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		sco[c].sumcj = sco[c].cs + sco[c].gs + sco[c].ys;
		c++;
	}
	fclose(fp);
	//计算排名并存储 
    for(i=0;i<n;i++)
    {
	    temp=1;//第1名 
	    for(j=0;j<n;j++){
	    	if(sco[i].sumcj<sco[j].sumcj) temp++;//如果较小，排名下降1名
		} 
		sco[i].rank=temp;
    }
    //更新记录 
    fp=fopen("cj.txt","w");
   	for(i=0;i<n;i++)
   	{
	    fprintf(fp,"%s %s %d %d %d %d %d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);	
   	}
	fclose(fp);
    printf("数据重新计算和排名成功,请按任意键返回主菜单。\n");
	getch();
    return;       
}
//6显示成绩信息
void xs(int n) 
{
	struct score sco[100];
	int i;	
	printf("成绩信息如下：\n");
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败,请重试！\n");
		getch(); 
		fclose(fp);  
		exit(0);
	} 
	printf("学号\t姓名\tc语言\t高数\t英语\t总分\t名次\n"); 
	int c = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d %d %d %d\n",&sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		c++;
	}
	if(n!=0){//人数不为0 
		for(i=0;i<c;i++)
		{
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
		}	
	}
	fclose(fp); 
	printf("显示完毕 ,请按任意键返回\n");
	getch();
	return;
}
//7求成绩的最大值 
void Sta_max() // 统计成绩最高分函数 
{

    int i=0,x,k=0;

    printf("********************输入查找选项**********************\n");/*选择功能菜单*/

    printf("          1.查找高数成绩最高学生       \n");

    printf("          2.查找英语成绩最高学生       \n");           

    printf("          3.查找C语言成绩最高学生      \n");

     scanf("%d",&x);/*用户选择变量*/     
	switch(x)
		{
			case 1: for(i=0;i<count;i++)/*查找高数成绩最高学生*/                   

                   {   if(sco[i].gs>sco[k].gs)

                        k=i;

                    }

                       printf("高数成绩最高学生信息如下:\n");

                       printf("学号:%s 姓名:%s\n",sco[k].snum,sco[k].sname);

                       printf("高数:%d  英语:%d  C语言:%d  总分:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       输出结束\n");

                       printf("  **********************************************************");break;
			case 2:for(i=0;i<count;i++)/*查找英语成绩最高学生*/                   

                   {   if(sco[i].ys>sco[k].ys)

                        k=i;

                    }

                       printf("英语成绩最高学生信息如下:\n");

                       printf("学号:%s 姓名:%s\n",sco[k].snum,sco[k].sname);

                       printf("高数:%d  英语:%d  C语言:%d  总分:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       输出结束\n");

                       printf("  **********************************************************");break; 
			case 3: for(i=0;i<count;i++)/*查找c语言成绩最高学生*/                   

                   {   if(sco[i].cs>sco[k].cs)

                        k=i;

                    }

       printf("c语言成绩最高学生信息如下:\n");

       printf("学号:%s 姓名:%s\n",sco[k].snum,sco[k].sname);

       printf("高数:%d  英语:%d  C语言:%d  总分:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

       printf("                       输出结束\n");

        printf("  **********************************************************");break;
			
		    default:printf("输入错误，请重试！\n");getch(); 
		}
	getch();
	return ;
}   
//求成绩的最低值
void Sta_min() // 统计成绩最低分函数 
{

    int i=0,x,k=0;

    printf("********************输入查找选项**********************\n");/*选择功能菜单*/

    printf("          1.查找高数成绩最低学生       \n");

    printf("          2.查找英语成绩最低学生       \n");           

    printf("          3.查找C语言成绩最低学生      \n");

    scanf("%d",&x);/*用户选择变量*/     
	switch(x)
		{
			case 1: for(i=0;i<count;i++)/*查找高数成绩最低学生*/                   

                   {   if(sco[i].gs<sco[k].gs)

                        k=i;

                    }

                       printf("高数成绩最低学生信息如下:\n");

                       printf("学号:%s 姓名:%s\n",sco[k].snum,sco[k].sname);

                       printf("高数:%d  英语:%d  C语言:%d  总分:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       输出结束\n");

                       printf("  **********************************************************");break;
			case 2:for(i=0;i<count;i++)/*查找英语成绩最低学生*/                   

                   {   if(sco[i].ys<sco[k].ys)

                        k=i;

                    }

                       printf("英语成绩最低学生信息如下:\n");

                       printf("学号:%s 姓名:%s\n",sco[k].snum,sco[k].sname);

                       printf("高数:%d  英语:%d  C语言:%d  总分:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       输出结束\n");

                       printf("  **********************************************************");break; 
			case 3: for(i=0;i<count;i++)/*查找c语言成绩最低学生*/                   

                   {   if(sco[i].cs<sco[k].cs)

                        k=i;

                    }

       printf("c语言成绩最低学生信息如下:\n");

       printf("学号:%s 姓名:%s\n",sco[k].snum,sco[k].sname);

       printf("高数:%d  英语:%d  C语言:%d  总分:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

       printf("                       输出结束\n");

        printf("  **********************************************************");break;
			
		    default:printf("输入错误，请重试！\n");getch(); 
		}
	getch();
	return ;
}   
//求成绩的平均分 
void Sta_avg(){
	int a=0,b=0,c=0,i;
	for(i=0;i<count;i++){
		a+=sco[i].gs;
		b+=sco[i].ys;
		c+=sco[i].cs;
	}
	printf("高数平均分%d\n",a/count);
	printf("英语平均分%d\n",b/count);
	printf("c语言平均分%d",c/count);
}
void Output() //输出学生成绩信息函数 
{  int i;
for(i=0;i<count;i++) {
	printf("学号%s\n",sco[i].snum);
    printf(" 姓名:%s\n",sco[i].sname);
    printf("高数:%d  英语:%d  C语言:%d  总分:%d\n",sco[i].gs,sco[i].ys,sco[i].cs,sco[i].sumcj);
}
   Sta_avg(); 
	system("pause");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	showmenu();
}
 
//0保存信息并退出系统
void bccj()
{
	printf("感谢您的使用，欢迎下次使用!\n");
	getch();	 
	return ;
}

