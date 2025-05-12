# [Platinum II] Knapsack in a Globalized World - 13149 

[문제 링크](https://www.acmicpc.net/problem/13149) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

데이크스트라, 그래프 이론, 배낭 문제, 최단 경로

### 제출 일자

2025년 5월 12일 22:48:14

### 문제 설명

<p>Globalization stops at nothing, not even at the good old honest profession of a burglar. Nowadays it is not enough to break in somewhere, take everything you can carry and dart off. No! You have to be competitive, optimize your profit and utilize synergies.</p>

<p>So, the new game rules are:</p>

<ul>
	<li>break only into huge stores, so there is practically endless supply of any kind of items;</li>
	<li>your knapsack should be huge;</li>
	<li>your knapsack should be full (there should be no empty space left).</li>
</ul>

<p>Damn you, globalization, these rules are not easy to follow! Luckily, you can write a program, which will help you decide whether you should loot a store or not.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers n (1 ≤ n ≤ 20) and k (1 ≤ k ≤ 10<sup>18</sup>), where n is the number of different item types and k is the size of your knapsack;</li>
	<li>one line with n integers g<sub>1</sub>, . . . , g<sub>n</sub> (1 ≤ g<sub>i</sub> ≤ 10<sup>3</sup> for all 1 ≤ i ≤ n), where g<sub>1</sub>, . . . , g<sub>n</sub> are the sizes of the n item types.</li>
</ul>

### 출력 

 <p>Output “possible” if it is possible to fill your knapsack with items from the store (you may assume that there are enough items of any type), otherwise output “impossible”.</p>

