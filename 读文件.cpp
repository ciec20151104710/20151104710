#include<stdio.h>
int main()
{
	FILE *fp;
	char ch;
	fp=fopen("score.txt","r");
	if(fp==NULL)
	{
		printf("打开文件错误，可能要打开的文件不存在");
		exit(-1);
    }
	else
	{
		ch=fgetc(fp);
		while(ch!=EOF)
		{
			printf("%c",ch);
			ch=fgetc(fp);
		}
		fclose(fp);//关闭文件
	}
	ruturn 0;
}