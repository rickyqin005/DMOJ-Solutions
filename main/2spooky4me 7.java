import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()), L = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken())-1, b = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			if(map.containsKey(a)) map.replace(a, map.get(a)+s);
			else map.put(a, s);
			if(map.containsKey(b)) map.replace(b, map.get(b)-s);
			else map.put(b, -s);
		}
		LinkedList<Integer> street = new LinkedList<Integer>(map.keySet());
		Collections.sort(street);
		int ans = 0;
		int rangeStart = 0;
		int spookyness = 0;
		for(int i: street) {
			if(spookyness < S) ans += i-rangeStart;
			spookyness += map.get(i);
			rangeStart = i;
		}
		ans += L-rangeStart;
		System.out.println(ans);
	}
}
