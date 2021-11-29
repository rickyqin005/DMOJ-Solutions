import java.io.*;
import java.util.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), D = Integer.parseInt(in[1]);
		int[] num = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		int[] sumArr = new int[N+1];
		for(int i = 1; i <= N; i++) {
			sumArr[i] = sumArr[i-1] + num[i-1];
		}
		
		int start = 0, end = N-1;
		for(int i = 0; i < D; i++) {
			int partition = Integer.parseInt(br.readLine());
			if(sumArr[partition+start]-sumArr[start] >= sumArr[end+1]-sumArr[partition+start]) {
				System.out.println(sumArr[partition+start]-sumArr[start]);
				start += partition;
			} else {
				System.out.println(sumArr[end+1]-sumArr[partition+start]);
				end = start+partition-1;
			}
		}
	}
}