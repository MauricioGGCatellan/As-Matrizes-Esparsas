#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct el_matriz{
long int i;
long int j;
struct el_matriz *anterior;
float valor;
int bandeira_valor;
};

#endif // STRUCT_H_INCLUDED
