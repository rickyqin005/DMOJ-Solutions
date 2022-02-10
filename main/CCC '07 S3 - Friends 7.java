import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] friend = new int[10000];
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			friend[Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
		}
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int f1 = Integer.parseInt(st.nextToken()), f2 = Integer.parseInt(st.nextToken());
			if(f1 == 0 && f2 == 0) break;
			
			boolean isConnected = false;
			int ans = 0;
			int next = friend[f1];
			boolean[] visited = new boolean[10000];
			while(true) {
				if(next == f2) {
					isConnected = true; break;
				}
				if(visited[next]) break;
				visited[next] = true;
				next = friend[next];
				ans++;
			}
			if(isConnected) System.out.println("Yes "+ans);
			else System.out.println("No");
		}
	}
}