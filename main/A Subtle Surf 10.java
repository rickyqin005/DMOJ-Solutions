import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int D = Integer.parseInt(br.readLine());
		for(int i = 0; i < D; i++) {
			String[] in = br.readLine().split(" ");
			int N = Integer.parseInt(in[0]), C = Integer.parseInt(in[1]), T = Integer.parseInt(in[2]);
			LinkedList<Integer> list = new LinkedList<Integer>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			int selection = Integer.parseInt(st.nextToken());
			for(int j = 1; j < N; j++) {
				int num = Integer.parseInt(st.nextToken());
				if(num > selection) list.add(num);
			}
			Collections.sort(list);
			int ans = 0, prevNum = selection;
			selection -= C;
			for(int j: list) {
				if(j - prevNum > C) break;
				if(j - selection > C) {
					selection = prevNum;
					ans++;
				}
				
				prevNum = j;
			}
			System.out.println(prevNum + " " + ans*T);
		}
	}
}
