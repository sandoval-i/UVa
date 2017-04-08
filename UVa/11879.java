import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

	public static void main(String[] args) throws Exception
	{
		BigInteger b;
		BigInteger c = new BigInteger( "17" );
		BufferedReader bs = new BufferedReader( new InputStreamReader( System.in ) );
		String linea;
		while( true )
		{
			linea = bs.readLine();
			b = new BigInteger( linea );
			if( linea.equals("0") )
				break;
			if( b.mod( c ) == BigInteger.ZERO )
				System.out.println("1");
			else
				System.out.println("0");
		}
		bs.close();
	}

}
