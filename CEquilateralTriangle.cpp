/**
 * @file CEquilateralTriangle.cpp
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Implementation of functions. Class Equilateral Triangle
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream> 
#include<cmath>
#include "CEquilateralTriangle.h"

/// @brief default constructor 
EquilateralT::EquilateralT() 
{
	cout << "EquilateralT - constructor - default" << endl;

	Init();
}

/// @brief Constructor
/// @param side side of triangle
EquilateralT::EquilateralT(float side) 
{
	Init();

	cout << "EquilateralT - constructor" << endl;

	if (side <= 0.) {
		WarningMessage("constructor: side should be > 0"); 
		SetDim(0);
	}
	else
		SetDim(side);
}

/// @brief destructor 
EquilateralT::~EquilateralT() 
{
	cout << "EquilateralT - destructor" << endl;
	Reset();
}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
EquilateralT::EquilateralT(const EquilateralT &r) 
{ 
	cout << "EquilateralT - copy constructor" << endl;

	Init(r);	
}

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
EquilateralT& EquilateralT::operator=(const EquilateralT &r) 
{ 
	cout << "EquilateralT - operator =" << endl;

	Init(r);
	
	return *this;	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
bool EquilateralT::operator==(const EquilateralT &r) 
{ 
	if (r.side == side)
		return true;
	return false;
}

/// @brief default initialization of the object
void EquilateralT::Init() 
{
	SetDim(0);
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void EquilateralT::Init(const EquilateralT &r) 
{	
	Init();
	SetDim(r.side);
}

/// @brief total reset of the object  
void EquilateralT::Reset() 
{	
	SetDim(0);	
}

/// @brief set the dimensions of triangle
/// @param s side of triangle
void EquilateralT::SetDim(float s) 
{
	side=s;
	Triangle::SetSides(s,s,s);
	return;
}

/// @brief give the dimensions of triangle
/// @param s side of triangle
void EquilateralT::GetDim(float &s) 
{
	s=side;
	return;
}

/// @brief get base
/// @return value of the base
float EquilateralT::GetSide()
{
	return side;
}

/// @brief compute the Height of triangle
/// @return float value of Height
float EquilateralT::GetHeight() 
{
    return (sqrt(3.)/2)*side;
}

/// @brief write an error message 
/// @param string message to be printed
void EquilateralT::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- Equilateral Triangle --";
	cout << string << endl;
    return;
}

/// @brief write a warning message 
/// @param string message to be printed
void EquilateralT::WarningMessage(const char *string) 
{
	cout << endl << "WARNING -- EquilateralT --";
	cout << string << endl;
    return;
}


/// @brief for debugging: all about the object
void EquilateralT::Dump()
{
	cout << endl;
	cout << "---Equilateral Triangle---" << endl; 
	cout << endl;
	
    cout << "Sides = " << side << endl;
	cout << "Height = " << GetHeight() << endl; 
	cout << "Area = " << GetArea() << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	
	Triangle::Dump();
	
	cout << endl;
    return;
}
