import java.util.Scanner;
import java.util.HashSet;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        for(int i = 0; i < 10; i++) {
        	HashSet<String> set = new HashSet<String>();
        	int N = input.nextInt();
        	for(int j = 0; j < N; j++) {
        		String[] email = input.next().toLowerCase().replaceAll("\\+[a-zA-Z0-9.]*","").split("@");
        		email[0] = email[0].replace(".","");
        		set.add(email[0]+"@"+email[1]);
        	}
        	System.out.println(set.size());
        }
    }
}