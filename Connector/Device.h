#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Data.h"

class Device
{
protected:
	Data* data{};

public:
	virtual void out() = 0;
	virtual void in() = 0;
	friend class Connector;
};

class Monitor: public Device
{
public:
	void out() override
	{
		std::cout << *data;
	}
	void in() override
	{
		std::cin >> *data;
	}
};

class File : public Device
{
private:
	std::fstream file;
	std::string path{};

public:
	File(std::string path) : path{ path } {}

public:
	void new_file(std::string new_path) { new_path = path; }
	void out() override
	{
		file.open(path, std::ios::out);
		file << *data;
		file.close();
	}
	void in() override
	{
		file.open(path, std::ios::in);
		file >> *data;
		file.close();
	}
};

class Printer : public Device
{
public:
	void out() override {}
	void in() override {}
};

class Scaner : public Device
{
public:
	void out() override {}
	void in() override {}
};

class Network : public Device
{
private:
	int ip;
public:
	void out() override {}
	void in() override {}
};
