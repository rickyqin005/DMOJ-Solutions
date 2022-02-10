import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++) {
			int numS = Integer.parseInt(br.readLine());
			int numV = Integer.parseInt(br.readLine());
			int numO = Integer.parseInt(br.readLine());
			String[] S = new String[numS];
			String[] V = new String[numV];
			String[] O = new String[numO];
			for(int j = 0; j < numS; j++) {
				S[j] = br.readLine();
			}
			for(int j = 0; j < numV; j++) {
				V[j] = br.readLine();
			}
			for(int j = 0; j < numO; j++) {
				O[j] = br.readLine();
			}
			for(int j = 0; j < numS; j++) {
				for(int k = 0; k < numV; k++) {
					for(int l = 0; l < numO; l++) {
						System.out.println(S[j]+" "+V[k]+" "+O[l]+".");
					}
				}
			}
		}
	}
}