# [Platinum II] Bad Doctor - 18502 

[문제 링크](https://www.acmicpc.net/problem/18502) 

### 성능 요약

메모리: 91300 KB, 시간: 968 ms

### 분류

자료 구조, 세그먼트 트리, 누적 합, 스위핑

### 제출 일자

2026년 1월 14일 22:37:55

### 문제 설명

<p>Alex got sick. He went to a clinic and visited n doctors. The i-th doctor said that starting with the day l<sub>i</sub> and ending with the day r<sub>i</sub> Alex must take k<sub>i</sub> medicines: a<sub>1</sub>, a<sub>2</sub>, . . ., a<sub>k<sub>i</sub></sub>, one pill a day of each. Medicines are numbered from 1 to m.</p>

<p>Of course, if several doctors tell Alex to take the same medicine at the same day, he will take only one pill of this medicine that day. At least, this is how people act in real life.</p>

<p>One pill of the medicine j costs c<sub>j</sub> roubles. But Alex has a doubt: the rumors say that one of the doctors in the clinic is really bad. He doesn’t know which doctor is bad, but he decided to ignore this doctor’s prescription.</p>

<p>Your task is to find n numbers t<sub>i</sub>: know how much money Alex will spend on the pills if the i-th doctor is bad.</p>

### 입력 

 <p>The first line contains two integers n and m: the number of doctors and the number of medicines (1 ≤ n ≤ 500 000, 1 ≤ m ≤ 500 000).</p>

<p>The second line contains m integers c<sub>j</sub>: the cost of one pill of the j-th medicine (1 ≤ c<sub>j</sub> ≤ 1 000 000).</p>

<p>Each of the next n lines describes doctors. The i-th of them starts with three integers l<sub>i</sub>, r<sub>i</sub>, k<sub>i</sub>: the start and end days in the i-th doctor’s prescription and the number of medicines he told Alex to take (1 ≤ l<sub>i</sub> ≤ r<sub>i</sub> ≤ 1 000 000, 1 ≤ k<sub>i</sub> ≤ m). Then follow k<sub>i</sub> distinct integers a<sub>1</sub>, a<sub>2</sub>, . . ., a<sub>k<sub>i</sub></sub>, each from 1 to m: the medicines in the prescription.</p>

<p>The sum of all k<sub>i</sub> in the input doesn’t exceed 1 000 000.</p>

### 출력 

 <p>Output n integers t<sub>1</sub>, t<sub>2</sub>, . . ., t<sub>n</sub>: how much money Alex will spend on the pills if he ignores the i-th doctor’s prescription.</p>

