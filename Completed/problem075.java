import java.util.*;
public class problem075 {
	// Problem: how many #s <= 1,500,000 can be formed into a right triangle in exactly one way?
	// Euclid's formula: let m > n > 0, and let k >= 1.
	// a = k*(m^2-n^2), b = k*2mn, c = k*(m^2+n^2)
	// a+b+c = 2k*m^2 + 2k*mn = 2k(m^2+mn) <= 1500000
	public static void main(String[] args) {
		int param = Integer.parseInt(args[0]);
		HashSet<Triple>[] ways = new HashSet[param+1];
		for (int i = 0; i < ways.length; i++) ways[i] = new HashSet<Triple>();
		for (long k = 1; k <= param/12; k++) {
			for (long n = 1; n*n < param/4; n++) {
				for (long m = n+1; 2*k*m*(m+n) <= param; m++) {
					Triple t = new Triple(k*(m*m+n*n),k*(m*m-n*n),k*2*m*n);
					ways[(int)(2*k*m*(m+n))].add(t);
				}
			}
		}
		int total = 0;
		for (int i = 0; i <= param; i++) {
			if (ways[i].size() == 1) total++;
		}
		System.out.println(total+" lengths can be formed in exactly one way");
	}
	public static long gcd(long a, long b) {
		if (a%b == 0) return b;
		if (b%a == 0) return a;
		if (a > b) return gcd(b,a%b);
		return gcd(a,b%a);
	}
	static class Triple {
		long a, b, c;
		public Triple(long a, long b, long c) {
			long[] array = {a,b,c};
			Arrays.sort(array);
			this.a = array[0]; this.b = array[1]; this.c = array[2];
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime*result + (int)a;
			result = prime*result + (int)b;
			result = prime*result + (int)c;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj) return true;
			if (obj == null) return false;
			if (getClass() != obj.getClass()) return false;
			Triple other = (Triple) obj;
			if (a != other.a) return false;
			if (b != other.b) return false;
			if (c != other.c) return false;
			return true;
		}
	}
}