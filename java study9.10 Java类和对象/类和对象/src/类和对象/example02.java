package 类和对象;
//类的封装
/**
  * 封装是面向对象的三大特征之一
  * 在设计一个Java类时，应该对成员变量的访问作出一些限定，不允许外界随意访问
  * 类的封装是指将对象的状态信息隐藏在对象内部，不允许外部程序直接访问对象的内部信息
  * 实现过程为在定义一个类时，将类中的属性私有化，使用private关键词来修饰，私有属性只能在它所在类中被访问
  * 如果外界想要访问私有属性，需要提供一些使用public修饰的公有方法
  * 包括用于获取属性值的getXxx()方法和设置属性值的setXxx()方法
 */
class Persons {
	private String name;
	private int age;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		if(age <= 0) {
			System.out.println("输入年龄有误");
		}
		else {
			this.age = age;
		}
	}
	public void speak() {
		System.out.println("我叫" + name + "，今年" + age + "岁");
	}
}

public class example02 {
	public static void main(String[] args) {
		Persons p = new Persons();
		p.setName("张三");
		p.setAge(-18);
		p.speak();
	}
}