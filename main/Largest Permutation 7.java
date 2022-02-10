import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), K = Integer.parseInt(in[1]);
		int[] arr = new int[N];
		int[] indexArr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr[i] = num;
			indexArr[num-1] = i;
		}
		int numSwaps = 0;
		for(int i = 0; i < N; i++) {
			if(arr[i] != N-i) {
				int temp1 = arr[i];
				arr[i] = N-i;
				arr[indexArr[N-i-1]] = temp1;
				
				int temp2 = indexArr[N-i-1];
				indexArr[N-i-1] = i;
				indexArr[temp1-1] = temp2;
				numSwaps++;
			}
			if(numSwaps == K) break;
		}
		
		System.out.print(arr[0]);
		for(int i = 1; i < N; i++) {
			System.out.print(" "+arr[i]);
		}
		System.out.println();
	}
}