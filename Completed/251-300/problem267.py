import numpy as np
import math
from scipy.optimize import minimize_scalar

def f(x):
    return (9*np.log(10)-1000*np.log(1-x))/(np.log(1+2*x)-np.log(1-x))

def choose(n, k):
    if k <= n//2:
        k = n-k
    ans = 1
    for i in range(1, k+1):
        ans *= (n-i+1)
        ans /= i
    return ans

if __name__ == "__main__":
    res = minimize_scalar(f, bounds=(0, 1), method='bounded')
    n = math.ceil(f(res.x))
    choose_sum = 0
    for i in range(n, 1001):
        choose_sum += choose(1000, i)
    print("{:.12f}".format(choose_sum/(2**1000)))
    