// https://leetcode.com/problems/3sum/


class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        HashSet<List<Integer>> set = new HashSet<>();
        for(int i = 0; i < nums.length; i++){
            int target = -nums[i];
            int start = i + 1;
            int end = nums.length - 1;
            
            while(start < end){
                int mid = start + (end - start)/2;
                if(nums[start] + nums[end] == target){
                    List<Integer> a = new LinkedList<>();
                    a.add(nums[i]);
                    a.add(nums[start]);
                    a.add(nums[end]);
                    start++;
                    end--;
                    
                    set.add(a);
                }
                else if(nums[start] + nums[end] > target){
                    end--;
                }else{
                    start++;
                }
            }
        }
        return new ArrayList<>(set);
        
    }
}
