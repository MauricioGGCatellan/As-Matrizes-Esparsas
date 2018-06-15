#include <stdio.h>
#include <stdlib.h>

#include "Struct.h"

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

void exclusao_matriz(struct el_matriz *p_el_matriz){
struct el_matriz *testa_salva_p_el_matriz = p_el_matriz;
while(testa_salva_p_el_matriz != NULL){
    free(testa_salva_p_el_matriz);
    testa_salva_p_el_matriz = testa_salva_p_el_matriz->anterior;
}

}

float soma_i(struct el_matriz *p_el_matriz, long int testa_i){
float soma = 0;
struct el_matriz *testa_salva_p_el_matriz = p_el_matriz;
while(testa_salva_p_el_matriz != NULL){
    if(testa_salva_p_el_matriz->i == testa_i){
    soma = soma + testa_salva_p_el_matriz->valor;
    }
    testa_salva_p_el_matriz = testa_salva_p_el_matriz->anterior;
}
return soma;
}

float soma_j(struct el_matriz *p_el_matriz, long int testa_j){
float soma = 0;
struct el_matriz *testa_salva_p_el_matriz = p_el_matriz;
while(testa_salva_p_el_matriz != NULL){
    if(testa_salva_p_el_matriz->j == testa_j){
    soma = soma + testa_salva_p_el_matriz->valor;
    }
    testa_salva_p_el_matriz = testa_salva_p_el_matriz->anterior;
}
return soma;
}
