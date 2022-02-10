import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String n = br.readLine();
		if(n.length() > 2) {System.out.println("999999998"); return;}
		int N = Integer.parseInt(n);
		if(N > 17) {System.out.println("999999998"); return;}
		if(N == 17) {System.out.println("99999998"); return;}
		if(N == 1) {System.out.println(9); return;}
		System.out.print(1);
		if(N % 2 == 1) System.out.print(0);
		for(int i = N/2-1; i > 0; i--) {
			System.out.print(9);
		}
		System.out.println(8);
	}
}