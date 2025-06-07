# [Platinum IV] Distribution in Metagonia - 11469 

[문제 링크](https://www.acmicpc.net/problem/11469) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

수학, 애드 혹, 정수론, 해 구성하기

### 제출 일자

2025년 6월 7일 23:07:54

### 문제 설명

<p>There are one hundred noble families in the country of Metagonia, and each year some of these families receive several ritual cubes from the Seer of the One. The One has several rules about cube distribution: if a family receives at least one cube, every prime divisor of the number of cubes received should be either 2 or 3, moreover if one family receives a > 0 cubes and another family in the same year receives b > 0 cubes then a should not be divisible by b and vice versa.</p>

<p>You are the Seer of the One. You know in advance how many cubes would be available for distribution for the next t years. You want to find any valid distribution of cubes for each of these years. Each year you have to distribute all cubes available for that year.</p>

### 입력 

 <p>The first line of input file contains a single integer t — the number of years to come (1 ≤ t ≤ 1000). Each of the following t lines contains a single integer n<sub>i</sub> — the number of cubes to distribute in i-th year (1 ≤ n<sub>i</sub> ≤ 10<sup>18</sup>).</p>

### 출력 

 <p>For each year i output two lines. The first line should contain m<sub>i</sub> — the number of families that would receive at least one cube in i-th year (1 ≤ m<sub>i</sub> ≤ 100). The second line should contain m<sub>i</sub> integers — the number of cubes received by each family. The sum of these numbers should be equal to n<sub>i</sub>.</p>

