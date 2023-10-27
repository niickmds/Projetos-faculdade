//DOM-KLMN - Projeto Domino - Etapa 6
//20/09/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_Model.h"


typedef struct pecas //estrutura para as pecas
{
	int lado1; int lado2; //valor numerico (1-6) de cada lado
	int status; // 1: primeiro jogador, 2: segundo jogador (ou computador), 3: para comprar, 4: mesa
} valoresPecas;


valoresPecas peca[MAX]; 
valoresPecas aux; //auxiliar para a randomizacao

struct mesa
{
	int lado1, lado2;
} mesa[MAX];

struct jogo
{
	int qtdJogadas; //quantidade de jogadas, tambem conta a quantidade de pecas na mesa
	int jogadorAtual; //o jogador da vez
	bool jogadorComputador; //jogador contra computador?
	int pecasDeposito; //quantas pecas ha no deposito
} sitJogo; //situacao do jogo



