import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader sc = new BufferedReader( new InputStreamReader( System.in ) );
        BigInteger p , m;
        int b;
        while(true)
        {
            String linea = sc.readLine();
            String numbers[] = linea.split(" ");
            if( linea.charAt(0) == '0' && linea.length() == 1 )   break;
            b = Integer.parseInt( numbers[0] );
            p = new BigInteger( numbers[1] , b );
            m = new BigInteger( numbers[2] , b );
            System.out.println( p.mod(m).toString(b));
        }
    }
    
}
