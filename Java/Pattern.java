// Java Program to print a pattern with input from command line argument
class Pattern
{
	public static void main(String[] args) {
		int a=Integer.parseInt(args[0]);
		for(int i=0; i<a; i++)
		{
			for (int j=0;j<=i;j++)
			{
				System.out.print((i+1)+" ");
			}
      System.out.println("");
		}
		
	}
}
