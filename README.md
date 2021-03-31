# Profiles

* [Kattis](https://open.kattis.com/users/raysk) Top 50 in Singapore :)
* [Codeforces](https://codeforces.com/profile/raysk) Became Expert ;)

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
* E-102-2 C: constructive algo, use examples to notice that aba <> bab: num inversions stay the same
* E-102-2 D: use segment tree to find min, max, sum and note that min and max of right side should increase by sum of left
* E-102-2 E: transform graph into deleting any edge and adding any edge: 1 node in original graph -> 4 nodes in transformed graph
* 696-2 D: Consider case no swaps first, then consider for a swap (i, i + 1), find rocks remaining for pile i - 1 and i + 2, check the remaining 4 piles whether ok + check min >= 0
* 697-3 A: key observation: prime factorization is {2^k * x * ...} -- check whether there exists prime factors other than 2
* 697-3 B: use queue (dequeue and push (x + 2020) and (x + 2021)) to determine possible sums OR observe that a * 2020 + b * 2021 = (a + b) * 2020 + b, then checking R <= Q
* 697-3 C: for each pair count (k -  num impossible x - num impossible y + 1) then divide 2 because double counting
* 697-3 D: sort by descending b1 and b2, can choose {1,2,...,b2.size()} "2", then check target sum in prefixSum of b1
* 697-3 E: sort, then filter for unique num, multiply by binomial coefficient
* 697-3 F: if j == 0 flip row, can only flip col if i == 0
* 697-3 G: dp[i] to find max num of "compatible" num <= x, use sieve and "push" dp for significant speedup
* 698-2 B: Notice that for all k > 10 * d + d, they are all achievable since you can keep minusing d to within range [10 * d, 10 * d + d]. For the rest of the values which is roughly < 100, do dp[i][x] -> x is achievable with digit i, dp[i][x] = true if there exists some y < x, dp[i][y] = true and (x - y) is lucky.
* 698-2 C: Try out a bunch of examples, observe 2(a_i)(n - i) = d[i] - offset (which is 2 * sum of previous a_i). Check all a_i are valid.
* 698-2 D: Key observation: 2x - y = x + (x - y) --> only difference bet adj elements are relevant. Closure of the set under (2x - y) is any element in original set + some multiple of gcd
* 699-2 B: brute force works (got WA in contest due to needless optimizations which caused bugs in corner cases)
* 701-2 C: a = rb + r --> iterate through r which is upper bounded by sqrt(x) find num pairs given x,y for a given r in O(1)
* 701-2 D: key observation: 720720 is LCM of {1,2,...,16}. Every other element can be 720720, adjacent element can be 720720 - v[i][j]^4
* E-104-2 B: 1 cycle (offset) roughly n/2, tol: (num cycles + expectB) % n
* E-104-2 E: implementation-heavy, use multiset
* 702-3 G: if S <= 0 and maxPrefixSum < x, then impossible; else, numRounds(ceil): (x - maxPrefixSum + IMPT >>S - 1<< IMPT) / S, bin-search for remainding indx on maxPrefixSum
* 704-2 C: greedily pick leftmost endpt in first pass from left to right, in second pass from right to left greedily pick rightmost endpt and take max diff
* 704-2 D: observe that you can set 0th bit in y to 1 and (k + 1)th bit in x to 1 --> diff is k one bits, then the rest of the ones can be placed at pos where both x and y bit are 0
* 708-2 B: use map to store number % m and count, for a number, there can only be one other partner
* 708-2 C1: different cases (even/odd)
* 708-2 C2: (k - 3) 1s, then use solution for C1

## Google Kickstart

* 20-A-2: dp[i][j] represents max value from first i rows, picking j plates. dp[i][j] = MAX_J'(prefixSum[i][j'] + dp[i - 1][j-j'])
* 20-A-3: Binary search the ans for the max gap, for a given diff, num of sessions to add is ceil(diff / gap) - 1
* 21-A-2: precompute up,down,left,right where [i][j] entry indicates num of consecutive 1s; use examples to derive formula is min(2x, y) - 1
* 21-A-3: start from MAX, neighbors should be within 1 away, iterate until searched whole matrix; use SET as a PQ to utilize the `erase` method to minimize num of irrelevant entries in PQ
* 21-A-4: only in the case of 4 "-1"s (i.e. cycle) do we need to spend cost, construct vertices -> rows/cols, edges -> (i,j) pos of -1s wt: B[i][j], find Max ST and the ans is the sum of edges not included

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
* sellingspatulas: EVIL FLOATING POINT COMPARISONS! Note the use of EPS to check equality of doubles
* ticketpricing: dp[n][w] = max_i (dp[n - p[i]*q[i]][w - 1])
* presidentialelections: 2 choices - either flip state or don't flip state
* bagoftiles: use of bitmask to generate all subset sums, split array in half for significant speedup (i.e. meet in the middle)
* increasingsubsequence: LIS with greedily replacement of min last element of incr subseq of length i
* canonical: simulate DP and greedy coin-change method
* exactchange2: use subset sum to find min num of coin changes to i >= price
* almostunionfind: use vector of sets
* sequences: notice that inversions matter only when ele = 0, then num inversions = num 1s that are ahead of the ele
* anthonyanddiablo: given a segment, prove that the shape with greatest area is a circle
* trainsorting: max(lis starting from pos i + lds starting from pos i - 1)
* builddeps: toposort with edges reversed from file that was changed
* nesteddolls: sort by H and LIS by W, note case H equal and only need to store endpoints
* supercomputer: use BIT
* humancannonball: set edge wt as time taken to travel
* froshweek: merge sort + count inversions
* walrusweights: prune values > 1000 if there exists value closer to 1000
* dvds: key observation: you always want indx[1] < indx[2] < indx[3] < ..., if indx[i] > indx[i + 1], need to put (i + 1) to top of stack
* buttonbashing: Actually a BFS problem, not dp
* closestpair1: classic O(nlogn) closest pair, note the limits
* virus: greedy, while front (back) equal, pop front(back), return size
* shortestpath2: standard dijkstra with modified constraint for edge processing
* janitortroubles: use Brahmagupta's formula
* tetration: a = n^{1 / n}
* perfectpowers: Prove that largest p --> gcd of exp of each num in the prime factorization, if x is neg, take the largest p that is odd
* nonprimefactors: num facts = pdt of (prime exp + 1), use modified sieve
* threepowers: test bit to determine if num exists in the set, use BigInteger
* leftandright: set up freq arr of {char, count}, if L then possible range is {min...max-1}, if R then possible range is {min + 1...max}
* catalan: C_{n + 1} = (4n+2)/(n+2) C_{n}, use python for large nums
* turbo: use sum segment tree, maintain segTreeIndx for each num
* alphabet: min no. to add is 26 - (max incr seq in S), use DP
* bst: use sum seg tree + range update
* intervalcover: sweep line algo, sort according to incr left endpoint, then decr right endpoint, note cancerous double comparisons
* polymul2: use fft
* ninetynine: simple winning strategy for 2nd player: 3,6,9,...,99; as first player, if 2nd player slips up, proceed to print multiples of 3 to win
* cats: use MinST + num vertices
* moviecollection: Challenging, maintain segTree of size (m + r) and pos vect, each time delete will insert into new empty node in segtree, query -> range from 0 to pos[x]
* fruitbaskets: use subset sum
* runningmom: finding cycle in directed graph - only have cycles if neighbor is visited AND neighbor is in the stack
