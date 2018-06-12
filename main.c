#include <stdio.h>
#include <stdlib.h>

struct el_matriz{
long int i;
long int j;
struct matriz *anterior;
};


int main()
{
int bandeira;
struct el_matriz *p_el_matriz;
struct el_matriz *salva_p_el_matriz;
char resp[2];
long int m;
long int n;

bandeira = 0;
salva_p_el_matriz = NULL;
p_el_matriz = NULL;

while(resp[0] != '2'){
//"MENU" DO PROGRAMA
printf("///OPERACOES COM MATRIZES ESPARSAS\n");
printf("Escolha uma funcao: \n");
printf("1. Criacao de matriz m por n\n");
printf("2. Exclusao de matriz");

//

scanf("%s", resp);

//CRIACAO DE MATRIZ M POR N

if(resp[0] == '3'){
p_el_matriz = malloc(sizeof(struct el_matriz));

printf("Digite o numero de linhas da matriz: ");
scanf("%ld", &m);
printf("\n");

printf("Digite o numero de colunas da matriz: ");
scanf("%ld", &n);
printf("\n");

printf("Matriz criada \n");
}

//EXCLUSAO DE MATRIZ
else if(resp[0] == '2'){
free(p_el_matriz);
p_el_matriz = NULL;
printf("Matriz excluida\n");
}




}

free(p_el_matriz);
return 0;
}
