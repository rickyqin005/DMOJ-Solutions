import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[] in = br.readLine().split(" ");
		int firstPair = Integer.parseInt(in[0]);
		int[] diffArr = new int[N];
		int sumDiff = 0;
		for(int i = 2; i < N; i++) {
			int num = diffArr[i-2]+Integer.parseInt(in[i-1])-Integer.parseInt(in[i-2]);
			diffArr[i] = num;
			sumDiff += num;
		}
		int x = 0, y = 0;
		if(N % 2 == 0) {
			outer: for(int i = 1; i < firstPair; i++) {
				if(i + i == firstPair) continue;
				if(i > N || firstPair-i > N) continue;
				y = firstPair-i;
				boolean[] isUsed = new boolean[N];
				isUsed[i-1] = true; isUsed[y-1] = true;
				for(int j = 2; j < N; j++) {
					int num = diffArr[j];
					if(j % 2 == 0) num += i;
					else num += y;
					if(num > N || num <= 0) continue outer;
					if(isUsed[num-1]) continue outer;
					isUsed[num-1] = true;
				}
				x = i;
				break;
			}
		} else x = N*(N+1)/2-sumDiff-firstPair*(N/2);
		y = firstPair-x;
		for(int i = 0; i < N; i++) {
			if(i % 2 == 0) System.out.print((x+diffArr[i])+" ");
			else System.out.print((y+diffArr[i])+" ");
		}
		System.out.println();
	}
}