# [Platinum V] 공책 구매 - 5375 

[문제 링크](https://www.acmicpc.net/problem/5375) 

### 성능 요약

메모리: 2164 KB, 시간: 28 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 정렬

### 제출 일자

2025년 4월 9일 00:12:13

### 문제 설명

<p>민혁이는 공책을 N개 사려고 한다. 민혁이는 온라인 쇼핑몰 M개에서 파는 공책의 가격을 모두 조사해놓았다.</p>

<p>i번째 쇼핑몰에서 파는 공책의 가격은 하나당 p<sub>i</sub>원이고, 총 s<sub>i</sub>개가 준비되어 있다. 또, 배송비는 o<sub>i</sub>원이다. 민혁이는 s<sub>i</sub>개를 넘게 주문할 수 없으며, 몇 개를 주문하더라도 배송비는 1번만 내면 된다.</p>

<p>공책 N개를 사는 비용의 최솟값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T (T ≤ 100)가 주어지며, 아래와 같은 형식으로 이루어져 있다.</p>

<ul>
	<li>첫째 줄에 사려고 하는 공책의 개수 N과 쇼핑몰의 개수 M이 주어진다. (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 100, N ≤ Σs<sub>i</sub>)</li>
	<li>M개의 줄에 s<sub>i</sub>, p<sub>i</sub>, o<sub>i</sub>가 주어진다. (0 ≤ s<sub>i</sub>, p<sub>i</sub> ≤ 10,000, 0 ≤ o<sub>i</sub> ≤ 1,000,000)</li>
</ul>

### 출력 

 <p>각각의 테스트 케이스마다 민혁이가 공책 N개를 구매하기 위한 비용의 최솟값을 출력한다.</p>

