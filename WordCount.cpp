#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countc(char *file) //�����ļ����ַ��� 
{   FILE *f;
    f = fopen(file, "r");
    char a;
    int sum=0;
    if(NULL==(f=fopen(file,"r")))
    {
        printf("file is NULL");
    }
    else
    while (!feof(f)) 
	{ 
	a=fgetc(f);
	if (a != ' '&&a != '\n'&&a != '\t')
	{ 
	    sum++;
	} 
	}
	fclose(f);
	printf("�ַ���:%d ",sum); 
}

int countw(char *file)//�����ļ����ʵ���Ŀ 
{   FILE *f;
    f=fopen(file,"r");
    int c=0;
    int flag;
    char ch;
    if(NULL==(f=fopen(file,"r")))
    {
     printf("file is NULL");
    }
    else
    while(!feof(f))
	{ 
	  ch=fgetc(f); 
	  if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z')||ch=='_')
	  { 
	   flag=1;
	  } 
	  else if (flag) 
	  { 
	    c++; 
	    flag=0; 
	  } 
	} 
	fclose(f); 
	printf("������:%d ",c); 
}
int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("FileNull\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]); 
		continue; 
		} 
		else if(!strcmp(argv[1],"-w")) 
		countw(argv[2]); 
		else if(!strcmp(argv[1],"-c")) 
		countc(argv[2]); 
		else printf("NullPoint\n");  
		scanf("%s%s%s",argv[0],argv[1],argv[2]); 
	} 
	return 0;
}
