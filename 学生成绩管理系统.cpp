//ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//�ɼ��ṹ��
struct score
{
	char snum[9];
	char sname[11];
	int cs;//c���Գɼ� 
	int gs;//�����ɼ� 
	int ys;//Ӣ��ɼ� 
	int sumcj;//�ɼ����� 
	int rank;//���� 
}sco[100];
int count=0;

//�������� 
void Sta_avg();//��ɼ���ƽ���� 
void Sta_min();//��ɼ�����Сֵ 
void Sta_max();//��ɼ����ֵ 
void Welcome(void);//��ӭ����
void Password(void);//��������
void showmenu(void);//�˵� 
int xg(int);//�޸ĳɼ�   
void lr(int);//¼��ɼ� 
void cx(int);//��ѯ�ɼ� 
void xhcx(int);//ѧ�Ų�ѯ 
void xmcx(int n);//������ѯ
void allrankcx(int);//������ѯ 
void showcxmenu(void);//�����˵�����ѯ�˵� 
void xs(int);//�ɼ���ʾ 
void jspm(int);//�������� 
int sc(int);//ɾ���ɼ� 
void bccj(void);//����ɼ����˳�
//main���� 
int main()
{   
    Welcome();
    Password();
    
	int flag,n=0,count=0;//flag��־λ,count����,��ǰ������
	//-------------�ж��ļ������ж�������¼--------------------//
	FILE *fp;
	fp=fopen("cj.txt","a+");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��,�����ԣ�\n");
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
        //����ַ�
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
		scanf("%d",&flag);//ѡ����� 
		switch(flag)
		{
			case 1: printf("��������Ҫ¼���������");
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
		    default:printf("������������ԣ�\n");getch(); 
		} 
	}while(flag!=0);
	getch();
	return 0;
}
//��ӭ����
void Welcome() 
{
 system("title ������ƿγ����"); //���ûỰ�Ĵ��ڱ���Ϊ"������ƿγ����"
 system("color F4");  //���ñ���ɫΪ����ɫ��������ɫΪ��ɫ
 system("cls");	//����
 printf("\n\n\t\t|----------------------------------------|\n");
 printf("\t\t    |----------------------------------------|\n");
 printf("\t\t    |        ��������ơ��γ����            |\n");
 printf("\t\t|   |          ѧ���ɼ�����ϵͳ              |\n");
 printf("\t\t    |----------------------------------------|\n");
 printf("\t\t    |----------------------------------------|\n");
 printf("\n\t\t	         ������ƣ��¹��Ʋ�ҵѧԺ            ");
 printf("\n\t\t          �༶��11��\n"); 
 printf("\n\t\t          ������������\n");
 printf("\n\t\t          ѧ�ţ�202012901124\n");
 printf("\n\t\t            2021��3��9��\n");
 printf("\n\t\t\t ��������������룺");
 }
//��������
void Password()
{ char xx[10];
 scanf("%s",&xx);
  if(strcmp("24",xx)==0)
	showmenu();
  else {
  printf("\n����������������룺");
     Password();
  }
     
}
   
