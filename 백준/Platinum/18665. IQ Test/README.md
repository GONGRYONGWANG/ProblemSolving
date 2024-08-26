# [Platinum V] IQ Test - 18665 

[문제 링크](https://www.acmicpc.net/problem/18665) 

### 성능 요약

메모리: 2040 KB, 시간: 0 ms

### 분류

애드 혹, 그리디 알고리즘, 재귀

### 제출 일자

2024년 8월 26일 14:52:27

### 문제 설명

<p>You are given a set S of integers. Initially, S contains 0, 1, and 2.</p>

<p>You can perform zero or more steps. On each step, you choose two elements (possibly equal) x and y such that x ∈ S and y ∈ S, and insert the number x<sup>2</sup> − y into the set S.</p>

<p>You can not perform more than 43 steps.</p>

<p>Your task is to get the integer n in your set.</p>

### 입력 

 <p>The first line contains a single integer n (0 ≤ n ≤ 10<sup>18</sup>), the number you have to get in the set.</p>

### 출력 

 <p>For each step, print x and y on a separate line. The condition 0 ≤ x<sup>2</sup> − y ≤ 10<sup>18</sup> must be satisfied.</p>

<p>The number of steps must be at most 43. Note that you don’t have to minimize it. If there are several possible solutions, print any one of them.</p>

