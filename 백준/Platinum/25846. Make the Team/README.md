# [Platinum IV] Make the Team - 25846 

[문제 링크](https://www.acmicpc.net/problem/25846) 

### 성능 요약

메모리: 2184 KB, 시간: 0 ms

### 분류

이분 매칭

### 제출 일자

2025년 3월 10일 00:26:07

### 문제 설명

<p>You are eager to make the programming team. You have decided that if you watch several videos, you will increase your chances of making the team. Each video you want to watch is one hour long, and each video plays at specific times. Naturally, you want to get through all the videos as fast as possible, to leave more time to practice!</p>

<p>For example, if you want to watch two videos and the first one is available at the time intervals [1,2), [4,5), [8,9) and [12,13), and the second video is available at the time intervals [4,5), [7,8), and [11,12), then the earliest time at which you can complete the two videos is time 5. You can accomplish this by watching the first video in the time interval [1,2) and the second one at the time interval [4,5). Note that all videos play for precisely the length of one time interval, and one can watch back to back videos. Thus, if one video plays at the interval [x, x+1) and another video plays at the interval [x+1, x+2), where x is a positive integer, both can be watched, back to back.</p>

<p>Given a list of times that each video you want to watch is available, determine the earliest time at which you can complete watching all of the videos. Note that the videos can be watched in any order as long as the time intervals allow.</p>

### 입력 

 <p>The first input line contains a single integer, n (1 ≤ n ≤ 200), indicating the number of videos you would like to watch. Each of the next n input lines describes a video you want to watch. The i th of these input lines starts with an integer, t<sub>i</sub> (1 ≤ t<sub>i</sub> ≤ 30), representing the number of times video i is available to watch. This is followed by t<sub>i</sub> space separated values indicating the starting time video i is available to watch. The list of times for each video will be a strictly increasing list of positive integers, with a maximum value of 1000. It is guaranteed that there will be at least one arrangement that allows you to watch all of the videos.</p>

### 출력 

 <p>Print the earliest time at which you can complete watching all of the videos.</p>

