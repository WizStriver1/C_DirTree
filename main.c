#include <stdio.h>
#include <stdlib.h>
#include <io.h>

char *getAbsltPath(char *first, char *last)
{
    char *slashes = "\\";
    char *ap = (char *) malloc(strlen(first) + strlen(slashes) + strlen(last));
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
    if((Handle = _findfirst(findpath, &FileInfo)) == -1L)
        printf("Not found\n");
    else
    {
        while(_findnext(Handle, &FileInfo) == 0)
        {
            char *recentPath = getAbsltPath(dirpath, FileInfo.name);
            printf("%s--%u\n", FileInfo.name, FileInfo.attrib);
            // if((strcmp(FileInfo.name, "..") != 0))
            // {
                // if(FileInfo.attrib == _A_SUBDIR)
                // {
                //     char *recentDirpath = getAbsltPath(dirpath, &(FileInfo.name));
                //     generateDirTree(recentDirpath);
                // }
                // else
                // {
                //     char *recentPath = getAbsltPath(dirpath, &(FileInfo.name));
                //     printf("%s--%u\n", recentPath, FileInfo.attrib);
                // }
            // }
        }
        _findclose(Handle);
    }
}

int main(int argc, char *argv[])
{
    char dirpath[] = "D:\\DevEnvironment\\CTestDir_Tempspace";
    generateDirTree(dirpath);
    return 0;
}
