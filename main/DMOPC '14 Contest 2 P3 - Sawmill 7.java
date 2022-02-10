import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
public class Sawmill {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		ArrayList<Integer>e = new ArrayList<Integer>();
		ArrayList<Integer>l = new ArrayList<Integer>();
		long total = 0;
		for(int i = 0; i < N; i++) {
			e.add(input.nextInt());
		}
		for(int i = 0; i < N; i++) {
			l.add(input.nextInt());
		}
		Collections.sort(e);
		Collections.sort(l);
		for(int i = 0; i < N; i++) {
			total += e.get(i) * l.get(N - 1 - i);
		}
		System.out.println(total);
	}
}