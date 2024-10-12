#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o 
#include <string.h> // Biblioteca por cuidar pelas strings 

int registro()
{
	char arquivo [40];//Inicio das vari�veis/string 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];//Final das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores das strings
	
	FILE *file;
	file = fopen(arquivo, "w");// criar arquivo e o "w" significa escrever
	fprintf(file,cpf);//Salvo o valor da variavel 
	fclose(file);//Fecho o arquivo 
	
	file = fopen(arquivo, "a");//O "a" serve para atualizar os dados 
	fprintf(file, ",");//Dar espa�o entre os arquivos
	fclose(file);//Fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);//Salvando a area criada nome 
	fclose(file);//Fechar o arquivo
	
	file = fopen(arquivo, "a");//O "a" serve para atualizar os dados 
	fprintf(file, ",");//Dar espa�o entre os arquivos
	fclose(file);//Fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem 
	
	char cpf[40];//Caracteres
	char conteudo[100];
	
	printf("Digite o conteudo a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
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
	
	printf("Digite o CPF do usu�rio a ser excluido: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
}


int main ()
{
	
	 int opcao=0;//Definindo as variaveis
	 int laco=1;
	 
	 for(laco=1;laco=1;)
	 {
	 
	  system("cls");
	
	setlocale(LC_ALL,"Portuguese");//Definindo a linguagem 
	
	printf("\tCart�rio da EBAC\n\n\n");//Inicio do menu
	printf("Escolha as op��es desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Op��o: ");//Final do menu
	
	scanf("%d", &opcao);//Armazenando a escolha do usu�rio 
	
	system("cls"); //Respos�vel por limpar a tela
	
	switch(opcao)
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
		printf("Essa op��o n�o est� dispon�vel!\n");
		system("pause");
		break;
	}
	

		
	}				
	
}

