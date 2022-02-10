import java.io.*;
import java.util.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()), A = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int[][] schedule = new int[2*(A+C)][2];
		int i = 0;
		for(; i < A; i++) {
			st = new StringTokenizer(br.readLine());
			schedule[2*i][0] = Integer.parseInt(st.nextToken())-1;
			schedule[2*i][1] = 1;
			schedule[2*i+1][0] = Integer.parseInt(st.nextToken());
			schedule[2*i+1][1] = 2;
		}
		for(; i < A+C; i++) {
			st = new StringTokenizer(br.readLine());
			schedule[2*i][0] = Integer.parseInt(st.nextToken())-1;
			schedule[2*i][1] = 3;
			schedule[2*i+1][0] = Integer.parseInt(st.nextToken());
			schedule[2*i+1][1] = 4;
		}
		
		Arrays.sort(schedule, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0], b[0]);
			}
		});
		
		int ans = 0;
		int commitments = 0;
		int streams = 0;
		int prev = 0;
		for(i = 0; i < 2*(A+C); i++) {
			if(commitments == 0 && streams > 0) ans += schedule[i][0]-prev;
			switch(schedule[i][1]) {
			case 1: streams++; break;
			case 2: streams--; break;
			case 3: commitments++; break;
			case 4: commitments--; break;
			}
			prev = schedule[i][0];
		}
		System.out.println(ans);
	}
}