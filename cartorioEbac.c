#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //função responsável por cadastrar usuários no sistema
{
	//início - criação de variáveis - strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim - criação de variáveis - strings
	
	printf("### Registro de nomes ### \n\n");
	printf("CPF: "); //pedindo ao usuário valor da variável
	scanf("%s", cpf); //armazenando valor da variável - %s referindo à string
	
	strcpy(arquivo, cpf); //copiando valores das strings arquivo = cpf
	
	FILE *file; // criando o arquivo
	file = fopen(arquivo, "w"); //criando arquivo
	fprintf(file,cpf); //salvando informação no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //editando arquivo
	fprintf(file,","); //salvando informação no arquivo
	fclose(file); //fechando o arquivo
	
	printf("Nome: "); //pedindo informação ao usuário
	scanf("%s", nome); //salvando informação na string
	
	file = fopen(arquivo, "a"); //editando arquivo
	fprintf(file,nome); //salvando informação no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //editando arquivo
	fprintf(file, ","); //salvando informação no arquivo
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
printf("### Consulta de usuários ### \n\n");
printf("Digite o CPF a ser consultado: ");
scanf("%s",cpf);
  	
FILE *file;
file = fopen(cpf,"r");
  	
if(file == NULL)
{
	printf("\nUsuário não localizado!\n\n");
}
	
while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");
}	

int deletar ()
{
	char cpf[40];
	
	printf("### 3. Deletar nomes ### \n\n");
    printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
			
    FILE *file;
    file = fopen(cpf, "r");
	
	if(file == NULL)
    {
    	system("cls");
		printf("O usuário não se encontra no sistema.\n\n");
    	system("pause");
	}
		
}

int main()
{
  	int opcao=0; //Definindo variáveis
  	int laco=1; //Definindo variável do laço
  	
  	for(laco=1;laco=1;) //Definindo entrada / saída / incremento
  	{
	
        system("cls"); 	  
    	setlocale(LC_ALL,"Portuguese"); //Definindo linguagem (caractéres)
	
    	printf("### Cartório da EBAC ###\n\n"); //início do Menu
    	printf("Escolha a opção desejada do menu:\n\n"); //Orientação usuário
    	printf("\t1. - Registrar nomes\n"); //Opções
    	printf("\t2. - Consultar nomes\n");
    	printf("\t3. - Deletar registro\n\n");
    	printf("Opção: "); //fim do Menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usuãrio
	
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
    		printf("### Essa opção não está disponível ### \n\n");
    		system("pause");
    		break;
    	} //fim da seleção
	
	} //fechamento do laço
} //FIM DA FUNÇÃO PRINCIPAL
