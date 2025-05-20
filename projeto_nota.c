#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 100

typedef struct
{ // Struct para armazenar cada aluno com suas respectivas notas
  char nome[TAMANHO];
  int n1, n2, n3;
  char rgm[10];
  int situacao;
  int ativo;
} Aluno;

void exportarCSV(Aluno alunos[], int totalAlunos, const char *rgm)
{

  exibirAlunos(alunos, totalAlunos);
}

int validadorRGM(Aluno alunos[], int totalAlunos, char *rgm)
{
  int comprimento = strlen(rgm);

  if (comprimento != 8)
  {
    return 0;
  }

  for (int i = 0; i < comprimento; i++)
  {
    if (!isdigit(rgm[i]))
    {
      return 0;
    }
  }
  for (int i = 0; i < totalAlunos; i++)
  {
    if (strcmp(alunos[i].rgm, rgm) == 0)
    {
      return 0;
    }
  }

  return 1;
}

Aluno *verificarRGM(Aluno alunos[], int totalAlunos, const char *rgm)
{
  for (int i = 0; i < totalAlunos; i++)
  {
    if (alunos->ativo == 1 && strcmp(alunos[i].rgm, rgm) == 0)
    {
      return &alunos[i];
    }
  }
  return NULL;
}

void exibirAlunos(Aluno alunos[], int totalAlunos)
{
  int alunosTotais = totalAlunos;

  if (alunosTotais == 0)
  {
    printf("Nenhum aluno cadastrado.\n");
  }

  for (int i = 0; i < alunosTotais; i++)
  {
    if (alunos[i].ativo == 0)
    {
      printf("RGM: %s | Aluno: %s\n", alunos[i].rgm, alunos[i].nome);
      if (alunos[i].n1 == -1)
      {
        printf("A1: Nota nao informada.\n");
      }
      else
      {
        printf("A1: %d\n", alunos[i].n1);
      }
      if (alunos[i].n2 == -1) // Nota da A2
      {
        printf("A2: Nota nao informada.\n");
      }
      else
      {
        printf("A2: %d\n", alunos[i].n2);
      }
      if (alunos[i].n3 == -1) // Nota da AF
      {
        printf("AF: Nota nao informada.\n");
      }
      else
      {
        printf("AF: %d\n", alunos[i].n3);
      }
      if (alunos[i].situacao == -1) // Logica para mostrar a situacao do aluno.
      {
        if (alunos[i].n1 == -1 || alunos[i].n2 == -1)
        {
          printf("Situacao: Notas insuficientes para calculo.\n");
        }
        else
        {
          if (alunos[i].n1 + alunos[i].n2 >= 6)
          {
            printf("Situacao: Aprovado.\n");
          }
          else if (alunos[i].n1 + alunos[i].n2 < 6)
          {
            printf("Situacao: Reprovado.\n");
          }
        }
      }
      else if (alunos[i].situacao == 0)
      {
        printf("Situacao: Reprovado.\n");
      }
      else if (alunos[i].situacao == 1)
      {
        printf("Situacao: Aprovado.\n");
      }

      printf("-------------------------------------------------------------\n");
    }
    else
    {
      printf("  ");
    }
  }
}

