class Solution {
    
private:

    struct Fraction{
    int numerator;
    int denominator;
    double fraction;
    };
    
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<Fraction>Value;
        
        for(int i=0;i<arr.size();i++){  //Storing in struct
            for(int j=i+1;j<arr.size();j++){
                Value.push_back({arr[i],arr[j],double(arr[i])/arr[j]});
            }
        }
        
        // Use std::sort with a lambda to sort fractions based on their values
        sort(Value.begin(), Value.end(), [](const Fraction& a, const Fraction& b) {
            return a.fraction < b.fraction;
        });
        
        /*The lambda function [](const Fraction& a, const Fraction& b) { return a.fraction <           b.fraction; } is used as a comparator to sort Fraction objects by their value.               The std::sort function will rearrange the fractions vector such that the                     elements are in ascending order based on their value.*/
        
        return {Value[k-1].numerator,Value[k-1].denominator};
    }
};