class Solution {
public:
    double myPow(double x, int n) {
        int nn = n;
        if(n < 0){
            if(n == INT_MIN){
                n = INT_MAX;
            }else{
                n = (-1 * n);
            }
        }

        double ans = 1;

        while(n){
            if(n%2 == 0){
                x = x*x;
                n = n/2;
            }else{
                ans = ans * x;
                n = n-1;
            }
        }
        if(nn<0){
            ans = (1.0/ans);
            if(nn == INT_MIN){
                ans = 1/x;
            }
        }
        return ans;
    }
};
