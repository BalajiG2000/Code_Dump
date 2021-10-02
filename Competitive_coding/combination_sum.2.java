// https://leetcode.com/problems/combination-sum-ii/
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(candidates);
        // boolean visited[] = new boolean[];
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
                if(i > start && candidates[i] == candidates[i-1]) continue; 
                list.add(candidates[i]);
                helper(res, list, candidates, i + 1, sum - candidates[i]);
                list.remove(list.size() - 1);
            }
        }
    }
}
