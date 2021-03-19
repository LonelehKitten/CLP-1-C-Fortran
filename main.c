#include <stdio.h>
#include <locale.h>
#include "lib/reader.h"

/**
 *  Inicializa o programa
 * 
 *  @param argc - contador de argumentos
 *  @param argv - array de argumentos
 */
int main (int argc, char ** argv) {

    setlocale(LC_ALL, "");

    // Caso o nome do arquivo não seja passado por argumento
    // imprime uma mensagem de erro e termina o programa
    if(argc == 1) {
        printf("\n\tErro: Nome do arquivo não informado\n\n");
        return 0;
    }
    
    // Chama o leitor
    init(argv[1]);

    return 0;
}



