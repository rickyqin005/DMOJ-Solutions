import java.util.Scanner;
import java.util.Arrays;
public class Question {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] arr = {input.nextInt(),input.nextInt(),input.nextInt()};
		Arrays.sort(arr);
		int diff1 = arr[1] - arr[0];
		int diff2 = arr[2] - arr[1];
		switch(diff1/diff2) {
		case 0:
			System.out.println(arr[1] + diff1);
			break;
		case 1:
			System.out.println(arr[2] + diff1);
			break;
		case 2: 
			System.out.println(arr[0] + diff2);
		}
	}
}