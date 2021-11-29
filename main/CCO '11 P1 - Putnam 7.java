import java.io.*;
import java.util.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		int start = 1;
		double[][] score = new double[N][2];
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			score[i][0] = Double.parseDouble(st.nextToken());
			score[i][1] = Double.parseDouble(st.nextToken());
		}
		Arrays.sort(score, (a,b) -> Double.compare(a[0], b[0])*-1);
		System.out.print("");
		double check = Double.parseDouble(br.readLine());
		for(int i = 0; i < N; i++) {
			if(score[i][0] == check) {
				System.out.println(start);
				System.out.println((int)(start+(score[i][1]-start)*2));
				return;
			}
			start += (score[i][1]-start)*2+1;
		}
	}
}