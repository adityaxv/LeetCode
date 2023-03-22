class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 1st method
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int cnt = 1;
        pq.push(intervals[0][1]);
        for(int i=1; i<n; i++){
            if(pq.top() > intervals[i][0]){
                pq.push(intervals[i][1]);
                cnt++;
            }
            else{
                pq.pop();
                pq.push(intervals[i][1]);
            }
        }
        return cnt;
    }
};

        // not working;
        // sort(intervals.begin(), intervals.end());
        // int n = intervals.size(), ans = 1, cnt = 1, prev = intervals[0][1];
        // for(int i=0; i<n; i++){
        //     if(i == 0) continue;
        //     if(prev <= intervals[i][0]){
        //         prev = min(intervals[i][1], intervals[i-1][1]);
        //     }
        //     else{
        //         cnt++;
        //         prev = min(intervals[i][1], intervals[i-1][1]);
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     cout << intervals[i][0] << " " << intervals[i][1] << "\n";
        // }
        // return cnt;