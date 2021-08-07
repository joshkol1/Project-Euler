def get_triangles(n):
    return [i*(i+1)/2 for i in range(n+1)]

def value(word):
    return sum([ord(c)-ord('A')+1 for c in word])

if __name__ == "__main__":
    f = open("../../problem_inputs/p042_words.txt", "r")
    triangles = get_triangles(50)
    names = f.readline().split(",")
    names = [s[1:-1] for s in names]
    answer = 0
    for n in names:
        if value(n) in triangles:
            answer += 1
    print(answer)
    