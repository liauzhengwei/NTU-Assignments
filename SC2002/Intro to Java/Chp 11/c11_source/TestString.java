public class TestString {
	public static void main(String[] args){
		
		String str1 = "SC";
		String str2 = "-Java Programming";
		int code = 123;

		
        String str = new StringBuffer().append(str1).append(code).append(str2).toString();

		System.out.println(str);
	}
}

