#include <Windows.h> // �� �ϳ� ����� ��� API�Լ����� ����/ ����ϴ� �Լ��� ������.


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // �Լ� ����
HINSTANCE g_hinst; // ���α׷� �ڵ��� ������ �������� ���� hInstance�� ���������� �׷�.
LPSTR lpszClass = "First"; // ���� ���ڿ�, �� ���ڿ��� ������ Ŭ������ �����ϴµ� ���.

//int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance ,LPSTR lpszCmdParam,int nCmdShow) �� ������.
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpszCmdParam, int nCmdShow) {
	// �����츦 ����� ȭ�鿡 ����� ��Ŵ.

// ���α׷��� �������� API ���� Main�Լ��� �ƴ� WinMain �Լ���.
	//hInstance = ���α׷��� �ν��Ͻ� �ڵ� �� ���α׷��� �ڵ鰪�� �� ������ ���α׷����� ������. ( ex :  �޸��� 2�� �϶� �����ϴ°�)
	//hPrevInstance = �ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ�. ���� ��� NULL��
	//lpCmdLine = ��������� �Էµ� ���α׷� �μ�
	//nCmdShow = ���α׷��� ����� ���� / �ּ�ȭ , ������ ���� ���޵�.
	// �� �� hInstance �̿ܿ��� �� ������ �ʴ� ����.
	// Instance �� Ŭ������ �޸𸮿� ������ ������ ��ü�� �ǹ���. �ν��Ͻ�ȭ -> Ŭ������ �޸𸮿� �ø��� ���� �ǹ�.
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hinst = hInstance;

	WndClass.cbClsExtra = 0; // ������ ���� ����, Ư���� ������ ������ �ʴ� �� 0���� ������.
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); // �������� �������� ������.
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // �� �����찡 ����� ���콺 Ŀ�� ����.
	/*// LoadCussor�Լ��� ù��° �μ��� Ŀ���� ������ �ִ� ���α׷��� �ν��Ͻ� �ڵ�.
	// �� �⺻ Ŀ�� ����ҷ��� NULL�� ����. �ι�° �μ��� ����Ϸ��� Ŀ���� �̸� ����.
	// IDC_ARROW ȭ��ǥ ��� 
	// IDC_CROSS ���ڸ��
	// IDC_IBEAM I�� ���
	// IDC_NO ���ȿ� ������ ������ ���
	// IDC_WAIT �𷡽ð� ���*/
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // �� �����찡 �ּ�ȭ�� ��� ��µ� ������ ����.
	WndClass.hInstance = hInstance; //�� ������ Ŭ������ ����ϴ� ���α׷��� ��ȣ(�ڵ�)��. 
									//�� ���� WinMain�� �μ��� ���޵� hInstance�� �׳� �����ϸ� ��.
	WndClass.lpfnWndProc = (WNDPROC)WndProc; // �������� �޼��� ó�� �Լ��� ����, �޼����� �߻� �� ���⼭ ������ �Լ��� ȣ���.
	WndClass.lpszClassName = lpszClass; // ������ Ŭ������ �̸��� ������. 
	WndClass.lpszMenuName = NULL; // �� ���α׷��� ����� �޴��� ������.
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // �������� ���� ���� ũ�Ⱑ ���Ҷ� �����츦 �ٽ� �׸���.
	// �߿��� ����� lpszClassName�� lpfnWndProc��, �޼��� ó��/ Ŭ���� �̸� ����.
	RegisterClass(&WndClass);// ������ Ŭ������ �����.

	hWnd = CreateWindow(lpszClass, "My First Program", WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL, 100, 100, 800
		, 600, NULL, (HMENU)NULL, hInstance, NULL);
	/*// HWND CreateWindow(lpszClassName, lpszWindowName, dwStyle, x, 
	//y, nWidth, nHeight, hwndParent, hmenu, hinst, lpvParam)  �� ������.
	// lpszClassName �����ϰ��� �ϴ� �������� Ŭ���� �����ϴ� ���ڿ�.
	// lpszWindowName �������� Ÿ��Ʋ �ٿ� ��Ÿ�� ���ڿ�.
	// dwStyle ������� �ϴ� �������� ���¸� ����. WS_OVERAPPEDWINDOW�� ����ϸ� ������ ������ ��.
	// X,Y nWidth, nHeight �������� ũ��� ��ġ�� ������.
	// x,y ��ǥ�� ���� ������ ���( ��üȭ�� ����) ���ϵ� ������ ���( �θ��� �»�� ����) ������ ��������.
	// CS_USEDEFAULT�� ��� �� ��������� ������ ũ�� ã�Ƽ� ����.
	// hWndParent �θ� ������ ���� �� �θ��� �ڵ��� ��������. ���� �� NULL.
	// hmenu �����켭 ����� �޴��� �ڵ��� ����. Ŭ�������� �����ϴ� �޴����� �������� Ŭ�������� �����ϸ� 
	// �� Ŭ������ ������� �ϴ� ��� �����쿡�� ���� �ݸ�, �� �μ��� ������ �޴��� CreateWindow�� ������� ������
	// ������ ����. NULL�� �ϸ� Ŭ�������� ������ ���� ����. 
	// hinst �����츦 ����� ��ü, �� ���α׷��� �ڵ��� ������.
	// lpvParam Ư���� ������ ���. �ַ� NULL. */
	// dwStyle�� ����
	// WS_CAPTION Ÿ��Ʋ �ٸ� ����.
	// WS_HSCROLL ���� ��ũ�� �ٸ� ����.
	// WS_VSCROLL ���� ��ũ�� �ٸ� ����.
	// WS_MAXIMIZBOX �ִ�ȭ ��ư�� ����.
	// WS_MINIMIZEBOX �ּ�ȭ ��ư�� ����.
	// WS_SYSMENU �ý��� �޴��� ����.
	// WS_THICKFRAME ũ�⸦ ������ �� �ִ� ��Լ� ����.
	// CreateWindow �Լ��� �������� ��� ������ �޸𸮿� ���� �� ������ �ص��� ���ϰ����� �ѱ�.
	ShowWindow(hWnd, nCmdShow);
	// hWnd �μ��� ȭ������ ����ϰ��� �ϴ� �������� �ڵ�(�νĹ�ȣ)��.
	// nCmdShow�� ȭ�鿡 ����ϴ� ����� ������. 
	/*// SW_HIDE �����츦 ����
	// SW_MINIMIZE �����츦 �ּ�ȭ ��Ű�� Ȱ��ȭ ��Ű�� ����.
	// SW_RESTORE �����츦 Ȱ��ȭ��Ŵ
	// SW_SHOW �����츦 Ȱ��ȭ���� ������
	// SW_SHOWNORMAL �����츦 Ȱ��ȭ ���Ѻ�����*/
	while (GetMessage(&Message, 0, 0, 0))//���� �޼����� WnmdProc�� ����ü�� ����
	{ 
		// GetMessage �Լ��� �޼��� ť���� �޼����� ����. ù��° �μ��� �о���� �޼��� ����
		// ���α׷��� �����϶�� WM_QUIT�� �޼������� ���ð�� false ���� �׿ܿ� true ���� 
		// �޼��� ť���� �޼����� ���� WndProc�� ������ ���Ҹ� ��.
		// �޼��� ������ ���۵�.
		TranslateMessage(&Message); // Ű���� �Է��� �߻����� �� ���ڰ� �ԷµǾ��ٴ� �޼����� ����.
		DispatchMessage(&Message);//WndProc�� ����ü�� ��¥�� WndProc�� ������.
		// �޼��� ť���� ���� �޼����� WinProc�� ������.
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{  /* // �ü���� ���� ȣ��Ǵ� ���� ���α׷����� �Լ��� �ݹ� �Լ���� �Ѵ�.
	// wParam�� lParam�� �� -> ���콺 ��ư�� ���������� ������ ��ġ���� ����, �� ���� Ű���� ��Ȳ�� ��� ���� 
	//�߰� ������ �ʿ��ѵ� �װ��� w/lParam���� ����.
	// WinMain �� �� �ܿ� ��κ��� ���� ����.
	//hWnd �޼����� ���� ������ �ڵ���.
	// message � ������ �޼����ΰ��� ��Ÿ��. �߿���
	// wParam �޼����� ���� �ΰ����� ������ ����.
	// lParam ���� ����.
	// time �޼����� �߻��� �ð���
	// pt �޼����� �߻����� ���� ���콺 ��ġ*/
/*    // �޼��� ���� ( �޼����� ���������� ǥ���ǹǷ� ����ġ ���� ����� ������. )
	// WM_QUIT ���α׷��� ���� �� �߻��ϴ� �޼���.
	// WM_LBUTTONDOWN ���콺�� ������ư�� ���� �� �߻�.
	// WM_CHAR Ű����κ��� ���ڰ� �Էµ� �� �߻�.
	// WM_PAINT ȭ���� �ٽ� �׷��� �� �ʿ䰡 ���� �� �߻��Ѵ�.
	// WM_DESTROY �����찡 �޸𸮿��� �ı��� �� �߻��Ѵ�.
	// WM_CREATE �����찡 ó�� ������� �� �߻��Ѵ�. */
	switch (iMessage) { //�긦 ����ġ�� �ξ� �������� �޼��� �������� case�� ��밡����.

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	/*// DefWindowProc�� ���� �޼����� ������ �ٸ� ��� ó���� �������.
	// ���� �ڵ忡�� DESTROY �ϳ����� ó���ϰ� ������ �޼����� DefWindowProc���� ó���ϰ� ��.
	// WM_DESTROY�� ���α׷��� ���ᰡ �߻� �� WM_QUIT�� ������.
	// WM_QUIT�� �߻��ϸ� ���� �޼��������� ���ϰ��� false�� �Ǿ� ���α׷��� ���������� �����.*/
}