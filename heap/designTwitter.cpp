#include <bits/stdc++.h>
using namespace std;

class Tweet {
public:
  int time;
  int tweetId;

  Tweet(int time, int tweetId) {
    this->time = time;
    this->tweetId = tweetId;
  }
};

class User {
public:
  int userId;
  unordered_set<int> followers;
  list<Tweet> tweets;

  User(int userId) {
    this->userId = userId;
    followers.insert(userId);
  }

  void addTweet(Tweet t) { tweets.push_front(t); }

  void follow(int followeeId) { followers.insert(followeeId); }

  void unfollow(int followeeId) { followers.erase(followeeId); }
};

class Twitter {
private:
  int time = 0;
  unordered_map<int, User *> userMap;

public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    if (!userMap.count(userId))
      userMap[userId] = new User(userId);
    userMap[userId]->addTweet(Tweet(++time, tweetId));
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> res;

    if (!userMap.count(userId))
      return {};

    User *user = userMap[userId];
    
    auto cmp = [](const Tweet &a, const Tweet &b) { return a.time < b.time; };
    priority_queue<Tweet, vector<Tweet>, decltype(cmp)> pq(cmp);
    
    for (auto &followeeId : user->followers) {
      int cnt = 0;
      for (auto &t : userMap[followeeId]->tweets) {
        pq.push(t);
        if(++cnt>=10)
          break;
      }
    }

    int cnt = 0;
    while(!pq.empty() && cnt <10){
      res.push_back(pq.top().tweetId);
      pq.pop();
      cnt++;
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    if (!userMap.count(followeeId))
      userMap[followeeId] = new User(followeeId);

    if (!userMap.count(followerId))
      userMap[followerId] = new User(followerId);

    userMap[followerId]->follow(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (!userMap.count(followeeId) || !userMap.count(followerId))
      return;
    userMap[followerId]->unfollow(followeeId);
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
