# [Unrated] Signatures - 8045 

[문제 링크](https://www.acmicpc.net/problem/8045) 

### 성능 요약

메모리: 2964 KB, 시간: 12 ms

### 분류

분류 없음

### 제출 일자

2025년 4월 9일 02:48:43

### 문제 설명

<p>There are clerks and commanders employed in Byteland Security Agency (BSA). The records of all the clerks can be found in the BSA archives. In each folder there is a signature of the clerk and signatures of workers (clerks or commanders), who vouche for his/her loyalty. Every newly engaged clerk has to obtain at least one guarantee. In the course of time, list of guarantors can increase. BSA has found out lately, that the circle of commanders has been infiltrated by a spy from hostile Microsoftland. Next spies were employed in BSA on clerks positions thanks to the guarantee of a spy-commander and/or other employed spies. Such spies have guarantees exclusively from workers being spies.</p>

<p>Reliability of a clerk can be questioned, if he has not indirectly got guarantees from any commander, who is not a spy, i.e. there is no such sequence of BSA workers p<sub>1</sub>,p<sub>2</sub>,…,p<sub>k</sub>, that p<sub>1</sub> is commander not being a spy, p<sub>k</sub> is given clerk and (for i=1,…,k-1) p<sub>i</sub> vouches for p<sub>i+1</sub>.</p>

<p>If an assumption that a commander is a spy, caused that reliability of a clerk became questioned, this clerk would be suspected of spying. The command of BSA would want to see the list of these clerks, as soon as possible!</p>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input number of commanders and clerks in BSA and informations about guarantees,</li>
	<li>determines a list of clerks suspected of spying,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input consists of exactly one positive integer n, (1 ≤ n ≤ 500), standing for the number of workers of BSA. The employees are numbered from 1 to n. The next n lines contain descriptions of guarantees. In the (i+1)-th line of the file there is the description of guarantees given to the i-th worker. It is a sequence of integers separated by single spaces. The first number in this sequence 0 ≤ m<sub>i</sub>, equals to the number of guarantees given to the i-th worker. The next m<sub>i</sub> integers are the numbers of workers, who have guaranteed the truthfullness of the -th worker. (Thus the number of elements in the sequence in the (i+1)-th line equals m<sub>i</sub>+1). Commanders are those workers, who have not been vouched for by anybody.</p>

### 출력 

 <p>Your program should:</p>

<ul>
	<li>write in the consecutive lines of the standard output sequence of positive integers being numbers of clerks suspected of spying - if such clerks exist. These numbers should be written in increasing order, exactly one in each line,</li>
	<li>write in the first and the only line of the standard output exactly one word BRAK - if such clerks do not exist.</li>
</ul>

