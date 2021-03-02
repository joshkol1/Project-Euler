import itertools
triangle = []
square = []
pentagonal = []
hexagonal = []
heptagonal = []
octagonal = []
all_numbers = [
	triangle, square, pentagonal, hexagonal, heptagonal, octagonal
]

for i in range(0, 1000):
	if 1000 <= i*(i+1)/2 <= 9999:
		triangle.append(int(i*(i+1)/2))
	if i*(i+1)/2 > 9999:
		break
for i in range(0, 1000):
	if 1000 <= i*i <= 9999:
		square.append(i*i)
	if i*i > 9999:
		break
for i in range(0, 1000):
	if 1000 <= i*(3*i-1)/2 <= 9999:
		pentagonal.append(int(i*(3*i-1)/2))
	if i*(3*i-1)/2 > 9999:
		break
for i in range(0, 1000):
	if 1000 <= i*(2*i-1) <= 9999:
		hexagonal.append(i*(2*i-1))
	if i*(2*i-1) > 9999:
		break
for i in range(0, 1000):
	if 1000 <= i*(5*i-3)/2 <= 9999:
		heptagonal.append(int(i*(5*i-3)/2))
	if i*(5*i-3)/2 > 9999:
		break
for i in range(0, 1000):
	if 1000 <= i*(3*i-2) <= 9999:
		octagonal.append(i*(3*i-2))
	if i*(3*i-2) > 9999:
		break


def binary_search(s_list, query):
	left = 0
	right = len(s_list)-1
	while(left <= right):
		if left==right and s_list[left] != query:
			if query > s_list[left]:
				return left+1
			else:
				return left
		elif left+1==right:
			if query != s_list[left] and query != s_list[right]:
				if query < s_list[left]:
					return left
				elif query > s_list[right]:
					return right+1
				else:
					return right
		medium = left + (right-left)//2
		if(s_list[medium] == query):
			return medium
		elif s_list[medium] < query:
			left = medium + 1
		else:
			right = medium - 1
	return -1 # This shouldn't happen


def dfs(perm, stack):
	if len(stack) == 6:
		# Check the cyclic condition on first and last terms
		leading = (stack[0]-stack[0]%100)//100
		trailing = stack[-1]%100
		if leading == trailing:
			print(stack)
			print("Sum of values: {}".format(sum(stack)))
		return
	perm_index = len(stack)-1
	leading = stack[-1]%100
	number_type = perm[perm_index]
	ind = binary_search(all_numbers[number_type], leading*100)
	while all_numbers[number_type][ind] < (leading+1)*100:
		if all_numbers[number_type][ind]%100 >= 10:
			stack.append(all_numbers[number_type][ind])
			dfs(perm, stack)
			stack.pop()
		ind += 1


for initial_term in all_numbers[0]:
	if initial_term%100 >= 10:
		for perm in list(itertools.permutations([1,2,3,4,5])):
			dfs(perm, [initial_term])