//DOM-KLMN - Projeto Domino - Etapa 6
//20/09/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.cpp" 
#include "Dom_KLMN_Controller.h"

void fIniciarJogo () //inicio do jogo
{
	fflush(stdin); //limpar buffer
	
	int opcMenu;
	
	putchar('\n');
    
    do
	{
		putchar('\n');
		fMenuInicio(); //guardar a opcao escolhida pelo usuario
		
		switch(opc) //opcao para cada saida do menu
		{
			case 1: //inicio com 2 jogadores
				system("cls");
				fGerarDomino();
				fDoisJogadores ();
				jogoMaquina = false;
				break;
			case 2: //inicio com 1 jogador
			{
				system("cls");
				fGerarDomino();
				fUmJogador ();
				jogoMaquina = true;
				break;
			}
			case 3:
			{
				if (numeroJogadas == 0)
				{	
					system("cls");
					fMensagem("\nSem jogo iniciado.\n");
					break;
				}
				if (jogoMaquina)
					fUmJogador();
				else
					fDoisJogadores();
				break;
			}
			case 4:
			{
				system("cls");
				fGravaCadastro();
				break;
			}
			case 5:
			{
				system("cls");
				if (fRecuperarCadastro())
				{
					if (jogoMaquina)
						fUmJogador();
					else
						fDoisJogadores();
				}
				break;
			}
			case 6:
			{
				system("cls");
				fPrintRegras();
				break;
			}
			case 0: //sair do jogo
			{
				system("cls");
				char msg[] = "\nSaindo...\n";
				fMensagem (msg);
				return;
			}
			default:
			{
				system("cls");
				char msg[] = "\nOpcao invalida.";
				fMensagem (msg);
				break;
			}
		}
	} while (opcMenu != 0); //condicao de parada
}

void fGerarDomino () //gerar o domino inicial
{
	int i, j;
	int n = 0;
	numeroJogadas = 0; //inicializar numero de jogadas como 0
	fimJogo = false;
	qtdPecasDeposito = 14;
	
	for (i = 0; i <= 6; i++) 
	{
        for (j = i; j <= 6; j++) 
		{
            peca[n].lado1 = i;
            peca[n].lado2 = j;
            n++;
        }
    }
}

void fShuffle () //aleatorizar ordem das pecas
{
	srand(time(NULL));
	for (int i = 0; i < MAX; i ++)
	{
		int pecaAleatoria = rand() % MAX; 
		aux = peca[i];
		peca[i] = peca[pecaAleatoria];
		peca[pecaAleatoria] = aux;
	}
}

void fSepararPecas () //separar as pecas para cada jogador e deposito
{
	fShuffle ();
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (i < 7)
			peca[i].status = 1; //pecas do primeiro jogador
		else if (i < 14)
			peca[i].status = 2; //pecas do segundo jogador (ou computador)
		else
			peca[i].status = 3; //pecas do deposito
	}
}

void fPrimeiroLance() //definir de quem sera a primeira jogada
{
	int i, pj, dupla;
	pj = -1; //posicao da peca encontrada
	dupla = -1;
	//pesquisar entre as peças com lado1 = lado2
	for (i=0; i<14; i++)
	{
		if (peca[i].lado1 == peca[i].lado2)
		{
			if (peca[i].lado1 > dupla)
			{
				dupla = peca[i].lado1;
				pj = i;
			}
		}
	}
	//se nao encontrar, escolher a peca com maior soma
	if (pj == -1)
	{
		dupla = 0;
		for (i=0; i<14; i++)
		{
			if (peca[i].lado1 + peca[i].lado2 > dupla)
			{
				dupla = peca[i].lado1 + peca[i].lado2;
				pj = i;
			}
		}
	}
	//descobrir qual o jogador que jogou a primeira peca
	J = peca[pj].status;
	
	//carregar mesa com a primeira peca na posicao 0
	mesa[0].lado1 = peca[pj].lado1; mesa[0].lado2 = peca[pj].lado2;
	peca[pj].status = 4; //status da peca na mesa
	
	numeroJogadas++; //primeira jogada feita
	
}

