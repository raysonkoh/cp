def extendEuclid(x, y):
    if (y == 0):
        return 1, 0
    f, s = extendEuclid(y, x % y)
    return s, f - x // y * s


n = input()
for i in range(0, int(n)):
    line = input()
    a, n, b, m = line.split(' ')
    a = int(a)
    n = int(n)
    b = int(b)
    m = int(m)
    # print(a, b, n, m)
    x, y = extendEuclid(n, m)
    ans = x * n * b + y * m * a
    k = n * m
    print(ans % k, k)
