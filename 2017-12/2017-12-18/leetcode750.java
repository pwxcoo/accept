class Solution {
    public int countCornerRectangles(int[][] grid) {
        Map<Integer, Integer> count = new HashMap();
        int res = 0;
        for(int[] row:grid){
            for(int i = 0; i < row.length; i++) if(row[i] == 1){
                for(int j = i + 1; j < row.length; j++) if(row[j] == 1){
                    int pos = 200 * i + j;
                    int c = count.getOrDefault(pos,0);
                    res += c;
                    count.put(pos, c + 1);
                }
            }
        }
        return res;
    }
}