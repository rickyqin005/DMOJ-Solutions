import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashSet<Integer> pointSet = new HashSet<Integer>();
		int N = Integer.parseInt(br.readLine());
		int[] pointArr = new int[N];
		int ans = 0;
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken())+20000, y = Integer.parseInt(st.nextToken())+20000;
			pointSet.add(41000*x+y);
			pointArr[i] = 41000*x+y;
		}
		for(int i = 0; i < N; i++) {
			for(int j = i+1; j < N; j++) {
				int x1 = pointArr[i] / 41000, y1 = pointArr[i] % 41000;
				int x2 = pointArr[j] / 41000, y2 = pointArr[j] % 41000;
				if(pointSet.contains(41000*x1+y2) && pointSet.contains(41000*x2+y1)) {
					ans = Math.max(ans, Math.abs((x2-x1)*(y2-y1)));
				}
			}
		}
		System.out.println(ans);
	}
}
