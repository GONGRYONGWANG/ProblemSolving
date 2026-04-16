
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        int N,M;
        Scanner input = new Scanner(System.in);
        N = input.nextInt();
        M = input.nextInt();
        long S;
        S = input.nextLong();

        System.out.println(Math.min(S*(100-N)*(M+1)/100, S*M));

    }
}