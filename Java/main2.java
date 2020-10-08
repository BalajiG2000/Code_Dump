public class main2 {
    public static void main(String[]args)
    {
        boolean gamewon=true;
        int games=5;
        int books=20;
        int score=5000;

        calculatevalue(gamewon ,games,books,score);
    }
     public static int calculatevalue(boolean gamewon, int games, int books, int score)
{
       if(gamewon)
       {
           int goodscore=games+(books*score);
           goodscore+=2000;
           System.out.println(goodscore);
           return goodscore;
       }     
       return -1;
}
}
