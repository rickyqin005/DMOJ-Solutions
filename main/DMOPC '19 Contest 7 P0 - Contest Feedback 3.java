import java.util.Scanner;
public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] aver = {input.nextInt(),input.nextInt(),input.nextInt(),input.nextInt()};
        for(int i = 0; i < 4; i++) {
        	for(int j = i+1; j < 4; j++) {
        		System.out.printf("%.06f\n", (double)(aver[i]+aver[j])/2);
        	}
        }
        for(int i = 0; i < 4; i++) {
        	for(int j = i+1; j < 4; j++) {
        		for(int k = j+1; k < 4; k++) {
        			System.out.printf("%.06f\n", (double)(aver[i]+aver[j]+aver[k])/3);
        		}
        	}
        }
        System.out.printf("%.06f\n", (double)(aver[0]+aver[1]+aver[2]+aver[3])/4);
    }
}