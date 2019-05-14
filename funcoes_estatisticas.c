#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "structs.h"
#include "funcoes_auxiliares.h"
#include "funcoes_emprestimos.h"
#include "menus.h"
#include "funcoes_utentes.h"
#include "funcoes_listaespera.h"
#include "funcoes_estatisticas.h"


int distanciaMedia(tipoEmprestimo vetor)
{
    int distancia;
    distancia = vetor.localDestino - vetor.localOrigem;
    distancia = abs(distancia);

    return distancia;
}


void distanciaMediaBicicletas(int quantBicicletas, int distanciaT)
{
    if(quantBicicletas!=0)
    {
        float media;
        media = distanciaT/(float)quantBicicletas;
        printf("\nDistancia media percorrida por cada bicicleta: %.2f Km", media);
    }
    printf("\nNao existem bicicletas para fazer calculo da distancia media.\n");
}



void campusMaisEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos)
{
    tipoContador campus[4]= {0}, aux;
    if(quantEmprestimos!=0)
    {
        int i,j,k,trocas;
        trocas=1;
        for(k=0; k<quantEmprestimos; k++)
        {
            if(emprestimos[k].localOrigem==0)
            {
                campus[0].campus=0;
                campus[0].contador++;
            }
            else
            {
                if(emprestimos[k].localOrigem==1)
                {
                    campus[1].campus=1;
                    campus[1].contador++;
                }
                else
                {
                    if(emprestimos[k].localOrigem==2)
                    {
                        campus[2].campus=2;
                        campus[2].contador++;
                    }
                    else
                    {
                        campus[3].campus=3;
                        campus[3].contador++;
                    }

                }
            }
        }
        for(i=0; i<4-1 && trocas!=0; i++)
        {
            trocas=0;
            for (j=0; j<4-i-1; j++)
            {
                if(campus[j+1].contador > campus[j].contador)  // > para decrescente
                {
                    trocas=1;
                    aux=campus[j];
                    campus[j]=campus[j+1];
                    campus[j+1]=aux;
                }
            }
        }
        printf("\nCampus com maior numero de emprestimos: ");
        if(campus[0].campus==0)
        {
            printf("Residencias.\n");
        }
        else
        {
            if(campus[0].campus==1)
            {
                printf("Campus1.\n");
            }
            else
            {
                if(campus[0].campus==2)
                {
                    printf("Campus2.\n");
                }
                else
                {
                    printf("Campus5.\n");
                }
            }

        }
    }
    else
    {
        printf("\nNao existem emprestimos.");
    }
}

void procuraBicicletaEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos,tipoBicicleta bicicletas[MAX_BICICLETAS], int quantBicicletas)
{
    int pos,i,contador=0;

    pos= procuraBicicleta(bicicletas,quantBicicletas);
    if(pos==-1)
    {
        printf("\nBicicleta nao existe.\n");
    }
    else
    {
        if(-1<pos && pos<quantBicicletas)
        {
            for(i=0; i<quantEmprestimos; i++)
            {
                if(strcmp(emprestimos[i].idBicicleta,bicicletas[pos].idBicicleta)==0)
                {
                    contador++;
                }
            }
            printf("\nA bicicleta [%s] foi usada por %d utentes.\n", bicicletas[pos].idBicicleta, contador);
        }
    }
}


void percEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos)
{
    int i,j;
    float percEmp;
    tipoContador categoria[4]= {0};

    if(quantEmprestimos!=0)
    {
        printf("\nPercentagem de emprestimos por tipo de utente: \n") ;
        for(i=0; i<quantEmprestimos; i++)
        {
            if(emprestimos[i].catUtente==0)
            {
                categoria[0].campus=0;
                categoria[0].contador++;
            }
            else
            {
                if(emprestimos[i].catUtente==1)
                {
                    categoria[1].campus=1;
                    categoria[1].contador++;
                }
                else
                {
                    if(emprestimos[i].catUtente==2)
                    {
                        categoria[2].campus=2;
                        categoria[2].contador++;
                    }
                    else
                    {
                        categoria[3].campus=3;
                        categoria[3].contador++;
                    }

                }
            }

        }
        for(j=0; j<4; j++)
        {
            percEmp= (categoria[j].contador/(float)quantEmprestimos)*100;
            if(categoria[j].campus==0)
            {
                printf("\nConvidados: \t\t %.2f %%", percEmp);
            }
            else
            {
                if(categoria[j].campus==1)
                {
                    printf("\nEstudantes: \t\t %.2f %%", percEmp);
                }
                else
                {
                    if(categoria[j].campus==2)
                    {
                        printf("\nDocentes: \t\t %.2f %%", percEmp);
                    }
                    else
                    {
                        printf("\nTecnicos administrativos: %.2f %%", percEmp);
                    }
                }
            }
        }
    }
    else
    {
        printf("\nNao existem emprestimos.");
    }
}


void emprestimosData(tipoEmprestimo *emprestimos, int quantEmprestimos)
{
    int i,cont=0;
    tipoData dataInicial, dataFinal;

    if(quantEmprestimos!=0)
    {
        printf("\nInsira data inicial: ");
        dataInicial=lerData();
        printf("\nInsira data final: ");
        dataFinal=lerData();
        for(i=0; i<quantEmprestimos; i++)
        {
            if(emprestimos[i].dataEmprestimo.ano>dataInicial.ano && emprestimos[i].dataEmprestimo.ano<dataFinal.ano)
            {
                cont++;
            }
            else
            {
                if(emprestimos[i].dataEmprestimo.ano==dataInicial.ano || emprestimos[i].dataEmprestimo.ano==dataFinal.ano)
                {
                    if(emprestimos[i].dataEmprestimo.mes>dataInicial.mes || emprestimos[i].dataEmprestimo.mes<dataFinal.mes)
                    {
                        cont++;
                    }
                    else
                    {
                        if(emprestimos[i].dataEmprestimo.mes==dataInicial.mes)
                        {
                            if(emprestimos[i].dataEmprestimo.dia>dataInicial.dia && emprestimos[i].dataEmprestimo.dia<dataFinal.dia)
                            {
                                cont++;
                            }

                        }
                        else
                        {
                            if(emprestimos[i].dataEmprestimo.mes==dataFinal.mes)
                            {
                                if(emprestimos[i].dataEmprestimo.dia>dataInicial.dia && emprestimos[i].dataEmprestimo.dia<dataFinal.dia)
                                {
                                    cont++;
                                }
                            }
                        }
                    }
                }
            }

        }
        printf("\nEntre as datas indicadas foram efetuados %d emprestimos.\n", cont);
    }
    else
    {
        printf("\nNao existem emprestimos.\n");
    }
}

