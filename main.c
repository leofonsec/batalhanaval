#include <ctype.h> //biblioteca para inclus�o do comando tolower, a fim de evitar qualquer tipo de erro na hora de recome�ar ou terminar do jogo =D
#include <locale.h> //biblioteca respons�vel pelo controle de acentos =D
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //biblioteca para os comandosSleep();
#include <windows.h>
#include <string.h> //biblioteca de string

typedef struct jogador{
  char nome[80];
  int jogo;
  int win;
  int lose;
}jogador;

void desenho();
void tutorial();
void aloca_jogador(jogador **j, int tam);
void pega_dados(jogador *j);
char continuar();
int pega_nivel(jogador *j);
void fim();

int main() {
  setlocale(LC_ALL, "Portuguese");
  jogador *pj = NULL;
  int nivel, linha, coluna, navios, acertos=0, i, j, jogadas, n, lado, limp, t, linhaA, colunaA;
  char tabuleiro[5][5], matriz[5][5], banana;
  navios = 3;

  aloca_jogador(&pj, 1);
  pega_dados(pj);
  printf("\nGostaria de ver o tutorial de como jogar?('S' ou 'N')");//escolha para ver o tutorial ou não
  banana = continuar();
  if (banana == 's')
  {
    tutorial();
  }
  do {
    do {
      nivel = pega_nivel(pj); // seleção de dificuldade para o jogador =D
      if (nivel > 3 || nivel < 1) 
      {
        printf("\nOps, parece que o nivel selecionado nao existe ;__;\n");
        printf("Aguarde 5 segundos e tente novamente com uma das tres opcoes\n");
        Sleep(5000);
        system("cls");
        /* condição para caso o jogador insira uma dificuldade que não seja
        existente*/
      }
    } while (nivel > 3 || nivel < 1);

    switch (nivel)
    {
      case 1:
        printf("\nVoce escolheu o nivel Facil... Mamao com acucar!\n");
        i = 2;
        j = 2;
        n = 5;
        Sleep(2000);
        break;
      case 2:
        printf("\nVoce escolheu o nivel Medio... Oloko meu!\n");
        i = 3;
        j = 3;
        n = 7;
        Sleep(2000);
        break;;
      case 3:
        printf("\nVoce escolheu o nivel Dificil... Que a forca esteja com voce!!!\n");
        i = 5;
        j = 5;
        n = 9;
        Sleep(2000);
        break;
    }
    system("cls");
    printf("\t\tVoce esta no nivel %d\n\n", nivel);

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
      printf("\nOps, parece que essa linha nao existe\n");
      printf("Tente novamente em 2 segundos\n");
      Sleep(2000);
    }
    }while(linha>i || linha<0);

  do{
    printf("Coluna:");
    limp = scanf("%d", &coluna);
    fflush(stdin);
    if (limp==0)
      nivel=4;
    if (coluna>j||coluna<0){//condiçao caso o jogador insira uma coluna não existente
      printf("\nOps, parece que essa coluna nao existe\n");
      printf("Tente novamente em 2 segundos\n");
      Sleep(2000);
    }
    }while(coluna>j||coluna<0);

    if(tabuleiro[linha][coluna]==matriz[linha][coluna])
    {
      tabuleiro[linha][coluna]='X';//se o usuário erra, atribui 'X' àquela casa
    }

    else if(tabuleiro[linha][coluna]!=matriz[linha][coluna] && tabuleiro[linha][coluna]!='X')
    {
      tabuleiro[linha][coluna]='o';
      acertos++;
      printf("\nacertos: %d\n", acertos);//se o jogador acerta, atribui 'o' àquela casa
    }

    if(acertos==3)
    {
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
      printf("\nParabens, voce derrubou todos os navios\n");//mensagem exibida quando o jogador vence
      pj->win++;
    } else if (acertos < 3) {
      system("cls");
      printf("\nQue pena, parece que nao foi dessa vez ;__;\n");//mensagem exibida quando o jogador perde
      pj->lose++;
    }

    acertos=0;//op��o para o usu�rio decidir se quer continuar jogando ou n�o
    printf("\n\t-----------------------------------\t\n");
    printf("\nDeseja jogar novamente?('S' ou 'N')");
    banana = continuar();
    system("cls");
  } while (banana == 's');

  printf("%s, o resumo da sua sessão foi:\n", pj->nome);
  printf("%d VITORIAS :)\n%d DERROTAS ;-;\n", pj->win, pj->lose);
  for(t=0;t<5;t++){
    printf(" . ");
    Sleep(1000);
  }
  system("cls");//relatório que mostra os acontecimentos da partida
  fim();

  return 0;
}

/*--------------------------FUNÇÕES-----------------------------*/

void aloca_jogador(jogador ** j, int tam)
{
  if((*j=(jogador*)realloc(*j,tam*sizeof(jogador)))==NULL)
  {
    exit(1);
  }
}

void pega_dados(jogador *j)
{
  printf("\n\t--Bem vindo ao Batalha Naval!--\t\n");
  printf("\nQual o seu nome?\n");
  gets(j->nome);//identificação do usuário
  fflush(stdin);
  j->jogo = 0;
  j->lose = 0;
  j->win = 0;
}

char continuar()
{
  char banana;
  scanf("%c", &banana);
  fflush(stdin);
  banana = tolower(banana);
  return banana;
}

int pega_nivel(jogador *j)
{
  int nivel, limp;
  printf("\nOla %s!! Escolha um nivel de dificuldade:\nNivel 1 (facil)\nNivel 2 (medio)\nNivel 3 (dificil)\n", j->nome);
  printf("\nInsira o nivel:");
  limp = scanf("%d", &nivel);
  fflush(stdin);
  if (limp==0)
  {
    nivel=4;
  }
  return nivel;
}

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
  printf("\n\tSelecione o lugar que você quer atirar usando linhas e colunas! Acerte os três navios e ganhe o jogo!");
  printf("\nO tabuleiro consiste em '~' que representam a água. Quando um navio inimigo for derrubado, o símbolo 'o' apa-");
  printf("\nrecerá, e quando errar aparecerá o símbolo 'X'. O jogador vence ao derrubar os 3 navios.\n");
}

void fim()
{
  printf("\n\tMuito Obrigado por jogar o Batalha Naval em C\n");
  printf("\n");
  desenho();
  printf("\n");
  printf("-feito por:   André Ferreira Gonçalves\n              Leonardo B. A. Fonseca\n");//mensagem exibida na finaliza��o do programa
}