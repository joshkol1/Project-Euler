#!/usr/bin/env python3

vals = [(420**2)/(i**2) for i in range(1,8)]
print(sum(vals))

for i in range(1,128):
	tot = 0
	temp = i
	for j in range(0,7):
		if (temp%2 == 1):
			tot += vals[6-j]
		temp = temp//2
	if (tot%121 == 0):
		print(i)
