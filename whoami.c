#include <pwd.h>
#include <sys/stat.h>
int main()
{
	struct stat stats;
	stat("./",&stats);
	struct passwd  *pwd;
	pwd = getpwuid(stats.st_uid);
        printf("%-8.8s\n", pwd->pw_name);
}
