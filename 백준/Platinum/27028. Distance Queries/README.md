# [Platinum V] Distance Queries - 27028 

[문제 링크](https://www.acmicpc.net/problem/27028) 

### 성능 요약

메모리: 9704 KB, 시간: 24 ms

### 분류

최소 공통 조상, 트리

### 제출 일자

2025년 8월 18일 17:02:18

### 문제 설명

<p>Farmer John's cows refused to run in his marathon since he chose a path much too long for their leisurely lifestyle. He therefore wants to find a path of a more reasonable length. The input to this problem consists of the same input as in "<a href="/problem/27026">Navigation Nightmare</a>",followed by a line containing a single integer K, followed by K "distance queries". Each distance query is a line of input containing two integers, giving the numbers of two farms between which FJ is interested in computing distance (measured in the length of the roads along the path between the two farms). Please answer FJ's distance queries as quickly as possible!</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..M+1: Each line contains four space-separated entities, F1, F2, L, and D that describe a road. F1 and F2 are numbers of two farms connected by a road, L is its length, and D is a character that is either 'N', 'E', 'S', or 'W' giving the direction of the road from F1 to F2.</li>
	<li>Line 2+M: A single integer, K. 1 ≤ K ≤ 10,000</li>
	<li>Lines 3+M..2+M+K: Each line corresponds to a distance query and contains the indices of two farms.</li>
</ul>

### 출력 

 <ul>
	<li>Lines 1..K: For each distance query, output on a single line an integer giving the appropriate distance.</li>
</ul>

