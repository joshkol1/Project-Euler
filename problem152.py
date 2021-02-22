#!/usr/bin/env python3
from fractions import Fraction
# Problem: find ways to make 1/2 from distinct square reciprocals up to 80

def goodVal(n): # only prime factors are 2,3,5,7
	while (n > 1):
		if (n%2 == 0):
			n = n//2
		elif (n%3 == 0):
			n = n//3
		elif (n%5 == 0):
			n = n//5
		elif (n%7 == 0):
			n = n//7
		else:
			return False
	return True

inv_squares = [Fraction(1,i**2) for i in range(3,46) if (goodVal(i))]
#inv_squares.insert(8,Fraction(1,144))
current_tally = Fraction(0,1)
desired_sum = sum(inv_squares)-Fraction(1,4)
ways = 0

print(inv_squares)
print(len(inv_squares))
print(sum(inv_squares)-Fraction(1,4))

def dfs(index):
	global current_tally
	global ways
	global inv_squares
	if (current_tally == desired_sum):
		ways += 1
		print(ways)
	else:
		for i in range(index,len(inv_squares)):
			if (current_tally < desired_sum):
				current_tally += inv_squares[i]
				#print(current_tally)
				for j in range(i+1,len(inv_squares)):
					dfs(j)
				current_tally -= inv_squares[i]

dfs(0)
print(ways)