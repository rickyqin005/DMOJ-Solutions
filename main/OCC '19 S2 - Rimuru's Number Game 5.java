import java.util.Scanner;
public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int ans = 0;
        String[] N = input.next().split("");
        ans += (int)Math.pow(2, N.length)-2;
        for(int i = 0; i < N.length; i++) {
        	int digit = Integer.parseInt(N[i]);
        	if(digit > 3) {
        		ans += (int)Math.pow(2, N.length-i); break;
        	} else if(digit < 2) break;
        	else if(digit == 3) ans += (int)Math.pow(2, N.length-i-1);
        }
        boolean contains23 = true;
        for(int i = 0; i < N.length; i++) {
        	if(!N[i].equals("2") && !N[i].equals("3")) {
        		contains23 = false; break;
        	}
        }
        if(contains23) ans++;
        System.out.println(ans);
    }
}