if __name__ == "__main__":
    f = open("../problem_inputs/p022_names.txt", "r")
    names = f.readline().split(",")
    names = [s[1:-1] for s in names]
    names.sort()
    answer = 0
    for i, s in enumerate(names):
        answer += (i+1)*sum([ord(c)-ord('A')+1 for c in s])
    print(answer)