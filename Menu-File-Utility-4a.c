#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int ch, fd;
    char name[50], data[100];

    printf("1.Create File\n");
    printf("2.Read File\n");
    printf("3.Delete File\n");
    printf("4.Create Directory\n");
    printf("5.Delete Directory\n");

    printf("Enter choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            printf("Enter file name: ");
            scanf("%s", name);

            fd = open(name, O_CREAT | O_RDWR, 0777);

            if(fd >= 0)
                printf("File created successfully\n");

            close(fd);
            break;

        case 2:
            printf("Enter file name: ");
            scanf("%s", name);

            fd = open(name, O_RDONLY);

            if(fd >= 0)
            {
                read(fd, data, sizeof(data));
                printf("File Content:\n%s\n", data);
                close(fd);
            }
            else
            {
                printf("File not found\n");
            }

            break;

        case 3:
            printf("Enter file name: ");
            scanf("%s", name);

            unlink(name);

            printf("File deleted\n");
            break;

        case 4:
            printf("Enter directory name: ");
            scanf("%s", name);

            mkdir(name, 0777);

            printf("Directory created\n");
            break;

        case 5:
            printf("Enter directory name: ");
            scanf("%s", name);

            rmdir(name);

            printf("Directory deleted\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}