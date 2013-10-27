#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char* argv[])
{
	DIR *mydir;
	FILE *fp;
	int i=0;
	char c;
   	struct dirent *myfile;
	if(argc == 1)
	{
		  	mydir = opendir("./");
			while((myfile = readdir(mydir)) != NULL)
				if(myfile->d_name[0]!='.')
					printf("%s\t", myfile->d_name);
			printf("\n");
			closedir(mydir);
		
    	}	
	else if(argc>1)
	{
		if(argv[1][0]=='-')
		{
			c=argv[1][1];
			switch(c)
			{
				case 'a':if(argv[1][2]=='\0')
						_a(argc,argv);
					else
						_al(argc,argv);
					break;
					printf("HEY\n");
				case 'l': _l(argc,argv);
					break;
				default: printf("ERROR!!! No such options");
			}
		}
		else
		{
			for (i=1;i<argc;i++)
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
					if(myfile->d_name[0]!='.')
						printf("%s\t", myfile->d_name);
				printf("\n");
				closedir(mydir);
			}
		}	
	}
}
