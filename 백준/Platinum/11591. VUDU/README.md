# [Platinum III] VUDU - 11591 

[문제 링크](https://www.acmicpc.net/problem/11591) 

### 성능 요약

메모리: 48900 KB, 시간: 576 ms

### 분류

자료 구조, 세그먼트 트리, 누적 합, 분할 정복

### 제출 일자

2026년 2월 15일 23:24:09

### 문제 설명

<p>Young Mirko has been buying voodoo dolls lately. Considering that he is very interested in the cheapest purchase possible, he has been tracking the prices of voodoo dolls each day. His price list consists of doll prices in the last N days, where doll price a<sub>i</sub> represents the price of a doll i days ago.</p>

<p>Mirko thinks he has noticed a connection between the average doll price in a sequence of consecutive days and the price on the following day. He wants to test his hunch and is puzzled by a very interesting question: “For a given P, how many different consecutive subsequences in the last N days are there, when the average doll price was greater than or equal to P?”</p>

<p>Two consecutive subsequences are considered different if their beginnings or ends are different.</p>

### 입력 

 <p>The first line of input contains the integer N, the sequence length (1 ≤ N ≤ 1 000 000). The second line of input contains N prices a<sub>i</sub> (0 ≤ a<sub>i</sub> ≤ 1 000 000 000). The third line of input contains an integer P. (0 ≤ P ≤ 1 000 000 000).</p>

### 출력 

 <p>The first and only line of output must contain the answer to Mirko’s question for a given P.</p>

