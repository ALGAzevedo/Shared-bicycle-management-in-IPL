#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "constantes.h"
#include "structs.h"
#include "funcoes_auxiliares.h"
#include "funcoes_emprestimos.h"
#include "menus.h"
#include "funcoes_utentes.h"
#include "funcoes_listaespera.h"




tipoEmprestimo *acrescentaListaEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int *pSomaEspera, tipoEmprestimo dados)
{
    tipoEmprestimo *aux;
    aux=listaEspera;
    listaEspera=realloc(listaEspera, ((*pQuantidadeEspera) + 1)*sizeof(tipoEmprestimo));
    if (listaEspera == NULL)
    {
        printf("\nMemoria insuficiente");
        listaEspera=aux;
    }
    else
    {
        listaEspera[*pQuantidadeEspera].numRegisto = (*pSomaEspera);
        listaEspera[*pQuantidadeEspera].idUtente = dados.idUtente;
        listaEspera[*pQuantidadeEspera].localOrigem = dados.localOrigem;
        listaEspera[*pQuantidadeEspera].localDestino = dados.localDestino;
        listaEspera[*pQuantidadeEspera].distanciaPadrao = dados.distanciaPadrao;
        listaEspera[*pQuantidadeEspera].catUtente = dados.catUtente;
        (*pQuantidadeEspera)++;
        (*pSomaEspera)++;
    }
    return listaEspera;
}



void consultarListaEspera(tipoEmprestimo *listaEspera,int *pQuantidadeEspera, int *pSomaEspera)
{
    int pos;
    if(*pQuantidadeEspera != 0)
    {
        pos = procuraListaEspera(listaEspera,*pQuantidadeEspera,*pSomaEspera);
        if(pos==-1)
        {
            printf("\n\nO numero de registo inserido nao corresponde a nenhum em espera.");
        }
        else
        {
            mostrarDadosListaEspera(listaEspera[pos]);              //PENSO QUE O PROBLEMA SEJA AQUI !
        }
    }
    else
    {
        printf("\nNão existem registos em espera.");
    }
}


int procuraListaEspera(tipoEmprestimo *listaEspera, int quantEspera, int somaEspera)
{
    int i,pos=-1,procura;

    procura = lerInteiro("\nInsira numero de registo : ",0,somaEspera);
    for(i=0; i<=quantEspera; i++)
    {
        if(listaEspera[i].numRegisto==procura)
        {
            pos = i;
            i = quantEspera;
        }
    }
    return pos;
}

void mostrarDadosListaEspera(tipoEmprestimo lista)
{
    printf("\n\nNumero de registo: %d\nCodigo do utente: %d", lista.numRegisto, lista.idUtente);
    printf("\nLocal de Origem: ");
    if(lista.localOrigem==0)
    {
        printf("Residencias");
    }
    else
    {
        if(lista.localOrigem==1)
        {
            printf("Campus1");
        }
        else
        {
            if(lista.localOrigem==2)
            {
                printf("Campus2");
            }
            else
            {
                printf("Campus5");
            }
        }
    }
    printf("\nLocal de Destino: ");
    if(lista.localDestino==0)
    {
        printf("Residencias");
    }
    else
    {
        if(lista.localDestino==1)
        {
            printf("Campus1");
        }
        else
        {
            if(lista.localDestino==2)
            {
                printf("Campus2");
            }
            else
            {
                printf("Campus5");
            }
        }
    }
}


void listarDadosListaEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera)
{
    int i;
    if((*pQuantidadeEspera)!=0)
    {
        printf("\n\nLISTA ESPERA: ");
        for(i=0; i<(*pQuantidadeEspera); i++)
        {
            mostrarDadosListaEspera(listaEspera[i]);
        }
    }
    else
    {
        printf("\nNao existe registos em espera.\n");
    }
}


tipoEmprestimo* eliminarEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int somaEspera)
{
    int pos;
    if(*pQuantidadeEspera != 0)
    {
        pos= procuraListaEspera(listaEspera,*pQuantidadeEspera,somaEspera);
        if(pos==-1)
        {
            printf("\nRegisto em espera nao existe.\n");
        }
        else
        {
            listaEspera = removeEspera(listaEspera,pQuantidadeEspera,pos);
        }
    }
    else
    {
        printf("\nNao existem utentes em espera.");
    }
    return listaEspera;
}


tipoEmprestimo* alterarEspera(tipoEmprestimo *listaEspera, int quantEspera,int somaEspera)
{
    int pos,destino,aux2,origem, cont=0;
    printf("\nAlterar Campus de destino: ");
    if(quantEspera != 0)
    {
        pos= procuraListaEspera(listaEspera,quantEspera,somaEspera);
        if(pos==-1)
        {
            printf("\nRegisto em espera nao existe");
        }
        else
        {
            origem=listaEspera[pos].localOrigem;
            destino=listaEspera[pos].localDestino;
            aux2=destino;
            while(aux2==destino || aux2==origem)
            {

                printf("\nNao pode inserir como destino ");
                if(destino==0)
                {
                    printf("Residencias e ");
                }
                else
                {
                    if(destino==1)
                    {
                        printf("Campus1 e ");
                    }
                    else
                    {
                        if(destino==2)
                        {
                            printf("Campus2 e ");
                        }
                        else
                        {
                            printf("Campus5 e ");
                        }
                    }
                }
                if(origem==0)
                {
                    printf("Residencias");
                }
                else
                {
                    if(origem==1)
                    {
                        printf("Campus1");
                    }
                    else
                    {
                        if(origem==2)
                        {
                            printf("Campus2");
                        }
                        else
                        {
                            printf("Campus5");
                        }
                    }
                }
                aux2=lerInteiro("\nInsira novo campus de destino:\n\n0 - Residencias\n1 - Campus1\n2 - Campus2\n3 - Campus5\n",0,3);
                cont++;
                if(cont>2)
                {
                    printf("\nNao seja teimoso insira um destino correto :) ");
                }
            }
            listaEspera[pos].localDestino=aux2;
             printf("\nRegisto efetuado com sucesso.\n");
        }

    }
    return listaEspera;
}


