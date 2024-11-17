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

User Profile::getOwner()
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

std::string Profile::getPage()
{
	std::string _pageString = "Status: " + _page.getStatus() + "\n";
	_pageString = _pageString + "*******************\n" + "*******************\n";
	_pageString = _pageString + _page.getPosts();
}

std::string Profile::getFriends()
{
	return std::string();
}

std::string Profile::getFriendsWithSameNameLength()
{
	return std::string();
}
