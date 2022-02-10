import java.io.*;
public class Student {
	String name;
	int score;
	public Student(String n, int s) {
		name = n; score = s;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), P = Integer.parseInt(in[1]);
		Student[] student = new Student[N];
		for(int i = 0; i < N; i++) {
			student[i] = new Student(br.readLine(),0);
		}
		for(int i = 0; i < P; i++) {
			in = br.readLine().split(" ");
			for(int j = 0; j < N; j++) {
				student[j].score += Integer.parseInt(in[j]);
			}
		}
		java.util.Arrays.sort(student, (a,b) -> Integer.compare(a.score, b.score)*-1);
		for(int i = 0; i < N; i++) {
			System.out.println((i+3)+". "+student[i].name);
		}
	}
}