#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGKEY 654321L

struct msgbuf1 {
	long mtype;
	char mtext[512];
} rcvbuf, *msgp;

struct msqid_ds ds, *buf;

int main()
{
	int msgid;
	key_t key;
	int mtype, msgflg;
	int rtn, msgsz;

	key = MSGKEY;
	msgflg = 00666 | IPC_CREAT | MSG_NOERROR;

	msgid = msgget( key, msgflg);
 	if ( msgid == -1) {
                perror("\n The msgget system call failed!");
                exit(-1);
        }
	printf("\n Az msgid: %d",msgid);

	msgp = &rcvbuf;
	buf = &ds;
	msgsz = 20;
	mtype = 0;
	rtn = msgctl(msgid,IPC_STAT,buf);
	printf("\n Az uzenetek szama: %d",buf->msg_qnum);

	while (buf->msg_qnum) {

		rtn = msgrcv(msgid,(struct msgbuf *)msgp, msgsz, mtype, msgflg);
		printf("\n Az rtn: %d,  a vett uzenet:%s\n",rtn, msgp->mtext);
		rtn = msgctl(msgid,IPC_STAT,buf);
	}
	exit (0);
}
