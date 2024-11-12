## Complexidade de Tempo

**Melhor Caso:** O melhor caso ocorre quando o pivô divide o array em duas metades iguais (ou quase iguais). Isso leva a log n níveis de recursão, com cada nível processando O(n) elementos. Ou seja: O(n log n).

**Caso Médio:** No caso médio, o Quick Sort também divide o array em duas metades aproximadamente balanceadas, mas isso pode não ser perfeito em todos os casos. Em geral, a complexidade de tempo no caso médio é O(n log n).

**Pior Caso:** O pior caso ocorre quando o pivô escolhido é sempre o menor ou maior elemento do array, o que faz com que o Quick Sort se torne um algoritmo recursivo simples (similar ao Selection Sort ou Insertion Sort), com uma complexidade de O(n^2). Isso acontece, por exemplo, quando o array já está ordenado ou quase ordenado.

## Complexidade de Espaço

O Quick Sort é eficiente em termos de espaço, mas isso depende se é implementado de forma recursiva ou iterativa.

**Espaço adicional:** É O(log n) no melhor e caso médio, já que a profundidade da pilha de recursão é proporcional ao log n níveis.

**Pior Caso:** No pior caso, a pilha de recursão pode atingir O(n) chamadas devido à divisão desbalanceada.
