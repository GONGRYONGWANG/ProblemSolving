# [Platinum V] Landline Telephone Network - 10414 

[문제 링크](https://www.acmicpc.net/problem/10414) 

### 성능 요약

메모리: 4636 KB, 시간: 20 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2025년 7월 8일 03:03:46

### 문제 설명

<p>The mayor of RMRCity wants to create a secure landline telephone network for emergency use in case of serious disasters when the city is cut off from the outside world. Some pairs of buildings in the city can be directly connected with a wire telephone line and the municipality engineers have prepared an estimate of the cost of connecting any such pair.</p>

<p>The mayor needs your help to find the cheapest network that connects all buildings in the city and satisfies a particular security measure that will be explained shortly. A call from a building A to another building B may be routed through any simple path in the network (i.e., a path that does not have any repeated building). There are also some insecure buildings that one or more persons with serious criminal records live in. The mayor wants only communications intended for these insecure buildings to reach them. In other words, no communication from any building A to any building B should pass through any insecure building C in the network (where C is different from A and B).</p>

### 입력 

 <p>The input consists of a single test case. The first line contains three integers n, m, p where 1 ≤ n ≤ 1 000 is the number of buildings, 0 ≤ m ≤ 100 000 is the number of possible direct connections between a pair of buildings, and 0 ≤ p ≤ n is the number of insecure buildings. The buildings are numbered from 1 to n. The second line contains p distinct integers between 1 and n (inclusive), which are the numbers of insecure buildings. Each of the next m lines contains three integers x<sub>i</sub>, y<sub>i</sub>, and ℓ<sub>i</sub> describing one potential direct line, where x<sub>i</sub> and y<sub>i</sub> (1 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ n) are the distinct buildings the line connects, and ℓ<sub>i</sub> (1 ≤ ℓ<sub>i</sub> ≤ 10 000) is the estimate of the cost of connecting these buildings. There is at most one direct link between any two buildings in these m lines.</p>

### 출력 

 <p>Display the cost of the cheapest network satisfying the security measure if it is possible. Otherwise, display impossible.</p>

