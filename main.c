#include <ctype.h> //biblioteca para inclus�o do comando tolower, a fim de evitar qualquer tipo de erro na hora de recome�ar ou terminar do jogo =D
#include <locale.h> //biblioteca respons�vel pelo controle de acentos =D
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //biblioteca para os comandosSleep();
#include <windows.h>
#include <string.h> //biblioteca de string

void desenho(){//fun��o de tipo void que exibe o desenho de um navio
    printf("         o     \n");
    printf("          o  _\n");
    printf("            | |\n");
    printf("       .___/   \\___________\n");
    printf("       |    O    O   O     /\n");
    printf("       |                  /\n");
    printf("  ~~~~~\\_________________/~~~~~~ \n");
}

void tutorial()//fun��o tipo void que cont�m instru��es de como jogar o batalha naval
{
  printf("\n\tSelecione o lugar que voc� quer atirar usando linhas e colunas! Acerte os tr�s navios e ganhe o jogo!");
  printf("\nO tabuleiro consiste em '~' que representam a �gua. Quando um navio inimigo for derrubado, o s�mbolo 'o' apa-");
  printf("\nrecer�, e quando errar aparecer� o s�mbolo 'X'. O jogador vence ao derrubar os 3 navios.\n");
}

int main() {
  setlocale(LC_ALL, "");
  int nivel, linha, coluna, navios, acertos=0, i, j, jogadas, n, lado, limp, win, lose, t, linhaA, colunaA;
  char tabuleiro[5][5], nome[20], continuar, matriz[5][5], banana;
  navios = 3;

  printf("\n\t--Bem vindo ao Batalha Naval!--\t\n");
  printf("\nQual o seu nome?\n");
  gets(nome);//identifica��o do usu�rio

  printf("\nGostaria de ver o tutorial de como jogar?('S' ou 'N')");//escolha para ver o tutorial ou n�o
  scanf("%c", &banana);
  banana = tolower(banana);
  if (banana == 's'){
   tutorial();
  }

  win=0;
  lose=0;
  do {
    do {
      printf("\nOl� %s!! Escolha um n�vel de dificuldade:\nN�vel 1 (f�cil)\nN�vel 2 (m�dio)\nN�vel 3 (dif�cil)\n", nome);
      printf("\nInsira o n�vel:");
      limp = scanf("%d", &nivel);
      fflush(stdin);
      if (limp==0)
      nivel=4;
      // sele��o de dificuldade para o jogador =D
      if (nivel > 3 || nivel < 1) {
        printf("\nOps, parece que o n�vel selecionado n�o existe ;__;\n");
        printf("Aguarde 5 segundos e tente novamente com uma das tr�s op��es\n");
        Sleep(5000);
        system("cls");
        // condi��o para caso o jogador insira uma dificuldade que n�o seja
        // existente
      }
    } while (nivel > 3 || nivel < 1);

    if (nivel == 1) { //diferentes mensagens que aparecer�o na sele��o de n�veis
                      //junto a declara��o das vari�veis que representam linhas, colunas e jogadas totais
      printf("\nVoc� escolheu o n�vel F�cil... Mam�o com a��car!\n");
      i = 2;
      j = 2;
      n = 5;
    } else if (nivel == 2) {
      printf("\nVoc� escolheu o n�vel M�dio... Oloko meu!\n");
      i = 3;
      j = 3;
      n = 7;
    } else if (nivel == 3) {
      printf("\nVoc� escolheu o n�vel Dif�cil... Que a for�a esteja com voc�!!!\n");
      i = 5;
      j = 5;
      n = 9;
    }

    system("cls");
    printf("\t\tVoc� est� no n�vel %d\n\n", nivel);

////////////


for(linha=0;linha<=i;linha++)//tabuleiro de informa��o(para realizar a compara��o)
    for(coluna=0;coluna<=j;coluna++)
        matriz[linha][coluna]='~';

for(navios=0; navios<3; navios++)//defini��o das bombas no tabuleiro de informa��o
    matriz[rand()%i][rand()%j]='*';

for(linha=0;linha<=i;linha++)//tabuleiro que aparece pro jogador
    for(coluna=0;coluna<=j;coluna++)
        tabuleiro[linha][coluna]='~';

for(jogadas=0;jogadas<n;jogadas++){

  printf(" \n\t 0 ");                           //Comandos para imprimir o tabuleiro --
  for (lado = 1; lado <= j; lado++) {
    printf(" %d ", lado);
    }
  printf("\n");
  for (linha = 0; linha <= i; linha++) {
    printf("%d\t", linha);
    for (coluna = 0; coluna <= j; coluna++) {
      printf(" %c ", tabuleiro[linha][coluna]);
      }
    printf("\n");
    }                                           // --

  do{
    printf("Linha:");
    limp = scanf("%d", &linha);
    fflush(stdin);
    if (limp==0)
      nivel=4;
    if (linha>i||linha<0){//condi��o caso o jogador insira uma linha n�o existente
      printf("\nOps, parece que essa linha n�o existe\n");
      printf("Tente novamente em 2 segundos\n");
      Sleep(2000);
    }
    }while(linha>i||linha<0);

  do{
    printf("Coluna:");
    limp = scanf("%d", &coluna);
    fflush(stdin);
    if (limp==0)
      nivel=4;
    if (coluna>j||coluna<0){//condi�ao caso o jogador insira uma coluna n�o existente
      printf("\nOps, parece que essa coluna n�o existe\n");
      printf("Tente novamente em 2 segundos\n");
      Sleep(2000);
    }
    }while(coluna>j||coluna<0);

    if(tabuleiro[linha][coluna]==matriz[linha][coluna]){
      tabuleiro[linha][coluna]='X';//se o usu�rio erra, atribui 'X' �quela casa
      }

    else if(tabuleiro[linha][coluna]!=matriz[linha][coluna] && tabuleiro[linha][coluna]!='X'){
      tabuleiro[linha][coluna]='o';
      acertos++;
      printf("\nacertos: %d\n", acertos);//se o jogador acerta, atribui 'o' �quela casa
      }

  if(acertos==3){
    jogadas=n-1;
    }

}
////////////

printf(" \n\t 0 ");
  for (lado = 1; lado <= j; lado++) {
    printf(" %d ", lado);
    }
  printf("\n");
  for (linha = 0; linha <= i; linha++) {
    printf("%d\t", linha);
    for (coluna = 0; coluna <= j; coluna++) {
      printf(" %c ", tabuleiro[linha][coluna]);
      }
    printf("\n");
    }

    printf("\nPressione ENTER para continuar\n");//mensagem exibida no fim da rodada para ir ao pr�ximo processo
    getchar();

    if (acertos >= 3) {
      system("cls");
      printf("\nParab�ns, voc� derrubou todos os navios\n");//mensagem exibida quando o jogador vence
      win++;
    } else if (acertos < 3) {
      system("cls");
      printf("\nQue pena, parece que n�o foi dessa vez ;__;\n");//mensagem exibida quando o jogador perde
      lose++;
    }

    acertos=0;//op��o para o usu�rio decidir se quer continuar jogando ou n�o
    printf("\n\t-----------------------------------\t\n");
    printf("\nDeseja jogar novamente?('S' ou 'N')");
    scanf("\n%c", &continuar);
    continuar = toupper(continuar);
    printf("\n%c", continuar);
    Sleep(3000);
    system("cls");

  } while (continuar == 'S');

  printf("%s, o resumo da sua sess�o foi:\n", nome);
  printf("%d VIT�RIAS :)\n%d DERROTAS ;-;\n", win, lose);
  for(t=0;t<5;t++){
    printf(" . ");
    Sleep(1000);
  }
  system("cls");//relat�rio que mostra os acontecimentos da partida

  printf("\n\tMuito Obrigado por jogar o Batalha Naval em C\n");
  printf("\n");
  desenho();
  printf("\n");
  printf("-feito por:   Andr� Ferreira Gon�alves\n              Leonardo B. A. Fonseca\n");//mensagem exibida na finaliza��o do programa

  return 0;
}
