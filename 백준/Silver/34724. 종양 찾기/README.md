# [Silver V] 종양 찾기 - 34724 

[문제 링크](https://www.acmicpc.net/problem/34724) 

### 성능 요약

메모리: 3000 KB, 시간: 12 ms

### 분류

구현, 브루트포스 알고리즘, 애드 혹

### 제출 일자

2025년 11월 8일 19:56:47

### 문제 설명

<p>아코는 세계에서 손꼽히는 혈관 박사이다. 아코는 천재적인 감으로 건강한 혈관과 종양이 있는 혈관을 빠르게 구분해 낼 수 있다. 아코는 동국인들의 건강을 위해 X-ray 사진에서 종양을 판별하는 프로그램을 만들고자 한다.</p>

<p>X-ray에서 종양과 혈관은 모두 $1$로 보이게 된다. 그 외의 빈 공간은 모두 $0$으로 보인다. 천재 동국이는 X-ray를 다음과 같이 분석한다.</p>

<ul>
<li>X-ray 상에서 $0$을 포함하지 않는 모든 직사각형을 조사한다.</li>
<li>직사각형의 모든 변은 X-ray의 행과 열에 평행하다.</li>
</ul>

<p>분석 결과는 다음 규칙에 따라 판정한다.</p>

<ol>
<li>직사각형의 짧은 변을 너비라고 한다.</li>
<li>모든 직사각형의 너비가 $1$이면 <strong>정상적인 혈관</strong>이다.</li>
<li>너비가 $1$보다 큰 직사각형이 하나라도 존재하면 <strong>종양</strong>이 있다고 판단한다.</li>
</ol>

<p>정상적인 혈관의 예시 1 :</p>

<table border="1" cellpadding="0" cellspacing="0" class="table table-bordered" style="width: 100px;">
<tbody>
<tr>
<td>0</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>0</td>
<td>0</td>
<td>0</td>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>1</td>
<td>0</td>
<td>0</td>
<td>0</td>
</tr>
<tr>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
</tr>
</tbody>
</table>

<p>정상적인 혈관의 예시 2 :</p>

<table border="1" cellpadding="0" cellspacing="0" class="table table-bordered" style="width: 100px;">
<tbody>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
</tr>
<tr>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
</tr>
<tr>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
</tr>
</tbody>
</table>

<p>종양의 예시:</p>

<table border="1" cellpadding="0" cellspacing="0" class="table table-bordered" style="width: 100px;">
<tbody>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
</tr>
<tr>
<td>0</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>0</td>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>0</td>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
<td>0</td>
</tr>
</tbody>
</table>

<p>위 경우는 <strong>너비가 2이고 길이가 3인 직사각형</strong>이 있기 때문에 종양이라고 판단한다.</p>

<p>아코를 위해! 그리고 동국인들의 혈관 건강을 위해! 프로그램을 만들어주자.</p>

### 입력 

 <p>첫째 줄에는 X-ray 사진의 세로길이 $N$과 가로길이 $M$이 주어진다. $(2\leq N, M \leq 1\,000)$ </p>

<p>다음 $N$개의 줄에 길이 $M$의 $0$과 $1$로 이루어진 문자열로 이루어진 X-ray 사진이 주어진다.</p>

### 출력 

 <p>종양이 있다면 $1$을 출력하고, 종양이 없다면 $0$을 출력한다.</p>

