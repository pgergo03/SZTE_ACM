import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class anagramcounting {
    public static void main(String[] args) throws Exception {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        try (PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)))) {
            String s;
            Map<Character, Integer> cnt=new HashMap<>();
            BigInteger fakt[]=new BigInteger[101];
            fakt[0]=new BigInteger("1");
            for(int i=1; i<101; i++)
                fakt[i]=fakt[i-1].multiply(new BigInteger(Integer.toString(i)));

            while (true)
            { 
                try {
                    s=br.readLine();
                    cnt.clear();
                    for(int i=0; i<s.length(); i++)
                        cnt.put(s.charAt(i), cnt.getOrDefault(s.charAt(i), 0)+1);
                    
                    BigInteger er=fakt[s.length()];
                    for (Map.Entry<Character, Integer> x: cnt.entrySet())
                        er=er.divide(fakt[x.getValue()]);
                    pw.println(er);
                    
                } catch (IOException e) {
                    break;
                }
            }

            pw.close();
        }
    }
}
/*
at
ordeals
abcdefghijklmnopqrstuvwxyz
abcdefghijklmabcdefghijklm
abcdABCDabcd
*/