#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
void _l(int argc,char * argv[])
{
	DIR *mydir;
	FILE *fp;
	int i=0;
   	struct dirent *myfile;
	struct stat stats;
	time_t timer;
	char buf[512];
	struct passwd  *pwd;
	struct group   *grp;
	char *time;
	int j=0;
	if(argc == 2)
	{
	    	mydir = opendir("./");
		while((myfile = readdir(mydir)) != NULL)
		{
			if(myfile->d_name[0]!='.')
			{
				sprintf(buf,"%s/%s","./",myfile->d_name);
				stat(buf,&stats);
				pwd = getpwuid(stats.st_uid);
				grp = getgrgid(stats.st_gid);
				printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
			    	printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
	    			printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
				printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
				printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
				printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
				printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
				printf( (stats.st_mode & S_IROTH) ? "r" : "-");
				printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
				printf( (stats.st_mode & S_IXOTH) ? "x" : "-");
				printf(" ");
				printf("%2d ",stats.st_nlink);
			        printf("%-8.8s ", pwd->pw_name);
		       		printf("%-8.8s ", grp->gr_name);
		       		printf("%5d ",stats.st_size);
				timer=stats.st_mtime;
				time=asctime(localtime(&timer));
				time[strlen(time)-1]='\0';
				printf("%s ",time);
				printf("%s\n", myfile->d_name);
			}
		}
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
			{
				if(myfile->d_name[0]!='.')
				{
					sprintf(buf,"%s/%s",argv[i],myfile->d_name);
					stat(buf,&stats);
					pwd = getpwuid(stats.st_uid);
					grp = getgrgid(stats.st_gid);
					printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
			    		printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
	    				printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
					printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
					printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
					printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
					printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
					printf( (stats.st_mode & S_IROTH) ? "r" : "-");
					printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
					printf( (stats.st_mode & S_IXOTH) ? "x" : "-");
					printf(" ");
					printf("%2d ",stats.st_nlink);
				        printf("%-8.8s ", pwd->pw_name);				
			       		printf("%-8.8s ", grp->gr_name);
		       			printf("%5d ",stats.st_size);
					timer=stats.st_mtime;
					time=asctime(localtime(&timer));
					time[strlen(time)-1]='\0';
					printf("%s ",time);
					printf("%s\n", myfile->d_name);
				}
			}
    		closedir(mydir);
		}
	}
}
