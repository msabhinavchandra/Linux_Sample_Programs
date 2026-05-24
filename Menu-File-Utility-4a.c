#include <stdio.h>
#include <sys/stat.h>

int main()
{
    int ch;
    char name[50];
    FILE *fp;

    printf("1.Create File\n2.Read File\n3.Delete File\n4.Create Directory\n5.Delete Directory\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter file name: ");
        scanf("%s", name);
        fp = fopen(name, "w");
        fclose(fp);
        break;

    case 2:
        printf("Enter file name: ");
        scanf("%s", name);
        fp = fopen(name, "r");
        if (fp)
            printf("File opened for reading\n");
        fclose(fp);
        break;

    case 3:
        printf("Enter file name: ");
        scanf("%s", name);
        remove(name);
        break;

    case 4:
        printf("Enter directory name: ");
        scanf("%s", name);
        mkdir(name, 0777);
        break;

    case 5:
        printf("Enter directory name: ");
        scanf("%s", name);
        rmdir(name);
        break;
    }

    return 0;
}
