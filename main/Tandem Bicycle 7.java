import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()), W = Integer.parseInt(st.nextToken());
		int[] students = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			students[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(students);
		long ans = 0;
		for(int i = 0; i < N-1; i++) {
			int start = i+1, end = N;
			int curr = students[i];
			while(start < end) {
				int mid = (start+end)/2;
				if(students[mid] + curr > W) {
					if(mid == i+1) break;
					if(students[mid-1] + curr <= W) {
						ans += mid-i-1;
						break;
					}
					end = mid;
				} else {
					if(mid == N-1) {
						ans += mid-i;
						break;
					}
					if(students[mid+1] + curr > W) {
						ans += mid-i;
						break;
					}
					start = mid+1;
				}
			}
		}
		System.out.println(ans);
	}
}