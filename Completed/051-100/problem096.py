corners = []

def print_puzzle(puzzle):
    for r in puzzle:
        row = ""
        for c in r:
            row += str(c)
        print(row)
    print()

def solve(puzzle, depth, solved):
    if solved:
        return
    if depth >= 81:
        corners.append(puzzle[0][0]*100+puzzle[0][1]*10+puzzle[0][2])
        solved = True
        return
    row, col = depth//9, depth%9
    if puzzle[row][col] != 0:
        solve(puzzle, depth+1, solved)
        return
    cands = [True for i in range(0, 10)]
    for i in range(0, 9):
        cands[puzzle[row][i]] = False
        cands[puzzle[i][col]] = False
    big_row, big_col = (row//3)*3, (col//3)*3
    for i in range(0, 3):
        for j in range(0, 3):
            cands[puzzle[big_row+i][big_col+j]] = False
    for i in range(1, 10):
        if cands[i]:
            puzzle[row][col] = i
            solve(puzzle, depth+1, solved)
            puzzle[row][col] = 0

if __name__ == "__main__":
    f = open("../../problem_inputs/p096_puzzles.txt", "r")
    for p in range(50):
        f.readline()
        puzzle = []
        for r in range(9):
            line = f.readline().strip()
            row = [ord(c)-ord('0') for c in line]
            puzzle.append(row)
        solve(puzzle, 0, False)
    print(sum(corners))