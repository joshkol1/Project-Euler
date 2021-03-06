from decimal import Decimal

eps = 1e-13
poly = []

def choose(n, k):
    ans = Decimal(1)
    for i in range(1, k+1):
        ans *= Decimal(n-i+1)
        ans /= Decimal(i)
    return ans

def mult(r):
    poly.append(Decimal(0))
    for i in range(len(poly)-2, -1, -1):
        poly[i+1] += -r*poly[i]
    return

def construct(q):
    global poly
    poly = [Decimal(1)]
    for i in range(1, 51):
        mult(Decimal(1)-Decimal(i)/q)

def probability(q):
    construct(q)
    ans = 0
    for i in range(20, 51):
        ans += choose(i, 20)*poly[i]
    return ans

def bin_search():
    low = Decimal(52.0)
    high = Decimal(53.0)
    while(abs(low-high) > eps):
        m = (low+high)/Decimal(2)
        p = probability(m)
        if p > Decimal(0.02):
            low = m
        else:
            high = m
    print("{:.10f}".format(low))
    
bin_search()