#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
#include <ctype.h> //biblioteca para converter resposatas para minuscula
#include <unistd.h> //biblioteca para utilizar a função access(), que verifica a existência e as permissões de acesso de um arquivo.

int registro() // Função para cadastrar úsuarios
{
	setlocale(LC_ALL, "Portuguese");
	
    char arquivo[40]; // Armazena o nome do arquivo
	char cpf[40]; // Armazena o CPF digitado pelo usuário
	char nome[40]; // Armazena o nome digitado pelo usuário
	char sobrenome[40]; // Armazena o sobrenome digitado pelo usuário
	char cargo[40]; // Armazena o cargo digitado pelo usuário
	char opcao; // Armazena a opção de continuar ou não o cadastro
	
	printf("=========================================\n\n");
	printf("     Digite o CPF a ser cadastrado\n\n");
	printf("=========================================\n\n");
	
	printf("CPF: ");
	scanf("%s", cpf);
	
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo

	FILE *file; // Declaração do ponteiro de arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo para escrita
	fprintf(file,cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo

	file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais informações
	fprintf(file,"\n"); // Adiciona uma quebra de linha
	fclose(file); // Fecha o arquivo

	system("cls"); // Limpa a tela
	
	// O mesmo padrão de operações é seguido para as informações de nome, sobrenome e cargo.

	printf("=========================================\n\n");
	printf("     Digite o nome a ser cadastrado\n\n");
	printf("=========================================\n\n");
	
	printf("Nome: ");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);

	system("cls");
	
	printf("=========================================\n\n");
	printf("   Digite o sobrenome a ser cadastrado\n\n");
	printf("=========================================\n\n");
	
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	    
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
 
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	system("cls");
	
	printf("=========================================\n\n");
	printf("     Digite o Cargo a ser cadastrado\n\n");
	printf("=========================================\n\n");
	
	printf("Cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("cls");
	
	printf("=========================================\n\n");
	printf("  Deseja realizar outro cadastro? (S/N)\n\n");
	printf("=========================================\n\n");
	printf("Opção: ");
	scanf(" %c", &opcao);
	
	opcao = tolower(opcao); // Converte a opção para minúscula

	while (opcao != 's' && opcao != 'n') 
	{
		system("cls");
		printf("\n=========================================\n\n");
		printf("\t    Opção inválida!\n\n      Digite S para novo cadastro\n\n      Digite N para voltar ao menu\n");
		printf("\n=========================================\n\n");
		printf("Opção: ");
		scanf(" %c", &opcao);
		
		opcao = tolower(opcao);
	}

	if (opcao == 's') {
		system("cls");
		return registro(); // Chamada recursiva para novo cadastro
	} else {
		return 0; // Retorno ao menu principal
	}
	
}

int consulta() //Função de consulta 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; // Armazena o CPF digitado pelo usuário
    char conteudo[200]; // Armazena o conteúdo lido do arquivo
  	int linha = 1; // Contador de linhas no arquivo

  	// Leitura do CPF
  	printf("=========================================\n\n");
  	printf("   Digite o CPF a ser consultado:\n\n");
  	printf("=========================================\n\n");
  	printf("CPF: ");
  	scanf("%s", cpf);

  	// Abertura do arquivo
  	FILE *file;
  	file = fopen(cpf, "r");

  	// Verificação de arquivo
	if (file == NULL)
  {
    system("cls");

    printf("=========================================\n\n");
    printf("\tCadastro não encontrado!\n\n");
    printf("=========================================\n\n");
    
    system("pause");

    return 1;
  }
    system("cls");
    
    
    
  // Leitura e exibição das informações
  while (fgets(conteudo, 200, file) != NULL)
  {
    switch (linha)
    {
    case 1:
    	printf("=========================================\n");
      printf("\n CPF: %s", conteudo);
      break;
    case 2:
      printf("\n Nome: %s", conteudo);
      break;
    case 3:
      printf("\n Sobrenome: %s", conteudo);
      break;
    case 4:
      printf("\n Cargo: %s\n\n", conteudo);
      printf("=========================================\n\n");
      break;
    }
    linha++;
  }

  // Fechamento do arquivo
  fclose(file);

  // Pausa
  system("pause");

  return 0;
	
}

