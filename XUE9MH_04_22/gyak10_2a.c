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


    key = ftok("gyak10_2_create.c", 65);
    msg_id = msgget(key, 0664 | IPC_CREAT);
    message.msg_type = 1;

    int ok= 0;



    while (ok==0) {

        printf("Kerem az uzenetet: \n");

        fgets(message.msg_text, MAX, stdin);
        if (strcmp(message.msg_text, "exit\n")==0) {
            ok = 1;
            continue;
        }
        msgsnd(msg_id, &message, sizeof(message), 0);
        printf("Uzenet elkuldve: %s", message.msg_text);
    }



  return 0;
}
