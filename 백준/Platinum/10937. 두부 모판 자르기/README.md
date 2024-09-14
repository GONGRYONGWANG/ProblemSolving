# [Platinum III] 두부 모판 자르기 - 10937 

[문제 링크](https://www.acmicpc.net/problem/10937) 

### 성능 요약

메모리: 2164 KB, 시간: 12 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2024년 9월 14일 13:31:45

### 문제 설명

<p>KOI 두부 공장에서 만들어내는 크기가 N × N (N ≤ 11)인 두부모판이 있다. 이 모판을 1×1 크기의 단위두부가 2개 붙어있는 형태의 포장단위(즉, 1×2 혹은 2×1 크기)로 잘라서 판매한다. 그런데 두부제조 공정상 모판에 있는 각 단위두부의 품질은 A, B, C, F급으로 분류되고, 잘려진 포장단위의 두부 가격은 이 포장단위에 있는 두 개의 단위두부의 품질에 따라서 그림 1과 같이 정해진다</p>

<table class="table table-bordered table-center-30 td-center th-center">
	<thead>
		<tr>
			<th style="width: 6%;">등급</th>
			<th style="width: 6%;">A</th>
			<th style="width: 6%;">B</th>
			<th style="width: 6%;">C</th>
			<th style="width: 6%;">F</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>A</th>
			<td>100</td>
			<td>70</td>
			<td>40</td>
			<td>0</td>
		</tr>
		<tr>
			<th>B</th>
			<td>70</td>
			<td>50</td>
			<td>30</td>
			<td>0</td>
		</tr>
		<tr>
			<th>C</th>
			<td>40</td>
			<td>30</td>
			<td>20</td>
			<td>0</td>
		</tr>
		<tr>
			<th>F</th>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">그림 1. 포장단위의 가격표</p>

<p>포장단위에 있는 두 단위두부가 [A,A]급이면 100원을 받고, [A,B]급이면 70원을, [A,C]급이면 40원을, [B,B]급이면 50원을, [B,C]급이면 30원을, [C,C]급이면 20원을 받는다. 포장단위에 있는 두 개의 단위두부 중 하나라도 F급이 있으면 이 포장단위는 한푼도 받을 수 없다. </p>

<p>N×N 두부 모판의 품질이 주어질 때, 가장 높은 가격을 받도록 두부 모판을 1×2 혹은 2×1 크기의 포장단위들로 자르고자 한다. 예를 들어 그림 2와 같은 3×3 두부 모판이 주어져 있다고 하자.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10937/1.png" style="height:91px; width:96px"></p>

<p style="text-align: center;">그림 2. 두부 모판의 예</p>

<p>이 경우, 그림 3과 같이 자르면 4개의 포장단위가 만들어진다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10937/2.png" style="height:85px; width:91px"></p>

<p style="text-align: center;">그림 3. 잘려진 두부모판</p>

<p>이때, 이들 포장단위의 가격은 [A,A]=100, [F,C]=0, [A,C]=40, 그리고 [A,B]=70 이다. 여기서 오른쪽 위 [C]와 같이 단위두부 하나는 포장단위가 아니므로 판매할 수 없다. 따라서 총 가격은 210원이 된다. 이 가격은 그림 2와 같은 3×3 두부모판에서 받을 수 있는 가장 높은 가격이다. </p>

<p>두부모판의 크기와 단위두부의 등급이 주어질 때, 이를 포장단위로 잘라 받을 수 있는 총 가격의 최댓값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에는 두부모판의 크기를 나타내는 N (2 ≤ N ≤ 11)이 주어진다. 둘째 줄부터 N 줄에 걸쳐 각 줄에 두부모판의 단위두부의 등급들이 행단위로 등급사이에 공백없이 첫 번째 행부터 차례로 주어진다.</p>

### 출력 

 <p>입력된 두부모판을 포장단위로 잘라서 받을 수 있는 최대 가격을 첫째 줄에 출력한다.</p>

