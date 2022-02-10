import java.util.Scanner;
import java.util.Arrays;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] present = new int[N];
        int ans = 1;
        for(int i = 0; i < N; i++) {
        	present[i] = input.nextInt();
        }
        Arrays.sort(present);
        int sumBefore = present[0];
        for(int i = 1; i < N; i++) {
        	if(sumBefore > present[i]) continue;
        	else {
        		sumBefore += present[i];
        		ans++;
        	}
        }
        System.out.println(ans);
    }
}