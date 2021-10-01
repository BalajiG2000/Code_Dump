import java.io.*;
import java.net.*;

class MyClient {

  public static void main(String args[]) throws Exception {
    Socket s = new Socket("localhost", 3333);
    DataInputStream din = new DataInputStream(s.getInputStream());
    DataOutputStream dout = new DataOutputStream(s.getOutputStream());
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = "", str2 = "";
    try {
      while (!str.equals("exit")) {
        System.out.print("Enter a number:");
        str = br.readLine();
        dout.writeUTF(str);
        dout.flush();
        str2 = din.readUTF();
        String arr[] = str2.split(" ");
        int i = 0;
        while (i < arr.length) {
          System.out.println(arr[i]);
          i++;
        }
      }
      dout.close();
      s.close();
    } catch (Exception e) {
      System.out.println("Connection ended");
    }
  }
}
