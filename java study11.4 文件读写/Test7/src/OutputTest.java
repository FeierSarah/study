import java.io.*;
public class OutputTest {

	public static void main(String[] args) {
		try {
			FileOutputStream fos=new FileOutputStream("d:\\def.txt");
			//创建一个文件字节输出流对象
			int[] arrays={1,2,3,4,5,6,7,8,9,10};
			for(int i=0;i<arrays.length;i++)
			{
				fos.write(arrays[i]+97);
			}
			fos.flush();
			fos.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
