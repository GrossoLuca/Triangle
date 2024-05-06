/**
 * @file CTriangle.h
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Declaratoin of functions. Class generic Triangle
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<iostream>

using namespace std;

/// @class Triangle
/// @brief an abstract base class for Triangle
class Triangle 
{
protected:

	float sides[3];
	
	void SetSides(float s0, float s1, float s2); 

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Triangle();
	Triangle(const Triangle &o);
	virtual ~Triangle();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Triangle& operator=(const Triangle &o); 
	bool operator==(const Triangle &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Triangle &o);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetPerimeter();
	void GetSides(float &s0, float &s1, float &s2);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
};

#endif
