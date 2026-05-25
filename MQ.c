#include <stdio.h>
#include <sys/msg.h>
#include <string.h>

struct msg
{
    long type;
    char text[50];
};

int main()
{
    int id;
    struct msg m;

    id = msgget(1, IPC_CREAT| 0666);

    m.type = 1;

    strcpy(m.text, "Hello");

    msgsnd(id, &m, sizeof(m.text), 0);

    msgrcv(id, &m, sizeof(m.text), 1, 0);

    printf("%s\n", m.text);

    msgctl(id, IPC_RMID, 0);

    return 0;
}