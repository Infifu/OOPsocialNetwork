#pragma once
#include <string>
#include "UserList.h"
#include "Page.h";
class Profile
{
private:
	User _user;
	Page _page;
	UserList _friendsList;
public:
	void init(User owner);
	void clear();
	User getOwner();
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage();
	std::string getFriends();
	std::string getFriendsWithSameNameLength();

};