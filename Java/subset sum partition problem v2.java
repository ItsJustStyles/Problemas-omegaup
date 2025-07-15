import java.util.Scanner;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

//Este problema es uno clasico y es el subset sum partition problem. Esta versión usa hashset.
public class Main{
    public static void main(String[] args){
        int n;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int[] numbers = new int[n];
        int sumaTotal = 0;
        
        for(int i = 0; i < n; i++){
            numbers[i] = in.nextInt();
            sumaTotal += numbers[i];
        }
        int target = sumaTotal/2;
        Set<Integer> posibles = new HashSet<>();
        posibles.add(0);
        
        for(int number:numbers){
            Set<Integer> nuevos = new HashSet<>();
            for(int suma: posibles){
                if(suma+number <= target){
                    nuevos.add(suma+number);
                }
            }
            posibles.addAll(nuevos);
        }
        
        int mejorSuma = 0;
        for(int num:posibles){
            if(num > mejorSuma){
                mejorSuma = num;
            }
        }
        System.out.print(sumaTotal-2*mejorSuma);
    }
}