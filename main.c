#include <stdio.h>
#include <stdlib.h>
#include <io.h>
char *getAbsltPath(char *first, char *last);
void generateDirTree(char *dirpath);

int main(int argc, char *argv[])
{
	char dirpath[] = "E:\\Python-Server\\Workspace\\nginx\\html";
	getch();
	generateDirTree(dirpath);
	getch();
	return 0;
}

char *getAbsltPath(char *first, char *last)
{
	char *slashes = "\\";
	char *ap = (char *)malloc(strlen(first) + strlen(slashes) + strlen(last));
	strcpy(ap, first);
	strcat(ap, slashes);
	strcat(ap, last);
	return ap;
}

void generateDirTree(char *dirpath)
{
	long Handle;
	struct _finddata_t FileInfo;
	char findrule[] = "*.*";
	char *findpath = getAbsltPath(dirpath, findrule);
	printf("%s--%d\n", dirpath, _A_SUBDIR);
	if ((Handle = _findfirst(findpath, &FileInfo)) == -1L)
		printf("Not found\n");
	else
	{
		while (_findnext(Handle, &FileInfo) == 0)
			if (strcmp(FileInfo.name, "..") != 0 && strcmp(FileInfo.name, "plugin") != 0 && strcmp(FileInfo.name, "images") != 0 && strcmp(FileInfo.name, "uploads") != 0)
				if (FileInfo.attrib == _A_SUBDIR)
				{
					char *recentDirpath = getAbsltPath(dirpath, &(FileInfo.name));
					generateDirTree(recentDirpath);
				}
				else
				{
					char *recentPath = getAbsltPath(dirpath, &(FileInfo.name));
					printf("%s--%u\n", recentPath, FileInfo.attrib);
				}
		_findclose(Handle);
	}
}
