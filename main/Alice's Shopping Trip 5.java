import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken());
		Integer[] stores = new Integer[N];
		int dist = 0, prev = 0;
		int ans = 0;
		for(int i = 0; i < N; i++) {
			stores[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(stores, (a,b) -> Integer.compare(Math.abs(a),Math.abs(b)));
		for(int i = 0; i < N; i++) {
			int curr = stores[i];
			if(dist + Math.abs(prev-curr) > T) break;
			dist += Math.abs(prev-curr);
			ans++;
			prev = curr;
		}
		System.out.println(ans);
	}
}