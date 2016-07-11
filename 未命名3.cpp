#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int flen;
	char str;
	fp=fopen("e\\export.txt","r");
	if(fp==NULL)
	{
		printf("Can't open this file!\n");
		return -1;
	}
	char *ptr1="<?xml version=1.0 encoding=UTF-8 standalone=no ?><gpx xmlns= creator=GPX Recorder version=1.1 xmlns:xsi= xsi:schemaLocation= <metadata><link href= <text>public-pin.for-the.biz</text></link><time>2014-06-02T18:08:57Z</time><bounds maxlat=40.990091 maxlon=112.464258 minlat=40.771599 minlon=111.674840/></metadata>"
    char s[13];
    int i=0;
    while(!((*(ptr1+i)=='m')&&(*(ptr1+i+1)=='a')&&(*(ptr1+i+2)=='x')&&(*(ptr1+i+3)=='l')&&(*(ptr1+i+4)=='a')))
    {
    	i++;
    }
    strncpy(s,prl1+i+7,9);
    s[9]='\0';
    printf("%s\n",s);
    strncpy(s,prl1+i+26,10);
    s[10]='\0';
    printf("%s\n",s);
	fseek(fp,0,SEEK_END);
	flen=ftell(fp);
	fseek(fp,0,SEEK_SET);
	str=(char *)malloc(1*flen);
	fread(str,1,flen,fp);
	printf("len=%d     %c\n",flen,str[0]);
	free(fp);
	fclose(fp);
	return 0;
}
