import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class every_window {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            Solution7 g = new Solution7();

            ArrayList<Integer> ans = g.countDistinct(a, n, k);

            for (Integer val: ans)
                System.out.print(val+" ");
            System.out.println();
            t--;
        }
    }
}// } Driver Code Ends


class Solution7
{
    ArrayList<Integer> countDistinct(int A[], int n, int k)
    {
        // code here
        HashMap<Integer,Integer> hashmap=new HashMap<>();
        ArrayList<Integer> arrayList=new ArrayList<>();
        for (int i = 0; i < k; i++) {
            hashmap.put(A[i],hashmap.getOrDefault(A[i],0)+1);
        }
        arrayList.add(hashmap.size());
            for (int i = k; i <A.length ; i++) {

                if (hashmap.get(A[i-k]) == 1)
                    hashmap.remove(A[i-k]);
                else
                    hashmap.put(A[i-k ], hashmap.get(A[i-k]) - 1);
                hashmap.put(A[i],hashmap.getOrDefault(A[i],0)+1);
                arrayList.add(hashmap.size());
            }

        return arrayList;
    }

}
