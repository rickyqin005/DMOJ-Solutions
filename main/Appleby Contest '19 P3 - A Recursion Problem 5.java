import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] str = input.nextLine().replaceAll("[()+]", "").split(" ");
        int ans = 0;
        for(int i = 0; i < str.length; i++) {
        	try {
        		ans += Integer.parseInt(str[i]);
        	} catch(Exception e) {}
        }
        System.out.println(ans);
    }
}