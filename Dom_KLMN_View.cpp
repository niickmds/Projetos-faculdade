//DOM-KLMN - Projeto Domino - Etapa 6
//20/09/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.h"
void fMenuInicio () //visualizacao do menu
{

    printf("\n+-------------------------------------------------------+\n");
    printf("|                  Jogo de Domino (PUC-SP)              |\n");
    printf("|                                                       |\n");
    printf("| 1. Iniciar jogo (2 jogadores)                         |\n");
    printf("| 2. Iniciar jogo (1 jogador)                           |\n");
    printf("| 3. Voltar ao jogo                                     |\n");
    printf("| 4. Salvar jogo                                        |\n");
    printf("| 5. Recuperar jogo salvo                               |\n");
    printf("| 6. Regras do Jogo                                     |\n");
    printf("| 0. Sair do jogo                                       |\n");
    printf("+-------------------------------------------------------+\n\n");

	printf("Digite uma opcao: ");
	scanf("%d", &opc);

}

void fPrintPrimeiroJogador()
{
	if (opc == 2 && J == 2)
		printf("A primeira jogada foi da maquina.");
	else
		printf("A primeira jogada foi do jogador %d.", J);
}

void fPrintResultadoMaquina(int compras, bool jogadaFoiPassada)
{
	if (compras > 0)
	{
		if (jogadaFoiPassada)
			printf("\nA maquina comprou %d pecas e passou a jogada.", compras);
		else
			printf("\nA maquina comprou %d pecas e jogou a peca a peca [%d|%d].", compras, peca[indicePeca].lado1, peca[indicePeca].lado2);
	}
	else
	{
		if (jogadaFoiPassada)
			printf("\nA maquina passou a jogada.");
		else
			printf("\nA maquina jogou a peca [%d|%d].", peca[indicePeca].lado1, peca[indicePeca].lado2);
	}
}

void fMensagem (char *msg)
{
	printf("%s", msg);
}

void fMesa ()
{
	printf("\n\n===============\nM E S A:");

	int i, j;
	for (i = 0; i < numeroJogadas; i++)
	{
		printf(" [%d|%d]", mesa[i].lado1, mesa[i].lado2);
	}
	printf("\n===============\n\n");
}

void fPrintPecas (int jogador)
{
	printf("Pecas no deposito: %d\n\n", qtdPecasDeposito);
	
	indicePeca = 97; int i;
	
	printf("Jogador %d\t Pecas: ", jogador);
	for (i = 0; i < MAX; i++)
	{
		if (peca[i].status == jogador) //se a peca pertencer ao jogador
		{
			printf(" %c.[%d|%d]", indicePeca, peca[i].lado1, peca[i].lado2);
			indicePeca++;
		}
	}
	printf("\n---------------\n\n");
}

void fPrintVencedor(int resultado)
{
	//system("cls");
	
	switch(resultado)
	{
		case 1:
		{
			if (opc == 2 && J == 2)
				printf("\nVOCE PERDEU! A MAQUINA TERMINOU AS PECAS.\n");
			else
				printf("\nPARABENS, JOGADOR %d, VOCE TERMINOU AS PECAS E VENCEU O JOGO!\n", J);
			break;
		}
		case 2:
		{
			if (opc == 2 && J == 2)
				printf("\nVOCE PERDEU! NAO HAVIAM PECAS JOGAVEIS E A MAQUINA TERMINOU COM MENOS PECAS.\n");
			else
				printf("\nPARABENS, JOGADOR %d, VOCE VENCEU COM MENOS PECAS!\n", J);
			break;
		}
		case 3:
		{
			if (opc == 2 && J == 2)
				printf("\nVOCE PERDEU! NAO HAVIAM PECAS JOGAVEIS A MAQUINA TINHA MAIS PONTOS POR PECA.\n");
			else
				printf("\nPARABENS, JOGADOR %d, VOCE VENCEU COM MAIS PONTOS POR PECA!\n", J);
			break;
		}
	}
}

char fEscolhaChar()
{
	char opcaoEscolha[2];
	do
	{
		fMensagem ("Opcao: ");
		fflush(stdin); //limpar o buffer
		scanf("%c", &opcaoEscolha[0]);
		if (opcaoEscolha[0] == '\0') //caso nada tenha sido digitado
			fMensagem ("\nOpcao invalida.");
		opcaoEscolha[0] = tolower(opcaoEscolha[0]);
	} while (opcaoEscolha[0] == '\0');
	
	return (opcaoEscolha[0]);
}

void fPrintRegras ()
{
	printf("\n----Regras do Jogo de Domino----\n\n");
    printf("1. Cada jogador comeca com sete pecas aleatorias e pode comprar mais quando necessario.\n");
    printf("2. O jogo comeca com o jogador que tiver a peca 'seis-seis', ou, se ninguem tiver, o jogador\n");
	printf("com os numeros repetidos mais altos.\n");
    printf("3. O jogo segue no sentido anti-horario.\n");
    printf("4. Coloque pecas com numeros correspondentes as extremidades da mesa.\n");
    printf("5. O jogador que comeca leva vantagem.\n");
    printf("6. Antes de cada jogada, um jogador pode comprar pecas do deposito.\n");
    printf("7. O jogador com mais pecas no final perde a partida.\n");
    printf("8. Se um jogador nao puder jogar, ele compra pecas ate poder jogar ou o deposito se esgota.\n");
    printf("9. O jogador so pode passar a jogada se nao tiver pecas para jogar e o deposito estiver vazio.\n");
    printf("10. O jogo continua ate que o estoque de pecas disponiveis para compra se esgote ou uma das\n"); 
	printf("seguintes situacoes ocorra:\n");
    printf("    - Um jogador coloca sua ultima peca na mesa (isso e chamado de 'bater') e ele vence.\n");
    printf("    - Nenhum jogador pode continuar a partida, e o deposito de pecas esta vazio; nesse caso,\n");
	printf("      a partida esta fechada, e o jogador com menos pecas ou menos pontos nas pecas vence.\n\n");
	
	system("pause.");
}
