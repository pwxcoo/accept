class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int mx = -1;
        for(int i0 = 0; i0 < 4; i0++)
            for(int i1 = 0; i1 < 4; i1++)
                for(int i2 = 0; i2< 4; i2++){    
                    if(i0 == i1 || i1 == i2 || i2 == i0 ) continue;
					
                    if((A[i0] == 2 && A[i1] < 4 && A[i2]  < 6) || (A[i0] < 2 && A[i2] < 6)) {
                        int temp = A[i0] * 1000 + A[i1] * 100 + A[i2] * 10 + A[6 - i0 - i1 - i2];
                        mx = max(mx,temp);
                    }
                 }
				 
        if(mx == -1) return "";
        char res[6];
        sprintf(res, "%d%d:%d%d", mx/ 1000, mx/100 % 10, mx %100 /10, mx %100 %10);
        return  res;
        
    }
};