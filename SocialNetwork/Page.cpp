#include "Page.h"

void Page::init()
{
	_status = "";
	_posts = "";
}

std::string Page::getPosts() const
{
	return _posts;
}

std::string Page::getStatus() const
{
	return _status;
}

void Page::cleanPage()
{
	_posts = "";
}

void Page::setStatus(std::string status)
{
	_status = status;
}

void Page::addLineToPosts(std::string new_line)
{
	_posts = _posts + new_line + "\n";
}
