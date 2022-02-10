import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int R = Integer.parseInt(in[0]);
		int C = Integer.parseInt(in[1]);
		int[][] spreadsheet = new int[R][C];
		for(int i = 0; i < R; i++) {
			in = br.readLine().split(" ");
			for(int j = 0; j < C; j++) {
				spreadsheet[i][j] = Integer.parseInt(in[j]);
			}
		}
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N; i++) {
			int c = Integer.parseInt(br.readLine())-1;
			Arrays.sort(spreadsheet, (a,b) -> Integer.compare(a[c],b[c]));
		}
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C-1; j++) {
				System.out.print(spreadsheet[i][j]+ " ");
			}
			System.out.println(spreadsheet[i][C-1]);
		}
	}
}