import java.io.*;
import java.util.LinkedHashMap;
import java.util.LinkedList;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		LinkedHashMap<String,LinkedList<Integer>> type = new LinkedHashMap<String,LinkedList<Integer>>();
		int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) {
			type.put(br.readLine(), new LinkedList<Integer>());
		}
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N; i++) {
			type.get(br.readLine()).add(i+1);
		}
		for(String i: type.keySet()) {
			for(int j: type.get(i)) {
				System.out.println(j);
			}
		}
	}
}