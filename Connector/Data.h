#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Data
{
public:
	friend std::ostream& operator<< (std::ostream& stream_out, const Data& obj)
	{
		obj.out(stream_out);
		return stream_out;
	}
	friend std::istream& operator>> (std::istream& stream_in, Data& obj)
	{
		obj.in(stream_in);
		return stream_in;
	}

private:
	virtual void out(std::ostream& out) const = 0;
	virtual void in(std::istream& in) = 0;
};

class Resolution : public Data
{
private:
	int width{1920};
	int height{1080};

private:
	void out(std::ostream& out) const override
	{
		out << width << "X" << height;
	}
	void in(std::istream& in) override
	{
		std::fstream* file = dynamic_cast<std::fstream*>(&in);
		if (file)
		{
			char temp[256]{};
			file->getline(temp, 256, 'X');
			width = std::atoi(temp);
			file->getline(temp, 256);
			height = std::atoi(temp);
		}
		else
			in >> width >> height;
	}
};

class Point : public Data
{
private:
	int x;
	int y;

	public:
	Point(int x, int y) : x{ x }, y{ y } {}

private:
	void out(std::ostream& out) const override
	{
		out << "(" << x << "," << y <<")";
	}
	void in(std::istream& in) override
	{
		std::fstream* file = dynamic_cast<std::fstream*>(&in);
		if (file)
		{
			std::string num{};
			char ch;
			int* ptr_param = &x;
			while (!file->eof())
			{
				file->get(ch);
				if (ch >= '0' && ch <= '9')
					num += ch;
				else if (num != "")
				{
					*ptr_param = stoi(num);
					ptr_param = &y;
					num = "";
				}
			}
		}
		else
			in >> x >> y;
	}
};
