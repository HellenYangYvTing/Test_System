#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct question                                    //����ṹ��
{     
	  int num;                                     //������Ŀ���
	  char quest[300];                             //�ṹ���Ա����ɡ�ѡ��ֿ����޸ķ���
	  char a[300],b[300],c[300],d[300];
	  char dault[10];                              //�ṹ���Ա�����
	  struct question* next;
};
struct question* phead;                            //����ȫ�ֱ����������ͷ�����ƶ���
int main()                                         //����������
{       
	    void initquestion();
        void showmainmenu();                        //��ʾ�����˵���������
	    phead=(struct question*)malloc(sizeof(struct question));
        phead->next=NULL;
		initquestion();
		showmainmenu();
		return 0;
}
void initquestion()	                                // ���ļ���Ŀ��ʼ����������
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
void showmainmenu()                                        //�������˵�����
{ 
	    void showmenu();                                   //��ʼ���ļ���������
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
		printf("           ��ӭ���뿼��ϵͳ\n");
		printf("           1����ʦ\n");
		printf("           2: ѧ��\n");
		printf("           3: �˳�\n");
		printf("************************************************************************************\n"); 
		printf("��ѡ����Ŀ\n");
		scanf("%d",&choose);
		switch(choose)
			{
		case 1: 
			{  
		        printf("������ϵͳ���룺");                //����Ȩ��
	        	scanf("%s",ch1);
		        fflush(stdin);	
				if(strcmp(pass1,ch1)==0)
				showmenu();
				else printf("�����������\n");
			}
				break;

		case 2: 
			{  
		        printf("�����뿼��ϵͳ���룺");             //����Ȩ��
	        	scanf("%s",ch2);
		        fflush(stdin);
				if(strcmp(pass2,ch2)==0)
				{
				printf("������ѧ�ţ�");
		        scanf("%d",&nu);
		        fflush(stdin);
		        printf("������������");
		        scanf("%s",name);
	        	fflush(stdin);
				freopen("score.txt","a+",stdout);		
	            printf("\nѧ��:%d\n����:%s",nu,name);		   
                fclose(stdout); 
                freopen( "CON", "w", stdout ); 
				show2menu();
				}
				else printf("�����������\n");
			}
			  break;
		case 3:          
				break;
		default:printf("enter dada error\n");
			}
		}   
}
void showmenu()                                            //�����Ӳ˵���Ŀ                            
{       
	   	void show1menu();
		void findscore();                                  //��������
		int choose=0;
		while(choose!=3)
		{
		printf("****************************************************************************\n");
		printf("             1:������Ŀ\n");
		printf("             2:�鿴ѧ���ɼ�\n");
		printf("             3:�˳�\n");
		printf("****************************************************************************\n");
		fflush(stdin);
		printf("������ѡ�����\n");
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
void show1menu()                                              //�����Ӳ˵���Ŀ                            
{       
	   	void addquestion();
		void deletquestion();
        void changequestion();
		void findquestion(); 
		void savequestion();                                  //��������
		int choose=0; 
		while(choose!=6)
		{
		printf("****************************************************************************\n");
		printf("             1:������Ŀ\n");
		printf("             2:ɾ����Ŀ\n");
		printf("             3:�޸���Ŀ\n");
		printf("             4:�鿴��Ŀ\n");	 
		printf("             5:���� \n");
		printf("             6��������һ�� \n");
		printf("****************************************************************************\n");
		fflush(stdin);
		printf("������ѡ�����\n");
		scanf("%d",&choose);
		fflush(stdin);
		switch(choose)
		{
		case 1:	    {
			        addquestion();
					printf("��ӳɹ���\n");
					break;
					}
		case 2:     {
			        deletquestion();
					printf("ɾ���ɹ���\n");
					break;
					}     
		case 3:     {
			        changequestion();
					printf("�޸ĳɹ���\n");
					break;
					}         
		case 4:     {
			        findquestion();
					printf("��ʾ�ɹ���\n");
					break;
					}         
		case 5:     {
			        savequestion();
					printf("����ɹ���\n");
					break;
					}        
		case 6:
				    break;
		default:printf("enter dada error\n");
		}
		}

}
void show2menu()                                       //�����Ӳ˵���Ŀ                            
{       
	    void text();                                   //��������
		int choose=0;	   
		while(choose!=2)
		{
		printf("****************************************************************************\n");
		printf("             1:��ʼ����\n");
		printf("             2���˳� \n");
		printf("****************************************************************************\n");
		fflush(stdin);
		printf("������ѡ�����\n");
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
void addquestion()                                     //����������Ŀ����
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
		printf("��������Ŀ��ţ�");
		scanf("%d",&pNew->num);
		printf("%s\n","��������");
		scanf("%s",buff);
		strcpy(pNew->quest,strcat(buff,"\t\n"));
		fflush(stdin);                                     //��scanf��gets��getchar֮���建��
		printf("A:");		                                   
		gets(buff);
		strcpy(pNew->a,strcat(buff,"\t\n"));
		fflush(stdin);                                      //��scanf��gets��getchar֮���建��
		printf("B:");
		gets(buff);
		strcpy(pNew->b,strcat(buff,"\t\n"));
		fflush(stdin);                                       //��scanf��gets��getchar֮���建��
		printf("C:");
		gets(buff);
		strcpy(pNew->c,strcat(buff,"\t\n"));
		fflush(stdin);                                       //��scanf��gets��getchar֮���建��
		printf("D:");
		gets(buff);
		strcpy(pNew->d,strcat(buff,"\t\n"));
		fflush(stdin);                                        //��scanf��gets��getchar֮���建��
		printf("���ǣ�");
		scanf("%s",buff);
		strcpy(pNew->dault,strcat(buff,"\t\n"));
		pNew->next=NULL;
		p->next=pNew;
     	printf("\n�Ƿ���������Ŀy/n\n");
		fflush(stdin);                                        //��scanf��gets��getchar֮���建��
		scanf("%c",&ch);
		}while(ch=='y'); 	
}
void  deletquestion()                                          //����ɾ����
{
     struct question* p,*ptemp; 
	 int i;
	 ptemp=(struct question*)malloc(sizeof(struct question));
	 p=phead;
	 printf("��������Ҫɾ����Ŀ��Ӧ�����");
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
 
void findquestion()                                            //���������Ŀ����
{
	struct question* pTemp=NULL;
    pTemp=phead->next;
	while(pTemp!=NULL)
	{
		printf("%d.%s\nA:%s\nB:%s\nC:%s\nD:%s\n����:%s\n",pTemp->num,pTemp->quest,pTemp->a,pTemp->b,pTemp->c,pTemp->d,pTemp->dault);
		pTemp=pTemp->next;
	}
}
void changequestion()                                            //�����޸���Ŀ����
{ 
	  int m;
	  struct question*psion=NULL;                                //��������
	  struct question*ptemp=NULL;
	  char buff[100];
	  ptemp=(struct question*)malloc(sizeof(struct question));   //Ϊ�ڵ����ռ�
	  psion=phead;
	  printf("�������޸ĵ���Ӧ���\n");
	  scanf("%d",&m);
	  while(psion->next->num!=m)
	  {
		  psion=psion->next;  
	  }
	  ptemp=psion->next;
	  printf("�������޸ĺ����Ŀ��");
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
	  printf("���ǣ�");
	  gets(buff);
	  strcpy(ptemp->dault,strcat(buff,"\t\n"));
	  ptemp=psion->next->next;
   
}
void savequestion()                                       //���屣����Ŀ����
{
   	struct question* pTemp=NULL;
    pTemp=phead->next;		                              //��һ�����⣨�ṹ�壩�ĵ�ַ
    //�ض��򣬱�׼�����stdout������ʾ��������ָ�����ļ���
    //�Ժ��printf���������ָ�����ļ���
    freopen("a.txt","w+",stdout);
	while(pTemp!=NULL)
	{
	printf("%d.%sA:%sB:%sC:%sD:%s%s",pTemp->num,pTemp->quest,pTemp->a,pTemp->b,pTemp->c,pTemp->d,pTemp->dault);
	pTemp=pTemp->next;
	}
	printf("\n");
    fclose(stdout); 
    //�ض��򣬱�׼�����stdout�����ļ����������������̨����ʾ����
    //�Ժ��printf���������ʾ����
    freopen( "CON", "w", stdout ); 
}
void text()
{
    FILE *fp;
    float result=0;
	int id,i=0,b;
	char buff[1000];                                              //buff������ʱ����ַ���
	char ch,a[100];
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
	  printf("�ļ������ڣ�"); 
	  return ;
	}  
	printf("\n           ���ڿ���                   \n");
	printf("�����뷵�ض������ݵĸ�����");
    scanf("%d",&id);
	b=id;                                                          //scanf���������ض������ݵĸ���
	for(;id>0;id--) 
	{	
		fgets(buff,1000,(FILE*)fp);                                //���ļ��е��ַ�����buff
		printf("%s",buff);                                         //buff���ַ�����ʾ����Ļ��
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
	    printf("����������ѡ�𰸣�");   
		ch=getchar();
		fgets(buff,1000,(FILE*)fp);
		if(a[i]==ch)
        result=result+10;
        i++;
	}
	printf("\n��ĳɼ��ǣ�%5.1f��\n",result);
	printf("��:");
	for(i=0;i<b;i++)
    printf("\t%c",a[i]);
	printf("\n");
	fclose(fp); 
	freopen("score.txt","a+",stdout);		
	printf("\n�ɼ��ǣ�%5.1f��",result);	   
    fclose(stdout); 
    freopen( "CON", "w", stdout ); 
}
void findscore()                                                     //�������ѧ���ɼ�����
{ 
    FILE *fp;
	char buff[1000];                                                 //buff������ʱ����ַ���
	fp=fopen("score.txt","r");
	if(fp==NULL)
	{
	   printf("�ļ������ڣ�"); 
	   return ;
	}  
	printf("\n          ѧ�����Գɼ�                   \n");
	while(!feof(fp))
	{	
		fgets(buff,1000,(FILE*)fp);
		printf("%s",buff);
        printf("\n");
	}
	
}