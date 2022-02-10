import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer,Boolean> map = new HashMap<Integer,Boolean>();
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
        	int num = Integer.parseInt(st.nextToken());
        	if(map.containsKey(num)) map.replace(num, true);
        	else map.put(num, false);
        }
        Object[] arr = map.keySet().toArray();
        Arrays.sort(arr);
        int ans = 0;
        for(int i = 0; i < arr.length-1; i++) {
        	int j = map.get(arr[i]) ? i : i+1;
        	for(; j < arr.length; j++) {
        		if(map.containsKey((int)arr[i]+(int)arr[j])) ans++;
        	}
        }
        if(ans == 0) System.out.println(-1);
        else System.out.println(ans);
    }
}