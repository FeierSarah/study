//static 静态方法定义
class Persons{
	public static void say() {
		System.out.println("Hello");
	}
}
public class example02 {
	public static void main(String[] args) {
		Persons.say();
		Persons persons = new Persons();
		Persons.say();
	}
}


