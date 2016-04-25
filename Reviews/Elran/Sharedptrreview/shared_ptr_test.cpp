/****************************************
*
*	shared_ptr Project Test file	shared_ptr_test.cpp
*	04-13-2016
*	
*	Production : Elran Sarusi
*	Reviewed by :
*
****************************************/


#include"shared_ptr.h"

	using namespace std;
	using namespace ilrd;


class Shape
{
public:
	Shape(int scale_ = 1);
	virtual ~Shape();
	int GetScale();
	virtual void Print();


private:
	int scale;
};

class Polygon : public Shape
{
public:
	Polygon(int num_sides_=3);
	~Polygon();
	int GetSides();
	void Print();


private:
	int num_sides;
};

//Shape
Shape::Shape(int scale_)
:scale(scale_)
{}
Shape::~Shape()
{}
int Shape::GetScale()
{
	return scale;
}
void Shape::Print()
{
	cout<<"I am Shape Print"<<endl;
}

//Polygon
Polygon::Polygon(int num_sides_)
:num_sides(num_sides_)
{}
Polygon::~Polygon()
{}
int Polygon::GetSides()
{
	return num_sides;
}
void Polygon::Print()
{
	cout<<"I am Polygon Print"<<endl;
}



/*****************MAIN******************/
int main (int argc, char *argv[], char **envp)
{


	cout<<"\n_____________TESTING __________\n"<<endl;
	cout<<"\n____________*** PHASE 1 - SP init ***___________\n"<<endl;

	Shape* shape1ptr(new Shape(2));
	Polygon* poly1ptr(new Polygon(4));

	SharedPtr<Shape>ptr1(shape1ptr);
	SharedPtr<Polygon>ptr2(poly1ptr);

	cout<<"//expect 2 - inisitalized value"<<endl;
	cout<<(*ptr1).GetScale()<<" <::> (*ptr1).GetScale()"<<endl;

	cout<<"//expect 1 - default ctor"<<endl;
	cout<<(*ptr2).GetScale()<<" <::> (*ptr2).GetScale()"<<endl;
	cout<<"\nPrinting from ptr1 and ptr2 respectively : "<<endl;
	(*ptr1).Print();
	(*ptr2).Print();


	cout<<"\n____________*** PHASE 2 - SP assign ***___________\n"<<endl;
	cout<<"assigning pointer ptr2 value ptr1 : (expect print to be : 1 (from polygon default constructor of shape)"<<endl;

	ptr1=ptr2;

	cout<<"//expect 1 - from the polygon def ctor"<<endl;
	cout<<(*ptr1).GetScale()<<" <::> (*ptr1).GetScale() "<<endl;

	cout<<"//expect 1 - from the polygon def ctor"<<endl;
	cout<<(*ptr2).GetScale()<<" <::> (*ptr2).GetScale()"<<endl;
	cout<<"\nPrinting from ptr1 and ptr2 respectively : "<<endl;
	(*ptr1).Print();
	(*ptr2).Print();






	
	return (0);	
	
}
/****************MAIN END***************/
