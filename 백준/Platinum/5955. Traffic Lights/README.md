# [Platinum V] Traffic Lights - 5955 

[문제 링크](https://www.acmicpc.net/problem/5955) 

### 성능 요약

메모리: 2808 KB, 시간: 8 ms

### 분류

너비 우선 탐색, 데이크스트라, 그래프 이론, 그래프 탐색, 구현, 시뮬레이션, 최단 경로

### 제출 일자

2024년 7월 31일 03:27:02

### 문제 설명

<p>Kenosha, the city nearest Farmer John, has M (1 <= M <= 14,000) roads conveniently numbered 1..M that connect N (2 <= N <= 300) junctions which are conveniently numbered 1..N. No two roads connect the same pair of junctions. No road connects a junction to itself. The integer travel time T_ij (1 <= T_ij <= 100) between junctions i and j is the same for both directions (i.e., T_ij = T_ji).</p>

<p>Each junction has a single traffic light with two colors: blue or purple. The color of each light alternates periodically: blue for certain duration and then purple for another duration.  Traffic is permitted to commence travel down the road between any two junctions, if and only if the lights at both junctions are the same color at the moment of departing from one junction for the other. The lights do not necessarily have to be the same on the whole trip down the road.</p>

<p>If a vehicle arrives at a junction just at the moment the lights switch it must consider the new colors of lights. Vehicles are allowed to wait at the junctions. You are given the city map which shows:</p>

<ul>
	<li>The travel times T_ij for all roads</li>
	<li>The durations of the two colors at junction i. (DB_i (1 <= DB_i <= 100) for the blue light and DP_i (1 <= DP_i <= 100) for the purple light)</li>
	<li>The initial color C_i of the light at junction i (a letter 'B' or 'P' with the obvious meaning) and the remaining time R_i (1 <= R_i <= 100) for this color to change</li>
</ul>

<p>Find the minimum time one needs to get from a given source S (1 <= S <= N) to a given destination D (1 <= D <= N; D != S).</p>

<pre>Consider the map below with four junctions and five roads. FJ wants to travel from junction 1 to junction 4. The first light is blue; the rest are purple.
                                    Init  Remg  Blue   Purple
       4       76         Junction  Color Time  Cycle  Cycle
>>[1B]===[2P]======          1        B    2     16      99
    |   /          \         2        P    6     32      13
  40|  /75          \        3        P    2     87       4
    | /              \       4        P   38     96      49
  [3P]===============[4P]>>
           77</pre>

<p>The minimum time is 127 utilizing the path 1-2-4.</p>

<p>Initially, the light at junction 1 is blue. Since the light at junction 2 is purple, vehicle waits at junction 1 for 2 seconds then travels 4 seconds to junction 2.</p>

<p>At time 6, the light at junction 2 switches to blue whereas the light at junction 4 has 32 more seconds to switch to blue. However, after 32 seconds, the light at junction 2 switches to purple and the light at junction 4 switches to blue at the same time. So the vehicle needs to wait 13 seconds more for junction 2 to switch to blue then the lights have the same color and vehicle travels 76 seconds to the destination junction 4.</p>

<p>The total time is 2+4+32+13+76=127 seconds.</p>

<p>Below is a more graphical presentation of this travel plan:</p>

<pre>                                                                                                       1    1    1    1    1    1
             1    1    2    2    3    3    4    4    5    5    6    6    7    7    8    8    9    9    0    0    1    1    2    2
   0....5....0....5....0....5....0....5....0....5....0....5....0....5....0....5....0....5....0....5....0....5....0....5....0....5..
   --------------------------------------------------------------------------------------------------------------------------------
J1 BBBPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPBBBBBBBBBBBBBBBBPPPPPPPPPP
J2 PPPPPPBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPPPPPPPPPPPPPBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPPPPPPPPPPPPPBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
J3 PPPBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPPPPBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
J4 PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
FJ 1..>>>2............................................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>4</pre>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: S and D</li>
	<li>Line 2: Two space-separated integers: N and M</li>
	<li>Lines 3..N+2: Line i+2 line describes junction i with a character and three integers (all separated by a single space): C_i, R_i, DB_i, and DP_i</li>
	<li>Lines N+3..N+M+2: Line N+2+k describes road k with three integers: i, j, and T_ij</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: One integer: the time taken by a minimum-time path from the source junction to the destination junction. If there is no path, output 0.</li>
</ul>

<p> </p>

