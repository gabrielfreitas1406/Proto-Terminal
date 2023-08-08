#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int contadorDePlavras;
int * vetor_posicoes;
char buffer_entrada[100];

int count_commands(char buffer_entrada[]){
    int i, num_cmd=1;
    for(i = 0; i < strlen(buffer_entrada); i++){
        if(buffer_entrada[i] == ' ') num_cmd++;
    }
    return num_cmd;
}

void print_vetor_posicoes(){

    for (int i = 0; i < contadorDePlavras; i++)
    {
        printf("%d ", vetor_posicoes[i]);
    }

    /*
    for (int i = 0; i < contadorDePlavras; i++)
    {
        printf("%s ", buffer_entrada[vetor_posicoes[i]]);
    }
    */
    printf("\n");
}

void parsing2(int qtdPalavras){
    
    vetor_posicoes = malloc(sizeof(int*)*qtdPalavras); // Cria um vetor com qtdPlavras posições
    vetor_posicoes[0] = 0; //palavra inicial
    int j = 1;
    printf("tam buffer %ld\n", strlen(buffer_entrada));
    long int tam_buffer = strlen(buffer_entrada);
    for(int i = 0; i < tam_buffer; i++){
        printf("i = %d j = %d\n", i, j);
        if(buffer_entrada[i] == ' ') {
            printf("entrei\n");
            vetor_posicoes[j] = i+1;
            j++;
            buffer_entrada[i] = '\0'; //fim de string
            printis();
        }
    }
}

char** parsing(int qtdPalavras){
    char ** res = (char**) malloc(sizeof(char*)*qtdPalavras);
    int i,j;
    for (i=0; i<qtdPalavras; i++){
        res[i] = NULL;
    }
    i = 0;
    j = 0;
    char *char_aux;
    char_aux = malloc(sizeof(char*)*50);
    for(j = 0; j < strlen(buffer_entrada); j++){
        if(buffer_entrada[j] == ' ') {
            i++;
            res[i] = char_aux;
            char_aux = malloc(sizeof(char*)*50);
        }
        else{

        }
    }
    return res;
}

char* command(char buffer_entrada[]){
    char *saida;
    saida = malloc(sizeof(char)*100);
    //int fork_cmd = fork();
    //printf("%d\n", fork_cmd);
    printf("num comandos:%d\n", count_commands(buffer_entrada));
    return saida;
}



int main(){
    while (strcmp(buffer_entrada,"exit")!=0){ //enquanto o usuário não digitar exit, o terminal continua recebendo novos comandos
        printf(">>> ");
        scanf("%[^\n]%*c",buffer_entrada);
        contadorDePlavras = count_commands(buffer_entrada);
        //printf("%d\n", contadorDePlavras);
        if (strcmp(buffer_entrada,"exit")!=0){
            parsing2(contadorDePlavras);
            //printis();
            
        } 
    }
}
