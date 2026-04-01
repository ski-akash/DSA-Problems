class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
                continue;
            }
            while(true){
                if(st.empty()){
                    ans.push_back(asteroids[i]); break;
                }
                else{
                    int Top = st.top(), cur_val = abs(asteroids[i]);
                    if(cur_val == Top){
                        st.pop(); break;
                    }
                    else if(cur_val < Top) break;
                    else st.pop();
                }
            }
        }

        vector<int> r;
        while(!st.empty()){
            r.push_back(st.top());
            st.pop();
        }

        reverse(r.begin(),r.end());
        for(int elem : r) ans.push_back(elem);
        return ans;
    }
};