int deletar() //Função de deletar
{
	char cpf[40]; // Armazena o CPF digitado pelo usuário
	char confirmar;
	
	printf("=========================================\n\n");
	printf("      Digite o CPF a ser deletado \n\n");
	printf("=========================================\n\n");
	printf("CPF: ");
	
	scanf("%s",cpf);
	
	system("cls");
	
	printf("=========================================\n\n");
	printf("    Tem certeza que deseja deletar \n        este cadastro? (S/N) \n\n");
	printf("=========================================\n\n");
	printf("Opção: ");
	scanf(" %c", &confirmar);
	
    if (confirmar == 'S' || confirmar == 's') // Verifica se o usuário digitou 'S' ou 's' para confirmar a exclusão
    {
        // Verifica se o arquivo com o CPF existe    
        if (access(cpf, F_OK) != -1) 
        {
            // Se o arquivo existe, tenta removê-lo
            if (remove(cpf) == 0) 
            {
                system("cls");
                
                printf("=========================================\n\n");
                printf("      Arquivo deletado com sucesso! \n\n");
                printf("=========================================\n\n");
            } 
            
            else 
            {
                system("cls");
                
                printf("=========================================\n\n");
                printf("\t Erro ao deletar o arquivo! \n\n");
                printf("=========================================\n\n");
            }
        } 
        
        else 
        {
            system("cls");
            
            printf("=========================================\n\n");
            printf("\t CPF não encontrado! \n\n");
            printf("=========================================\n\n");
        }
    }
    else
    {
        system("cls");
        
        printf("=========================================\n\n");
        printf("\t Operação cancelada! \n\n");
        printf("=========================================\n\n");
    }   
    
    system("pause"); // Pausa o programa
    return 0; // Retorna 0 indicando sucesso
}



int main()
{
	int opcao=0;//Definindo as variáveis
	int rep=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("=========================================\n\n");//Estética do menu
	printf("      Bem-vindo ao Cartório da Ebac\n\n Digite a senha de login de administrador: \n\n");
	printf("=========================================\n\n");
	printf("Opção: ");
	
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		for(rep=1;rep=1;)//Repetir o menu
		{
		
			system("cls");
			
	    	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
		
	    	printf("=========================================\n\n");//Estética do menu
		
	    	printf("\tCARTÓRIO DA EBAC\n\n");//Inicio
	    	printf("\tEscolha a opção desejada: \n\n");
	    	printf("\t1 - Registrar nomes\n");
	    	printf("\t2 - Consultar nomes\n");
	    	printf("\t3 - Deletar   nomes\n");
			printf("\t4 - Sair  do  menu \n\n");//Fim
	
	    	printf("\tFeito por Gedyel Kerllon\n\n");//Creditos
	
	    	printf("=========================================\n\n");//Estética do menu
	
	    	printf("Opção: ");
	
	    	scanf("%d", &opcao);//Armazenando escolha do usuário 
	
	    	system("cls");//Limpar menu
	    
	    
	    	switch(opcao) //inicio da seleção
	    	{
	    		case 1:
            	registro();
    			break;
    		
    			case 2:
    			consulta();
	    		break;
	    	
	    		case 3:
	    		deletar();
    			break;
    		
    			case 4:
    			printf("=========================================\n\n");
	    		printf("   Obrigado por utilizar o sistema!\n\n");
    			printf("=========================================\n\n");
    			return 0;
    			break;
    			
    			default:
    			printf("=========================================\n\n");
	    		printf("   Esta opção não está disponível!\n\n");
    			printf("=========================================\n\n");
    		
				system("pause");
	    		break;
	    	
			} //fim da seleção
		}
	}
	
	else
	    system("cls");
		printf("=========================================\n\n");
		printf("\t    Senha incorreta!\n\n");
		printf("=========================================\n\n");
		system("pause");
		return main();
}





