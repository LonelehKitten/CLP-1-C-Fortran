#include "reader.h"

/**
 * Inicializa o algoritmo
 * 
 * @param filename - nome do arquivo
 */
void init (char * filename) {

    // arquivo a ser lido
    FILE * file = fopen(filename, "r");

    // contador de ocorrências de string (line_1 em read(FILE*, int*))
    // inicializado em 0
    int * result = (int *) malloc(sizeof(int));     
    *result = 0;                                    
    
    // chama a função de varredura do arquivo
    // passando um ponteiro para o arquivo e para o contador
    read(file);

    fclose(file);

    // imprime o contador na tela
    printf("Resultado: %d", args_.count);

}

/**
 * Varre o arquivo linha por linha após a primeira.
 * 
 * @param file - o arquivo a ser varrido
 */
void read (FILE * file) {

    // string a ser encontrada e
    // string a ser vasculhada respectivamente
    char * line_1 = (char *) malloc(20), * line_2;

    // lê a primeira string
    fscanf(file, " %s\n", line_1);

    // flag de EOF
    int isEof = 0;

    args_.count = 0;
    int len_line_1, len_line_2;
    len_line_1 = (int) strlen(line_1);
    do {
        // pega a próxima linha do arquivo e retorna se chegou ou não ao fim dele
        isEof = getNextLine(file, &line_2, &len_line_2);
        // chama o programa em Fortran passando a primeira linha em par com as demais e o contador para ser incrementado

        findsubstring_(line_1, line_2, &len_line_1, &len_line_2);
        // limpa line_2 para ler as próximas linhas
        free(line_2);
    } while(isEof != EOF); // sai do loop quando chega no fim do arquivo

}

/**
 * fprintf feito no braço
 * 
 * @param file - o arquivo a ser lido
 * @param sp - ponteiro que devolve a string lida
 * 
 * @return EOF caso tenha chegado no fim do arquivo ou 0 caso contrário
*/
int getNextLine(FILE * file, char ** sp, int * length) {

    // linha retirada do arquivo
    char * line = (char *) malloc(sizeof(char));
    *line = '\0';
    // tamanho da linha que no inicio será considerada como se fosse 0
    *length = 0;
    // caractere retirado do arquivo que vai pra line
    char c;
    do {

        // le caractere da linha do arquivo
        c = fgetc(file);
        // sai do loop caso encontre '\n' que indica fim de linha
        if(c == '\n') break;

        // incrementa o tamanho de line
        (*length)++;
        // aumenta o tamanho de line caso a linha tenha mais de 1 caractere
        if((*length) > 1) line = (char *) realloc(line, (*length)*sizeof(char));
        // concatena o novo caractere à line
        line[(*length)-1] = c;

    } while(!feof(file)); // sai do loop quando chega no fim do arquivo

    // devolve line para o parametro da função
    *sp = line;

    // retorna EOF caso tenha chego no fim da linha ou 0 caso contrário
    return feof(file) ? EOF : 0;

}