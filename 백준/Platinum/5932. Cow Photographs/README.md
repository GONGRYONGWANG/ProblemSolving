# [Platinum IV] Cow Photographs - 5932 

[문제 링크](https://www.acmicpc.net/problem/5932) 

### 성능 요약

메모리: 7564 KB, 시간: 56 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 2월 27일 11:49:47

### 문제 설명

<p>Farmer John wants to take a picture of his entire herd of N (1 <= N <= 100,000) cows conveniently numbered 1..N so he can show off to his friends.</p>

<p>On picture day, the cows run to form a single line in some arbitrary order with position i containing cow c_i (1 <= c_i <= N). Farmer John has his own ideas about how the cows should line up.</p>

<p>FJ thinks cow i may stand only to the left of cow i+1 (for all i, 1 <= i <= N-1) and that cow N may only stand to the left of Cow 1. Of course, no cow will stand to the left of the first (leftmost) cow in the line.</p>

<p>The cows are hungry for the promised post-photo dinner, so Farmer John wants to take the picture as quickly as possible. Cows are not great at following directions, so he will only choose a pair of adjacent cows and have them switch places once per minute. How quickly is Farmer John able to get them into some acceptable order?</p>

<p>Consider a set of 5 cows whose initial lineup looks like this:</p>

<pre>     Left           Right
        3  5  4  2  1</pre>

<p>He can first swap the second pair of cows:</p>

<pre>        3  4  5  2 1</pre>

<p>and then swap the rightmost pair:</p>

<pre>        3  4  5  1  2</pre>

<p>to yield an acceptable lineup that required but two minutes of cow swapping.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains the number of the i-th cow in line: c_i</li>
</ul>

<p> </p>

### 출력 

 <p>Line 1: The minimum amount of time, in minutes, that it takes Farmer John to get the cows into some appropriate order.</p>

