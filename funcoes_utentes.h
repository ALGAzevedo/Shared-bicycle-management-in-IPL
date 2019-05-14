#ifndef FUNCOES_UTENTES_H_INCLUDED
#define FUNCOES_UTENTES_H_INCLUDED

#include "constantes.h"
#include "structs.h"
#include "funcoes_bicicletas.h"
#include "funcoes_utentes.h"



void inserirUtente(tipoUtente utentes[MAX_UTENTES],int  *pQuantidadeUtentes);
int procurarUtente(tipoUtente utentes[MAX_UTENTES], int quantUtentes, int procura);
void consultarUtente(tipoUtente utentes[MAX_UTENTES],int *pQuantidadeUtentes);
void mostrarDadosUtente(tipoUtente utente);
void alterarUtente(tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes);
void listarDadosUtentes(tipoUtente utentes[MAX_UTENTES], int quantUtentes);
void listarUtentesEmprestimos(tipoUtente utentes[MAX_UTENTES], int quantUtentes);


#endif
