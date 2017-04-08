import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;


public class Main
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader sc = new BufferedReader( new InputStreamReader( System.in ) );
        BigDecimal ans , aux;
        int casos , fin;
        casos = Integer.parseInt( sc.readLine() );
        while(casos > 0)
        {
            casos--;
            ans = BigDecimal.ZERO;
            while(true)
            {
                aux = new BigDecimal(sc.readLine());
                if( aux.equals(BigDecimal.ZERO) )   break;
                ans = ans.add(aux);
            }
            if( ans.equals(BigDecimal.ZERO) )
                System.out.println("0");
            else 
            {
                String res = ans.toPlainString();
                fin = res.length();
                for( int i = res.length() - 1 ; i >= 0 ; --i )
                {
                    if( res.charAt(i) != '0' )
                    {
                        if( res.charAt(i) == '.' )
                            fin = i;
                         break;
                    }
                    fin = i;
                }
                for( int i = 0 ; i < fin ; ++i )
                    System.out.print(res.charAt(i));
                System.out.println();
            }
        }
    }
    
}
