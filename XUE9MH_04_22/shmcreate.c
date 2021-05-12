#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 123456L


int main(void) {
    int shmid;
    key_t key = SHM_KEY;
    int size = 200;
    int shmflg = 0;

    shmid = shmget(key, size, shmflg);

    if (shmid < 0) {
        shmflg = 00666 | IPC_CREAT;
        shmid = shmget(key, size, shmflg);
        if (shmid < 0) {
            perror("shmget hívás hiba\n");
            return -1;
        }
    } else {
        printf("a szegmens már létrejött\n");
    }
    printf("A kellő ID: %d\n", shmid);

  return 0;
}
