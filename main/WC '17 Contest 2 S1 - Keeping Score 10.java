import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int L = Integer.parseInt(in[0]), G = Integer.parseInt(in[1]);
        int LG = L+G;
        int[][] arr = new int[LG][2];
        for(int i = 0; i < L; i++) {
        	arr[i][0] = Integer.parseInt(br.readLine());
        	arr[i][1] = 0;
        }
        for(int i = L; i < LG; i++) {
        	arr[i][0] = Integer.parseInt(br.readLine());
        	arr[i][1] = 1;
        }
        Arrays.sort(arr, new Comparator<int[]>() {
        	public int compare(int[]a, int[]b) {
        		if(a[0] == b[0]) return Integer.compare(a[1], b[1]);
        		return Integer.compare(a[0], b[0])*-1;
        	}
        });
        
        int numL = 0, numG = 0;
        for(int i = 0; i < LG; i++) {
        	if(arr[i][1] == 0) numL++;
        	else numG++;
        	if(numG > numL) {System.out.println(arr[i][0]); return;}
        }
        System.out.println(-1);
    }
}