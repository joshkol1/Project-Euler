# Post-solving: check out https://en.wikipedia.org/wiki/Parasitic_number

# Return number of satisfying integers for that mod 100000 value
def search_end(end_digits, multiplier):
    n_solutions = 0
    for ten_pow in range(95):
        low = 10**ten_pow
        high = 10**(ten_pow+1)-1
        # Binary search for solution, given # digits and mod 100000
        while low < high:
            mid = (low+high)//2
            candidate = mid*100000+end_digits
            rotation = candidate//10 + (candidate%10)*(10**(ten_pow+5))
            if candidate*multiplier == rotation:
                # print("{} {} {}".format(candidate, rotation, multiplier))
                n_solutions += 1
                break
            elif candidate*multiplier > rotation:
                high = mid-1
            else:
                low = mid+1
        if low == high:
            candidate = low*100000+end_digits
            rotation = candidate//10 + (candidate%10)*(10**(ten_pow+5))
            if candidate*multiplier == rotation:
                # print("{} {} {}".format(candidate, rotation, multiplier))
                n_solutions += 1
    return n_solutions

def main():
    answer = 0
    for i in range(100000):
        if i%10 == 0:
            continue
        right_rot = i//10
        for j in range(1, i%10+1):
            # Note that the value of j (multiplication factor) is unique
            if (i*j)%10000 == right_rot:
                answer = (answer+search_end(i, j)*i)%100000
                break
        if i >= 10:
            i_string = str(i)
            i_rot = int(i_string[-1]+i_string[:-1])
            if i_rot%i == 0:
                answer = (answer+i)%100000
    print(answer)
    return 0

if __name__ == "__main__":
    main()