//0��ʾ�˵�
void showmenu()
{
	system("cls"); //���� 
	printf("\t*----------------------------------------------------*\n");
	printf("\t*               ��ӭʹ��ѧ���ɼ�����ϵͳ             *\n");
	printf("\t*----------------------------------------------------*\n"); 
	printf("\t*               1�� ¼��ɼ�                         *\n");
	printf("\t*               2�� ɾ���ɼ�                         *\n");
	printf("\t*               3�� �޸ĳɼ�                         *\n");
	printf("\t*               4�� �ɼ���ѯ                         *\n");
	printf("\t*               5�� �ɼ����㲢����                   *\n");
	printf("\t*               6�� ��ʾ�ɼ���Ϣ                     *\n");
	printf("\t*               7�� ��ɼ������ֵ                   *\n");
	printf("\t*               8�� ��ɼ�����Сֵ                   *\n");
	printf("\t*               9�� ��ɼ���ƽ����                   *\n");
	printf("\t*               0�� ������Ϣ���˳�ϵͳ               *\n");
	printf("\t*----------------------------------------------------*\n");
	printf("\t ѡ�����<0-6>                                        \n");
	return;                                         
	
}
//1¼��ɼ� 
void lr(int n)
 {  count=n;
 	struct score sco[100];
 	FILE *fp;
 	fp=fopen("cj.txt","a+");
 	if(fp==NULL)
 	{
		printf("���ļ�ʧ��,�����ԣ�\n");
		getch(); 
		fclose(fp);
		exit(0);
	}
 	printf("������ȫ��ѧ����ѧ�ţ�������c���Գɼ��������ɼ���Ӣ��ɼ���\n"); 
 	int i;
 	for(i=0;i<n;i++)
 	{	
 		printf("----��%d��ѧ��----\n", i+1);
		printf("ѧ��:");
		scanf("%s",&sco[i].snum);
		
		printf("������");
		scanf("%s,",&sco[i].sname);
		
		printf("c���Գɼ���");
		scanf("%d",&sco[i].cs);
		
		printf("�����ɼ���");
		scanf("%d",&sco[i].gs);
		
		printf("Ӣ��ɼ���");
		scanf("%d",&sco[i].ys);
		
		sco[i].sumcj=0;
		sco[i].rank=0;	
		//д������ 
		fprintf(fp,"%s %s %d %d %d %d %d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);} 
	 	fclose(fp);
	 	printf("���ѧ���ɹ�,�밴���������\n");
	 	getch();
	 	return;
 }
//2ɾ���ɼ�                                    
int sc(int n)
{
	struct score sco[100];
	struct score sub[99];//ɾ����Ľṹ������ 
	char stnum[9];//ѧ��
	int find=0;
	printf("��������Ҫɾ����ѧ��ѧ��:"); 
	scanf("%s", &stnum);
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��,����ϵ����Ա\n");
		getch(); 
		return -1;   
	}
	int c=0;
	int index=0;//���ڼ�¼Ŀ����� 
	while(!feof(fp))//��Ϊ��
	{ 
		fscanf(fp,"%s %s %d %d %d %d %d\n", &sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		if(strcmp(stnum,sco[c].snum)==0)
		{
			find = 1;//����ѧ�Ų��ң��ҵ���ֵΪ1 
			index = c;//��¼���
		} 
		c++;
	}
	fclose(fp);
	if(n==0)
	{
		printf("�Ѿ�û��ѧ���ɼ���Ϣ��,�밴���������\n");
		getch();  
		showmenu();
		return n;
	}
	if(find==0)
	{
		printf("û�и�ѧ���ɼ���Ϣ,�밴���������\n");
		getch();  
		showmenu();
		return n;
	}
	else 
	{
		int i;
		//ɾ�� 
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
		//д������ 
		for(i=0;i<c-1;i++)
		{
			fprintf(fp,"%s %s %d %d %d %d %d\n",sub[i].snum,sub[i].sname,sub[i].cs,sub[i].gs,sub[i].ys,sub[i].sumcj,sub[i].rank); 	
		} 
		fclose(fp);
		printf("ѧ��Ϊ%s��ѧ���ɼ�ɾ���ɹ�,�밴���������\n",stnum);
		getch();
		showmenu();
		return n-1;
	}     
}
//3�޸ĳɼ�
int xg(int n) 
{	
	struct score sco[100];
 	FILE *fp;
 	char stnum[9];
 	int find=0;  
 	printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
 	scanf("%s",stnum);
 	fp=fopen("cj.txt","r");
 	if(fp==NULL)
 	{
	  	printf("�ļ���ʧ��,����ϵ����Ա\n");
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
		 	//�޸Ĳ��� 
		 	printf("�ҵ���Ҫ�޸ĳɼ���ͬѧ,���������ĳɼ�:\n");
		 	printf("c���Գɼ�: %d,�³ɼ�Ϊ:",sco[c].cs);
		 	scanf("%d",&sco[c].cs);
		 	printf("�����ɼ�: %d,�³ɼ�Ϊ:",sco[c].gs); 
		 	scanf("%d",&sco[c].gs);
		 	printf("Ӣ��ɼ�: %d,�³ɼ�Ϊ:",sco[c].ys);
		 	scanf("%d",&sco[c].ys);
 		}
  		c++;	
 	}
	fclose(fp);
	if(find==0)
	{
		printf("û���ҵ�Ҫɾ����ѧ����¼,�밴������˳�\n");
		getch(); 
	} 
	else
 	{
	  	fp=fopen("cj.txt","w");
	  	int i; 
	   	for(i=0;i<n;i++)
	   	{
	   		//�������� 
		    fprintf(fp,"%s %s %d %d %d %d %d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);	
	   	}
		fclose(fp);	 
		printf("ѧ��Ϊ%sͬѧ�ĳɼ��Ѿ��޸ĳɹ�,�밴���������",stnum);
 		getch(); 
 	}
  	showmenu();
  	return 1; 
}
//4�ɼ���ѯ
void cx(int n) //nȫ������ 
{
	int k;
	do
	{
		showcxmenu();
		scanf("%d",&k); 
		switch(k)
		{ 
			case 1:xhcx(n);break;//ѧ�Ų�ѯ 
			case 2:xmcx(n);break;//������ѯ 
			case 3:allrankcx(n);break;//ȫ��������ѯ
			case 0:break;
			default:printf("�������������ѡ��\n");getch();
		} 
	}while(k!=0);
	return;		
}

//4.0��ѯ�˵�
void showcxmenu() 
{
	system("cls");
	printf("*----------------------------------------------------*\n");
	printf("*                    �ɼ���ѯ�˵�                    *\n");
	printf("*----------------------------------------------------*\n"); 
	printf("*               1�� ��ѧ�Ų�ѯ                       *\n");
	printf("*               2�� ��������ѯ                       *\n");
	printf("*               3�� ȫ��������ѯ                     *\n");
	printf("*               0�� �˳���ѯϵͳ��������ϵͳ         *\n");
	printf("*----------------------------------------------------*\n");
	printf("ѡ�����<0-3>                                         \n");
}
//4.1ѧ�Ų�ѯ
void xhcx(int n)
{   
	struct score sco[100];
	char snum[9];
	printf("��������Ҫ��ѯѧ����ѧ�ţ�");
	scanf("%s",&snum);
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ѧ��\t����\tc����\t����\tӢ��\t�ܷ�\t����\n");
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
			printf("�����������\n");
			getch();
			fclose(fp);
			return;			
		}
	}
	printf("δ�ҵ�Ҫ��ѯѧ���ĳɼ��������ԣ�\n");
	getch();
	fclose(fp);
	return;
}  
//4.2������ѯ
void xmcx(int n)
{
  	struct score sco[100];	
	char sname[11];
	printf("��������Ҫ��ѯѧ����������");
	scanf("%s",&sname);
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ѧ��\t����\tc����\t����\tӢ��\t�ܷ�\t����\n");
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
			printf("�����������\n");
			getch();
			fclose(fp);
			return;
		}
	}
	printf("δ�ҵ�Ҫ��ѯѧ���ĳɼ��������ԣ�\n");
	getch();
	fclose(fp);
	return;     
}
//4.3ȫ��������ѯ
void allrankcx(int n)
{
  	struct score sco[100];	
  	struct score temp;	
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("���Ƚ��гɼ����������������\n");
			getch();
			fclose(fp);
			return;	
		}
		sco[i].sumcj = sco[i]. cs+ sco[i].gs + sco[i].ys;
		//ð�������㷨������ n-1 �ֱȽ�
	    for(i=0; i<n-1; i++){
	        //ÿһ�ֱȽ�ǰ n-1-i ����Ҳ����˵���Ѿ�����õ���� i �����ñȽ�
	        for(j=0; j<n-1-i; j++){
	            if(sco[j].sumcj > sco[j+1].sumcj){
	                temp = sco[j];
	                sco[j] = sco[j+1];
	                sco[j+1] = temp;
	            }
	        }
	    }
	    printf("ѧ��\t����\tc����\t����\tӢ��\t�ܷ�\t����\n");
	    for(i=0;i<n;i++)
	    {
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
		}
		printf("�����������\n");
		getch();
		fclose(fp);
		return;
	}
	printf("��ѯʧ�ܣ������ԣ�\n");
	getch();
	fclose(fp);
	return;     
}
//5������������ 
void jspm(int n)
{
	struct score sco[100];
	int i,j,temp;
	int count;
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
	//�����������洢 
    for(i=0;i<n;i++)
    {
	    temp=1;//��1�� 
	    for(j=0;j<n;j++){
	    	if(sco[i].sumcj<sco[j].sumcj) temp++;//�����С�������½�1��
		} 
		sco[i].rank=temp;
    }
    //���¼�¼ 
    fp=fopen("cj.txt","w");
   	for(i=0;i<n;i++)
   	{
	    fprintf(fp,"%s %s %d %d %d %d %d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);	
   	}
	fclose(fp);
    printf("�������¼���������ɹ�,�밴������������˵���\n");
	getch();
    return;       
}
//6��ʾ�ɼ���Ϣ
void xs(int n) 
{
	struct score sco[100];
	int i;	
	printf("�ɼ���Ϣ���£�\n");
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��,�����ԣ�\n");
		getch(); 
		fclose(fp);  
		exit(0);
	} 
	printf("ѧ��\t����\tc����\t����\tӢ��\t�ܷ�\t����\n"); 
	int c = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d %d %d %d\n",&sco[c].snum,&sco[c].sname,&sco[c].cs,&sco[c].gs,&sco[c].ys,&sco[c].sumcj,&sco[c].rank);
		c++;
	}
	if(n!=0){//������Ϊ0 
		for(i=0;i<c;i++)
		{
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",sco[i].snum,sco[i].sname,sco[i].cs,sco[i].gs,sco[i].ys,sco[i].sumcj,sco[i].rank);
		}	
	}
	fclose(fp); 
	printf("��ʾ��� ,�밴���������\n");
	getch();
	return;
}
//7��ɼ������ֵ 
void Sta_max() // ͳ�Ƴɼ���߷ֺ��� 
{

    int i=0,x,k=0;

    printf("********************�������ѡ��**********************\n");/*ѡ���ܲ˵�*/

    printf("          1.���Ҹ����ɼ����ѧ��       \n");

    printf("          2.����Ӣ��ɼ����ѧ��       \n");           

    printf("          3.����C���Գɼ����ѧ��      \n");

     scanf("%d",&x);/*�û�ѡ�����*/     
	switch(x)
		{
			case 1: for(i=0;i<count;i++)/*���Ҹ����ɼ����ѧ��*/                   

                   {   if(sco[i].gs>sco[k].gs)

                        k=i;

                    }

                       printf("�����ɼ����ѧ����Ϣ����:\n");

                       printf("ѧ��:%s ����:%s\n",sco[k].snum,sco[k].sname);

                       printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       �������\n");

                       printf("  **********************************************************");break;
			case 2:for(i=0;i<count;i++)/*����Ӣ��ɼ����ѧ��*/                   

                   {   if(sco[i].ys>sco[k].ys)

                        k=i;

                    }

                       printf("Ӣ��ɼ����ѧ����Ϣ����:\n");

                       printf("ѧ��:%s ����:%s\n",sco[k].snum,sco[k].sname);

                       printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       �������\n");

                       printf("  **********************************************************");break; 
			case 3: for(i=0;i<count;i++)/*����c���Գɼ����ѧ��*/                   

                   {   if(sco[i].cs>sco[k].cs)

                        k=i;

                    }

       printf("c���Գɼ����ѧ����Ϣ����:\n");

       printf("ѧ��:%s ����:%s\n",sco[k].snum,sco[k].sname);

       printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

       printf("                       �������\n");

        printf("  **********************************************************");break;
			
		    default:printf("������������ԣ�\n");getch(); 
		}
	getch();
	return ;
}   
//��ɼ������ֵ
void Sta_min() // ͳ�Ƴɼ���ͷֺ��� 
{

    int i=0,x,k=0;

    printf("********************�������ѡ��**********************\n");/*ѡ���ܲ˵�*/

    printf("          1.���Ҹ����ɼ����ѧ��       \n");

    printf("          2.����Ӣ��ɼ����ѧ��       \n");           

    printf("          3.����C���Գɼ����ѧ��      \n");

    scanf("%d",&x);/*�û�ѡ�����*/     
	switch(x)
		{
			case 1: for(i=0;i<count;i++)/*���Ҹ����ɼ����ѧ��*/                   

                   {   if(sco[i].gs<sco[k].gs)

                        k=i;

                    }

                       printf("�����ɼ����ѧ����Ϣ����:\n");

                       printf("ѧ��:%s ����:%s\n",sco[k].snum,sco[k].sname);

                       printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       �������\n");

                       printf("  **********************************************************");break;
			case 2:for(i=0;i<count;i++)/*����Ӣ��ɼ����ѧ��*/                   

                   {   if(sco[i].ys<sco[k].ys)

                        k=i;

                    }

                       printf("Ӣ��ɼ����ѧ����Ϣ����:\n");

                       printf("ѧ��:%s ����:%s\n",sco[k].snum,sco[k].sname);

                       printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

                       printf("                       �������\n");

                       printf("  **********************************************************");break; 
			case 3: for(i=0;i<count;i++)/*����c���Գɼ����ѧ��*/                   

                   {   if(sco[i].cs<sco[k].cs)

                        k=i;

                    }

       printf("c���Գɼ����ѧ����Ϣ����:\n");

       printf("ѧ��:%s ����:%s\n",sco[k].snum,sco[k].sname);

       printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d\n",sco[k].gs,sco[k].ys,sco[k].cs,sco[k].sumcj);

       printf("                       �������\n");

        printf("  **********************************************************");break;
			
		    default:printf("������������ԣ�\n");getch(); 
		}
	getch();
	return ;
}   
//��ɼ���ƽ���� 
void Sta_avg(){
	int a=0,b=0,c=0,i;
	for(i=0;i<count;i++){
		a+=sco[i].gs;
		b+=sco[i].ys;
		c+=sco[i].cs;
	}
	printf("����ƽ����%d\n",a/count);
	printf("Ӣ��ƽ����%d\n",b/count);
	printf("c����ƽ����%d",c/count);
}
void Output() //���ѧ���ɼ���Ϣ���� 
{  int i;
for(i=0;i<count;i++) {
	printf("ѧ��%s\n",sco[i].snum);
    printf(" ����:%s\n",sco[i].sname);
    printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d\n",sco[i].gs,sco[i].ys,sco[i].cs,sco[i].sumcj);
}
   Sta_avg(); 
	system("pause");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	showmenu();
}
 
//0������Ϣ���˳�ϵͳ
void bccj()
{
	printf("��л����ʹ�ã���ӭ�´�ʹ��!\n");
	getch();	 
	return ;
}

