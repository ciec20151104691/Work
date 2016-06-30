#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char *s; 
	int len=0;
	if((fp=fopen("export.txt","r"))==0)
	{
		printf("未能正常打开文件\n");
		return (-1);
	}
	fseek(fp,0,SEEK_END);
	len=ftell(fp);
	s=(char *)malloc(len);
	printf("length=%d",len);
	fclose(fp);
	return 0;
 } 
