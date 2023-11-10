% Tópico 3: Ordenação Eficiente -- Parte 1: Merge Sort e Quick Sort
% Prof. Dr. Juliano Henrique Foleis

Estude com atenção os vídeos e as leituras sugeridas abaixo. Os exercícios servem para ajudar na fixação do conteúdo e foram escolhidos para complementar o material básico apresentado nos vídeos e nas leituras. Quando o exercício pede que crie ou modifique algum algoritmo, sugiro que implemente-o em linguagem C para ver funcionando na prática. 
<!-- O único exercício que é necessário entregar está descrito na Seção "Atividade Para Entregar". -->

# Vídeos

[Merge Sort (Ordenação Por Intercalação) - Parte 1: Intercalação](https://youtu.be/7yx9JjidGaM)

[Merge Sort (Ordenação Por Intercalação) - Parte 2: Merge Sort](https://youtu.be/SV2qHvJQbiQ)

[Merge Sort (Ordenação Por Intercalação) - Exemplo](https://youtu.be/Dvq-kJYiKRs)

[Quick Sort (Ordenação Por Particionamento) - Parte 1: Particionamento](https://youtu.be/BCAySWc2sNQ)

[Quick Sort (Ordenação Por Particionamento) - Parte 2: Quick Sort](https://youtu.be/u2xXX-SNGyY)

# Leitura Sugerida


PEREIRA, Silvio Lago. Estruturas de Dados em C - Uma Abordagem Didática. [Minha Biblioteca].
Capítulo 8 (Ordenação e Busca), Seção 8.2.4 [(Link)](https://integrada.minhabiblioteca.com.br/#/books/9788536517254/pageid/89)

FEOFILOFF, Paulo. Projeto de Algoritmos em C. Mergesort: Ordenação por Intercalação [(Link)](https://www.ime.usp.br/~pf/algoritmos/aulas/mrgsrt.html) -- (Pode pular a seção "Intercalação de vetores ordenados".)

FEOFILOFF, Paulo. Projeto de Algoritmos em C. Quicksort [(Link)](https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html)

SZWARCFITER, Jayme Luiz e MARKENZON, Lilian. Estruturas de Dados e Seus Algoritmos. [Minha Biblioteca].
Capítulo 7 (Algoritmos de Ordenação), Seções 7.4 e 7.5  - [(Link)](https://integrada.minhabiblioteca.com.br/#/books/978-85-216-2995-5/epubcfi/6/34%5B%3Bvnd.vst.idref%3Dchapter07%5D!/4/58/4%400:100) -- (Não precisa se preocupar com as subseções de análise. Vamos estudar esse assunto em outro momento.)

<!--

VETORAZZO, Adriana Souza; SARAIVA, Maurício Oliveira; BARRETO, Jeanine Santos; JUNIOR, Ram. Estrutura de dados. [Minha Biblioteca]. Páginas ? ( ??? ) [(Link)](https://integrada.minhabiblioteca.com.br/#/books/9788595023932/pageid/28) -->

# Exercícios

## Exercícios dos materiais de leitura sugerida

Exercícios 1.1, 2.1, 2.2, 2.3, 2.6, 2.7, 3.1, 3.3, 3.4, 4.2, 5.2 da página do Prof. Feofiloff (Quicksort) [(Link)](https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html)

Exercícios 7.5 e 7.11 do livro de Szwarcfiter e Markenzon [(Link)](https://integrada.minhabiblioteca.com.br/#/books/978-85-216-2995-5/epubcfi/6/34[;vnd.vst.idref=chapter07]!/4/282/66@0:88.9)


## Exercícios Complementares

<!-- inversões 

* mergesort: 
    * quando tem apenas 2 elementos ordenar simplesmente usando uma comparação e troca se necessário
    * pré-alocar os vetores E e D e usar os mesmos em todas as intercalações
    * copiar os elementos pra E e D usando memcpy ao invés de uma cópia por elemento
    * implementar a ordenação de um arquivo (trabalho?)
    * usar merge pra ordenar um arquivo que constituído por vários subvetores ordenados em sequencia (atividade da semana)
    * implementar mergesort iterativamente, usando uma pilha (empilhar os e, d)

* quicksort:
    * mediana de três
    * quicksort só até vetor de tamanho M, parar. rodar o insertionsort no vetor todo pra terminar a ordenação.
    * o mesmo que o anterior, exceto que o insertionsort é executado pra cada subvetor

-->

### Merge Sort

**1)** O número de inversões de um vetor $v[0 \dots n-1]$ é o número de pares ordenados $(i,j)$ tais que  $0 \leq i < j < n$  e  $v[i] > v[j]$. Modifique o algoritmo Merge Sort (e Merge) para calcular o número de inversões em $v$.

**2)** O algoritmo Merge estudado é eficiente no sentido que faz a intercalação de dois vetores em tempo linear. Entretanto, o custo dele para intercalar dois vetores unitários é maior que simplesmente trocar os elementos caso não estejam em ordem. Modifique o algoritmo de Merge Sort (do vídeo) para que intercale dois vetores unitários usando uma troca simples caso necessário. Compare o tempo para ordenar 100000 elementos aleatórios usando o algoritmo original (do vídeo) e o algoritmo modificado.

**3)** Modifique o algoritmo Merge apresentado no vídeo para que a cópia dos subvetores de V para os vetores E e D seja feita usando [*memcpy*](http://www.cplusplus.com/reference/cstring/memcpy/). Compare o tempo para ordenar 100000 elementos aleatórios usando o algoritmo original e o algoritmo modificado.

**4)** Modifique o algoritmo Merge Sort e Merge de forma que os vetores E e D sejam pré-alocados no início da execução e seja reusado em todas as chamadas a Merge. Compare o tempo para ordenar 100000 elementos aleatórios usando o algoritmo original e o algoritmo modificado.  **DICA:** Você pode criar uma função *mergesort(int \*v, int n)* que funciona como um *wrapper* para a implementação de MergeSort (apresentada no vídeo). A idéia é que *mergesort* invoque MergeSort (ou seja um *wrapper*). Tanto a alocação, quando a liberação da memória pode ser feita nessa função. Os endereços dos vetores E e D pré-alocados devem ser passados como parâmetros para o algoritmo MergeSort e Merge, respectivamente.

**5)** Implemente uma versão iterativa do algoritmo Merge Sort.


### Quick Sort

<!--
    evitar pior caso: escolha do pivô. aleatório, mediana de três, mediana de cinco
-->

**1)** Algoritmos "simplórios", como o *Insertion Sort*, normalmente são mais rápidos para ordenar vetores pequenos do que algoritmos mais sofisticados, como o Quick Sort. Por essa razão é comum invocar *Insertion Sort* ao invés de uma chamada recursiva para *Quick Sort* quando o subvetor se torna menor que um certo $M$, que varia de $10$ a $20$. Implemente essa variação e experimente com $M$ entre $10$ e $20$. Compare o tempo de execução dessa versão com a versão do *Quick Sort* discutida no vídeo. Avalie a ordenação com vetores de 100000 posições contendo números aleatórios.

**2)** Uma variação da abordagem anterior simplesmente não ordena os subvetores menores que $M$. Ao invés de chamar *Insertion Sort* para ordenar cada subvetor menor que $M$, somente uma chamada a *Insertion Sort* é realizada após a execução completa do *Quick Sort*. Compare o tempo de execução dessa versão com os resultados obtidos no exercício anterior. Avalie a ordenação com vetores de 100000 posições contendo número aleatórios.

<!-- **3)** Conforme discutido no vídeo, o tempo de execução do *Quick Sort* no caso médio e no melhor caso é $\Theta(n \lg n)$. Além disto, o custo de *partition*, é significativamente menor que *merge*, fazendo com que o Quick Sort seja mais rápido que o *Merge Sort*, outro algoritmo de ordenação eficiente. Entretanto, no pior caso, o desempenho do *Quick Sort* pode degenerar para $\Theta(n^2)$. O pior caso (que é a permutação inicial do vetor a ser ordenado que leva ao tempo $\Theta(N^2)$) varia de acordo com a forma que o pivô é escolhido. No vídeo eu discuti que a versão de *partition* implementada sempre usa o último elemento do vetor como pivô e que, nessa implementação, o pior caso ocorre quando o vetor de entrada está ordenado em ordem crescente ou decrescente.

**a.** Ordene o vetor $v = [ 1, 2, 3, 4, 5 ]$ usando as implementações de *Quick Sort* e *partition* apresentadas nos vídeos. Qual a peculiaridade que você notou?

**b.** ***QuickSort randomizado:*** Para evitar que o algoritmo caia no pior caso discutido no enunciado, uma modificação pode ser realizada na função *partition*. Ao invés de usar o elemento que já está na última posição do subvetor ($v[r]$) no início da execução de *partition*, um elemento aleatório do subvetor $v[p \dots r]$ é trocado com o elemento $v[r]$ antes da linha $x = v[r]$. Assim, mesmo que o subvetor esteja inicialmente ordenado, há uma chance significativa que um elemento intermediário seja escolhido como pivô, evitando o pior caso. Implemente essa modificação na função *partition* apresentada no vídeo. Compare o tempo de execução do Quick Sort com essa versão modificada do *partition* com a versão discutida no vídeo em: **i.** um vetor já ordenado de 50000 posições; e **ii.** um vetor aleatório com 50000 posições. 

**c.** Embora a modificação apresentada no item **b** acima evite o pior caso do *Quick Sort*, o custo de gerar o número aleatório pode atrapalhar o desempenho do *Quick Sort* no caso médio. Uma abordagem alternativa bastante conhecida consiste em escolher o número mediano entre três elementos em posições fixas do subvetor. As posições comumente utilizadas são $p$, $r$ e $(p+r)/2$. Esta abordagem é conhecida como *mediana de três*. Note que as três posições escolhidas não são aleatórias, uma vez que estamos evitando chamar a função de geração de números aleatórios. Implemente essa modificação na função *partition* apresentada no vídeo. Execute os mesmos testes realizados no experimento proposto no item **b** e compare os resultados.

**d.** Combine a estratégia apresentada no exercício **1** com o exercício **3b** e **3c** (*1 + 3b*, *1 + 3c*) e compare com os resultados obtidos nos exercícios **1**, **3b** e **3c**. O que você notou? -->

<!-- # Atividade Para Entregar

A atividade a seguir é para ser feita individualmente e entregue via Moodle no tópico da Semana 1. A data-limite para entrega é dia 18/10/2021 às 23:55. Em caso de cópia as atividades dos participantes serão desconsideradas. -->

<!-- ## Descrição da Atividade -->

**3)** Conforme discutido no vídeo, o tempo de execução do *Quick Sort* no caso médio e no melhor caso é $\Theta(n \lg n)$. Além disto, o custo de *partition*, é significativamente menor que *merge*, fazendo com que o Quick Sort seja mais rápido que o *Merge Sort*, outro algoritmo de ordenação eficiente. Entretanto, no pior caso, o desempenho do *Quick Sort* pode degenerar para $\Theta(n^2)$. O pior caso (que é a permutação inicial do vetor a ser ordenado que leva ao tempo $\Theta(N^2)$) varia de acordo com a forma que o pivô é escolhido. No vídeo eu discuti que a versão de *partition* implementada sempre usa o último elemento do vetor como pivô e que, nessa implementação, o pior caso ocorre quando o vetor de entrada está ordenado em ordem crescente ou decrescente.

**a.** Ordene o vetor $v = [ 1, 2, 3, 4, 5 ]$ usando as implementações de *Quick Sort* e *partition* apresentadas nos vídeos. Qual a peculiaridade que você notou?

**b.** ***QuickSort randomizado:*** Para evitar que o algoritmo caia no pior caso discutido no enunciado, uma modificação pode ser realizada na função *partition*. Ao invés de usar o elemento que já está na última posição do subvetor ($v[r]$) no início da execução de *partition*, um elemento aleatório do subvetor $v[p \dots r]$ é trocado com o elemento $v[r]$ antes da linha $x = v[r]$. Assim, mesmo que o subvetor esteja inicialmente ordenado, há uma chance significativa que um elemento intermediário seja escolhido como pivô, evitando o pior caso. Implemente essa modificação na função *partition* apresentada no vídeo.

<!-- **i.** um vetor já ordenado de 50000 posições; e **ii.** um vetor aleatório com 50000 posições.  -->

**c.** ***QuickSort (Mediana de Três):***  Embora a modificação apresentada no item **b** acima evite o pior caso do *Quick Sort*, o custo de gerar o número aleatório pode atrapalhar o desempenho do *Quick Sort* no caso médio. Uma abordagem alternativa bastante conhecida consiste em escolher o número mediano entre três elementos em posições fixas do subvetor. As posições comumente utilizadas são $p$, $r$ e $(p+r)/2$. Esta abordagem é conhecida como *mediana de três*. Note que as três posições escolhidas não são aleatórias, uma vez que estamos evitando chamar a função de geração de números aleatórios. Implemente essa modificação na função *partition* apresentada no vídeo. Execute os mesmos testes realizados no experimento proposto no item **b** e compare os resultados.

**d.** Usando o Quick Sort implementado de acordo com o Vídeo e as duas variações implementadas nos itens **b** e **c** acima, preencha as tabelas a seguir. Para preencher a Tabela \ref{tab:resultados_aleatorios} você deve usar a função ``random_vector`` implementada conforme descrito acima para gerar o mesmo vetor para avaliar as três variantes do Quick Sort. Use a semente *42* e *max = 100\*n*. 

Para cronometrar a execução de cada algoritmo você pode usar a função [*clock()*](http://cplusplus.com/reference/ctime/clock/). Clique no link para aprender como usá-la.

\begin{table}[h!]
\centering
\begin{tabular}{|c|c|c|c|}
\hline
 & Quick Sort (Vídeo) & Quick Sort Randomizado & Quick Sort (Mediana de Três) \\[10pt] \hline
n = 100 &  &  &  \\[10pt] \hline
n = 1000 &  &  &  \\[10pt] \hline
n = 10000 &  &  &  \\[10pt] \hline
n = 50000 &  &  &  \\[10pt] \hline
\end{tabular}
\caption{Tempo de Execução (em segundos) do Quick Sort com vetores contendo \textit{n} elementos aleatórios}
\label{tab:resultados_aleatorios}
\end{table}

\begin{table}[h!]
\centering
\begin{tabular}{|c|c|c|c|}
\hline
 & Quick Sort (Vídeo) & Quick Sort Randomizado & Quick Sort (Mediana de Três) \\[10pt] \hline
n = 100 &  &  &  \\[10pt] \hline
n = 1000 &  &  &  \\[10pt] \hline
n = 10000 &  &  &  \\[10pt] \hline
n = 50000 &  &  &  \\[10pt] \hline
\end{tabular}
\caption{Tempo de Execução (em segundos) do Quick Sort com vetores contendo \textit{n} elementos ordenados}
\label{tab:resultados_ordenados}
\end{table}

**e.** Analisando os resultados das Tabelas \ref{tab:resultados_aleatorios} e \ref{tab:resultados_ordenados}, responda as perguntas a seguir.

**i)** Considerando a ordenação dos vetores contendo *n* elementos aleatórios (Tabela \ref{tab:resultados_aleatorios}), algum dos algoritmos é mais eficiente? Se sim, qual? Justifique.

**ii)** Considerando a ordenação dos vetores contendo *n* elementos já ordenados (Tabela \ref{tab:resultados_ordenados}), algum dos algoritmos é mais eficiente? Se sim, qual? Justifique. 

**iii)** Qual desses algoritmos você utilizaria na prática? Por quê?

