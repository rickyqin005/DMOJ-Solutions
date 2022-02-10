import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	int N = in.nextInt();
    	int ans = 0;
    	ans += (N / 8) * 15;
    	N %= 8;
    	if(N == 0) ans--;
    	for(int i = 0; i < 15; i++) {
    		if(i % 3 != 0 && i % 5 != 0) N--;
    		if(N == 0) {
    			ans += i; break;
    		}
    	}
    	System.out.println(ans);
    }
}