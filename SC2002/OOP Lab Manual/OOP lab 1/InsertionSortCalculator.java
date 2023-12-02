public class InsertionSortCalculator{
    public static void main(String [] args){
        //System.out.println("Hello! This is my first program.");
        //System.out.println("Bye Bye!");
        /*long powSum = 1;

        for (int i = 1; i < 100; i++) {
            long fact = powSum*=i;
            System.out.println(fact);

            long pow = (long) Math.pow(10,i);
            System.out.println(pow);
            
            if(fact > pow){
                System.out.println("Factorial is bigger than power");
            }
            System.out.println();
        }*/

        int[] arr = {4,18,7,34,7,2};
        int[]result = new int[6];
        result = insertionSort(arr);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i]+" ");
        }
    }

    private static int[] insertionSort(int[] arr) {
        int n = arr.length;
        int swap = 0;
        int comparisons = 0;
        for (int i = 1; i < n; i++) {
             for (int j = i; j >0; j--) {
                comparisons++;
                if(arr[j] < arr[j-1]){
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    swap++;
                }
                else{
                    break;
                }
            }    
        }
        System.out.println("Insertion Sort swap count is "+swap);
        System.out.println("Insertion Sort key comparisons is "+comparisons);
        return arr;
    }

    
}