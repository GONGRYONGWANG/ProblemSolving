# [Platinum II] Airports - 11593 

[문제 링크](https://www.acmicpc.net/problem/11593) 

### 성능 요약

메모리: 6752 KB, 시간: 116 ms

### 분류

이분 매칭, 플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2025년 10월 28일 22:35:55

### 문제 설명

<p>An airline company offers flights out of n airports, conveniently labeled from 1 to n. The flight time t<sub>ij</sub> from airport i to airport j is known for every i and j. It may be the case that t<sub>ij</sub> ≠ t<sub>ji</sub>, due to things like wind or geography. Upon landing at a given airport, a plane must be inspected before it can be flown again. This inspection time p<sub>i</sub> is dependent only on the airport at which the inspection is taking place and not where the previous flight may have originated.</p>

<p>Given a set of m flights that the airline company must provide, determine the minimum number of planes that the company needs to purchase. The airline may add unscheduled flights to move the airplanes around if that would reduce the total number of planes needed.</p>

### 입력 

 <p>The first line of input contains two space-separated integers n and m (1 ≤ n, m ≤ 500). The next line contains n space-separated integers p<sub>1</sub>, . . . , p<sub>n</sub> (0 ≤ p<sub>i</sub> ≤ 10<sup>6</sup>).</p>

<p>Each of the next n lines contains n space-separated integers. The jth integer in line i + 2 is t<sub>ij</sub> (0 ≤ t<sub>ij</sub> ≤ 10<sup>6</sup>). It is guaranteed that t<sub>ii</sub> = 0 for all i. However, it may be the case that t<sub>ij</sub> ≠ t<sub>ji</sub> when i ≠ j.</p>

<p>Each of the next m lines contains three space-separated integers, s<sub>i</sub>, f<sub>i</sub>, and t<sub>i</sub> (1 ≤ s<sub>i</sub>, f<sub>i</sub> ≤ n, s<sub>i</sub> ≠ f<sub>i</sub>, 1 ≤ t<sub>i</sub> ≤ 10<sup>6</sup>), indicating that the airline company must provide a flight that flies out from airport s<sub>i</sub> at exactly time t<sub>i</sub> , heading directly to airport f<sub>i</sub>.</p>

### 출력 

 <p>Print, on a single line, a single integer indicating the minimum number of planes the airline company must purchase in order to provide the m requested flights.</p>

