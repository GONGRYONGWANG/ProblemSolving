# [Platinum IV] Program - 18510 

[문제 링크](https://www.acmicpc.net/problem/18510) 

### 성능 요약

메모리: 5928 KB, 시간: 292 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 1월 12일 23:28:45

### 문제 설명

<p>You are given a program operating with integer variable X, which is initially equal to 1. The program consists of n instructions of two types:</p>

<ul>
	<li>“1 p” (1 ≤ p ≤ n), assigns value p to variable X.</li>
	<li>“2 p q” (1 ≤ p, q ≤ n, p 6= q), assigns value q to variable X only if the current value of X is p.</li>
</ul>

<p>In one step, you can remove any single instruction from the program. You can’t reorder instructions or add new instructions. What is the minimum number of steps required to get such a program that, after it runs, the variable X has value k? You are asked to solve this problem for each k from 1 to n.</p>

### 입력 

 <p>The first line of input contains a single integer n (2 ≤ n ≤ 10<sup>6</sup>), the number of instructions in program.</p>

<p>The next n lines contains descriptions of instructions in the format described above.</p>

### 출력 

 <p>Output n integers, where i-th integer is the minimum number of steps required to make program set value i to variable X, or −1 if it is impossible.</p>

