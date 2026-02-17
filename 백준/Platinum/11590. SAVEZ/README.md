# [Platinum III] SAVEZ - 11590 

[문제 링크](https://www.acmicpc.net/problem/11590) 

### 성능 요약

메모리: 10624 KB, 시간: 68 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 문자열, 트리, 해싱, 트라이, KMP

### 제출 일자

2026년 2월 17일 22:40:00

### 문제 설명

<p>There are eight planets and one planetoid in the Solar system. It is not a well known fact that there is a secret planet S4 inhabited by small creatures similar to bears, their codename being Lodas. Although this fact is well hidden from the public, the association Savez sent a team lead by general Henrik to study the Lodas. It has been discovered that Lodas have the ability of teleportation and he wants to hire them in his army.</p>

<p>One Lod consists of N strings where the ith string is denoted by x<sub>i</sub>. Research has shown that the number of teleportations a Loda can make depends on one special subsequence (not necessarily consecutive) of these strings. Strings x<sub>i</sub> and x<sub>j</sub> (i < j) can both be in that sequence if and only if string x<sub>j</sub> both starts with and ends with string x<sub>i</sub>. The number of teleportations a Loda can make is the length of the longest described subsequence.</p>

<p>Determine the number of teleportations.</p>

### 입력 

 <p>The first line of input contains of the integer N, the number of strings. Each of the following N lines contains one string consisting of uppercase letters of the English alphabet. The input data will be such that there will be less than two million characters in total.</p>

### 출력 

 <p>The first and only line of output must contain the number of teleportations a Loda can make.</p>

