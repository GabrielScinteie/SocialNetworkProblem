# Challenge
### Let's build a social network. 

In this social network, each user has friends.

A chain of friends between two users, user A and user B, is a sequence of users starting with A and ending with B, such that for each user in the chain, ua, the subsequent user, ua + 1, are friends.

Given a social network and two users, user A and user B, please write a function that computes the length of the shortest chain of friends between A and B

## How did you represent the social network? Why did you choose this representation? <br>

I represented the social network as an undirected graph where users are mapped as vertices and friendships between users are mapped as edges. <br>
For the implementation of the graph I used an Adjacency List because it is more time efficient than its most common alternative which is an Adjacency Matrix. <br>

## What algorithm did you use to compute the shortest chain of friends? What alternatives did you consider? Why did you choose this algorithm over the alternatives? <br>

I chose DFS(Depth First Search) to compute the shortest chain of friends. <br>
Firstly I considered using Dijktra's algorithm to compute the shortest path between two vertices but I have realized that it's not necessary because the cost of each edge is 1. <br>
Then I started thinking about BFS and DFS and I arbitrary chose DFS since I was confident that they have the same time complexity.<br>

## Please enumerate the test cases you considered and explain their relevance

Firstly I made up a test where there are multiple paths with distinct lengths from user A to user B to see if the algorithm can choose the best one. <br>
After seeing it worked well on general testcases I tested the case where there's no path of friends from user A to user B.<br>

## Input examples:

#### 1)
8 <br>
2 8 <br>
1 2 <br>
1 3 <br>
2 3 <br>
3 6 <br>
3 5 <br>
5 4 <br>
4 7 <br>
6 7 <br>
7 8 <br>
6 8 <br>


#### 2) 
9 <br>
2 9 <br>
1 2 <br>
1 3 <br>
2 3 <br>
3 6 <br>
3 5 <br>
5 4 <br>
4 7 <br>
6 7 <br>
7 8 <br>
6 8 <br>


