/*! \file CScaleneTriangle.h
	\brief Declaration of the class Right Triangle

	Details.
*/


#ifndef SCALENET_H
#define SCALENET_H

#include<iostream>

#include "CTriangle.h"

using namespace std;

/// @class ScaleneT
/// @brief to manage an object with the shape of a Right Triangle
class ScaleneT : public Triangle
{

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	ScaleneT();
	ScaleneT(float s0, float s1, float s2);
	ScaleneT(const ScaleneT &r);
	
	~ScaleneT();
	/// @}
	
	/// @name OPERATORS
	/// @{
	ScaleneT& operator=(const ScaleneT &r); 
	bool operator==(const ScaleneT &r);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const ScaleneT &r);							
	void Reset();												
	/// @}
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float s0, float s1, float s2);
	
	void GetDim(float &s0, float &s1, float &s2);
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
