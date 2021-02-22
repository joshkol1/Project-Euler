# List of all primes
primes = []
# List of primes 1 mod 3
primes_one = []
# List of primes 2 mod 3
primes_two = []
max_prime = int(1e5)
upper_bound = sum([13, 5197, 5701, 6733, 8389])
for i in range(2, max_prime):
	isPrime = True
	for prime in primes:
		if prime*prime > i:
			break
		if i%prime == 0:
			isPrime = False
			break
	if isPrime:
		if i%3 == 1 and i < upper_bound:
			primes_one.append(i)
		elif i%3 == 2 and i != 5 and i != 2 and i < upper_bound:
			primes_two.append(i)
		primes.append(i)


def isPrime(n):
	global primes
	for prime in primes:
		if prime*prime > n:
			break
		if n%prime == 0:
			return False
	return True


def append_okay(cur_list, new_prime):
	if (5-len(cur_list))*new_prime >= upper_bound:
		return False
	for p in cur_list:
		new_val1 = int(str(p)+str(new_prime))
		if not isPrime(new_val1):
			return False
		new_val2 = int(str(new_prime)+str(p))
		if not isPrime(new_val2):
			return False
	return True


def dfs(candidates, cur_list, index):
	# Solution found
	if len(cur_list) == 5:
		print(cur_list)
		return
	while index < len(candidates):
		if append_okay(cur_list, candidates[index]):
			cur_list.append(candidates[index])
			dfs(candidates ,cur_list, index+1)
			cur_list.pop()
		index += 1


# Initial: try including 3 in the set, probably good
# Notice that all the primes must come from primes_one or primes_two
# but not both.
# SOLUTION FOUND: [3, 5323, 10357, 29587, 31231]
# Therefore, sum is less than or equal to 76501
# one_list = [3]
# two_list = [3]
# dfs(primes_one, one_list, 0)
# dfs(primes_two, two_list, 0)
# Above implies solution does not include 3, so try that
one_list = []
two_list = []
dfs(primes_one, one_list, 0)
dfs(primes_two, two_list, 0)

