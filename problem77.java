import java.util.*;
public class problem77 {
	static ArrayList<Integer> primes;
	public static void main(String[] args) {
		primes = new ArrayList<>();
		generatePrimesUpto(1000);
		int[][] ways = new int[10001][primes.size()];
		// ways[i][j] = # ways to make i, using up to the jth prime (and including it)
		for (int i = 1; i <= ways.length; i++) {
			for (int j = 0; primes.get(j) <= i; j++) {
				if (primes.get(j) == i) ways[i][j] = 1;
				else {
					int diff = i - primes.get(j);
					for (int k = 0; primes.get(k) <= diff && k <= j; k++) {
						ways[i][j] += ways[diff][k];
					}
				}
			}
			int sum = 0;
			for (int j = 0; primes.get(j) <= i; j++) {sum += ways[i][j];}
			System.out.println(i+": "+sum);
			if (sum > 5000) {
				System.out.println(i+" can be written in "+sum+" ways");
				break;
			}
		}
	}
	static void generatePrimesUpto(int n) {
		boolean[] array = new boolean[n+1];
		for (int i = 2; i < array.length; i++) {
			if (!array[i]) {
				primes.add(i);
				for (int j = i; j < array.length; j += i) {
					array[j] = true;
				}
			}
		}
	}
}