void fUmJogador () //iniciar o jogo para um jogador contra a maquina
{
	int retorno;
	if (numeroJogadas == 0) //caso seja um jogo novo
	{
		fSepararPecas ();
		fPrimeiroLance();
		
		system("cls"); //limpar a tela
		
		fPrintPrimeiroJogador();
	}
	else
	{
		system("cls"); //limpar a tela
		J = (J == 1) ? 2 : 1; //metodo para manter o mesmo jogador caso nao seja jogo novo
	}
	
	do
	{	
	
		J = (J == 1) ? 2 : 1; //J = 1? se sim, J = 2, se nao, J = 1
		
		if (J == 2)
		{
			fJogadaMaquina();
		}
		else if (J == 1)
		{
			fMesa();
			if (fMenuJogador(J) == false) //se o jogador digitar para sair do jogo
				break;
			system("cls"); //limpar a tela para o proximo jogador
		}
		
		retorno = fChecarVencedor();
			
		if (retorno != 0)
		{
			fimJogo = true;
			fPrintVencedor(retorno);
			break;
		}
		
	} while (1);
}

void fDoisJogadores () //iniciar o jogo para dois jogadores
{
	int retorno;
	
	if (numeroJogadas == 0) //caso seja um jogo novo
	{
		fSepararPecas ();
		fPrimeiroLance();
		
		fPrintPrimeiroJogador();
	}
	else
		J = (J == 1) ? 2 : 1; //metodo para manter o mesmo jogador caso nao seja jogo novo
	
	do
	{
		
		J = (J == 1) ? 2 : 1; //J = 1? se sim, J = 2, se nao, J = 1
		
		fMesa();
		
		if (fMenuJogador(J) == false) //se o jogador digitar para sair do jogo
			break;
			
		retorno = fChecarVencedor();
			
		if (retorno != 0)
		{
			fimJogo = true;
			fPrintVencedor(retorno);
			break;
		}
			
		system("cls"); //limpar a tela para o proximo jogador
		
	} while (1);
}

void fJogadaMaquina()
{
	int i; 
	int qtdCompras = 0;
	bool jogadaPassada = false;
	do
	{
		for (indicePeca = 0; indicePeca < MAX; indicePeca++) //varrer todas as pecas disponiveis e descobrir se alguma delas e jogavel
		{
			if (peca[indicePeca].status == J && ((mesa[0].lado1 == peca[indicePeca].lado1 || mesa[0].lado1 == peca[indicePeca].lado2) || (mesa[numeroJogadas-1].lado2 == peca[indicePeca].lado1 || mesa[numeroJogadas-1].lado2 == peca[indicePeca].lado2)))
			{
				break;
			}
		}
		
		if (indicePeca >= MAX) //nenhuma peca do jogador e jogavel
		{
			if (fDepositoVazio() == false)
			{
				fCompra(J);
				qtdCompras++;
				continue;
			}
			else
			{	
				jogadaPassada = true; //jogada passada
				fPrintResultadoMaquina(qtdCompras, jogadaPassada);
				return;
			}
				
		}
		
		if (mesa[0].lado1 == peca[indicePeca].lado1 || mesa[0].lado1 == peca[indicePeca].lado2) //jogavel na esquerda
		{
			//deslocamento de toda a mesa para abrir a primeira posição 0
			for(i = numeroJogadas; i > 0; i--)
				mesa[i] = mesa[i-1];
		
			//verifica se será necessário inverter a peça a ser jogada e
			//joga na posição 0 da mesa
		
			if (peca[indicePeca].lado2 == mesa[0].lado1)
			{
				mesa[0].lado2 = peca[indicePeca].lado2;
				mesa[0].lado1 = peca[indicePeca].lado1;
			}
			else
			{
				mesa[0].lado2 = peca[indicePeca].lado1;
				mesa[0].lado1 = peca[indicePeca].lado2;
			}
		}
		else //jogavel somente na direita
		{
			if (peca[indicePeca].lado1 == mesa[numeroJogadas-1].lado2)
			{
				mesa[numeroJogadas].lado2 = peca[indicePeca].lado2;
				mesa[numeroJogadas].lado1 = peca[indicePeca].lado1;
			}
			else
			{
				mesa[numeroJogadas].lado2 = peca[indicePeca].lado1;
				mesa[numeroJogadas].lado1 = peca[indicePeca].lado2;
			}
		}
		
		numeroJogadas++;

		peca[indicePeca].status = 4; //atualiza o status da peça jogada
		
		break;
	
	} while (1);
	
	fPrintResultadoMaquina(qtdCompras, jogadaPassada);
	
	return; //jogada bem sucedida
}

