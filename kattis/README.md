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
* railroad2: euler walk: all nodes even deg (i.e. x has deg 4, y has deg 3, make sure tol deg is even -- handshaking lemma)
* teque: simulate with two deques (one front, one back), making sure that each deque is roughly half of tol size
* commercials: kadane's algo - key idea is dp[i] refers to max sum subarray ending at index i --> dp[i] = max(dp[i - 1] + A[x], A[x])
* digits: stoi(very large string) will cause runtime error
* bitsequalizer: finding patterns (kind of greedy, tricky!)
* baloni: tricky 1D array - initialize vector with size MAX height, storing at each height the number of arrows. At height h, check height h + 1
* numbertree: can use bit manipulation (left shift and bit-wise and) 
* ceiling: create BST using pointers to left and right (kinda confused over c++ memory management / memory leaks)
* coast: modified bfs + tedious post-processing, check for edge case (using simple inputs) and simple typo bugs in the code
* minspantree: variant of Kruskal's Algo
* downtime: use stack to keep track of available servers, arrays to keep track of start and end time, serverLoad and assignment of servers
* flowshop: use of custom comparator for priority queue
* imageprocessing: very tedius 2d array manipulation
* sidewayssorting: stable sort
* workstations: similar to **downtime**, except using two queues (one for locked and one for unlocked workstations) instead of a stack (note int overflow error)
* allpairspath: standard floyd warshall, but note the tricky check for negative cycles
* narrowartgallery: tricky 3-D DP problem
* evenup: use two stacks, prove that only the immediate right neighbor is relevant when two adjacent numbers are popped
* virtualfriends: application of UFDS using size heuristic instead of rank
* fenwick: implementation of fenwick tree, use fast io using `ios_base::sync_with_stdio(false)` and instead of using `endl` use `\n`
