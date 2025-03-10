# [Gold V] Cow Frisbee Team - 6104 

[문제 링크](https://www.acmicpc.net/problem/6104) 

### 성능 요약

메모리: 2152 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 수학, 정수론

### 제출 일자

2025년 3월 10일 20:05:31

### 문제 설명

<p>After Farmer Don took up Frisbee, Farmer John wanted to join in the fun. He wants to form a Frisbee team from his N cows (1 <= N <= 2,000) conveniently numbered 1..N. The cows have been practicing flipping the discs around, and each cow i has a rating R_i (1 <= R_i <= 100,000) denoting her skill playing Frisbee. FJ can form a team by choosing one or more of his cows.</p>

<p>However, because FJ needs to be very selective when forming Frisbee teams, he has added an additional constraint. Since his favorite number is F (1 <= F <= 1,000), he will only accept a team if the sum of the ratings of each cow in the team is exactly divisible by F.</p>

<p>Help FJ find out how many different teams he can choose. Since this number can be very large, output the answer modulo 100,000,000.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and F</li>
	<li>Lines 2..N+1: Line i+1 contains a single integer: R_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer representing the number of teams FJ can choose, modulo 100,000,000.</li>
</ul>

