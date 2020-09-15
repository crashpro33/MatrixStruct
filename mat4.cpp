#pragma once
#include <math.h>
#include "vec4.h"
#include <xmmintrin.h>
#include <pmmintrin.h>

// Struct
struct mat4 {

	// Array of matrix elements
	float matrixElements[16];

	// Constructors
	mat4();
	mat4(int scalar);

	// Static functions
	static mat4 ScaleMatrix(vec4 scaleVector);
	static mat4 TranslationMatrix(const float& xSclae, const float& yScale, const float& zScale);
	static mat4 RotationMatrix(float xRot, float yRot, float zRot);
	static vec4 mulVectorMatrix(vec4 v, mat4 m);

	// Inline matrix += override
	inline mat4& operator += (const mat4& rhs) {
		for (int index = 0; index < 16; index++) {
			matrixElements[index] += rhs.matrixElements[index];
		}
		return *this;
	}

	// Inline matrix matrix -= override
	inline mat4& operator -= (const mat4& rhs) {
		for (int index = 0; index < 16; index++) {
			this->matrixElements[index] -= rhs.matrixElements[index];
		}
		return *this;
	}

	// Inline matrix matrix *= override
	inline mat4& operator *= (const mat4& rhs) {
		matrixElements[0] = matrixElements[0] * rhs.matrixElements[0] + matrixElements[1] * rhs.matrixElements[4] + matrixElements[2] * rhs.matrixElements[8] + matrixElements[3] * rhs.matrixElements[12];
		matrixElements[1] = matrixElements[0] * rhs.matrixElements[1] + matrixElements[1] * rhs.matrixElements[5] + matrixElements[2] * rhs.matrixElements[9] + matrixElements[3] * rhs.matrixElements[13];
		matrixElements[2] = matrixElements[0] * rhs.matrixElements[2] + matrixElements[1] * rhs.matrixElements[6] + matrixElements[2] * rhs.matrixElements[10] + matrixElements[3] * rhs.matrixElements[14];
		matrixElements[3] = matrixElements[0] * rhs.matrixElements[3] + matrixElements[1] * rhs.matrixElements[7] + matrixElements[2] * rhs.matrixElements[11] + matrixElements[3] * rhs.matrixElements[15];

		matrixElements[4] = matrixElements[4] * rhs.matrixElements[0] + matrixElements[5] * rhs.matrixElements[4] + matrixElements[6] * rhs.matrixElements[8] + matrixElements[7] * rhs.matrixElements[12];
		matrixElements[5] = matrixElements[4] * rhs.matrixElements[1] + matrixElements[5] * rhs.matrixElements[5] + matrixElements[6] * rhs.matrixElements[9] + matrixElements[7] * rhs.matrixElements[13];
		matrixElements[6] = matrixElements[4] * rhs.matrixElements[2] + matrixElements[5] * rhs.matrixElements[6] + matrixElements[6] * rhs.matrixElements[10] + matrixElements[7] * rhs.matrixElements[14];
		matrixElements[7] = matrixElements[4] * rhs.matrixElements[3] + matrixElements[5] * rhs.matrixElements[7] + matrixElements[6] * rhs.matrixElements[11] + matrixElements[7] * rhs.matrixElements[15];

		matrixElements[8] = matrixElements[8] * rhs.matrixElements[0] + matrixElements[9] * rhs.matrixElements[4] + matrixElements[10] * rhs.matrixElements[8] + matrixElements[11] * rhs.matrixElements[12];
		matrixElements[9] = matrixElements[8] * rhs.matrixElements[1] + matrixElements[9] * rhs.matrixElements[5] + matrixElements[10] * rhs.matrixElements[9] + matrixElements[11] * rhs.matrixElements[13];
		matrixElements[10] = matrixElements[8] * rhs.matrixElements[2] + matrixElements[9] * rhs.matrixElements[6] + matrixElements[10] * rhs.matrixElements[10] + matrixElements[11] * rhs.matrixElements[14];
		matrixElements[11] = matrixElements[8] * rhs.matrixElements[3] + matrixElements[9] * rhs.matrixElements[7] + matrixElements[10] * rhs.matrixElements[11] + matrixElements[11] * rhs.matrixElements[15];

		matrixElements[12] = matrixElements[12] * rhs.matrixElements[0] + matrixElements[13] * rhs.matrixElements[4] + matrixElements[14] * rhs.matrixElements[8] + matrixElements[15] * rhs.matrixElements[12];
		matrixElements[13] = matrixElements[12] * rhs.matrixElements[1] + matrixElements[13] * rhs.matrixElements[5] + matrixElements[14] * rhs.matrixElements[9] + matrixElements[15] * rhs.matrixElements[13];
		matrixElements[14] = matrixElements[12] * rhs.matrixElements[2] + matrixElements[13] * rhs.matrixElements[6] + matrixElements[14] * rhs.matrixElements[10] + matrixElements[15] * rhs.matrixElements[14];
		matrixElements[15] = matrixElements[12] * rhs.matrixElements[3] + matrixElements[13] * rhs.matrixElements[7] + matrixElements[14] * rhs.matrixElements[11] + matrixElements[15] * rhs.matrixElements[15];
		return *this;
	}

	// Inline matrix float *= override
	inline mat4& operator *= (const float& rhs) {
		for (int index = 0; index < 16; index++) {
			this->matrixElements[index] *= rhs;
		}
		return *this;
	}
};

// Inline operator overrides
extern inline mat4 operator+(const mat4& lhs, const mat4& rhs);
extern inline mat4 operator-(const mat4& lhs, const mat4& rhs);
extern inline mat4 operator*(const mat4& lhs, const mat4& rhs);
extern inline mat4 operator*(const mat4& lhs, const mat4& rhs);
