#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
void _a(int argc, char *argv[])
{
	DIR *mydir;
	FILE *fp;
	int i=0;
	char c;
   	struct dirent *myfile;
	if(argc == 2)
	{
	    	mydir = opendir("./");
		while((myfile = readdir(mydir)) != NULL)
			printf("%s\t", myfile->d_name);
		printf("\n");
		closedir(mydir);
    	}	
	else if(argc>2)
	{
		for (i=2;i<argc;i++)
		{
			mydir = opendir(argv[i]);
			if(mydir==NULL)
			{
				fp=fopen(argv[i],"r");
				if(fp==NULL)
					printf("ERROR!!!NO such file or directory\n");
				else
					printf("%s\n",argv[i]);
				return;
			}
			while((myfile = readdir(mydir)) != NULL)
				printf("%s\t", myfile->d_name);
			printf("\n");
			closedir(mydir);
		}
	}
}
