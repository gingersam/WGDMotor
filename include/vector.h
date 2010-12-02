#ifndef _WGDVECTOR_
#define _WGDVECTOR_

#include <math.h>
#include <iostream>

class Vector3D;

/**
 * A two dimensional floating point vector. All common vector
 * operations are supported, mostly through operator
 * overloading so you can to c = a+b to add vectors.
 */
class Vector2D
{
	public:
	float x;
	float y;
	
	// This is a bit hacky, but in other ways I quite like it...
	// Is defined to be 0 in globals.cpp (can't be initialised in header file).
	static const float z;

	Vector2D();
	
	Vector2D(float px, float py);

	Vector2D(float *pf);
	
	Vector2D(const Vector2D &v);

	inline Vector2D(const Vector3D &v);
	
	float length() const ;
	
	float lengthSquared() const;
	
	float distance (const Vector2D &v) const ;
	float distanceSquared (const Vector2D &v) const ;
	
	/**
	 * Calculate the distance between two vectors.
	 * @return Distance between vectors.
	 */
	static float distance(const Vector2D &a, const Vector2D &b);

	/**
	 * Calculate the distance squared between two vectors.
	 * @return Distance squared between vectors.
	 */
	static float distanceSquared(const Vector2D &a, const Vector2D &b);

	Vector2D normalise() const;

	const float *getArray() const;
	void fillArray(float *a);

	float dot (const Vector2D &v) const;
	/** Unary negation */
	Vector2D operator-() const;

	Vector2D operator+(const Vector2D &v) const ;

	Vector2D operator-(const Vector2D &v) const;

	Vector2D operator*(float scale) const;

	Vector2D operator*(const Vector2D &v) const;

	Vector2D operator/(float scale) const;

	Vector2D& operator+=(const Vector2D &v);

	Vector2D& operator-=(const Vector2D &v);

	Vector2D& operator*=(float scale);

	Vector2D& operator*=(const Vector2D &v);

	Vector2D& operator/=(float scale);
	
	bool operator==(const Vector2D& v);

	bool operator!=(const Vector2D& v);

	static float dotProduct(const Vector2D &a, const Vector2D &b);

	static Vector2D lerp(const Vector2D &a, const Vector2D &b, float t);

	friend std::ostream &operator<<(std::ostream &os, const Vector2D &vec);
	inline friend Vector2D operator*(float scale, const Vector2D &v);
};

/**
 * A three dimensional floating point vector. It actually contains a fourth
 * dimension so that it can be used with the Matrix class. All common
 * vector operators can be performed, mostly by using the overloaded
 * operators.
 */
class Vector3D
{
	public:
	union {
		struct {
			float x; /**< X-Coordinate */
			float y; /**< Y-Coordinate */
			float z; /**< Z-Coordinate */
			float w; /**< Dummy Coordinate */
		};
		
		float data[4];
	};

	/** Zero vector. */
	Vector3D();

	/**
	 * 2D constructor, z defaults to 0.0. This is used for 2D games when specifying
	 * position of sprites etc. In a 2D game the values correspond to pixels.
	 * @param px X-Coordinate.
	 * @param py Y-Coordinate.
	 */
	Vector3D(float px, float py);

	/**
	 * XYZ constructor. The W-Coordinate defaults to 1.0.
	 * @param px X-Coordinate.
	 * @param py Y-Coordinate.
	 * @param pz Z-Coordinate.
	 */
	Vector3D(float px, float py, float pz);

	/**
	 * XYZW constructor. You will not usually need this, use XYZ instead.
	 * @param px X-Coordinate.
	 * @param py Y-Coordinate.
	 * @param pz Z-Coordinate.
	 * @param pw W-Coordinate.
	 */
	Vector3D(float px, float py, float pz, float pw);

	/**
	 * Construct from a 3 float array.
	 * @param pf Pointer to 3 floats.
	 */
	Vector3D(float *pf);

	Vector3D(const Vector2D &v);

	Vector3D(const Vector3D &v);

	/**
	 * Calculate the vectors length. Note that this uses square root and may be slow.
	 * @return Length of vector.
	 */
	float length() const;
	/**
	 * Calculate the squared length of this vector. This avoids the square root so is faster.
	 * @return Squared length of vector
	 */
	float lengthSquared() const;

