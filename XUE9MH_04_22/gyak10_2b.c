#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 100

struct msg_buffer {
  long msg_type;
  char msg_text[100];
} message;

int main(void) {
    key_t key;
    int msg_id;

    key = ftok("gyak10_2.c", 65);
    msg_id = msgget(key, 0664 | IPC_CREAT);

    struct msqid_ds stat;
    //msgctl(msg_id, IPC_RMID, NULL);
    msgctl(msg_id, IPC_STAT, &stat);
    printf("Az uzenetek darabszama jelenleg: %d\n", (int)stat.msg_qnum);
    return 0;
}
