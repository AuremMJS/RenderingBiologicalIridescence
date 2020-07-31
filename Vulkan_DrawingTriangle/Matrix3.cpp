#include "Matrix3.h"



Matrix3::Matrix3()
{
}


Matrix3::~Matrix3()
{
}

Matrix3 Matrix3::Inverse()
{
	Matrix3 Inverse;
	double determinant = 0;
	for (int i = 0; i < 9; i++)
	{
		int row = i / 3;
		int col = i % 3;

		double newVal = values[(row + 1) % 3][(col + 1) % 3] * values[(row + 2) % 3][(col + 2) % 3] - values[(row + 1) % 3][(col + 2) % 3] * values[(row + 2) % 3][(col + 1) % 3];
		if (row == 0)
			determinant += values[row][col] * newVal;
		Inverse.values[col][row] = newVal;
	}

	for (int i = 0; i < 9; i++)
	{
		int row = i / 3;
		int col = i % 3;

		Inverse.values[row][col] /= determinant;
	}
	return Inverse;
}

Vec3 Matrix3::operator*(Vec3 vector)
{
	Vec3 result;

	result.x = values[0][0] * vector.x + values[0][1] * vector.y + values[0][2] * vector.z;
	result.y = values[1][0] * vector.x + values[1][1] * vector.y + values[1][2] * vector.z;
	result.z = values[2][0] * vector.x + values[2][1] * vector.y + values[2][2] * vector.z;

	return result;
}


Matrix4::Matrix4()
{
}

Matrix4::Matrix4(float values[16])
{
	for (int i = 0; i < 16; i++)
	{
		this->values[i / 4][i % 4] = values[i];
	}
}


Matrix4::~Matrix4()
{
}

Vec4 Matrix4::operator*(Vec4 vector)
{
	Vec4 result;

	result.x = values[0][0] * vector.x + values[0][1] * vector.y + values[0][2] * vector.z + values[0][3] * vector.w;
	result.y = values[1][0] * vector.x + values[1][1] * vector.y + values[1][2] * vector.z + values[1][3] * vector.w;
	result.z = values[2][0] * vector.x + values[2][1] * vector.y + values[2][2] * vector.z + values[2][3] * vector.w;
	result.w = values[3][0] * vector.x + values[3][1] * vector.y + values[3][2] * vector.z + values[3][3] * vector.w;
	return result;
}

Matrix4 Matrix4::perspective(float fovy, float aspect, float zNear, float zFar)
{
	float tanHalfFovy = tan(fovy / 2);

	float Result[16];
	Result[0] = 1 / (aspect * tanHalfFovy);
	Result[1] = 0;
	Result[2] = 0;
	Result[3] = 0;
	Result[4] = 0;
	Result[5] = -1 / (tanHalfFovy);
	Result[6] = 0;
	Result[7] = 0;
	Result[8] = 0;
	Result[9] = 0;
	Result[10] = zFar / (zNear - zFar);
	Result[11] = -1;
	Result[12] = 0;
	Result[13] = 0;
	Result[14] = -(zFar * zNear) / (zFar - zNear);
	Result[15] = 0;
	Matrix4 mat(Result);
	return mat;
}

Matrix4 Matrix4::lookAt(Vec3 eye, Vec3 center, Vec3 up)
{
	Vec3 centerToEye = center - eye;
	centerToEye.Normalize();
	Vec3 f(centerToEye);
	Vec3 FCrosUp = f.cross(&up);
	FCrosUp.Normalize();
	Vec3 s(FCrosUp);
	Vec3 SCrosF = s.cross(&f);
	Vec3 u(SCrosF);

	float Result[16];
	Result[0] = s.x;
	Result[1] = u.x;
	Result[2] = -f.x;
	Result[3] = 0;
	Result[4] = s.y;
	Result[5] = u.y;
	Result[6] = -f.y;
	Result[7] = 0;
	Result[8] = s.z;
	Result[9] = u.z;
	Result[10] = -f.z;
	Result[11] = 0;
	Result[12] = s * &eye;
	Result[13] = u * &eye * -1;
	Result[14] = f * &eye;
	Result[15] = 1;
	return Result;
}