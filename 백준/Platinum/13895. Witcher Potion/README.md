# [Platinum V] Witcher Potion - 13895 

[문제 링크](https://www.acmicpc.net/problem/13895) 

### 성능 요약

메모리: 2276 KB, 시간: 4 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2025년 1월 20일 16:48:43

### 문제 설명

<p>In a mythical world, there is a fighting contest where each contestant fights a monster one by one and needs to defeat monsters as many as possible until the contestant is knocked out. Among fighter tribes, a Witcher tribe has an edge over others since they can take advantage from energy-boosting, but poisonous, potions. These potions instantly increase his or her energy and as long as a Witcher does not run out of energy, he will not be knocked out. Unfortunately, these potions contain toxicity and he can drink at most one potion bottle once he defeats each monster.</p>

<p>Geralt, a legendary Witcher, enters this tournament with N potion bottles. Each bottle has its own strength and toxicity level. If he drinks a potion with strength E, his energy increases by E units, but it will not exceed 100. Potion with toxicity level P increases toxicity level in his blood by P units. If the toxicity level in blood reaches 100, Geralt will be knocked out. Therefore, he will never let that happens.</p>

<p>However, his body can quickly release blood toxicity. In T minutes, his blood toxicity level reduces by T units too. This allows Geralt to safely drink another potion bottle when he defeats a monster.</p>

<p>Since Geralt knows exactly how much energy and time he needs to spend to defeat a monster, he knows that he can plan how to drink potions that will let him defeat many monsters and become the winner of this contest. Nevertheless, calculation seems not to be his strength.</p>

<p>Your task is to analyze potion and monster data. Then, tell Geralt the maximum number of monsters he can defeat before he will be knocked out. Assume that all monsters are the same (need the same amount of energy and time to be defeated). Furthermore, if the needed energy is K units and Geralt has K or less energy units, Geralt will not be able to defeat a monster.</p>

### 입력 

 <p>The first line contains a positive integer C ≤ 20, representing the number of test cases. For each test case, the input is as follows:</p>

<p>Line 1 : contains positive integers K and M where K and M are the amount of energy and time that Geralt needs to spend for each monster. Also, 10 ≤ K ≤ 80 and M ≤ 100.<br>
Line 2 : contains N, the number of potions Geralt has where 1 ≤ N ≤ 8.<br>
Line 3 : contains positive integers E<sub>1</sub>, E<sub>2</sub>, E<sub>3</sub>, …, E<sub>N</sub>, the potion strength of bottles 1 to N.<br>
Line 4 : contains positive integers P<sub>1</sub>, P<sub>2</sub>, P<sub>3</sub>, …, P<sub>N</sub>, the potion toxicity level of bottles 1 to N. (1 ≤ E<sub>i</sub>, P<sub>i</sub> ≤ 100)</p>

### 출력 

 <p>For each test case, your program will print the maximum number of monsters that Geralt can defeat, one line for one case.</p>

