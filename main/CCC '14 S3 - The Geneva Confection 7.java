import java.util.Scanner;
import java.util.LinkedList;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int test = input.nextInt();
        test: for(int i = 0; i < test; i++) {
        	LinkedList<Integer> top = new LinkedList<Integer>();
        	LinkedList<Integer> branch = new LinkedList<Integer>();
        	int N = input.nextInt();
        	for(int j = 0; j < N; j++) {
        		top.addFirst(input.nextInt());
        	}
        	num: for(int j = 1; j <= N; j++) {
        		if(!branch.isEmpty()) {
        			if(branch.getFirst() == j) {
        				branch.pop(); continue num;
        			}
        		}
        		while(!top.isEmpty()) {
        			if(top.getFirst() == j) {
        				top.pop(); continue num;
        			}
        			branch.addFirst(top.pop());
        		}
        		if(top.isEmpty() && j < N) {
        			System.out.println("N"); continue test;
        		}
        	}
        	System.out.println("Y");
        }
    }
}