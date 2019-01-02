#include <stdio.h>
#include <stdlib.h>
#include <io.h>

int main()
{
    long Handle;
    struct _finddata_t FileInfo;
    if((Handle = _findfirst("*.*", &FileInfo)) == -1L)
        printf("Not found\n");
    else
    {
        printf("%s\n", FileInfo.name);
        while(_findnext(Handle, &FileInfo) == 0)
            printf("%s\n", FileInfo.name);
        _findclose(Handle);
    }
    return 0;
}
