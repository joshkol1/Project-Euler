def sqrt_expansion(n):
    root = 0
    for d in range(100):
        root *= 10
        while root*root < n:
            root += 1
        root -= 1
        n *= 100
    return root

if __name__ == "__main__":
    squares = [4, 9, 16, 25, 36, 49, 64, 81]
    ans = 0
    for n in range(2, 100):
        if n in squares:
            continue
        root = str(sqrt_expansion(n))
        ans += sum([ord(c)-ord('0') for c in root])
    print(ans)

