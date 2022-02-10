import java.io.*;
import java.util.*;
import java.text.*;
public class Question5 {
	public static double median(double[] arr) {
		int N = arr.length;
		if(N % 2 == 0) return (double)(arr[(N-1)/2] + arr[(N-1)/2+1])/2;
		else return arr[N/2];
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		double[] point = new double[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			point[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(point);
		NumberFormat nf = new DecimalFormat("########.######");
		System.out.print(nf.format(point[0]) + " " + nf.format(point[N-1]) + " ");
		System.out.print(nf.format(median(Arrays.copyOfRange(point, 0, N/2))) + " ");
		System.out.print(nf.format(median(point)) + " ");
		System.out.print(nf.format(median(Arrays.copyOfRange(point, N - N/2, N))));
		System.out.println();
	}
}