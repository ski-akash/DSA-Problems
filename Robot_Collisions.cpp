class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector< vector<int> > r(n);
        vector< pair<int,int> > safe; // < order_i, healths_i > 

        for(int i=0;i<n;i++){
            vector<int> v = {positions[i],i,healths[i],directions[i]};
            r[i] = v;
        }
        
        // sort r according to pos
        sort(r.begin(),r.end(),[](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });

        stack< pair<int,int> > st; // < order_i, health_i > 
        for(int i=0;i<n;i++){
            int ord = r[i][1], H = r[i][2], dir = r[i][3];
            while(1){
                if(dir == 'R'){
                    st.push({ord,H}); break;
                }
                else if(st.empty() && dir == 'L') {
                    safe.push_back({ord,H}); break;
                }
                else {
                    int Top_o = st.top().first, Top_h = st.top().second;
                    if(H == Top_h){
                        st.pop(); break;
                    }
                    else if(H < Top_h){
                        st.pop(); 
                        st.push({Top_o, Top_h-1}); break;
                    }
                    else{
                        st.pop();
                        H -= 1;
                    }
                }
            }
        }

        while(!st.empty()){
            safe.push_back(st.top());
            st.pop();
        }

        sort(safe.begin(),safe.end());
        vector<int> ans;
        for(auto it : safe) ans.push_back(it.second);
        return ans;
    }
};