## Código auxiliar

Nesta atividade faremos uma comparação entre duas variantes do algoritmo Quick Sort. Para que a comparação seja justa, os vetores utilizados devem ter os mesmos elementos. Para isso, implemente a função ``int* random_vector(int n, int max, int seed)`` que retorna um vetor de inteiros de tamanho *n* alocado dinâmicamente e preenchido com valores aleatórios de 0 a *max* gerados a partir da semente *seed*. Você pode usar a função [*rand()*](http://cplusplus.com/reference/cstdlib/rand/) da *stdlib.h* para gerar um número aleatório e [*srand()*](http://cplusplus.com/reference/cstdlib/srand/) para alterar a semente do gerador de números aleatórios. Dessa forma a chamada ``random_vetor(100, 1000, 0)``, por exemplo, sempre gerará um vetor aleatório de números de 0 a 1000 com 100 posições sempre na mesma sequencia.

<!-- ## Você deve Entregar

Entregue em formato .zip os arquivos a seguir:

* Um arquivo *pdf* com as tabelas do **d** e as respostas dos itens **a** e **e**;
* Um arquivo .c com os códigos-fonte desenvolvidos, inclusive o programa principal. -->

<!-- Mudei a atividade pq nesta versão do curso estamos estudando os algoritmos Merge e Quick antes dos algoritmos clássicos. -->
<!-- Nesta atividade vamos comparar o desempenho dos algoritmos de ordenação desenvolvidos até o momento. Em todos os experimentos abaixo utilize sua função *int\* random_vector(int n, int max, int seed)* desenvolvida na atividade da semana passada para gerar os vetores aleatórios. Utilize *seed = 0*.

**a)** Seja N o número de elementos em um vetor. Gere vetores aleatórios com $N = 1000$, $N = 10000$, $N = 100000$ e $N = 500000$ elementos. O valor dos elementos deve ser entre 0 e N*100 (por exemplo, no vetor com $N=1000$ elementos, os números devem ser sorteados entre 0 e 100000). Ordene esses vetores com os 5 algoritmos de ordenação estudados até o momento. Anote apenas o tempo de execução de cada algoritmo na tabela a seguir:

