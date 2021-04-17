#include "reader.h"

/**
 * Inicializa o algoritmo
 * 
 * @param filename - nome do arquivo
 */
void init (char * filename) {

    // arquivo a ser lido
    FILE * file = fopen(filename, "r");                                  

    // inicializa o contador
    args_.count = 0;

    // chama a função de varredura do arquivo
    // passando um ponteiro para o arquivo e para o contador
    // apenas se o arquivo não está vazio
    if (file) status = read(file);
    else status = FOPENERR;

    fclose(file);

    // analisa o retorno e imprime o contador na tela se um erro não foi encontrado             
    switch(status) {
        case FOPENERR:
            printf("\n\tErro: Arquivo não existe\n\n");
            break;
        case INVFIRSTERR:
            printf("\n\tErro: Primeira linha não foi formatada corretamente\n\n");
            break;
        case MUST2ERR:
            printf("\n\tErro: Arquivo precisa ter 2 ou mais linhas\n\n");
            break;
        case ALLRIGHT:
            printf("\n\tResultado: %d\n\n", args_.count);
    }

}

/**
 * Varre o arquivo linha por linha após a primeira.
 * 
 * @param file - o arquivo a ser varrido
 */
int read (FILE * file) {

    // string a ser encontrada e
    // string a ser vasculhada respectivamente
    unsigned char * line_1, * line_2;

    // parâmetros para os tamanhos das strings a ser passadas para as funções seguintes
    int len_line_1, len_line_2;

    // flag de EOF
    int isEof;
    
    // lê a primeira string
    isEof = getNextLine(file, &line_1, &len_line_1);

    printf("%d\n",len_line_1);

    // verifica se o arquivo já chegou no final, ou seja, se possui apenas uma linha
    if (isEof == EOF)
        return MUST2ERR;
    
    // verifica se a primeira linha está formatada corretamente
    for (int i = 0; i < len_line_1; i++)
        if (len_line_1 > 20)
            return INVFIRSTERR; 
        else if (line_1[i] < '0' || line_1[i] > '9')
                if (line_1[i] < 'A' || line_1[i] > 'z')
                    return INVFIRSTERR; 
            

    do {
        // pega a próxima linha do arquivo e retorna se chegou ou não ao fim dele
        isEof = getNextLine(file, &line_2, &len_line_2);
        // chama o programa em Fortran passando a primeira linha em par com a linha da iteração atual, junto do tamanho de cada
        findsubstring_(line_1, line_2, &len_line_1, &len_line_2);
        // limpa line_2 para ler as próximas linhas
        free(line_2);
    } while(isEof != EOF); // sai do loop quando chegou no fim do arquivo

    return ALLRIGHT;
}

/**
 * fscanf feito no braço para ler a partir da segunda linha
 * 
 * @param file - o arquivo a ser lido
 * @param sp - ponteiro que devolve a string lida
 * 
 * @return EOF caso tenha chegado no fim do arquivo ou 0 caso contrário
*/
int getNextLine(FILE * file, unsigned char ** sp, int * length) {

    // linha retirada do arquivo
    unsigned char * line = (unsigned char *) malloc(sizeof(unsigned char));
    *line = '\0';
    // tamanho da linha que no inicio será considerada como se fosse 0
    *length = 0;
    // caractere retirado do arquivo que vai pra line
    unsigned char c;
    do {

        // le caractere da linha do arquivo
        c = fgetc(file);
        // sai do loop caso encontre '\n' que indica fim de linha
        if(c == '\n') break;

        // incrementa o tamanho de line
        (*length)++;
        // aumenta o tamanho de line caso a linha tenha mais de 1 caractere
        if((*length) > 1) line = (unsigned char *) realloc(line, (*length)*sizeof(unsigned char));
        // concatena o novo caractere à line
        line[(*length)-1] = c;

    } while(!feof(file)); // sai do loop quando chega no fim do arquivo

    // devolve line para o parametro da função
    *sp = line;

    // retorna EOF caso tenha chego no fim da linha ou 0 caso contrário
    return feof(file) ? EOF : 0;

}