#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"
#include "funcoes_auxiliares.h"
#include "funcoes_bicicletas.h"
#include "menus.h"
#include "funcoes_lergravar.h"
#include "funcoes_utentes.h"
#include "funcoes_emprestimos.h"


void inserirBicicleta(tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas)
{
    int estado,cont;

    if(*pQuantidadeBicicletas==MAX_BICICLETAS)
    {
        printf("\nNao pode inserir mais bicicletas.");
    }
    else
    {
        lerString("\nInsira designacao da bicicleta: ", bicicletas[*pQuantidadeBicicletas].idBicicleta, MAX_STRING);
        // bicicletas[*pQuantidadeBicicletas].idBicicleta =(*pQuantidadeBicicletas);
        printf("\nBicicleta[%s]:", bicicletas[*pQuantidadeBicicletas].idBicicleta);
        lerString("\nInsira modelo da bicicleta: ",bicicletas[*pQuantidadeBicicletas].modelBicicleta, MAX_STRING);
        bicicletas[*pQuantidadeBicicletas].localBicicleta=lerInteiro("\nInsira onde se encontra a bicicleta:\n\n0 - Residencias\n1 - Campus1\n2 - Campus2\n3 - Campus5\n",0,3);
        bicicletas[*pQuantidadeBicicletas].distanciaTotal=0.0;
        bicicletas[*pQuantidadeBicicletas].avarias=0;
        bicicletas[*pQuantidadeBicicletas].numEmprestimos=0;
        bicicletas[*pQuantidadeBicicletas].estadoBicicleta=0;
        (*pQuantidadeBicicletas)++;
        do
        {
            estado=lerInteiro("\nInsira estado da bicicleta:\n\n 0 - Disponivel\n2 - Avariada\n",0,2);
            cont++;
            if(estado==1)
            {
                printf("\n1 Nao e uma opcao valida. Insira 0 ou 2.");
                cont++;
                if(cont>=2)
                {
                    printf("\nNao insista, insira um valor valido.");
                }
            }
        }
        while(estado==1);
        if(estado==0)
        {
            bicicletas[(*pQuantidadeBicicletas)-1].estadoBicicleta=0;
        }
        else
        {
            do
            {
                registarAvaria(bicicletas,*pQuantidadeBicicletas);
            }
            while(bicicletas[(*pQuantidadeBicicletas)-1].estadoBicicleta==0);
        }
    }
    printf("\nBicicleta registada com sucesso.");
}

void consultarBicicletas(tipoBicicleta bicicletas[MAX_BICICLETAS],int *pQuantidadeBicicletas)
{
    int pos;
    pos = procuraBicicleta(bicicletas, *pQuantidadeBicicletas);
    if(pos==-1)
    {
        printf("\nBicicleta nao existe\n");
    }
    else
    {
        mostrarDadosBicicletas(bicicletas[pos]);
    }

}


int procuraBicicleta(tipoBicicleta bicicletas[MAX_BICICLETAS],int quantBicicletas)
{
    int i,pos=-1;
    char designacao[MAX_STRING];
    lerString("\nInsira designacao da bicicleta: ", designacao, MAX_STRING);
    for(i=0; i<quantBicicletas; i++)
    {
        //aux=strcmp(designacao,bicicletas[i].idBicicleta);
        if(strcmp(designacao,bicicletas[i].idBicicleta)==0)
        {
            pos=i;
            i=quantBicicletas;
        }

    }

    return pos;
}

void listarBicicletas(tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas)
{
    int i;
    for(i=0; i<(*pQuantidadeBicicletas); i++)
    {
        mostrarDadosBicicletas(bicicletas[i]);
    }
}

void mostrarDadosBicicletas(tipoBicicleta bicicleta)
{
    printf("\nDesignacao: %s\nModelo: %s", bicicleta.idBicicleta, bicicleta.modelBicicleta);
    printf("\nEstado: ");
    if(bicicleta.estadoBicicleta==0)
    {
        printf("Disponivel.");
    }
    else
    {
        if(bicicleta.estadoBicicleta==1)
        {
            printf("Emprestada.");
        }
        else
        {
            printf("Avariada.");
        }
    }
    printf("\nLocal: ");
    if(bicicleta.localBicicleta==0)
    {
        printf("Residencias.");
    }
    else
    {
        if(bicicleta.localBicicleta==1)
        {
            printf("Campus 1.");
        }
        else
        {
            if(bicicleta.localBicicleta==2)
            {
                printf("Campus 2.");
            }
            else
            {
                printf("Campus 5.");
            }
        }
    }
    printf("\nQuantidade de emprestimos: %d\nQuantidade de avarias: %d\nDistancia total percorrida: %0.2f\n", bicicleta.numEmprestimos,bicicleta.avarias,bicicleta.distanciaTotal);
}


