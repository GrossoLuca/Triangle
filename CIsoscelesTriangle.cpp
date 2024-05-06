/**
 * @file CIsoscelesTriangle.cpp
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Implementation of functions. Class Isosceles Triangle
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream> 
#include<cmath>
#include "CIsoscelesTriangle.h"

/// @brief default constructor 
IsoscelesT::IsoscelesT() 
{
	cout << "IsoscelesT - constructor - default" << endl;

	Init();
}

/// @brief Constructor
/// @param base base of triangle
/// @param side two of the equal sides of triangle
IsoscelesT::IsoscelesT(float base, float side) 
{
	Init();

	cout << "IsoscelesT - constructor" << endl;

	if (base <= 0. || side <= 0.) {
		WarningMessage("constructor: sides should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(base,side);
}

/// @brief destructor 
IsoscelesT::~IsoscelesT() 
{
	cout << "IsoscelesT - destructor" << endl;
	Reset();
}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
IsoscelesT::IsoscelesT(const IsoscelesT &r) 
{ 
	cout << "IsoscelesT - copy constructor" << endl;

	Init(r);	
}

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
IsoscelesT& IsoscelesT::operator=(const IsoscelesT &r) 
{ 
	cout << "IsoscelesT - operator =" << endl;

	Init(r);
	
	return *this;	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
bool IsoscelesT::operator==(const IsoscelesT &r) 
{ 
	if (r.base == base && r.side == side)
		return true;
	return false;
}

/// @brief default initialization of the object
void IsoscelesT::Init() 
{
	SetDim(0,0);
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void IsoscelesT::Init(const IsoscelesT &r) 
{	
	Init();
	SetDim(r.base,r.side);
}

/// @brief total reset of the object  
void IsoscelesT::Reset() 
{	
	SetDim(0,0);	
}

/// @brief set the dimensions of triangle
/// @param base base of triangle
/// @param s sides of triangle
void IsoscelesT::SetDim(float b, float s) 
{
	base=b;
	side=s;
	Triangle::SetSides(b,s,s);
	return;
}

/// @brief give the dimensions of triangle
/// @param base base of triangle
/// @param s sides of triangle
void IsoscelesT::GetDim(float &b, float &s) 
{
	b=base;
	s=side;
	return;
}

/// @brief get base
/// @return value of the base
float IsoscelesT::GetBase()
{
	return base;
}

/// @brief get Side
/// @return value of both equal sides
float IsoscelesT::GetSide()
{
	return side;
}

/// @brief compute the Height of triangle
/// @return float value of Height
float IsoscelesT::GetHeight() 
{
	float height=0.;
    height=sqrt(side*side+((base*base)/4));
    return height;
}

/// @brief computes the area of the object
/// @return the area 
float IsoscelesT::GetArea() 
{	
	return (base*GetHeight()/2);
}

/// @brief return the values of the angles
/// @param a1 Base angles
/// @param a2 Height angle
void IsoscelesT::GetAngles(float &a1, float &a2)
{
	//lato*cos(a)=b/2
    a1=acos((float)base/(2*side));  //Angles at the base of the triangle
    a2=180-2*a1;                    //Angle at the height of the triangle
    return;
}

/// @brief write an error message 
/// @param string message to be printed
void IsoscelesT::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- Isosceles Triangle --";
	cout << string << endl;
    return;
}

/// @brief write a warning message 
/// @param string message to be printed
void IsoscelesT::WarningMessage(const char *string) 
{
	cout << endl << "WARNING -- IsoscelesT --";
	cout << string << endl;
    return;
}


/// @brief for debugging: all about the object
void IsoscelesT::Dump()
{
	cout << endl;
	cout << "---Isosceles Triangle---" << endl; 
	cout << endl;
	
	cout << "Base = " << base << endl;
    cout << "Sides = " << side << endl;
	cout << "Height = " << GetHeight() << endl; 
	cout << "Area = " << GetArea() << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	
	Triangle::Dump();
	
	cout << endl;
    return;
}
