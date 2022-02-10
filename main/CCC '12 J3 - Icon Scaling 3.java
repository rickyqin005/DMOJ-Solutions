import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(br.readLine());
		String[][] icon = {
				{"*","x","*"},
				{" ","x","x"},
				{"*"," ","*"}
		};
		for(int i = 0; i < 3*k; i++) {
			for(int j = 0; j < 3*k; j++) {
				System.out.print(icon[i/k][j/k]);
			}
			System.out.println();
		}
	}
}