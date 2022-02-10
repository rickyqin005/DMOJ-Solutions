import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int max = 10000000, i, j;
		byte[] primacity = new byte[max+1];
		for(i = 2; i <= max; i+=2) {primacity[i]++;}
		for(i = 3; i <= max; i+=2) {
			if(primacity[i] != 0) continue;
			for(j = i; j <= max; j+=i) { primacity[j]++; }
		}
		int T = Integer.parseInt(br.readLine());
		for(i = 1; i <= T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken()), B = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken()), ans = 0;
			if(K == 8) {
				if(A <= 9699690 && B >= 9699690) ans = 1;
			} else if(K < 8) {
				for(; A <= B; A++) {if(primacity[A] == K) ans++;}
			}
			System.out.println("Case #"+i+": "+ans);
		}
	}
}