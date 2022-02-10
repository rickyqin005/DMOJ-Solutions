import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str1 = br.readLine();
		String str2 = str1;
		int numHappy = 0, numSad = 0;
		while(str1.indexOf(":-)") != -1) {
			numHappy++;
			str1 = str1.substring(str1.indexOf(":-)")+3);
		}
		while(str2.indexOf(":-(") != -1) {
			numSad++;
			str2 = str2.substring(str2.indexOf(":-(")+3);
		}
		if(numHappy == numSad) {
			if(numHappy == 0) System.out.println("none");
			else System.out.println("unsure");
		} else if (numHappy > numSad) System.out.println("happy");
		else System.out.println("sad");
	}
}