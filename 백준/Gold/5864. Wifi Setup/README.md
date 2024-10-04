# [Gold IV] Wifi Setup - 5864 

[문제 링크](https://www.acmicpc.net/problem/5864) 

### 성능 요약

메모리: 2176 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 10월 4일 15:35:48

### 문제 설명

<p>Farmer John's N cows (1 <= N <= 2000) are all standing at various positions along the straight path from the barn to the pasture, which we can think of as a one-dimensional number line.  Since his cows like to stay in email contact with each-other, FJ wants to install Wifi base stations at various positions so that all of the cows have wireless coverage.</p><p>After shopping around, FJ learns that the cost of a Wifi base station depends on distance it can transmit: a base station of power r costs A + B*r, where A is a fixed cost for installing the base station and B is a cost per unit of transmission distance.  If FJ installs such a device at position x, then it can transmit data to any cow located in the range x-r ... x+r.  A base station with transmission power of r=0 is allowed, but this only provides coverage to a cow located at the same position as the transmitter.</p><p>Given the values of A and B, as well as the locations of FJ's cows, please determine the least expensive way FJ can provide wireless coverage for all his cows.</p>

### 입력 

 <ul><li>Line 1: Three space-separated integers: N A B (0 <= A, B <= 1000).</li><li>Lines 2..1+N: Each line contains an integer in the range 0..1,000,000 describing the location of one of FJ's cows.</li></ul>

### 출력 

 <ul><li>Line 1: The minimum cost of providing wireless coverage to all cows.</li></ul>

