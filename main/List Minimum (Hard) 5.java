import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i < N; i++) {
        	list.add(input.nextInt());
        }
        Collections.sort(list);
        for(int i = 0; i < N; i++) {
        	System.out.println(list.get(i));
        }
    }
}