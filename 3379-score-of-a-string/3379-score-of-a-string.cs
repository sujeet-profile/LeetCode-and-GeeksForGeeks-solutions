
public class Solution {
    public int ScoreOfString(string str) {
        int ans = 0;
        for(int i = 1; i < str.Count(); ++i){
            ans = ans + Math.Abs(str[i] - str[i - 1]);
        }
        return ans;
    }
}