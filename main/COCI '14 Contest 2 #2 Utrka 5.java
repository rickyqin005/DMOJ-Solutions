import java.util.HashMap;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<String,Integer> map = new HashMap<String,Integer>();
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N; i++) {
			String name = br.readLine();
			if(map.containsKey(name)) map.replace(name, map.get(name)+1);
			else map.put(name, 1);
		}
		for(int i = 0; i < N-1; i++) {
			String name = br.readLine();
			int num = map.get(name);
			if(num == 1) map.remove(name);
			map.replace(name, num-1);
		}
		for(String i: map.keySet()) {
			System.out.println(i);
		}
	}
}