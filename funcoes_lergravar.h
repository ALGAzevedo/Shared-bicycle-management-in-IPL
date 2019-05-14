#ifndef FUNCOES_LERGRAVAR_H_INCLUDED
#define FUNCOES_LERGRAVAR_H_INCLUDED

#include "structs.h"
#include "constantes.h"

void gravarBicicletasBin(tipoBicicleta bicicletas[MAX_BICICLETAS],int *pQuantidadeBicicletas, float *pDistanciaTotal);
void lerBicicletasBin(tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas, float *pDistanciaTotal);
void gravarUtentesBin(tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes);
void lerUtentesBin(tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes);
void gravarAvariasLog(tipoAvaria avarias);

void gravarEmprestimosBin(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos);
tipoEmprestimo* lerEmprestimosBin(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos);

void gravarListaBin(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int *pSomaEspera);
tipoEmprestimo* lerListaBin(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int *pSomaEspera);

#endif // FUNCOES_LERGRAVAR_H
