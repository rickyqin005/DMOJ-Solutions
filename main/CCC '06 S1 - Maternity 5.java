import java.io.*;
import java.util.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] in1 = br.readLine().toCharArray();
		char[] in2 = br.readLine().toCharArray();
		HashSet<Character> parent1 = new HashSet<Character>();
		HashSet<Character> parent2 = new HashSet<Character>();
		for(int i = 0; i < 10; i++) {
			parent1.add(in1[i]);
			parent2.add(in2[i]);
		}
		int X = Integer.parseInt(br.readLine());
		for(int i = 0; i < X; i++) {
			char[] baby = br.readLine().toCharArray();
			boolean isBaby = true;
			for(int j = 0; j < 5; j++) {
				if(baby[j] == 97+j) {
					if(!(parent1.contains(baby[j]) && parent2.contains(baby[j]))) {
						isBaby = false; break;
					}
				} else {
					if(!parent1.contains(baby[j]) && !parent2.contains(baby[j])) {
						isBaby = false; break;
					}
				}
			}
			if(isBaby) System.out.println("Possible baby.");
			else System.out.println("Not their baby!");
		}
	}
}