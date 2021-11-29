import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] city = new int[5];
		city[0] = 0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 1; i < 5; i++) {
			city[i] = Integer.parseInt(st.nextToken()) + city[i-1];
		}
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				System.out.print(Math.abs(city[i] - city[j]));
				if(j < 5-1) System.out.print(" ");
			}
			System.out.println();
		}
	}
}