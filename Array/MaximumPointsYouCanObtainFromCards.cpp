class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
		
        for(int i=0 ; i<k ; i++){
            ans+=cardPoints[i];
        } 
        int current = ans;
        
        for(int i=k-1 ; i>=0 ; i--) {
            current -= cardPoints[i];
            current += cardPoints[cardPoints.size()-k+i];
			
			ans = max(ans, current);
        }
        
        return ans;
    }
};