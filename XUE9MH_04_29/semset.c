#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs

	int semid,	// Szemafor azonosító
	    nsems,	// Szemaforok száma
	    semnum,	// Szemafor száma
	    rtn;	// Visszatérési érték

	int semflg;	// Flag
	struct sembuf sembuf, *sop;
    union semun;

	int cmd;	// semctl()-nek szóló parancs változója

int main()
{

    int arg;


	nsems = 1;	// Egyetlen szemafor a set-ben
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror("semget() hiba!\n"); exit(0);}
	else printf("\n Az azonosító: %d\n",semid);
	printf ("Kérem a semval erteket: ");

	semnum = 0;	// 0. szemafort azonosítom

	cmd = SETVAL;	// Állítsd be a szemafor érteket
	scanf("%d", &arg);
	rtn = semctl(semid, semnum, cmd, arg); // Semid-vel azonosított set 0-ik szemafor

	printf("\nVisszatérési érték: %d\nSemval értéke: %d\n",rtn, arg);

    return 0;

}
