#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
void linha()
{
	printf("------------------------------------\n");
}

void capslock(char str[]){
	//função pra deixar caracteres em minusculo.
	for(int i=0;i<strlen(str);i++){
		str[i]=tolower(str[i]);
	}
}

int checar(char str[]){
	//função pra checar se o caracter é um numero.
	int k;
	k=strlen(str);
	for(int i=0;i<k;i++){
		if(isdigit(str[i])){
			return 1;
		}
	}return 0;
}

int checar_num(char str[]){
	//função pra checar se o caracter NÂO é um numero.
	int k;
	k=strlen(str);
	for(int i=0;i<k;i++){
		if(!isdigit(str[i])){
			return 1;
		}
	}return 0;
}

int main()
{
setlocale(LC_ALL, "Portuguese");
	char nome[45],opiniao[250],sug[4],sugestao[250],volta[4],idade_str[4],nota_str[4];
	int idade,nota;
while(1){
	nome[0]=0;
	opiniao[0]=0;
	sugestao[0]=0;
	volta[0]=0;
	idade_str[0]=0;
	nota_str[0]=0;
	idade=0;
	nota=0;
	
	FILE*p_arquivo;
	p_arquivo=fopen("arquivo.txt","a");
	printf("Nos de sua opinião!\n");
linha();
	printf("Nome: ");
	scanf(" %[^\n]s",nome);
	while(checar(nome)){
		printf("Digite apenas letras!\n");
		scanf(" %[^\n]s",nome);
	}
linha();
	printf("Idade: ");
	scanf(" %[^\n]s",idade_str);
	while(checar_num(idade_str)||atoi(idade_str)<=0){
		printf("Digite uma idade valida! Sem espaço e letras.\n");
		scanf(" %[^\n]s",idade_str);
	}
	idade=atoi(idade_str);
linha();
	printf("De 0 a 5 avalie esta obra: ");
	scanf(" %[^\n]s",&nota_str);
	while(checar_num(nota_str)||(atoi(nota_str)<0 || atoi(nota_str)>5)){
		printf("Digite uma nota valida! Apenas numeros.\n");
		scanf(" %[^\n]s",&nota_str);
	}	
	nota=atoi(nota_str);
linha();
	printf("O que achou desta obra? ");
	scanf(" %[^\n]s",opiniao);
linha();
	printf("Veria esta obra novamente?(Sim/Não)\n");
	scanf(" %[^\n]s",volta);
	capslock(volta);
	while(strcmp(volta,"sim")!=0 && strcmp(volta,"s")!=0 && strcmp(volta,"nao")!=0 && strcmp(volta,"n")!=0 ){
		printf("Digite apenas \"Sim\" ou \"Não\"\n");
		scanf(" %[^\n]s",volta);
		capslock(volta);
	}
linha();
	printf("Gostaria de contribuir com sugestões\nou críticas? (Sim/Não)");
	scanf(" %[^\n]s",sug);
	capslock(sug);
	while(strcmp(sug,"sim")!=0 && strcmp(sug,"s")!=0 && strcmp(sug,"nao")!=0 && strcmp(sug,"n")!=0 ){
		printf("Digite apenas \"Sim\" ou \"Não\"\n");
		scanf(" %[^\n]s",sug);
		capslock(sug);
	}
	if (strcmp(sug, "sim") == 0 || strcmp(sug, "s") == 0 && strcmp(sug, "nao") != 0 && strcmp(sug, "n") != 0) {
		printf("Nos ajude com sugestões, criticas e etc..:\n");
		scanf(" %[^\n]s",sugestao);
	}
linha();
	printf("Resultado");
    printf("\nNome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Nota: %d\n", nota);
    printf("Opinião: %s\n", opiniao);
    printf("Visitaria novamente? %s\n", volta);
    printf("Sugestões/Críticas: %s\n", sugestao);
linha();
	printf("Obrigado pelo feedback. Volte sempre!\n");
linha();
	system("pause");
    fprintf(p_arquivo,"\nNome: %s\n", nome);
    fprintf(p_arquivo,"Idade: %d\n", idade);
    fprintf(p_arquivo,"Nota: %d\n", nota);
    fprintf(p_arquivo,"Opinião: %s\n", opiniao);
    fprintf(p_arquivo,"Visitaria novamente? %s\n", volta);
    fprintf(p_arquivo,"Sugestões/Críticas: %s\n", sugestao);
    fprintf(p_arquivo,"----------------------------------------");
	fclose(p_arquivo);
	
    system("cls");
	}
}