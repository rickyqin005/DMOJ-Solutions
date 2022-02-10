import java.io.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine())%26;
		char[] str = br.readLine().toCharArray();
		for(int i = 0; i < str.length; i++) {
			char curr = str[i];
			if(curr > 96) System.out.print((char)((curr-97+26-N)%26+97));
			else if(curr > 64) System.out.print((char)((curr-65+26-N)%26+65));
			else System.out.print(" ");
		}
		System.out.println();
	}
}