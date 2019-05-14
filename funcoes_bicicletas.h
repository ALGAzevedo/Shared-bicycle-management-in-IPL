#ifndef FUNCOES_BICICLETAS_H_INCLUDED
#define FUNCOES_BICICLETAS_H_INCLUDED

#include "constantes.h"
#include "structs.h"
#include "funcoes_bicicletas.h"

void inserirBicicleta(tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas);
void consultarBicicletas(tipoBicicleta bicicletas[MAX_BICICLETAS],int *pQuantidadeBicicletas);
int procuraBicicleta(tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas);
void listarBicicletas(tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas);
void mostrarDadosBicicletas(tipoBicicleta bicicleta);
void registarDevolucao(tipoBicicleta bicicletas[MAX_BICICLETAS],int quantBicicletas,tipoUtente utentes[MAX_UTENTES], int quantUtentes,tipoEmprestimo *emprestimos, int quantEmprestimos,float *pDistanciaTotal);
void registarAvaria(tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas);
void registarReparacao(tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas);

void listarHistoricoEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos,tipoUtente utentes[MAX_UTENTES], int quantUtentes,tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas);


#endif

