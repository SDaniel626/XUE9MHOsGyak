#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs

	int semid, nsems, rtn;
	unsigned nsops;	// Ezzel adjuk meg, hány struktúrával foglakozzon
	int semflg;
	struct sembuf sembuf, *sop;


int main()
{


	nsems = 1;
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror("semget() hiba!\n"); exit(0);}
	else printf("Azonosító: %d\n",semid);
	printf ("\n");

	nsops = 1;		//Egy művelet van
	sembuf.sem_num = 0;	//A 0-ik szemaforral foglakozunk
	sembuf.sem_op = 1;	// Növelés
	sembuf.sem_flg = 0666;	// Flag beállítás
	sop = &sembuf;		// Argumentum kérése
	rtn = semop(semid, sop, nsops); // A 0-val visszatérő semop sikeres.
	printf("Visszatérési érték: %d\n",rtn);

    return 0;

}
