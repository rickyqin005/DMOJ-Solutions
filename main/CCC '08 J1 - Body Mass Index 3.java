import java.util.Scanner;
public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double w = input.nextDouble();
        double h = input.nextDouble();
        double ans = w / (h*h);
        if(ans < 18.5) System.out.println("Underweight");
        else if(ans <= 25) System.out.println("Normal weight");
        else System.out.println("Overweight");
    }
}