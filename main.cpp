#include <Novice.h>
#include "Mat4x4/Mat4x4.h"

const char kWindowTitle[] = "LE2A_04_キクタニ_タクマ_MT3_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Mat4x4 orthographicMatirx = MakeMatrixOrthographic(-160.0f, 160.0f, 200.0f, 300.0f, 0.0f, 1000.0f);

	Mat4x4 perspectiveMatrix = MakeMatrixPerspectiveFov(0.63f, 1.33f, 0.1f, 1000.0f);

	Mat4x4 viewportMatrix = MakeMatrixViewPort(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);


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
		MatrixScreenPrintf(0, 0, orthographicMatirx, "orthographicMatirx");
		MatrixScreenPrintf(0, kRowHeight * 5, perspectiveMatrix, "perspectiveMatrix");
		MatrixScreenPrintf(0, kRowHeight * 5 * 2, viewportMatrix, "viewportMatrix");
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
