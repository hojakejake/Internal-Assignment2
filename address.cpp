/*
 * address.cpp
 *
 *  Created on: 2017¦~12¤ë20¤é
 *      Author: Jake
 */
#include "address.h"
std::vector<Entry> Address::entries;
bool Address::parse_arg(const std::vector<std::string>& arguments){
	if(arguments.size() == 3 && arguments[0] == "add"){
		std::pair<int,bool> value = Address::strtoint(arguments[2],false);
		if(value.second)
			return Address::add_entry(arguments[1], value.first);
		else
			return false;
	}
	else if(arguments.size() == 2 && arguments[0] == "del"){
		std::pair<int,bool> address = Address::strtoint(arguments[1],true);
		if(address.second)
			return Address::del_entry((int*)address.first);
		else
			return false;
	}
	else if(arguments.size() == 3 && arguments[0] == "chg"){
		std::pair<int,bool> address = Address::strtoint(arguments[1],true);
		std::pair<int,bool> value = Address::strtoint(arguments[2]);
		if(address.second && value.second)
			return Address::chg_entry((int*)address.first,value.first);
		else
			return false;

	}
	else
		return false;
	return false;
}

bool Address::add_entry(const std::string &name, const int& value){
	entries.push_back(Entry(name,new int(value)));
	return true;
}

bool Address::del_entry(int *address){
	for(int i = 0 ; i < (int)entries.size(); i++){
		if(entries[i].addr_ == address){
			delete entries[i].addr_;
			entries.erase(entries.begin()+i);
			return true;
		}
	}
	return false;
}

bool Address::chg_entry(int *address, const int& value){
	for(int i = 0 ; i < (int)entries.size(); i++){
		if(entries[i].addr_ == address){
			*entries[i].addr_ = value;
			return true;
		}
	}
	return false;
}

void Address::print_data(){
	std::cout << "Address\t\tName\tValue" << std::endl;
	for(int i = 0 ; i < (int)entries.size(); i++){
		std::cout << entries[i].addr_ << "\t" << entries[i].name_ << "\t" << *entries[i].addr_ << std::endl;
	}
	return;
}
