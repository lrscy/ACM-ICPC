import java.util.*;

public class Main {
    static HashMap<String, Integer> nmap = new HashMap<String, Integer>();
    
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );
        int n = sc.nextInt();
        String tmp = new String();
        nmap.clear();
        sc.nextLine();
        while( n-- > 0 ) {
            String tstr = sc.nextLine();
            int tp = tstr.indexOf( "define" ), pos; pos = tp;
            while( pos < tstr.length() && tstr.charAt( pos ) != ' ' ) ++pos;
            while( pos < tstr.length() && tstr.charAt( pos ) == ' ' ) ++pos;
            tp = pos;
            while( pos < tstr.length() && tstr.charAt( pos ) != ' ' ) ++pos;
            tmp = tstr.substring( tp, pos );
            nmap.put( tmp, hash( tstr.substring( pos + 1, tstr.length() ) ) );
        }
        if( hash( sc.nextLine() ) == 0 ) System.out.println( "Suspicious" );
        else System.out.println( "OK" );
        sc.close();
    }

    public static int hash( String tmp ) {
        String str = new String();
        for( int i = 0; i < tmp.length(); ++i ) {
            char ch = tmp.charAt( i );
            if( ch != ' ' )
                str += ch;
        }
        return cal( 0, str.length(), str );
    }
    
    public static int cal( int s, int e, String str ) {
        String st = str.substring( s, e );
        int flag = 0, left, right;
        char ch;
        for( int i = e - 1; i >= s; --i ) {
            flag += str.charAt( i ) == '(' ? 1 : 0;
            flag -= str.charAt( i ) == ')' ? 1 : 0;
            ch = str.charAt( i );
            if( flag == 0 && ( ch == '+' || ch == '-' ) ) {
                left = cal( s, i, str );
                right = cal( i + 1, e, str );
                if( left > 0 && right > 0 && ( right > 1 || str.charAt( i ) != '-' ) )
                    return 1;
                else return 0;
            }
        }
        flag = 0;
        for( int i = e - 1; i >= s; --i ) {
            flag += str.charAt( i ) == '(' ? 1 : 0;
            flag -= str.charAt( i ) == ')' ? 1 : 0;
            ch = str.charAt( i );
            if( flag == 0 && ( ch == '*' || ch == '/' ) ) {
                left = cal( s, i, str );
                right = cal( i + 1, e, str );
                if( left > 1 && right > 1 && ( right > 2 || str.charAt( i ) != '/' ) )
                    return 2;
                else return 0;
            }
        }
        if( str.charAt( s ) == '(' ) {
            return cal( s + 1, e - 1, str ) != 0 ? 3 : 0;
        }
        if( nmap.containsKey( st ) )
            return nmap.get( st );
        return 3;
    }
}
