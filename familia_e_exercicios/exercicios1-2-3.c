#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i;
    pid_t pid;
    int x;
    int soma = 0;
    
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        //O código aqui dentro será executado no processo filho
        x = 20;
        // soma dos pares ate 100
        printf("pid do Filho: %d\n", getpid());
        for (i = 0; i <= 100; i += 2){
            soma += i;
        }
        int status = system("firefox");
        
    }
    else
    {
        //O código neste trecho será executado no processo pai
        x = 10;
        printf("pid do Pai: %d\n", getpid());
        // soma dos impares ate 100
        for (i = 1; i <= 100; i += 2){
            soma += i;
        }
    }


    printf("Esta regiao sera executada por ambos processos\n");
    printf("O valor de x é: %d\n", x);
    printf("O valor da soma é: %d\n\n", soma);
    scanf("%d", &i);
    printf("Digitar S para sair. ");
    exit(0);
}


