# [Gold II] Flowery Trails - 10530 

[문제 링크](https://www.acmicpc.net/problem/10530) 

### 성능 요약

메모리: 11424 KB, 시간: 96 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2024년 9월 10일 22:20:01

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images2/flower.png" style="float:right; height:321px; width:278px">In order to attract more visitors, the manager of a national park had the idea of planting flowers along both sides of the popular trails, which are the trails used by common people. Common people only go from the park entrance to its highest peak, where views are breathtaking, by a shortest path. So, he wants to know how many metres of flowers are needed to materialize his idea.</p>

<p>For instance, in the park whose map is depicted in the figure, common people make only one of the three following paths (which are the shortest paths from the entrance to the highest peak).</p>

<ul>
	<li>At the entrance, some start in the rightmost trail to reach the point of interest 3 (after 100 metres), follow directly to point 7 (200 metres) and then pick the direct trail to the highest peak (620 metres).</li>
	<li>The others go to the left at the entrance and reach point 1 (after 580 metres). Then, they take one of the two trails that lead to point 4 (both have 90 metres). At point 4, they follow the direct trail to the highest peak (250 metres).</li>
</ul>

<p>Notice that popular trails (i.e., the trails followed by common people) are highlighted in yellow. Since the sum of their lengths is 1930 metres, the extent of flowers needed to cover both sides of the popular trails is 3860 metres (3860 = 2 × 1930).</p>

<p>Given a description of the park, with its points of interest and (two-way) trails, the goal is to find out the extent of flowers needed to cover both sides of the popular trails. It is guaranteed that, for the given inputs, there is some path from the park entrance to the highest peak.</p>

### 입력 

 <p>The first line of the input has two integers: P and T. P is the number of points of interest and T is the number of trails. Points are identified by integers, ranging from 0 to P − 1. The entrance point is 0 and the highest peak is point P − 1.</p>

<p>Each of the following T lines characterises a different trail. It contains three integers, p1, p2, and l, which indicate that the (two-way) trail links directly points p1 and p2 (not necessarily distinct) and has length l (in metres).</p>

<p>Integers in the same line are separated by a single space.</p>

### 출력 

 <p>The output has a single line with the extent of flowers (in metres) needed to cover both sides of the popular trails.</p>

