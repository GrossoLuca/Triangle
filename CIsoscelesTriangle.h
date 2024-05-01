/*! \file CIsoscelesT.h
	\brief Declaration of the class Isosceles Triangle

	Details.
*/


#ifndef ISOSCELEST_H
#define ISOSCELEST_H

#include<iostream>

#include "CTriangle.h"

using namespace std;

/// @class IsoscelesT
/// @brief to manage an object with the shape of a Isosceles Triangle
class IsoscelesT : public Triangle
{
protected:
	
	float base;
	float side;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	IsoscelesT();
	IsoscelesT(float base, float side);
	IsoscelesT(const IsoscelesT &r);
	
	~IsoscelesT();
	/// @}
	
	/// @name OPERATORS
	/// @{
	IsoscelesT& operator=(const IsoscelesT &r); 
	bool operator==(const IsoscelesT &r);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const IsoscelesT &r);							
	void Reset();												
	/// @}
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float b, float s);
	
	void GetDim(float &b, float &s);
	float GetBase();
	float GetSide();
    float GetHeight();
	void GetAngles(float &a1, float &a2);	
	
	float GetArea();
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
		
};

#endif