tipoEmprestimo* atualizaEspera(tipoEmprestimo **emprestimos, tipoEmprestimo *listaEspera,tipoBicicleta bicicletas[MAX_BICICLETAS],tipoUtente utentes[MAX_UTENTES], int *pQuantidadeEmprestimos, int *pQuantidadeEspera, int quantBicicletas, int quantUtentes)
{
    int i,j,k, pos,idUtente;

    if((*pQuantidadeEspera)!=0)
    {
        for(j=0; j<quantBicicletas; j++)
        {
            if(bicicletas[j].estadoBicicleta==0)
            {
                pos=j;

                for(i=0; i<(*pQuantidadeEspera); i++)
                {
                    if(listaEspera[i].localOrigem == bicicletas[pos].localBicicleta)
                    {
                        idUtente=listaEspera[i].idUtente;
                        for(k=0; k<quantUtentes; k++)
                        {
                            if(utentes[k].idUtente==idUtente)
                            {
                                utentes[k].status=1;
                                printf("\n####  Bicicleta [%s] disponivel para emprestimo ao utilizador [%s] ####",bicicletas[pos].idBicicleta, utentes[k].nomeUtente);
                                *emprestimos= acrescentaEmprestimo(*emprestimos,pQuantidadeEmprestimos,listaEspera[i],bicicletas[pos]);
                                listaEspera = removeEspera(listaEspera,pQuantidadeEspera, j);
                                bicicletas[pos].estadoBicicleta=1;
                                bicicletas[pos].numEmprestimos++;
                            }
                        }
                    }
                }
            }
        }
    }
    return listaEspera;
}


tipoEmprestimo* removeEspera(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int pos)          //Funcao para remover elemento da lista de espera
{
    int i;
    tipoEmprestimo *aux;
    aux=listaEspera;

    for(i=pos; i<((*pQuantidadeEspera)-1); i++)         //Percorrer vetor dinamico da lista de espera após a posicao eliminada(pos)
    {
        listaEspera[i]= listaEspera[i+1];               //Elemento anterior é igual ao elemento seguinte
    }
    listaEspera=realloc(listaEspera,((*pQuantidadeEspera)-1)*sizeof(tipoEmprestimo));   //Reallocar memoria

    if(listaEspera==NULL && ((*pQuantidadeEspera)-1) != 0)
    {
        printf("\nErro na alocacao de memoria.");
        listaEspera=aux;                                //redifine lista de espera para a anterior à alocacao
    }
    else
    {
        (*pQuantidadeEspera)--;   //Decrementa a posicao maxima do vetor
    }
    return listaEspera;         //retorna o vetor
}


//Funções de ordenação por critério
tipoEmprestimo* ordenaListaTipo(tipoEmprestimo *listaEspera, int quantEspera)           //Funcao para ordenar pelo tipo de Utente(Prioridade explicada no relatorio)
{
    int i,j, trocas;
    tipoEmprestimo aux;

    trocas=1;
    for(i=0; i<quantEspera-1 && trocas!=0; i++)
    {
        trocas=0;

        for(j=0; j<quantEspera-i-1; j++)
        {
            if(listaEspera[j+1].catUtente>listaEspera[j].catUtente)
            {
                trocas=1;
                aux=listaEspera[j];
                listaEspera[j]=listaEspera[j+1];
                listaEspera[j+1]=aux;
            }
        }
    }
    printf("\nCriterio definido.\n");
    return listaEspera;
}

tipoEmprestimo* ordenaListaEntrada(tipoEmprestimo *listaEspera, int quantEspera)        //Funcao para ordenar pela ordem de entrada na lista de espera
{
    int i,j, trocas;
    tipoEmprestimo aux;

    trocas=1;
    for(i=0; i<quantEspera-1 && trocas!=0; i++)
    {
        trocas=0;

        for(j=0; j<quantEspera-i-1; j++)
        {
            if(listaEspera[j+1].numRegisto<listaEspera[j].numRegisto)
            {
                trocas=1;
                aux=listaEspera[j];
                listaEspera[j]=listaEspera[j+1];
                listaEspera[j+1]=aux;
            }
        }
    }
    printf("\nCriterio definido.\n");
    return listaEspera;
}



tipoEmprestimo* ordenaListaDistancia(tipoEmprestimo *listaEspera, int quantEspera)      //Funcao para ordenar por ordem crescente da distancia entre os campi
{
    int i,j, trocas;
    tipoEmprestimo aux;

    trocas=1;
    for(i=0; i<quantEspera-1 && trocas!=0; i++)
    {
        trocas=0;

        for(j=0; j<quantEspera-i-1; j++)
        {
            if(listaEspera[j+1].distanciaPadrao<listaEspera[j].distanciaPadrao)
            {
                trocas=1;
                aux=listaEspera[j];
                listaEspera[j]=listaEspera[j+1];
                listaEspera[j+1]=aux;
            }
        }
    }
    printf("\nCriterio definido.\n");
    return listaEspera;
}
