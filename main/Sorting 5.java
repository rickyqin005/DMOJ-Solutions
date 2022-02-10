import java.util.Arrays;
import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] num = new int[N];
        for(int i = 0; i < N; i++) {
        	num[i] = input.nextInt();
        }
        Arrays.sort(num);
        for(int i = 0; i < N; i++) {
        	System.out.println(num[i]);
        }
    }
}
