import java.util.LinkedList;

public class latihan_java {
    
    public static void main(String[] args){
        //Creating Instance / Object from LinkedList
        LinkedList<String> buah = new LinkedList<>();
        
        //Adding Data to Fruit Objects
        buah.add("Jeruk");
        buah.add("Jambu");
        buah.add("Apel");
        buah.add("Melon");
        buah.add("Semangka");
        buah.add("Nanas");
        buah.add("Sirsak");
        
        //Printing / Displaying Data
        System.out.println("Fruits name: "+buah);
        
        //Calculating the Amount / Size on the LinkedList object
        System.out.println("Number of Fruits: "+buah.size());
    }
}
