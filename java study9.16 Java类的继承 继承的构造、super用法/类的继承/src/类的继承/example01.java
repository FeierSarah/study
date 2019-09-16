package 类的继承;
//继承写法
class Animal{
	String name;
	void shout() {
		System.out.println("动物发出叫声");
	}
}
class Dog extends Animal{
	public void printName() {
		System.out.println("name=" + name);
	}
}
public class example01 {
	public static void main(String[] args) {
		Dog dog = new Dog();
		dog.name = "哈哈";
		dog.printName();
		dog.shout();
	}
}
