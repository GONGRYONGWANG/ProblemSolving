# [Gold IV] Cow Contest - 6156 

[문제 링크](https://www.acmicpc.net/problem/6156) 

### 성능 요약

메모리: 2164 KB, 시간: 0 ms

### 분류

플로이드–워셜, 그래프 이론, 그래프 탐색, 최단 경로

### 제출 일자

2025년 5월 27일 17:32:07

### 문제 설명

<p>N (1 <= N <= 100) cows, conveniently numbered 1..N, are participating in a programming contest. As we all know, some cows code better than others. Each cow has a certain constant skill rating that is unique among the competitors.</p>

<p>The contest is conducted in several head-to-head rounds, each between two cows. If cow A has a greater skill level than cow B (1 <= A <= N; 1 <= B <= N; A != B), then cow A will always beat cow B.</p>

<p>Farmer John is trying to rank the cows by skill level. Given a list the results of M (1 <= M <= 4,500) two-cow rounds, determine the number of cows whose ranks can be precisely determined from the results. It is guaranteed that the results of the rounds will not be contradictory.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..M+1: Each line contains two space-separated integers that describe the competitors and results (the first integer, A, is the winner) of a single round of competition: A and B</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer representing the number of cows whose ranks can be determined</li>
</ul>

