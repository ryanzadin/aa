#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espaco em memoria
#include <locale.h> //biblioteca de aloca��es de textos por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro(){
	//Inicio cria��o de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
    char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das string
	
	FILE *file; // cria  o arquivo
	file = fopen(arquivo, "w");// cria  o arquivo e o 'w' significa escrever
	fprintf(file, cpf); // salva  o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite um sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consultar(){

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL )
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system ("pause");
	
	
}

int deletar(){	

    char cpf[40];
    
    printf("Digite o CPF do usuario a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");// "r" le o arquivo
    
    if (file == NULL);
    {
	
       printf("O usuario n�o se encontra no sistema!.\n");
       system("pause");	
    
}  

}

int main()
{
	int opcao=0; //Definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
     system("cls");
     
	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	 printf("### Cartorio da EBAC ###\n\n");//Inicio do menu
 	 printf("Escolha uma das op��es abaixo:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n");
	 printf("\t4 - Sair do sistema.\n\n");
	 printf("Esse Softare � de livre usso dos alunos\n");
	 printf("Op��o: ");//Fim do menu
	
	 scanf("%d", &opcao);//Armazenando a escolha do usuario
	
	 system("cls");
	
	 switch(opcao)
	{
 	    case 1:
	 	registro();
 		break;
 		
 		case 2:
 		 consultar();
		 break;
		 
	 	case 3:
 	    deletar();
 		break;
 		
 		case 4:
 		printf("Obrigado por utilizar o sistema!\n");
 		return 0;
 		break;
 		
 		default:
 		 printf("Essa op��o n�o esta disponivel!");
 		system("pause");
 		break;
 		
 	}
 	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
