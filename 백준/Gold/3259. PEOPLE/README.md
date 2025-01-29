# [Gold V] PEOPLE - 3259 

[문제 링크](https://www.acmicpc.net/problem/3259) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

비트마스킹, 브루트포스 알고리즘, 구현

### 제출 일자

2025년 1월 29일 22:47:53

### 문제 설명

<p>A group of N people is given. These people can be classified into two subgroups: those who always tell the truth and those who lie.</p>

<p>We interviewed all of them. Each person named several members of the group and said whether they belong to the first subgroup or to the second.</p>

<p>Your task is to write a program that will use these statements to determine who tells a lie and who doesn’t. </p>

### 입력 

 <p>First line of the input file consists of an integer N, 2 ≤ N ≤ 20, a number of people in the group.</p>

<p>Next 2N lines contain statements of each person in the following form (j-th person’s statement is placed in lines 2j and 2j+1):</p>

<pre>K A<sub>1</sub> A<sub>2</sub> ... A<sub>K</sub>
L B<sub>1</sub> B<sub>2</sub> ... B<sub>L</sub></pre>

<p>This means that j-th person said that A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>K</sub> tell the truth and that B<sub>1</sub>, B<sub>2</sub>, ..., B<sub>L</sub> lie.</p>

<p>People are numbered 1 to N. Each person made a statement about at least one other, did not make any statements about herself and did not say that someone tells the truth and lies at the same time.</p>

<p>If a person tells the truth then each of her statements must be true and if she lies then at least one of her statements must be false. </p>

### 출력 

 <p>The output file should have N lines, j-th line telling whether j-th person tells the truth or lies. If a person tells the truth, word 'true' should be printed and word 'false' otherwise.</p>

<p>Test data will be such that the solution will always exist, although it may not be necessarily unique.</p>

