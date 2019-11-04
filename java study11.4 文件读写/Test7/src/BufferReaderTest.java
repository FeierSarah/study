import java.io.*;
public class BufferReaderTest {

	public static void main(String[] args) {
		/*try {
			FileReader fr=new FileReader("d:\\student.txt");
			BufferedReader br=new BufferedReader(fr);
			String str=br.readLine();
			while(str!=null)
			{
				System.out.println(str);
				str=br.readLine();
			}
			br.close();
			fr.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		*/
		System.out.println(findNumByName("丁二1"));
		System.out.println(findNameByNum("001"));
		System.out.println(getSexCount("女"));

	}
	
	public static String findNumByName(String name)
	{
		String result="查无此人";
		try {
			FileReader fr=new FileReader("d:\\student.txt");
			BufferedReader br=new BufferedReader(fr);
			String str=br.readLine();
			while(str!=null)
			{
				String[] infos=str.split(",");
				if(infos[1].equals(name))
				{
					result=infos[0];
					break;
				}
				str=br.readLine();
			}
			br.close();
			fr.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return result;
	}

	
	public static String findNameByNum(String num)
	{
		String result="查无此人";
		try {
			FileReader fr=new FileReader("d:\\student.txt");
			BufferedReader br=new BufferedReader(fr);
			String str=br.readLine();
			while(str!=null)
			{
				String[] infos=str.split(",");
				if(infos[0].equals(num))
				{
					result=infos[1];
					break;
				}
				str=br.readLine();
			}
			br.close();
			fr.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return result;
	}
	
	public static int getSexCount(String sex)
	{
		int result=0;
		try {
			FileReader fr=new FileReader("d:\\student.txt");
			BufferedReader br=new BufferedReader(fr);
			String str=br.readLine();
			while(str!=null)
			{
				String[] infos=str.split(",");
				if(infos[2].equals(sex))
				{
					result++;
				}
				str=br.readLine();
			}
			br.close();
			fr.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return result;
	}
}
