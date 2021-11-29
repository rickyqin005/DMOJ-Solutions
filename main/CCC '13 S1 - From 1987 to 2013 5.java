import java.util.Scanner;
public class CCC_13_S1_From_1987_to_2013 {
	public static boolean isDistinct(String[] arr) {
		for(int i = 0; i < arr.length-1; i++) {
			for(int j = i+1; j < arr.length; j++) {
				if(arr[i].equals(arr[j])) return false;
			}
		}
		return true;
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int year = input.nextInt()+1;
        while(!isDistinct(Integer.toString(year).split(""))) {
        	year++;
        }
        System.out.println(year);
    }
}