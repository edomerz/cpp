write a translation to a c++ prog in c

overloading:
void foo(int); -> foo_i
void foo(char*); -> foo_cp

global function such as
foo(X& a) -> foo(X* a)

new:
X* ptr = new X; -> X* ptr = malloc(sizeof(X));
x_ctor(ptr);


class to struct:
class X
{
public:
	X(){ a = 3;}

	void foo();

private:
	int a;	
}


typedef struct X
{
	int a;
};

c++
void X_ctor(X* this)
{
	this->a = 3;
}


x_oper_assig()

x_cctor()

pass by value in C++ uses a cctor
foo(X a)
{
	
}

void bar()
{
	X y;
	foo(y);
}




void bar()
{
	X y;
	X temp;
	x_cctor(& temp, &y)
	foo(&temp)
	x_dtor(&temp)
}


return by value in c++
X foo()
{
	X ret;
	.
	.
	.
	return(ret); // cctor
}

void bar()
{
	X var = foo(); // this is different from
	// X var2;
	// var2 = foo();
}


c:
void foo(X* objptr)
{
	X ret;
	x_cctor(objptr ,&ret)
	.
	.
	.
	x_dtor(ret);
}

void bar()
{
	X tmp, stat = foo(&stat);
	X tmp;
	
}
// return value optimazation in the compiler