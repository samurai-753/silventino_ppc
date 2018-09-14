#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int NUM_THREADS = 5;

int TAM_ARRAY = 5;
int A[] = {1,2,3,4,5};
int B[] = {10,20,30,40,50};
int C[5];

void *somaPosicao(void* pos)
{
   long t = (long) pos;
   // printf("%lu\n", t);
   C[t] = A[t] + B[t];
}



int main (int argc, char *argv[])
{
   
   int tamanho = 0;
   if(NUM_THREADS > TAM_ARRAY){
      tamanho = TAM_ARRAY;
   }
   else{
      tamanho = NUM_THREADS;
   }

   pthread_t threads[tamanho];
   int rc;
   long t;

   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, somaPosicao, (void*)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   for(t=0; t<NUM_THREADS; t++){
      pthread_join(threads[t],NULL);
   }


   ////// PRINTANDO OS VETORES A B ////////
   printf("\nVetor A: ");
   for(t=0; t<NUM_THREADS; t++){
      printf("%d ", A[t]);
   }
   printf("\n");

   printf("\nVetor B: ");
   for(t=0; t<NUM_THREADS; t++){
      printf("%d ", B[t]);
   }
   printf("\n");
   ////////////////////////////////////////


   printf("\nVetor C resultante: ");
   for(t=0; t<NUM_THREADS; t++){
      printf("%d ", C[t]);
   }
   printf("\n");

   pthread_exit(NULL);
}

 
