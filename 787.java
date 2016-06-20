import java.math.BigInteger;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;


public class Main
{

  static int size;
  static BigInteger voy;
  static BigInteger maximo;
  private static BigInteger maxProduct( ArrayList< BigInteger > arreglo )
  {
    maximo = arreglo.get( 0 );
    size = arreglo.size();
    for( int i = 0 ; i < size ; i++ )
    {
      voy = arreglo.get( i );
      maximo = maximo.max( voy );
      for( int j = i + 1 ; j < size ; j++ )
      {
        voy = voy.multiply( arreglo.get( j ) );
        maximo = maximo.max( voy );
        if( voy == BigInteger.ZERO )
            break;
      }
    }
    return maximo;
  }

	public static void main(String[] args) throws Exception
	{
		try
		{
		    Scanner entrada = new Scanner( System.in );
		    BigInteger actual;
		    while( entrada.hasNextLine() )
		    {
		      ArrayList< BigInteger > array = new ArrayList< BigInteger >();
		      while( true )
		      {
		        actual = entrada.nextBigInteger();
		        if( actual.intValue() == -999999 )
		          break;
		        array.add( actual );
		      }
		      System.out.println( maxProduct( array ).toString() );
		    }
		    entrada.close();
		}
		catch( NoSuchElementException e )
		{
			return;
		}
	}

}
