// GPX 数据的导出.cpp : 定义控制台应用程序
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int c;
	int j;
	char lat[80],lon[80],time[80];
	int i=0;
	char *str;
	FILE*fp,*fp1;
	fp=fopen("export.gpx","r");
	fp1=fopen("wangjiashun.csv","w");
    if(fp==NULL)
	{
		printf("Can not open this file!\n");
		return(-1); 
	}
	else
	{
	fseek(fp,0,SEEK_END);
	c=ftell(fp);
	fseek(fp,SEEK_CUR,SEEK_SET);
	str=(char*)malloc(c);
	fread(str,1,c,fp);
		while(!((*(str+i)=='<')&&(*(str+i+1)=='/')&&(*(str+i+2)=='g')&&(*(str+i+3)=='p')&&(*(str+i+4)=='x')&&(*(str+i+5)=='>')))
		{
			if(*(str+i)==' '&&*(str+i+1)=='l'&&*(str+i+2)=='a'&&*(str+i+3)=='t')
			{
			
				strncpy(lat,str+i+6,9);
				lat[9]='\0';
				printf("lat=%s,",lat);
				strncpy(lon,str+i+4+19,9);
				lon[9]='\0';
				printf("lon=%s,",lon);
				strncpy(time,str+i+4+19+21,20);
				time[20]='\0';
				printf("time=%s\n",time);
				fprintf(fp1,"%s,%s,%s\n",lat,lon,time);
		    }
			i++;
				
		}
		fclose(fp);
		fclose(fp1);
	}
	return 0;
}
