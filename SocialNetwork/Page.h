#pragma once
#include <string>

class Page
{
private:
	std::string _status;
	std::string _posts;
public:
	void init();
	std::string getPosts() const;
	std::string getStatus() const;
	void cleanPage();
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);
};