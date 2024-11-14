# [Gold I] Map - 8302 

[문제 링크](https://www.acmicpc.net/problem/8302) 

### 성능 요약

메모리: 10084 KB, 시간: 300 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2024년 11월 14일 21:55:02

### 문제 설명

<p>Jane has found an old map of her town in her basement. The map is a square-shaped piece of paper divided into unit squares on which several mysterious points are marked. Jane does not know the meaning of these points and that is why she decided to visit each one of them. She decided to meet with 3 of her colleagues - Jack, Adam and Robert - in one of the mysterious points: this will be the starting point. Afterwards each of the persons will be assigned an area in which he/she will find all the mysterious points and check the secrets hidden in them. Jane decided to settle four areas: the first one that consists of all the points with both coefficients less than the coefficients of the starting point, the second one in which both coefficients are greater, the third one in which the first coefficient is greater and the second one is less, and the fourth one in which the first coefficient is less and the second one is greater. In the end all the colleagues will visit together the marked points for which the first or second coefficient equals the corresponding coefficient of the starting point.</p>

<p>Now Jane only needs to choose the starting point. It should be chosen in such a way that each person will visit <i>independently</i> at least one of the mysterious points. Can you find the number of such starting points?</p>

### 입력 

 <p>The first line of the standard input contains two integers <em>n</em> and <em>d</em> (1 ≤ <em>n</em> ≤ 1 000 000, 3 ≤ <em>d</em> ≤ 10<sup>9</sup>), denoting the number of points that are marked on the map and the size of the map. The following <em>n</em> lines contain descriptions of the points, each of which has the form of a pair of integers <em>x<sub>i</sub></em>, <em>y<sub>i</sub></em> (0 ≤ <em>x<sub>i</sub></em>, <em>y<sub>i</sub></em> ≤ <em>d</em>), representing the coefficients of the <em>i</em>-th point. All points in the input are distinct.</p>

### 출력 

 <p>The first and only line of the standard output should contain a single integer representing the number of points that can become the starting point.</p>

