## Complexidade de Tempo
**Melhor Caso**: O melhor caso ocorre quando o array já está quase ordenado. Nesse caso, o algoritmo pode realizar uma quantidade de trocas muito pequena. Dependendo da sequência de gaps utilizada, o tempo de execução pode ser **O(n log n)** ou até melhor.

**Caso Médio:** O desempenho típico do Shell Sort em arrays aletórios é O(n^{3/2}) para a sequência de gaps mais comum, mas pode variar dependendo da escolha dos gaps. Para a sequência de Hibbard, a complexidade média é O(n^{3/2}).

**Pior Caso**: No pior caso, o Shell Sort pode se comportar como o Insertion Sort, onde a complexidade pode ser tão ruim quanto O(n^2), especialmente se uma sequência de gaps inadequada for usada.

## Complexidade de Espaço
O(1) — O Shell Sort é um algoritmo de ordenação in-place, ou seja, ele não exige memória adicional significativa além da necessária para armazenar o array original.
