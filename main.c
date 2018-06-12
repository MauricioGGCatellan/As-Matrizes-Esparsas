#include <stdio.h>
#include <stdlib.h>


void digitar_i_e_j (long int *i, long int *j){
printf("Digite o valor i da posicao: ");
scanf("%ld", i);
printf("\n");

printf("Digite o valor j da posicao: ");
scanf("%ld", j);
printf("\n");
}

int teste_i_e_j(long int testa_i, long int testa_j, long int m, long int n){
if(testa_i < 1 || testa_i > m){
    printf("Valor invalido de i ou j\n");
    printf("\n");
    return 0;
}
if(testa_j < 1 || testa_j > n){
    printf("Valor invalido de i ou j\n");
    printf("\n");
    return 0;
}
return 1;
}

struct el_matriz{
long int i;
long int j;
struct el_matriz *anterior;
double valor;
int bandeira_valor;
};

void exclusao_matriz(struct el_matriz *p_el_matriz){
struct el_matriz *testa_salva_p_el_matriz = p_el_matriz;
while(testa_salva_p_el_matriz != NULL){
    free(testa_salva_p_el_matriz);
    testa_salva_p_el_matriz = testa_salva_p_el_matriz->anterior;
}

}


int main()
{
struct el_matriz *p_el_matriz;
struct el_matriz *salva_p_el_matriz;
struct el_matriz *testa_salva_p_el_matriz;
char resp[2];
long int testa_i;
long int testa_j;
long int m;
long int n;
int testar_i_e_j;

testa_salva_p_el_matriz = NULL;
salva_p_el_matriz = NULL;
p_el_matriz = NULL;

while(resp[0] != '4'){
//"MENU" DO PROGRAMA
printf("///OPERACOES COM MATRIZES ESPARSAS\n");
printf("Escolha uma funcao: \n");
printf("1. Criacao da matriz m por n\n");
printf("2. Exclusao da matriz\n");
printf("3. Consulta dos valores de uma posicao (i, j) da matriz\n");
printf("6. Atribuicao de um valor na posicao (i, j) da matriz\n");

//

scanf("%s", resp);
fflush(stdin);

//CRIACAO DA MATRIZ M POR N

if(resp[0] == '1'){
if(p_el_matriz != NULL){
    printf("Matriz ja criada. Deseja sobrescreve-la criando uma nova?(s\n)");
    while(resp[0] != 's' && resp[0] != 'n' && resp[0] != 'S' && resp[0] != 'N'){
        scanf("%s", resp);
        if(resp[0] != 's' && resp[0] != 'n' && resp[0] != 'S' && resp[0] != 'N'){
            printf("Resposta invalida. Digite novamente\n");
        }
    }
    if(resp[0] == 's' || resp[0] == 'S'){
     exclusao_matriz(p_el_matriz);
    } else{
    printf("\n");
     continue;
    }
}

p_el_matriz = (struct el_matriz*) malloc(sizeof(struct el_matriz));
if(p_el_matriz == NULL){
    printf("Problema de memoria. Nao foi possivel criar a matriz\n");
    return 1;
}

printf("Digite o numero de linhas da matriz: ");
scanf("%ld", &m);
printf("\n");

if(m <= 0){
    printf("Valor invalido para o numero de linhas!\n");
    printf("\n");
    continue;
}

printf("Digite o numero de colunas da matriz: ");
scanf("%ld", &n);
printf("\n");

if(n <= 0){
    printf("Valor invalido para o numero de colunas!\n");
    printf("\n");
    continue;
}

printf("Matriz criada \n");
printf("\n");
}

//EXCLUSAO DA MATRIZ
else if(resp[0] == '2'){
if(p_el_matriz == NULL){
    printf("Nao ha matriz a ser excluida \n");
    printf("\n");
    continue;
}
exclusao_matriz(p_el_matriz);
p_el_matriz = NULL;
printf("Matriz excluida\n");

printf("\n");
}

//CONSULTA DOS VALORES DE UMA POSICAO (i, j) DA MATRIZ
else if(resp[0] == '3'){

testa_salva_p_el_matriz = p_el_matriz;
if(testa_salva_p_el_matriz == NULL){
    printf("Nao foi criada uma matriz. Nao ha valores a serem consultados \n");
    continue;
}

digitar_i_e_j(&testa_i, &testa_j);

testar_i_e_j = teste_i_e_j(testa_i, testa_j, m, n);

if(testar_i_e_j == 0){
    continue;
}

while(testa_salva_p_el_matriz != NULL){
if((testa_i == testa_salva_p_el_matriz->i) && (testa_j == testa_salva_p_el_matriz->j) ){
    if(testa_salva_p_el_matriz->bandeira_valor){
    printf("O valor da posicao (%ld, %ld) e: %lf\n", testa_salva_p_el_matriz->i, testa_salva_p_el_matriz->j, testa_salva_p_el_matriz->valor);
    break;
} else {
    printf("O valor da posicao (%ld, %ld) e: 0", testa_i, testa_j);
    break;
}
} else if(testa_salva_p_el_matriz->anterior == NULL) {
    printf("O valor da posicao (%ld, %ld) e: 0\n", testa_i, testa_j);
}

testa_salva_p_el_matriz = testa_salva_p_el_matriz->anterior;

printf("\n");
}


//ATRIBUICAO DE UM VALOR NA POSICAO (i, j) DA MATRIZ
} else if(resp[0] == '6'){
if(p_el_matriz == NULL){
    printf("Nao foi criada uma matriz. Nao ha posicoes para atribuir valores \n");
    printf("\n");
    continue;
}
if(p_el_matriz->bandeira_valor == 0){
    digitar_i_e_j(&p_el_matriz->i, &p_el_matriz->j);
    testar_i_e_j = teste_i_e_j(p_el_matriz->i, p_el_matriz->j, m, n);
    if(testar_i_e_j == 0){
        continue;
    }
    printf("Digite o valor que deseja atribuir a posicao (%ld, %ld): ", p_el_matriz->i, p_el_matriz->j);
    scanf("%lf", &p_el_matriz->valor);
    printf("\n");
    p_el_matriz->bandeira_valor = 1;
    printf("Valor atribuido com sucesso.\n");
}
else{
salva_p_el_matriz = p_el_matriz;
p_el_matriz = (struct el_matriz*) malloc(sizeof(struct el_matriz));
if(p_el_matriz == NULL){
    printf("Problema de memoria. Nao foi possivel atribuir mais valores a matriz\n");
    continue;
}
p_el_matriz->anterior = salva_p_el_matriz;
digitar_i_e_j(&p_el_matriz->i, &p_el_matriz->j);
testar_i_e_j = teste_i_e_j(p_el_matriz->i, p_el_matriz->j, m, n);
if(testar_i_e_j == 0){
    continue;
}
printf("Digite o valor que deseja atribuir a posicao (%ld, %ld): ", p_el_matriz->i, p_el_matriz->j);
scanf("%lf", &p_el_matriz->valor);
printf("\n");
p_el_matriz->bandeira_valor = 1;
printf("Valor atribuido com sucesso.\n");
}

printf("\n");
}
}
free(p_el_matriz);
return 0;

}
