import java.util.Scanner;
import java.util.Arrays;
public class CCC_13_J4_Time_on_task {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		int C = input.nextInt();
		int[] chore = new int[C];
		for(int i = 0; i < C; i++) {
			chore[i] = input.nextInt();
		}
		Arrays.sort(chore);
		int ans = 0;
		int time = 0;
		while(time <= T) {
			if(time + chore[ans] > T) break;
			time += chore[ans];
			ans++;
		}
		System.out.println(ans);
	}
}