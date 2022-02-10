import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Integer>[] numFact = new ArrayList[633];
		for(int i = 0; i < 633; i++) {
			numFact[i] = new ArrayList<Integer>();
		}

		int[] arr = new int[100000];
		for(int i = 2; i <= 100000; i++) {
			for(int j = i-1; j < 100000; j += i) arr[j]++;
		}
		for(int i = 0; i < 100000; i++) {
			numFact[arr[i]+1].add(i+1);
		}
		int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int K = Integer.parseInt(st.nextToken());
			int A = Integer.parseInt(st.nextToken()), B = Integer.parseInt(st.nextToken());
			if(K > 632) {System.out.println(0); continue;}
			if(numFact[K].size() == 0) {System.out.println(0); continue;}
			int start = 0, end = numFact[K].size(), mid = 0;
			if(numFact[K].get(start) > B) {System.out.println(0); continue;}
			if(numFact[K].get(end-1) < A) {System.out.println(0); continue;}
			int startIndex = 0;
			if(A <= numFact[K].get(0)) startIndex = 0;
			else if(A >= numFact[K].get(end-1)) startIndex = end-1;
			else {
				while(start < end) {
		            mid = (start+end)/2;
		            if(numFact[K].get(mid) == A) {startIndex = mid; break;}
		            if(A < numFact[K].get(mid)) {
		                if(mid > 0 && A > numFact[K].get(mid-1)) {
		                    startIndex = mid; break;
		                }
		                end = mid;
		            }
		            else {
		                if(mid < end-1 && A < numFact[K].get(mid+1)) {
		                	startIndex = mid+1; break;
		                }
		                start = mid + 1;
		            }
		        }
			}
			start = 0; end = numFact[K].size(); mid = 0;
			int endIndex = 0;
			if(B <= numFact[K].get(0)) endIndex = 0;
			else if(B >= numFact[K].get(end-1)) endIndex = end-1;
			else {
				while(start < end) {
		            mid = (start+end)/2;
		            if(numFact[K].get(mid) == B) {endIndex = mid; break;}
		            if(B < numFact[K].get(mid)) {
		                if(mid > 0 && B > numFact[K].get(mid-1)) {
		                    endIndex = mid-1; break;
		                }
		                end = mid;
		            }
		            else {
		                if(mid < end-1 && B < numFact[K].get(mid+1)) {
		                	endIndex = mid; break;
		                }
		                start = mid;
		            }
		        }
			}
			//System.out.println(startIndex+" "+endIndex);
			System.out.println(endIndex-startIndex+1);
		}
	}
}