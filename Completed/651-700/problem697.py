import numpy as np
from scipy.stats import erlang
np.set_printoptions(precision=16,suppress=False)

def main():
    n = 10000000
    c_lb = np.float64(n)
    c_ub = np.float64(n)+np.sqrt(n)
    percentile = 0
    rv = erlang(n, scale=np.float64(1))
    while np.abs(c_lb-c_ub) >= 1e-4:
        mid = (c_lb+c_ub)/2
        percentile = rv.cdf(mid)
        if percentile > np.float64(0.75):
            c_ub = mid
        else:
            c_lb = mid
    answer = (c_lb+c_ub)/(2*np.log(10))
    print(round(answer, 2))
    return 0

if __name__ == "__main__":
    main()