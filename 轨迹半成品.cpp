#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <graphics.h>    // 绘图库头文件，绘图语句需要
#include <conio.h>    // 控制台输入输出头文件，getch()语句需要
int main()
{
	char *content;
	int l;
	int i=0,j=0;
	char lat[10];
	char lon[11];
	char date[11];
	char time[9];
	FILE *fp,*fp1;
  
	fp=fopen("export.gpx","r");
	fp1=fopen("export.csv","w");
	if(fp==NULL)
	{
		printf("打开文件错误！");
		return -1;
	}
	else
	{
		fseek(fp,SEEK_SET,SEEK_END);
	    l=ftell(fp);
	    fseek(fp,0,SEEK_SET);
	    content=new char[l+1];
	    fread(content,sizeof(char),l,fp);
	    content[l]='\0';
	}
	fprintf(fp1,"序号,纬度,经度,日期,时间\n");
	while(!(content[i]=='<'&&content[i+1]=='/'&&content[i+2]=='g'&&content[i+3]=='p'&&content[i+4]=='x'&&content[i+5]=='>'))
	{
		if(content[i]==' '&&content[i+1]=='l'&&content[i+2]=='a'&&content[i+3]=='t')
		{
			strncpy(lat,&content[i+6],9);
		    strncpy(lon,&content[i+22],10);
		    strncpy(date,&content[i+44],10);
		    strncpy(time,&content[i+55],8);
		    lat[9]='\0';
		    lon[10]='\0';
		    date[10]='\0';
		    time[8]='\0';
		    printf("%d,%s,%s,%s,%s\n",j+1,lat,lon,date,time);
		    fprintf(fp1,"%d,%s,%s,%s,%s\n",j+1,lat,lon,date,time);
		    j++;
		}
		i++;
	initgraph(640, 480); // 初始化640x480的绘图屏幕    
	line(200, 240, 440, 240); // 画线(200,240) - (440,240)    
	line(320, 120, 320, 360); // 画线(320,120) - (320,360)    
	getch();    // 按任意键    
	closegraph();    // 关闭绘图屏幕	
	}
	fclose(fp);
	fclose(fp1);
	
	return 0;
}
