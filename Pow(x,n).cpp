class Solution {
public:
    double myPow(double x, long long n) {
        if(x==1){
            return x;
        }
        double total=1;
        int flag=0;
        if(n<0){
            n= -1*n;
            flag =1;
        }
        while(n){
            if(n%2){
                total *=x;
                n-=1;
            }
            else{
                x*=x;
                n/=2;
            }
        }
        if(flag==1){
            return 1/total;
        }
        return total;
    }
};
