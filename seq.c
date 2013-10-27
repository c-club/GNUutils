#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int first=1,increment=1,last=0; 
	int i=0;
	if(argc==2)
	{
		/*if(argv[1][1]<'0'||argv[1][1]>'9')
		{
			printf("ERROR!!!\n");
			return 0;
		}*/
		last=atoi(argv[1]);
	}
	else if(argc == 3)
	{
		/*if(argv[1][1]<'0'||argv[1][1]>'9'||argv[2][1]<'0'||argv[2][1]>'9')
		{
			printf("ERROR!!!\n");
			return 0;
		}*/
		first=atoi(argv[1]);
		last= atoi(argv[2]);
	}
	else if(argc==4)
	{
		/*if(argv[1][1]<'0'||argv[1][1]>'9'||argv[2][1]<'0'||argv[2][1]>'9'||argv[3][1]<'0'||argv[3][1]>'9')
		{
			printf("ERROR!!!\n");
			return 0;
		}*/
		first=atoi(argv[1]);
		increment=atoi(argv[2]);
		last= atoi(argv[3]);
	}
	else
	{
		printf("ERROR!!!\n");
		return 0;
	}
	for(i=first;i<=last;i+=increment)
		printf("%d\n",i);
}
