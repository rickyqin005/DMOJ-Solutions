import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int currNum = 2 - input.nextInt();
        int numDays = input.nextInt();
        System.out.println("Sun Mon Tue Wed Thr Fri Sat");
        outer: for(int i = 0; i < 6; i++) {
        	for(int j = 0; j < 7; j++) {
        		if(currNum > 0) {
        			if(Integer.toString(currNum).length() == 1) System.out.print("  ");
        			else System.out.print(" ");
        			System.out.print(currNum);
        		} else System.out.print("   ");
        		if(currNum == numDays) {
        			System.out.println();
        			break outer;
        		}
        		if(j < 7-1) System.out.print(" ");
        		currNum++;
        	}
        	System.out.println();
        }
    }
}