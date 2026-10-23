
# 🧮 Atividade: Cálculo de Média com `MPI_Reduce`

## 📝 Descrição

O objetivo desta atividade é desenvolver um programa paralelo utilizando a biblioteca **MPI (Message Passing Interface)** para calcular a **média global de valores** distribuídos entre diferentes processos.

Cada processo irá:
- Gerar um vetor local de números aleatórios (no intervalo [0,1]).
- Calcular sua **soma local** e **média local**.
- Utilizar a função `MPI_Reduce` para calcular a **soma global** de todos os valores.
- Com base na soma global, o processo de rank 0 calculará e exibirá a **média global**.

---

## 🎯 Objetivo

Aplicar conceitos de programação paralela com MPI, especialmente o uso de:
- Comunicação coletiva com `MPI_Reduce`
- Geração de dados locais em cada processo
- Cálculo de métricas locais e globais
- Sincronização e responsabilidade do processo mestre

---

## 📥 Entrada

O programa deve receber, via linha de comando, **um único argumento inteiro**:

```
N: o tamanho do vetor local que será gerado por cada processo
```

Exemplo de uso:

```bash
mpirun -np 4 ./media_mpi 1000
```

Neste caso, cada um dos 4 processos criará um vetor local com 1000 valores aleatórios.

---

## ✅ Requisitos

1. Cada processo deve gerar um vetor local de `N` valores aleatórios entre 0 e 1.
2. Cada processo deve calcular:
   - A **soma local** de seus valores
   - A **média local**
3. Utilizar `MPI_Reduce` para:
   - Obter a **soma global** de todos os dados no processo de rank 0
4. O processo de rank 0 deve:
   - Calcular a **média global**
   - Exibir:
     - A soma local e média local de todos os processos (podem ser enviados com `MPI_Gather` ou impressos individualmente)
     - A soma global
     - A média global

---

## 🧪 Exemplo de Saída Esperada

```
[Processo 0] Soma local: 499.837, Média local: 0.4998
[Processo 1] Soma local: 498.912, Média local: 0.4989
[Processo 2] Soma local: 500.441, Média local: 0.5004
[Processo 3] Soma local: 501.322, Média local: 0.5013

[Soma global] 2000.512
[Média global] 0.5001
```

---

## ⚙️ Como compilar e rodar

Compilar (gera o executável `media_mpi`):

```bash
make
```

Rodar com 4 processos e vetores locais de 1000 valores:

```bash
make run
```

Ou rodar diretamente, escolhendo o número de processos e o valor de `N`:

```bash
mpirun -np 4 ./media_mpi 1000
```

Remover o executável:

```bash
make clean
```
