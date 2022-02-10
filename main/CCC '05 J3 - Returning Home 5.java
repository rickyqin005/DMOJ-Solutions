import java.io.*;
import java.util.ArrayList;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Boolean> dir = new ArrayList<Boolean>();
		ArrayList<String> street = new ArrayList<String>();
		street.add("HOME");
		while(true) {
			String str1 = br.readLine();
			String str2 = br.readLine();
			dir.add(str1.equals("R") ? true : false);
			if(str2.equals("SCHOOL")) break;
			street.add(str2);
		}
		for(int i = dir.size()-1; i >= 0; i--) {
			System.out.print("Turn " + (dir.get(i) ? "LEFT" : "RIGHT"));
			if(street.get(i).equals("HOME")) System.out.println(" into your HOME.");
			else System.out.println(" onto " + street.get(i) + " street.");
		}
	}
}