import java.util.Scanner;
public class Question {
	static boolean[][] tunnel = new boolean[200][401];
	static int posR = -1;
    static int posC = 200;
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] path = {"d","d","d","r","r","r","d","d","r","r","u","u","r","r","d","d","d","d","l","l","l","l","l","l","l","l","u","u"};
        boolean isGood = true;
        for(int i = 0; i < path.length; i++) {
        	switch(path[i]) {
        	case "u": posR--;
        		break;
        	case "r": posC++;
        		break;
        	case "d": posR++;
        		break;
        	case "l": posC--;
        	}
    		tunnel[posR][posC] = true;
        }
        while(true) {
        	String dir = input.next();
        	if(dir.equals("q")) break;
        	int dist = input.nextInt();
        	for(int i = 0; i < dist; i++) {
        		switch(dir) {
            	case "u": posR--;
            		break;
            	case "r": posC++;
            		break;
            	case "d": posR++;
            		break;
            	case "l": posC--;
            	}
        		if(tunnel[posR][posC]) {
        			isGood = false;// break;
        		}
        		else tunnel[posR][posC] = true;
        	}
        	System.out.print((posC-200) + " " + (posR*-1-1));
        	if(isGood) System.out.println(" safe");
        	else {
        		System.out.println(" DANGER"); break;
        	}
        }
    }
}