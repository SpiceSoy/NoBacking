// NoBacking.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include <atlimage.h>
#include "GameFramework.h"
#include "resource.h"

#define PEEKMESSAGE

#define UM_TIMER 5124124

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"S";
LPCTSTR lpszWindowName = L"Inversus";

constexpr size_t X_SIZE = 1000;
constexpr size_t Y_SIZE = 820;
constexpr size_t Margin = 50;

constexpr int interval = 1000;

LRESULT CALLBACK wProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

LONGLONG updatecnt = 0;
static GameFramework framework;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ipszCmdParam, int mCmdShow)
{
	framework.Create();
	static bool timeStart = false;
	static LARGE_INTEGER Frequency;
	static LARGE_INTEGER BeginTime;
	static LARGE_INTEGER Endtime;

	HWND hWnd;
	MSG Message = MSG();
	WNDCLASSEX WndClass;
	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)wProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDC_MYICON));
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassEx(&WndClass);
	srand(time(NULL));
	hWnd = CreateWindow(
		lpszClass, lpszWindowName,
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_MINIMIZEBOX ^ WS_THICKFRAME | WS_BORDER,
		0, 0, X_SIZE, Y_SIZE,
		NULL, (HMENU)NULL,
		hInstance, NULL
	);
	ShowWindow(hWnd, mCmdShow);
	UpdateWindow(hWnd);
	//SetTimer(hWnd, UM_TIMER, 20, nullptr);
#ifdef PEEKMESSAGE
	while (WM_QUIT != Message.message)
	{
		// 메세지큐에 메세지가 있는지 검사한다.  
		// 메세지가 있건,없건 그냥 리턴한다.  
		if (PeekMessage(&Message, 0, 0, 0, PM_NOREMOVE))
		{
			//메세지 큐에서 메세지를 가져온다.  
			GetMessage(&Message, 0, 0, 0);
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else
		{
			if (timeStart == false)
			{
				QueryPerformanceFrequency(&Frequency);
				QueryPerformanceCounter(&BeginTime);
				QueryPerformanceCounter(&Endtime);
				timeStart = true;
			}

			QueryPerformanceCounter(&Endtime);
			INT64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
			double duringtime = (double)elapsed / (double)Frequency.QuadPart;

			framework.Update(static_cast<float>(duringtime));
			updatecnt++;
			QueryPerformanceCounter(&BeginTime);
			InvalidateRect(hWnd, nullptr, false);
		}
	}
#else
	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
#endif // DEBUG

	return Message.wParam;
}





