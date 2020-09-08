//
// Created by yuval on 21/11/2019.
//
#include "../include/User.h"
class Watchable;//?
class Session;//?

class User{

    User(const std::string& name):this.name=name{}
    virtual Watchable* getRecommendation(Session& s) = 0{}
    std::string getName() const{}
    {
        return name;
    }

};


class LengthRecommenderUser : public User {

    LengthRecommenderUser(const std::string& name):User(name),avgLength=0{}
    virtual Watchable* getRecommendation(Session& s){}


};

class RerunRecommenderUser : public User {
    RerunRecommenderUser(const std::string& name):User(name){}
    virtual Watchable* getRecommendation(Session& s){}
};

class GenreRecommenderUser : public User {

    GenreRecommenderUser(const std::string& name):User(name){}
    virtual Watchable* getRecommendation(Session& s)
    {

    }

};
