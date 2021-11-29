import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int type = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        int[] dmoj = new int[N];
        int[] peg = new int[N];
        int ans = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
        	dmoj[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
        	peg[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(dmoj);
        Arrays.sort(peg);
        if(type == 1) {
        	for(int i = 0; i < N; i++) {
        		ans += Math.max(dmoj[i], peg[i]);
        	}
        } else {
        	for(int i = 0; i < N/2; i++) {
        		ans += Math.max(dmoj[i], peg[N-i-1]) + Math.max(peg[i], dmoj[N-i-1]);
        	}
        	if(N%2 == 1) ans += Math.max(dmoj[N/2], peg[N/2]);
        }
        System.out.println(ans);
    }
}