/**
 * @file CEquilateralTriangle.h
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Declaration of functions. Class Equilateral Triangle
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef EQUILATERALT_H
#define EQUILATERALT_H

#include<iostream>

#include "CTriangle.h"

using namespace std;

/// @class EquilateralT
/// @brief to manage an object with the shape of a Equilateral Triangle
class EquilateralT : public Triangle
{
protected:
	
	float side;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	EquilateralT();
	EquilateralT(float side);
	EquilateralT(const EquilateralT &r);
	
	~EquilateralT();
	/// @}
	
	/// @name OPERATORS
	/// @{
	EquilateralT& operator=(const EquilateralT &r); 
	bool operator==(const EquilateralT &r);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const EquilateralT &r);							
	void Reset();												
	/// @}
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float s);
	
	void GetDim(float &s);
	float GetSide();
    float GetHeight();
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
