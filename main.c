
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcoes_auxiliares.h"
#include "structs.h"
#include "constantes.h"
#include "menus.h"
#include "funcoes_bicicletas.h"
#include "funcoes_utentes.h"
#include "funcoes_emprestimos.h"
#include "funcoes_lergravar.h"
#include "funcoes_listaespera.h"
#include "funcoes_estatisticas.h"



int main()                  //Inicio programa
{
    float distanciaTotal=0.0;
    float *pDistanciaTotal=NULL;
    int quantBicicletas=0, quantUtentes=0, quantEmprestimos=0,quantEspera=0, somaEspera=0;
    int *pQuantidadeBicicletas = NULL, *pQuantidadeUtentes=NULL, *pQuantidadeEmprestimos = NULL, *pQuantidadeEspera=NULL, *pSomaEspera=NULL;
    pQuantidadeBicicletas=&quantBicicletas;
    pQuantidadeUtentes=&quantUtentes;
    pQuantidadeEmprestimos=&quantEmprestimos;
    pQuantidadeEspera=&quantEspera;
    pDistanciaTotal = &distanciaTotal;
    pSomaEspera = &somaEspera;

    tipoBicicleta bicicletas[MAX_BICICLETAS];
    tipoUtente utentes[MAX_UTENTES];

    tipoEmprestimo *emprestimos;
    tipoEmprestimo *listaEspera;
    emprestimos=NULL;
    listaEspera=NULL;



    int idUtente, pos, pos2, local;
    tipoEmprestimo dados;




    //Inicio menu principal

    int op1,op2,op4,op5,op6,op7,op9;
    char op;

    do
    {
        printf("\n####################GESTAO DE BICICLETAS PARTILHADAS##############################\n#\n#\n");
        printf("# Quantidade de Utentes: %d\t\t\t\tEmprestimos Registados: %d\n# Distancia total percorrida: %.2f\t\t\tPedidos em lista de espera: %d\n#",*pQuantidadeUtentes, *pQuantidadeEmprestimos, *pDistanciaTotal, *pQuantidadeEspera);
        printf("\n# 1 - Bicicletas");
        printf("\n# 2 - Utentes");
        printf("\n# 3 - Emprestimos");
        printf("\n# 4 - Registar devolucao de bicicleta");
        printf("\n# 5 - Eliminar/alterar lista espera");
        printf("\n# 6 - Registar avaria/reparacao");
        printf("\n# 7 - Menu criterios de atribuicao dos pedidos em espera");
        printf("\n# 8 - Listar dados da ultima bicicleta utilizada por utilizador");
        printf("\n# 9 - Listar Utentes por ordem decrescente de emprestimos");
        printf("\n# 0 - Menu Estatisticas");
        printf("\n# G - Gravar em ficheiros binarios");
        printf("\n# L - Ler de ficheiros binarios");
        printf("\n# F - Fim do programa");
        printf("\n#\n# Opcao:");
        scanf("%s", &op);
        limpaBufferStdin();

        op=toupper(op);
        switch(op)
        {
        case '1':                         //Menu Bicicletas

            do
            {
                op1 = menuBicicletas();
                switch(op1)
                {
                case 1:
                    inserirBicicleta(bicicletas, pQuantidadeBicicletas);
                    break;
                case 2:
                    consultarBicicletas(bicicletas,pQuantidadeBicicletas);
                    break;
                case 3:
                    listarBicicletas(bicicletas, pQuantidadeBicicletas);
                    break;
                default:
                    printf("\nOpcao invalida.");
                }
                listaEspera=atualizaEspera(&emprestimos,listaEspera,bicicletas,utentes,pQuantidadeEmprestimos,pQuantidadeEspera, *pQuantidadeBicicletas,*pQuantidadeUtentes);
            }
            while(op1!=0);
            break;
        case '2':


            do
            {
                op2 = menuUtentes();
                switch(op2)
                {
                case 1:
                    inserirUtente(utentes,pQuantidadeUtentes);

                    break;
                case 2:
                    consultarUtente(utentes,pQuantidadeUtentes);

                    break;
                case 3:
                    alterarUtente(utentes,pQuantidadeUtentes);

                    break;
                case 4:
                    listarDadosUtentes(utentes,*pQuantidadeUtentes);

                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcao invalida.");
                    break;
                }
            }
            while(op2!=0);
            break;
        case '3':
            do
            {
                op4=menuEmprestimos();

                switch(op4)
                {
                case 1:
                    //emprestimos=registaEmprestimo(&listaEspera, pQuantidadeEspera, pSomaEspera, emprestimos,pQuantidadeEmprestimos,utentes,pQuantidadeUtentes,bicicletas,pQuantidadeBicicletas);



                    //VETOR DINAMICO TESTE NO MAIN

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
                                listaEspera = acrescentaListaEspera(listaEspera, pQuantidadeEspera, pSomaEspera, dados);
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
                            listaEspera = acrescentaListaEspera(listaEspera, pQuantidadeEspera, pSomaEspera, dados);
                        }

                    }


                    break;
                case 2:
                    consultarEmprestimos(emprestimos, pQuantidadeEmprestimos);
                    break;
                case 3:
                    listarDadosEmprestimos(emprestimos, pQuantidadeEmprestimos);
                    listarDadosListaEspera(listaEspera, pQuantidadeEspera);
                    break;
                default:
                    printf("\nOpcao invalida");
                }
            }
            while(op4!=0);
            break;
        case '4':
            registarDevolucao(bicicletas,*pQuantidadeBicicletas,utentes,*pQuantidadeUtentes,emprestimos,*pQuantidadeEmprestimos, pDistanciaTotal);
            break;
        case '5':
            do
            {
                op5 = menuListaEspera();
                switch(op5)
                {
                case 1:
                    listaEspera=eliminarEspera(listaEspera, pQuantidadeEspera, *pSomaEspera);
                    break;
                case 2:
                    listaEspera=alterarEspera(listaEspera, *pQuantidadeEspera, *pSomaEspera);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcao invalida");
                }
                listaEspera=atualizaEspera(&emprestimos,listaEspera,bicicletas,utentes,pQuantidadeEmprestimos,pQuantidadeEspera, *pQuantidadeBicicletas,*pQuantidadeUtentes);
            }
            while(op5!=0);
            break;
        case '6':
            do
            {
                op6 = menuAvarias();
                switch(op6)
                {
                case 1:
                    registarDevolucao(bicicletas,*pQuantidadeBicicletas,utentes,*pQuantidadeUtentes,emprestimos,*pQuantidadeEmprestimos, pDistanciaTotal);
                    registarAvaria(bicicletas, *pQuantidadeBicicletas);
                    break;
                case 2:
                    registarReparacao(bicicletas, *pQuantidadeBicicletas);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcao invalida");
                }
                listaEspera=atualizaEspera(&emprestimos,listaEspera,bicicletas,utentes,pQuantidadeEmprestimos,pQuantidadeEspera, *pQuantidadeBicicletas,*pQuantidadeUtentes);
            }
            while(op6!=0);
        case '7':
            do
            {
                op7=menuCriterios();
                switch(op7)
                {
                case 1:
                    listaEspera=ordenaListaEntrada(listaEspera, *pQuantidadeEspera);
                    break;
                case 2:
                    listaEspera=ordenaListaTipo(listaEspera, *pQuantidadeEspera);
                    break;
                case 3:
                    listaEspera=ordenaListaDistancia(listaEspera, *pQuantidadeEspera);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcao invalida!");
                }
            }
            while(op7!=0);
            break;
        case '8':
            listarHistoricoEmprestimos(emprestimos, *pQuantidadeEmprestimos, utentes, *pQuantidadeUtentes, bicicletas, *pQuantidadeBicicletas);
            break;
        case '9':
            listarUtentesEmprestimos(utentes,*pQuantidadeUtentes);
            break;
        case '0':
            do
            {
                op9=menuEstatisticas();

                switch(op9)
                {
                case 1:
                    campusMaisEmprestimos(emprestimos,*pQuantidadeEmprestimos);
                    break;
                case 2:
                    distanciaMediaBicicletas(*pQuantidadeBicicletas,*pDistanciaTotal);
                    break;
                case 3:
                    percEmprestimos(emprestimos, *pQuantidadeEmprestimos);
                    break;
                case 4:
                    procuraBicicletaEmprestimos(emprestimos,*pQuantidadeEmprestimos,bicicletas,*pQuantidadeBicicletas);
                    break;
                case 5:
                    emprestimosData(emprestimos, *pQuantidadeEmprestimos);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcao invalida!");
                    break;
                }
            }
            while(op9!=0);
            break;
        case 'G':
            gravarBicicletasBin(bicicletas, pQuantidadeBicicletas, pDistanciaTotal);
            gravarUtentesBin(utentes, pQuantidadeUtentes);
            gravarEmprestimosBin(emprestimos,pQuantidadeEmprestimos);
            gravarListaBin(listaEspera,pQuantidadeEspera,pSomaEspera);
            break;
        case 'L':
            lerBicicletasBin(bicicletas, pQuantidadeBicicletas, pDistanciaTotal);
            lerUtentesBin(utentes, pQuantidadeUtentes);
            emprestimos=lerEmprestimosBin(emprestimos, pQuantidadeEmprestimos);
            listaEspera=lerListaBin(listaEspera, pQuantidadeEspera, pSomaEspera);
            break;
        case 'F':
            printf("\nFim do programa.\n");
            break;
        default:
            printf("\nOpcao invalida!");
        }
        listaEspera=atualizaEspera(&emprestimos,listaEspera,bicicletas,utentes,pQuantidadeEmprestimos,pQuantidadeEspera, *pQuantidadeBicicletas,*pQuantidadeUtentes);
    }
    while(op!='F');

    free(listaEspera);
    free(emprestimos);
    listaEspera=NULL;
    emprestimos=NULL;
    return 0;                                   //Fim de programa
}

