# Profiles

* [Kattis](https://open.kattis.com/users/raysk)
* [Codeforces](https://codeforces.com/profile/raysk)

# Interesting Problems

## Codeforces
* 690-3 D: greedily check whether can split from k = n segments to k = 1
* 690-3 E1: sort then use lower_bound, m - 1 choose k - 1, note int overflow
* 690-3 F: intervals don't intersect when they are totally disjoint (num start after I ends + num end after I start)
* circularrmq: application of segment trees with lazy prop
* 686-3 D: prime factorization, k = max exponent, n = i * i *.. * i * {pdt of remaining factors}
* 686-3 E: "almost" tree / cthulhu graph, first find cyclic nodes, then sum each num paths within each subtree + num paths between subtrees
* 686-3 F: keep prefix + suffix runningMax, rmq using segment tree, fix x and binary search y
* 693-3 E: bin search for H, keep minimum width prefix for sorted H array
* 693-3 F: greedy, always prefer to put vertical, maintain offset bet top and bot and do case analysis based on whether dist is even/odd
* 693-3 G: graph DP using dfs
* 695-2 C: requires novel insight using trees: odd dist subtract, even dist add, two cases: separate min from 2 bag or negate a whole bag
* 695-2 D: use DP twice, once for finding num good paths starting from A[i], another for finding occurence of A[i] in good path after j moves
* **695-2 E: too hard, will upsolve it at a later time**

## Kattis

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
* knapsack: standard knapsack DP but with additional parent pointers
* brexit: keep vector of initial and current deg, had a nasty bug with forgetting to insert initial `l` into the `deleted` set
* closestsums: O(n^2) pairings, store sum in set and compare lower_bound and lower_bound--
* gcpc: keep score vector and penalty vector and set of teams which are better
* moneymatters: make sure tol sum in each connected component is 0
* secretchamber: BFS to find all possible translations given a source
* almostperfect: sumDiv(n)
* bing: use Trie data structure with each TrieNode storing size of its subtree
* stringmatching: use KMP string matching algo for O(n + m) time, rabin-karp might be too slow
* happyprime: use prime seive to check prime + cycle finding to check is happy
* lostmap: similar to Kruskal's algo
* ants: greedy, for each pos find dist to left / right end
* classy: convert string to numerical rep for easier sorting and use custom sort comparator
* cookieselection: online median finding algo using 2 PQs - maxHeap for smaller ranks, minHeap for higher ranks 
* grid: slightly modified dijkstra 
* yinyangstones: greedy, prove that only possible if num white = num black
* grandpabernie: rank tree using pbds, avoid duplicate by using double and truncating to int
* shortestpath3: output must have blank line between cases (qns is not clear) and note edge cases when dist[u] = INF
* calculatingdartscores: can brute force
* kattissquest: use map and lower_bound
* spiderman: tricky DP, at each step go U or D + store solution string
* integerlists: read input char by char, reverse by swapping start and end ptrs, drop by incr or decr start ptr
* a1paper: observing patterns
* restaurant: simulate queue using 2 stacks
* polygonarea: application of shoestring algo to find area + determine CCW (+ve area) or CW (-ve area)
* sim: use stl list and iterator
* airconditioned: greedy, aim to keep curr interval as large as possible
* howmanydigits: num digits = log10(a*b*c*...), precompute
* speed: bin search using double, terminate when within acceptable error range
* firefly: sort then lower_bound
* inversefactorial: num digits can uniquely identify n except edge case where n <= 6
* anagramcounting: use java BigInteger, precompute factorials
* longincsubseq: O(nlogn) LIS
* bigtruck: standard dijkstra with extra maximize items op when d + wt == dist
* orders: set count vect with MAX size, iterate thru multiples of x and where v[y] > 0, v[y + x] += v[y]
* ladice: interesting application of modified UFDS, proof that you can always insert into same set if unused size > 0
* bachetsgame: dp on 2-player 0-sum game, no need to store player 2's state for speedup -> if player 1 cannot win then player 2 wins
* ballotboxes: use PQ and add divisor to the curr max
* rationalarithmetic: only need func for add and mul, use std::gcd for shortest form
* millionairemadness: dijkstra from (n-1,m-1) with modified minimax relax func
