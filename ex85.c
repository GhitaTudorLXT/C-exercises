#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

#define MAX_PATH 1024

void dirwalk(char *name, void (*fcn)(char*))
{
	DIR *dir;
	struct dirent *drent;

	char dirname[MAX_PATH];

	dir = opendir(name);

	if (dir == NULL)
	{
		printf(" Error opening directory %s \n", name);
		return;
	}

	while ((drent = readdir(dir)) != NULL)
	{
		if (strcmp(drent->d_name, ".") == 0 || strcmp(drent->d_name, "..") == 0)
			continue;

		sprintf(dirname, "%s/%s", name, drent->d_name);

		fcn(dirname);
	}

	closedir(dir);
}

void fsize(char *name)
{
	struct stat stinf;

	if (stat(name, &stinf) == -1)
	{
		printf("\n Cannot open file \n\n");
		return;
	}

	if ((stinf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);

	printf("%s: \n", name);
	printf(" Size: %ld \n", stinf.st_size);
	printf(" Inode: %lu \n", stinf.st_ino);
	printf(" UID: %u \n", stinf.st_uid);
	printf(" GID: %u \n", stinf.st_gid);
	printf(" Last access: %s", ctime(&stinf.st_atime));
	printf(" Last modification: %s", ctime(&stinf.st_mtime));
	printf(" Created: %s", ctime(&stinf.st_ctime));
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("\n Usage: ex85 [filename]\n\n");

		return 0;
	}

	fsize(argv[1]);

	return 0;
}