\centering
![](tab_sem2.png)

\justify

\noindent
**b)** Execute os mesmos testes que no item anterior, mas dessa vez, use vetores já ordenados como entrada. Anote apenas o tempo de execução de cada algoritmo em uma tabela como a apresentada acima.

\noindent
**c)** De acordo com os resultados obtidos nos itens **a** e **b**, responda as perguntas a seguir:

**i)** Qual algoritmo você usaria em um vetor que está praticamente ordenado, ou seja, tem apenas alguns elementos fora do lugar? Por quê?

**ii)** Qual algoritmo você usaria para ordenar um vetor que está ordenado em ordem decrescente? Por quê? (vamos fazer de conta que essa é a melhor forma de ordenar um vetor ordenado em ordem decrescente)

**iii)** Qual algoritmo você usaria em um vetor que você não faz idéia sobre a ordem dos elementos? Por quê?

**iv)** Você usaria os algoritmos ineficientes em alguma situação? Se sim, qual deles você usaria? Em que situação?


## Você deve Entregar

Entregue em formato .zip os arquivos a seguir:

* Um arquivo *pdf* com as tabelas dos itens **a** e **b** e as respostas do item **c**;
* Um arquivo .c com o programa principal utilizado para gerar os resultados no item **a** e **b**.
-->

