import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 5; i++) {
			ArrayList<String> text = new ArrayList<String>();
			String str = br.readLine();
			for(int j = 0; j < str.length(); j++) {
				char currChar = str.charAt(j);
				if(currChar == '\'' || currChar == '"') {
					j++;
					StringBuilder block = new StringBuilder(str.length());
					while(str.charAt(j) != currChar) {
						block.append(str.charAt(j));
						j++;
					}
					text.add(block.toString());
				} else if(j != str.length()-1) {
					if(currChar == '/' && str.charAt(j+1) == '/') {
						StringBuilder block = new StringBuilder(str.length());
						for(j += 2; j < str.length(); j++) {
							block.append(str.charAt(j));
						}
						text.add(block.toString());
					} else if(currChar == '/' && str.charAt(j+1) == '*') {
						StringBuilder block = new StringBuilder(str.length());
						for(j += 2; j < str.length()-2; j++) {
							block.append(str.charAt(j));
							if(str.charAt(j+1) == '*' && str.charAt(j+2) == '/') {
								j += 2; break;
							}
						}
						text.add(block.toString());
					}
				}
			}
			int count = 0;
			for(String j: text) {
				if(count > 0) System.out.print(" ");
				System.out.print(j);
				count++;
			}
			System.out.println();
		}
	}
}