import java.util.*;
public class problem78 {
	// p(n,k) = # partitions of n into k parts
	// Note that p(n,k) = p(n-1,k-1)+p(n-k,k)
	static int[][] dp = new int[20001][20001];
	static int MOD = 1000000;
	public static void main(String[] args) {
		for (int n = 1; n <= dp.length; n++) {
			for (int k = 1; k <= n; k++) {
				calculate_dp(n,k);
			}
			int function = 0;
			for (int i = 1; i <= n; i++) {
				function = (function + dp[n][i]) % MOD;
			}
			if (n%1000 == 0) System.out.println(n);
			if (function == 0) {
				System.out.println("Found: "+n);
				break;
			}
		}
	}
	public static void calculate_dp(int n, int k) {
		if (n == k || k == 1) dp[n][k] = 1;
		else {
			dp[n][k] = (getValue(n-1,k-1)+getValue(n-k,k))%MOD;
		}
	}
	public static int getValue(int n, int k) {
		if (n < k) return 0;
		else return dp[n][k];
	}
}