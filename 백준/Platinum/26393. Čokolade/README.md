# [Platinum V] Čokolade - 26393 

[문제 링크](https://www.acmicpc.net/problem/26393) 

### 성능 요약

메모리: 3592 KB, 시간: 364 ms

### 분류

이분 탐색, 누적 합, 삼분 탐색

### 제출 일자

2024년 4월 20일 19:26:55

### 문제 설명

<p>Little Lana and little Fran are visiting a chocolate factory. They have seen how chocolate is made, tasted many chocolates, and now they want to buy some of the chocolates.</p>

<p>In the shop, there are n different chocolates, and the i-th of them has the price c<sub>i</sub>. Lana and Fran want to buy m chocolates.</p>

<p>Fran found a way to split the cost in the shop:</p>

<ul>
	<li>If the chocolate is cheaper than k kunas, Lana will pay for it.</li>
	<li>Otherwise, Lana will pay k kunas, and Fran will pay the rest, that is c<sub>i</sub> − k kunas.</li>
</ul>

<p>Let’s denote l as the amount Lana has to pay, and f as the amount Fran has to pay. Lana, dissatisfied with Fran’s deal, wants to spite Fran and choose the chocolates so the value of the expression l − f is as small as possible. Since Fran is hesitant and doesn’t know how many he wants to buy, Lana wants to know the minimal value of the expression l − f for q different numbers k<sub>i</sub> and m<sub>i</sub>.</p>

<p>Help her choose the chocolates and determine the minimum value of the expression l − f for each of the q queries.</p>

### 입력 

 <p>The first line contains two integers n and q (1 ≤ n, q ≤ 10<sup>5</sup>), the number of chocolates, and the number of queries.</p>

<p>The second line contains n integers c<sub>1</sub>, c<sub>2</sub>, . . . , c<sub>q</sub> (1 ≤ c<sub>i</sub> ≤ 10<sup>9</sup>), the prices of the individual chocolates, in order.</p>

<p>The following q lines contain integers k<sub>i</sub> and m<sub>i</sub> (1 ≤ k<sub>i</sub> ≤ 10<sup>9</sup>, 1 ≤ m<sub>i</sub> ≤ n), Fran’s bound, and the number of chocolates they are going to buy.</p>

### 출력 

 <p>Print q lines. In the i-th line print the answer to Lana’s i-th query.</p>

