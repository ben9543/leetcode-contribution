class Twitter {
public:
    
    // Each user will have feed
    // Push the feed to all users that have the feed's tweetId
    vector<vector<bool>> followerMatrix;
    priority_queue<vector<int>> feedTimeline; // <time, userId, tweetId>
    int time = 0;
    
    Twitter() {
        followerMatrix = vector<vector<bool>>(501, vector<bool>(501, false));
        for(int i = 0; i < 501; i++)
            followerMatrix[i][i] = true;
    }
    
    void postTweet(int userId, int tweetId) {
        feedTimeline.push({time, userId, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>> cp = feedTimeline;
        while(res.size() < 10 && !cp.empty()){
            vector<int> data = cp.top();
            // int t = data[0];
            int uid = data[1];
            int tid = data[2];
            if(followerMatrix[userId][uid]){
                res.push_back(tid);
            }
            cp.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followerMatrix[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMatrix[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */