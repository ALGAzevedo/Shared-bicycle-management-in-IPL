#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_bicicletas.h"
#include "funcoes_emprestimos.h"
#include "funcoes_lergravar.h"
#include "funcoes_utentes.h"
#include "menus.h"
#include "structs.h"



void gravarBicicletasBin(tipoBicicleta bicicletas[MAX_BICICLETAS],int *pQuantidadeBicicletas, float *pDistanciaTotal)
{
    int numLidos;
    FILE *ficheiro;
    ficheiro =fopen("bicicletas.dat", "wb");
    if(ficheiro==NULL)
    {
        printf("Ficheiro das bicicletas nao existe!");
    }
    else
    {
        numLidos=fwrite(pQuantidadeBicicletas,sizeof(int),1,ficheiro);
        printf("\n1-Elementos bicicletas gravados: %d",numLidos);
        numLidos=fwrite(pDistanciaTotal,sizeof(float),1,ficheiro);
        printf("\n1-Elementos bicicletas gravados: %d",numLidos);
        numLidos=fwrite(bicicletas,sizeof(tipoBicicleta),*pQuantidadeBicicletas,ficheiro);
        printf("\n2-Elementos bicicletas gravados: %d\n",numLidos);
    }

    fclose(ficheiro);
}

void lerBicicletasBin(tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas, float *pDistanciaTotal)
{
    int numLidos;

    FILE *ficheiro;
    ficheiro =fopen("bicicletas.dat", "rb");
    if(ficheiro==NULL)
    {
        printf("Ficheiro das bicicletas nao existe!");
    }
    else
    {
        numLidos=fread(pQuantidadeBicicletas,sizeof(int),1,ficheiro);
        printf("\n1-Elementos bicicletas lidos: %d",numLidos);
        numLidos=fread(pDistanciaTotal,sizeof(float),1,ficheiro);
        printf("\n1-Elementos bicicletas lidos: %d",numLidos);
        numLidos=fread(bicicletas,sizeof(tipoBicicleta),*pQuantidadeBicicletas,ficheiro);
        printf("\n2-Elementos bicicletas lidos: %d\n",numLidos);
    }
    fclose(ficheiro);
}


void gravarUtentesBin(tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes)
{
    int numLidos;

    FILE *ficheiro;
    ficheiro = fopen("utentes.dat", "wb");
    if(ficheiro==NULL)
    {
        printf("Ficheiro dos utentes nao existe!");
    }
    else
    {
        numLidos=fwrite(pQuantidadeUtentes,sizeof(int),1,ficheiro);
        printf("\n1-Elementos utentes gravados: %d", numLidos);
        numLidos=fwrite(utentes,sizeof(tipoUtente),(*pQuantidadeUtentes),ficheiro);
        printf("\n2-Elementos utentes gravados: %d",numLidos);
    }
    fclose(ficheiro);
}


void lerUtentesBin(tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes)
{
    int numLidos;

    FILE *ficheiro;
    ficheiro = fopen("utentes.dat", "rb");
    if(ficheiro==NULL)
    {
        printf("Ficheiro dos utentes nao existe!");
    }
    else
    {
        numLidos=fread(pQuantidadeUtentes,sizeof(int),1,ficheiro);
        printf("\n1-Elementos utentes lidos: %d", numLidos);
        numLidos=fread(utentes,sizeof(tipoUtente),(*pQuantidadeUtentes),ficheiro);
        printf("\n2-Elementos utentes lidos: %d",numLidos);
    }
    fclose(ficheiro);
}

void gravarEmprestimosBin(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos)
{
    int numLidos;

    FILE *ficheiro;
    ficheiro = fopen("emprestimos.dat", "wb");
    if(ficheiro==NULL)
    {
        printf("Ficheiro dos emprestimos nao existe!");
    }
    else
    {
        numLidos=fwrite(pQuantidadeEmprestimos,sizeof(int),1,ficheiro);
        printf("\n1-Elementos emprestimos gravados: %d", numLidos);
        numLidos=fwrite(emprestimos,sizeof(tipoEmprestimo),(*pQuantidadeEmprestimos),ficheiro);
        printf("\n2-Elementos emprestimos gravados: %d",numLidos);
        fclose(ficheiro);
    }
}


