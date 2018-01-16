class Solution {
    public List<Integer> partitionLabels(String S) {
        int last[] = new int[30];
        for(int i = 0; i < S.length(); i++) {
            last[S.charAt(i) - 'a'] = i;
        }
        
        List<Integer> res = new ArrayList();
        int shouldCut = 0, begining = 0;
        for(int i = 0; i < S.length(); i++) {
            shouldCut = Math.max(shouldCut, last[S.charAt(i) - 'a']);
            if(shouldCut == i) {
                res.add(shouldCut - begining + 1);
                begining = i + 1;
            }
        }
        return res;
    }
}