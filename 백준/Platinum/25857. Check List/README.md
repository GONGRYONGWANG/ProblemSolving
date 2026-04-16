# [Platinum II] Check List - 25857 

[문제 링크](https://www.acmicpc.net/problem/25857) 

### 성능 요약

메모리: 27112 KB, 시간: 244 ms

### 분류

값 / 좌표 압축, 자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<p><img alt="" src="" style="width: 84px; height: 85px; float: right;">When test driving a vehicle, you are asked to make a checkmark on a tablet. Upon inspection, you have noticed many fingerprints on the screen. Aside from the rush of disgust, you notice that the fingerprints on the screen can be represented by a series of 2D points on a standard Cartesian grid. You know that checkmarks can be uniquely defined by three points; these three points have distinct x coordinates and the three points also have distinct y coordinates. The leftmost point must be lower than the rightmost point and higher than the middle point. Now you want to know how many unique checkmarks you can make using the 2D points.</p>

<p>Let’s consider some examples. The three points (1,2), (2,1), and (3,2) do not form a valid checkmark because the leftmost and rightmost points are at the same height. The three points (1,2), (2,1), and (2,3) do not form a valid checkmark because two points have the same x coordinates. The three points (1,2), (3,1), and (4,9) do form a valid checkmark.</p>

<p>Given a list of 2D points, determine the number of unique checkmarks that can be formed from them.</p>

### 입력 

 <p>The first input line contains a single integer, n (1 ≤ n ≤ 100,000), representing the number of points. Each of the following n input lines contains two integers, x<sub>i</sub> and y<sub>i</sub> (1 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 1,000,000,000), representing the location of a point on the 2D grid. No two points will be identical.</p>

### 출력 

 <p>Print the number of distinct checkmarks that can be formed by the given 2D points.</p>

