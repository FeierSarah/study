import java.io.*;
public class InputTest1 {

	public static void main(String[] args) {
		try {
			FileInputStream fis=new FileInputStream("d:\\abc.txt");
			//以磁盘上的记事本文件来创建一个文件字节输入流对象
			int ch=fis.read();//读取一个字节
			System.out.print(ch+",");
			while(ch!=-1)
			{
				ch=fis.read();
				System.out.print(ch+",");
			}
			fis.close();//关闭输入流
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
