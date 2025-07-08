# [Platinum II] Mutant Vaccine - 21839 

[문제 링크](https://www.acmicpc.net/problem/21839) 

### 성능 요약

메모리: 10536 KB, 시간: 1844 ms

### 분류

문자열, 이분 탐색, 접미사 배열과 LCP 배열

### 제출 일자

2025년 7월 8일 22:24:02

### 문제 설명

<p>Dr. Icey Peacie is working on a vaccine for Covid-19. One difficulty with vaccines is that viruses mutate, so there are many different strains circulating. Dr. Peacie wants the vaccine to target a part of the genetic sequence of the virus that all the strains have in common. Can you find the longest piece of RNA that occurs in all of the strains?</p>

### 입력 

 <p>The first line of input contains an integer N, the number of strains of the virus, with 1 ≤ N ≤ 100. The next N lines each contain the genetic sequence of a strain of the virus, a string of the letters <code>A</code>, <code>C</code>, <code>G</code>, and <code>T</code>. Each string has length between 1 and 10 000.</p>

### 출력 

 <p>Output a single line containing the longest string that occurs as a substring of all of the strains. If there is more than one such longest string, output the one that occurs earliest in the first strain.</p>

