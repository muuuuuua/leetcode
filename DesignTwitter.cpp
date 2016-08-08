/**
 * 355. Design Twitter
 */
#include "inc/common.h"

struct Tweet {
    int id;
    int timestamp;
    Tweet(int a, int t):id(a),timestamp(t) {}
};

bool cmp(Tweet a, Tweet b) {
    return a.timestamp > b.timestamp;
}

class Twitter {
private:
    unordered_map<int, vector<Tweet> > tweetMap;
    unordered_map<int, unordered_set<int> > followMap;
    int timestamp;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(tweetMap.find(userId) == tweetMap.end()) {
            vector<Tweet> tweetList;
            tweetList.push_back(Tweet(tweetId, timestamp++));
            tweetMap[userId] = tweetList;
        }
        else {
            tweetMap[userId].insert(tweetMap[userId].begin(), Tweet(tweetId, timestamp++));
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int n = 10;
        vector<int> res;
        vector<vector<Tweet> > newsFeed;
        newsFeed.push_back(tweetMap[userId]);
        if(followMap.find(userId) != followMap.end()) {
            unordered_set<int> followee = followMap[userId];
            for(unordered_set<int>::iterator it = followee.begin();it != followee.end();it++) {
                if(tweetMap.find(*it) != tweetMap.end())
                    newsFeed.push_back(tweetMap[*it]);
            }
        }
        vector<Tweet> list;
        for(int i = 0;i < newsFeed.size();i++) {
            for(int j = 0;j < newsFeed[i].size();j++)
                list.push_back(newsFeed[i][j]);
        }
        sort(list.begin(), list.end(), cmp);
        n = n < list.size()?n:list.size();
        for(int i = 0;i < n;i++)
            res.push_back(list[i].id);
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter = Twitter();
    vector<int> r;
    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    r = twitter.getNewsFeed(1);
    print(r);
    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    r = twitter.getNewsFeed(1);
    print(r);

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    r = twitter.getNewsFeed(1);
    print(r);

    return 0;
}