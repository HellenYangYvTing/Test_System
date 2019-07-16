#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct question                                    //定义结构体
{     
	  int num;                                     //定义题目编号
	  char quest[300];                             //结构体成员：题干、选项。分开供修改方便
	  char a[300],b[300],c[300],d[300];
	  char dault[10];                              //结构体成员：结果
	  struct question* next;
};
struct question* phead;                            //定义全局变量，链表的头（不移动）
int main()                                         //定义主函数
{       
	    void initquestion();
        void showmainmenu();                        //显示出主菜单函数声明
	    phead=(struct question*)malloc(sizeof(struct question));
        phead->next=NULL;
		initquestion();
		showmainmenu();
		return 0;
}
void initquestion()	                                // 将文件题目初始化到链表中
{     
	    FILE *fp=fopen("a.txt","r+");
	    struct question *p=NULL,*pnew=NULL;
		pnew=(struct question*)malloc(sizeof(struct question));
		p=(struct question*)malloc(sizeof(struct question));
		p=phead;
		if(fp==NULL)                                                                      
		{
			printf("cannot open the file\n");
			exit(0);
		} 
		while(!feof(fp))
		{			    
			fscanf(fp,"%d",&pnew->num);
			fgetc(fp);
			fgets(pnew->quest,300,(FILE*)fp);
			fgetc(fp);fgetc(fp);
			fgets(pnew->a,300,(FILE*)fp);
			fgetc(fp);fgetc(fp);
			fgets(pnew->b,300,(FILE*)fp);
			fgetc(fp);fgetc(fp);
			fgets(pnew->c,300,(FILE*)fp);
			fgetc(fp);fgetc(fp);
			fgets(pnew->d,300,(FILE*)fp);
			fgets(pnew->dault,10,(FILE*)fp);
            p->next=pnew;
			p=pnew;
			pnew->next=NULL;
			pnew=(struct question*)malloc(sizeof(struct question));
		}		
		fclose(fp);
}
void showmainmenu()                                        //定义主菜单函数
{ 
	    void showmenu();                                   //初始化文件函数声明
		void show2menu();
		int choose=0;
		int nu;
        char name[10],ch1[10];
		char ch2[10];
        char pass1[50]="123";
		char pass2[50]="456";
		while(choose!=3)
		{
		printf("***********************************************************************************\n");
		printf("           欢迎进入考试系统\n");
		printf("           1：老师\n");
		printf("           2: 学生\n");
		printf("           3: 退出\n");
		printf("************************************************************************************\n"); 
		printf("请选择项目\n");
		scanf("%d",&choose);
		switch(choose)
			{
		case 1: 
			{  
		        printf("请输入系统密码：");                //设置权限
	        	scanf("%s",ch1);
		        fflush(stdin);	
				if(strcmp(pass1,ch1)==0)
				showmenu();
				else printf("密码输入错误\n");
			}
				break;

		case 2: 
			{  
		        printf("请输入考试系统密码：");             //设置权限
	        	scanf("%s",ch2);
		        fflush(stdin);
				if(strcmp(pass2,ch2)==0)
				{
				printf("请输入学号：");
		        scanf("%d",&nu);
		        fflush(stdin);
		        printf("请输入姓名：");
		        scanf("%s",name);
	        	fflush(stdin);
				freopen("score.txt","a+",stdout);		
	            printf("\n学号:%d\n姓名:%s",nu,name);		   
                fclose(stdout); 
                freopen( "CON", "w", stdout ); 
				show2menu();
				}
				else printf("密码输入错误\n");
			}
			  break;
		case 3:          
				break;
		default:printf("enter dada error\n");
			}
		}   
}
void showmenu()                                            //定义子菜单题目                            
{       
	   	void show1menu();
		void findscore();                                  //函数声明
		int choose=0;
		while(choose!=3)
		{
		printf("****************************************************************************\n");
		printf("             1:管理题目\n");
		printf("             2:查看学生成绩\n");
		printf("             3:退出\n");
		printf("****************************************************************************\n");
		fflush(stdin);
		printf("请输入选择的项\n");
		scanf("%d",&choose);
		fflush(stdin);
		switch(choose)
		{
	    case 1:	    show1menu();
					break;		
		case 2:     findscore();  
				    break;
		case 3:     
				    break;
		default:printf("enter dada error\n");
		}
		}
}
void show1menu()                                              //定义子菜单题目                            
{       
	   	void addquestion();
		void deletquestion();
        void changequestion();
		void findquestion(); 
		void savequestion();                                  //函数声明
		int choose=0; 
		while(choose!=6)
		{
		printf("****************************************************************************\n");
		printf("             1:新增题目\n");
		printf("             2:删除题目\n");
		printf("             3:修改题目\n");
		printf("             4:查看题目\n");	 
		printf("             5:保存 \n");
		printf("             6：返回上一级 \n");
		printf("****************************************************************************\n");
		fflush(stdin);
		printf("请输入选择的项\n");
		scanf("%d",&choose);
		fflush(stdin);
		switch(choose)
		{
		case 1:	    {
			        addquestion();
					printf("添加成功！\n");
					break;
					}
		case 2:     {
			        deletquestion();
					printf("删除成功！\n");
					break;
					}     
		case 3:     {
			        changequestion();
					printf("修改成功！\n");
					break;
					}         
		case 4:     {
			        findquestion();
					printf("显示成功！\n");
					break;
					}         
		case 5:     {
			        savequestion();
					printf("保存成功！\n");
					break;
					}        
		case 6:
				    break;
		default:printf("enter dada error\n");
		}
		}

}
void show2menu()                                       //定义子菜单题目                            
{       
	    void text();                                   //函数声明
		int choose=0;	   
		while(choose!=2)
		{
		printf("****************************************************************************\n");
		printf("             1:开始考试\n");
		printf("             2：退出 \n");
		printf("****************************************************************************\n");
		fflush(stdin);
		printf("请输入选择的项\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    case 1:	    text();
					break;		
		case 2:       
				    break;
		default:printf("enter dada error\n");
		}
		}

}
void addquestion()                                     //定义增加题目函数
{	    
	  char ch='y';
	  struct question* p=phead;
	  struct question* pNew;
      char buff[100];
	  do{			
		 while(p->next!=NULL)
		 {
		 p=p->next;
		 }
		pNew=(struct question*)malloc(sizeof(struct question));
		printf("请输入题目编号：");
		scanf("%d",&pNew->num);
		printf("%s\n","请输入题");
		scanf("%s",buff);
		strcpy(pNew->quest,strcat(buff,"\t\n"));
		fflush(stdin);                                     //用scanf，gets，getchar之后清缓存
		printf("A:");		                                   
		gets(buff);
		strcpy(pNew->a,strcat(buff,"\t\n"));
		fflush(stdin);                                      //用scanf，gets，getchar之后清缓存
		printf("B:");
		gets(buff);
		strcpy(pNew->b,strcat(buff,"\t\n"));
		fflush(stdin);                                       //用scanf，gets，getchar之后清缓存
		printf("C:");
		gets(buff);
		strcpy(pNew->c,strcat(buff,"\t\n"));
		fflush(stdin);                                       //用scanf，gets，getchar之后清缓存
		printf("D:");
		gets(buff);
		strcpy(pNew->d,strcat(buff,"\t\n"));
		fflush(stdin);                                        //用scanf，gets，getchar之后清缓存
		printf("答案是：");
		scanf("%s",buff);
		strcpy(pNew->dault,strcat(buff,"\t\n"));
		pNew->next=NULL;
		p->next=pNew;
     	printf("\n是否继续添加题目y/n\n");
		fflush(stdin);                                        //用scanf，gets，getchar之后清缓存
		scanf("%c",&ch);
		}while(ch=='y'); 	
}
void  deletquestion()                                          //定义删函数
{
     struct question* p,*ptemp; 
	 int i;
	 ptemp=(struct question*)malloc(sizeof(struct question));
	 p=phead;
	 printf("请输入想要删除题目相应的题号");
	 scanf("%d",&i);
	 if(p->next->num==i)
	 {
      ptemp=phead->next;
	  p->next=ptemp->next;
	 }
	 else 
	 {
	 while(p->next->num!=i)
     p=p->next;
	 ptemp=p->next;
	 p->next=ptemp->next;
	 free(ptemp);
	 ptemp=NULL;
	 }
}
 
