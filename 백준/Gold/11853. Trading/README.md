# [Gold II] Trading - 11853 

[문제 링크](https://www.acmicpc.net/problem/11853) 

### 성능 요약

메모리: 20684 KB, 시간: 188 ms

### 분류

자료 구조, 우선순위 큐, 스위핑, 트리를 사용한 집합과 맵

### 제출 일자

2025년 1월 8일 00:37:51

### 문제 설명

<p>There are N small villages close to the highway between Almaty and Taraz numbered from 1 to N. At the beginning of the winter M unknown traders began trading knitted hats in these villages. They have only two rules: never trade in one place more than once (one day) and increase the price on hats each day.</p>

<p>More formally, each i-th trader:</p>

<ol>
	<li>begins trading in village L<sub>i</sub> with starting price X<sub>i</sub>.</li>
	<li>each day he moves to the next adjacent village, i.e. if he was trading in village j yesterday, then today he is trading in village j + 1.</li>
	<li>each day he increases the price by 1, so if yesterday's price was x, then today's price is x + 1.</li>
	<li>stops trading at village R<sub>i</sub> (after he traded his knitted hats in village R<sub>i</sub>).</li>
</ol>

<p>The problem is for each village to determine the maximal price that was there during the whole trading history.</p>

### 입력 

 <p>Each line contains two integer number N (1 ≤ N ≤ 300000) and M (1 ≤ M ≤ 300000) - number of villages and traders accordingly.</p>

<p>Next M lines contains 3 numbers each: L<sub>i</sub>, R<sub>i</sub> (1 ≤ L<sub>i</sub> ≤ R<sub>i</sub> ≤ N) and X<sub>i</sub> (1 ≤ X<sub>i</sub> ≤ 10<sup>9</sup>) - numbers of first and last village and starting price for i-th trader.</p>

### 출력 

 <p>Output N integer numbers separating them with spaces - i-th number being the maximal price for the trading history of i-th village. If there was no trading in some village, output 0 for it.</p>

