import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        int N , A;
        BigInteger ans , a , b;
        Scanner sc = new Scanner( System.in );
        try
        {
            while(true)
            {
                ans = BigInteger.ZERO;
                N = sc.nextInt();
                A = sc.nextInt();
                a = BigInteger.ONE;
                b = BigInteger.valueOf(A);
                for( int i = 1 ; i <= N ; ++i )
                {
                    ans = ans.add( a.multiply(b) );
                    b = b.multiply(BigInteger.valueOf(A));
                    a = a.add(BigInteger.ONE);
                }
                System.out.println(ans);
            }
        }
        catch( Exception e )
        {
        }
        finally
        {
            sc.close();
        }
    }
    
}
