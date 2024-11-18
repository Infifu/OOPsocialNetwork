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
	while (curr) //loop through the _friendlist linked list
	{
		friendsString = friendsString + curr->get_data().getUserName() + ","; //extract friends name and connect to string
		curr = curr->get_next();
	}
	stringLength = friendsString.length(); //get the length of the string
	friendsString.resize(stringLength - 1); //remove the trailing comma ,
	return friendsString;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	int userNameSize = _user.getUserName().length();
	std::string friendsString = "";
	int friendsLength = 0;
	UserNode* curr = _friendsList.get_first();
	while (curr) //loop through the _friendslist linked list
	{
		if (curr->get_data().getUserName().length() == userNameSize) //check if friends name lengh matches user name length
		{
			friendsString = friendsString + curr->get_data().getUserName() + ","; //if it does, add it the the string
		}
		curr = curr->get_next();
	}
	friendsLength = friendsString.length();
	if (friendsLength >= 1) 	//check if the friendsString not empty
		friendsString.resize(friendsLength - 1); //if its not remove the trailing comma
	return friendsString;
}

void Profile::changeAllWordsInStatus(std::string word)
{
	int spaceCounter = 0;
	int statusLength = _page.getStatus().length();
	std::string status = _page.getStatus();
	std::string newStatus = "";
	int i = 0;
	for (i = 0; i < statusLength; i++) //check the amount of words in status by looping through the status
	{									//and count the amount of spaces
		if (status[i] == ' ')
		{
			spaceCounter++;
		}
	}
	spaceCounter++; //add one space for the last word
	for (i = 0; i < spaceCounter; i++) //spaceCounter = amount of words
	{									//loop through the spaceCounter and add one word for every i
		newStatus += word + " "; 
	}
	_page.setStatus(newStatus);
	
}

void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word)
{
	std::string status = _page.getStatus();
	int index = status.find(word_to_replace); //find the starting index of the first occurence
	while (index != std::string::npos) //npos = no positon meaning nothing found, loop while find function doesnt return npos
	{
		status.replace(index, word_to_replace.size(), new_word); //replace function, needs the starting index of ther word
																//the size of the word that needs to be replaced, and the new word
		index = status.find(word_to_replace, index + new_word.size()); //checks if any more occurances
	}
	_page.setStatus(status); //upload the status
 
}
