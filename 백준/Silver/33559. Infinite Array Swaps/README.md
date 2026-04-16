# [Silver III] Infinite Array Swaps - 33559 

[문제 링크](https://www.acmicpc.net/problem/33559) 

### 성능 요약

메모리: 7408 KB, 시간: 80 ms

### 분류

자료 구조, 정렬, 해 구성하기, 해시를 사용한 집합과 맵

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<blockquote>
<p><strong>이 문제는 <a href="/problem/33567" target="_blank">Finite Array Swaps</a>와 굵은 글씨로 적힌 부분과 입출력만 다릅니다.</strong></p>
</blockquote>

<p>동우는 길이가 $N$인 두 배열 $A=\left[ A_1,A_2,\cdots ,A_N \right]$과 $B=\left[ B_1,B_2,\cdots ,B_N \right]$을 가지고 있다.</p>

<p>동우는 두 배열에 다음 두 시행을 <strong>각각 원하는 만큼</strong> 할 수 있다. 교환하는 두 원소의 인덱스는 달라야 한다.</p>

<ul>
	<li>배열 $A$에서 두 원소를 골라 교환한다.</li>
	<li>배열 $B$에서 두 원소를 골라 교환한다.</li>
</ul>

<p>이 연산을 통해 얻은 최종 상태에서의 두 배열을 $A^\prime=\left[ A_1^\prime,A_2^\prime,\cdots ,A_N^\prime \right]$과 $B^\prime=\left[ B_1^\prime,B_2^\prime,\cdots ,B_N^\prime \right]$이라 할 때, 동우는 $A_i^\prime=B_i^\prime$를 만족하는 쌍의 개수를 최대화하려고 한다. 두 배열이 주어질 때, 이를 최대로 하는 교환을 찾아보자.</p>

### 입력 

 <p>첫 번째 줄에 두 배열의 길이 $N(1\le N\le 10^5)$이 주어진다.</p>

<p>두 번째 줄에 배열 $A$의 원소 $A_1,A_2,\cdots ,A_N(1\le A_i\le 10^9)$이 공백으로 구분되어 주어진다.</p>

<p>세 번째 줄에 배열 $B$의 원소 $B_1,B_2,\cdots ,B_N(1\le B_i\le 10^9)$이 공백으로 구분되어 주어진다.</p>

<p>주어지는 입력은 모두 정수이다.</p>

### 출력 

 <p>첫 번째 줄에 $A_i^\prime=B_i^\prime$를 만족하는 쌍의 개수의 최댓값을 출력한다.</p>

<p>두 번째 줄에 최종 상태에서의 배열 $A^\prime$의 원소 $A_1^\prime,A_2^\prime,\cdots ,A_N^\prime$을 공백으로 구분하여 출력한다.</p>

<p>세 번째 줄에 최종 상태에서의 배열 $B^\prime$의 원소 $B_1^\prime,B_2^\prime,\cdots ,B_N^\prime$을 공백으로 구분하여 출력한다.</p>

<p>가능한 정답이 여러 개라면 아무거나 하나 출력한다.</p>

