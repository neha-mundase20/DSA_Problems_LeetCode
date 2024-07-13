class Solution {
public:

    struct robot{
        int position;
        int health;
        char direction;
        int index;
    };

    static bool compare(const robot&a,const robot&b){ //Operator overloading
        return a.position<b.position;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<robot>robotGame(n);

        for(int i=0;i<n;i++){
            robotGame[i].position=positions[i];
            robotGame[i].health=healths[i];
            robotGame[i].direction=directions[i];
            robotGame[i].index=i;
        }

        sort(robotGame.begin(),robotGame.end(),compare);

        stack<robot> s;
        unordered_map<int, int> survivingHealth;

        for (auto& r : robotGame) {
            if (r.direction == 'R') {
                s.push(r);
            } else {
                while (!s.empty() && s.top().direction == 'R') {
                    auto top = s.top();
                    s.pop();

                    if (top.health > r.health) {
                        top.health -= 1;
                        r.health = 0;
                        s.push(top);
                        break;
                    } else if (top.health < r.health) {
                        r.health -= 1;
                        top.health = 0;
                    } else {
                        r.health = 0;
                        top.health = 0;
                        break;
                    }
                }
                if (r.health > 0) {
                    s.push(r);
                }
            }
        }

        // Collect the surviving robots' healths
        while (!s.empty()) {
            auto r = s.top();
            s.pop();
            if (r.health > 0) {
                survivingHealth[r.index] = r.health;
            }
        }

        vector<int> result;
        for (int i = 0; i < positions.size(); i++) {
            if (survivingHealth.count(i)) {
                result.push_back(survivingHealth[i]);
            }
        }

        return result;
    }
};