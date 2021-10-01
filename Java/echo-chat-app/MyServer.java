import java.io.*;
import java.net.*;

class MyServer {

  public static void main(String args[]) throws Exception {
    ServerSocket ss = new ServerSocket(3333);
    Socket s = ss.accept();
    DataInputStream din = new DataInputStream(s.getInputStream());
    DataOutputStream dout = new DataOutputStream(s.getOutputStream());
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = "", str2 = "";
    int count = 0;
    try {
      while (!str.equals("exit")) {
        if (count == 0) {
          System.out.println("Connection Succeeded");
          System.out.println(
            "Now you can enter a number on your side to get a table for that number."
          );
        }
        count++;
        str = din.readUTF();
        int num = Integer.parseInt(str);
        for (int i = 1; i < 11; i++) {
          str2 = str2 + " " + Integer.toString(num * i);
        }
        dout.writeUTF(str2);
        str2 = "";
        System.out.println("Table Printed");
      }
      din.close();
      s.close();
      ss.close();
    } catch (Exception e) {
      System.out.println("Connection closed.");
    }
  }
}
