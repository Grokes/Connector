#pragma once
#include "Device.h"
#include "Data.h"

class Connector
{
private:
	Device* device{};
public:
	void operator() (Data& data, Device& device_new)
	{
		if (device)
			device->data = nullptr;
		device_new.data = &data;
		device = &device_new;
	}
};
