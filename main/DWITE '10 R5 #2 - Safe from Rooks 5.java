import java.io.*;
import java.util.HashSet;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 5; i++) {
			HashSet<String> rows = new HashSet<String>();
			HashSet<String> cols = new HashSet<String>();
			String[] in = br.readLine().split(" ");
			int R = Integer.parseInt(in[0]), C = Integer.parseInt(in[1]);
			int numRooks = Integer.parseInt(in[2]);
			for(int j = 0; j < numRooks; j++) {
				in = br.readLine().split(" ");
				rows.add(in[0]);
				cols.add(in[1]);
			}
			System.out.println((R-rows.size())*(C-cols.size()));
		}
	}
}