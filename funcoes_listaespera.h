#ifndef FUNCOES_LISTAESPERA_H_INCLUDED
#define FUNCOES_LISTAESPERA_H_INCLUDED

#include "constantes.h"
#include "structs.h"


tipoEmprestimo* acrescentaListaEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int *pSomaEspera, tipoEmprestimo dados);
void consultarListaEspera(tipoEmprestimo *listaEspera,int *pQuantidadeEspera, int *pSomaEspera);
int procuraListaEspera(tipoEmprestimo *listaEspera, int quantEspera, int somaEspera);
void mostrarDadosListaEspera(tipoEmprestimo lista);
void listarDadosListaEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera);
tipoEmprestimo* eliminarEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int somaEspera);
tipoEmprestimo* alterarEspera(tipoEmprestimo *listaEspera, int quantEspera,int somaEspera);
tipoEmprestimo* removeEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int pos);
tipoEmprestimo* atualizaEspera(tipoEmprestimo **emprestimos, tipoEmprestimo *listaEspera,tipoBicicleta bicicletas[MAX_BICICLETAS],tipoUtente utentes[MAX_UTENTES], int *pQuantidadeEmprestimos, int *pQuantidadeEspera, int quantBicicletas, int quantUtentes);

tipoEmprestimo* ordenaListaTipo(tipoEmprestimo *listaEspera, int quantEspera);
tipoEmprestimo* ordenaListaDistancia(tipoEmprestimo *listaEspera, int quantEspera);
tipoEmprestimo* ordenaListaEntrada(tipoEmprestimo *listaEspera, int quantEspera);



#endif
