def next_convergent(n, d):
    return n+2*d, n+d

if __name__ == "__main__":
    n, d = 1, 1
    ans = 0
    for i in range(1000):
        n, d = next_convergent(n, d)
        if(len(str(n)) > len(str(d))):
            ans += 1
    print(ans)
