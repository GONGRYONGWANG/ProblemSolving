# [Gold IV] Entertainment Box - 11271 

[문제 링크](https://www.acmicpc.net/problem/11271) 

### 성능 요약

메모리: 5184 KB, 시간: 52 ms

### 분류

자료 구조, 그리디 알고리즘, 정렬, 트리를 사용한 집합과 맵

### 제출 일자

2025년 4월 20일 18:49:12

### 문제 설명

<p>Ada, Bertrand and Charles often argue over which TV shows to watch, and to avoid some of their fights they have finally decided to buy a video tape recorder. This fabulous, new device can record k different TV shows simultaneously, and whenever a show recorded in one the machine’s k slots ends, the machine is immediately ready to record another show in the same slot.</p>

<p>The three friends wonder how many TV shows they can record during one day. They provide you with the TV guide for today’s shows, and tell you the number of shows the machine can record simultaneously. How many shows can they record, using their recording machine? Count only shows that are recorded in their entirety.</p>

### 입력 

 <p>The first line of input contains two integers n, k (1 ≤ k < n ≤ 100 000). Then follow n lines, each containing two integers x<sub>i</sub>, y<sub>i</sub>, meaning that show i starts at time x<sub>i</sub> and finishes by time y<sub>i</sub>. This means that two shows i and j, where y<sub>i</sub> = x<sub>j</sub>, can be recorded, without conflict, in the same recording slot. You may assume that 0 ≤ x<sub>i</sub> < y<sub>i</sub> ≤ 1 000 000 000.</p>

### 출력 

 <p>The output should contain exactly one line with a single integer: the maximum number of full shows from the TV guide that can be recorded with the tape recorder.</p>

