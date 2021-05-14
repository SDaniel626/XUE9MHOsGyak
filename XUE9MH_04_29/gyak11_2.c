#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t m;

void* thread(void* arg)
{
    //wait
    sem_wait(&m);
    printf("A pidem: %d\nVárakozás...\n", getpid());  // PID kiíratás
    sleep(3);   // Várakozás
    sem_post(&m);
}

int main()
{
    sem_init(&m, 0, 1);
    pthread_t t1,t2,t3;  // 3 feladat
    pthread_create(&t1, NULL,thread,NULL);
    pthread_create(&t2, NULL,thread,NULL);
	pthread_create(&t3, NULL,thread,NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
	pthread_join(t3, NULL);
    sem_destroy(&m);    // Megszüntetés
    return 0;
}
