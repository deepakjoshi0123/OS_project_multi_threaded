#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
int rCount=0;
void *Reader(void *arg);
void *Writer(void *arg);

sem_t read_counter;
sem_t database;

int main()
{
int i=0,no_read_thread=5,no_write_thread=5;  // no. of readers is 5 no. of writers is 5
sem_init(&read_counter,0,1);       //semaphore intialization
sem_init(&database,0,1);           //semaphore intialization
 
pthread_t read_thread[10],Writer_thr[10];    // decalring thread

for(i=0;i<no_read_thread;i++)
pthread_create(&read_thread[i],NULL,Reader,(void *)i);      // creating readers thread

for(i=0;i<no_read_thread;i++)
pthread_create(&Writer_thr[i],NULL,Writer,(void *)i);      // creating writers thread  

for(i=0;i<no_read_thread;i++)
pthread_join(Writer_thr[i],NULL);                   // joining writers thread

for(i=0;i<no_read_thread;i++)
pthread_join(read_thread[i],NULL);                  // joinng  readers thread  

sem_destroy(&database);
sem_destroy(&read_counter);
return 0;
}

void * Writer(void *arg)
{
sleep(2);
int temp=(int)arg;
printf("\nWriter %d is trying to enter into database for modifying the data",temp);
sem_wait(&database);         // decrements  the semaphore pointed to by semaphore
printf("\nWriter %d is writting into the database",temp);
printf("\nWriter %d is leaving the database");
sem_post(&database);          //atomically increment the semaphore pointed to by semaphore 
}

void *Reader(void *arg)
{
sleep(2);
int temp=(int)arg;
printf("\nReader %d is trying to enter into the Database for reading the data",temp);
sem_wait(&read_counter);   // decreasing value of semaphore
rCount++;                   // counter increment 
if(rCount==1)
{
sem_wait(&database);
printf("\nReader %d is reading the database",temp);
}
//

//
sem_post(&read_counter);       //atomically increment the semaphore pointed to by semaphore 
sem_wait(&read_counter);       //decrements  the semaphore pointed to by semaphore
rCount--;
if(rCount==0)
{
printf("\nReader %d is leaving the database",temp);
sem_post(&database);        //atomically increment the semaphore pointed to by semaphore  
}
sem_post(&read_counter); //atomically increment the semaphore pointed to by semaphore 

//5 readers 5 writers 
//readers writers problem solution using semaphore
