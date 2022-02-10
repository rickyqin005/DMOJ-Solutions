import java.util.Arrays;
import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] num = new int[3];
        for(int i = 0; i < 3; i++) {
        	num[i] = input.nextInt();
        }
        Arrays.sort(num);
        String[] order = input.next().split("");
        for(int i = 0; i < 3; i++) {
        	switch(order[i]) {
        	case "A": System.out.print(num[0]+" ");
        		break;
        	case "B": System.out.print(num[1]+" ");
        		break;
        	case "C": System.out.print(num[2]+" ");
        	}
        }
        System.out.println();
    }
}