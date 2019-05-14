#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"
#include "funcoes_auxiliares.h"
#include "funcoes_bicicletas.h"
#include "funcoes_utentes.h"
#include "menus.h"
#include "constantes.h"


void inserirUtente(tipoUtente utentes[MAX_UTENTES],int *pQuantidadeUtentes)
{
    int i, idUtente, pos;

    //Se quantidade de utentes = MAX_UTENTES
    if((*pQuantidadeUtentes)==MAX_UTENTES)
    {
        printf("\n Nao pode acrescentar mais utentes.");
    }
    else
    {
        idUtente = lerInteiro("Insira um numero de utente", 0, MAX_IDUTENTES);
        pos = procurarUtente(utentes,*pQuantidadeUtentes,idUtente);

        //utentes[*pQuantidadeUtentes].idUtente=(*pQuantidadeUtentes);

        if(pos == -1)
        {
            utentes[*pQuantidadeUtentes].idUtente=idUtente;
            lerString("\nInsira nome do utente: ",utentes[*pQuantidadeUtentes].nomeUtente, MAX_STRING);
            //lerString("\nInsira numero de telefone: ", utentes.[*pQuantidadeUtentes].telefoneUtente, NUM_TELEFONE);
            utentes[*pQuantidadeUtentes].catUtente=lerInteiro("\nInsira o tipo de utente:\n\n0 - Convidado\n1 - Estudante\n2 - Docente\n3 - Tecnico Administrativo\n",0,3);
            utentes[*pQuantidadeUtentes].telefoneUtente=lerInteiro("\nInsira o numero de telefone do utente: ",910000000,969999999);
            utentes[*pQuantidadeUtentes].numEmprestimos=0;
            utentes[*pQuantidadeUtentes].distanciaUtente=0.0;
            utentes[*pQuantidadeUtentes].status=0;
            (*pQuantidadeUtentes)++;
        }
        else
        {
            printf("\nNumero de utente já existe");
        }
    }
}

int procurarUtente(tipoUtente utentes[MAX_UTENTES], int quantUtentes, int procura)
{

    int i, pos;
    pos=-1;

    for(i=0; i<quantUtentes; i++)
    {
        if(utentes[i].idUtente==procura)
        {
            pos=i;
            i=quantUtentes;
        }
    }
    return pos;
}


void consultarUtente(tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes)
{
    int pos, procura;

    procura = lerInteiro("\nInsira identificacao do utente:",0, MAX_IDUTENTES);
    pos = procurarUtente(utentes, *pQuantidadeUtentes, procura);
    if(pos==-1)
    {
        printf("\nUtente nao existe.");
    }
    else
    {
        mostrarDadosUtente(utentes[pos]);
    }
}

void mostrarDadosUtente(tipoUtente utente)
{
    printf("\nIdentificacao do utente: %d \nNome do utente: %s \nTelefone do utente: %d",utente.idUtente,utente.nomeUtente,utente.telefoneUtente);
    printf("\nTipo de utente: ");
    if(utente.catUtente==0)
    {
        printf("Convidado");
    }
    else
    {
        if(utente.catUtente==1)
        {
            printf("Estudante");
        }
        else
        {
            if(utente.catUtente==2)
            {
                printf("Docente");
            }
            else
            {
                printf("Tecnico administrativo");
            }
        }

    }
    printf("\nEmprestimos efetuados: %d\nDistancia percorrida: %.2f Km\n", utente.numEmprestimos,utente.distanciaUtente);
    printf("\nEstado: ");
    if(utente.status==0)
    {
        printf("Utente sem emprestimo em curso.\n");
    }
    else
    {
        printf("Utente com emprestimo em curso.\n");
    }
}

void alterarUtente(tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes)
{
    int pos, procura;

    procura = lerInteiro("\nInsira identificacao do utente:",0, MAX_UTENTES);

    pos = procurarUtente(utentes, *pQuantidadeUtentes, procura);

    if(pos==-1)
    {
        printf("\nUtente nao existe.");
    }
    else
    {
        mostrarDadosUtente(utentes[pos]);
        printf("\n\nAltere os dados do utente[%d]: ", procura);
        lerString("\nInsira nome do utente: ",utentes[procura].nomeUtente, MAX_STRING);
        utentes[procura].catUtente=lerInteiro("\nInsira o tipo de utente:\n\n0 - Convidado\n1 - Estudante\n2 - Docente\n3 - Tecnico Administrativo\n",0,3);
        utentes[procura].telefoneUtente=lerInteiro("\nInsira o numero de telemovel do utente: ",910000000,969999999);
    }
}

void listarDadosUtentes(tipoUtente utentes[MAX_UTENTES], int quantUtentes)
{
    int i;

    for(i=0; i<quantUtentes; i++)
    {
        mostrarDadosUtente(utentes[i]);
    }
}

void listarUtentesEmprestimos(tipoUtente utentes[MAX_UTENTES], int quantUtentes)
{

    int i,j,trocas;
    tipoUtente aux, aux2[MAX_UTENTES];
    aux2[MAX_UTENTES]=utentes[MAX_UTENTES];
    trocas=1;
    if(quantUtentes==0)
    {
        printf("\nNao existem emprestimos.");
    }
    else
    {
        for(j=0; j<quantUtentes-1 && trocas!=0; j++)
        {
            trocas=0;
            for(i=0; i<quantUtentes-j-1; i++)
            {
                if(utentes[i+1].numEmprestimos>utentes[i].numEmprestimos)
                {
                    trocas=1;
                    aux=utentes[i];
                    utentes[i]=utentes[i+1];
                    utentes[i+1]=aux;
                }
            }
        }
        listarDadosUtentes(utentes,quantUtentes);
        utentes[MAX_UTENTES]=aux2[MAX_UTENTES];
    }
}
