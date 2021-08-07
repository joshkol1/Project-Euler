#!/usr/bin/env python3
import math
from decimal import *
MAX_DEN = 1000000000000
MAX_ROOT = 100000

"""
    Euclidean algorithm
"""
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)


"""
    Is n square?
"""
def square(n):
    root = math.floor(math.sqrt(n))
    return root*root == n


"""
    Calculate all the mediants of sqrt(n) and find the best
    approximation to sqrt(n) below MAX_DEN. Return its denominator
"""
def process(n):
    seq = []
    h_list = [0, 1]
    k_list = [1, 0]
    """
        Coefficients of (a+b*sqrt(n))/c
    """
    a = 0
    b = 1
    c = 1
    """
        Main loop for c.f. generation
    """
    best_num = int(math.sqrt(n))
    best_den = 1
    sqrt_n = Decimal(n).sqrt()
    best_difference = abs(sqrt_n-Decimal(best_num)/Decimal(best_den))
    while k_list[-1] <= MAX_DEN:
        cf_floor = int((a+b*math.sqrt(n))/c)
        seq.append(cf_floor)
        a -= cf_floor*c
        old_c = c
        c = b*b*n-a*a
        a *= -old_c
        b *= old_c
        common_factor = gcd(a, gcd(b, c))
        a /= common_factor
        b /= common_factor
        c /= common_factor
        for i in range(max(cf_floor//2, 1), cf_floor+1):
            h1 = i*h_list[-1]+h_list[-2]
            k1 = i*k_list[-1]+k_list[-2]
            if k1 > MAX_DEN:
                continue
            diff = abs(sqrt_n-Decimal(h1)/Decimal(k1))
            if diff < best_difference:
                best_difference = diff
                best_num = h1
                best_den = k1
        h = cf_floor*h_list[-1]+h_list[-2]
        k = cf_floor*k_list[-1]+k_list[-2]
        h_list.append(h)
        k_list.append(k)
    return best_num, best_den


if __name__ == "__main__":
    getcontext().prec = 60
    final_answer = 0
    for N in range(2, MAX_ROOT+1):
        if square(N):
            continue
        num, den = process(N)
        final_answer += den
    print(final_answer)