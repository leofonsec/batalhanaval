#include <ctype.h> //biblioteca para inclusão do comando tolower, a fim de evitar qualquer tipo de erro na hora de recomeçar ou terminar do jogo =D
#include <locale.h> //biblioteca responsável pelo controle de acentos =D
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //biblioteca para os comandosSleep();
#include <windows.h>
#include <string.h> //biblioteca de string

void desenho(){//função de tipo void que exibe o desenho de um navio
    printf("         o     \n");
    printf("          o  _\n");
    printf("            | |\n");
    printf("       .___/   \\___________\n");
    printf("       |    O    O   O     /\n");
    printf("       |                  /\n");
    printf("  ~~~~~\\_________________/~~~~~~ \n");
}

void tutorial()//função tipo void que contém instruções de como jogar o batalha naval
{
  printf("\n\tSelecione o lugar que você quer atirar usando linhas e colunas! Acerte os três navios e ganhe o jogo!");
  printf("\nO tabuleiro consiste em '~' que representam a água. Quando um navio inimigo for derrubado, o símbolo 'o' apa-");
  printf("\nrecerá, e quando errar aparecerá o símbolo 'X'. O jogador vence ao derrubar os 3 navios.\n");
}

int main() {
  setlocale(LC_ALL, "");
  int nivel, linha, coluna, navios, acertos=0, i, j, jogadas, n, lado, limp, win, lose, t, linhaA, colunaA;
  char tabuleiro[5][5], nome[20], continuar, matriz[5][5], banana;
  navios = 3;

  printf("\n\t--Bem vindo ao Batalha Naval!--\t\n");
  printf("\nQual o seu nome?\n");
  gets(nome);//identificação do usuário

  printf("\nGostaria de ver o tutorial de como jogar?('S' ou 'N')");//escolha para ver o tutorial ou não
  scanf("%c", &banana);
  banana = tolower(banana);
  if (banana == 's'){
   tutorial();
  }

  win=0;
  lose=0;
  do {
    do {
      printf("\nOlá %s!! Escolha um nível de dificuldade:\nNível 1 (fácil)\nNível 2 (médio)\nNível 3 (difícil)\n", nome);
      printf("\nInsira o nível:");
      limp = scanf("%d", &nivel);
      fflush(stdin);
      if (limp==0)
      nivel=4;
      // seleção de dificuldade para o jogador =D
      if (nivel > 3 || nivel < 1) {
        printf("\nOps, parece que o nível selecionado não existe ;__;\n");
        printf("Aguarde 5 segundos e tente novamente com uma das três opções\n");
        Sleep(5000);
        system("cls");
        // condição para caso o jogador insira uma dificuldade que não seja
        // existente
      }
    } while (nivel > 3 || nivel < 1);

    if (nivel == 1) { //diferentes mensagens que aparecerão na seleção de níveis
                      //junto a declaração das variáveis que representam linhas, colunas e jogadas totais
      printf("\nVocê escolheu o nível Fácil... Mamão com açúcar!\n");
      i = 2;
      j = 2;
      n = 5;
    } else if (nivel == 2) {
      printf("\nVocê escolheu o nível Médio... Oloko meu!\n");
      i = 3;
      j = 3;
      n = 7;
    } else if (nivel == 3) {
      printf("\nVocê escolheu o nível Difícil... Que a força esteja com você!!!\n");
      i = 5;
      j = 5;
      n = 9;
    }

    system("cls");
    printf("\t\tVocê está no nível %d\n\n", nivel);

////////////


for(linha=0;linha<=i;linha++)//tabuleiro de informação(para realizar a comparação)
    for(coluna=0;coluna<=j;coluna++)
        matriz[linha][coluna]='~';

for(navios=0; navios<3; navios++)//definição das bombas no tabuleiro de informação
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
    if (linha>i||linha<0){//condição caso o jogador insira uma linha não existente
      printf("\nOps, parece que essa linha não existe\n");
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
    if (coluna>j||coluna<0){//condiçao caso o jogador insira uma coluna não existente
      printf("\nOps, parece que essa coluna não existe\n");
      printf("Tente novamente em 2 segundos\n");
      Sleep(2000);
    }
    }while(coluna>j||coluna<0);

    if(tabuleiro[linha][coluna]==matriz[linha][coluna]){
      tabuleiro[linha][coluna]='X';//se o usuário erra, atribui 'X' àquela casa
      }

    else if(tabuleiro[linha][coluna]!=matriz[linha][coluna] && tabuleiro[linha][coluna]!='X'){
      tabuleiro[linha][coluna]='o';
      acertos++;
      printf("\nacertos: %d\n", acertos);//se o jogador acerta, atribui 'o' àquela casa
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

    printf("\nPressione ENTER para continuar\n");//mensagem exibida no fim da rodada para ir ao próximo processo
    getchar();

    if (acertos >= 3) {
      system("cls");
      printf("\nParabéns, você derrubou todos os navios\n");//mensagem exibida quando o jogador vence
      win++;
    } else if (acertos < 3) {
      system("cls");
      printf("\nQue pena, parece que não foi dessa vez ;__;\n");//mensagem exibida quando o jogador perde
      lose++;
    }

    acertos=0;//opção para o usuário decidir se quer continuar jogando ou não
    printf("\n\t-----------------------------------\t\n");
    printf("\nDeseja jogar novamente?('S' ou 'N')");
    scanf("\n%c", &continuar);
    continuar = toupper(continuar);
    printf("\n%c", continuar);
    Sleep(3000);
    system("cls");

  } while (continuar == 'S');

  printf("%s, o resumo da sua sessão foi:\n", nome);
  printf("%d VITÓRIAS :)\n%d DERROTAS ;-;\n", win, lose);
  for(t=0;t<5;t++){
    printf(" . ");
    Sleep(1000);
  }
  system("cls");//relatório que mostra os acontecimentos da partida

  printf("\n\tMuito Obrigado por jogar o Batalha Naval em C\n");
  printf("\n");
  desenho();
  printf("\n");
  printf("-feito por:   André Ferreira Gonçalves\n              Leonardo B. A. Fonseca\n");//mensagem exibida na finalização do programa

  return 0;
}
