#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char *a;
	a=(char *malloc(100);
	FILE *fp=fopen("export.txt","r");
	while(fgets(a,100,fp))
	{
		printf("%s",a);
	}
	fclose(fp);
	free(a);
 } 
