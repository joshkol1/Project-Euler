ten_powers = [10**i for i in range(8)]
full_bits = [2**i-1 for i in range(5,9)]

def isPrime(n):
	if n == 1:
		return False
	i = 2
	while i*i <= n:
		if(n%i == 0):
			return False
		i += 1
	return True

answer_found = False
problem_answer = 1e10

for full_bit in full_bits:
	if answer_found:
		break
	# print(full_bit)
	for i in range(1, full_bit+1, 2):
		min_multiplier = 0
		if i < full_bit//2+2:
			min_multiplier = 1
		# Bit complement of i with full_bit # of bits
		# print("\t{}".format(i))
		neg = full_bit^i
		if(neg == 0):
			continue
		all_ones = 0
		selected_tens = []
		# all_ones (neg) will be repeats
		# selected_tens (i) will be varied/looped from 0-9
		power = 0
		while neg > 0:
			all_ones += (ten_powers[power])*(neg&1)
			neg >>= 1
			power += 1
		power = 0
		while i > 0:
			if(i&1):
				selected_tens.append(ten_powers[power])
			i >>= 1
			power += 1
		# print("all_ones: {}".format(all_ones))
		# print(selected_tens)
		min_digits = ten_powers[len(selected_tens)-1]
		iterated_digits = ten_powers[len(selected_tens)]-1
		# print(iterated_digits)
		for combo in range(min_digits+1, iterated_digits, 2):
			# print("combo: {}".format(combo))
			if combo%5 == 0:
				continue
			base_total = 0
			index = 0
			while(combo > 0):
				base_total += selected_tens[index]*(combo%10)
				combo //= 10
				index += 1
			# print("base_total: {}".format(base_total))
			not_prime = 0
			prime_count = 0
			prime_found = False
			smallest_prime = 0
			for mult in range(min_multiplier, 10):
				if isPrime(base_total + mult*all_ones):
					if not prime_found:
						prime_found = True
						smallest_prime = base_total + mult*all_ones
				else:
					not_prime += 1
				if not_prime > 2:
					break
			threshold = 2-min_multiplier
			if not_prime <= threshold:
				answer_found = True
				problem_answer = min(problem_answer, smallest_prime)
				# print(base_total)
				# print(all_ones)
				# print("Smallest prime: {}".format(smallest_prime))
print("Answer: {}".format(problem_answer))
