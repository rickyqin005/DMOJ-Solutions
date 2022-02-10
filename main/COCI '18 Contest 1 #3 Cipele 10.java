import java.io.*;
import java.util.*;
public class Question3 {
	static int N, M;
	static int[] arr1, arr2;
	public static boolean check(int num) {
		int j = 0;
		for(int i = 0; i < N; i++, j++) {
                while(j < M && Math.abs(arr2[j]-arr1[i]) > num) j++;
                if(j >= M) return false;
        }
        return true;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr1 = new int[N];
		arr2 = new int[M];
		boolean[] isUsed = new boolean[M];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) { arr1[i] = Integer.parseInt(st.nextToken()); }
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < M; i++) { arr2[i] = Integer.parseInt(st.nextToken()); }
		
		if(N > M) {
			int[] temp1 = arr1;
			arr1 = arr2; arr2 = temp1;
			int temp2 = N;
			N = M; M = temp2;
		}
		
		Arrays.sort(arr1);
		Arrays.sort(arr2);
		int low = 0, high = 1000000000;
		int ans = 0;
		while(low <= high) {
        int mid = (low+high)/2;
        	if(check(mid)) {
        		high = mid-1;
        		ans = mid;
        	} else low = mid+1;
		}
		System.out.println(ans);
	}
}