# [Gold II] piloti - 3210 

[문제 링크](https://www.acmicpc.net/problem/3210) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐

### 제출 일자

2025년 4월 29일 02:33:37

### 문제 설명

<p>Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible.</p>

<p>There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain.</p>

<p>Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.</p>

### 입력 

 <p>The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company.</p>

<p>The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).</p>

### 출력 

 <p>The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. </p>

