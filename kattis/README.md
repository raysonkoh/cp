# Interesting Problems

* phonelist: prefix matching (use sort for speed up)
* shortestpath1: basic dijkstra
* 10kindsofpeople: smart BFS (i.e. do BFS once to get all connected components)
* bank: "kinda" greedy - start from endtime to starttime using maxheap
* unionfind: basic UFDS (weighted union)
* wheresmyinternet: basic BFS connectivity
* primesieve : finding prime numbers < 10^8 quickly
* getshorty: dijkstra with negative log
* pivot: two pass from left and from right, each time keep track of current max and min
* guess: simple binary search
* joinstrings: recursive print string problem disguised as string concat (append index instead of actual string for significant speedup)
* railroad2: euler walk: all nodes even deg (i.e. x has deg 4, y has deg 3, make sure tol deg is even -- handshaking lemma);
* teque: simulate with two deques (one front, one back), making sure that each deque is roughly half of tol size
* commercials: kadane's algo - key idea is dp[i] refers to max sum subarray ending at index i --> dp[i] = max(dp[i - 1] + A[x], A[x])
* digits: stoi(very large string) will cause runtime error
