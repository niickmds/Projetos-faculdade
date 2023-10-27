// TRI - rec 6-9 
// Pedro Henrique isamu fagundes de souza tsukahara yoshissaro
// Juan Fernando Coucolis
// Diogo Casari Del Pino
// Nicolas Mariano da Silva
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct sthospede
{
	char nome[40];
	char cpf[11];
	char endereco[50];
	char telefone[15];
	char email[50];
};
				

void limparBuffer();
void fhospede(char nome[40], char c[11], char e[50], char t[15], char em[50]);
void clear(); 
void MostrarTabela (); 

int main()
{
    char tab[20][14];
    struct sthospede hospedes[20][14];
    int i, j; // i = linhas j = coluna
    int opcao;
    int escolha; // escolha se quer fazer cadastrou ou nao
    int hotel = 280; //numero total de quartos no hotel
    
    //gerar tabela
    for(i = 20; i >= 1; i--)
        for(j = 1; j <= 14; j++)
            tab[i][j] = '.';
    
    do
    {
        //menu de opcoes
        printf("\n===============================================\n");
        printf("+----------------------------+\n");
    	printf("|         Hotel Tri          |\n");
    	printf("|           Menu             |\n");
    	printf("+----------------------------+\n");
        printf("Digite a opcao desejada:\n");
        printf("1 - Mostrar os Quartos\n");
        printf("2 - Realizar Reserva\n");
        printf("3 - Realizar Check-In com reserva\n");
        printf("4 - Realizar Check-in sem reserva \n");
        printf("5 - Realizar Check-Out\n");
        printf("6 - Cancelar Reserva\n");
        printf("7 - Taxa de ocupacao\n");	
		printf("8 - Consultar quarto\n");
        printf("0 - sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        system("cls");
        printf("\n===============================================\n");
    
        switch(opcao)
        {
            case 1: //Mostrar os Quartos
            { 
                printf(" Apto ->");
                printf("\t");
                for(j = 1; j <= 14; j++)
                    printf(" %2d ", j);
                printf("\n\n");
            
                for(i = 20; i >= 1; i--)
                {   
                    printf(" Andar %2d\t", i); //numero da linha
                    for(j = 1; j <= 14; j++)
                        printf("  %c ", tab[i][j]);
                    printf("\n");    
                }
                
                printf("Pressione Enter para voltar ao menu.\n");
                limparBuffer();
                getchar();  // Aguarda o usuario pressionar Enter
                system("cls"); //limpa a tela
                break;
            }   
            
            case 2://Realizar Reserva
            {
                printf(" Apto ->");
                printf("\t");
                for(j = 1; j <= 14; j++)
                    printf(" %2d ", j);
                printf("\n\n");
            
                for(i = 20; i >= 1; i--)
                {   
                    printf(" Andar %2d\t", i); //numero da linha
                    for(j = 1; j <= 14; j++)
                        printf("  %c ", tab[i][j]);
                    printf("\n");    
                }
                        
                printf("Digite o andar (0 para voltar): ");
                scanf("%d", &i);

                if(i == 0)
                {
                	system("cls"); //limpa a tela
                    continue;
                }

                if(i < 0 || i > 20) //caso o andar seja invalido
                {
                    system("cls"); //limpa a tela
                    printf("\nAndar invalido.\n");
                    continue;
                }

        
                printf("Digite o apartamento: ");
                scanf("%d", &j);
                
                if(j < 0 || j > 14) //caso o apartamento seja invalido
                {
                    system("cls");
                    
                    printf("\nApartamento invalido.\n");
                    continue;    
                }   
        
                if(tab[i][j] == 'R')
                {
                    system("cls");
                    printf("\nQuarto ja ocupado, tente novamente.\n\n");
                    continue;
                }
                

                if(tab[i][j] == 'O')
                {
                    system("cls");
                    printf("\nJa fizeram Check In no quarto escolhido, tente novamente.\n\n");
                    continue;
                }
                else 
                    system("cls");
                	tab[i][j] = 'R';
                
                printf("Reserva realizada no quarto %d, andar %d\n", i, j );
                break;
            }
            
            case 3: //Realizar Check-In com reserva
            {
                printf(" Apto ->");
                printf("\t");
                for(j = 1; j <= 14; j++)
                    printf(" %2d ", j);
                printf("\n\n");
            
                for(i = 20; i >= 1; i--)
                {   
                    printf(" Andar %2d\t", i); //numero da linha
                    for(j = 1; j <= 14; j++)
                        printf("  %c ", tab[i][j]);
                    printf("\n");    
                }
            
                printf("Qual quarto voce deseja fazer Ckeck In\n");

                printf("Digite o andar (0 para voltar): ");
                scanf("%d", &i);

                if(i == 0)
                {
                	system("cls"); //limpa a tela
                    continue;
                }

                if(i < 0 || i > 20) //caso o andar seja invalido
                {
                    system("cls"); //limpa a tela
                    printf("\nAndar invalido.\n");
                    continue;
                }
        
                printf("Digite o apartamento: ");
                scanf("%d", &j);
                
                if(j < 0 || j > 14) //caso o apartamento seja invalido
                {
                    system("cls");
                    printf("\nApartamento invalido.\n");
                    continue;    
                }   

                if (tab[i][j] == '.')
                {
                    system("cls");
                    printf("\nO quarto ainda nao foi reservado.");
                    continue;
                }
                
                if(tab[i][j] == 'O')
                {
                    system("cls");
                    printf("\nO quarto ja esta ocupado, tente novamente.\n\n");
                    continue;
                }

                if(tab[i][j] != 'O')
                {
                    system("cls");
                    tab[i][j] = 'O';
                    printf("Check In realizado no quarto %d, andar %d", i,j);
            	}
            
                
    				printf("\nCadastro do hospede: ");
                	
						struct sthospede hospede;
				
						printf("\nNome: ");
						scanf("%s", &hospede.nome);
						clear();    
			
						printf("CPF: ");
						gets(hospede.cpf);
				
						printf("Endereco: ");
						gets(hospede.endereco);
	
						printf("Telefone: ");
						gets(hospede.telefone);
		
						printf("E-mail: ");
						gets(hospede.email);
						
						//nesse bloco o programa endereça os dados do hospede com o quarto desejado
						strcpy(hospedes[i][j].nome, hospede.nome); //strcpy = string copy, copia os dados de uma string e endereça pra outra
						strcpy(hospedes[i][j].cpf, hospede.cpf);
						strcpy(hospedes[i][j].endereco, hospede.endereco);
						strcpy(hospedes[i][j].telefone, hospede.telefone);
						strcpy(hospedes[i][j].email, hospede.email);
				
						system("cls");
						fhospede(hospede.nome, hospede.cpf, hospede.endereco, hospede.telefone, hospede.email);	
				
				  		printf("Pressione Enter para voltar ao menu.\n");
	                	getchar();  // Aguarda o usuario pressionar Enter
                		system("cls"); //limpa a tela
				
						printf("Cadastro realizado com sucesso! \n");
						break;
				
            }
                
            case 4: //Realizar Check-in sem reserva
            {   
                printf(" Apto ->");
                printf("\t");
                for(j = 1; j <= 14; j++)
                    printf(" %2d ", j);
                printf("\n\n");
            
                for(i = 20; i >= 1; i--)
                {   
                    printf(" Andar %2d\t", i); //numero da linha
                    for(j = 1; j <= 14; j++)
                        printf("  %c ", tab[i][j]);
                    printf("\n");    
                }
                
                
                printf("Voce escolheu a opcao de fazer check-in sem reserva\n");

                printf("Digite o andar (0 para voltar): ");
                scanf("%d", &i);

                if(i == 0)
                {
                	system("cls"); //limpa a tela
                    continue;
                }

                if(i < 0 || i > 20) //caso o andar seja invalido
                {
                    system("cls"); //limpa a tela
                    printf("\nAndar invalido.\n");
                    continue;
                }

        
                printf("Digite o apartamento: ");
                scanf("%d", &j);
                
                if(j < 0 || j > 14) //caso o apartamento seja invalido
                {
                    system("cls");
                    printf("\nApartamento invalido.\n");
                    continue;    
                }   
                
                if(tab[i][j] == 'O' || tab[i][j] == 'R')
                {
                	system("cls");
                	printf("Nao foi possivel fazer o Check In, pois o quarto ja esta ocupado\n");
                	continue;
				}
                
                system("cls");
                tab[i][j] = 'O';
                printf("Check In realizado no quarto %d, andar %d", i,j);
                
				printf("\Cadastro do hospede:");
                
					struct sthospede hospede;
			
					printf("\nNome: ");
					scanf("%s", &hospede.nome);
					clear();    
		
					printf("CPF: ");
					gets(hospede.cpf);
			
					printf("Endereco: ");
					gets(hospede.endereco);

					printf("Telefone: ");
					gets(hospede.telefone);
	
					printf("E-mail: ");
					gets(hospede.email);
					
					//nesse bloco o programa endereça os dados do hospede com o quarto desejado
					strcpy(hospedes[i][j].nome, hospede.nome); //strcpy = string copy, copia os dados de uma string e endereça pra outra
					strcpy(hospedes[i][j].cpf, hospede.cpf);
					strcpy(hospedes[i][j].endereco, hospede.endereco);
					strcpy(hospedes[i][j].telefone, hospede.telefone);
					strcpy(hospedes[i][j].email, hospede.email);
			
					system("cls");
					fhospede(hospede.nome, hospede.cpf, hospede.endereco, hospede.telefone, hospede.email);	
			
			  		printf("Pressione Enter para voltar ao menu.\n");
                	getchar();  // Aguarda o usuario pressionar Enter
            		system("cls"); //limpa a tela
			
					printf("Cadastro realizado com sucesso! \n");
					break;
			}
				
            case 5: //Realizar Check-Out
            {
                printf("opcao escolhida foi efetuar Check-out\n ");
                
                printf(" Apto ->");
                printf("\t");
                for(j = 1; j <= 14; j++)
                    printf(" %2d ", j);
                printf("\n\n");
            
                for(i = 20; i >= 1; i--)
                {   
                    printf(" Andar %2d\t", i); //numero da linha
                    for(j = 1; j <= 14; j++)
                        printf("  %c ", tab[i][j]);
                    printf("\n");    
                }
            
                printf("Digite o andar: ");
                scanf("%d", &i);


                if(i < 0 || i > 20) //caso o andar seja invalido
                {
                        printf("\nAndar invalido.\n");
                    continue;
                }

                printf("Digite o apartamento: ");
                scanf("%d", &j);
                
                if(j < 0 || j > 14) //caso o apartamento seja invalido
                {
                    system("cls");
                    printf("\nApartamento invalido.\n");
                    continue;    
                }
                    
                if(tab[i][j] == 'O')
                {
                    system("cls");
                    printf("Check out efetuado com sucesso, quarto do andar %d, apartamento %d, foi liberado!.\n",i, j);
                    tab[i][j] = '.';
                }
                else
                {
                    system("cls");
                    printf("\nEste quarto nao esta ocupado.\n");
                    continue;
                }
                continue;
            }
            
			case 6: //Cancelar Reserva
            {
                printf("opcao escolhida foi cancelar reserva\n");
                
                printf(" Apto ->");
                printf("\t");
                for(j = 1; j <= 14; j++)
                    printf(" %2d ", j);
                printf("\n\n");
            
                for(i = 20; i >= 1; i--)
                {   
                    printf(" Andar %2d\t", i); //numero da linha
                    for(j = 1; j <= 14; j++)
                        printf("  %c ", tab[i][j]);
                    printf("\n");    
                }
            
                printf("Digite o andar: ");
                scanf("%d", &i);


                if(i < 0 || i > 20) //caso o andar seja invalido
                {
                    printf("\nAndar invalido.\n");
                    continue;
                }

                printf("Digite o apartamento: ");
                scanf("%d", &j);
                
                if(j < 0 || j > 14) //caso o apartamento seja invalido
                {
                    system("cls");
                    printf("\nApartamento invalido.\n");
                    continue;    
                }
                    
                if(tab[i][j] == 'R')
                {
                    system("cls");
                    printf("Reserva cancelada.\n");
                    tab[i][j] = '.';
                }
                else if(tab[i][j] == 'O')
                {
                	system("cls");
                	printf("O quarto se econtra Ocupado");
                	continue;
				}
                else
                {
                    system("cls");
                    printf("\nEste quarto nao possui reserva.\n");
                    continue;
                }
                break;
            }
            
            case 7: //Taxa de ocupacao
            {
            		system("cls");
            		int occ; //taxa de ocupacao
    				int occr; //taxa de reserva
    				int oct; //taxa de ocupacaso geral 
    				int qlivre;
    				
            		printf("Opcao escolhida foi Ver taxa de ocupacao\n");
            		occ = 0;
            		occr = 0;
					for(i = 20; i >= 1; i--)
        				for(j = 1; j <= 14; j++)
        				{
	    					if(	tab[i][j] == 'R')			
							{
								occr++;			
							}		
						
							if( tab[i][j] == 'O')
							{
								occ++;
							}
									
						}
							
					qlivre = (280 - occ - occr);
					printf("Quartos Reservados: %d, Quartos Ocupados: %d, Quartos livres: %d", occr, occ, qlivre);
					break;
        		}
            
			case 8: //Consultar quarto
			{
				system("Cls");
				
			 	printf(" Apto ->");
                printf("\t");
                for(j = 1; j <= 14; j++)
                    printf(" %2d ", j);
                printf("\n\n");
            
                for(i = 20; i >= 1; i--)
                {   
                    printf(" Andar %2d\t", i); //numero da linha
                    for(j = 1; j <= 14; j++)
                        printf("  %c ", tab[i][j]);
                    printf("\n");    
                }
                
				printf("Digite o andar (0 para voltar): ");
                scanf("%d", &i);

                if(i == 0)
                {
                	system("cls"); //limpa a tela
                    continue;
                }

                if(i < 0 || i > 20) //caso o andar seja invalido
                {
                    system("cls"); //limpa a tela
                    printf("\nAndar invalido.\n");
                    continue;
                }
        
                printf("Digite o apartamento: ");
                scanf("%d", &j);
                
                if(j < 0 || j > 14) //caso o apartamento seja invalido
                {
                    system("cls");
                    printf("\nApartamento invalido.\n");
                    continue;    
                }
                
				if(tab[i][j] == 'O')
				{
					system("cls");
				    printf("Status do quarto andar %d, apartamento %d: Ocupado\n", i, j);
				    fhospede(hospedes[i][j].nome, hospedes[i][j].cpf, hospedes[i][j].endereco, hospedes[i][j].telefone, hospedes[i][j].email);
				    continue;
				} 
				else if(tab[i][j] == 'R')
				{
					system("cls");
				    printf("Status do quarto andar %d, apartamento %d: Reservado\n", i, j);
				    printf("Nenhum hospede encontrado\n\n");
				    continue;
				} 
				else 
				{
					system("cls");
				    printf("Status do quarto andar %d, apartamento %d: Apartamento Vazio\n", i, j);
				    printf("Nenhum hospede encontrado\n\n");
				    continue;
  				}
            	
            	
            	break;
			}
            
            case 0: //sair
            {
                printf("Voce saiu do programa.");
                break;
            }
            
            default:
            {
                printf("Opcao invalida. Tente novamente.\n");
            }
        }
        
        printf("\n");
    
    } while(opcao != 0);
    
}

void limparBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void fhospede(char nome[40], char c[11], char e[50], char t[15], char em[50])
{
	printf("Dados do cliente:\n");
	printf("\nNome: %s\n", nome);
	printf("CPF: %s\n", c);
	printf("Endereco: %s\n", e);
	printf("Telefone: %s\n", t);
	printf("E-mail: %s\n", em);
}

//limpeza do buffer do teclado
void clear()
{
	char carac;
	
	while((carac = fgetc(stdin)) != EOF && carac != '\n'){}
}
