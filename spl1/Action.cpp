//
// Created by yuval on 21/11/2019.
//
#include "../include/Action.h"
#include <vector>
#include <unordered_map>
#include <string>

class Session;

enum ActionStatus{
    PENDING, COMPLETED, ERROR
};


class BaseAction{
    BaseAction():status=PENDING{}
    ActionStatus getStatus() const;
    {
        return status;
    }
    virtual void act(Session& sess)=0;
    virtual std::string toString() const=0;
protected:
    void complete()
    {
        status=COMPLETED;
    }
    void error(const std::string& errorMsg)
    {
        status=ERROR;
        this.errorMsg=*errorMsg;
    }
     std::string getErrorMsg() const
    {
        return errorMsg;
    }

};

class CreateUser  : public BaseAction {
public:
    virtual void act(Session& sess)
    {

    }
    virtual std::string toString() const
    {
        return "Create user";
    }
};

class ChangeActiveUser : public BaseAction {
public:
    virtual void act(Session& sess){ }
    virtual std::string toString() const;
};

class DeleteUser : public BaseAction {
public:
    virtual void act(Session & sess);
    virtual std::string toString() const;
};


class DuplicateUser : public BaseAction {
public:
    virtual void act(Session & sess);
    virtual std::string toString() const;
};

class PrintContentList : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual std::string toString() const;
};

class PrintWatchHistory : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual std::string toString() const;
};


class Watch : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
};


class PrintActionsLog : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
};

class Exit : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
};