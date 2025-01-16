class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // //Brute Force
        // int m=nums1.size();
        // int n=nums2.size();
        // vector<int>nums3(m*n);
        // int count=0;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         nums3[count++]=nums1[i]^nums2[j];
        //     }
        // }

        // int result=nums3[0];
        // for(int i=1;i<nums3.size();i++){
        //     result=result^nums3[i];
        // }

        // return result;

        int m=nums1.size();
        int n=nums2.size();

        unordered_map<int,long>mp;

        for(auto it:nums1){
            mp[it] += n;
        }

        for(auto it:nums2){
            mp[it] += m;
        }

        int result=0;
        for(auto it:mp){
            int num=it.first;
            if(it.second%2!=0){
                //Odd Occurence
                result=result^num;
            }
        }
        return result;
    }
};


// nums1 = [2,1,3], nums2 = [4,5]
// nums3=[(2^4)^(2^5)^(1^4)^(1^5)^(3^4)^(3^5)]

// As we know XOR operation is associative and commutative.
// a^b=b^a
// a^(b^c)=c^(a^b)
// This can be rewritten as:
// nums3=[(2^2)^(4^5)^(1^1)^(4^5)^(3^3)^(4^5)]
// So, 2 was XORed 2 times (2^4)^(2^5) i.e. appeared 2 times so 2^2=0
// So, 4 appeared 3 times 4^4^4=0^4=4

// So, even occurences get cancel out and odd occurences only need to be considered