int main()
{

  Aluno alunos[TAMANHO];                             // Var do tipo aluno. Armazena cada aluno diferente
  int totalAlunos = 0;                               // Contabiliza os alunos
  int sair = 0;                                      // Condicao do laco de repticao do menu
  int escolha_MENU, escolha_ADnota, escolha_EX_nota; // Escolhas usadas no switch

  while (sair == 0)
  {
    printf("\n ----- Bem vindo ao sistema de gerenciamento de notas!-----");
    printf("\n|                   O que deseja fazer?                    |");
    printf("\n|    1 - Cadastrar aluno         6 - Calcular situacao     |");
    printf("\n|    2 - Exibir alunos           7 - Excluir notas         |");
    printf("\n|    3 - Adicionar notas         8 - Excluir aluno         |");
    printf("\n|    4 - Atualizar notas         9 - Exportar para .CSV    |");
    printf("\n|    5 - Consultar aluno        10 - Limpar terminal       |");
    printf("\n|                      11 - Sair                           |");
    printf("\n ----------------------------------------------------------");
    printf("\n                   Escolha uma opcao: ");

    if (scanf("%d", &escolha_MENU) == 0)
    {                            // Aqui, verifica se o input do usuario e int ou nao , e logo apos limpa o buffer para nao ocasionar repeticao
      printf("Valor invalido."); //(A verificacao e feita comparando se escolha e int por meio do "%d", comparando a um intean falso)
      while (getchar() != '\n')
        ; // Limpeza de buffer para nao causar loops infinitos
    }
    else
    {
      switch (escolha_MENU)
      {

        //-------------------------- CADASTRAR ALUNOS ----------------------------

      case 1:
      {

        char cadNome[TAMANHO];
        char cadRGM[10];
        int sairmenuCAD = 0;

        if (totalAlunos >= TAMANHO)
        {
          printf("Limite de alunos atingido!"); // Caso o usuario cadastre mais de 100 alunos, essa mensagem aparece
          break;
        }
        while (getchar() != '\n')
          ;
        printf("Digite o nome do aluno: ");
        fgets(cadNome, sizeof(cadNome), stdin); // O valor colocado aqui preenche a var cadNome q serve pra guardar o nome do aluno, q so sera preenchido pos validacoes
        cadNome[strcspn(cadNome, "\n")] = '\0'; // Substitui o \n presente na string por \0 para nao ocasionar erros

        while (sairmenuCAD == 0)
        {
          printf("Digite o RGM do aluno: ");
          fgets(cadRGM, sizeof(cadRGM), stdin);
          cadRGM[strcspn(cadRGM, "\n")] = '\0';

          if (validadorRGM(alunos, totalAlunos, cadRGM)) // Chama a funcao que valida o rgm
          {
            strcpy(alunos[totalAlunos].nome, cadNome); // Copia o conteudo de cadNome e joga pro registro do aluno cadastrado
            strcpy(alunos[totalAlunos].rgm, cadRGM);   // Copia o conteudo de cadRGM e joga pro registro do aluno cadastrado
            alunos[totalAlunos].n1 = -1;               // Aqui, define-se as notas em -1
            alunos[totalAlunos].n2 = -1;
            alunos[totalAlunos].n3 = -1;
            alunos[totalAlunos].situacao = -1; // Aqui defini-se a situacao como -1
            alunos[totalAlunos].ativo = 1;
            printf("Aluno %s cadastrado!\n", alunos[totalAlunos].nome); // O programa acessa a struct Aluno e pega o nome para exibir
            totalAlunos++;
            sairmenuCAD = 1;
          }
          else
          {
            printf("Valor invalido e/ou ja cadastrado.\n");
          }
        }
        break;
      }
        //-------------------------- CONSULTAR ALUNOS ----------------------------

      case 2:
        exibirAlunos(alunos, totalAlunos);
        break;
        // PINDAMONHANGABA
        //------------------------- ADICIONAR NOTAS ------------------------------

      case 3:
      {
        char validarRGM[8];
        int validadorn1, validadorn2; // Validam as notas inseridas
        int laco1 = 0;
        int laco2 = 0;

        printf("Digite o RGM do aluno: "); // Verificacao feita nos cases 3, 4, 5, 6 e 7 caso o usuario acesse elas antes de cadastrar algum aluno.
        scanf("%s", validarRGM);

        Aluno *alunoEncontrado = verificarRGM(alunos, totalAlunos, validarRGM);
        if (alunoEncontrado != NULL)
        {
          while (laco1 == 0)
          {
            printf("Adicionando notas de: %s\n", alunoEncontrado->nome);
            printf("Digite a primeira nota: "); // Aqui, em uma condicao, verifica se o valor informado e int ou nao
            if (scanf("%d", &validadorn1) == 0)
            {
              printf("Valor invalido.\n");
              while (getchar() != '\n')
                ;
            }
            else
            {
              if (validadorn1 > 5 || validadorn1 < 0)
              { // Aqui, o validador confere se a nota esta nos parametros(0 < n < 5)
                printf("Valor invalido.\n");
                continue;
              }
              else
              {
                alunoEncontrado->n1 = validadorn1; // E finalmente, armazena a nota
                laco1 = 1;
              }
            }
          }
          while (laco2 == 0)
          {
            printf("Digite a segunda nota: ");
            if (scanf("%d", &validadorn2) == 0)
            {
              printf("Valor invalido.\n");
              while (getchar() != '\n')
                ;
            }
            else
            {
              if (validadorn2 > 5 || validadorn2 < 0)
              {
                printf("Valor invalido.\n");
                continue;
              }
              else
              {
                alunoEncontrado->n2 = validadorn2;

                if (validadorn1 + validadorn2 >= 6)
                {
                  printf("Notas adicionadas!\n");
                  printf("O aluno esta aprovado!\n");
                }
                else
                {
                  printf("O aluno esta reprovado! Portanto, e necessario realizar a AF.\n");
                }
                laco2 = 1;
              }
            }
          }
        }
        else
        {
          printf("Aluno nao cadastrado e/ou valor invalido.\n");
          break;
        }
        break;
      }
        //---------------------- ATUALIZAR NOTAS ---------------------------------
      case 4:
      {
        int novan1, novan2; // Variaveis exclusivas daqui que recebem o valor inserido e, se forem ints, substituem o valor de alunos[index].n
        int laco1 = 0;
        int laco2 = 0;
        char validarRGM[8];

        printf("Digite o RGM do aluno: "); // Verificacao feita nos cases 3, 4, 5 e 6 caso o usuario acesse elas antes de cadastrar algum aluno.
        scanf("%s", validarRGM);

        Aluno *alunoEncontrado = verificarRGM(alunos, totalAlunos, validarRGM);
        if (alunoEncontrado != NULL)
        {
          if (alunoEncontrado->n1 == -1 || alunoEncontrado->n2 == -1)
          { // Caso as notas sejam -1 (definidas como padroes), as notas nao sao informadas
            printf("Notas nao informadas\n");
            break;
          }
          printf("\n ---------- Atualizar notas ------------");
          printf("\n|Atualizando notas de: %s|", alunoEncontrado->nome);
          printf("\n|               1 - A1                  |");
          printf("\n|               2 - A2                  |");
          printf("\n ---------------------------------------");
          printf("\n          Escolha uma opcao: ");

          if (scanf("%d", &escolha_ADnota) == 0)
          {
            printf("Valor invalido.\n");
            while (getchar() != '\n')
              ;
          }
          switch (escolha_ADnota)
          {
          case 1:
            while (laco1 == 0)
            {
              printf("\nDigite a nova nota: ");
              if (scanf("%d", &novan1) == 0)
              {
                printf("Valor invalido.\n");
                while (getchar() != '\n')
                  ;
              }
              else
              {
                if (novan1 > 5 || novan1 < 0)
                {
                  printf("Valor invalido.\n");
                }

                else
                {
                  alunoEncontrado->n1 = novan1;
                  printf("Nota atualizada!\n");
                  laco1 = 1;
                }
              }
            }
            break;
          case 2:
            while (laco2 == 0)
            {
              printf("Digite a nova nota: ");
              if (scanf("%d", &novan2) == 0)
              {
                printf("Valor invalido.\n");
                while (getchar() != '\n')
                  ;
              }
              else
              {
                if (novan2 > 5 || novan2 < 0)
                {
                  printf("Valor invalido.\n");
                }
                else
                {
                  alunoEncontrado->n2 = novan2;
                  printf("Nota atualizada!\n");
                  laco2 = 1;
                }
              }
            }
            break;
          default:
            printf("Valor invalido.\n");
            break;
          }
        }
        break;
      }
        //----------------------- CONSULTAR NOTAS ------------------------------

      case 5:
      {
        char validarRGM[8];

        printf("Digite o RGM do aluno: "); // Aqui sao informadas todas as notas, negando aquelas que nao foram informadas/excluidas
        scanf("%s", validarRGM);

        Aluno *alunoEncontrado = verificarRGM(alunos, totalAlunos, validarRGM);
        if (alunoEncontrado != NULL)
        {
          printf("RGM:%s | Aluno: %s\n", alunoEncontrado->rgm, alunoEncontrado->nome); // Loop limitado ao total de alunos, mostrando todos eles de acordo com o ID
          if (alunoEncontrado->n1 == -1)                                               // Nota da A1
          {
            printf("A1: Nota nao informada.\n");
          }
          else
          {
            printf("A1: %d\n", alunoEncontrado->n1);
          }
          if (alunoEncontrado->n2 == -1) // Nota da A2
          {
            printf("A2: Nota nao informada.\n");
          }
          else
          {
            printf("A2: %d\n", alunoEncontrado->n2);
          }
          if (alunoEncontrado->n3 == -1) // Nota da AF
          {
            printf("AF: Nota nao informada.\n");
          }
          else
          {
            printf("AF: %d\n", alunoEncontrado->n3);
          }
          if (alunoEncontrado->situacao == -1)
          {
            if (alunoEncontrado->n1 == -1 || alunoEncontrado->n2 == -1)
            {
              printf("Situacao: Notas insuficientes para calculo.\n");
            }
            else
            {
              if (alunoEncontrado->n1 + alunoEncontrado->n2 >= 6)
              {
                printf("Situacao: Aprovado.\n");
              }
              else if (alunoEncontrado->n1 + alunoEncontrado->n2 < 6)
              {
                printf("Situacao: Reprovado.\n");
              }
            }
          }
          else if (alunoEncontrado->situacao == 0)
          {
            printf("Situacao: Reprovado.\n");
          }
          else if (alunoEncontrado->situacao == 1)
          {
            printf("Situacao: Aprovado.\n");
          }

          printf("-----------------------------------------------------------------------------\n");
        }
        else
        {
          printf("Aluno nao cadastrado e/ou valor invalido.\n");
          break;
        }
        break;
      }

        //---------------------- CALCULAR NF -----------------------------------

      case 6:
      {
        char validarRGM[8];
        int notaMaior, notaMenor, notaFinal; // Calculos de NF
        int case6 = 0;

        printf("Digite o RGM do aluno: ");
        scanf("%s", validarRGM);

        Aluno *alunoEncontrado = verificarRGM(alunos, totalAlunos, validarRGM);
        if (alunoEncontrado != NULL)
        {

          int n1 = alunoEncontrado->n1; // Para simplificar, determino que n1 e n2 assumirao os valores das notas do aluno do indice informado
          int n2 = alunoEncontrado->n2;

          if (n1 == -1 || n2 == -1)
          { // Caso seja menor que 0 e Maior que 5
            printf("Notas nao informadas.\n");
            break;
          }
          else
          { // Se nao:
            notaFinal = (n1 + n2);

            // Para calcular menor valor de notas
            if (n1 < n2)
            {
              notaMenor = n1;
              notaMaior = n2;
            }
            else
            {
              notaMenor = n2;
              notaMaior = n1;
            }

            if (notaFinal > 6)
            { // Se a soma de n1+n2 for Maior que 6, o aluno esta aprovado
              printf("O aluno %s ja esta aprovado!\n", alunoEncontrado->nome);
            }
            else if (notaFinal < 6)
            { // Caso nao seja, o programa instrui a realizar a AF e retornar quando tiver feito
              do
              {
                while (case6 == 0)
                {
                  printf("Calculando nota final de: %s", alunoEncontrado->nome);
                  printf("Digite o valor da nota obtida na AF: ");
                  if (scanf("%d", &alunoEncontrado->n3) == 0)
                  { // O valor informado e colocado na "n3" do aluno com o indice informado.
                    printf("Valor invalido.\n");
                    while (getchar() != '\n')
                      ;
                  }
                  else
                  {
                    if (alunoEncontrado->n3 < 0 || alunoEncontrado->n3 > 5)
                    { // Se a nota obtida na AF for menor que 0 e Maior que 5
                      printf("Digite um valor de 0 a 5.");
                    }
                    else
                    {
                      notaMenor = alunoEncontrado->n3;
                      notaFinal = notaMaior + notaMenor;
                      if (notaFinal >= 6)
                      { // Caso a soma das notas seja superior ou igual a 6, o aluno esta aprovado.
                        printf("\nO valor da nota final de %s e %d, portanto, APROVADO!", alunoEncontrado->nome, notaFinal);
                        alunoEncontrado->situacao = 1;
                        case6 = 1;
                      }
                      else
                      { // Caso a soma das notas seja inferior a 6, o aluno esta reprovado.
                        printf("\nO valor da nota final de %s e %d, portanto, REPROVADO!", alunoEncontrado->nome, notaFinal);
                        alunoEncontrado->situacao = 0;
                        case6 = 1;
                      }
                    }
                  }
                }
              } while (alunoEncontrado->n3 < 0 || alunoEncontrado->n3 > 5); // Esse processo repete ate que a nota esteja nos parametros corretos (0 > n > 5)
            }
          }
        }
        else
        {
          printf("RGM nao cadastrado e/ou invalido.\n");
        }
        break;
      }
        //--------------------------- EXCLUIR NOTAS ----------------------------

      case 7:
      {
        char validarRGM[8];

        printf("Digite o RGM do aluno: ");
        scanf("%s", validarRGM);

        Aluno *alunoEncontrado = verificarRGM(alunos, totalAlunos, validarRGM);
        if (alunoEncontrado != NULL)
        { // Caso o aluno nao esteja cadastrado, o programa nao avanca, prevenindo erros
          printf("\n --------- Excluir notas ---------");
          printf("\n|      Excluindo notas de: %s     |", alunoEncontrado->nome);
          printf("\n|            1 - A1               |");
          printf("\n|            2 - A2               |");
          printf("\n|            3 - AF               |");
          printf("\n ---------------------------------");
          printf("\n Escolha uma nota para excluir: ");
          if (scanf("%d", &escolha_EX_nota) == 0)
          {
            printf("Valor invalido.\n");
            while (getchar() != '\n')
              ;
          }
          switch (escolha_EX_nota)
          {
          case 1:
            alunoEncontrado->n1 = -1; // Nos tres casos, o programa acessa o valor n1, n2 e n3 e volta para os valores padroes
            printf("Nota excluida.\n");
            break;
          case 2:
            alunoEncontrado->n2 = -1;
            printf("Nota excluida.\n");
            break;
          case 3:
            alunoEncontrado->n3 = -1;
            alunoEncontrado->situacao = -1;
            printf("Nota excluida.\n");
            break;
          default:
            printf("Valor invalido.\n");
            break;
          }
        }
        else
        {
          printf("RGM invalido e/ou inexistente.\n");
        }
        break;
      }

        //---------------------- EXCLUIR ALUNO -----------------------------

      case 8:
      {
        char validarRGM1[8];
        char validarRGM2[8];
        int escolha;

        printf("Digite o RGM do aluno: ");
        scanf("%s", validarRGM1);

        Aluno *alunoEncontrado = verificarRGM(alunos, totalAlunos, validarRGM1);

        if (alunoEncontrado != NULL)
        {
          printf("\n Tem certeza de que deseja excluir o aluno %s?", alunoEncontrado->nome);
          printf("\n|                                                    |");
          printf("\n|                  1 - Sim                           |");
          printf("\n|                  2 - Nao                           |");
          printf("\n ----------------------------------------------------");
          printf("\n               Escolha uma opcao: ");

          if (scanf("%d", &escolha) == 0)
          {
            printf("Valor invalido.\n");
            while (getchar() != '\n')
              ;
          }
          switch (escolha)
          {
          case 1:
            printf("Digite novamente o RGM do aluno: ");
            scanf("%s", validarRGM2);

            if (strcmp(validarRGM2, alunoEncontrado->rgm) == 0)
            {
              printf("O aluno %s foi excluido.\n", alunoEncontrado->nome);
              alunoEncontrado->ativo = 0;
            }
            else
            {
              printf("RGM invalido.\n");
            }
            break;

          case 2:
            break;

          default:
            break;
          }
        }
        else
        {
          printf("Aluno nao encontrado e/ou inexistente.\n");
        }

        break;
      }

      //---------------------- EXPORTAR PARA CSV -----------------------------
      case 9:

        break;
      //----------------------- LIMPAR TERMINAL -----------------------------
      case 10:
        system("cls");
        break;
      //--------------------------- SAIR -----------------------------------
      case 11: // Sair
        printf("Saindo...\n");
        sair = 1;
        break;

      //----------------------- OPCAO INVALIDA -----------------------------
      default: // Opcao invalida
        printf("Opcao invalida.\n");
        break;
      }
    }
  }
  return 0;
}
