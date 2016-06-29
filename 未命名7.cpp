#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	FILE *fp=fopen("export.txt","r");
	while(fgets(b,100,fp))
	{
		strcpy(a,b);
		printf("%s",a);
	}
	fclose(fp);
}
