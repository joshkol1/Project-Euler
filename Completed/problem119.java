import java.util.*;
public class problem119 {
	public static void main(String[] args) {
		ArrayList<Long> solutions = new ArrayList<>();
		for (long sum = 1; sum <= 300; sum++) { // digit sum
			long val = 1;
			for (int i = 0; i < 30; i++) { // exponent
				val *= sum;
				if (digitSum(val) == sum && val >= 10 && validate(val)) {
					solutions.add(val);
				}
			}
		}
		Collections.sort(solutions);
		System.out.println(solutions.size());
		System.out.println(solutions);
		System.out.println(solutions.get(29));
	}
	public static long digitSum(long l) {
		long sum = 0;
		while (l != 0) {
			sum += l%10;
			l /= 10;
		}
		return sum;
	}
	public static boolean validate(long l) {
		long sum = digitSum(l);
		while (l != 1) {
			if (l % sum != 0) {
				return false;
			}
			l /= sum;
		}
		return true;
	}
}