#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 123456L


int main(void) {
    int shmid;
    key_t key = SHM_KEY;
    int size=200;
    int shmflg = 0;
    struct shmid_ds stat;

    if (shmid < 0) {
        perror("shmget hívás hiba\n");
        return -1;
    }

    shmid = shmget(key, size, shmflg);
    shmctl(shmid, IPC_RMID, NULL);
    shmctl(shmid, IPC_STAT, &stat);
    printf("Szegmens méret: %d\n", (int)stat.shm_segsz);
    printf("Utolso muvelet: PID %d\n", stat.shm_lpid);




  return 0;
}
