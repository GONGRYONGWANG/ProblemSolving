# [Gold I] Bones’s Battery - 9502 

[문제 링크](https://www.acmicpc.net/problem/9502) 

### 성능 요약

메모리: 2176 KB, 시간: 320 ms

### 분류

그래프 이론, 이분 탐색, 최단 경로, 매개 변수 탐색, 플로이드–워셜

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<p>Bones is investigating what electric shuttle is appropriate for his mom’s school district vehicle. Each school has a charging station. It is important that a trip from one school to any other be completed with no more than K rechargings. The car is initially at zero battery and must always be recharged at the start of each trip; this counts as one of the K rechargings. There is at most one road between each pair of schools, and there is at least one path of roads connecting each pair of schools. Given the layout of these roads and K, compute the necessary range required of the electric shuttle.</p>

### 입력 

 <p>Input begins with a line with one integer T (1 ≤ T ≤ 50) denoting the number of test cases. Each test case begins with a line containing three integers N, K, and M (2 ≤ N ≤ 100, 1 ≤ K ≤ 100), where N denotes the number of schools, K denotes the maximum number of rechargings permitted per trip, and M denotes the number of roads. Next follow M lines each with three integers u<sub>i</sub>, v<sub>i</sub>, and d<sub>i</sub> (0 ≤ u<sub>i</sub>, v<sub>i</sub> < N, u<sub>i</sub> ≠ v<sub>i</sub>, 1 ≤ d<sub>i</sub> ≤ 10<sup>9</sup>) indicating that road i connects schools u<sub>i</sub> and v<sub>i</sub> (0-indexed) bidirectionally with distance d<sub>i</sub>.</p>

### 출력 

 <p>For each test case, output one line containing the minimum range required.</p>

