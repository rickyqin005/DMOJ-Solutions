import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int N = Integer.parseInt(in[0]), M = Integer.parseInt(in[1]);
        int[][] suggestions = new int[M][3];
        for(int i = 0; i < M; i++) {
        	in = br.readLine().split(" ");
        	suggestions[i][0] = in[0].charAt(0)-97;
        	suggestions[i][1] = Integer.parseInt(in[1]);
        	suggestions[i][2] = Integer.parseInt(in[2])-1;
        }
        Arrays.sort(suggestions, new Comparator<int[]>() {
        	public int compare(int[] a, int[] b) {
        		return Integer.compare(a[2], b[2]);
        	}
        });
        char[] str = new char[N];
        int[] letterRange = new int[26];
        int[] lettersUsed = new int[26];
        for(int i = 0; i < M; i++) {
	        int letterNum = suggestions[i][0];
	        char letter = (char)(letterNum+97);
	        int count = suggestions[i][1] - lettersUsed[letterNum];
	        if(count < 0) {System.out.println("-1"); return;}
	        if(suggestions[i][1] > suggestions[i][2]+1) {System.out.println("-1"); return;}
	        int index = letterRange[letterNum];
	        while(count > 0) {
	        	if(index == N || index > suggestions[i][2]) {System.out.println("-1"); return;}
	        	if(str[index] == '\0') {
	        		str[index] = letter; count--;
	        	}
	        	index++;
	        }
	        letterRange[letterNum] = suggestions[i][2]+1;
	        lettersUsed[letterNum] = suggestions[i][1];
        }
        int minLetterRange = Integer.MAX_VALUE;
        char minLetter = ' ';
        for(int i = 0; i < 26; i++) {
        	if(letterRange[i] < minLetterRange) {
        		minLetter = (char)(i+97);
        		minLetterRange = letterRange[i];
        	}
        }
        StringBuilder ans = new StringBuilder(N);
        for(int i = 0; i < N; i++) {
        	if(str[i] == '\0') {
        		if(i < minLetterRange) {System.out.println("-1"); return;}
        		ans.append(minLetter);
        	}
        	else ans.append(str[i]);
        }
        System.out.println(ans);
    }
}