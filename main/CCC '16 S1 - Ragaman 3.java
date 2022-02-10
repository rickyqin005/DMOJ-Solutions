import java.util.Scanner;
import java.util.ArrayList;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        char[] str1 = input.next().toCharArray();
        char[] str2 = input.next().replaceAll("[*]", "").toCharArray();
        ArrayList<Character> list1 = new ArrayList<Character>();
        ArrayList<Character> list2 = new ArrayList<Character>();
        int numAsterisk = str1.length-str2.length;
        for(int i = 0; i < str1.length; i++) {
        	list1.add(str1[i]);
        }
        for(int i = 0; i < str2.length; i++) {
        	list2.add(str2[i]);
        }
        outer:for(int i = 0; i < list2.size(); i++) {
        	for(int j = i; j < list1.size(); j++) {
        		if(list2.get(i) == list1.get(j)) {
        			list2.remove(i);
        			list1.remove(j);
        			i--;
        			continue outer;
        		}
        	}
        }
        if(list1.size() > numAsterisk) System.out.println("N");
        else System.out.println("A");
    }
}