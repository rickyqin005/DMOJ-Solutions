import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] people = new int[K];
		for(int i = 0; i < K; i++) {
			people[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(people);
		int remainder = K%M;
		int numFullRows = K/M;
		long ans = 0;
		for(int i = 1; i <= numFullRows; i++) {
			int prev = people[K-i];
			int count = i;
			for(int j = 1; j < M; j++) {
				count += numFullRows+(j <= remainder?1:0);
				int curr = people[K-count];
				if(curr <= prev) {
					ans += prev-curr+1;
					curr = prev+1;
				} else curr++;
				prev = curr;
			}
		}
		int prev = people[K-numFullRows-1];
		int count = numFullRows+1;
		for(int i = 1; i < remainder; i++) {
			count += numFullRows+1;
			int curr = people[K-count];
			if(curr <= prev) {
				ans += prev-curr+1;
				curr = prev+1;
			} else curr++;
			prev = curr;
		}
		
		System.out.println(ans);
	}
}