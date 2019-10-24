#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

__ino_t  checked[20];
int need_to_print[20];

int was_checked(__ino_t n, int size)
{
    for(int i = 0; i < n; i++)
    {
        if(n == checked[i])
            return 1;
    }

    return 0;
}


int main()
{
    DIR *dirp = opendir("temp");
    printf("HI");
    __ino_t inodes[20];
    char *names[20];

    if(dirp == NULL)
    {
        printf("no such directory exists\n");
        return -1;
    }

    struct dirent *dp;
    int count = 0, c = 0, c2 = 0;

    while((dp = readdir(dirp)) != NULL)
    {
        names[count] = calloc(strlen(dp->d_name), sizeof(char));
        names[count] = dp->d_name;
        inodes[count] = dp->d_ino;
        count++;
    }

    for(int i = 0; i < count-1; i++)
    {
        if(!was_checked(inodes[i], c2))
        {
            checked[c2] = inodes[i];
            c2++;
            for(int j = i + 1; j < count; j++)
            {
                if(inodes[i] == inodes[j])
                {
                    need_to_print[c] = j;
                    c++;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < c; i++)
    {
        if(need_to_print[i])
        {
            for(int j = 0; j < count; j++)
            {
                if(inodes[j] == inodes[need_to_print[i]])
                {
                    printf("%s ", names[j]);
                }
            }

            printf(":%ld\n", inodes[i]);
        }
    }


    return 0;
}