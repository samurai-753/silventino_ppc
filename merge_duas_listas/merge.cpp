#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int NUM_THREADS = 10;
int TAM_ARRAY = 10;
int A[] = {1,3,5,7,9, 2,4,6,8,10};
int C[10];

void *somaPosicao(void* pos)
{
    int n = TAM_ARRAY;
    int low = 0;
    int high = n/2 -1;
    long i = (long) pos;
    if(i < (n/2)){
        low = n/2;
        high = n-1;
    }
    // else{
    //     low = 0;
    //     high = n/2 - 1;
    // }

    int x = A[i];
    int index;
    do{
        index = (low+high)/2;
        if(x < A[index]){
            high = index - 1;
        }
        else{
            low = index + 1;
        }
    } while (low <= high);
    C[high+i+1-n/2] = x;
}



int main (int argc, char *argv[])
{
   
//    int tamanho = 0;
//    if(NUM_THREADS > TAM_ARRAY){
//       tamanho = TAM_ARRAY;
//    }
//    else{
//       tamanho = NUM_THREADS;
//    }

   pthread_t threads[NUM_THREADS];

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


   ////// PRINTANDO OS VETORES A L ////////
   printf("\nVetor A: ");
   for(t=0; t<NUM_THREADS; t++){
      printf("%d ", A[t]);
   }
   printf("\n");

//    printf("\nVetor L: ");
//    for(t=0; t<NUM_THREADS/2; t++){
//       printf("%d ", L[t]);
//    }
//    printf("\n");
   ////////////////////////////////////////


   printf("\nVetor C resultante: ");
   for(t=0; t<NUM_THREADS; t++){
      printf("%d ", C[t]);
   }
   printf("\n");

   pthread_exit(NULL);
}

 
