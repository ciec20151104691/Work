#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	FILE *fp,*pw;
	char *s;
	long int l,a,b;
	long int i,j;
	char lat[10];
	char lon[11];
	char date[11];
	char time[9];
	if(!(fp=fopen("export.gpx","r")))
	{
		printf("�ļ���ʧ��");
		exit(0);
	}

	fseek(fp,0,SEEK_END);
	a=ftell(fp);
	s=(char *)malloc(a);
	do
	{
		fseek(fp,-i,SEEK_CUR);
		for(i=0;i<l;i++)
		if((i=getc(fp))!=s[i]) 
		break;
	if(i==EOF)
	{
		printf("û�з����ض��ַ���!\n");
		exit(0);
	}
	}
	while(i<l);
/*	if(!(pw=fopen("XYZ.txt","w")))
	{
	printf("����Ŀ���ļ�ʧ��...");
	exit(0);
	}
	while((ch=getc(fp))!='"' && ch!=(char)176);
	while((ch=getc(fp))!='"' && ch!=(char)177)
	{
	if(ch=='\n' || ch==' ') continue;
	putc(ch,pw);
	}

fclose(pw);
fclose(fp);
printf("�ļ��ѳɹ���������ΪXYZ.txt\n");
	return 0;
}*/
	while(!(s[i]=='<'&&s[i+1]=='/'&&s[i+2]=='g'&&s[i+3]=='p'&&s[i+4]=='x'&&s[i+5]=='>'))
	{
		if(s[i]==' '&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='t')
		{
			strncpy(lat,&s[i+6],9);
		    strncpy(lon,&s[i+22],10);
		    strncpy(date,&s[i+44],10);
		    strncpy(time,&s[i+55],8);
		    lat[9]='\0';
		    lon[10]='\0';
		    date[10]='\0';
		    time[8]='\0';
            size_t len = strlen(lat) + 1;
	        size_t converted = 0;
		    fprintf(pw,"%d,%s,%s,%s,%s\n",j,lat,lon,date,time);
		    j++;
		}
		i++;	
	}
	return 0;
}
