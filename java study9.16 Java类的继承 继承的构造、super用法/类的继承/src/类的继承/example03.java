package 类的继承;
//super
class Animalss{
	String name = "动物";
	void shout() {
		System.out.println("动物发出叫声");
	}
}
class Dogss extends Animalss{
	String name = "犬类";
	void shout() {
		super.shout();
	}
	void printName() {
		System.out.println("name = " + super.name);
	}
}
public class example03 {
	public static void main(String[] args) {
		Dogss dogss = new Dogss();
		dogss.shout();
		dogss.printName();
	}
}
