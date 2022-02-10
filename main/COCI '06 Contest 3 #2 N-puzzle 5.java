import java.util.Scanner;
public class Question2 { 
    public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
    	char[][] original = {
    			{'A','B','C','D'},
    			{'E','F','G','H'},
    			{'I','J','K','L'},
    			{'M','N','O','.'},
    	};
    	char[][] current = new char[4][];
    	int scatter = 0;
        for(int i = 0; i < 4; i++) {
        	current[i] = input.next().toCharArray();
        }
        for(int i = 0; i < 4; i++) {
        	for(int j = 0; j < 4; j++) {
        		if(original[i][j] == '.') continue;
        		for(int k = 0; k < 4; k++) {
        			for(int l = 0; l < 4; l++) {
        				if(current[k][l] == original[i][j] ) scatter += Math.abs(l-j) + Math.abs(k-i);
        			}
        		}
        	}
        }
        System.out.println(scatter);
    } 
}