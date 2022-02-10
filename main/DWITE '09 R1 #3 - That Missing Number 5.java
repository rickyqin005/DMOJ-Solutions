import java.util.Scanner;
import java.util.Arrays;
public class Q1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int i = 0; i < 5; i++) {
			int M = input.nextInt();
			int[] num = new int[M];
			int ans = M+1;
			for(int j = 0; j < M; j++) {
				num[j] = input.nextInt();
			}
			Arrays.sort(num);
			for(int j = 0; j < M; j++) {
				if(num[j] != j+1) {
					ans = j+1; break;
				}
			}
			System.out.println(ans);
		}
	}
}