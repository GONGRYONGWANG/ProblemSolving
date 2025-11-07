# [Platinum III] Stretch Rope (Large) - 14305 

[문제 링크](https://www.acmicpc.net/problem/14305) 

### 성능 요약

메모리: 2104 KB, 시간: 3652 ms

### 분류

자료 구조, 덱, 덱을 이용한 구간 최댓값 트릭, 다이나믹 프로그래밍, 덱을 이용한 다이나믹 프로그래밍, 우선순위 큐, 세그먼트 트리

### 제출 일자

2025년 11월 8일 00:47:58

### 문제 설명

<p>Mary likes playing with rubber bands. It's her birthday today, and you have gone to the rubber band shop to buy her a gift.</p>

<p>There are N rubber bands available in the shop. The i-th of these bands can be stretched to have any length in the range [A<sub>i</sub>, B<sub>i</sub>], inclusive. Two rubber bands of range [a, b] and [c, d] can be connected to form one rubber band that can have any length in the range [a+c, b+d]. These new rubber bands can themselves be connected to other rubber bands, and so on.</p>

<p>You want to give Mary a rubber band that can be stretched to a length of exactly L. This can be either a single rubber band or a combination of rubber bands. You have M dollars available. What is the smallest amount you can spend? If it is impossible to accomplish your goal, output <code>IMPOSSIBLE</code> instead.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with 3 integers N, M, L, the number of rubber bands available in the shop, the number of dollars you have and the desired rubber band length. Then N lines follow. Each line represents one rubber band and consists of 3 integers, A<sub>i</sub>, B<sub>i</sub>, and P<sub>i</sub>. [A<sub>i</sub>, B<sub>i</sub>] is the inclusive range of lengths that the i-th rubber band can stretch to, and P<sub>i</sub> is the price of the i-th rubber band in dollars.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is <code>IMPOSSIBLE</code> if you cannot buy rubber bands to satisfy the goal described above, or otherwise an integer: the minimum price you can pay.</p>

