import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int[] num = {Integer.parseInt(in[0]),Integer.parseInt(in[1]),
				Integer.parseInt(in[2]),Integer.parseInt(in[3])};
		java.util.Arrays.sort(num);
		System.out.println(num[0] * num[2]);
	}
}