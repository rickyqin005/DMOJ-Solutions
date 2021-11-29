import java.util.*;
public class CCC_15_S1_Zero_That_Out {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int K = input.nextInt();
		int sum = 0;
		LinkedList<Integer> list = new LinkedList<Integer>();
		for(int i = 0; i < K; i++) {
			int num = input.nextInt();
			if(num == 0) list.removeLast();
			else list.add(num);
		}
		for(int i: list) {
			sum += i;
		}
		System.out.println(sum);
	}
}