bool fMenuJogador (int jogador) //ler as opcoes do menu
{
	
	do
	{
		
		fPrintPecas(jogador);
		char opc[2];

		fMensagem ("J - Jogar\nC - Comprar\nP - Passar\nS - Sair (fim de jogo)\n");

		opc[0] = fEscolhaChar();

		opc[0] = toupper(opc[0]); //deixar caractere minusculo maiusculo

		switch(opc[0])
		{
			case 'J': //jogar uma peca
				if (fJogada(jogador)) //se a jogada foi bem sucedida (ou seja, retorna true)
					return true;
				break;
			case 'C': //comprar uma peca
				fCompra(jogador);
				break;
			case 'P': //passar a jogada
			{
				if (fPecasJogaveis(jogador) == true) //se o jogador da vez tiver pecas para se jogar
				{
					fMensagem("\nPassagem bloqueada. O jogador tem pecas jogaveis.\n\n");
					break;
				}
				else if (fDepositoVazio() == false) //caso o deposito nao estiver vazio
				{
					fMensagem("\nPassagem bloqueada. O deposito nao esta vazio.\nVoce deve jogar ou comprar.\n\n");
					break;
				}
				fMensagem ("\nPassando jogada...");
				return true; //passar jogada
			}
			case 'S': //finalizar o jogo e voltar ao menu
			{
				system("cls");
				fMensagem ("\nFinalizando jogo...");
				return false; //sair do jogo
			}
			default:
			{
				fMensagem ("\nOpcao invalida.\n\n");
				break;
			}
		}

	} while (1);
	
}

bool fJogada(int jogador) //jogar
{
	
	if (fPecasJogaveis(jogador) == false)
	{
		system("cls");
		fMensagem("\nNao ha pecas disponiveis para jogada.\nVoce deve comprar uma peca.");
		fMesa();
		return false;
	}
	
	char opc[2];
	int pj, numeroPeca, aux;
	do
	{
		fMensagem ("Escolha a peca para jogar (0 para desistir).\n");
		opc[0] = fEscolhaChar();
		opc[0] = tolower(opc[0]); //convertendo o caractere para letra minuscula
		if (opc[0] == '0') //desistir da jogada
		{
			putchar('\n');
			return false;
		}
		else if (opc[0] == '\0' || opc[0] < 97 || opc[0] > indicePeca)
		{
			fMensagem ("\nOpcao invalida.\n\n");
			continue;
		}
	
		numeroPeca = (int)(opc[0]);

		aux = 97-1; //inicializado para 0 pecas
			
		for (pj = 0; pj < MAX; pj++)
		{
			if (peca[pj].status == jogador)
			{
				aux++; //mais uma peca pertencente ao usuario
				if (aux == numeroPeca)
				{
					break;
				}
			}
		}
		
		//pj agora possui o indice da peca a se jogar
		
		aux = fChecarPeca(pj); //checar se a peca e jogavel
			
		if (aux == 0) //a peca nao e jogavel
			continue;
		else if (aux == 1) //peca jogada na esquerda da mesa
			carregaMesaE(pj);
		else //peca jogada na direita da mesa
			carregaMesaD(pj);
			
		break;
		
	} while (1);
	
	return true;
}

int fChecarPeca(int i) //checar se a peca e valida
{
	char opc[2];
	
	if ((mesa[0].lado1 == peca[i].lado1 || mesa[0].lado1 == peca[i].lado2) && (mesa[numeroJogadas-1].lado2 == peca[i].lado1 || mesa[numeroJogadas-1].lado2 == peca[i].lado2))
	{
		
		fMensagem("Escolha um lado (E/D).\n");
		opc[0] = fEscolhaChar();
		
		if (opc[0] == 'd')
			return 2; //2 - direita
		else if (opc[0] == 'e')
			return 1; //1 - esquerda
		else
			return 0;	
	}
	
	if (mesa[0].lado1 == peca[i].lado1 || mesa[0].lado1 == peca[i].lado2)
	{
		return 1;
	}
	else if (mesa[numeroJogadas-1].lado2 == peca[i].lado1 || mesa[numeroJogadas-1].lado2 == peca[i].lado2)
	{
		return 2;
	}
	
	fMensagem ("Jogada invalida.\n\n");
	
	return 0;
	
}

