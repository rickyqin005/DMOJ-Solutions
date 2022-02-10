import java.io.*;
import java.util.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		char[] A = br.readLine().toCharArray();
		char[] B = br.readLine().toCharArray();
		int ans = 0;
		boolean prevEqual = true;
		for(int i = 0; i < N; i++) {
			if(A[i] != B[i]) {
				if(prevEqual) {
					ans++;
					prevEqual = false;
				}
			} else {
				prevEqual = true;
			}
		}
		System.out.println(ans);
	}
}