import java.util.*;
public class problem93 {
	static ArrayList<String> permutations = new ArrayList<>();
	static ArrayList<String> ops = new ArrayList<>();
	static TreeSet<Long> answers = new TreeSet<>();
	public static void main(String[] args) {
		generateOps("", 0);
		int beststreak = 0;
		String bestString = "";
		for (int a = 1; a < 10; a++) {
			for (int b = a+1; b < 10; b++) {
				for (int c = b+1; c < 10; c++) {
					for (int d = c+1; d < 10; d++) {
						permutations.clear();
						answers.clear();
						String ans = ""+a+b+c+d;
						generatePermutations(ans, 0);
						for (String perm : permutations) {
							for (String op : ops) {
								process(perm, op);
							}
						}
						long firstOut = 1;
						while(answers.contains(firstOut)) firstOut++;
						
						if (firstOut-1 > beststreak) {
							beststreak = (int)(firstOut-1);
							bestString = ans;
						}
					}
				}
			}
		}
		System.out.println(bestString);
		System.out.println("Forms all integers up to "+beststreak);
	}
	public static void process(String perm, String op) {
		for (int run = 0; run < 2; run++) {
			ArrayList<Double> vals = new ArrayList<>();
			for (int j = 0; j < 4; j++) {
				vals.add(Double.parseDouble(perm.substring(j,j+1)));
			}
			for (int i = 0; i < 3; i++) {
				double d1; double d2;
				if (run == 1 && i == 1) {
					d1 = vals.get(1);
					d2 = vals.get(2);
					vals.remove(1);
					vals.remove(1);
				}
				else {
					d1 = vals.get(0);
					d2 = vals.get(1);
					vals.remove(0);
					vals.remove(0);
				}
				if (op.charAt(i) == '1') {
					vals.add(0,d1+d2);
				} else if (op.charAt(i) == '2') {
					vals.add(0,d1-d2);
				} else if (op.charAt(i) == '3') {
					vals.add(0,d1*d2);
				} else {
					vals.add(0,d1/d2);
				}
			}
			double answer = vals.get(0);
			if (Math.abs(answer-Math.round(answer)) < 1e-6 && answer > 0) {
				answers.add(Math.round(answer));
			}
		}
	}
	public static void generateOps(String s, int depth) {
		if (depth >= 3) ops.add(s);
		else {
			for (int i = 1; i <= 4; i++) {
				generateOps(s + i, depth+1);
			}
		}
	}
	public static void generatePermutations(String s, int depth) {
		if (depth >= 3) permutations.add(s);
		else {
			for (int i = depth; i < s.length(); i++) {
				String swapped = swap(s,depth,i);
				generatePermutations(swapped, depth+1);
			}
		}
	}
	public static String swap(String s, int i, int j) {
		if (i == j) return s;
		if (i > j) {
			int temp = i;
			i = j;
			j = temp;
		}
		String ans = s.substring(0,i);
		ans += s.charAt(j);
		ans += s.substring(i+1,j);
		ans += s.charAt(i);
		ans += s.substring(j+1);
		return ans;
	}
}