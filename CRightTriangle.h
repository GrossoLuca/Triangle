/*! \file CRightT.h
	\brief Declaration of the class Right Triangle

	Details.
*/


#ifndef RIGHTT_H
#define RIGHTT_H

#include<iostream>

#include "CTriangle.h"

using namespace std;

/// @class RightT
/// @brief to manage an object with the shape of a Right Triangle
class RightT : public Triangle
{
protected:
	
	float base;
	float height;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	RightT();
	RightT(float base, float height);
	RightT(const RightT &r);
	
	~RightT();
	/// @}
	
	/// @name OPERATORS
	/// @{
	RightT& operator=(const RightT &r); 
	bool operator==(const RightT &r);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const RightT &r);							
	void Reset();												
	/// @}
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float b, float h);
	
	void GetDim(float &b, float &h);
	float GetBase();
	float GetHeight();
	float GetHypo();
	float GetSide();
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