void registarDevolucao(tipoBicicleta bicicletas[MAX_BICICLETAS],int quantBicicletas,tipoUtente utentes[MAX_UTENTES], int quantUtentes,tipoEmprestimo *emprestimos, int quantEmprestimos,float *pDistanciaTotal)
{
    int i,j,posB,posE,posU;
    float distancia;

    if(quantBicicletas==0)
    {
        printf("\nNao existem bicicletas emprestadas");
    }
    else
    {
        posB = procuraBicicleta(bicicletas,quantBicicletas);
        if(posB==-1)
        {
            printf("\nBicicleta nao encontrada");
        }
        else
        {
            if(bicicletas[posB].estadoBicicleta==1)
            {
                for(i=0; i<quantEmprestimos; i++)
                {
                    if(strcmp(emprestimos[i].idBicicleta, bicicletas[posB].idBicicleta)==0)
                    {
                        posE=i;
                        i=quantEmprestimos;
                    }
                }
                bicicletas[posB].estadoBicicleta=0;
                bicicletas[posB].localBicicleta=emprestimos[posE].localDestino;
                distancia=lerFloat("\nInsira distancia percorrida: ", 0.0,9999.0);
                bicicletas[posB].distanciaTotal+=distancia;
                for(j=0; j<quantUtentes; j++)
                {
                    if(utentes[j].idUtente==emprestimos[posE].idUtente)
                    {
                        posU=j;
                        j=quantUtentes;
                    }
                }
                utentes[posU].distanciaUtente+=distancia;
                utentes[posU].status=0;
                (*pDistanciaTotal)+=distancia;
            }
            else
            {
                printf("\nBicicleta nao esta emprestada.\n");
            }
        }
    }

}

void registarAvaria(tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas)
{
    int pos;
    tipoAvaria avarias;
    printf("\nRegisto de avaria:");
    pos=procuraBicicleta(bicicletas,quantBicicletas);
    if(pos==-1)
    {
        printf("\nBicicleta nao existe.");
    }
    else
    {
        bicicletas[pos].estadoBicicleta=2;
        bicicletas[pos].avarias++;
        strcpy(avarias.idBicicleta,bicicletas[pos].idBicicleta);
        avarias.distanciaTotal=bicicletas[pos].distanciaTotal;
        printf("\nInsira data e hora da avaria: ");
        avarias.dataAvaria=lerData();
        avarias.horaAvaria=lerHora();
        lerString("\nInsira a descricao da avaria: ", avarias.descricao,MAX_STRING);
        gravarAvariasLog(avarias);
    }
}

void registarReparacao(tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas)
{
    int pos;

    printf("Registo de reparacao: ");
    pos=procuraBicicleta(bicicletas, quantBicicletas);
    if(pos==-1)
    {
        printf("\nBicicleta nao existe.");
    }
    else
    {
        if(bicicletas[pos].estadoBicicleta!=2)
        {
            printf("\nA bicicleta que inseriu nao esta em reparacao.");
        }
        else
        {
            bicicletas[pos].estadoBicicleta=0;
        }
    }
}

void listarHistoricoEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos,tipoUtente utentes[MAX_UTENTES], int quantUtentes,tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas)
{
    int i,j,control=0,idUtente,posU;
    idUtente=lerInteiro("\nInsira numero de utente a procurar: ",0, MAX_IDUTENTES);
    posU=procurarUtente(utentes, quantUtentes, idUtente);
    if(posU==-1)
    {
        printf("\nUtente nao existe.");
    }
    else
    {
        for(i=quantEmprestimos-1; i>=0; i--)
        {
            if(emprestimos[i].idUtente==idUtente)
            {
                if(control==0)
                {
                    for(j=0; j<quantBicicletas; j++)
                    {
                        if(strcmp(emprestimos[i].idBicicleta,bicicletas[j].idBicicleta)==0)
                        {
                            printf("\nUltima bicicleta utilizada pelo utente [%d]:\n", idUtente);
                            mostrarDadosBicicletas(bicicletas[j]);
                            control=1;
                            j=quantBicicletas;
                        }

                    }
                }
                printf("\n\nEmprestimos do utente [%d]:", idUtente);
                mostrarDadosEmprestimos(emprestimos[i]);
            }
        }
    }
}


