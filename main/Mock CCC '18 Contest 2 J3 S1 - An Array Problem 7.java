import java.io.*;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long sum = 0;
        int max = 0;
        for(int i = 0; i < N; i++) {
        	int num = Integer.parseInt(br.readLine());
        	sum += num;
        	max = Math.max(max,num);
        }
        System.out.println(Math.min(sum-max,sum/2));
    }
}