# [Platinum II] Delivering Goods - 14764 

[문제 링크](https://www.acmicpc.net/problem/14764) 

### 성능 요약

메모리: 7572 KB, 시간: 44 ms

### 분류

이분 매칭, 데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 4월 15일 22:49:58

### 문제 설명

<p>You run a delivery company and must deploy a fleet of vehicles to deliver goods to clients. All of the goods and delivery trucks are initially located at your warehouse.</p>

<p>The road network consists of one-way streets between junctions. The warehouse and clients are all located at a junction. You know the driving time across each street.</p>

<p>You guarantee extremely fast shipping: the trucks start driving immediately at the start of the day and each client i will receive the package at time T<sub>i</sub> where T<sub>i</sub> is the shortest possible driving time for a truck to go from the warehouse to the location of the client i.</p>

<p>What is the minimum number of trucks you have to deploy to ensure this guarantee is met? That is, what is the minimum number of trucks such that it is possible to give each truck a driving route so that every client i is visited by some truck at time T<sub>i</sub>. Assume it takes no time to load the trucks with the appropriate goods at the start of the day, and it takes no time to drop goods off at a client once the truck arrives at the client. These goods are small enough that each truck can carry goods for as many clients as necessary</p>

### 입력 

 <p>The input consists of a single test case. The first line of each test case consists of three numbers N, M, and C. Here N denotes the number of junctions in the road network (2 ≤ N ≤ 10<sup>3</sup>), M denotes the number of streets (1 ≤ M ≤ 10<sup>5</sup>), and C denotes the number of clients (1 ≤ C ≤ 300, C < N).</p>

<p>The junctions are numbered 0 to N − 1. The warehouse is always at junction 0. The second line consists of C distinct integers between 1 and N − 1 indicating the junctions where the clients reside.</p>

<p>The rest of the input consists of M lines, each containing integers U, V, W where 0 ≤ U, V ≤ N − 1 and U ≠ V . This indicates there is a one-way street from U to V with driving time W. Each street’s driving time W satisfies 1 ≤ W ≤ 10<sup>9</sup>. It will always be possible to reach every client from the warehouse.</p>

<p>There will be at most one street from a vertex U to another vertex V , but there may be streets from both U to V and from V to U.</p>

### 출력 

 <p>Output a single integer that is the minimum number of vehicles required to ensure each client i is visited at time Ti by some vehicle.</p>

