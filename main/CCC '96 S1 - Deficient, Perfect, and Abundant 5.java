import java.io.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N; i++) {
			int num = Integer.parseInt(br.readLine());
			int ans = 1;
			int sqrt = (int)Math.sqrt(num);
			for(int j = 2; j <= sqrt; j++) {
				if(num % j == 0) {
					ans += j + num/j;
				}
			}
			if(sqrt*sqrt == num) ans -= sqrt;
			if(ans < num) System.out.println(num + " is a deficient number.");
			else if(ans == num) System.out.println(num +  " is a perfect number.");
			else System.out.println(num + " is an abundant number.");
		}
	}
}