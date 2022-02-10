import java.io.*;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] convert = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
        int t = Integer.parseInt(br.readLine());
        for(int i = 0; i < t; i++) {
        	char[] str = br.readLine().replaceAll("-","").toCharArray();
        	for(int j = 0; j < 10; j++) {
        		if(str[j] > 64) str[j] = (char)(convert[(int)str[j]-65]+48);
        		System.out.print(str[j]);
        		if(j == 2 || j == 5) System.out.print("-");
        	}
        	System.out.println();
        }
    }
}