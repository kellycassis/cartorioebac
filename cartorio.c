#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include<string.h>// biblioteca respons�vel por cuindar das string

		//inicio registro
		
		
int registro()// fun��o respons�vel por cadastrar os usu�rios no sistema

{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/ String
	
	


// CPF a ser cadastrado
	printf("Digite o CPF a ser cadastrado:  ");// coletando informa��es do usu�rio
	scanf("%s",cpf);// %s refere-se a string (string conjunto de vari�veis)
	
	strcpy(arquivo,cpf);//respons�vel por copiar o valor das string
	
	// procedimento para gerar o arquivo e gravar o valor da vari�vel, no caso o cpf
	FILE *file;// cria o arquivo
	file = fopen(arquivo,"w");// cria o arquivo na pasta onde salvamos o sistma e o w significa escrever
	fprintf(file,cpf);// salvo o valor da vari�vel cpf
	fclose(file);// fecha o arquivo
	
	file=fopen(arquivo, "a"); // abre o arquivo que j� est� salvo na m�quina
	fprintf(file,",");// inclui no arquivo existente e atualiza colocando a virgura
	fclose(file);// fecha o aquivo
	

// Nome a ser cadastrado
	printf("Digite o nome a ser cadastrado:  ");//pergunta para o usu�rio // coletando o nome do usu�rio
	scanf("%s",nome);// o que o usu�rio digitar vamos salvar no string (%s)
	
	file=fopen(arquivo,"a");// abrir o arquivo
	fprintf(file,nome);// salvando o conte�do da variavel nome dentro do arquivo
	fclose(file);// fecha o arquivo
	
	file=fopen(arquivo, "a");// abre o arquivo
	fprintf(file,","); // incluindo a virgula dentro do conte�do
	fclose(file);// fecha o arquivo
	
//Sobrenome a ser cadastrado

	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);// armanzenar dentro da vari�vel sobrenome
	
	file=fopen(arquivo, "a");// abre o arquivo e salva dentro ( com o "a" de atualiza��o)
	fprintf(file,sobrenome);// atualiza com o sobrenome
	fclose(file);//fecha esse arquivo
	
	file=fopen(arquivo, "a");// abre o arquivo e atualiza
	fprintf(file,",");// atualiza com a v�rgula
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
	
	char cpf[40];// string conte�do deste arquivo
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:  ");// pergunta ao usu�rio
	scanf("%s",cpf);// salvar na vari�vel string
	
	FILE *file;//consulta o arquivo que j� est� pronto
	file = fopen(cpf,"r");//abre o arquivo cpf e leia (r)
	
	if(file == NULL)// usu�rio n�o localizado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	//fgets - indo buscar o arquivo
	while(fgets(conteudo, 200, file)  !=NULL)//quando precisamos fazer uma a��o at� acabar, usuamos um la�o de repeti��o
	// vai rodar 200 vezes dentro do arquivo at� lcoalizar todas as informa��es. vai parar quando for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo );// vai salvar o conte�do da vari�vel
		printf("\n\n");
				
	}
	
	system("pause");

}	//fim consulta



	// inicio Deletar
int deletar()// fun��o deletar
{
	char cpf[40];// char criar
	
	printf("Digitar o CPF a ser deletado:");// informa��o que aparece ao usu�rio
	scanf("%s", cpf); //procurar dentro da vari�vel cpf- string
	
	remove(cpf);// remove o cpf digitado pelo usu�rio
	
	FILE *file;
	file = fopen(cpf,"r");// abre o arquivo cpf e apagar (ler de read)
	
	if(file==NULL)
	{
		printf("Usu�rio deletado com sucesso!\n\n\n");
		printf("o usu�rio n�o se encontra no sistema.\n");
	
	}
	
	system("pause");// encerra
	
}


int main()
{
	int opcao=0;// Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a  linguagem
			
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("Op��o:");// fim do menu
			
			scanf("%d",&opcao); // armazenando a escolha do usu�rio
			
			
			system("cls");// respons�vel por limpar a tela
			
			switch(opcao)
			{
				case 1:
				registro();//chamada de fun��es
				break;
				
				case 2: 
				consulta();
				break;
								
				case 3:
				deletar();
				break;
																
				default:
				printf("Esta opcao n�o est� dispon�vel\n");
				system("pause");
				break;	
				
			}
	
			

		}	
		
}

