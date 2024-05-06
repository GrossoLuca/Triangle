/**
 * @file CScaleneTriangle.cpp
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Implementation of functions. Class Scalene Triangle
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream> 
#include<cmath>
#include "CScaleneTriangle.h"

/// @brief default constructor 
ScaleneT::ScaleneT() 
{
	cout << "ScaleneT - constructor - default" << endl;

	Init();
}

/// @brief constructor
/// @param s0 side 0
/// @param s1 side 1
/// @param s2 side 2
ScaleneT::ScaleneT(float s0, float s1, float s2) 
{
	Init();

	cout << "ScaleneT - constructor" << endl;

	if (s0<=s1+s2 || s1<=s0+s2 || s2<=s0+s1)    //A triangle exixst only when each side is
    {                                           //less than the sum of the other two sides
		WarningMessage("constructor: impossible triangle."); 
		SetDim(0,0,0);
	}
	else if (s0<=0 || s1<=0 || s2<=0)
    {
		WarningMessage("constructor: sides should be >0."); 
		SetDim(0,0,0);
    }
		SetDim(s0,s1,s2);
}

/// @brief destructor 
ScaleneT::~ScaleneT() 
{
	cout << "ScaleneT - destructor" << endl;
	Reset();
}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
ScaleneT::ScaleneT(const ScaleneT &r) 
{ 
	cout << "ScaleneT - copy constructor" << endl;

	Init(r);	
}

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
ScaleneT& ScaleneT::operator=(const ScaleneT &r) 
{ 
	cout << "ScaleneT - operator =" << endl;

	Init(r);
	
	return *this;	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
bool ScaleneT::operator==(const ScaleneT &r) 
{ 
	if (r.sides[0] == sides[0] && r.sides[1] == sides[1] && r.sides[2] == sides [2])
		return true;
	return false;
}

/// @brief default initialization of the object
void ScaleneT::Init() 
{
	SetDim(0,0,0);
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void ScaleneT::Init(const ScaleneT &r) 
{	
	Init();
	SetDim(r.sides[0],r.sides[1],r.sides[2]);
}

/// @brief total reset of the object  
void ScaleneT::Reset() 
{	
	SetDim(0,0,0);	
}

/// @brief function to set dimensions
/// @param s0 side 0
/// @param s1 side 1
/// @param s2 side 2
void ScaleneT::SetDim(float s0, float s1, float s2) 
{
	sides[0]=s0;
    sides[1]=s1;
    sides[2]=s2;
	return;
}

/// @brief give the dimension of existing triangle
/// @param s0 side 0
/// @param s1 side 1
/// @param s2 side 2
void ScaleneT::GetDim(float &s0, float &s1, float &s2) 
{
	s0=sides[0];
	s1=sides[1];
	s2=sides[2];
	return;
}

/// @brief computes the area of the object
/// @return the area 
float ScaleneT::GetArea() 
{	
    float p=GetPerimeter()/2;
	return (sqrt(p*(p-sides[0])*(p-sides[1])*(p-sides[2])));
}

/// @brief write an error message 
/// @param string message to be printed
void ScaleneT::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- Scalene Triangle --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
void ScaleneT::WarningMessage(const char *string) 
{
	cout << endl << "WARNING -- ScaleneT --";
	cout << string << endl;
}


/// @brief for debugging: all about the object
void ScaleneT::Dump()
{
	cout << endl;
	cout << "---Scalene Triangle---" << endl; 
	cout << endl;

	Triangle::Dump();

	cout << "Area = " << GetArea() << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	
	Triangle::Dump();
	
	cout << endl;
}
