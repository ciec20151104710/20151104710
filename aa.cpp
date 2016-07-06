#include"stdafx.h"
#include"stdlib.h"

int _tmain(int argc,_TCHAR* argv[])
{
	FILE*fp;
	int flen=0;
	char *str;
	printf("str len=%d",sizeof(str));
	if((fp=fopen("e:\\test\\abc.txt","r"))==0);
	{
		printf("Can not open file!\n");
		return -1;
	}
	fseek(fp,0,SEEK_END);
	flen=ftell(fp);
	fseek(fp,0,SEEK_SET);
	str=(char *)malloc(1*flen);
	fread(str,1,flen,fp);
	printf("len=%d    %c\n",flen,str[0]);
	fclose(fp);
	return 0;
}

