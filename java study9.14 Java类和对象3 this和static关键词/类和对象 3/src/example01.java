//this 关键字
//this用于指代当前对象，用于在方法中访问对象的其他成员
//用法1：解决局部变量名称冲突
/*class Person{
	int age;
	public Person(int age) {
		this.age = age;
	}
}*/

//用法2：通过this调用成员方法
/*class Person{
	public void openMouth() {
		System.out.println(" ");
	}
	public void speak() {
		this.openMouth();
	}
}*/

//方法3：调用构造方法
class Person{
	public Person() {
		System.out.println("无参数构造方法被调用");
	}
	public Person(int age) {
		this();
		System.out.println("有参数构造方法被调用");
	}
}
public class example01 {
	public static void main(String[] args) {
		Person p = new Person(18);
	}
}
