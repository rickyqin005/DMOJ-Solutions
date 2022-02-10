import java.util.Scanner;
public class Question2 { 
    public static void recurse(int n,String rod1,String rod2,String rod3) { 
    	if (n == 1) System.out.println(rod1 + rod3);
    	else {
	        recurse(n-1,rod1,rod3,rod2);
	        System.out.println(rod1 + rod3);
	        recurse(n-1,rod2,rod1,rod3); 
        }
    } 
    public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        recurse(n,"A","B","C");
    } 
}