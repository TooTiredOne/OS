#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

__ino_t  checked[20];
int need_to_print[20];


//if a link with i-node n was already met\checked
int was_checked(__ino_t n, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(n == checked[i])
            return 1;
    }

    return 0;
}


int main()
{
    FILE *ouput = fopen("ex4.txt", "w"); //opening output file
    DIR *dirp = opendir("./temp"); //opening temp folder
    __ino_t inodes[20]; //to store inodes of files
    char *names[20]; //to store names of files

    if(dirp == NULL)
    {
        printf("no such directory exists\n");
        return -1;
    }

    struct dirent *dp;
    int count = 0, c = 0, c2 = 0; //counters with creative names

    //reading file names from stored in temp
    while((dp = readdir(dirp)) != NULL)
    {
        names[count] = calloc(strlen(dp->d_name), sizeof(char)); //reserving a space for a filename
        //acquiring file name and inode to which it points
        names[count] = dp->d_name; 
        inodes[count] = dp->d_ino;
        count++;
    }

    //finding i-nodes with 2 or more hard links
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
                    need_to_print[c] = j; //marking the file for printing
                    c++;
                    break;
                }
            }
        }
    }

    //printing those i-nodes
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < count; j++)
        {
            if(inodes[j] == inodes[need_to_print[i]])
            {
                fprintf(ouput, "%s ", names[j]);
            }
        }

        fprintf(ouput, ":%ld\n", inodes[i]);
    }


    closedir(dirp);
    fclose(ouput);


    return 0;
}