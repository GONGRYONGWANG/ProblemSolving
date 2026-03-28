# [Platinum IV] No Luck - 23400 

[문제 링크](https://www.acmicpc.net/problem/23400) 

### 성능 요약

메모리: 16084 KB, 시간: 244 ms

### 분류

자료 구조, 정렬, 세그먼트 트리, 오프라인 쿼리, 머지 소트 트리

### 제출 일자

2026년 3월 28일 22:26:11

### 문제 설명

<p>Vini is a very dedicated car painter. Ever since he learned how to paint cars, his dream was to participate in the International Competition for Painting Cars (ICPC for short).</p>

<p>Every year Vini’s region has a local competition to rank all teams of competitive car painters from this region. Painters in teams that were ranked in the top x spots will then go on to compete in the ICPC. It is a very thrilling competition with lots of new competitors every year, until the noxious fumes from the car paint eventually leads them to permanently retire.</p>

<p>Because of the variance in the national car painting budget and ICPC constraints, this number x may vary between years, which may cause a lot of displeasure in some competitors.</p>

<p>On Vini’s last year as a contestant, his team was a single position away from qualifying to the ICPC. How unlucky! To make his “bad luck” feeling worse, in the following year the team who got the same position did qualify! Despite this feeling, after talking to other former contestants, he noticed that many have had the same feeling of being unlucky in one way or another.</p>

<p>Former contestants usually follow the results of the regional competition for a few years after retiring. Hence, a contestant would not feel unlucky for changes in x that occur many years after they retire. More precisely, each former contestant had their last participation in the year a<sub>i</sub>, being placed in the position p<sub>i</sub> and, after retiring, followed results for the next f<sub>i</sub> years.</p>

<p>A contestant that didn’t qualify to the ICPC in their last participation has felt unlucky on every year that they followed the results in which they would qualify to the ICPC if they had competed in that year. In other words, for every year up to f<sub>i</sub> years after the contestant retired, if they didn’t qualify in their last participation, they felt unlucky if the number of teams that qualify for the ICPC in this year was at least p<sub>i</sub>.</p>

<p>Given the number of slots per year and the information about the former contestants, we want to know how many years each former contestant felt unlucky.</p>

### 입력 

 <p>The first line contains two integers Y and N (1 ≤ Y, N ≤ 3 × 10<sup>5</sup>), representing the number of years of competition and the number of former contestants that Vini had talked to, respectively. (Yes, painting cars is a millenary tradition, also a very popular one!).</p>

<p>The next line contains Y integers x<sub>1</sub>, x<sub>2</sub>, . . . , x<sub>Y</sub> (0 ≤ x<sub>i</sub> ≤ 10<sup>5</sup>), representing the how many slots to the ICPC for their region there were for each year.</p>

<p>Each of the next N lines contains three integers a<sub>i</sub>, p<sub>i</sub> and f<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ Y, 1 ≤ p<sub>i</sub> ≤ 10<sup>5</sup>, 0 ≤ f<sub>i</sub> ≤ Y − a<sub>i</sub>), representing the year that the i-th former competitor had their last participation, the position the i-th former competitor’s team ranked and for how many years after competing the i-th former competitor followed the results after retiring, respectively.</p>

### 출력 

 <p>Output N lines, the i-th line should contain how many years the i-th former competitor felt unlucky.</p>

