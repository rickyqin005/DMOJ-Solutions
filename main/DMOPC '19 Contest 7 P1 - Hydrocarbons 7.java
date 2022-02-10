import java.util.Scanner;
public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt(), b = input.nextInt(), c = input.nextInt(), d = input.nextInt();
        int carbon = a+b+c+1;
        int hydrogen = carbon*2+2-2*b-4*c;
        if(d != hydrogen) System.out.println("invalid");
        else System.out.println("C" + carbon + "H" + hydrogen);
    }
}