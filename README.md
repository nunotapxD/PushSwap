# push_swap

<p align="center">
  <img src="https://img.shields.io/badge/42-Porto-blue" alt="42 Porto"/>
  <img src="https://img.shields.io/badge/Norma-inge--pushswap-lightgrey" alt="Norminette"/>
  <img src="https://img.shields.io/badge/Language-C-00599C" alt="C"/>
</p>

## 📖 Sobre o projeto

**push_swap** é um projeto da 42 Porto cujo objetivo é ordenar uma pilha (stack) de números inteiros usando o **menor número de instruções possível**, recorrendo a duas pilhas (`a` e `b`) e a um conjunto restrito de operações.

O programa recebe uma lista de números como argumentos e imprime na saída padrão a sequência de instruções necessária para ordenar a pilha `a` por ordem crescente, com os menores valores no topo.

Este projeto trabalha três competências centrais:

- **Algoritmos** e complexidade (Big O)
- **Estruturas de dados** (listas ligadas, pilhas)
- Escrita de código limpo, em C, respeitando a **Norminette**

---

## ⚙️ Compilação

```bash
make
```

Isto gera o executável `push_swap` a partir dos ficheiros fonte, seguindo as regras do `Makefile` (obrigatório incluir pelo menos as regras `all`, `clean`, `fclean` e `re`).

---

## ▶️ Utilização

```bash
./push_swap [argumentos]
```

### Exemplos

```bash
./push_swap 2 1 3 6 5 8
```

```bash
ARGS="4 67 3 87 23 1 2 3 5 9 0 -1"
./push_swap $ARGS
```

Se os argumentos não formarem uma lista válida de inteiros (duplicados, overflow, caracteres inválidos), o programa deve imprimir `Error` seguido de uma nova linha em `stderr` e terminar.

Se a pilha já estiver ordenada ou tiver 0/1 elemento, não deve imprimir nada.

---

## 🧱 Operações permitidas

| Instrução | Descrição |
|-----------|-----------|
| `sa` | Troca os dois primeiros elementos do topo da pilha `a` |
| `sb` | Troca os dois primeiros elementos do topo da pilha `b` |
| `ss` | `sa` e `sb` ao mesmo tempo |
| `pa` | Coloca o elemento do topo de `b` no topo de `a` |
| `pb` | Coloca o elemento do topo de `a` no topo de `b` |
| `ra` | Move o topo de `a` para o fundo (rotação para cima) |
| `rb` | Move o topo de `b` para o fundo (rotação para cima) |
| `rr` | `ra` e `rb` ao mesmo tempo |
| `rra` | Move o fundo de `a` para o topo (rotação inversa) |
| `rrb` | Move o fundo de `b` para o topo (rotação inversa) |
| `rrr` | `rra` e `rrb` ao mesmo tempo |

---

## 🧠 Estratégia do algoritmo

A abordagem geral costuma seguir estes passos:

1. **Parsing e validação** dos argumentos (converter para inteiros, detetar duplicados/overflow).
2. **Colocar tudo na pilha `a`**.
3. **Dividir e mover parte dos elementos para `b`**, usando um critério de posição/índice (por exemplo, dividir o intervalo de valores em "chunks").
4. **Ordenar progressivamente**, movendo elementos de volta para `a` na posição correta, escolhendo sempre a rotação mais barata (`ra`/`rra`, combinando com `rb`/`rrb` via `rr`/`rrr` quando possível).
5. **Casos pequenos otimizados**:
   - 2 elementos → no máximo 1 `sa`
   - 3 elementos → algoritmo fixo com no máximo 2/3 instruções
   - 5 elementos → mover 2 para `b`, ordenar os 3 restantes em `a`, reinserir
   - 100 / 500 elementos → algoritmo genérico (ex.: turk/radix sort ou divisão em chunks)

### Complexidade alvo (referência típica de avaliação)

| Nº de elementos | Nº de instruções (aproximado) |
|---|---|
| 3 | ≤ 3 |
| 5 | ≤ 12 |
| 100 | ≤ 700 (ideal < 700, aceitável até ~1300 dependendo dos critérios) |
| 500 | ≤ 5500 (ideal < 5500, aceitável até ~11500 dependendo dos critérios) |

> ⚠️ Estes valores variam conforme a versão do subject/avaliação em uso — confirma sempre os limites exatos no PDF do teu campus.

---

## 🧪 Testes

Podes verificar se a saída do `push_swap` ordena corretamente a pilha combinando-a com um **checker** (fornecido pela escola ou implementado por ti como bónus):

```bash
ARGS="2 1 3 6 5 8"
./push_swap $ARGS | ./checker_OS $ARGS
```

Resultado esperado: `OK` (ordenado) ou `KO` (não ordenado / erro).

### Contar o número de instruções

```bash
ARGS=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-1000,1000), 100))))")
./push_swap $ARGS | wc -l
```

### Script de teste rápido (exemplo)

```bash
for i in $(seq 1 100); do
    ARGS=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-10000,10000), 500))))")
    ./push_swap $ARGS > /tmp/moves.txt
    ./checker_OS $ARGS < /tmp/moves.txt
done
```

---

## 📁 Estrutura sugerida do projeto

```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h
├── src/
│   ├── main.c
│   ├── parsing.c
│   ├── stack_utils.c
│   ├── operations.c
│   ├── sort_small.c
│   ├── sort_big.c
│   └── ...
└── libft/          # (se usada)
```



## 📜 Licença

Projeto realizado no âmbito do currículo da 42 Porto, para fins educativos.
