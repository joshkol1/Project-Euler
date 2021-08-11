roman = [
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
]

roman_values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

def to_arabic(roman_num):
    ans = 0
    while len(roman_num) > 0:
        for i, r in enumerate(roman):
            if roman_num.find(r) == 0:
                ans += roman_values[i]
                roman_num = roman_num[len(r):]
                break
    return ans

def from_arabic(n):
    ans = ""
    while n > 0:
        for i, v in enumerate(roman_values):
            if v <= n:
                if roman[i].find("D") >= 0 and ans.find("D") >= 0:
                    continue
                if roman[i].find("L") >= 0 and ans.find("L") >= 0:
                    continue
                if roman[i].find("V") >= 0 and ans.find("V") >= 0:
                    continue
                ans += roman[i]
                n -= v
                break
    return ans

if __name__ == "__main__":
    f = open("../../problem_inputs/p089_numerals.txt", "r")
    ans = 0
    for line in f:
        n = line.strip()
        ans += len(n) - len(from_arabic(to_arabic(n)))
    print(ans)