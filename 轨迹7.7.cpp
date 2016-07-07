#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int main()
{
	FILE *fp,*pW;
	char CoStr[20],ln,ch,i=0;
	if(!(fp=fopen("export.txt","r")))
	{
	printf("源文件打开失败...");
	exit(0);
	} 
	printf("请输入特定字符串...\nCoStr=");
	ln=strlen(gets(CoStr));
	do
	{
		fseek(fp,-i,SEEK_CUR);
		for(i=0;i<ln;i++)
		if((ch=getc(fp))!=CoStr[i]) 
		break;
	if(ch==EOF)
	{
		printf("没有发现特定字符串%s!\n",CoStr);
		exit(0);
	}
	}
	while(i<ln);
	if(!(pW=fopen("XYZ.txt","w")))
	{
	printf("创建目标文件失败...");
	exit(0);
	}
	while((ch=getc(fp))!='"' && ch!=(char)176);
	while((ch=getc(fp))!='"' && ch!=(char)177)
	{
	if(ch=='\n' || ch==' ') continue;
	putc(ch,pW);
	}

fclose(pW);
fclose(fp);
printf("文件已成功建立，名为XYZ.txt\n");
}

