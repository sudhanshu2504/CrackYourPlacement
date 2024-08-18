class Solution {
public:
    int nthUglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0] = 1;
    int v2 = 0;
    int v3 = 0;
    int v5 = 0;

    for(int i=1 ; i<n ; i++){
        ugly[i] = min(ugly[v2]*2, min(3*ugly[v3],5*ugly[v5]));

        if(ugly[i] == ugly[v2]*2){
            v2++;
        }
        if(ugly[i] == ugly[v3]*3){
            v3++;
        }
        if(ugly[i] == ugly[v5]*5){
            v5++;
        }
    }
    return ugly[n-1];
    }
};