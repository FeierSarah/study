import java.io.IOException;


public class Test1 {

	public static void main(String[] args) {
		Runtime run=Runtime.getRuntime();
		try {
			run.exec("notepad.exe");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		

	}

}
