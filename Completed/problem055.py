def lychrel(n):
    for i in range(50):
        n += int(str(n)[::-1])
        if str(n) == str(n)[::-1]:
            return False
    return True

if __name__ == "__main__":
    ans = 0
    for n in range(1, 10000):
        if lychrel(n):
            ans += 1
    print(ans)