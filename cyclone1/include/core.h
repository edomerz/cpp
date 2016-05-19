namespace cyclone
{
/*
 * holds a vector in 3 dim. 4 data members are allocated
 * to ensure alignment in an array
 */

class Vector3
{
public:
	// default ctor
	Vector3(): x(0), y(0), z(0), pad(0)
	{}
	// explicit ctor
	Vector3(const real x_, const real y_, const real z_):
			x(x_), y(y_), z(z_), pad(0)
	{}

	real x;		// x axis value
	real y; 	// y axis
	real z; 	// z axis

	// function members
	// flips all the components of the vector
	void Invert()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	// gets the magnitude of this vector
	real Magnitude() const
	{
		return real_sqrt(x * x + y * y + z * z);
	}

	// gets the squared magnitude of this vector
	real SquareMagnitude() const
	{
		return(x * x + y * y + z * z);
	}

	// turns a non 0 vector into a unit length vector
	void Normalize()
	{
		real l = Magnitude();
		if(l > 0)
		{
			(*this) *= ((real)1) / l;
		}
	}

	// multiples this vec by the given scalar
	void operator*=(const real value)
	{
		x *= value;
		y *= value;
		z *= value;
	}

	Vector3 operator*(const real value) const
	{
		return(Vector3(x * value, y * value, z * value));
	}

	// add a given vec to this vec
	void operator+=(const Vector3& other_)
	{
		x += other_.x;
		y += other_.y;
		z += other_.z;
	}

	// sub a given vec to this vec
	void operator-=(const Vector3& other_)
	{
		x -= other_.x;
		y -= other_.y;
		z -= other_.z;
	}

	Vector3 operator+(const Vector3& other_)
	{
		return(Vector3(x + other_.x, y + other_.y, z + other_.z));
	}

	Vector3 operator-(const Vector3& other_)
	{
		return(Vector3(x - other_.x, y +-other_.y, z - other_.z));
	}

	// adds the given vec to this, scaled by the given amount
	void AddScaledVector(const Vector3& vector, real scale)
	{
		x += vector.x * scale;
		y += vector.y * scale;
		z += vector.x * scale;
	}



private:
	// padding to ensure 4-word alignment
	real pad;
};



}
