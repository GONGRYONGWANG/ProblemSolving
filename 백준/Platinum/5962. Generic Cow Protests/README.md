# [Platinum III] Generic Cow Protests - 5962 

[문제 링크](https://www.acmicpc.net/problem/5962) 

### 성능 요약

메모리: 10292 KB, 시간: 100 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 세그먼트 트리, 누적 합, 값 / 좌표 압축

### 제출 일자

2025년 11월 11일 16:13:15

### 문제 설명

<p>Farmer John's N (1 <= N <= 100,000) cows are lined up in a row and numbered 1..N. The cows are conducting another one of their strange protests, so each cow i is holding up a sign with an integer A_i (-10,000 <= A_i <= 10,000).</p>

<p>FJ knows the mob of cows will behave if they are properly grouped and thus would like to arrange the cows into one or more contiguous groups so that every cow is in exactly one group and that every group has a nonnegative sum.</p>

<p>Help him count the number of ways he can do this, modulo 1,000,000,009.</p>

<p>By way of example, if N = 4 and the cows' signs are 2, 3, -3, and 1, then the following are the only four valid ways of arranging the cows:</p>

<pre>(2 3 -3 1)
(2 3 -3) (1)
(2) (3 -3 1)
(2) (3 -3) (1)</pre>

<p>Note that this example demonstrates the rule for counting different orders of the arrangements.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N + 1: Line i + 1 contains a single integer: A_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer, the number of arrangements modulo 1,000,000,009.</li>
</ul>

<p> </p>