	/**
	 * Calculate the distance to a vector
	 * @return Distance to the other vector.
	 */
	float distance (const Vector3D &v) const;
	
	/**
	 * Calculate the distance to a vector
	 * @return Distance to the other vector.
	 */
	float distanceSquared (const Vector3D &v) const;
	
	/**
	 * Calculate the distance between two vectors.
	 * @return Distance between vectors.
	 */
	static float distance(const Vector3D &a, const Vector3D &b);

	/**
	 * Calculate the distance squared between two vectors.
	 * @return Distance squared between vectors.
	 */
	static float distanceSquared(const Vector3D &a, const Vector3D &b);

	/**
	 * Normalise the vector. This will make it have a length of 1.
	 */
	Vector3D normalise() const;

	/**
	 * Get this vector as an array of floats. Note that this is read-only.
	 * @return Pointer to 3 (or 4) floats.
	 */
	const float *getArray() const ;
	
	float& operator[] (int i);
	
	float operator[] (int i) const;
	
	/**
	 * Put this vector into a specified array. Similar to getArray. This will only
	 * fill the array with XYZ not W.
	 * @param a Pointer to 3 float array.
	 */
	void fillArray(float *a) ;

	/**
	 * Make this vector from a float array. Useful if you want to reuse a vector
	 * instead of making a new one.
	 * @param a 3 float array.
	 */
	void fromArray(const float *a);
	
	float dot (const Vector3D &v) const;

	Vector3D cross (const Vector3D &v) const;

	/** Unary negation */
	Vector3D operator-() const ;

	/** Add two vectors. */
	Vector3D operator+(const Vector3D &v) const;

	/** Subtract a vector from another. */
	Vector3D operator-(const Vector3D &v) const;

	/** Scale a vector */
	Vector3D operator*(float scale) const;

	/** Scale a vector */
	Vector3D operator/(float scale) const;

	Vector3D& operator+=(const Vector3D &v);

	Vector3D& operator-=(const Vector3D &v);

	Vector3D& operator*=(float scale);

	Vector3D& operator/=(float scale);

	Vector3D& operator*=(const Vector3D &v);

	bool operator==(const Vector3D& v) const;

	bool operator!=(const Vector3D& v) const;

	/**
	 * Scale a vector. This is faster as fewer vector temporaries are created.
	 * @param result Scaled result goes here.
	 * @param a Vector to scale.
	 * @param b Scale factor.
	 */
	static void fastScale(Vector3D &result, const Vector3D &a, float scale);

	/** Multiply two vectors. */
	Vector3D operator*(const Vector3D &v) const;

	/**
	 * Calculate the dot product of two vectors. This corresponds to the angle between them.
	 * @param a First vector.
	 * @param b Second vector.
	 * @return Dot product of a.b.
	 */
	static float dotProduct(const Vector3D &a, const Vector3D &b);

	/**
	 * Cross product of two vectors a and b.
	 * @param a First vector.
	 * @param b Second vector.
	 * @return Cross product of a and b.
	 */
	static Vector3D crossProduct(const Vector3D &a, const Vector3D &b);

	/**
	 * Linear interpolation between two vectors.
	 * @param a Start vector.
	 * @param b End vector.
	 * @param t Interpolation coeficient.
	 * @return The interpolated vector.
	 */
	static Vector3D lerp(const Vector3D &a, const Vector3D &b, float t) ;

	/**
	 * Get normal from 3 vectors. Useful if you have a triangle and need to find its normal.
	 * @param a Vector A
	 * @param b Vector B
	 * @param c Vector C
	 * @return Normal to plane described by A B and C.
	 */
	static Vector3D makeNormal(const Vector3D &a, const Vector3D &b, const Vector3D &c);

	friend std::ostream &operator<<(std::ostream &os, const Vector3D &vec);
	inline friend Vector3D operator*(float scale, const Vector3D &v);

};

inline std::ostream& operator<<(std::ostream &os, const Vector2D &vec) ;
inline std::ostream& operator<<(std::ostream &os, const Vector3D &vec);

Vector2D operator*(float scale, const Vector2D &v);
Vector3D operator*(float scale, const Vector3D &v);

#endif


