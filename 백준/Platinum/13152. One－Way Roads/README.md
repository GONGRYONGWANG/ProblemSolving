# [Platinum I] One-Way Roads - 13152 

[문제 링크](https://www.acmicpc.net/problem/13152) 

### 성능 요약

메모리: 2364 KB, 시간: 4 ms

### 분류

이분 탐색, 최대 유량, 매개 변수 탐색, 그래프 이론

### 제출 일자

2025년 5월 12일 15:45:41

### 문제 설명

<p>In the country of Via, the cities are connected by roads that can be used in both directions. However, this has been the cause of many accidents since the lanes are not separated: The drivers frequently look at their smartphones while driving, causing them to collide with the oncoming traffic. To alleviate the problem, the politicians of Via came up with the magnificent idea to have one-way roads only, i.e., the existing roads are altered such that each can be only used in one of two possible directions. They call this “one-way-ification”.</p>

<p>The mayors do not want too many one-way roads to lead to their cities because this can cause traffic jam within the city: they demand that the smallest integer d be found such that there is a ‘one-way-ification’ in which for every city, the number of one-way roads leading to it is at most d.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with an integer n (1 ≤ n ≤ 500), where n is the number of cities labeled from 1 to n;</li>
	<li>one line with an integer m (0 ≤ m ≤ 2.5 · 10<sup>3</sup>), where m is the number of (bi-directional) roads;</li>
	<li>m lines describing the roads. Each road is described by:
	<ul>
		<li>one line with two integers a and b (1 ≤ a, b ≤ n, a ≠ b) indicating a road between cities a and b.</li>
	</ul>
	</li>
</ul>

<p>There is at most one road between two cities.</p>

### 출력 

 <p>Output the minimum number d.</p>

