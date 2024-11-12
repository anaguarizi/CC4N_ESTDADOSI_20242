## Complexidade de Tempo

**Melhor Caso**: O melhor caso ocorre quando o array está parcialmente ordenado ou quando não há nenhum benefício de fazer a fusão (merge). No entanto, o Merge Sort sempre realiza a fusão das metades, independentemente da ordem dos elementos, o que implica que a complexidade de tempo será sempre O(n log n), mesmo no melhor caso.

**Caso Médio**: No caso médio, o algoritmo ainda divide o array em duas metades recursivamente e depois faz a fusão de todas as partes. Isso leva a uma complexidade de tempo de O(n log n).

**Pior Caso**: O pior caso também ocorre com a divisão recursiva e a fusão dos arrays, de forma semelhante ao caso médio. O Merge Sort tem um desempenho estável, independentemente da ordem dos elementos.

## Complexidade de Espaço

O(n) — O Merge Sort exige espaço extra para armazenar os subarrays temporários durante o processo de fusão.
