# [Platinum III] Minimum Cost Flow - 14688 

[문제 링크](https://www.acmicpc.net/problem/14688) 

### 성능 요약

메모리: 5548 KB, 시간: 84 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2026년 4월 17일 19:35:55

### 문제 설명

<p>The city of Watermoo has buildings numbered 1, 2, . . . , N. The city has M pipes that connect pairs of buildings. Due to urban planning oversights, building 1 is the only sewage treatment plant in the city. Each pipe can be either active or inactive. The set of active pipes forms a valid plan if building 1 is directly or indirectly connected to each other building using active pipes. (Pipes directly connect pairs of buildings. Buildings X and Z are indirectly connected if X is directly or indirectly connected to Y , and Y is directly or indirectly connected to Z.)</p>

<p>The municipal government of Watermoo is currently operating a valid plan of N − 1 pipes today, but they think it is too expensive! Each pipe has a monthly maintenance fee that the city must pay when it is active, and the total cost of a valid plan is the sum of the maintenance fees of its active pipes. (Inactive pipes cost nothing.)</p>

<p>Additionally, researchers at the University of Watermoo have developed an experimental pipe enhancer which you can use on one pipe of your choice. It will reduce that pipe’s cost from C down to max(0, C − D), where D is the enhancer’s strength.</p>

<p>The city wants you to minimize the cost of the plan, and they want you to do it quickly. Every day, the city will allow you to activate one pipe, and deactivate another pipe. How many days do you need to make the set of active pipes form a valid plan, whose cost is minimum among all valid plans and all choices of enhanced pipe?</p>

<p>Note that it is possible that the plan becomes invalid while you are working, but by the end it should be a valid plan.</p>

### 입력 

 <p>The first line will contain the integers N, M, and D (1 ≤ N ≤ 100 000, N − 1 ≤ M ≤ 200 000, 0 ≤ D ≤ 10<sup>9</sup>). Each of the next M lines contain three integers A<sub>i</sub>, B<sub>i</sub>, and C<sub>i</sub>, which means that there is a pipe from building A<sub>i</sub> to building B<sub>i</sub> that costs C<sub>i</sub> per month when activated (1 ≤ A<sub>i</sub> , B<sub>i</sub> ≤ N, 1 ≤ C<sub>i</sub> ≤ 10<sup>9</sup>). The first N − 1 of these lines represent the valid plan the city is currently using.</p>

<p>It is guaranteed that there is at most one pipe connecting any two buildings and no pipe connects a building to itself.</p>

<p>For 3 of the 15 available marks, N ≤ 8, M ≤ 28 and D = 0.</p>

<p>For an additional 5 of the 15 available marks, N ≤ 1 000 and M ≤ 5 000 and D = 0.</p>

<p>For an additional 3 of the 15 available marks, D = 0.</p>

<p>For an additional 2 of the 15 available marks, N ≤ 1 000 and M ≤ 5 000.</p>

### 출력 

 <p>Output one integer on a single line, the minimum number of days to complete this task. If the initial valid plan is already an optimal plan, then output 0.</p>

