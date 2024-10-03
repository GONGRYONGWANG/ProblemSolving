# [Platinum V] Sleepy Cow Sorting - 17022 

[문제 링크](https://www.acmicpc.net/problem/17022) 

### 성능 요약

메모리: 7176 KB, 시간: 68 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2024년 10월 3일 18:41:25

### 문제 설명

<p>Farmer John is attempting to sort his $N$ cows ($1 \leq N \leq 10^5$), conveniently numbered $1 \dots N$, before they head out to the pastures for breakfast.</p>

<p>Currently, the cows are standing in a line in the order $p_1, p_2, p_3, \dots, p_N$, and Farmer John is standing in front of cow $p_1$. He wants to reorder the cows so that they are in the order $1, 2, 3, \dots, N$, with cow $1$ next to Farmer John.</p>

<p>Today the cows are a bit sleepy, so at any point in time the only cow who is paying attention to Farmer John's instructions is the cow directly facing Farmer John. In one time step, he can instruct this cow to move $k$ paces down the line, for any $k$ between $1$ and $N-1$ inclusive. The $k$ cows whom she passes will amble forward, making room for her to insert herself in the line after them.</p>

<p>For example, suppose that $N=4$ and the cows start off in the following order:</p>

<p>FJ: 4, 3, 2, 1</p>

<p>The only cow paying attention to FJ is cow $4$. If he instructs her to move $2$ paces down the line, the order will subsequently look like this:</p>

<p>FJ: 3, 2, 4, 1</p>

<p>Now the only cow paying attention to FJ is cow $3$, so in the second time step he may give cow $3$ an instruction, and so forth until the cows are sorted.</p>

<p>Farmer John is eager to complete the sorting, so he can go back to the farmhouse for his own breakfast. Help him find a sequence of instructions that sorts the cows in the minimum number of time steps.</p>

### 입력 

 <p>The first line of input contains $N$. The second line contains $N$ space-separated integers: $p_1, p_2, p_3, \dots, p_N$, indicating the starting order of the cows.</p>

### 출력 

 <p>The first line should contain a single integer, $K$, giving the minimum number of time steps required to sort the cows.</p>

<p>The second line should contain $K$ space-separated integers, $c_1, c_2, \dots, c_K$, each in the range $1 \ldots N-1$. Furthermore, if in the $i$-th time step FJ instructs the cow facing him to move $c_i$ paces down the line, then after $K$ time steps the cows should be in sorted order.</p>

<p>If there are multiple optimal instruction sequences, your program may output any of them.</p>

