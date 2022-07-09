import java.io.*;
import java.util.*;

public class Alchemy {

  public static int lol = 0;
  public static void main(String[] args) throws IOException {
    
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(in.readLine());
    StringTokenizer st = new StringTokenizer(in.readLine());
    int[] have = new int[n];
    for(int i = 0; i < n; i++) have[i] = Integer.parseInt(st.nextToken());
    int ans = 0;
    int[][] recipes = new int[n][];
    int k = Integer.parseInt(in.readLine());
    while(k-- > 0) {
      st = new StringTokenizer(in.readLine());
      int gain = Integer.parseInt(st.nextToken())-1;
      recipes[gain] = new int[Integer.parseInt(st.nextToken())];
      for(int i = 0; i < recipes[gain].length; i++) recipes[gain][i] = Integer.parseInt(st.nextToken())-1;
    }
    while(canMake(recipes, have, n-1)) ans++;
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    out.println(ans);
    out.println(lol);
    out.close();
  }

  private static boolean canMake(int[][] recipes, int[] have, int want) {
    lol++;
    if(have[want] > 0) {
      have[want]--;
      return true;
    }
    if(recipes[want] == null) return false;
    for(int component: recipes[want]) if(!canMake(recipes, have, component)) return false;
    return true;
  }
}
