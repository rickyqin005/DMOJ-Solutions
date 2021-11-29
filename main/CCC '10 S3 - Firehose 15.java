import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int H = nextInt(),i,j;
		int[] houses = new int[2*H];
		for(j = 0; j < H; j++) {
			houses[j] = nextInt();
			houses[H+j] = houses[j]+1000000;
		}
		int K = nextInt();
		if(K >= H) {System.out.println(0); return;}
		Arrays.sort(houses);
		
		int ans = 1000000;
		int low = 0, high = houses[H-1]-houses[0], mid = 0;
		int count, start, range;
		boolean valid;
		while(low < high) {
			mid = (low+high)/2;
			valid = false;
			for(i = 0; i < H; i++) {
				count = 1;
				range = 0;
				start = houses[i];
				for(j = i; j < H+i && count <= K; j++) {
					range = houses[j]-start;
					if(range > mid*2) {
						count++;
						start = houses[j];
						range = 0;
					}
				}
				if(count <= K) valid = true;
			}
			if(!valid) low = mid+1;
			else {
				high = mid;
				ans = Math.min(ans, mid);
			}
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