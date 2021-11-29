import java.util.Scanner;
public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x = input.nextInt();
        int m = input.nextInt();
        boolean hasAns = false;
        int ans;
        for(ans = 1; ans < m; ans++) {
        	if((x*ans)%m == 1) {
        		hasAns = true; break;
        	}
        }
        if(hasAns) System.out.println(ans);
        else System.out.println("No such integer exists.");
    }
}