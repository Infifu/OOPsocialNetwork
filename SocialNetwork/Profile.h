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
	User getOwner() const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;
	void changeAllWordsInStatus(std::string word);
	void changeWordInStatus(std::string word_to_replace, std::string new_word);
};