void carregaMesaE(int Pj) //atualizar dados da mesa para jogada na esquerda
{
	//deslocamento de toda a mesa para abrir a primeira posição 0
	for(int i = numeroJogadas; i > 0; i--)
		mesa[i] = mesa[i-1];

	//verifica se será necessário inverter a peça a ser jogada e
	//joga na posição 0 da mesa

	if (peca[Pj].lado2 == mesa[0].lado1)
	{
		mesa[0].lado2 = peca[Pj].lado2;
		mesa[0].lado1 = peca[Pj].lado1;
	}
	else
	{
		mesa[0].lado2 = peca[Pj].lado1;
		mesa[0].lado1 = peca[Pj].lado2;
	}
	//atualiza a variável global mesaE com o ladoE agora atualizado

	numeroJogadas++;

	peca[Pj].status = 4; //atualiza o status da peça jogada

}

void carregaMesaD(int Pj) //atualizar dados da mesa para jogada na direita
{

	//verifica se será necessário inverter a peça a ser jogada e
	//joga na posição 0 da mesa

	if (peca[Pj].lado1 == mesa[numeroJogadas-1].lado2)
	{
		mesa[numeroJogadas].lado2 = peca[Pj].lado2;
		mesa[numeroJogadas].lado1 = peca[Pj].lado1;
	}

	else
	{
		mesa[numeroJogadas].lado2 = peca[Pj].lado1;
		mesa[numeroJogadas].lado1 = peca[Pj].lado2;
	}
	//atualiza a variável global mesaE com o ladoE agora atualizado

	numeroJogadas++;

	peca[Pj].status = 4; //atualiza o status da peça jogada
}

void fCompra(int jogador) //comprar peca
{
	for (int i = 14; i < 28; i++)
	{
		if (peca[i].status == 3) //status 3 = na mesa
		{
			peca[i].status = jogador; //peca comprada
			if (jogador == 1 || (jogador == 2 && !(jogoMaquina)))
			{
				system("cls");
				fMensagem("\nPeca comprada.");
				fMesa ();
			}
			qtdPecasDeposito--; //uma peca a menos no deposito
			return;
		}
	}
	if (jogador == 1 || (jogador == 2 && !(jogoMaquina)))
		fMensagem("\nNada a comprar.\n");
}

bool fDepositoVazio() //verificar se esta disponivel para compras
{
	for(int i = 0; i < 28; i++)
	{
		if (peca[i].status == 3) //se a peca estiver disponivel para compra
			return false;
	}
	return true;
}

bool fPecasJogaveis(int jogadorDaVez) //checa se ha pecas jogaveis para o jogador da vez
{
	int j;
	
	for (j = 0; j < MAX; j++) //varrer todas as pecas disponiveis e descobrir se alguma delas e jogavel
	{
		if (peca[j].status == jogadorDaVez && ((mesa[0].lado1 == peca[j].lado1 || mesa[0].lado1 == peca[j].lado2) || (mesa[numeroJogadas-1].lado2 == peca[j].lado1 || mesa[numeroJogadas-1].lado2 == peca[j].lado2)))
		{
			break;
		}
	}
	if (j >= MAX) 
	{
		return false; //nenhuma peca do jogador e jogavel
	}
	return true; //peca jogavel
}

int fChecarVencedor() //checar se ha um vencedor
{
	int i, pecas1 = 0, pecas2 = 0;
	
	for (i = 0; i < MAX; i++) //contar quantidade de pecas para cada jogador (1 e 2)
		{
			if (peca[i].status == 1)
				pecas1++;
			else if (peca[i].status == 2)
				pecas2++;
		}
	
	if (fDepositoVazio()) //se nao houver mais pecas compraveis
	{
		if (pecas1 == 0) //jogador 1 sem pecas
			return 1;
		else if (pecas2 == 0) //jogador 2 sem pecas
			return 1;
		else if (fPecasJogaveis(1) == false && fPecasJogaveis(2) == false) //se nenhum dos jogadores tiver pecas para jogar
		{
			if (pecas1 < pecas2) //se o jogador 1 tiver menos pecas
				return 2;
			else if (pecas2 < pecas1) //se o jogador 2 tiver menos pecas
				return 2;
				
			//quantidade de pecas igual
			pecas1 = pecas2 = 0;
				
			for (i = 0; i < MAX; i++) //soma cada lado de cada peca para descobrir quantos pontos
			{
				if (peca[i].status == 1)
					pecas1 += peca[i].lado1 + peca[i].lado2;
				else if (peca[i].status == 2)
					pecas2 += peca[i].lado1 + peca[i].lado2;
			}
			
			if (pecas1 < pecas2) //jogador 1 vence com menos pontos
				return 3;
			else //jogador 2 vence com menos pontos
				return 3;
		}	
	}
	
	return 0; //sem vencedores
}

