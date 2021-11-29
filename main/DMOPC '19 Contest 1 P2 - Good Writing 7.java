import java.util.Scanner;
public class Question2 {
	static String str1 = "Good writing is good writing is good writing.";
	static String str2 = "Good writing is good ";
	static String str3 = " writing is good ";
	static String str4 = " is good writing.";
	public static long length(int lvl) {
		long len = 45;
        for(int i = 0; i < lvl; i++) {
        	len *= 2;
        	len += 55;
        }
        return len;
	}
	public static void findPosition(int n,long k) {
		if(n == 0) System.out.println(str1.charAt((int)k-1));
		else {
			long len = length(n-1);
			if(k > 2*len+55) System.out.println(".");
			else if(k <= 21) System.out.println(str2.charAt((int)k-1));
			else if(k <= 21+len) findPosition(n-1,k-21);
			else if(k <= 38+len) System.out.println(str3.charAt((int)(k-1-21-len)));
			else if(k <= 38+len+len) findPosition(n-1,k-38-len);
			else System.out.println(str4.charAt((int)(k-1-38-len*2)));
		}
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int q = input.nextInt();
        for(int i = 0; i < q; i++) {
        	findPosition(input.nextInt(),(long)input.nextInt());
        }
    }
}