import java.io.*;
import java.util.Collections;
import java.util.LinkedList;
public class Question4 {
	public static LinkedList<String> ans = new LinkedList<String>();
	public static void swap(char[] arr, int i1, int i2) {
		char temp = arr[i1];
		arr[i1] = arr[i2];
		arr[i2] = temp;
	}
	public static void permutation(char[] arr,int level) {
		if(level == arr.length) ans.add(new String(arr));
		else {
			for(int i = level; i < arr.length; i++) {
				swap(arr,level,i);
				permutation(arr,level+1);
				swap(arr,level,i);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] str = br.readLine().toCharArray();
		permutation(str,0);
		Collections.sort(ans);
		for(String i: ans) {
			System.out.println(i);
		}
	}
}