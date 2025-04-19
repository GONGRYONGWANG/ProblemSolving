# [Unrated] Carpool - 4234 

[문제 링크](https://www.acmicpc.net/problem/4234) 

### 성능 요약

메모리: 2420 KB, 시간: 48 ms

### 분류

분류 없음

### 제출 일자

2025년 4월 19일 16:00:53

### 문제 설명

<p>A group of friends has just completed their CS assignments, and because of the nice weather, they decide to go to Joe's house for a BBQ. Unfortunately, after all that coding, they are too tired to walk. Fortunately, between them they have enough cars to take everyone.</p>

<p>Joe remembers that he needs to stop off at the supermarket along the way to buy some burgers and pop.</p>

<p>Jenn proposes that they stop at her house to get a frisbee.</p>

<p>Jim decides that he doesn't like burgers, and wants to grab a pizza along the way.</p>

<p>After having spent so long in the computer lab, Jerry's eyes have become very sensitive to sunlight, so he needs to stop at his house for his sunglasses.</p>

<p>And so it goes: each person needs to run a little errand along the way. At this rate, the friends worry that it will be dark by the time they get to Joe's house. They launch into a heated discussion to about who should go in which car to minimize the time needed for everyone to reach Joe's house. The discussion itself, of course, wastes precious time that could be better spent at the BBQ.</p>

<p>To help the group, you will write a program to settle the discussion by computing an optimal assignment of people to cars. The overall travel time is the maximum of the travel times of each car. An optimal assignment is one that minimizes the overall travel time.</p>

<p>Your program will be provided with a representation of the roads in the city, in the form of distances between major landmarks. Assume that every car always travels at 60 kilometres per hour (one kilometre per minute). Each stop (at a supermarket, someone's house, etc.) takes five minutes.</p>

<p>Although the friends have many cars between them, to be nice to the environment, they decide to take no more cars than necessary. Each car can take at most five people.</p>

### 입력 

 <p>The first line of input contains two integers n and m, 1 ≤ n ≤ 15, 1 ≤ m ≤ 1000, the number of people in the group and the number of roads in the city. The places that must be visited along the way are numbered 1 through n. The campus is numbered 0, and Joe's house is numbered n+1. An additional m lines follow, each containing three integers describing a stretch of road. The first two integers are in the range 0 to n+1 inclusive, and describe the two places connected by the stretch of road. The third integer specifies the length of the stretch of road, in kilometres. A road may be taken in both directions. There is a sequence of roads connecting every place in the city to every other place.</p>

### 출력 

 <p>Output a single integer, giving the number of minutes required for everyone to reach Joe's house using an optimal assignment of people to cars.</p>

