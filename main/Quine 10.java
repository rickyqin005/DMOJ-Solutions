public class Question4 {
public static void main(String[] args) {
char quote = 34;
String[] arr = {
"public class Question4 {",
"public static void main(String[] args) {",
"char quote = 34;",
"String[] arr = {",
"};",
"for(int i = 0; i < 4; i++) System.out.println(arr[i]);",
"for(int i = 0; i < arr.length; i++) System.out.println(quote+arr[i]+quote+',');",
"for(int i = 4; i < arr.length; i++) System.out.println(arr[i]);",
"}",
"}",
};
for(int i = 0; i < 4; i++) System.out.println(arr[i]);
for(int i = 0; i < arr.length; i++) System.out.println(quote+arr[i]+quote+',');
for(int i = 4; i < arr.length; i++) System.out.println(arr[i]);
}
}