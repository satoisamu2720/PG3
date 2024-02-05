#include <Novice.h>
#include <math.h>
#include <stdio.h>
#include "imgui.h"


const char kWindowTitle[] = "";
struct Vector2 {
	float x;
	float y;
};
struct Vector3 {
	float x;
	float y;
	float z;
};
struct Matrix4x4 final {
	float m[4][4];
};
struct Quaternion {
	float x;
	float y;
	float z;
	float w;
};
Matrix4x4 MakeIdentity4x4() { return {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}; }

float Dot(const Vector3& v1, const Vector3& v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

float Length(const Vector3& v) { return sqrtf(Dot(v, v)); }

Vector3 Normalize(const Vector3& v) {
	float len = Length(v);
	if (len != 0) {
		return {v.x / len, v.y / len, v.z / len};
	}
	return v;
}
Matrix4x4 MakeRotateAxisAngle(Vector3 axis, float angle) {
	axis = Normalize(axis);
	Matrix4x4 result;

	float cos = cosf(angle);
	float sin = sinf(angle);

	result = MakeIdentity4x4();
	result.m[0][0] = (axis.x * axis.x) * (1 - cos) + cos;
	result.m[0][1] = axis.x * axis.y * (1 - cos) + axis.z * sin;
	result.m[0][2] = axis.x * axis.z * (1 - cos) - axis.y * sin;
	result.m[1][0] = axis.x * axis.y * (1 - cos) - axis.z * sin;
	result.m[1][1] = (axis.y * axis.y) * (1 - cos) + cos;
	result.m[1][2] = axis.y * axis.z * (1 - cos) + axis.x * sin;
	result.m[2][0] = axis.x * axis.z * (1 - cos) + axis.x * sin;
	result.m[2][1] = axis.y * axis.z * (1 - cos) - axis.x * sin;
	result.m[2][2] = (axis.z * axis.z) * (1 - cos) + cos;

	return result;
}

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = (v1.y * v2.z - v1.z * v2.y);
	result.y = (v1.z * v2.x - v1.x * v2.z);
	result.z = (v1.x * v2.y - v1.y * v2.x);
	return result;
}

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to) {
	Matrix4x4 result = MakeIdentity4x4();
	Vector3 normal = Normalize(Cross(from, to));
	if (from.x == -to.x && from.y == -to.y && from.z == -to.z) {
		if (from.x != 0.0f || from.y != 0.0f) {
			normal = {from.y, -from.x, 0.0f};
		} else if (from.x != 0.0f || from.z != 0.0f) {
			normal = {from.z, 0.0f, -from.x};
		}
	}
	float cos = Dot(from, to);
	float sin = Length(Cross(from, to));

	result.m[0][0] = normal.x * normal.x * (1.0f - cos) + cos;
	result.m[0][1] = normal.x * normal.y * (1.0f - cos) + normal.z * sin;
	result.m[0][2] = normal.x * normal.z * (1.0f - cos) - normal.y * sin;

	result.m[1][0] = normal.x * normal.y * (1.0f - cos) - normal.z * sin;
	result.m[1][1] = normal.y * normal.y * (1.0f - cos) + cos;
	result.m[1][2] = normal.y * normal.z * (1.0f - cos) + normal.x * sin;

	result.m[2][0] = normal.x * normal.z * (1.0f - cos) + normal.y * sin;
	result.m[2][1] = normal.y * normal.z * (1.0f - cos) - normal.x * sin;
	result.m[2][2] = normal.z * normal.z * (1.0f - cos) + cos;

	return result;
}

// MT4_01_03
Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs) {
	Quaternion result;
	Vector3 cross = Cross({lhs.x, lhs.y, lhs.z}, {rhs.x, rhs.y, rhs.z});
	float dot = Dot({lhs.x, lhs.y, lhs.z}, {rhs.x, rhs.y, rhs.z});
	result.x = cross.x + rhs.w * lhs.x + lhs.w * rhs.x;
	result.y = cross.y + rhs.w * lhs.y + lhs.w * rhs.y;
	result.z = cross.z + rhs.w * lhs.z + lhs.w * rhs.z;
	result.w = lhs.w * rhs.w - dot;

	return result;
}

Quaternion IdentityQuaternion() { return Quaternion({0.0f, 0.0f, 0.0f, 1.0f}); }

Quaternion Conjugate(const Quaternion& quaternion) {
	return Quaternion(
	    {quaternion.x * -1.0f, quaternion.y * -1.0f, quaternion.z * -1.0f, quaternion.w});
}

float Norm(const Quaternion& quaternion) {
	return sqrtf(
	    quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z +
	    quaternion.w * quaternion.w);
}

Quaternion Normalize(const Quaternion& quaternion) {
	Quaternion result{};
	float norm = Norm(quaternion);
	if (norm != 0.0f) {
		result.x = quaternion.x / norm;
		result.y = quaternion.y / norm;
		result.z = quaternion.z / norm;
		result.w = quaternion.w / norm;
	}
	return result;
}

