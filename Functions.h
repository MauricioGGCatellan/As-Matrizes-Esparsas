#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "Struct.h"

//DECLARAÇÃO DAS FUNÇÕES USADAS NO PROGRAMA
void digitar_i_e_j (long int *i, long int *j);
int teste_i_e_j(long int testa_i, long int testa_j, long int m, long int n);
void exclusao_matriz(struct el_matriz *p_el_matriz);
float soma_i(struct el_matriz *p_el_matriz, long int testa_i);
float soma_j(struct el_matriz *p_el_matriz, long int testa_j);

#endif // FUNCTIONS_H_INCLUDED
