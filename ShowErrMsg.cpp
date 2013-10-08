// エラーコードから、メッセージを取得するためのサンプル
#include "stdafx.h"

// dxerr9 の API を使う
void HrToStrByDxErr(HRESULT hr) {
	TCHAR szMsg[MAX_ERROR_TEXT_LEN+MAX_PATH+256];
	_snwprintf_s(szMsg, _countof(szMsg), _TRUNCATE,
		TEXT("HRESULT=%08X (%s) ErrStr=%s Desc=%s\n")
		, hr
		, (FAILED(hr)) ? TEXT("FAILED") : TEXT("SUCCEEDED")
		, DXGetErrorString9(hr), DXGetErrorDescription9(hr));
	OutputDebugString(szMsg);
}

// AMGetErrorText を使う
void HrToStrByAMGet(HRESULT hr) {
	TCHAR szErr[MAX_ERROR_TEXT_LEN];
	TCHAR szMsg[MAX_ERROR_TEXT_LEN+MAX_PATH+256];
	// MAX_ERROR_TEXT_LEN は errors.h で定義済み
	AMGetErrorText(hr,szErr,MAX_ERROR_TEXT_LEN);
	_snwprintf_s(szMsg, _countof(szMsg), _TRUNCATE,
		_T("HRESULT=%08X (%s) %s")
		, hr
		, (FAILED(hr)) ? TEXT("FAILED") : TEXT("SUCCEEDED")
		, szErr);
	OutputDebugString(szMsg);
}

// FormatMessage を使う
void HrToStr(HRESULT hr) {
    LPVOID string;
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                  FORMAT_MESSAGE_FROM_SYSTEM,
                  NULL,
                  hr,
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                  (LPTSTR)&string,
                  0,
                  NULL);
    if (string != NULL)
        OutputDebugString((LPCWSTR)string);
    LocalFree(string);
}

int _tmain(int argc, _TCHAR* argv[]) {
	HRESULT hr=NOERROR;
	// 第一引数を !=NULL にして、わざとエラーコードを出す
	int *p=(int*)0x1;
	hr=CoInitializeEx(p, COINIT_APARTMENTTHREADED);
	HrToStrByDxErr(hr);
	HrToStrByAMGet(hr);
	HrToStr(hr);
	return 0;
}
