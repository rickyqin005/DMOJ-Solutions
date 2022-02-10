import java.io.*;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine().replaceAll("[IOSHZXN]","");
        if(str.length() == 0) System.out.println("YES");
        else System.out.println("NO");
    }
}