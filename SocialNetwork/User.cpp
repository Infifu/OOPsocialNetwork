#include "User.h"

void User::init(unsigned int id, std::string username, unsigned int age)
{
	_id = id;
	_username = username;
	_age = age;
	_list.init();
}

void User::clear()
{
	_id = 0;
	_username = "";
	_age = 0;
	_list.clear();
}

unsigned int User::getID() const
{
	return _id;
}

std::string User::getUserName() const
{
	return _username;
}

unsigned int User::getAge() const
{
	return _age;
}

DevicesList& User::getDevices()
{
	return _list;
}

void User::addDevice(Device newDevice)
{
	_list.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode *curr = _list.get_first();
	while (curr)
	{
		if (curr->get_data().isActive() == false)
		{
			return false;
		}
		curr = curr->get_next();
	}
	return true;
}
