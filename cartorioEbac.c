#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio - cria��o de vari�veis - strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim - cria��o de vari�veis - strings
	
	printf("### Registro de nomes ### \n\n");
	printf("CPF: "); //pedindo ao usu�rio valor da vari�vel
	scanf("%s", cpf); //armazenando valor da vari�vel - %s referindo � string
	
	strcpy(arquivo, cpf); //copiando valores das strings arquivo = cpf
	
	FILE *file; // criando o arquivo
	file = fopen(arquivo, "w"); //criando arquivo
	fprintf(file,cpf); //salvando informa��o no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //editando arquivo
	fprintf(file,","); //salvando informa��o no arquivo
	fclose(file); //fechando o arquivo
	
	printf("Nome: "); //pedindo informa��o ao usu�rio
	scanf("%s", nome); //salvando informa��o na string
	
	file = fopen(arquivo, "a"); //editando arquivo
	fprintf(file,nome); //salvando informa��o no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //editando arquivo
	fprintf(file, ","); //salvando informa��o no arquivo
	fclose (file); //fechando o arquivo
	
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose (file);
	
	printf("Cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
    system("pause");		
}

int consultar ()
{
setlocale(LC_ALL, "Portuguese");
	
char arquivo [40];
char cpf [40];
char nome [40];
char sobrenome [40];
char cargo [40];
char conteudo[100];
printf("### Consulta de usu�rios ### \n\n");
printf("Digite o CPF a ser consultado: ");
scanf("%s",cpf);
  	
FILE *file;
file = fopen(cpf,"r");
  	
if(file == NULL)
{
	printf("\nUsu�rio n�o localizado!\n\n");
}
	
while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");
}	

int deletar ()
{
	char cpf[40];
	
	printf("### 3. Deletar nomes ### \n\n");
    printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
			
    FILE *file;
    file = fopen(cpf, "r");
	
	if(file == NULL)
    {
    	system("cls");
		printf("O usu�rio n�o se encontra no sistema.\n\n");
    	system("pause");
	}
		
}

int main()
{
  	int opcao=0; //Definindo vari�veis
  	int laco=1; //Definindo vari�vel do la�o
  	
  	for(laco=1;laco=1;) //Definindo entrada / sa�da / incremento
  	{
	
        system("cls"); 	  
    	setlocale(LC_ALL,"Portuguese"); //Definindo linguagem (caract�res)
	
    	printf("### Cart�rio da EBAC ###\n\n"); //in�cio do Menu
    	printf("Escolha a op��o desejada do menu:\n\n"); //Orienta��o usu�rio
    	printf("\t1. - Registrar nomes\n"); //Op��es
    	printf("\t2. - Consultar nomes\n");
    	printf("\t3. - Deletar registro\n\n");
    	printf("Op��o: "); //fim do Menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls"); //Limpar tela
	
    	switch(opcao)
    	{
    		case 1:
			registrar ();
    		break;
    		
    		case 2:
			consultar ();
    		break;
    		
    		case 3:
    		deletar ();
    		break;
    		
    		default:
    		printf("### Essa op��o n�o est� dispon�vel ### \n\n");
    		system("pause");
    		break;
    	} //fim da sele��o
	
	} //fechamento do la�o
} //FIM DA FUN��O PRINCIPAL
