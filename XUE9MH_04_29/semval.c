#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs


	int semid,nsems,rtn;
	int semflg;
	struct sembuf sembuf, *sop;
	union semun arg;
    union semun {
        int val;
    struct semid_ds *buf;
        unsigned short int *array;
         };
	int cmd;

int main()
{


	nsems = 1;
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror("semget() hiba!\n"); exit(0);}
	else printf("Azonosító: %d\n",semid);


	cmd = GETVAL;	// Szemafor árteket ad vissza majd az rtn-ben
	rtn = semctl(semid,0, cmd, NULL);

	printf("Semval kiolvasott értéke: %d ",rtn);
	printf("\n");

    return 0;

}
