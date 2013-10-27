#include <stdio.h>
int main(int argc, char * argv[])
{
	FILE * fp;
	int c,i=0;
	if(argc==1)
		while((c=getchar())!=EOF)
			putchar(c);
	else
	{
		for(i=1;i<argc;i++)
		{
			fp=fopen(argv[i],"r");
			while((c=fgetc(fp))!=EOF)
				putchar(c);
			fclose(fp);
		}
	}
}