<!-- **Por favor entregue como especificado acima!**  -->

<!-- 
Uma forma de avaliar o desempenho de algoritmos de ordenação consiste em contar quantas comparações são realizadas durante a execução. Nesta atividade você vai comparar a quantidade de comparações realizadas pelos três algoritmos estudados em função do tamanho do vetor.

**a)** Para que a comparação seja justa, os vetores utilizados devem ter os mesmos elementos. Para isso, implemente a função *int\* random_vector(int n, int max, int seed)* que retorna um vetor de inteiros de tamanho *n* alocado dinâmicamente e preenchido com valores aleatórios de 0 a *max* gerados a partir da semente *seed*. Você pode usar a função [*rand()*](http://cplusplus.com/reference/cstdlib/rand/) da *stdlib.h* para gerar um número aleatório e [*srand()*](http://cplusplus.com/reference/cstdlib/srand/) para alterar a semente do gerador de números aleatórios. Dessa forma a chamada *random_vetor(100, 1000, 0)* sempre gerará um vetor aleatório de números de 0 a 1000 com 100 posições sempre na mesma sequencia.

**b)** Altere os algoritmos apresentados nos vídeos 1, 2 e 3 para retornarem a quantidade de comparações diretas entre 2 elementos do vetor. A posição que o contador é incrementado varia de acordo com o algoritmo. No algoritmo SelectionSort, as comparações diretas acontecem na função *max*. No algoritmo BubbleSort devemos contar quantas vezes a comparação *if(v[i] > v[i+1])* é executada (não somente quantas vezes é verdadeira). Ja no algoritmo InsertionSort devemos contar quantas vezes o conteúdo do laço *while* é repetido. Note que, no caso das rotinas SelectionSort e InsertionSort estamos interessados na soma total dass comparações efetuadas pelas funções auxiliares *insertion* e *max*.

