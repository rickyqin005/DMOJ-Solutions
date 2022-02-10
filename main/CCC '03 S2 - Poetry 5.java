import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        input.nextLine();
        for(int i = 0; i < N; i++) {
        	String[] rhyme = new String[4];
        	String[][] verse = new String[4][];
        	for(int j = 0; j < 4; j++){
        		verse[j] = input.nextLine().toLowerCase().split("");
        	}
        	line: for(int j = 0; j < 4; j++) {
	        	for(int k = verse[j].length-1; k >= 0; k--) {
	        		String letter = verse[j][k];
	        		if(letter.equals("a") || letter.equals("e") || letter.equals("i") || letter.equals("o") || letter.equals("u") || letter.equals(" ") || k == 0) {
	        			String end = "";
	        			for(int l = k; l < verse[j].length; l++) {
	        				end += verse[j][l];
	        			}
	        			rhyme[j] = end;
	        			continue line;
	        		}
	        	}
        	}
        	if(rhyme[0].equals(rhyme[1]) && rhyme[0].equals(rhyme[2]) && rhyme[0].equals(rhyme[3])) {
        		System.out.println("perfect");
        	} else if(rhyme[0].equals(rhyme[1]) && rhyme[2].equals(rhyme[3])) {
        		System.out.println("even");
        	} else if(rhyme[0].equals(rhyme[2]) && rhyme[1].equals(rhyme[3])) {
        		System.out.println("cross");
        	} else if(rhyme[0].equals(rhyme[3]) && rhyme[1].equals(rhyme[2])) {
        		System.out.println("shell");
        	} else System.out.println("free");
        }
    }
}