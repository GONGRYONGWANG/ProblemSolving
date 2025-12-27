# [Gold I] Farmer - 23499 

[문제 링크](https://www.acmicpc.net/problem/23499) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

해 구성하기, 수학

### 제출 일자

2025년 12월 28일 01:11:48

### 문제 설명

<p>You are given three numbers $n, k$ and $x$. Construct an array $A$ with the following properties: </p>

<ul>
	<li> $A$ contains exactly $n$ elements.</li>
	<li>All elements of $A$ are positive integers smaller than $10^6$.</li>
	<li>There are <strong>exactly</strong> $k$ pairs of indices $(i, j)$ such that: $1 \le i < j \le n$ and $|A_i - A_j| \geq x$.</li>
</ul>

### 입력 

 <p>Single line of input contains three numbers $n$ $(1 \leq n \leq 1000)$, $k$ $(0 \leq k \leq \frac{n\cdot (n-1)}{2})$, $x$  $(2\leq x \leq 1000)$.</p>

### 출력 

 <p>In single line of output print $n$ integers, elements of array $A$. In case there is no array with needed properties, print $-1$</p>

