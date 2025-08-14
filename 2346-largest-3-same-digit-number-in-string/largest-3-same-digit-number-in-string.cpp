class Solution {
public:
    string largestGoodInteger(string num) {
        int answer =-1,first,second,third;
        for(int i=0;i<=num.size()-3;i++){
            first =num[i]-'0',second = num[i+1]-'0',third = num[i+2]-'0';
            if(first == second and second == third){
                answer = max(answer, first*100 + second*10 + third);
            }
        }
        return (answer ==-1)? "":((answer ==0)?"000":to_string(answer));
    }
};