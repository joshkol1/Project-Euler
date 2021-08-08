import math

epsilon = 1e-9

def contains_origin(p1, p2):
    return p1[0]*p2[1] == p1[1]*p2[0]

def angle(p1, p2):
    dotprod = p1[0]*p2[0]+p1[1]*p2[1]
    magn1 = math.sqrt(p1[0]*p1[0]+p1[1]*p1[1])
    magn2 = math.sqrt(p2[0]*p2[0]+p2[1]*p2[1])
    return math.acos(dotprod/(magn1*magn2))

if __name__ == "__main__":
    f = open("../../problem_inputs/p102_triangles.txt", "r")
    ans = 0
    for line in f:
        line_split = line.strip().split(",")
        p1 = [int(line_split[0]), int(line_split[1])]
        p2 = [int(line_split[2]), int(line_split[3])]
        p3 = [int(line_split[4]), int(line_split[5])]
        if contains_origin(p1, p2) or contains_origin(p1, p3) or contains_origin(p2, p3):
            continue
        angle_total = angle(p1, p2) + angle(p1, p3) + angle(p2, p3)
        if abs(angle_total-2*math.pi) < epsilon:
            ans += 1
    print(ans)