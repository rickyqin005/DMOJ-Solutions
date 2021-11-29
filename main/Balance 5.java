import java.io.*;
import java.util.*;
public class Question {
	static LinkedList<Integer> numbers = new LinkedList<Integer>();
	static int ans = Integer.MAX_VALUE, totalSum = 0;
	public static void recurse(int sum) {
		ans = Math.min(ans,Math.abs(sum-(totalSum-sum)));
		for(int i = 0; i < numbers.size(); i++) {
			int curr = numbers.remove(i);
			recurse(sum+curr);
			numbers.add(i, curr);
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[] in = br.readLine().split(" ");
		for(int i = 0; i < N; i++) {
			int num = Integer.parseInt(in[i]);
			numbers.add(num);
			totalSum += num;
		}
		recurse(0);
		System.out.println(ans);
	}
}
