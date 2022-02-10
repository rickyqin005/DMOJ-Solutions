import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 5; i++) {
			int N = Integer.parseInt(br.readLine());
			String[] dictionary = new String[N];
			for(int j = 0; j < N; j++) {
				dictionary[j] = br.readLine();
			}
			for(int j = 0; j < 5; j++) {
				String regex = br.readLine().replace("*", ".*").replace("?", ".");
				int numMatches = 0;
				for(int k = 0; k < N; k++) {
					if(dictionary[k].matches(regex)) {
						if(numMatches != 0) System.out.print(", ");
						System.out.print(dictionary[k]);
						numMatches++;
					}
				}
				if(numMatches == 0) System.out.println("NO MATCH");
				else System.out.println();
			}
			
		}
	}
}