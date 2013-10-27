#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
void main(int argc, char *argv[])
{
	char line[128];
	int l=0,i=0,k=0,j;
	char *file;
	char s1[20];
	char *s;
	s=argv[1];
	file=argv[2];
	FILE *fp=fopen(file,"r");	
	if(fp!=NULL)
	{
		while(fgets(line,sizeof(line),fp)!=NULL)
		{	
			k=0;
			l=strlen(line);
			for (i=0;i<l;i++)
			{
				s1[k]=line[i];
				k++;
				if(k==strlen(s) && strcmp(s,s1)==0)
				{
					fputs(line,stdout);
					break;
				}
				if(k==strlen(s))
				{
					k--;
					for(j=0;j<strlen(s)-1;j++)
						s1[j]=s1[j+1];
				}
			}			
		}
		fclose(fp);
	}
	else
		printf("wrong file");
}
