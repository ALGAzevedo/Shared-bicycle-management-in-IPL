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
#include "funcoes_estatisticas.h"

tipoEmprestimo *registaEmprestimo(tipoEmprestimo **listaEspera, int *pQuantidadeEspera, int *pSomaEspera, tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos, tipoUtente utentes[MAX_UTENTES], int *pQuantidadeUtentes, tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas)
{
    int idUtente, pos, pos2, local;
    tipoEmprestimo dados;

    //VETOR DINAMICO

    idUtente = lerInteiro("\nInsira o numero do utente: ", 0, MAX_IDUTENTES);
    pos = procurarUtente(utentes, *pQuantidadeUtentes, idUtente); //Verificar se utente existe
    if (pos == -1)
    {
        printf("\nUtente nao existe.");
    }
    else
    {
        dados.idUtente = utentes[pos].idUtente;
        dados.catUtente = utentes[pos].catUtente;
        local = lerInteiro("Insira campus de origem:\n\n0 - Residencias\n1 - Campus1\n2 - Campus2\n3 - Campus5\n", 0, 3);
        dados.localOrigem = local;
        do
        {
            dados.localDestino = lerInteiro("Insira campus de destino:\n\n0 - Residencias\n1 - Campus1\n2 - Campus2\n3 - Campus5\n", 0, 3);
        }
        while (dados.localDestino == local);

        dados.distanciaPadrao = distanciaMedia(dados);
        if(utentes[pos].status!=1)
        {
            pos2 = verificaBicicleta(bicicletas, pQuantidadeBicicletas, local);
            if (pos2 == -1)
            {
                printf("\nNao existem bicicletas disponiveis. Fica em lista de espera.");
                *listaEspera = acrescentaListaEspera(*listaEspera, pQuantidadeEspera, pSomaEspera, dados);
            }
            else
            {
                emprestimos = acrescentaEmprestimo(emprestimos, pQuantidadeEmprestimos, dados, bicicletas[pos2]);
                bicicletas[pos2].estadoBicicleta = 1;
                bicicletas[pos2].numEmprestimos++;
                utentes[pos].numEmprestimos++;
                utentes[pos].status=1;
                printf("\nEmprestimo registado com sucesso.\n");
            }

        }
        else
        {
            printf("\nUtente ja tem emprestimo em curso. Fica em lista de espera.\n");
            *listaEspera = acrescentaListaEspera(*listaEspera, pQuantidadeEspera, pSomaEspera, dados);
        }

    }
    return emprestimos;
}



tipoEmprestimo *acrescentaEmprestimo(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos, tipoEmprestimo dados, tipoBicicleta bicicleta)
{
    tipoEmprestimo *aux;
    aux = emprestimos;

    emprestimos = realloc(emprestimos, ((*pQuantidadeEmprestimos) + 1) * sizeof(tipoEmprestimo));
    if (emprestimos == NULL)
    {
        printf("\nErro a reservar memoria.");
        emprestimos = aux;
    }
    else
    {
        printf("\nInsira data e hora do emprestimo: ");
        dados.dataEmprestimo = lerData();
        dados.horaEmprestimo = lerHora();
        dados.numRegisto = (*pQuantidadeEmprestimos);
        emprestimos[*pQuantidadeEmprestimos] = dados;
        strcpy(emprestimos[*pQuantidadeEmprestimos].idBicicleta, bicicleta.idBicicleta);
        (*pQuantidadeEmprestimos)++;
    }
    return emprestimos;
}

int verificaBicicleta(tipoBicicleta bicicletas[MAX_BICICLETAS], int *pQuantidadeBicicletas, int local)
{
    int i, pos = -1;

    for (i = 0; i < (*pQuantidadeBicicletas); i++)
    {
        if (bicicletas[i].estadoBicicleta == 0 && bicicletas[i].localBicicleta == local)
        {
            pos = i;
            i = (*pQuantidadeBicicletas);
        }
    }
    return pos;
}

void consultarEmprestimos(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos)
{
    int pos;
    if (*pQuantidadeEmprestimos != 0)
    {
        pos = procuraEmprestimo(emprestimos, pQuantidadeEmprestimos);
        if (pos == -1)
        {
            printf("\nO numero de registo inserido nao corresponde a nenhum emprestimo ativo.");
        }
        else
        {
            printf("\nEMPRESTIMOS:\n ");
            mostrarDadosEmprestimos(emprestimos[pos]);
        }
    }
    else
    {
        printf("\nNao existem emprestimos ativos.");
    }
}

int procuraEmprestimo(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos)
{
    int i, pos = -1, procura;

    procura = lerInteiro("\nInsira numero de registo do emprestimo: ", 0, (*pQuantidadeEmprestimos) - 1);
    for (i = 0; i < (*pQuantidadeEmprestimos); i++)
    {
        if (emprestimos[i].numRegisto == procura)
        {
            pos = i;
            i = (*pQuantidadeEmprestimos);
        }
    }
    return pos;
}

void mostrarDadosEmprestimos(tipoEmprestimo emprestimo)
{
    printf("\nNumero de registo: %d\nCodigo do utente: %d\nDesignacao da bicicleta: %s\nData: %d-%d-%d\nHora: %02d:%02d", emprestimo.numRegisto, emprestimo.idUtente, emprestimo.idBicicleta, emprestimo.dataEmprestimo.dia, emprestimo.dataEmprestimo.mes, emprestimo.dataEmprestimo.ano, emprestimo.horaEmprestimo.horas, emprestimo.horaEmprestimo.minutos);
    printf("\nLocal de Origem: ");
    if (emprestimo.localOrigem == 0)
    {
        printf("Residencias");
    }
    else
    {
        if (emprestimo.localOrigem == 1)
        {
            printf("Campus1");
        }
        else
        {
            if (emprestimo.localOrigem == 2)
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
    if (emprestimo.localDestino == 0)
    {
        printf("Residencias");
    }
    else
    {
        if (emprestimo.localDestino == 1)
        {
            printf("Campus1");
        }
        else
        {
            if (emprestimo.localDestino == 2)
            {
                printf("Campus2");
            }
            else
            {
                printf("Campus5");
            }
        }
    }
    printf("\nDistancia media: %d\n", emprestimo.distanciaPadrao);

}

void listarDadosEmprestimos(tipoEmprestimo *emprestimos, int *pQuantidadeEmprestimos)
{
    int i;
    if ((*pQuantidadeEmprestimos) != 0)
    {
        printf("\nEmprestimos:\n");
        for (i = 0; i < (*pQuantidadeEmprestimos); i++)
        {
            mostrarDadosEmprestimos(emprestimos[i]);
        }
    }
    else
    {
        printf("\nNao existem emprestimos ativos.");
    }
}





/*
int distanciaMedia(tipoEmprestimo vetor)
{
    int distancia;
    distancia = vetor.localDestino - vetor.localOrigem;
    distancia = abs(distancia);

    return distancia;
}


void distanciaMediaBicicletas(int quantBicicletas, int distanciaT)
{
    float media;
    media = distanciaT/(float)quantBicicletas;
    printf("\nDistancia media percorrida por cada bicicleta: %.2f Km", media);
}



void campusMaisEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos)
{
    tipoContador campus[4]= {0}, aux;

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
        if(-1<pos<quantBicicletas)
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


void percEmprestimos(tipoEmprestimo *emprestimos, int quantEmprestimos,tipoUtente utentes[MAX_UTENTES], int quantUtentes)
{
    int i,j,k;
    float percEmp;
    tipoContador categoria[4]= {0};

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

*/

