#include "Profile.h"

void Profile::init(User owner)
{
	_user = owner;
	_page.init();
	_friendsList.init();
}

void Profile::clear()
{
	_user.clear();
	_page.cleanPage();
	_page.setStatus("");
	_friendsList.clear();
}

User Profile::getOwner() const
{
	return _user;
}

void Profile::setStatus(std::string new_status)
{
	_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	_page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	_friendsList.add(friend_to_add);
}

std::string Profile::getPage() const
{
	std::string pageString = "Status: " + _page.getStatus() + "\n";
	pageString = pageString + "*******************\n" + "*******************\n";
	pageString = pageString + _page.getPosts();
	return pageString;
}

std::string Profile::getFriends() const
{
	std::string friendsString = "";
	UserNode* curr = _friendsList.get_first();
	int stringLength = 0;
	while (curr)
	{
		friendsString = friendsString + curr->get_data().getUserName() + ",";
		curr = curr->get_next();
	}
	stringLength = friendsString.length();
	friendsString.resize(stringLength - 1);
	return friendsString;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	int userNameSize = _user.getUserName().length();
	std::string friendsString = "";
	int friendsLength = 0;
	UserNode* curr = _friendsList.get_first();
	while (curr)
	{
		if (curr->get_data().getUserName().length() == userNameSize)
		{
			friendsString = friendsString + curr->get_data().getUserName() + ",";
		}
		curr = curr->get_next();
	}
	friendsLength = friendsString.length();
	if (friendsLength >= 1)
		friendsString.resize(friendsLength - 1);
	return friendsString;
}

void Profile::changeAllWordsInStatus(std::string word)
{
	int spaceCounter = 0;
	int statusLength = _page.getStatus().length();
	std::string status = _page.getStatus();
	std::string newStatus = "";
	int i = 0;
	for (i = 0; i < statusLength; i++)
	{
		if (status[i] == ' ')
		{
			spaceCounter++;
		}
	}
	spaceCounter++;
	for (i = 0; i < spaceCounter; i++)
	{
		newStatus += word + " ";
	}
	_page.setStatus(newStatus);
	
}

void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word)
{
	std::string status = _page.getStatus();
	size_t index = status.find(word_to_replace); //size_t should be used for the find method
	while (index != std::string::npos)//find method returns npos if nothing found so if status.find() == std::string::npos the string wasnt found
	{
		status.replace(index, word_to_replace.size(), new_word);
		index = status.find(word_to_replace);
	}
}
