import java.io.*;
public class InputTest1 {

	public static void main(String[] args) {
		try {
			FileInputStream fis=new FileInputStream("d:\\abc.txt");
			//�Դ����ϵļ��±��ļ�������һ���ļ��ֽ�����������
			int ch=fis.read();//��ȡһ���ֽ�
			System.out.print(ch+",");
			while(ch!=-1)
			{
				ch=fis.read();
				System.out.print(ch+",");
			}
			fis.close();//�ر�������
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