LRESULT CALLBACK wProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDc;
	static HDC bufferDc;
	static CImage backbufferImg;
	static HBITMAP OldBufferBit;
	static HBITMAP hBufferBit;

	static HDC StretchDc;
	static HBITMAP OldStretchBit;
	static HBITMAP hStretchBit;

	static HDC ImageDc;

	static POINT center = { X_SIZE / 2 , Y_SIZE / 2 };
	static RECT ClientRect = {};

	static LARGE_INTEGER Frequency;
	static LARGE_INTEGER BeginTime;
	static LARGE_INTEGER Endtime;
	static bool timeStart = false;

	static bool isClicked = false;

	switch (iMessage)
	{
	case WM_CREATE:
	{
		hDc = GetDC(hWnd);



		GetClientRect(hWnd, &ClientRect);
#ifdef PEEKMESSAGE
		//SetTimer(hWnd, UM_TIMER, interval, nullptr);
#else
		SetTimer(hWnd, UM_TIMER, interval, nullptr);
#endif // PEEKMESSAGE

		ReleaseDC(hWnd, hDc);
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		}
	}
	break;
	case WM_LBUTTONDOWN:
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		framework.MouseInput(Vec2DU{ xPos,yPos }, iMessage);
	}
	break;
	case WM_MOUSEMOVE:
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		framework.MouseInput(Vec2DU{ xPos,yPos }, iMessage);
	}
	break;
	case WM_LBUTTONUP:
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		framework.MouseInput(Vec2DU{ xPos,yPos }, iMessage);
	}
	break;
	case WM_TIMER:
	{
		switch (wParam)
		{
		case UM_TIMER:
		{
#ifdef PEEKMESSAGE
			InvalidateRect(hWnd, nullptr, false);
#else
			if (timeStart == false)
			{
				QueryPerformanceFrequency(&Frequency);
				QueryPerformanceCounter(&BeginTime);
				QueryPerformanceCounter(&Endtime);
				timeStart = true;
			}

			QueryPerformanceCounter(&Endtime);
			INT64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
			double duringtime = (double)elapsed / (double)Frequency.QuadPart;

			framework.Update(static_cast<float>(duringtime));

			QueryPerformanceCounter(&BeginTime);
			InvalidateRect(hWnd, nullptr, false);
#endif // PEEKMESSAGE

		}
		break;
		default:
			break;

		}
	}
	break;
	case WM_PAINT:
	{

		//39 *  21
		hDc = BeginPaint(hWnd, &ps);
		ImageDc = CreateCompatibleDC(hDc);
		//bufferDc = CreateCompatibleDC(hDc);
		StretchDc = CreateCompatibleDC(hDc);
		if (hBufferBit == NULL)
		{
			hBufferBit = CreateCompatibleBitmap(hDc, (ClientRect.right + Margin), (ClientRect.bottom + Margin));
			backbufferImg.Create((ClientRect.right + Margin), (ClientRect.bottom + Margin), 24, 0);
		}
		bufferDc = backbufferImg.GetDC();
		if (hStretchBit == NULL)
		{
			hStretchBit = CreateCompatibleBitmap(hDc, X_SIZE, Y_SIZE);
		}
		OldBufferBit = (HBITMAP)SelectObject(bufferDc, hBufferBit);
		OldStretchBit = (HBITMAP)SelectObject(StretchDc, hStretchBit);
		RECT BufferRect = { 0,0,(ClientRect.right + Margin),(ClientRect.bottom + Margin) };
		FillRect(bufferDc, &BufferRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
		FillRect(StretchDc, &ClientRect, (HBRUSH)GetStockObject(BLACK_BRUSH));

		PaintInfo pInfo;
		pInfo.hinst = g_hInst;
		pInfo.hdc = bufferDc;
		pInfo.imageDc = ImageDc;
		pInfo.stretchDc = StretchDc;
		pInfo.margin = Margin;
		pInfo.DrawSize = Vec2DU{ ClientRect.right,ClientRect.bottom };
		pInfo.CollisionPen[0] = CreatePen(PS_DASH, 2, RGB(0, 255, 0));
		pInfo.CollisionPen[1] = CreatePen(PS_DASH, 2, RGB(255, 0, 255));
		pInfo.CollisionPen[2] = CreatePen(PS_DASH, 2, RGB(255, 255, 0));

		framework.Draw(pInfo);

		SetStretchBltMode(StretchDc, COLORONCOLOR);


		StretchBlt(hDc, 0, 0, ClientRect.right ,ClientRect.bottom,
			bufferDc, pInfo.StartPoint().x, pInfo.StartPoint().y , pInfo.DrawSize.x, pInfo.DrawSize.y,
			SRCCOPY);
		DeleteObject(pInfo.CollisionPen[0]);
		DeleteObject(pInfo.CollisionPen[1]);
		DeleteObject(pInfo.CollisionPen[2]);


		//BitBlt(hDc, 0, 0, ClientRect.right, ClientRect.bottom, StretchDc, 0, 0, SRCCOPY);
		SelectObject(bufferDc, OldBufferBit);
		SelectObject(StretchDc, OldStretchBit);
		DeleteDC(StretchDc);
		backbufferImg.ReleaseDC();
		//DeleteDC(bufferDc);
		DeleteDC(ImageDc);
		EndPaint(hWnd, &ps);
	}
	break;

	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}