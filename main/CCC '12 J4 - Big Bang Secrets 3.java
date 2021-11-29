import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int K = Integer.parseInt(br.readLine());
		char[] str = br.readLine().toCharArray();
		for(int i = 0; i < str.length; i++) {
			System.out.print((char)((260+str[i]-65-K-3*(i+1))%26+65));
		}
		System.out.println();
	}
}