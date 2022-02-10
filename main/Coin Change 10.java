import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x = Integer.parseInt(br.readLine());
		int n = Integer.parseInt(br.readLine());
		int[] num = new int[n];
		for(int i = 0; i < n; i++) {
			num[i] = Integer.parseInt(br.readLine());
		}
		int[] arr = new int[x+1];
		for(int i = 0; i < num.length; i++) {
			int curr = num[i];
			for(int j = 1; j < arr.length-curr; j++) {
				if(arr[j] == 0) continue;
				if(arr[j+curr] == 0) arr[j+curr] = arr[j]+1;
				else arr[j+curr] = Math.min(arr[j]+1,arr[j+curr]);
			}
			int count = 1;
			for(int j = curr; j < arr.length; j += curr) {
				if(arr[j] == 0) arr[j] = count;
				else arr[j] = Math.min(arr[j], count);
				count++;
			}
		}
		System.out.println(arr[x]);
	}
}