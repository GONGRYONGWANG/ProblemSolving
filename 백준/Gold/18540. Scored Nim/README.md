# [Gold II] Scored Nim - 18540 

[문제 링크](https://www.acmicpc.net/problem/18540) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

게임 이론, 그리디 알고리즘

### 제출 일자

2024년 11월 11일 00:33:09

### 문제 설명

<p>Alice and Bob want to play Nim. Well, some kind of it.</p>

<p>Initially, they have n heaps of stones, i-th heap containing a<sub>i</sub> stones. Players take alternating turns, Alice moves first. On their turn, a player chooses any heap with at least two stones and splits it into two new heaps with at least one stone in each. After that, the player colors all stones in one of the new heaps white and all stones in the other one black. The game lasts until every heap contains only one stone.</p>

<p>After the game, Alice’s score is the number of white stones on the board, and Bob’s score is the number of black stones. Both players want to maximize their score and play optimally. What will be Alice’s score?</p>

### 입력 

 <p>The first line of input contains a single integer n (1 ≤ n ≤ 128).</p>

<p>The second line of input contains n integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> (2 ≤ a<sub>i</sub> ≤ 128).</p>

<p>Note that the initial colors of the stones are irrelevant.</p>

### 출력 

 <p>Output a single integer: Alice’s score if both players play optimally.</p>

