import java.io.*;
public class FileReadTest {

	public static void main(String[] args) {
		try {
			FileReader fr=new FileReader("d:\\123.txt");
			FileWriter fw=new FileWriter("d:\\def.txt");
			int ch=fr.read();
			while(ch!=-1)
			{
				System.out.print((char)ch+",");
				fw.write(ch);
				ch=fr.read();
			}
			fr.close();
			fw.flush();
			fw.close();
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
