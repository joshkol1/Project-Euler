primes_list = [3, 5323, 10357, 29587, 31231]

def isPrime(n):
	i = 2
	while i*i <= n:
		if n%i==0:
			return False
		i += 1
	return True

for i in range(0, 5):
	for j in range(i+1, 5):
		new_prime1 = int(str(primes_list[i])+str(primes_list[j]))
		print("{} is prime: {}".format(new_prime1, isPrime(new_prime1)))
		new_prime2 = int(str(primes_list[j])+str(primes_list[i]))
		print("{} is prime: {}".format(new_prime2, isPrime(new_prime2)))