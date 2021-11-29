import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] key = br.readLine().replaceAll("[^A-Z]","").toCharArray();
		char[] message = br.readLine().replaceAll("[^A-Z]","").toCharArray();
		int keyLen = key.length;
		for(int i = 0; i < message.length; i ++) {
			System.out.print((char)((message[i]-65+key[i%keyLen]-65)%26+65));
		}
		System.out.println();
	}
}