import java.io.*;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int numS = 0, numT = 0;
        for(int i = 0; i < N; i++) {
        	String str = br.readLine().replaceAll("[^T^t^S^s]","");
        	int num = str.length();
        	str = str.replaceAll("[Tt]","");
        	numS += str.length();
        	numT += num-str.length();
        }
        if(numS >= numT) System.out.println("French");
        else System.out.println("English");
    }
}