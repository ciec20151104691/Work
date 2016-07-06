#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char *str;
	int flen;
	if((fp=fopen("ABC.txt","r"))==0)
	{
		printf("can not open file\n");
		return -1;
	}
	fseek(fp,0,SEEK_END);
	flen=ftell(fp);
	fseek(fp,0,SEEK_SET);
	str=(char *)malloc(1*flen);
	fread(str,1,flen,fp);
	printf("len=%d %c\n",flen,str[2]);
	fclose(fp);
	return 0;
 }
