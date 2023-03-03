#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//Fun��o respons�vel por cadastras ps usu�rios no sistema.
{
	//In�cio da cria��o de vari�veis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/strings.
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //% se refere a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	printf("\nCadastro conclu�do com sucesso!\n\n");
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo, CPF n�o localizado!\n\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);	
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if (file == NULL)
	{
		printf("\nO CPF informado n�o consta no sistema! Por gentileza, verifique o CPF informado e tente novamente.\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0;
	int rep=1;
	
	for(rep=1;rep=1;) 
   {
		system("cls");
		setlocale(LC_ALL, "Portuguese");
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\nOp��o: ");
	
		scanf("%d", &opcao);
		
		system("cls");
	
	
		switch (opcao)
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
			
			default:
				printf("Op��o inv�lida!\n");
				system("pause");
			break;
		}
		
	
	}	

}
