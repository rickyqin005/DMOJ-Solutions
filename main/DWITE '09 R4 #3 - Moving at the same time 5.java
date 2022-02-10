import java.util.Scanner;
import java.util.ArrayList;
public class Character {
	int velocity;
	int index;
	public Character(int v, int i) {
		velocity = v;
		index = i;
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int i = 0; i < 5; i++) {
			ArrayList<Character> characters = new ArrayList<Character>();
			String line = input.nextLine();
			String[] in = line.split("");
			System.out.println(line);
			
			for(int j = 0; j < in.length; j++) {
				if(!in[j].equals(".")) {
					characters.add(new Character(Integer.parseInt(in[j]),j));
				}
			}
			
			for(int j = 1; j < 5; j++) {
				for(int k = 0; k < characters.size(); k++) {
					characters.get(k).index += characters.get(k).velocity;
				}
				
				for(int k = 0; k < in.length; k++) {
					int velocity = 0;
					boolean hasCharacter = false;
					for(int l = 0; l < characters.size(); l++) {
						if(characters.get(l).index == k) {
							velocity += characters.get(l).velocity;
							hasCharacter = true;
						}
					}
					if(hasCharacter) System.out.print(velocity);
					else System.out.print(".");
				}
				System.out.println();
			}
		}
	}
}