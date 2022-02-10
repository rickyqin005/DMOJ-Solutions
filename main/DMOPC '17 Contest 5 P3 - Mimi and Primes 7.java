import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		long[] arr = new long[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			arr[i] = Long.parseLong(st.nextToken());
		}
		Arrays.sort(arr);
		
		LinkedList<Long> primeFact = new LinkedList<Long>();
		long minNum = arr[0];
		long maxPrime = 1;
		boolean isFactor = false;
		
		while(minNum % 2 == 0) {
			minNum /= 2; maxPrime = 2;
			isFactor = true;
		}
		if(isFactor) primeFact.add((long)2);
		isFactor = false;
		
		for(int i = 3; i <= Math.sqrt(minNum); i += 2) {
			while(minNum % i == 0) {
				minNum /= i; maxPrime = i;
				isFactor = true;
			}
			if(isFactor) primeFact.add((long)i);
			isFactor = false;
		}
		maxPrime = Math.max(minNum, maxPrime);
		primeFact.add(maxPrime);
		
		if(maxPrime == 1) {System.out.println("DNE"); return;}
		for(int i = 0; i < N; i++) {
			while(arr[i] % primeFact.getLast() != 0) {
				primeFact.removeLast();
				if(primeFact.isEmpty()) {System.out.println("DNE"); return;}
			}
		}
		System.out.println(primeFact.getLast());
	}
}