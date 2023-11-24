#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

void linha(){
	printf("--------------------------------------------------\n");
}

void capslock(char str[]){
	//função pra deixar caracteres em minusculo.
	for(int i=0;i<strlen(str);i++){
		str[i]=tolower(str[i]);
	}
}

int checar(char str[])
{	//Função pra checar se o caracter é um numero.
	int k;
	k=strlen(str);
	for(int i=0;i<k;i++)
    {
		if(isdigit(str[i]))
        {
			return 1;
		}
	}return 0;
}

int checar_num(char str[])
{	//Função pra checar se o caracter é alfabético.
	int k;
	k=strlen(str);
	for(int i=0;i<k;i++)
    {
		if(isalpha(str[i]))
        {
			return 1;
		}
	}return 0;
}

int main()
{
setlocale(LC_ALL, "Portuguese");
while(1){
	FILE*p_arquivo;
	p_arquivo=fopen("bilheteria.txt","a");
	char nome[50],idade_str[4],inteira_str[5],meia_str[5],estudante[5];
	int idade=0,inteira=0,meia=0,total=0;
	//Limpando strings a cada sessão.
	nome[0]=0;
	idade_str[0]=0;
	inteira_str[0]=0;
	meia_str[0]=0;
	estudante[0]=0;
	
    printf("----------------BEM VINDO AO MUSEU!---------------\n");
linha();
    printf("\t     **Valores dos ingressos**\n");
	printf("\t\t **Inteira: 20R$**\n\t\t   **Meia: 10R$**");
	printf("\n    **Tema atual: Evolucao dos computadores.**\n");

linha();
	printf("Informe seu nome: ");
	scanf(" %[^\n]s",nome);
	while(checar(nome)){
		printf("Digite apenas letras!\n");
		scanf(" %[^\n]s",nome);
	}
linha();
	printf("Informe sua idade: ");
	scanf(" %[^\n]s",&idade_str);
	while(checar_num(idade_str)||atoi(idade_str)<=0){
		printf("Digite uma idade valida! Sem espaço e letras.\n");
		scanf(" %[^\n]s",idade_str);
	}
	idade=atoi(idade_str);
linha();
	printf("Digite a quantidade total de ingressos: ");
	scanf(" %[^\n]s",inteira_str);
	while(checar_num(inteira_str)||atoi(inteira_str)<=0){
		printf("Digite uma quantia valida! Sem espaço e letras.\n");
		scanf(" %[^\n]s",inteira_str);
	}
	inteira=atoi(inteira_str);
linha();
	printf("Gostaria de Meia-entrada para estudantes?(Sim/não)\n");
	scanf(" %[^\n]s",estudante);
	capslock(estudante);
	while(strcmp(estudante,"sim")!=0 && strcmp(estudante,"s")!=0 && strcmp(estudante,"nao")!=0 && strcmp(estudante,"n")!=0 ){
		printf("Digite apenas \"Sim\" ou \"Nao\"(SEM ACENTO!)\n");
		scanf(" %[^\n]s",estudante);
		capslock(estudante);
	}
	if (strcmp(estudante, "sim") == 0 || strcmp(estudante, "s") == 0 && strcmp(estudante,"nao")!=0 && strcmp(estudante, "n") != 0 && inteira>1){
		printf("De %d ingressos, quantos serão meia-entrada?\n",inteira);
		scanf(" %[^\n]s",meia_str);
		meia=atoi(meia_str);
		while(checar_num(meia_str)||atoi(meia_str)<=0||atoi(meia_str)>inteira){
			printf("Digite uma quantia valida! Sem espaço e letras.\n");
			scanf(" %[^\n]s",meia_str);
			meia=atoi(meia_str);
		}
	}
	else if((strcmp(estudante, "sim") == 0 || strcmp(estudante, "s") == 0 && strcmp(estudante,"nao")!=0 && strcmp(estudante, "n") != 0) && inteira==1){
		meia++;
	}
	inteira-=meia;
	total+=(meia*10)+(inteira*20);
linha();
	printf("Resultado\n");
	printf("Nome:%s\n",nome);
	printf("Idade:%d\n",idade);
	if(inteira>=1){
	printf("Ingressos inteira:%d\n",inteira);
	}
	if(meia>=1){
	printf("Ingressos meia-entrada:%d\n",meia);
	}
	printf("Qtd total de ingressos:%d\n",inteira+meia);
	printf("Total:%dR$\n",total);
	
	//imprimindo no arquivo
    fprintf(p_arquivo,"\nNome:%s\n",nome);
	fprintf(p_arquivo,"Idade:%d\n",idade);
	if(inteira>=1){
	fprintf(p_arquivo,"Ingressos inteira:%d\n",inteira);
	}
	if(meia>=1){
	fprintf(p_arquivo,"Ingressos meia-entrada:%d\n",meia);
	}
	fprintf(p_arquivo,"Qtd total de ingressos:%d\n",inteira+meia);
    fprintf(p_arquivo,"Total:%dR$\n",total);
    fprintf(p_arquivo,"--------------------------");
    fclose(p_arquivo);
linha();
    printf("Agradecemos pela preferencia.\nTenha uma ótima experiencia!\n");
linha();
    system("pause");
	system("cls");
}
}