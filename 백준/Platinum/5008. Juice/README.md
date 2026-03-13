# [Platinum IV] Juice - 5008 

[문제 링크](https://www.acmicpc.net/problem/5008) 

### 성능 요약

메모리: 2440 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 정렬, 트리, 트리에서의 다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2026년 3월 14일 03:52:14

### 문제 설명

<p>In the Favela of Rio de Janeiro there was a ﬂicker of light. After months of careful building, they ﬁnally connected the generator to the thousands of extension cords and the slum was illuminated by millions of bright lights...</p>

<p>However, the capacity of the extension cords was not enough to meet the energy demands of all the houses in the slum. Thus, the engineers had to carefully select which houses should be powered, and which should not, prior to connecting the power generator. Their idea was to power as many houses as possible, based on the energy demands of each house, and the capacity of the extension cords.</p>

<p>More speciﬁcally, the generator and each of the houses are represented by nodes, and extension cords are represented by edges between these. Thus, each node gets power from exactly one other node. In addition, each node except the generator node has a non-negative power demand. The generator produces an amount of energy that far surpasses the total capacity of the extension cords connected to it, and can thus be treated as an inﬁnite energy source.</p>

<p>Given the same data, ﬁnd out how many houses the engineers were able to cover the energy demands of.</p>

### 입력 

 <p>The ﬁrst line of the input contains a single integer 0 ≤ n ≤ 1000, the number of houses in the slum.</p>

<p>Then follow n lines in the format p<sub>i</sub> r<sub>i</sub> c<sub>i</sub>, where 0 ≤ p<sub>i</sub> ≤ n is the parent node of house i, 0 ≤ r<sub>i</sub> ≤ 100 is the energy demand of house i and 1 ≤ c<sub>i</sub> ≤ 100 is the capacity of the extension cord connecting house i to house p<sub>i</sub>.</p>

<p>The power generator has index 0.</p>

### 출력 

 <p>Output the maximum number of power requirements that can be met.</p>

