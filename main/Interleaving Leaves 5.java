import java.util.Scanner;
public class Q1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for(int i = 0; i < T; i++) {
			int N = input.nextInt();
			input.nextLine();
			String[] str1 = input.nextLine().split("");
			String[] str2 = input.nextLine().split("");
			for(int j = N-1; j >= 0; j--) {
				System.out.print(str2[j] + str1[j]);
			}
			System.out.println();
		}
	}
}