Quaternion Inverse(const Quaternion& quaternion) {
	Quaternion result{};
	float norm = Norm(quaternion);
	norm = norm * norm;
	Quaternion conj = Conjugate(quaternion);
	if (norm != 0.0f) {
		result.x = conj.x / norm;
		result.y = conj.y / norm;
		result.z = conj.z / norm;
		result.w = conj.w / norm;
	}
	return result;
}
// MT4_01_04
Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle) {
	Quaternion result;
	result.x = axis.x * sinf(angle / 2);
	result.y = axis.y * sinf(angle / 2);
	result.z = axis.z * sinf(angle / 2);
	result.w = cosf(angle / 2);
	return result;
}

Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion) {
	Quaternion fromVector = {vector.x, vector.y, vector.z, 0.0f};
	Quaternion conj = Conjugate(quaternion);
	Quaternion rotate = Multiply(quaternion, Multiply(fromVector, conj));
	Vector3 result;
	result.x = rotate.x;
	result.y = rotate.y;
	result.z = rotate.z;

	return result;
}

Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion) {
	Matrix4x4 result;
	result.m[0][0] = (quaternion.w * quaternion.w) + (quaternion.x * quaternion.x) -
	                 (quaternion.y * quaternion.y) - (quaternion.z * quaternion.z);
	result.m[0][1] = 2 * ((quaternion.x * quaternion.y) + (quaternion.w * quaternion.z));
	result.m[0][2] = 2 * ((quaternion.x * quaternion.z) - (quaternion.w * quaternion.y));
	result.m[0][3] = 0;

	result.m[1][0] = 2 * ((quaternion.x * quaternion.y) - (quaternion.w * quaternion.z));
	result.m[1][1] = (quaternion.w * quaternion.w) - (quaternion.x * quaternion.x) +
	                 (quaternion.y * quaternion.y) - (quaternion.z * quaternion.z);
	result.m[1][2] = 2 * ((quaternion.y * quaternion.z) + (quaternion.w * quaternion.x));
	result.m[1][3] = 0;

	result.m[2][0] = 2 * ((quaternion.x * quaternion.z) + (quaternion.w * quaternion.y));
	result.m[2][1] = 2 * ((quaternion.y * quaternion.z) - (quaternion.w * quaternion.x));
	result.m[2][2] = (quaternion.w * quaternion.w) - (quaternion.x * quaternion.x) -
	                 (quaternion.y * quaternion.y) + (quaternion.z * quaternion.z);
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}
Vector3 VectorTransform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] +
	           1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] +
	           1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] +
	           1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] +
	          1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}
// MT4_01_5
Quaternion Slerp(const Quaternion& q0, const Quaternion& q1, float t) {
	Quaternion result;
	Quaternion Localq0 = q0;
	Quaternion Localq1 = q1;
	// q0とq1の内積
	float dot = Localq0.x * Localq1.x + Localq0.y * Localq1.y + Localq0.z * Localq1.z;
	if (dot < 0.0f) {
		// もう片方の回転を利用
		Localq0 = {-q0.x, -q0.y, -q0.z, -q0.w};
		// 内積も反転
		dot = -dot;
	}
	// なす角を求める
	float theta = acosf(dot);

	float scale0 = sinf((1 - t) * theta) / sinf(theta);
	float scale1 = sinf(t * theta) /sinf(theta);
	result.x = scale0 * Localq0.x + scale1 * Localq1.x;
	result.y = scale0 * Localq0.y + scale1 * Localq1.y;
	result.z = scale0 * Localq0.z + scale1 * Localq1.z;
	result.w = scale0 * Localq0.w + scale1 * Localq1.w;

	return result;
}
Quaternion rotation0 = MakeRotateAxisAngleQuaternion({0.71f, 0.71f, 0.0f}, 0.3f);
Quaternion rotation1 = MakeRotateAxisAngleQuaternion({0.71f, 0.0f, 0.71f}, 3.141592f);

Quaternion interpolate0 = Slerp(rotation0, rotation1, 0.0f);
Quaternion interpolate1 = Slerp(rotation0, rotation1, 0.3f);
Quaternion interpolate2 = Slerp(rotation0, rotation1, 0.5f);
Quaternion interpolate3 = Slerp(rotation0, rotation1, 0.7f);
Quaternion interpolate4 = Slerp(rotation0, rotation1, 1.0f);

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		ImGui::Begin("MT4_01_05");
		ImGui::Text("interpolate0");
		ImGui::Text(
		    "%4.2f %4.2f %4.2f %4.2f", interpolate0.x, interpolate0.y, interpolate0.z,
		    interpolate0.w);
		ImGui::Text("interpolate1");
		ImGui::Text(
		    "%4.2f %4.2f %4.2f %4.2f", interpolate1.x, interpolate1.y, interpolate1.z,
		    interpolate1.w);
		ImGui::Text("interpolate2");
		ImGui::Text(
		    "%4.2f %4.2f %4.2f %4.2f", interpolate2.x, interpolate2.y, interpolate2.z,
		    interpolate2.w);
		ImGui::Text("interpolate3");
		ImGui::Text(
		    "%4.2f %4.2f %4.2f %4.2f", interpolate3.x, interpolate3.y, interpolate3.z,
		    interpolate3.w);
		ImGui::Text("interpolate4");
		ImGui::Text(
		    "%4.2f %4.2f %4.2f %4.2f", interpolate4.x, interpolate4.y, interpolate4.z,
		    interpolate4.w);
		ImGui::End();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
