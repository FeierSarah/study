//���鶨��
public class example01 {
	public static void main(String[] args) {
		//int[]
		int[] ids = new int[100];
		System.out.println("ids[0]=" + ids[0]);
		System.out.println("ids[99]=" + ids[99]);
		System.out.println("===================");
		//String[]
		String[] names = new String[] {"����" , "tom" ,"jack"};
		System.out.println("names[0]=" + names[0]);
		System.out.println("names[2]=" + names[2]);
		System.out.println("===================");
		//Object
		Object[] object = {"����" , "tom" ,"jack"};
		System.out.println("����ĳ���Ϊ��" + object.length);
		System.out.println("object[0]=" + object[0]);
		System.out.println("object[2]=" + object[2]);
	}
	/**
	*1.��C������ͬ��ÿ�����鶼��һ����Χ��0����length-1����������Խ��
	*2.ʹ�ñ�������һ������ʱ����������ָ��һ����Ч����������������ֵΪNULL����ζ��
	*û��ָ������һ�����飬��ʱͨ���ñ�����������Ԫ�ػ���ֿ�ָ���쳣
	*/
}
