#include "../include/vector.h"

	Vector2D::Vector2D() : x(0), y(0) {}
	
	Vector2D::Vector2D(float px, float py)
		:	x(px),
			y(py) {};

	Vector2D::Vector2D(float *pf)		//Assumes only of size 3... w is ignored.
		:	x(pf[0]),
			y(pf[1]) {};
	
	Vector2D::Vector2D(const Vector2D &v)
		: x(v.x), y(v.y) {};


	float Vector2D::length() const {
		return sqrt(x*x + y*y);
	}
	
	float Vector2D::lengthSquared() const {
		return (x*x + y*y);
	}
	
	float Vector2D::distance (const Vector2D &v) const {
		float dx = x - v.x;
		float dy = y - v.y;
		return sqrt(dx * dx + dy * dy);
	}
	
	float Vector2D::distanceSquared (const Vector2D &v) const {
		float dx = x - v.x;
		float dy = y - v.y;
		return dx * dx + dy * dy;
	}
	
	float Vector2D::distance(const Vector2D &a, const Vector2D &b) {
		return a.distance(b);
	};

	/**
	 * Calculate the distance squared between two vectors.
	 * @return Distance squared between vectors.
	 */
	float Vector2D::distanceSquared(const Vector2D &a, const Vector2D &b) {
		return a.distanceSquared(b);
	};

	Vector2D Vector2D::normalise() const {
		float l = length();
		if (l == 0)
			return *this;

		return Vector2D(x / l, y / l);
	};

	const float *Vector2D::getArray() const { return &x; };
	void Vector2D::fillArray(float *a) {
		a[0] = x;
		a[1] = y;
	};

	float Vector2D::dot (const Vector2D &v) const {
		return dotProduct(*this, v);
	}

	/** Unary negation */
	Vector2D Vector2D::operator-() const {
		return Vector2D(-x, -y);
	};

	Vector2D Vector2D::operator+(const Vector2D &v) const {
		return Vector2D(x+v.x, y+v.y);
	};

	Vector2D Vector2D::operator-(const Vector2D &v) const {
		return Vector2D(x-v.x, y-v.y);
	};

	Vector2D Vector2D::operator*(float scale) const {
		return Vector2D(x*scale, y*scale);
	};

	Vector2D Vector2D::operator*(const Vector2D &v) const {
		return Vector2D(x*v.x, y*v.y);
	};

	Vector2D Vector2D::operator/(float scale) const {
		return Vector2D(x/scale, y/scale);
	};

	Vector2D& Vector2D::operator+=(const Vector2D &v) {
		x += v.x;
		y += v.y;
		
		return *this;
	};

	Vector2D& Vector2D::operator-=(const Vector2D &v) {
		x -= v.x;
		y -= v.y;
		
		return *this;
	};

	Vector2D& Vector2D::operator*=(float scale) {
		x *= scale;
		y *= scale;
		
		return *this;
	};

	Vector2D& Vector2D::operator*=(const Vector2D &v) {
		x *= v.x;
		y *= v.y;
		
		return *this;
	};

	Vector2D& Vector2D::operator/=(float scale) {
		x /= scale;
		y /= scale;
		
		return *this;
	};
	
	bool Vector2D::operator==(const Vector2D& v) {
		return (x == v.x && y == v.y);
	}

	bool Vector2D::operator!=(const Vector2D& v) {
		return (x != v.x || y != v.y);
	}

	float Vector2D::dotProduct(const Vector2D &a, const Vector2D &b) {
		return (a.x*b.x + a.y*b.y);
	};

	Vector2D Vector2D::lerp(const Vector2D &a, const Vector2D &b, float t) {
		return Vector2D(a.x+((b.x-a.x)*t), a.y+((b.y-a.y)*t));
	}


