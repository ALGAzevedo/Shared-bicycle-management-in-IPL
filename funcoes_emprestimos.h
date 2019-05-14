#ifndef FUNCOES_EMPRESTIMOS_H_INCLUDED
#define FUNCOES_EMPRESTIMOS_H_INCLUDED

#include "constantes.h"
#include "structs.h"

void inserirEmprestimo(tipoEmprestimo *emprestimos,int *pQuantidadeEmprestimos, tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes, tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBiciceltas);
tipoEmprestimo* registaEmprestimo(tipoEmprestimo **listaEspera,int *pQuantidadeEspera,int *pSomaEspera,tipoEmprestimo *emprestimos,int *pQuantidadeEmprestimos, tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes, tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas);
int verificaBicicleta(tipoBicicleta bicicletas[MAX_BICICLETAS],int *pQuantidadeBicicletas, int local);
void consultarEmprestimos(tipoEmprestimo *emprestimos,int *pQuantidadeEmprestimos);
int procuraEmprestimo(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos);
void mostrarDadosEmprestimos(tipoEmprestimo emprestimo);
void listarDadosEmprestimos(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos);
tipoEmprestimo* acrescentaEmprestimo(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos,tipoEmprestimo dados,tipoBicicleta bicicleta);

//tipoEmprestimo** acrescentaListaEspera(tipoEmprestimo **listaEspera, int *pQuantidadeEspera, int *pSomaEspera, tipoEmprestimo dados);


/*
int distanciaMedia(tipoEmprestimo vetor);
void campusMaisEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos);
void distanciaMediaBicicletas(int quantBicicletas, int distanciaT);
void procuraBicicletaEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos,tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas);
void percEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos,tipoUtente utentes[MAX_UTENTES], int quantUtentes);
*/

#endif
