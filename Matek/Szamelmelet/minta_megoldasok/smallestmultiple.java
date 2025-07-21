import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class smallestmultiple {

    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        while (true)
        {
            try
            {
                StringTokenizer in=new StringTokenizer(br.readLine());
                BigInteger er=new BigInteger(in.nextToken());
                while(in.hasMoreTokens())
                {
                    
                    BigInteger x=new BigInteger(in.nextToken());
                    er=er.multiply(x).divide(er.gcd(x));
                }
                pw.println(er.toString());
            }
            catch(IOException e)
            {
                break;
            }
        }
        
        pw.flush();
    }
}
/*
2 3 5
1 2 3 4
399 772 163 959 242
*/