**c)** Gere vetores aleatórios com 10, 100, 1000 e 10000 usando sua função *random_vector* com *seed = 0*. Execute os 3 algoritmos alterados no item *b* em cada um dos vetores gerados. Anote o número, em notação científica com 3 casas decimais, o número de comparações realizadas na tabela a seguir:

\centering
![](tab.png)

\justify

Anote também, em segundos, o tempo que cada algoritmo demorou para executar. Utilize a função [*clock()*](http://cplusplus.com/reference/ctime/clock/). Anote suas medidas em uma tabela.

\noindent
**d)** Responda:

\noindent
**i)** Algum algoritmo executou consideravelmente menos comparações considerando vetores com mais que 10 elementos?

\noindent
**ii)** O algoritmo que executou menos comparações foi o que precisou de menos tempo para executar a ordenação?

\noindent
**iii)** O que tem de interessante nos dois algoritmos com maior numero de comparações em relação ao tempo de execução? Explique o resultado.

## Você deve Entregar

Entregue em formato .zip os arquivos a seguir:

* Um arquivo *pdf* com as tabelas do item *c* e as respostas do item *d*;
* Um arquivo .c com a implementação dos algoritmos propostos nos itens *a* e *b* e o programa principal utilizado para gerar os resultados no item *c*.

**Por favor entregue como especificado acima!** -->


\vspace{50pt}

\Large
\centering
**BONS ESTUDOS!**
