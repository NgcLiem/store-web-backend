package LeetCode;

public class MovesZeros {
    public void moveZeroes(int[] nums) {
        int cur = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            if (nums[i] != 0) {
                nums[cur] = nums[i];
                cur++;
            }
            else {
                continue;
            }
        }
        for(;cur < n; cur++){
            nums[cur] = 0;
        }
    }
}
