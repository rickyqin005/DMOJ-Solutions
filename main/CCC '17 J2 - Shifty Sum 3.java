import java.util.Scanner;
public class CCC_17_J2_Shifty_Sum {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int k = input.nextInt();
		long sum = N;
		for(int i = 0; i < k; i++) {
			sum += 10*N;
			N *= 10;
		}
		System.out.println(sum);
	}
}