void fGravaCadastro()
{
	if(numeroJogadas == 0)
	{
		fMensagem("\nSem jogo a ser gravado.\n");
		return;
	}
	else if (fimJogo == true)
	{
		fMensagem("\nJogo terminado nao pode ser gravado.\n");
		return;
	}
	
	int i;
	FILE *fp;
	FILE *fpm;
	FILE *fps;
	
	sitJogo.qtdJogadas = numeroJogadas;
	sitJogo.jogadorAtual = J;
	sitJogo.pecasDeposito = qtdPecasDeposito;
	
	if (jogoMaquina)
		sitJogo.jogadorComputador = true;
	else
		sitJogo.jogadorComputador = false;
		
	//Checagem de erros para abertura dos arquivos
		
	if ( (fp = fopen("CAD_DOMINO", "w") ) == NULL)
	{
		fMensagem("\nO arquivo CAD_DOMINO nao pode ser aberto para cadastro.\n");
		return;
	}
	if ( (fpm = fopen("CAD_MESA", "w") ) == NULL)
	{
		fMensagem("\nO arquivo CAD_MESA nao pode ser aberto para cadastro.\n");
		return;
	}
	if ( (fps = fopen("CAD_JOGO", "w") ) == NULL)
	{
		fMensagem("\nO arquivo CAD_JOGO nao pode ser aberto para cadastro.\n");
		return;
	}
	
	for (i = 0; i<MAX; i++)
	{
		if (fwrite(&peca[i], sizeof(struct pecas), 1, fp) != 1)
		{
			fMensagem("\nErro na gravacao do arquivo CAD_DOMINO.\n");
			break;
		}
	}
	
	for (i = 0; i<MAX; i++)
	{
		if (fwrite(&mesa[i], sizeof(struct mesa), 1, fpm) != 1)
		{
			fMensagem("\nErro na gravacao do arquivo CAD_MESA.\n");
			break;
		}
	}
	
	if (fwrite(&sitJogo, sizeof(struct jogo), 1, fps) != 1)
		fMensagem("\nErro na gravacao do arquivo CAD_JOGO.\n");
		
	
	//gravacao bem suscedida
	
	fclose(fps);
	fclose(fpm);
	fclose(fp);
	
	fMensagem("\nGravados os arquivos CAD_DOMINO, CAD_MESA e CAD_JOGO com sucesso.\n");

}

bool fRecuperarCadastro()
{
	int i;
	FILE *fp;
	FILE *fpm;
	FILE *fps;
	
	if ((fp = fopen("CAD_DOMINO", "r")) == NULL)
	{
		fMensagem("\nO arquivo CAD_DOMINO nao pode ser aberto.\n");
		return false;
	}
	if ((fpm = fopen("CAD_MESA", "r")) == NULL)
	{
		fMensagem("\nO arquivo CAD_MESA nao pode ser aberto.\n");
		return false;
	}
	if ((fps = fopen("CAD_JOGO", "r")) == NULL)
	{
		fMensagem("\nO arquivo CAD_JOGO nao pode ser aberto\.");
		return false;
	}
	
	for (i = 0; i<MAX; i++)
	{
		if (fread(&peca[i], sizeof(struct pecas), 1, fp) != 1)
			fMensagem("\nErro na gravacao do arquivo CAD_DOMINO.\n");
	}
	
	for (i = 0; i<MAX; i++)
	{
		if (fread(&mesa[i], sizeof(struct mesa), 1, fpm) != 1)
			fMensagem("\nErro na gravacao do arquivo CAD_MESA.\n");
	}
	
	if (fread(&sitJogo, sizeof(struct jogo), 1, fps) != 1)
			fMensagem("\nErro na gravacao do arquivo CAD_JOGO.\n");
	
	//gravacao bem suscedida
	
	fclose(fps); fclose(fpm); fclose(fp);
	
	//recuperar dados do jogo salvo
	
	numeroJogadas = sitJogo.qtdJogadas;
	
	J = sitJogo.jogadorAtual;
	
	qtdPecasDeposito = sitJogo.pecasDeposito;
	
	if (sitJogo.jogadorComputador)
		jogoMaquina = true;
	else
		jogoMaquina = false;
		
	fMensagem("\nRetornando ao jogo recuperado...\n\n");
	
	return true;

}