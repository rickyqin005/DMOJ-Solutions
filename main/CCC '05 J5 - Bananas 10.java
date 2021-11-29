import java.io.*;
public class Question3 {
	public static boolean check(String T) {
		while(T.indexOf("BAS") != -1 || T.indexOf("ANA") != -1) {
			T = T.replaceAll("ANA","A").replaceAll("BAS","A");
		}
		if(T.equals("A")) return true;
		else return false;
	}
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
        	String T = br.readLine();
        	if(T.equals("X")) break;
        	if(check(T)) System.out.println("YES");
        	else System.out.println("NO");
        }
    }
}