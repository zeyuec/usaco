# USACO Solutions

These are my solutions of [USACO](http://train.usaco.org) problems, written in c.

Author: zeyuec

## Section 1

##### Section 1.1 
* 1-1-1 Your ride is Here [2013-05-08]: Implementation
* 1-1-2 Greedy Gift Giver [2013-05-08]: Implementation
* 1-1-3 Friday Thirteenth [2013-05-11]: Implementation
* 1-1-4 Broken Necklace [2013-05-11]: Triple the necklace and search all positions

##### Section 1.2
* 1-2-1 Milking Cows [2013-05-11]: Sort the list of time and go over it.
* 1-2-2 Transformations [2013-05-11]: Implementation
* 1-2-3 Name That Number [2013-05-11]: Hash all words in the file and search
* 1-2-4 Palindromic Squares [2013-05-11]: Implementation
* 1-2-5 Dual Palindromes [2013-05-11]: Implementation

##### Section 1.3
* 1-3-1 Mixing Milk [2013-05-11]: Greedy, sort milks by price
* 1-3-2 Barn Repair [2013-05-11]: Greedy, sort the spaces between barns, top M spaces donot need to be repaired
* 1-3-3 Calf Flac [2013-05-12]: Implementation
* 1-3-4 Prime Cryptarithm [2013-05-12]: Search with brute force

##### Section 1.4
* 1-4-1 Packing Rectangles [2013-05-16]: Implementation with patient
* 1-4-2 The Clocks [2013-05-16]: Implementation, each move appears three times at most
* 1-4-3 Arithmetic Progressions [2013-05-13]: Generate all nums of p^2+q^2 and search
* 1-4-4 Mother's Milk [2013-05-13]: DFS

##### Section 1.5
* 1-5-1 Number Triangles [2013-05-16]: Easy DP
* 1-5-2 Prime Palindromes [2013-05-16]: Palindrome num can be generateed
* 1-5-3 SuperPrime Rib [2013-05-16]: BFS
* 1-5-4 Checker Challenge [2013-05-20]: Use binary number to indicate one row status. This is the fastest algorithm, it only costs 0.1s when N=13, see more details in my source file

## Section 2

##### Section 2.1
* 2-1-1 The Castle [2013-05-20]: Easy Floodfill
* 2-1-2 Ordered Fractions [2013-05-20]: Implementation
* 2-1-3 Sorting A Three-Valued Sequence [2013-05-21]: Count 1, 2, 3
* 2-1-4 Healthy Holsteins [2013-05-22]: For each feed, choose or not,  only 2^15 possibilities, just search
* 2-1-5 Hamming Codes [2013-05-22]: Search 2^B-1 numbers, maintain an answer queue. First one is 0, then check if the candidate number has at least D distance from each numbers in the queue, if it is, add it in.

##### Section 2.2
* 2-2-1 Preface Numbering [2013-05-24]: Count each character recursion
* 2-2-2 Subset Sums [2013-05-23]: Easy DP, f[i][j] = f[i-1][j] + (f[i-1][j-i] if j-i >=0), f[i][j] indicates how many ways can you find to get a sum of j in the first i nums
* 2-2-3 Runaround Numbers [2013-05-24]: Implementation
* 2-2-4 Party Lamps [2013-05-26]: Press a button twice is the same as not pressing it and the order of pressing does not matter, so there are at most 15 possibilities. For any C>4, keep minusing it by 2 until C<=4, then search

##### Section 2.3
* 2-3-1 The Longest Prefix [2013-05-27]: DP (hint: 200,000 times of strlen() will cause a lot of time)
* 2-3-3 Zero Sum [2013-05-26]: Only at most 3^8 possibilities, DFS
* 2-3-4 Money System [2013-05-28]: f[i][j] = f[i-1][j] + (f[i-1][j-coin[i]] if j-coin[i] >= 0), f[i][j] indicates number of ways make j cents with first i type of coins
* 2-3-5 Controlling Companies [2013-05-29]: DFS, pay attention to the range

