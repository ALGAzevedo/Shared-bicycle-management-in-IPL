#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "constantes.h"

typedef struct
{
    int dia;
    int mes;
    int ano;
} tipoData;


typedef struct
{
    int horas;
    int minutos;
} tipoHora;


typedef struct
{
    tipoData dataDevolucao;
    tipoHora horaDevolucao;
    int distancia;
} tipoDevolucao;


typedef struct
{
    char idBicicleta[MAX_STRING];
    char modelBicicleta[MAX_STRING];
    int estadoBicicleta;
    int localBicicleta;
    float distanciaTotal;
    int numEmprestimos;
    int avarias;
} tipoBicicleta;


typedef struct
{
    int idUtente;
    char nomeUtente[50];
    int telefoneUtente;
    int catUtente;
    int numEmprestimos;
    float distanciaUtente;
    int status;
} tipoUtente;


typedef struct
{
    int numRegisto;
    int idUtente;
    int catUtente;
    char idBicicleta[MAX_STRING];
    tipoData dataEmprestimo;
    tipoHora horaEmprestimo;
    int localOrigem;
    int localDestino;
    tipoDevolucao devolucao;
    int distanciaPadrao;
} tipoEmprestimo;


typedef struct
{
    char idBicicleta[MAX_STRING];
    float distanciaTotal;
    tipoData dataAvaria;
    tipoHora horaAvaria;
    char descricao[MAX_STRING];
}tipoAvaria;


typedef struct
{
    int campus;
    int contador;
}tipoContador;
#endif
