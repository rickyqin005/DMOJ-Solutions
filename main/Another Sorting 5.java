import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Integer[] arr = new Integer[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
        	arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr, new Comparator<Integer>() {
        	public int compare(Integer a, Integer b) {
        		if(a%10 == b % 10) return Integer.compare(a, b)*-1;
        		return Integer.compare(a%10, b%10);
        	}
        });
        System.out.print(arr[0]);
        for(int i = 1; i < N; i++) {
        	System.out.print(" "+arr[i]);
        }
    }
}
