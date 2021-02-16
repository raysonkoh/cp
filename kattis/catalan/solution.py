q = input()
q = int(q)

catalan = [1]
for n in range(1, 5001):
    catalan.append((catalan[n - 1] * (4 * (n - 1) + 2)) // (n + 1))

for i in range(0, q):
    print(int(catalan[int(input())]))
