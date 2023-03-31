#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include<string.h>// biblioteca responsável por cuindar das string

		//inicio registro
		
		
int registro()// função responsável por cadastrar os usuários no sistema

{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/ String
	
	


// CPF a ser cadastrado
	printf("Digite o CPF a ser cadastrado:  ");// coletando informações do usuário
	scanf("%s",cpf);// %s refere-se a string (string conjunto de variáveis)
	
	strcpy(arquivo,cpf);//responsável por copiar o valor das string
	
	// procedimento para gerar o arquivo e gravar o valor da variável, no caso o cpf
	FILE *file;// cria o arquivo
	file = fopen(arquivo,"w");// cria o arquivo na pasta onde salvamos o sistma e o w significa escrever
	fprintf(file,cpf);// salvo o valor da variável cpf
	fclose(file);// fecha o arquivo
	
	file=fopen(arquivo, "a"); // abre o arquivo que já está salvo na máquina
	fprintf(file,",");// inclui no arquivo existente e atualiza colocando a virgura
	fclose(file);// fecha o aquivo
	

// Nome a ser cadastrado
	printf("Digite o nome a ser cadastrado:  ");//pergunta para o usuário // coletando o nome do usuário
	scanf("%s",nome);// o que o usuário digitar vamos salvar no string (%s)
	
	file=fopen(arquivo,"a");// abrir o arquivo
	fprintf(file,nome);// salvando o conteúdo da variavel nome dentro do arquivo
	fclose(file);// fecha o arquivo
	
	file=fopen(arquivo, "a");// abre o arquivo
	fprintf(file,","); // incluindo a virgula dentro do conteúdo
	fclose(file);// fecha o arquivo
	
//Sobrenome a ser cadastrado

	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);// armanzenar dentro da variável sobrenome
	
	file=fopen(arquivo, "a");// abre o arquivo e salva dentro ( com o "a" de atualização)
	fprintf(file,sobrenome);// atualiza com o sobrenome
	fclose(file);//fecha esse arquivo
	
	file=fopen(arquivo, "a");// abre o arquivo e atualiza
	fprintf(file,",");// atualiza com a vírgula
	fclose(file);// fecha o arquivo
	

// Cargo a ser cadastrado

	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,",");
	fclose(file);
	
	system("pause");//fim registro
	
}

//Inicio Consulta
	
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a  linguagem
	
	char cpf[40];// string conteúdo deste arquivo
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:  ");// pergunta ao usuário
	scanf("%s",cpf);// salvar na variável string
	
	FILE *file;//consulta o arquivo que já está pronto
	file = fopen(cpf,"r");//abre o arquivo cpf e leia (r)
	
	if(file == NULL)// usuário não localizado
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	//fgets - indo buscar o arquivo
	while(fgets(conteudo, 200, file)  !=NULL)//quando precisamos fazer uma ação até acabar, usuamos um laço de repetição
	// vai rodar 200 vezes dentro do arquivo até lcoalizar todas as informações. vai parar quando for nulo
	{
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo );// vai salvar o conteúdo da variável
		printf("\n\n");
				
	}
	
	system("pause");

}	//fim consulta



	// inicio Deletar
int deletar()// função deletar
{
	char cpf[40];// char criar
	
	printf("Digitar o CPF a ser deletado:");// informação que aparece ao usuário
	scanf("%s", cpf); //procurar dentro da variável cpf- string
	
	remove(cpf);// remove o cpf digitado pelo usuário
	
	FILE *file;
	file = fopen(cpf,"r");// abre o arquivo cpf e apagar (ler de read)
	
	if(file==NULL)
	{
		printf("Usuário deletado com sucesso!\n\n\n");
		printf("o usuário não se encontra no sistema.\n");
	
	}
	
	system("pause");// encerra
	
}


int main()
{
	int opcao=0;// Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a  linguagem
			
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("Opção:");// fim do menu
			
			scanf("%d",&opcao); // armazenando a escolha do usuário
			
			
			system("cls");// responsável por limpar a tela
			
			switch(opcao)
			{
				case 1:
				registro();//chamada de funções
				break;
				
				case 2: 
				consulta();
				break;
								
				case 3:
				deletar();
				break;
																
				default:
				printf("Esta opcao não está disponível\n");
				system("pause");
				break;	
				
			}
	
			

		}	
		
}

