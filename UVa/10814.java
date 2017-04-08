import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader sc = new BufferedReader( new InputStreamReader( System.in ) );
        BigInteger a , b , mod;
        int casos;
        casos = Integer.parseInt( sc.readLine() );
        while(casos > 0)
        {
            casos--;
            String numbers[] = sc.readLine().split("/");
            a = new BigInteger( numbers[0].trim() );
            b = new BigInteger( numbers[1].trim() );
            mod = a.gcd(b);
            System.out.println( a.divide(mod) + " / " + b.divide(mod));
        }
    }
    
}