void findquestion()                                            //定义查找题目函数
{
	struct question* pTemp=NULL;
    pTemp=phead->next;
	while(pTemp!=NULL)
	{
		printf("%d.%s\nA:%s\nB:%s\nC:%s\nD:%s\n答案是:%s\n",pTemp->num,pTemp->quest,pTemp->a,pTemp->b,pTemp->c,pTemp->d,pTemp->dault);
		pTemp=pTemp->next;
	}
}
void changequestion()                                            //定义修改题目函数
{ 
	  int m;
	  struct question*psion=NULL;                                //采用链表
	  struct question*ptemp=NULL;
	  char buff[100];
	  ptemp=(struct question*)malloc(sizeof(struct question));   //为节点分配空间
	  psion=phead;
	  printf("请输入修改的相应题号\n");
	  scanf("%d",&m);
	  while(psion->next->num!=m)
	  {
		  psion=psion->next;  
	  }
	  ptemp=psion->next;
	  printf("请输入修改后的题目：");
	  scanf("%s",buff);
	  strcpy(ptemp->quest,strcat(buff,"\t\n"));
	  printf("A:");
	  getchar();
	  gets(buff);
	  strcpy(ptemp->a,strcat(buff,"\t\n"));
	  printf("B:");
	  gets(buff);
	  strcpy(ptemp->b,strcat(buff,"\t\n"));
	  printf("C:");
	  gets(buff);
	  strcpy(ptemp->c,strcat(buff,"\t\n"));
	  printf("D:");
	  gets(buff);
	  strcpy(ptemp->d,strcat(buff,"\t\n"));
	  printf("答案是：");
	  gets(buff);
	  strcpy(ptemp->dault,strcat(buff,"\t\n"));
	  ptemp=psion->next->next;
   
}
void savequestion()                                       //定义保存题目函数
{
   	struct question* pTemp=NULL;
    pTemp=phead->next;		                              //第一道试题（结构体）的地址
    //重定向，标准的输出stdout不是显示器，而是指定的文件。
    //以后的printf语句会输出到指定的文件中
    freopen("a.txt","w+",stdout);
	while(pTemp!=NULL)
	{
	printf("%d.%sA:%sB:%sC:%sD:%s%s",pTemp->num,pTemp->quest,pTemp->a,pTemp->b,pTemp->c,pTemp->d,pTemp->dault);
	pTemp=pTemp->next;
	}
	printf("\n");
    fclose(stdout); 
    //重定向，标准的输出stdout不是文件，而是输出到控制台（显示器）
    //以后的printf语句会输出显示器上
    freopen( "CON", "w", stdout ); 
}
void text()
{
    FILE *fp;
    float result=0;
	int id,i=0,b;
	char buff[1000];                                              //buff用于临时存放字符串
	char ch,a[100];
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
	  printf("文件不存在！"); 
	  return ;
	}  
	printf("\n           正在考试                   \n");
	printf("请输入返回读入数据的个数：");
    scanf("%d",&id);
	b=id;                                                          //scanf函数，返回读入数据的个数
	for(;id>0;id--) 
	{	
		fgets(buff,1000,(FILE*)fp);                                //读文件中的字符串到buff
		printf("%s",buff);                                         //buff中字符串显示到屏幕上
		fgets(buff,1000,(FILE*)fp);
		printf("%s",buff);
		fgets(buff,1000,(FILE*)fp);
		printf("%s",buff);
		fgets(buff,1000,(FILE*)fp);
		printf("%s",buff);
		fgets(buff,1000,(FILE*)fp);
		printf("%s",buff);
		a[i]=fgetc(fp);
		fflush(stdin);
	    printf("请输入你所选答案：");   
		ch=getchar();
		fgets(buff,1000,(FILE*)fp);
		if(a[i]==ch)
        result=result+10;
        i++;
	}
	printf("\n你的成绩是：%5.1f分\n",result);
	printf("答案:");
	for(i=0;i<b;i++)
    printf("\t%c",a[i]);
	printf("\n");
	fclose(fp); 
	freopen("score.txt","a+",stdout);		
	printf("\n成绩是：%5.1f分",result);	   
    fclose(stdout); 
    freopen( "CON", "w", stdout ); 
}
void findscore()                                                     //定义查找学生成绩函数
{ 
    FILE *fp;
	char buff[1000];                                                 //buff用于临时存放字符串
	fp=fopen("score.txt","r");
	if(fp==NULL)
	{
	   printf("文件不存在！"); 
	   return ;
	}  
	printf("\n          学生考试成绩                   \n");
	while(!feof(fp))
	{	
		fgets(buff,1000,(FILE*)fp);
		printf("%s",buff);
        printf("\n");
	}
	
}