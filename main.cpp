#include <Novice.h>
#include <math.h>
#include <stdio.h>



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
static const int kRowHeight = 20;
static const int kColummWidth = 60;

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
	for (int row = 0; row < 4; ++row) {
		for (int columm = 0; columm < 4; ++columm) {
			Novice::ScreenPrintf(
			    x + columm * kColummWidth, y + row * kRowHeight, "%6.3f", matrix.m[row][columm],
			    label);
		}
	}
}
Vector3 from0 = Normalize(Vector3{1.0f, 0.7f, 0.5f});
Vector3 to0 = from0;
Vector3 from1 = Normalize(Vector3{-0.6f, 0.9f, 0.2f});
Vector3 to1 = Normalize(Vector3{0.4f, 0.7f, -0.5});

Matrix4x4 rotateMatrix0 = DirectionToDirection(
    Normalize(Vector3{1.0f, 0.0f, 0.0f}), Normalize(Vector3{-1.0f, 0.0f, 0.0f}));
Matrix4x4 rotateMatrix1 = DirectionToDirection(from0, to0);
Matrix4x4 rotateMatrix2 = DirectionToDirection(from1, to1);
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
		//Novice::ScreenPrintf(0, 0, "rotateMatrix0");
		MatrixScreenPrintf(0, kRowHeight*5, rotateMatrix0, "rotateMatrix0");
		MatrixScreenPrintf(0, kRowHeight*10, rotateMatrix1, "rotateMatrix1");
		MatrixScreenPrintf(0, kRowHeight*15, rotateMatrix2, "rotateMatrix2");

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
