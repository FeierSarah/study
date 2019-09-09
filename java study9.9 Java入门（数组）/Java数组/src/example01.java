//数组定义
public class example01 {
	public static void main(String[] args) {
		//int[]
		int[] ids = new int[100];
		System.out.println("ids[0]=" + ids[0]);
		System.out.println("ids[99]=" + ids[99]);
		System.out.println("===================");
		//String[]
		String[] names = new String[] {"张三" , "tom" ,"jack"};
		System.out.println("names[0]=" + names[0]);
		System.out.println("names[2]=" + names[2]);
		System.out.println("===================");
		//Object
		Object[] object = {"张三" , "tom" ,"jack"};
		System.out.println("数组的长度为；" + object.length);
		System.out.println("object[0]=" + object[0]);
		System.out.println("object[2]=" + object[2]);
	}
	/**
	*1.与C语言相同，每个数组都有一个范围：0——length-1，索引不能越界
	*2.使用变量引用一个数组时，变量必须指向一个有效的数组对象，如果变量值为NULL，意味着
	*没有指向任意一个数组，此时通过该变量访问数组元素会出现空指针异常
	*/
}
