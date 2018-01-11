import java.util.Scanner;

public class Main {

    /**
     * @param args
     * PAT Advanced 1136
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String str = sc.next();
            StringBuffer temp = new StringBuffer(str);
            int count = 0;
            while(!isPalindromic(temp) && count < 10) {
                StringBuffer retemp = new StringBuffer(temp).reverse();
                StringBuffer restemp = countRes(temp);
                System.out.printf("%s + %s = %s\n", temp, retemp, restemp);
                temp = restemp;
                count++;
            }
            if(isPalindromic(temp)) System.out.printf("%s is a palindromic number.\n", temp);
            else System.out.printf("Not found in 10 iterations.\n");
        }

    }

    private static StringBuffer countRes(StringBuffer str) {
        String retemp = new StringBuffer(str).reverse().toString();
        StringBuffer res = new StringBuffer("");
        int cnt = 0, len = str.length();
        for(int i = 0; i < len; i++) {
            int u = str.charAt(i) + retemp.charAt(i) - '0' * 2 + cnt;
            res.append(u % 10);
            cnt = u / 10;
        }
        if(cnt != 0) res.append(cnt);
        return res.reverse();
    }

    private static boolean isPalindromic(StringBuffer str) {
        int right = str.length() - 1, left = 0;
        while(left < right)
            if(str.charAt(left++) != str.charAt(right--)) return false;
        return true;
    }
}
