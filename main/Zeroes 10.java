import java.io.*;
import java.math.BigInteger;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		BigInteger ans = new BigInteger("1");
		for(int i = 2; i <= n; i++) {
			ans = ans.multiply(new BigInteger(String.valueOf(i)));
		}
		System.out.println(ans.toString().replaceAll("[^0]","").length());
	}
}
