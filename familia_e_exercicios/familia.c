#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    pid_t pid;
    
    // PRIMEIRO FILHO
    if((pid = fork()) < 0){
    	perror("fork");
    	exit(1);
    }
    if(pid == 0){
    	int x = 0;
    	while(x < 60){
    		x ++;
    		printf("Ano %d\n", x);
    		sleep(1);
    	}
    }
    else{
    	sleep(14);
    	printf("primeiro filho nasceu\n");
	    if ((pid = fork()) < 0)
	    {
	        perror("fork");
	        exit(1);
	    }
	    if (pid == 0)
	    {
	        //O código aqui dentro será executado no processo filho1
	        pid_t neto1;
	        sleep(12);
	        printf("primeiro neto nasceu\n");
	        if((neto1 = fork()) < 0){
	            
	        }
	        if(neto1 == 0){
	            // codigo neto 1
	        	sleep(12);
	            printf("primeiro neto morreu\n");
	            exit(0);
	        }
	        sleep(18);
	        printf("primeiro filho morreu\n");
	        exit(0);

	        
	    }
	    else
	    {
	        //O código neste trecho será executado no processo pai
	        sleep(2);
	        pid_t pid2;
	        printf("segundo filho nasceu\n");
	        // SEGUNDO FILHO
	        if((pid2 = fork()) < 0){
	            perror("fork");
	            exit(1);
	        }
	        if(pid2 == 0){
	            //codigo do filho 2
	            sleep(14);
	            pid_t neto2;
	            printf("segundo neto nasceu\n");
	            if((neto2 = fork()) < 0){
	                perror("fork");
	                exit(1);
	            }
	            if( neto2 == 0 ){
	                sleep(14);
	                printf("segundo neto morreu\n");
	            	exit(0);

	            }
	            else{                    
	                sleep(16);
	                printf("segundo filho morreu\n");
	            	exit(0);

	            }
	        } 
	        else{
	            sleep(44);
	            printf("morreu pai\n");
	            exit(0);
	        }
	    }
	}
    exit(0);
}


