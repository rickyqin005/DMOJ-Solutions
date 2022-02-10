import java.io.*;
public class Question {
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String[] in = br.readLine().split(" ");
    	int N = Integer.parseInt(in[0]), K = Integer.parseInt(in[1]);
    	int[] cup = new int[N+1];
    	for(int i = 0; i < K; i++) {
    		cup[Integer.parseInt(br.readLine())+1]++;
    	}
    	for(int i = 1; i <= N; i++) {
    		cup[i] += cup[i-1];
    	}
    	int Q = Integer.parseInt(br.readLine());
    	for(int i = 0; i < Q; i++) {
    		in = br.readLine().split(" ");
    		System.out.println(cup[Integer.parseInt(in[1])+1]-cup[Integer.parseInt(in[0])]);
    	}
    }
}