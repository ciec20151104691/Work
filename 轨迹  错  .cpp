#include<stdio.h>
int main()
{

	FILE *fp1,*fp2;
	char str[50];
	fp1=fopen("export.txt","r");
	fp2=fopen("eoport-a.gpx","w");
	if(fp1==NULL)
	{
		printf("���ļ�����!�����ļ�������");
	}
	else
	{
		while(fscanf(str,fp2)!=NULL)
		{    
			printf("%s",str);
			fputs(str,fp2);
		}
		fclose(fp1);
		fclose(fp2);
	}
	return 0;
}