tipoEmprestimo* lerEmprestimosBin(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos)
{
    int numLidos;

    FILE *ficheiro;
    ficheiro = fopen("emprestimos.dat", "rb");
    if(ficheiro==NULL)
    {
        printf("\nImpossivel abrir ficheiro dos emprestimos");
        free(emprestimos);
        emprestimos= NULL;
        (*pQuantidadeEmprestimos)=0;
    }
    else
    {
        numLidos=fread(&(*pQuantidadeEmprestimos),sizeof(int),1,ficheiro);
        printf("\n1-Elementos emprestimos lidos: %d", numLidos);
        emprestimos=realloc(emprestimos, (*pQuantidadeEmprestimos)*sizeof(tipoEmprestimo));
        if(emprestimos==NULL && (*pQuantidadeEmprestimos)!=0)
        {
            printf("\nErro na reserva da memória");
            (*pQuantidadeEmprestimos)=0;
        }
        else
        {
            numLidos=fread(emprestimos,sizeof(tipoEmprestimo),(*pQuantidadeEmprestimos),ficheiro);
            printf("\n2-Elementos emprestimos lidos: %d",numLidos);
            fclose(ficheiro);
        }
    }
    return emprestimos;
}


void gravarAvariasLog(tipoAvaria avarias)
{
    FILE *ficheiro;
    ficheiro = fopen("log.txt", "a+");
    if(ficheiro==NULL)
    {
        printf("\nErro a abrir ficheiro log");
    }
    else
    {
        fprintf(ficheiro,"\nIdentificacao da bicicleta: %s",avarias.idBicicleta);
        fprintf(ficheiro,"\nDistancia total percorrida: %.2f",avarias.distanciaTotal);
        fprintf(ficheiro,"\nData da avaria: %d-%d-%d",avarias.dataAvaria.dia,avarias.dataAvaria.mes,avarias.dataAvaria.ano);
        fprintf(ficheiro,"\nHora da avaria: %02d:%02d",avarias.horaAvaria.horas,avarias.horaAvaria.minutos);
        fprintf(ficheiro,"\nDescricao da avaria: %s",avarias.descricao);
        printf("\n#Criado log da avaria em log.txt#");
        fclose(ficheiro);
    }
}



void gravarListaBin(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int *pSomaEspera)
{
    int numLidos;

    FILE *ficheiro;
    ficheiro = fopen("listaespera.dat", "wb");
    if(ficheiro==NULL)
    {
        printf("Ficheiro emprestimos nao existe!");
    }
    else
    {
        numLidos=fwrite(pQuantidadeEspera,sizeof(int),1,ficheiro);
        printf("\n1-Elementos lista de espera gravados: %d", numLidos);
        numLidos=fwrite(pSomaEspera,sizeof(int),1,ficheiro);
        printf("\n1-Elementos lista de espera gravados: %d", numLidos);
        numLidos=fwrite(listaEspera,sizeof(tipoEmprestimo),(*pQuantidadeEspera),ficheiro);
        printf("\n2-Elementos lista de espera gravados: %d",numLidos);
        fclose(ficheiro);
    }
}


tipoEmprestimo* lerListaBin(tipoEmprestimo *listaEspera, int *pQuantidadeEspera, int *pSomaEspera)
{
    int numLidos;

    FILE *ficheiro;
    ficheiro = fopen("listaespera.dat", "rb");
    if(ficheiro==NULL)
    {
        printf("\nImpossivel abrir ficheiro da lista");
        free(listaEspera);
        listaEspera= NULL;
        (*pQuantidadeEspera)=0;
        (*pSomaEspera)=0;
    }
    else
    {
        numLidos=fread(&(*pQuantidadeEspera),sizeof(int),1,ficheiro);
        printf("\n1-Elementos lista espera lidos: %d", numLidos);

        numLidos=fread(&(*pSomaEspera),sizeof(int),1,ficheiro);
        printf("\n1-Elementos lista espera lidos: %d", numLidos);

        listaEspera=realloc(listaEspera, (*pQuantidadeEspera)*sizeof(tipoEmprestimo));
        if(listaEspera==NULL && (*pQuantidadeEspera)!=0)
        {
            printf("\nErro na reserva da memória para a lista");
            (*pQuantidadeEspera)=0;
            (*pSomaEspera)=0;
        }
        else
        {
            numLidos=fread(listaEspera,sizeof(tipoEmprestimo),(*pQuantidadeEspera),ficheiro);
            printf("\n2-Elementos lista espera lidos: %d",numLidos);
        }
        fclose(ficheiro);
    }
    return listaEspera;
}


