import java.util.Scanner;
import java.util.Arrays;
public class CCC_18_S1_Voronoi_Villages {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int arr[] = new int[N];
		double min = Integer.MAX_VALUE;
		for(int i = 0; i < N; i++) {
			arr[i] = input.nextInt();
		}
		Arrays.sort(arr);
		for(int i = 1; i < N-1; i++) {
			min = Math.min(min, (double)(arr[i+1] - arr[i-1])/2);
		}
		System.out.printf("%.1f", min);
	}
}