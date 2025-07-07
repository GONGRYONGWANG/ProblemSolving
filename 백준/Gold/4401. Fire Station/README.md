# [Gold II] Fire Station - 4401 

[문제 링크](https://www.acmicpc.net/problem/4401) 

### 성능 요약

메모리: 3984 KB, 시간: 104 ms

### 분류

데이크스트라, 플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2025년 7월 8일 03:25:29

### 문제 설명

<p>A city is served by a number of fire stations. Some residents have complained that the distance from their houses to the nearest station is too far, so a new station is to be built. You are to choose the location of the fire station so as to reduce the distance to the nearest station from the houses of the disgruntled residents.</p>

<p>The city has up to 500 intersections, connected by road segments of various lengths. No more than 20 road segments intersect at a given intersection. The location of houses and firestations alike are considered to be at intersections (the travel distance from the intersection to the actual building can be discounted). Furthermore, we assume that there is at least one house associated with every intersection. There may be more than one firestation per intersection.</p>

### 입력 

 <p>The first line of input contains two positive integers: f,the number of existing fire stations (f <= 100) and i, the number of intersections (i <= 500). The intersections are numbered from 1 to i consecutively. f lines follow; each contains the intersection number at which an existing fire station is found. A number of lines follow, each containing three positive integers: the number of an intersection, the number of a different intersection, and the length of the road segment connecting the intersections. All road segments are two-way (at least as far as fire engines are concerned), and there will exist a route between any pair of intersections.</p>

### 출력 

 <p>You are to output a single integer: the lowest intersection number at which a new fire station should be built so as to minimize the maximum distance from any intersection to the nearest fire station.</p>

