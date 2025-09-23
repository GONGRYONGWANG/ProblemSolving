# [Platinum III] Hotels - 10122 

[문제 링크](https://www.acmicpc.net/problem/10122) 

### 성능 요약

메모리: 2572 KB, 시간: 368 ms

### 분류

조합론, 깊이 우선 탐색, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 수학, 트리

### 제출 일자

2025년 9월 23일 20:21:46

### 문제 설명

<p>There are n towns in Byteotia, connected with only n-1 roads. Each road directly links two towns. All the roads have the same length and are two way. It is known that every town can be reached from every other town via a route consisting of one or more (direct-link) roads. In other words, the road network forms a tree.</p>

<p>Byteasar, the king of Byteotia, wants three luxury hotels erected to attract tourists from all over the world. The king desires that the hotels be in different towns and at the same distance one from each other.</p>

<p>Help the king out by writing a program that determines the number of possible locations of the hotel triplet in Byteotia.</p>

### 입력 

 <p>The first line of the standard input contains a single integer n(1 ≤ n ≤ 5,000), the number of towns in Byteotia. The towns are numbered from 1 to n.</p>

<p>The Byteotian road network is then described in n-1 lines. Each line contains two integers a and b (1 ≤ a ≤ b ≤ n) , separated by a single space, that indicate there is a direct road between the towns a and b.</p>

### 출력 

 <p>The first and only line of the standard output should contain a single integer equal to the number of possible placements of the hotels.</p>

