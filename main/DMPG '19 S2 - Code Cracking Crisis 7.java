import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] key = new int[10][10];
		for(int i = 0; i < 10; i++) {
			String in = br.readLine();
			for(int j = 0; j < 10; j++) {
				key[i][in.charAt(j)-48] = j;
			}
		}
		String str = br.readLine();
		int len = str.length();
		int prev = str.charAt(0)-48;
		System.out.print(prev);
		for(int i = 1; i < len; i++) {
			int decrypt = key[prev][str.charAt(i)-48];
			System.out.print(decrypt);
			prev = decrypt;
		}
		System.out.println();
	}
}