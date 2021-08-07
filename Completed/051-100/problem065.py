def get_convergent(terms):
    num, den = 1, terms[-1]
    for i in range(-2, -(len(terms)+1), -1):
        num = num+terms[i]*den
        num, den = den, num
    return num, den

if __name__ == "__main__":
    terms = []
    for i in range(100//3):
        terms += [1, 2*(i+1), 1]
    num, den = get_convergent(terms)
    print(sum([ord(c)-ord('0') for c in str(num+2*den)]))
