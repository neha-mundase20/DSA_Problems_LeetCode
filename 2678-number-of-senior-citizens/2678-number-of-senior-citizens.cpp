class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCitizenCount=0;

        for(int i=0;i<details.size();i++){
            string answer;
            answer.push_back(details[i][11]);
            answer.push_back(details[i][12]);

            int age=stoi(answer);

            if(age>60){
                seniorCitizenCount++;
            }
        }

        return seniorCitizenCount;
    }
};