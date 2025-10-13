# [Platinum V] CodeCoder vs TopForces - 13475 

[문제 링크](https://www.acmicpc.net/problem/13475) 

### 성능 요약

메모리: 16656 KB, 시간: 116 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 정렬

### 제출 일자

2025년 10월 13일 22:42:19

### 문제 설명

<p>Competitive programming is very popular in Byteland. In fact, every Bytelandian citizen is registered at two programming sites — CodeCoder and TopForces. Each site maintains its own proprietary rating system. Each citizen has a unique integer rating at each site that approximates their skill. Greater rating corresponds to better skill.</p>

<p>People of Byteland are naturally optimistic. Citizen A thinks that he has a chance to beat citizen B in a programming competition if there exists a sequence of Bytelandian citizens A = P<sub>0</sub>, P<sub>1</sub>, . . . , P<sub>k</sub> = B for some k ≥ 1 such that for each i (0 ≤ i < k), P<sub>i</sub> has higher rating than P<sub>i+1</sub> at one or both sites.</p>

<p>Each Bytelandian citizen wants to know how many other citizens they can possibly beat in a programming competition.</p>

### 입력 

 <p>The first line of the input contains an integer n — the number of citizens (1 ≤ n ≤ 100 000). The following n lines contain information about ratings. The i-th of them contains two integers CC<sub>i</sub> and T F<sub>i</sub> — ratings of the i-th citizen at CodeCoder and TopForces (1 ≤ CC<sub>i</sub>, T F<sub>i</sub> ≤ 10<sup>6</sup>). All the ratings at each site are distinct.</p>

### 출력 

 <p>For each citizen i output an integer b<sub>i</sub> — how many other citizens they can possibly beat in a programming competition. Each b<sub>i</sub> should be printed in a separate line, in the order the citizens are given in the input.</p>

