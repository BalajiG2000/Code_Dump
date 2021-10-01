// https://leetcode.com/problems/combination-sum
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(candidates);
        helper(res, list, candidates, 0, target);
        return res;
        
    }
    
    public void helper(List<List<Integer>> res, List<Integer> list, int[] candidates, int start, int sum){
        if(sum < 0) return;
        else if(sum == 0){
            res.add(new ArrayList<>(list));
            
        }
        else{
            for(int i = start; i < candidates.length; i++){
                list.add(candidates[i]);
                helper(res, list, candidates, i, sum - candidates[i]);
                list.remove(list.size() - 1);
            }
        }
    }
}
