#include<stdio.h>
int main()
{
	FILE *fp;
	char ch;
	fp=fopen("score.txt","r");
	if(fp==NULL)
	{
		printf("���ļ����󣬿���Ҫ�򿪵��ļ�������");
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
		fclose(fp);//�ر��ļ�
	}
	ruturn 0;
}