#include <Windows.h> // 요 하나 헤더에 모든 API함수들의 원형/ 사용하는 함수를 정의함.


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 함수 선언
HINSTANCE g_hinst; // 프로그램 핸들을 저장할 전역변수 선언 hInstance는 지역변수라 그럼.
LPSTR lpszClass = "First"; // 전역 문자열, 이 문자열은 윈도우 클래스를 정의하는데 사용.

//int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance ,LPSTR lpszCmdParam,int nCmdShow) 가 원형임.
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpszCmdParam, int nCmdShow) {
	// 윈도우를 만들고 화면에 출력을 시킴.

// 프로그램의 시작점은 API 에선 Main함수가 아닌 WinMain 함수임.
	//hInstance = 프로그램의 인스턴스 핸들 즉 프로그램의 핸들값임 이 값으로 프로그램들을 구분함. ( ex :  메모장 2개 일때 구분하는거)
	//hPrevInstance = 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들. 없을 경우 NULL임
	//lpCmdLine = 명령행으로 입력된 프로그램 인수
	//nCmdShow = 프로그램이 실행될 형태 / 최소화 , 보통모양 등이 전달됨.
	// 이 중 hInstance 이외에는 잘 사용되지 않는 편임.
	// Instance 란 클래스가 메모리에 실제로 구현된 실체를 의미함. 인스턴스화 -> 클래스를 메모리에 올리는 것을 의미.
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hinst = hInstance;

	WndClass.cbClsExtra = 0; // 일종의 예약 영역, 특수한 목적에 사용되지 않는 한 0으로 지정함.
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); // 윈도우의 배경색상을 지정함.
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 이 윈도우가 사용할 마우스 커서 지정.
	/*// LoadCussor함수의 첫번째 인수는 커서를 가지고 있는 프로그램의 인스턴스 핸들.
	// 즉 기본 커서 사용할려면 NULL로 지정. 두번째 인수는 사용하려는 커서의 이름 지정.
	// IDC_ARROW 화살표 모양 
	// IDC_CROSS 십자모양
	// IDC_IBEAM I자 모양
	// IDC_NO 원안에 빗금이 새겨진 모양
	// IDC_WAIT 모래시계 모양*/
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 이 윈도우가 최소화될 경우 출력될 아이콘 지정.
	WndClass.hInstance = hInstance; //이 윈도우 클래스를 사용하는 프로그램의 번호(핸들)임. 
									//이 값은 WinMain의 인수로 전달된 hInstance를 그냥 대입하면 됨.
	WndClass.lpfnWndProc = (WNDPROC)WndProc; // 윈도우의 메세지 처리 함수를 지정, 메세지가 발생 시 여기서 지정한 함수가 호출됨.
	WndClass.lpszClassName = lpszClass; // 윈도우 클래스의 이름을 정의함. 
	WndClass.lpszMenuName = NULL; // 이 프로그램이 사용할 메뉴를 지정함.
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // 윈도우의 수직 수평 크기가 변할때 윈도우를 다시 그린다.
	// 중요한 멤버는 lpszClassName과 lpfnWndProc임, 메세지 처리/ 클래스 이름 정의.
	RegisterClass(&WndClass);// 윈도우 클래스를 등록함.

	hWnd = CreateWindow(lpszClass, "My First Program", WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL, 100, 100, 800
		, 600, NULL, (HMENU)NULL, hInstance, NULL);
	/*// HWND CreateWindow(lpszClassName, lpszWindowName, dwStyle, x, 
	//y, nWidth, nHeight, hwndParent, hmenu, hinst, lpvParam)  가 원형임.
	// lpszClassName 생성하고자 하는 윈도우의 클래스 지정하는 문자열.
	// lpszWindowName 윈도우의 타이틀 바에 나타날 문자열.
	// dwStyle 만들고자 하는 윈도우의 형태를 지정. WS_OVERAPPEDWINDOW를 사용하면 무난한 설정이 됨.
	// X,Y nWidth, nHeight 윈도우의 크기와 위치를 지정함.
	// x,y 좌표는 메인 윈도우 경우( 전체화면 기준) 차일드 윈도우 경우( 부모의 좌상단 기준) 정수값 지정가능.
	// CS_USEDEFAULT를 사용 시 윈도우즈에서 적절한 크기 찾아서 해줌.
	// hWndParent 부모 윈도가 있을 때 부모의 핸들을 지정해줌. 없을 땐 NULL.
	// hmenu 윈도우서 사용할 메뉴의 핸들을 지정. 클래스에서 지정하는 메뉴와의 차이점은 클래스에서 지정하면 
	// 그 클래스를 기반으로 하는 모든 윈도우에서 사용됨 반면, 이 인수로 지정된 메뉴는 CreateWindow로 만들어진 윈도우
	// 에서만 사용됨. NULL로 하면 클래스에서 지정된 값이 사용됨. 
	// hinst 윈도우를 만드는 주체, 즉 프로그램의 핸들을 지정함.
	// lpvParam 특수한 목적에 사용. 주료 NULL. */
	// dwStyle의 종류
	// WS_CAPTION 타이틀 바를 가짐.
	// WS_HSCROLL 수평 스크롤 바를 가짐.
	// WS_VSCROLL 수직 스크롤 바를 가짐.
	// WS_MAXIMIZBOX 최대화 버튼을 가짐.
	// WS_MINIMIZEBOX 최소화 버튼을 가짐.
	// WS_SYSMENU 시스템 메뉴를 가짐.
	// WS_THICKFRAME 크기를 조절할 수 있는 경게선 가짐.
	// CreateWindow 함수는 윈도우의 모든 정보를 메모리에 만든 후 윈도우 해들을 리턴값으로 넘김.
	ShowWindow(hWnd, nCmdShow);
	// hWnd 인수는 화면으로 출력하고자 하는 윈도우의 핸들(인식번호)임.
	// nCmdShow는 화면에 출력하는 방법을 지정함. 
	/*// SW_HIDE 윈도우를 숨김
	// SW_MINIMIZE 윈도우를 최소화 시키고 활성화 시키지 않음.
	// SW_RESTORE 윈도우를 활성화시킴
	// SW_SHOW 윈도우를 활성화시켜 보여줌
	// SW_SHOWNORMAL 윈도우를 활성화 시켜보여줌*/
	while (GetMessage(&Message, 0, 0, 0))//읽은 메세지를 WnmdProc의 구조체로 전달
	{ 
		// GetMessage 함수는 메세지 큐에서 메세지를 읽음. 첫번째 인수에 읽어들인 메세지 저장
		// 프로그램을 종료하라는 WM_QUIT가 메세지에서 나올경우 false 리턴 그외에 true 리턴 
		// 메세지 큐에서 메세지를 꺼내 WndProc로 보내는 역할만 함.
		// 메세지 루프가 시작됨.
		TranslateMessage(&Message); // 키보드 입력이 발생했을 때 문자가 입력되었다는 메세지를 만듦.
		DispatchMessage(&Message);//WndProc의 구조체를 진짜로 WndProc로 전달함.
		// 메세지 큐에서 꺼낸 메세지를 WinProc로 전달함.
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{  /* // 운영체제에 의해 호출되는 응용 프로그램내의 함수를 콜백 함수라고 한다.
	// wParam과 lParam의 예 -> 마우스 버튼이 눌러졋을때 눌려진 위치등을 저장, 그 때의 키보드 상황은 어떤가 등의 
	//추가 정보가 필요한데 그것을 w/lParam에서 맡음.
	// WinMain 의 일 외에 대부분의 일을 맡음.
	//hWnd 메세지를 받을 윈도우 핸들임.
	// message 어떤 종류의 메세지인가를 나타냄. 중요함
	// wParam 메세지에 대한 부가적인 정보를 가짐.
	// lParam 위와 같음.
	// time 메세지가 발생한 시간임
	// pt 메세지가 발생했을 때의 마우스 위치*/
/*    // 메세지 종류 ( 메세지는 정수값으로 표현되므로 스위치 문에 사용이 가능함. )
	// WM_QUIT 프로그램을 끝낼 때 발생하는 메세지.
	// WM_LBUTTONDOWN 마우스의 좌측버튼을 누를 때 발생.
	// WM_CHAR 키보드로부터 문자가 입력될 때 발생.
	// WM_PAINT 화면을 다시 그려야 할 필요가 있을 때 발생한다.
	// WM_DESTROY 윈도우가 메모리에서 파괴될 때 발생한다.
	// WM_CREATE 윈도우가 처음 만들어질 때 발생한다. */
	switch (iMessage) { //얘를 스위치로 두어 정수값인 메세지 종류들을 case로 사용가능함.

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	/*// DefWindowProc는 위에 메세지를 제외한 다른 모든 처리를 담당해줌.
	// 지금 코드에선 DESTROY 하나만을 처리하고 나머지 메세지는 DefWindowProc에서 처리하게 함.
	// WM_DESTROY는 프로그램의 종료가 발생 시 WM_QUIT를 리턴함.
	// WM_QUIT가 발생하면 위에 메세지루프의 리턴값이 false가 되어 프로그램이 실절적으로 종료됨.*/
}