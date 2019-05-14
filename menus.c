#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "structs.h"
#include "funcoes_auxiliares.h"
#include "menus.h"
#include "funcoes_bicicletas.h"
#include "funcoes_utentes.h"



int menuBicicletas()
{
    int op1;

    printf("\n#######GESTAO DE BICICLETAS PARTILHADAS#######\n\n");
    printf("\n\nMenu Bicicletas\n");
    printf("\n1 - Inserir bicicleta");
    printf("\n2 - Consultar bicicleta");
    printf("\n3 - Listar dados de bicicletas");
    printf("\n0 - Recuar");
    printf("\n\nOpcao: ");
    scanf("%d", &op1);
    limpaBufferStdin();

    return op1;
}

int menuUtentes()
{
    int op2;

    printf("\n#######GESTAO DE BICICLETAS PARTILHADAS#######\n\n");
    printf("\n\nMenu Utentes\n");
    printf("\n1 - Inserir utente");
    printf("\n2 - Consultar utente");
    printf("\n3 - Alterar utente");
    printf("\n4 - Listar dados dos utentes");
    printf("\n0 - Recuar");
    printf("\n\nOpcao: ");
    scanf("%d", &op2);

    limpaBufferStdin();

    return op2;
}

int menuEmprestimos()
{
    int op4;

    printf("\n#######GESTAO DE BICICLETAS PARTILHADAS#######\n\n");
    printf("\n\nMenu Emprestimos\n");
    printf("\n1 - Registar emprestimo");
    printf("\n2 - Consultar emprestimo");
    printf("\n3 - Listar dados dos emprestimos e lista de espera");
    printf("\n0 - Recuar");
    printf("\n\nOpcao: ");
    scanf("%d", &op4);

    limpaBufferStdin();

    return op4;
}

int menuListaEspera()
{
    int op5;

    printf("\n#######GESTAO DE BICICLETAS PARTILHADAS#######\n\n");
    printf("\n\nMenu Lista Espera\n");
    printf("\n1 - Eliminar da lista");
    printf("\n2 - Alterar Destino");
    printf("\n0 - Recuar");
    printf("\n\nOpcao: ");
    scanf("%d", &op5);

    limpaBufferStdin();

    return op5;
}

int menuAvarias()
{
    int op6;

    printf("\n#######GESTAO DE BICICLETAS PARTILHADAS#######\n\n");
    printf("\n\nMenu Avarias\n");
    printf("\n1 - Registar avaria");
    printf("\n2 - Registar reparacao");
    printf("\n0 - Recuar");
    printf("\n\nOpcao: ");
    scanf("%d", &op6);

    limpaBufferStdin();

    return op6;
}


int menuCriterios()
{
    int op7;

    printf("\n#######GESTAO DE BICICLETAS PARTILHADAS#######\n\n");
    printf("\n\nDefina criterio de atribuicao da lista de espera\n");
    printf("\n1 - Por ordem de entrada do pedido");
    printf("\n2 - Tipo de Utente (Prioridade: Tecnico->Docente->Estudante->Convidado");
    printf("\n3 - Distancia a percorrer entre os campi");
    printf("\n0 - Recuar");
    printf("\n\nOpcao: ");
    scanf("%d", &op7);

    limpaBufferStdin();

    return op7;
}


int menuEstatisticas()
{
    int op;

       printf("\n#######GESTAO DE BICICLETAS PARTILHADAS#######\n\n");
    printf("\n\nMenu Estatisticas:\n");
    printf("\n1 - Campus com mais emprestimos");
    printf("\n2 - Distancia media percorrida por cada bicicleta");
    printf("\n3 - Percentagem de emprestimos por tipo de utente ");
    printf("\n4 - Quantidade de utentes que utilizaram uma bicicleta");
    printf("\n5 - Emprestimos entre duas datas");
    printf("\n0 - Recuar");
    printf("\n\nOpcao: ");
    scanf("%d", &op);

    limpaBufferStdin();
    return op;
}
