import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i;
		String str = nextLine();
		int[] freq2Idx = new int[26];
		Arrays.fill(freq2Idx, -1);
		for(i = N-1; i >= 0; i--) {
			if(freq2Idx[str.charAt(i)-97] == -1) {
				freq2Idx[str.charAt(i)-97] = i;
			}
		}
		
		int ans = 0;
		int curr = 0;
		boolean[] checked = new boolean[26];
		for(i = 0; i < N; i++) {
			if(i < freq2Idx[str.charAt(i)-97]) {
				if(!checked[str.charAt(i)-97]) {
					curr++;
					checked[str.charAt(i)-97] = true;
				}
			} else {
				if(checked[str.charAt(i)-97]) curr--;
			}
			ans = Math.max(ans, curr);
		}
		System.out.println(ans);
	}
	static long nextLong() throws IOException {return Long.parseLong(next());}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static double nextDouble() throws IOException {return Double.parseDouble(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}