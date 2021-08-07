import math

if __name__ == "__main__":
    f = open("../problem_inputs/p099_numbers.txt", "r")
    largest = 0
    ans = -1
    for i, line in enumerate(f):
        nums = line.split(",")
        power = int(nums[1])*math.log(int(nums[0]))
        if power > largest:
            ans = i+1
            largest = power
    print(ans)
            
    