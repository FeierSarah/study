package ��Ͷ���;
//��ķ�װ
/**
  * ��װ������������������֮һ
  * �����һ��Java��ʱ��Ӧ�öԳ�Ա�����ķ�������һЩ�޶�������������������
  * ��ķ�װ��ָ�������״̬��Ϣ�����ڶ����ڲ����������ⲿ����ֱ�ӷ��ʶ�����ڲ���Ϣ
  * ʵ�ֹ���Ϊ�ڶ���һ����ʱ�������е�����˽�л���ʹ��private�ؼ��������Σ�˽������ֻ�������������б�����
  * ��������Ҫ����˽�����ԣ���Ҫ�ṩһЩʹ��public���εĹ��з���
  * �������ڻ�ȡ����ֵ��getXxx()��������������ֵ��setXxx()����
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
			System.out.println("������������");
		}
		else {
			this.age = age;
		}
	}
	public void speak() {
		System.out.println("�ҽ�" + name + "������" + age + "��");
	}
}

public class example02 {
	public static void main(String[] args) {
		Persons p = new Persons();
		p.setName("����");
		p.setAge(-18);
		p.speak();
	}
}