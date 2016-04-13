#pragma once
#include <string>

class IBody
{
public:
	virtual ~IBody();

	// TODO: RENAME isDataMoreZero TO IsDataMoreZero 
	virtual bool IsDataMoreZero() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetDensity() const = 0;
	virtual double GetMass() const = 0;
	virtual std::string GetInfo() const = 0;
};
