import java.sql.Array;
import java.util.Arrays;

class Activity implements Comparable<Activity>{
    int start,finish;
    public Activity(int start,int finish)
    {
        this.start = start;
        this.finish = finish;
    }

    @Override
    public int compareTo(Activity o) {
        return this.finish-o.finish;
    }
}
public class ActivitySelection {
    public static void main(String[] args) {
        Activity arr[] = {new Activity(20, 25),
                new Activity(10, 30),
                new Activity(25, 30)};
        Arrays.sort(arr);
        ActivitySelection obj = new ActivitySelection();
        System.out.println(obj.maxActivity(arr));
    }
    public int maxActivity(Activity[] arr)
    {
        int r = 1;
        int prev = 0;
        for (int i = 1; i < arr.length ; i++) {
            if(arr[i].start>=arr[prev].finish)
            {
                r++;
                prev = i;
            }
        }
        return r;
    }
}
