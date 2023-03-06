#include <time.h>
#include <locale.h>
#include "ordenacao.c"
#include "busca.c"

int* criaVetorEmbaralhado(int n);
clock_t buscaVetor(int* v, int i, int n, int opcao);
clock_t ordenaVetor(int* v, int n, int t);
void imprimeVetor(int* v, int n);

int main(void){
  setlocale(LC_ALL, "Portuguese");

  int n1 = pow(10, 1);
  int n2 = pow(10, 2);
  int n3 = pow(10, 3);
  int n4 = pow(10, 4);
  int n5 = pow(10, 5);

  int* vetor1 = criaVetorEmbaralhado(n1);
  int* vetor2 = criaVetorEmbaralhado(n2);
  int* vetor3 = criaVetorEmbaralhado(n3);
  int* vetor4 = criaVetorEmbaralhado(n4);
  int* vetor5 = criaVetorEmbaralhado(n5);

  int opcao;
  printf("Deseja imprimir os 5 vetores embaralhados?\n1) Sim\n2) Não\nOpção: ");
  scanf("%d", &opcao);

  if (opcao == 1){
    printf("\n\t\tImpressão (vetor1 Embaralhado)");
    imprimeVetor(vetor1, n1);

    printf("\n\n\n\t\tImpressão (vetor2 Embaralhado)");
    imprimeVetor(vetor2, n2);

    printf("\n\n\n\t\tImpressão (vetor3 Embaralhado)");
    imprimeVetor(vetor3, n3);

    printf("\n\n\n\t\tImpressão (vetor4 Embaralhado)");
    imprimeVetor(vetor4, n4);

    printf("\n\n\n\t\tImpressão (vetor5 Embaralhado)");
    imprimeVetor(vetor5, n5);
  } 

  clock_t tempoOrdenaV1;
  clock_t tempoOrdenaV2;
  clock_t tempoOrdenaV3;
  clock_t tempoOrdenaV4;
  clock_t tempoOrdenaV5;

  clock_t tempoBuscaV1;
  clock_t tempoBuscaV2;
  clock_t tempoBuscaV3;
  clock_t tempoBuscaV4;
  clock_t tempoBuscaV5;

  printf("\n\n\nInforme o método de busca desejado:\n1) Busca Linear\n2) Busca Binária\nOpção: ");
  scanf("%d", &opcao);

  /*
  Condição para o último print. Caso seja 1, imprime
  apenas o tempo gasto para realizar a busca, caso
  seja 2, imprime os tempos gastos para realizar a
  ordenação e a busca, e caso contrário, não 
  imprime nada.
  */
  int condicaoPrintFinal = 0;

  switch (opcao){
    case 1:
      tempoBuscaV1 = buscaVetor(vetor1, 1, n1, 1);
      tempoBuscaV2 = buscaVetor(vetor2, 2, n2, 1);
      tempoBuscaV3 = buscaVetor(vetor3, 3, n3, 1);
      tempoBuscaV4 = buscaVetor(vetor4, 4, n4, 1);
      tempoBuscaV5 = buscaVetor(vetor5, 5, n5, 1);

      condicaoPrintFinal = 1;
      break;

    case 2:
      int tipoOrdenacao;
      printf("\nInforme o tipo de ordenação a ser utilizado na Busca Binária:\n1) BubbleSort\n2) QuickSort\n3) MergeSort\nOpção: ");
      scanf("%d", &tipoOrdenacao);

      if (tipoOrdenacao == 1 || tipoOrdenacao == 2 || tipoOrdenacao == 3){
        tempoOrdenaV1 = ordenaVetor(vetor1, n1, tipoOrdenacao);
        tempoOrdenaV2 = ordenaVetor(vetor2, n2, tipoOrdenacao);
        tempoOrdenaV3 = ordenaVetor(vetor3, n3, tipoOrdenacao);
        tempoOrdenaV4 = ordenaVetor(vetor4, n4, tipoOrdenacao);
        tempoOrdenaV5 = ordenaVetor(vetor5, n5, tipoOrdenacao);

        tempoBuscaV1 = buscaVetor(vetor1, 1, n1, 1);
        tempoBuscaV2 = buscaVetor(vetor2, 2, n2, 1);
        tempoBuscaV3 = buscaVetor(vetor3, 3, n3, 1);
        tempoBuscaV4 = buscaVetor(vetor4, 4, n4, 1);
        tempoBuscaV5 = buscaVetor(vetor5, 5, n5, 1);

        condicaoPrintFinal = 2;

      } else {
        printf("\nERRO! Opção Inexistente.\nSaindo do programa...");        
      }
      break;

    default:
        printf("\nERRO! Opção Inexistente.\nSaindo do programa...");        
  }

  if (condicaoPrintFinal == 1 || condicaoPrintFinal == 2){
    printf("\nDeseja imprimir os 5 vetores ordenados?\n1) Sim\n2) Não\nOpção: ");
    scanf("%d", &opcao);

    if (opcao == 1){
      printf("\n\t\tImpressão (vetor1 Ordenado)");
      imprimeVetor(vetor1, n1);

      printf("\n\n\n\t\tImpressão (vetor2 Ordenado)");
      imprimeVetor(vetor2, n2);

      printf("\n\n\n\t\tImpressão (vetor3 Ordenado)");
      imprimeVetor(vetor3, n3);

      printf("\n\n\n\t\tImpressão (vetor4 Ordenado)");
      imprimeVetor(vetor4, n4);

      printf("\n\n\n\t\tImpressão (vetor5 Ordenado)");
      imprimeVetor(vetor5, n5);
    } 

    printf("\n\n\t\tTempos Gastos");
    if (condicaoPrintFinal == 2){
      printf("\n\nOrdenação vetor1: %lfms", ((double)tempoOrdenaV1)/((CLOCKS_PER_SEC/1000)));
      printf("\nOrdenação vetor2: %lfms", ((double)tempoOrdenaV2)/((CLOCKS_PER_SEC/1000)));
      printf("\nOrdenação vetor3: %lfms", ((double)tempoOrdenaV3)/((CLOCKS_PER_SEC/1000)));
      printf("\nOrdenação vetor4: %lfms", ((double)tempoOrdenaV4)/((CLOCKS_PER_SEC/1000)));
      printf("\nOrdenação vetor5: %lfms", ((double)tempoOrdenaV5)/((CLOCKS_PER_SEC/1000)));
    }

    printf("\n\nBusca no vetor1: %lfms", ((double)tempoBuscaV1)/((CLOCKS_PER_SEC/1000)));
    printf("\nBusca no vetor2: %lfms", ((double)tempoBuscaV2)/((CLOCKS_PER_SEC/1000)));
    printf("\nBusca no vetor3: %lfms", ((double)tempoBuscaV3)/((CLOCKS_PER_SEC/1000)));
    printf("\nBusca no vetor4: %lfms", ((double)tempoBuscaV4)/((CLOCKS_PER_SEC/1000)));
    printf("\nBusca no vetor5: %lfms\n", ((double)tempoBuscaV5)/((CLOCKS_PER_SEC/1000)));
  }

  free(vetor1);
  free(vetor2);
  free(vetor3);
  free(vetor4);
  free(vetor5);
}

