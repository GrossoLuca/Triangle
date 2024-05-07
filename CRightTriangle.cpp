/**
 * @file CRightTriangle.cpp
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Implementation of functions. Class Right Triangle
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream> 
#include<cmath>
#include "CRightTriangle.h"

/// @brief default constructor 
RightT::RightT() 
{
	cout << "RightT - constructor - default" << endl;

	Init();
}

/// @brief Constructor
/// @param base base of triangle
/// @param height height of triangle
RightT::RightT(float base, float height) 
{
	Init();

	cout << "RightT - constructor" << endl;

	if (base <= 0. || height <= 0.) {
		WarningMessage("constructor: sides should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(base,height);
}

/// @brief destructor 
RightT::~RightT() 
{
	cout << "RightT - destructor" << endl;
	Reset();
}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
RightT::RightT(const RightT &r) 
{ 
	cout << "RightT - copy constructor" << endl;

	Init(r);	
}

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
RightT& RightT::operator=(const RightT &r) 
{ 
	cout << "RightT - operator =" << endl;

	Init(r);
	
	return *this;	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
bool RightT::operator==(const RightT &r) 
{ 
	if (r.base == base && r.height == height)
		return true;
	return false;
}

/// @brief default initialization of the object
void RightT::Init() 
{
	SetDim(0,0);
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void RightT::Init(const RightT &r) 
{	
	Init();
	SetDim(r.base,r.height);
}

/// @brief total reset of the object  
void RightT::Reset() 
{	
	SetDim(0,0);	
}

/// @brief set the dimensions of triangle
/// @param base base of triangle
/// @param height height of triangle
void RightT::SetDim(float b, float h) 
{
	this->base=b;
	this->height=h;
	Triangle::SetSides(b,h,GetHypo());
	return;
}

/// @brief give the dimensions of triangle
/// @param base base of triangle
/// @param height height of triangle
void RightT::GetDim(float &b, float &h) 
{
	b=this->base;
	h=this->height;
	return;
}

/// @brief get base
/// @return base
float RightT::GetBase()
{
	return base;
}

/// @brief get height
/// @return height
float RightT::GetHeight()
{
	return height;
}

/// @brief compute the hypotenuse of triangle
/// @return float value of hypotenuse
float RightT::GetHypo() 
{
	float hypo=0.;
	hypo=sqrt(base*base+height*height);
	return hypo;
}

/// @brief return the values of the angles
/// @param a1 Base angle
/// @param a2 Height angle
void RightT::GetAngles(float &a1, float &a2)
{
	float hypo=GetHypo();
	a1=acos(float(hypo/base));
	a2=90-a1;
}

/// @brief write an error message 
/// @param string message to be printed
void RightT::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- Right Triangle --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
void RightT::WarningMessage(const char *string) 
{
	cout << endl << "WARNING -- RightT --";
	cout << string << endl;
}


/// @brief for debugging: all about the object
void RightT::Dump()
{
	cout << endl;
	cout << "---Right Triangle---" << endl; 
	cout << endl;
	
	cout << "Base = " << base << endl;
	cout << "Height = " << height << endl; 
	cout << "Hypotenuse = " << GetHypo() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	
	Triangle::Dump();
	
	cout << endl;
}
