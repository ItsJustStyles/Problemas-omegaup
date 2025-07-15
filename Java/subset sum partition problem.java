import java.util.Scanner;
import java.util.Arrays;

//Este problema es uno clasico y es el subset sum partition problem.
public class Main{
    public static void main(String[] args){
        int n;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int[] numbers = new int[n];
        int suma = 0;
        for(int i = 0; i < n; i++){
            numbers[i] = in.nextInt();
            suma += numbers[i];
        }
        int objetivo = suma/2;
        boolean[] dp = new boolean[objetivo + 1];
        dp[0] = true;
        for(int num:numbers){
            for(int i = objetivo; i >= num; i--){
                if(dp[i-num]){
                    dp[i] = true;
                }
            }
        }
        
        int sumaCercana = 0;
        for(int i = objetivo; i >= 0; i--){
            if(dp[i]){
                sumaCercana = i;
                break;
            }
        }
        System.out.print(suma-sumaCercana*2);
    }
}