/**
 * @brief Cria dinamicamente um vetor com N elementos e 
 * o retorna com seus valores embaralhados.
 * @param n número de elementos que terão no vetor.
 * @return int* 
 */
int* criaVetorEmbaralhado(int n){
  int* v =  (int*) malloc(n*sizeof(int));

  for (int i = 0; i < n; i++){
    v[i] = i + 1;
  }

  srand(time(NULL));

  for (int j = 0; j < n; j++){
    int r = rand() % n;
    int tmp = v[j];
    v[j] = v[r];
    v[r] = tmp;
  }
  return v;
}

/**
 * @brief Função que recebe um valor a ser buscado no vetor, fornecido
 * via parâmetro, e chama as funções de busca, sendo busca linear caso
 * a opção fornecida pelo usuário seja 1 e busca binária caso seja 2.
 * Além disso, a posição onde o valor se encontra será impressa e o 
 * tempo gasto para realizar a busca será retornado.
 * @param v Vetor.
 * @param i O número do vetor em questão. Será utilizado apenas para 
 * um print personalizado.
 * @param n Número de elementos do vetor.
 * @param opcao Opção escolhida pelo usuário. 1 para busca linear
 * e 2 para busca binária.
 * @return clock_t 
 */
clock_t buscaVetor(int* v, int i, int n, int opcao){
  int p;
  printf("\n\nInforme o número a ser buscado no vetor%d: ", i);
  scanf("%d", &p);

  clock_t t;
  int resultado;

  if (opcao == 1){
    t = clock();
    resultado = buscaLinear(n, v, p);
    t = clock() - t;
  } else {
    t = clock();
    resultado = buscaBinaria(n, v, p);
    t = clock() - t;
  }  

  printf("\nPosição de %d no vetor%d: %d", p, i, resultado);
  return t;
}

/**
 * @brief Função que ordena o vetor em questão e retorna o tempo
 * gasto para fazer o mesmo. Só será chamada caso a busca 
 * binária tenha sido escolhida pelo usuário no main().
 * @param v Vetor.
 * @param n Número de elementos do vetor.
 * @param opcao Opção escolhida pelo usuário. 1 para Bubble
 * Sort, 2 para Quick Sort e 3 para Merge Sort.
 * @return clock_t 
 */
clock_t ordenaVetor(int* v, int n, int opcao){
  clock_t t;

  if (opcao == 1){
    t = clock();
    bubbleSort(n, v);
    t = clock() - t;

  } else if (opcao == 2){
    t = clock();
    quickSort(0, n - 1, v);
    t = clock() - t;

  } else {
    t = clock();
    mergeSort(0, n - 1, v);
    t = clock() - t;
  }

  return t;
}

/**
 * @brief Imprime o vetor.
 * @param v Vetor.
 * @param n Número de elementos do vetor.
 */
void imprimeVetor(int* v, int n){
  printf("\n[   ");
  for (int i = 0; i < n; i++){
    printf("%d   ", v[i]);
  }
  printf("]");
}