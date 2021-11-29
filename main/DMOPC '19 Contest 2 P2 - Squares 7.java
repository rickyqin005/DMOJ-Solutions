import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int N = Integer.parseInt(in[0]), M = Integer.parseInt(in[1]);
        int[][] arr = new int[N][M];
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr[0][0] = Integer.parseInt(st.nextToken());
        for(int j = 1; j < M; j++) {
    		arr[0][j] = arr[0][j-1] + Integer.parseInt(st.nextToken());
    	}
        for(int i = 1; i < N; i++) {
        	st = new StringTokenizer(br.readLine());
        	arr[i][0] = arr[i-1][0] + Integer.parseInt(st.nextToken());
        	for(int j = 1; j < M; j++) {
        		arr[i][j] = Math.min(arr[i-1][j], arr[i][j-1]) + Integer.parseInt(st.nextToken());
        	}
        }
        System.out.println(arr[N-1][M-1]);
    }
}