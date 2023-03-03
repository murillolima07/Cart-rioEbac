#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//Função responsável por cadastras ps usuários no sistema.
{
	//Início da criação de variáveis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/strings.
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //% se refere a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file, cpf); //salva o valor da variável
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
	
	printf("\nCadastro concluído com sucesso!\n\n");
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
		printf("\nNão foi possível abrir o arquivo, CPF não localizado!\n\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);	
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if (file == NULL)
	{
		printf("\nO CPF informado não consta no sistema! Por gentileza, verifique o CPF informado e tente novamente.\n");
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
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\nOpção: ");
	
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
				printf("Opção inválida!\n");
				system("pause");
			break;
		}
		
	
	}	

}
