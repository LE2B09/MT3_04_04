#include <Novice.h>
#include <imgui.h>
#include "Math/MathFunction.h"

static const int kWindowWidth = 1280;
static const int kWindowHeight = 720;

// TransformNormal関数（ベクトル変換）
Vector3ex TransformNormal(Vector3ex& v, Matrix4x4ex& m) {
	Vector3ex result{
		v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0],  // x
		v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1],  // y
		v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] }; // z
	return result;
}

const char kWindowTitle[] = "提出用課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	int prevMouseX = 0;
	int prevMouseY = 0;
	bool isDragging = false;

	// 動いているかどうかのフラグ
	bool isActive = false;

	// デルタタイム
	float deltaTime = 1.0f / 60.0f;

	MathFunction Func;

	Plane plane{};
	plane.normal = Func.Normalize({ -0.2f, 0.9f, -0.3f });
	plane.distance = 0.0f;

	Vector3ex planeRotate = { 0.0f, 0.0f, 0.0f };

	Ball ball{};
	ball.position = { 0.8f, 1.2f, 0.3f };
	ball.mass = 2.0f;
	ball.acceleration = { 0.0f, -9.8f, 0.0f };
	ball.radius = 0.05f;
	ball.color = WHITE;

	Sphere sphere = { .center{ball.position.x, ball.position.y, ball.position.z}, .radius{ball.radius} };

	Vector3ex abc = { -0.2f, 0.9f, -0.3f };

	Vector3ex translate{};
	Vector3ex rotate{};

	Vector3ex cameraTranslate = { 0.0f, 1.9f, -6.49f };
	Vector3ex cameraRotate = { 0.26f, 0.0f, 0.0f };

	// 透視投影行列を作成
	Matrix4x4ex projectionMatrix = Func.MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
	// ViewportMatrixビューポート変換行列を作成
	Matrix4x4ex viewportMatrix = Func.MakeViewportMatrix(0.0f, 0.0f, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// マウス入力を取得
		POINT mousePosition;
		GetCursorPos(&mousePosition);

		///
		/// ↓更新処理ここから
		///

		// マウスドラッグによる回転制御
		if (Novice::IsPressMouse(1))
		{
			if (!isDragging)
			{
				isDragging = true;
				prevMouseX = mousePosition.x;
				prevMouseY = mousePosition.y;
			}
			else
			{
				int deltaX = mousePosition.x - prevMouseX;
				int deltaY = mousePosition.y - prevMouseY;
				rotate.y += deltaX * 0.01f; // 水平方向の回転
				rotate.x += deltaY * 0.01f; // 垂直方向の回転
				prevMouseX = mousePosition.x;
				prevMouseY = mousePosition.y;
			}
		}
		else
		{
			isDragging = false;
		}

		// マウスホイールで前後移動
		int wheel = Novice::GetWheel();
		if (wheel != 0)
		{
			cameraTranslate.z += wheel * 0.01f; // ホイールの回転方向に応じて前後移動
		}

		ImGui::Begin("Control Window");
		if (ImGui::Button("Start"))
		{
			isActive = true; // 動きを開始
		}
		if (ImGui::Button("Reset"))
		{
			isActive = false; // 動きを停止
			// 初期位置にリセット
			sphere.center = { 0.8f, 1.2f, 0.3f };
			ball.velocity = { 0.0f, 0.0f, 0.0f };
		}
		// 平面の回転角度を調整するUIを追加
		ImGui::DragFloat3("Plane.Rotate", &planeRotate.x, 0.01f);
		ImGui::DragFloat("Plane.Distance", &plane.distance, 0.01f);
		ImGui::End();

		// 反発係数
		float restitution = 0.8f;

		// 反発を実装
		if (isActive)
		{
			ball.velocity += ball.acceleration * deltaTime;
			sphere.center += ball.velocity * deltaTime;

			// 平面との衝突判定
			float distanceToPlane = Func.Dot(plane.normal, sphere.center) - plane.distance;
			if (distanceToPlane < sphere.radius)
			{
				// 反射処理
				Vector3ex reflected = Func.Reflect(ball.velocity, plane.normal);
				ball.velocity = reflected * restitution;

				// 衝突面から少し離す
				sphere.center = sphere.center + plane.normal * (sphere.radius - distanceToPlane);

				// 新しい位置を計算して平面外に移動
				distanceToPlane = Func.Dot(plane.normal, sphere.center) - plane.distance;
				sphere.center += plane.normal * (sphere.radius - distanceToPlane);

				// 新しい位置を計算して平面外に移動
				distanceToPlane = Func.Dot(plane.normal, sphere.center) - plane.distance;
				sphere.center += plane.normal * (sphere.radius - distanceToPlane);
			}
		}

		// 各種行列の計算
		Matrix4x4ex worldMatrix = Func.MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, rotate, translate);
		Matrix4x4ex cameraMatrix = Func.MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4ex viewWorldMatrix = Func.Inverse(worldMatrix);
		Matrix4x4ex viewCameraMatrix = Func.Inverse(cameraMatrix);
		Matrix4x4ex viewProjectionMatrix = Func.Multiply(viewWorldMatrix, Func.Multiply(viewCameraMatrix, projectionMatrix));

		Matrix4x4ex rotationXMatrix = Func.MakeRotateXMatrix(planeRotate.x);
		Matrix4x4ex rotationYMatrix = Func.MakeRotateYMatrix(planeRotate.y);
		Matrix4x4ex rotationZMatrix = Func.MakeRotateZMatrix(planeRotate.z);
		Matrix4x4ex rotationMatrix = Func.Multiply(Func.Multiply(rotationXMatrix, rotationYMatrix), rotationZMatrix);


		plane.normal = TransformNormal(abc, rotationMatrix);
		plane.normal = Func.Normalize(plane.normal);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// Gridを描画
		Func.DrawGrid(viewProjectionMatrix, viewportMatrix);
		Func.DrawPlane(plane, viewProjectionMatrix, viewportMatrix, WHITE);
		Func.DrawSphere(sphere, viewProjectionMatrix, viewportMatrix, ball.color);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
		{
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
