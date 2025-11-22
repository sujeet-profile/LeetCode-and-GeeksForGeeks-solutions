public class Solution {
    public int[] ReplaceElements(int[] arr) {
        int max = arr[arr.Length - 1], temp = 0;
        for(int i = arr.Length - 1; i >= 0; --i){
            temp = arr[i];
            arr[i] = max;
            if(temp > max){
                max = temp;
            }
        }
        arr[arr.Length - 1] = -1;
        return arr;
    }
}