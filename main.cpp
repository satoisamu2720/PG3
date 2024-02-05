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

Vector3 Normalise(const Vector3& v) {
	float len = Length(v);
	if (len != 0) {
		return {v.x / len, v.y / len, v.z / len};
	}
	return v;
}
Matrix4x4 MakeRotateAxisAngle(Vector3 axis, float angle) {
	axis = Normalise(axis);
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
Vector3 axis = Normalise({1.0f, 1.0f, 1.0f});

float angle = 0.44f;

Matrix4x4 rotateMatrix = MakeRotateAxisAngle(axis, angle);

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
		Novice::ScreenPrintf(0, 0, "rotateMatrix");
		MatrixScreenPrintf(0, 20, rotateMatrix, "rotateMatrix");
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
