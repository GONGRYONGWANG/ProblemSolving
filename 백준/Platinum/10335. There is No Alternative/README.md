# [Platinum V] There is No Alternative - 10335 

[문제 링크](https://www.acmicpc.net/problem/10335) 

### 성능 요약

메모리: 2748 KB, 시간: 84 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2025년 6월 27일 01:46:44

### 문제 설명

<p>ICPC (Isles of Coral Park City) consist of several beautiful islands.</p>

<p>The citizens requested construction of bridges between islands to resolve inconveniences of using boats between islands, and they demand that all the islands should be reachable from any other islands via one or more bridges.</p>

<p>The city mayor selected a number of pairs of islands, and ordered a building company to estimate the costs to build bridges between the pairs. With this estimate, the mayor has to decide the set of bridges to build, minimizing the total construction cost.</p>

<p>However, it is difficult for him to select the most cost-efficient set of bridges among those connecting all the islands. For example, three sets of bridges connect all the islands for the Sample Input 1. The bridges in each set are expressed by bold edges in Figure F.1.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images2/no-alter.png" style="height:199px; width:755px"></p>

<p style="text-align: center;">Figure F.1. Three sets of bridges connecting all the islands for Sample Input 1</p>

<p>As the first step, he decided to build only those bridges which are contained in all the sets of bridges to connect all the islands and minimize the cost. We refer to such bridges as no alternative bridges. In Figure F.2, no alternative bridges are drawn as thick edges for the Sample Input 1, 2 and 3.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images2/no-alter-2.png" style="height:206px; width:740px"></p>

<p style="text-align: center;">Figure F.2. No alternative bridges for Sample Input 1, 2 and 3</p>

<p>Write a program that advises the mayor which bridges are no alternative bridges for the given input.</p>

### 입력 

 <p>The input consists of a single test case.</p>

<pre>N M
S<sub>1</sub> D<sub>1</sub> C<sub>1</sub>
.
.
.
S<sub>M</sub> D<sub>M</sub> C<sub>M</sub></pre>

<p>The first line contains two positive integers N and M. N represents the number of islands and each island is identified by an integer 1 through N. M represents the number of the pairs of islands between which a bridge may be built.</p>

<p>Each line of the next M lines contains three integers S<sub>i</sub> , D<sub>i</sub> and C<sub>i</sub> (1 ≤ i ≤ M) which represent that it will cost C<sub>i</sub> to build the bridge between islands S<sub>i</sub> and D<sub>i</sub>. You may assume 3 ≤ N ≤ 500, N − 1 ≤ M ≤ min(50000, N(N − 1)/2), 1 ≤ S<sub>i</sub> < D<sub>i</sub> ≤ N, and 1 ≤ C<sub>i</sub> ≤ 10000. No two bridges connect the same pair of two islands, that is, if i ≠ j and S<sub>i</sub> = S<sub>j</sub> , then D<sub>i</sub> ≠ D<sub>j</sub> . If all the candidate bridges are built, all the islands are reachable from any other islands via one or more bridges.</p>

### 출력 

 <p>Output two integers, which mean the number of no alternative bridges and the sum of their construction cost, separated by a space.</p>