/**
 * A three dimensional floating point vector. It actually contains a fourth
 * dimension so that it can be used with the Matrix class. All common
 * vector operators can be performed, mostly by using the overloaded
 * operators.
 */

	/** Zero vector. */
	Vector3D::Vector3D() :x(0), y(0), z(0), w(1.0) {};

	/**
	 * 2D constructor, z defaults to 0.0. This is used for 2D games when specifying
	 * position of sprites etc. In a 2D game the values correspond to pixels.
	 * @param px X-Coordinate.
	 * @param py Y-Coordinate.
	 */
	Vector3D::Vector3D(float px, float py)
		:	x(px),
			y(py),
			z(0.0),
			w(1.0) {};

	/**
	 * XYZ constructor. The W-Coordinate defaults to 1.0.
	 * @param px X-Coordinate.
	 * @param py Y-Coordinate.
	 * @param pz Z-Coordinate.
	 */
	Vector3D::Vector3D(float px, float py, float pz)
		:	x(px),
			y(py),
			z(pz),
			w(1.0) {};

	/**
	 * XYZW constructor. You will not usually need this, use XYZ instead.
	 * @param px X-Coordinate.
	 * @param py Y-Coordinate.
	 * @param pz Z-Coordinate.
	 * @param pw W-Coordinate.
	 */
	Vector3D::Vector3D(float px, float py, float pz, float pw)
		:	x(px),
			y(py),
			z(pz),
			w(pw) {};

	/**
	 * Construct from a 3 float array.
	 * @param pf Pointer to 3 floats.
	 */
	Vector3D::Vector3D(float *pf)		//Assumes only of size 3... w is ignored.
		:	x(pf[0]),
			y(pf[1]),
			z(pf[2]),
			w(1.0) {};

	Vector3D::Vector3D(const Vector2D &v)
		: x(v.x), y(v.y), z(0), w(1.0) {};

	Vector3D::Vector3D(const Vector3D &v)
		: x(v.x), y(v.y), z(v.z), w(v.w) {};

	/**
	 * Calculate the vectors length. Note that this uses square root and may be slow.
	 * @return Length of vector.
	 */
	float Vector3D::length() const
	{
		return sqrt(x*x + y*y + z*z);
	}
	/**
	 * Calculate the squared length of this vector. This avoids the square root so is faster.
	 * @return Squared length of vector
	 */
	float Vector3D::lengthSquared() const
	{
		return (x*x + y*y + z*z);
	}

	/**
	 * Calculate the distance to a vector
	 * @return Distance to the other vector.
	 */
	float Vector3D::distance (const Vector3D &v) const {
		float dx = x - v.x;
		float dy = y - v.y;
		float dz = z - v.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}
	
	/**
	 * Calculate the distance to a vector
	 * @return Distance to the other vector.
	 */
	float Vector3D::distanceSquared (const Vector3D &v) const {
		float dx = x - v.x;
		float dy = y - v.y;
		float dz = z - v.z;
		return dx * dx + dy * dy + dz * dz;
	}
	
	/**
	 * Calculate the distance between two vectors.
	 * @return Distance between vectors.
	 */
	float Vector3D::distance(const Vector3D &a, const Vector3D &b) {
		return a.distance(b);
	};

	/**
	 * Calculate the distance squared between two vectors.
	 * @return Distance squared between vectors.
	 */
	float Vector3D::distanceSquared(const Vector3D &a, const Vector3D &b) {
		return a.distanceSquared(b);
	};

	/**
	 * Normalise the vector. This will make it have a length of 1.
	 */
	Vector3D Vector3D::normalise() const
	{
		float l = length();
		if (l == 0)
			return *this;

		return Vector3D(x / l, y / l, z / l);
	};

	/**
	 * Get this vector as an array of floats. Note that this is read-only.
	 * @return Pointer to 3 (or 4) floats.
	 */
	const float *Vector3D::getArray() const { return data; };
	
	float& Vector3D::operator[] (int i) {
		// TODO assert i >= 0 && i < 4
		return data[i];
	}
	
	float Vector3D::operator[] (int i) const {
		// TODO assert i >= 0 && i < 4
		return data[i];
	}
	
	/**
	 * Put this vector into a specified array. Similar to getArray. This will only
	 * fill the array with XYZ not W.
	 * @param a Pointer to 3 float array.
	 */
	void Vector3D::fillArray(float *a) {
		a[0] = x;
		a[1] = y;
		a[2] = z;
		//Don't assume w.
	};

	/**
	 * Make this vector from a float array. Useful if you want to reuse a vector
	 * instead of making a new one.
	 * @param a 3 float array.
	 */
	void Vector3D::fromArray(const float *a) {
		x = a[0];
		y = a[1];
		z = a[2];
	};
	
	float Vector3D::dot (const Vector3D &v) const {
		return dotProduct(*this, v);
	}

	Vector3D Vector3D::cross (const Vector3D &v) const {
		return crossProduct(*this, v);
	}

	/** Unary negation */
	Vector3D Vector3D::operator-() const {
		return Vector3D(-x, -y, -z);
	};

	/** Add two vectors. */
	Vector3D Vector3D::operator+(const Vector3D &v) const {
		return Vector3D(x+v.x, y+v.y, z+v.z);
	};

	/** Subtract a vector from another. */
	Vector3D Vector3D::operator-(const Vector3D &v) const {
		return Vector3D(x-v.x, y-v.y, z-v.z);
	};

	/** Scale a vector */
	Vector3D Vector3D::operator*(float scale) const {
		return Vector3D(x*scale, y*scale, z*scale);
	};

	/** Scale a vector */
	Vector3D Vector3D::operator/(float scale) const {
		return Vector3D(x/scale, y/scale, z/scale);
	};

	Vector3D& Vector3D::operator+=(const Vector3D &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		
		return *this;
	};

	Vector3D& Vector3D::operator-=(const Vector3D &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		
		return *this;
	};

	Vector3D& Vector3D::operator*=(float scale) {
		x *= scale;
		y *= scale;
		z *= scale;
		
		return *this;
	};

	Vector3D& Vector3D::operator/=(float scale) {
		x /= scale;
		y /= scale;
		z /= scale;
		
		return *this;
	};

	Vector3D& Vector3D::operator*=(const Vector3D &v) {
		x *= v.x;
		y *= v.y;
		z *= v.z;
		
		return *this;
	};

	bool Vector3D::operator==(const Vector3D& v) const {
		return (x == v.x && y == v.y && z == v.z);
	}

	bool Vector3D::operator!=(const Vector3D& v) const {
		return (x != v.x || y != v.y || z != v.z);
	}

	/**
	 * Scale a vector. This is faster as fewer vector temporaries are created.
	 * @param result Scaled result goes here.
	 * @param a Vector to scale.
	 * @param b Scale factor.
	 */
	void Vector3D::fastScale(Vector3D &result, const Vector3D &a, float scale) {
		result.x = a.x*scale;
		result.y = a.y*scale;
		result.z = a.z*scale;
	};

	/** Multiply two vectors. */
	Vector3D Vector3D::operator*(const Vector3D &v) const {
		return Vector3D(x*v.x, y*v.y, z*v.z);
	};

	/**
	 * Calculate the dot product of two vectors. This corresponds to the angle between them.
	 * @param a First vector.
	 * @param b Second vector.
	 * @return Dot product of a.b.
	 */
	float Vector3D::dotProduct(const Vector3D &a, const Vector3D &b) {
		return (a.x*b.x + a.y*b.y + a.z*b.z);
	};

	/**
	 * Cross product of two vectors a and b.
	 * @param a First vector.
	 * @param b Second vector.
	 * @return Cross product of a and b.
	 */
	Vector3D Vector3D::crossProduct(const Vector3D &a, const Vector3D &b) {
		return Vector3D(	(a.y*b.z) - (a.z*b.y),
						(a.z*b.x) - (a.x*b.z),
						(a.x*b.y) - (a.y*b.x));
	};

	/**
	 * Linear interpolation between two vectors.
	 * @param a Start vector.
	 * @param b End vector.
	 * @param t Interpolation coeficient.
	 * @return The interpolated vector.
	 */
	Vector3D Vector3D::lerp(const Vector3D &a, const Vector3D &b, float t) {
		return Vector3D(a.x+((b.x-a.x)*t), a.y+((b.y-a.y)*t), a.z+((b.z-a.z)*t), a.w+((b.w-a.w)*t));
	}

	/**
	 * Get normal from 3 vectors. Useful if you have a triangle and need to find its normal.
	 * @param a Vector A
	 * @param b Vector B
	 * @param c Vector C
	 * @return Normal to plane described by A B and C.
	 */
	Vector3D Vector3D::makeNormal(const Vector3D &a, const Vector3D &b, const Vector3D &c) {
		return Vector3D::crossProduct(b-a,c-a).normalise();
	};


/*
inline std::ostream& Vector2D::operator<<(std::ostream &os, const Vector2D &vec) {
	os << "(" << vec.x << "," << vec.y << ")";
	return os;
}

inline std::ostream& Vector3D::operator<<(std::ostream &os, const Vector3D &vec) {
	os << "(" << vec.x << "," << vec.y << "," << vec.z << "," << vec.w << ")";
	return os;
}

Vector2D::Vector2D(const Vector3D &v)
	: x(v.x), y(v.y) {};

Vector2D Vector2D::operator*(float scale, const Vector2D &v) {
	return Vector2D(v.x * scale, v.y * scale);
}

Vector3D Vector3D::operator*(float scale, const Vector3D &v) {
	return Vector3D(v.x * scale, v.y * scale, v.z * scale);
}
*/
