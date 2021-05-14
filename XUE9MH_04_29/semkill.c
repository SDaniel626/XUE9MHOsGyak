#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x10  // Kulcs


	int semid, nsems, rtn;
	int semflg;
	struct sembuf sembuf, *sop;
	union semun {
        int val;
    struct semid_ds *buf;
        unsigned short int *array;
         };
	int cmd;

int main()
{

    int arg;
	nsems = 1;
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror("semget() hiba!\n"); exit(0);}
	else printf("semid értéke: %d\n",semid);

	cmd = IPC_RMID;		// Ezzel szüntetjük meg
	rtn = semctl(semid, 0, cmd, arg);

	printf("Kill visszatérés: %d\n",rtn);

    return 0;

}
