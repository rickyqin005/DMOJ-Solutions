import java.util.Scanner;
public class Q2 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int K = input.nextInt();
		int N = input.nextInt();
		int[][] arr = new int[K][N];
		int ans = 0;
		for(int i = 0; i < K; i++) {
			for(int j = 0; j < N; j++) {
				int num = input.nextInt();
				arr[i][num-1] = j;
			}
		}
		for(int i = 0; i < N-1; i++) {
			comparison: for(int j = i+1; j < N; j++) {
				boolean performance = arr[0][i] > arr[0][j];
				for(int k = 1; k < K; k++) {
					if(arr[k][i] > arr[k][j] != performance) continue comparison;
				}
				ans++;
			}
		}
		System.out.println(ans);
	}
}