import java.util.Scanner;
import java.util.ArrayList;
public class Q8 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int i = 0 ; i < 10 ; i++) {
			int n = input.nextInt();
			int[] where = new int[n];
			ArrayList<Integer> now = new ArrayList<Integer>();
			ArrayList<Integer> past = new ArrayList <Integer>();
			for(int j = 0 ; j < n ; j++) {
				int num = input.nextInt();
				where[num-1] = j;
				now.add(num);
			}
			int answer = 0;
			int whereLast = where[n-1];
			
			for(int j = n-2; j >= 0; j--) {
				int index = where[j];
				
				for(int i2 = 0; i2 < past.size(); i2++) {
					if(past.get(i2) > index) index++;
				}
				if(whereLast < index) {
					now.add(now.get(index),0);
					now.remove(index+1);
					past.add(index);
					answer += index;
					whereLast = 0;
				} else whereLast = index;
			}
			System.out.println(answer);
		}
	}
}