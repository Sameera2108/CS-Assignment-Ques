#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f1,*f2;
    char file1[200],file2[200], c;
    printf("Please enter the file name to open for reading \n");
    scanf("%s", file1);
    printf("Please enter the file name to open for writing \n");
    scanf("%s", file2);
    f1=fopen(file1,"r");
    f2=fopen(file2,"w");
    if(f1!=NULL )
    {
        if(f2!=NULL)
        {
            c = fgetc(f1);
            while (c != EOF)
            {
                fputc(c, f2);
                c = fgetc(f1);
            }
          
            fclose(f1);
            fclose(f2);
            printf("copied from one file to another");
        }
        else
        printf("mission unsuccessful1");
    }
    else printf("mission unsuccessful");
    
}
