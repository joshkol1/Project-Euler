import java.util.*;
public class problem123 {
	static ArrayList<Long> primes = new ArrayList<>();
	static boolean[] prime = new boolean[100000001];
	public static void main(String[] args) {
		generatePrimes();
		System.out.println(primes.get(1));
		for (int i = 0; i < primes.size(); i++) {
			if ((1+2*i)*primes.get(i) > 5000000000L) {
				System.out.println(primes.get(i));
				break;
			}
		}
	}
	public static void generatePrimes() {
		int count = 0;
		for (int i = 2; i < prime.length; i++) {
			if (!prime[i]) {
				if (count%2 == 0) primes.add((long)i);
				count++;
				for (int j = i ; j < prime.length; j += i) {
					prime[j] = true;
				}
			}
		}
	}
}