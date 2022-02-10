import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        input.nextInt();
        int H = input.nextInt();
        int numBerries = 0;
        input.nextLine();
        for(int i = 0; i < H; i++) {
        	char[] bush = input.nextLine().toCharArray();
        	for(int j = 0; j < bush.length; j++) {
        		if(bush[j] == 'o') {
        			numBerries++;
        			bush[j] = ' ';
        		} else if(bush[j] == '*') bush[j] = ' ';
        		System.out.print(bush[j]);
        	}
        	System.out.println();
        }
        for(int i = 0; i < numBerries; i++) {
        	System.out.print('o');
        }
        System.out.println();
    }
}