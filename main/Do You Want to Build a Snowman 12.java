import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] top = {
        	 "          |",
		     "       \\  |  /",
		     "        \\ | /",
		     "         \\|/",
		     "       XXXXXXX",
		     "      X       X",
		     "     X  O   O  X",
		     "    X     V     X",
		     "W   X  X     X  X",
		     " \\   X  XXXXX  X",
		     "  \\   X       X",
		     "   \\   XXXXXXX",
		     "    \\ X       X---",
		     "     X    O    X  \\",
		     "    X           X  \\",
		     "     XXXXXXXXXXX    \\",
        };
        for(int i = 0; i < 5; i++) {
        	int N = Integer.parseInt(br.readLine());
        	int leadingSpace = 0;
        	if(N < 3);
        	else if(N == 3) leadingSpace = 1;
        	else leadingSpace = 1+(4+N)*(N-4+1)/2;
        	for(int j = 0; j < top.length; j++) {
        		for(int l = 0; l < leadingSpace; l++) System.out.print(" ");
        		System.out.println(top[j]);
        	}
        	int torsoBottom = 11;
        	leadingSpace = (N == 2) ? 2 : (3+N)*(N-3+1)/2;
        	for(int j = 2; j <= N; j++) {
        		for(int k = 0; k < j+2; k++) {
        			for(int l = 0; l < leadingSpace; l++) System.out.print(" ");
        			for(int l = 1+j-k; l > 0; l--) System.out.print(" ");
        			System.out.print("X");
        			for(int l = 0; l < torsoBottom-2+2*k; l++) {
        				if(l == (torsoBottom-2+2*k)/2 && k != 0 && k != j+1) System.out.print("O");
        				else System.out.print(" ");
        			}
        			System.out.print("X");
        			if(j == 2 && k == 0) System.out.print("     M");
        			System.out.println();
        		}
        		torsoBottom += j*2;
        		for(int l = 0; l < leadingSpace; l++) System.out.print(" ");
        		System.out.print(" ");
        		for(int k = 0; k < torsoBottom; k++) System.out.print("X");
        		System.out.println();
        		leadingSpace -= j+1;
        	}
        	if(N < 3) leadingSpace = 6;
        	else leadingSpace = torsoBottom/2-3;
        	for(int l = 0; l < leadingSpace; l++) System.out.print(" ");
        	System.out.print("OOOO OOOO");
        	if(N == 1) System.out.print("      M");
        	System.out.println();
        	for(int l = 0; l < leadingSpace; l++) System.out.print(" ");
        	System.out.println("OOOO OOOO");
        	if(i != 4) System.out.println();
        }
    }
}