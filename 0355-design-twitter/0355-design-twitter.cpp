class Twitter {
    
private:
    vector<pair<int, int>> posts;
    unordered_map<int, unordered_set<int>> following;
    
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newFeed;
        int count = 10;
        
        // Posts are already ordered by created time 
        for(int i = posts.size()-1; i >= 0; i--){
            if(count <= 0) break;
            int author = posts[i].first;
            int tweetId = posts[i].second;
            unordered_set<int> s = following[userId];
            s.find(userId);
            if(author == userId || s.find(author) != s.end()){
                newFeed.push_back(tweetId);
                count--;
            }
        }
        
        return newFeed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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