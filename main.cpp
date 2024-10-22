#include <windows.h>
#include <iostream>
#include <sstream>

int algorithm(int m, int n, int k, int* d, int* re){
	int t=0;//加油次数 
	int sum=n;//还能行驶的距离 
	int reindex = 0;
	for(int i=0;i<k+1;i++){
		if(sum<d[i]){//不能到下一个加油站了
			re[reindex++] = i;	// 在第 i 个加油站加油
			sum=n;//加满油 
			t++;
			if(sum<d[i]){//加满之后还不能到达 
				return -1;
			}
			
		}
		sum-=d[i];//行驶 
	}
	return t;
}


/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	HFONT hFont;
	HWND hEdit1, hEdit2, hEdit3, hEdit4;
	HWND hStatic1, hStatic2, hStatic3, hStatic4, hStatic5;
	HWND hSubmitButton, MsgBox;
	switch(Message) {
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			HFONT hFont = (HFONT)SendMessage(GetDlgItem(hwnd, 1), WM_GETFONT, 0, 0);
			DeleteObject(hFont);
			PostQuitMessage(0);
			break;
		}
		
		
		case WM_GETMINMAXINFO: {
			MINMAXINFO* minMaxInfo = (MINMAXINFO*)lParam;
			minMaxInfo->ptMinTrackSize.x = 640; // 设置最小宽度
			minMaxInfo->ptMinTrackSize.y = 640; // 设置最小高度
			minMaxInfo->ptMaxTrackSize.x = 640; // 设置最大宽度
			minMaxInfo->ptMaxTrackSize.y = 640; // 设置最大高度
			return 0;
		}
		
		// 创建控件
		case WM_CREATE: {
			// 设置字体
			hFont = CreateFont(15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_MODERN, "黑体");
			
			// 创建参数 m 的输入框
			hStatic1 = CreateWindowEx(0, "STATIC", "ab点间的距离 m ", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_NOTIFY | SS_CENTERIMAGE, 20, 50, 150, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);	
			hEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL, 190, 50, 200, 25, hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);
			
			
			// 创建参数 n 的输入框
			hStatic2 = CreateWindowEx(0, "STATIC", "汽车能行驶的距离 n ", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_NOTIFY | SS_CENTERIMAGE, 20, 100, 150, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
			hEdit2 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL, 190, 100, 200, 25, hwnd, (HMENU)2, GetModuleHandle(NULL), NULL);
			
			
			// 创建参数 k 的输入框
			hStatic3 = CreateWindowEx(0, "STATIC", "加油站的数量 k ", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_NOTIFY | SS_CENTERIMAGE, 20, 150, 150, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
			hEdit3 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL, 190, 150, 200, 25, hwnd, (HMENU)3, GetModuleHandle(NULL), NULL);
			
			// 创建参数加油站的距离 d[] 的输入框
			hStatic4 = CreateWindowEx(0, "STATIC", "加油站间的间隔 di ", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_NOTIFY | SS_CENTERIMAGE, 20, 200, 150, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
			hEdit4 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL, 190, 200, 400, 25, hwnd, (HMENU)4, GetModuleHandle(NULL), NULL);
			
			// 提交按钮
			hSubmitButton = CreateWindowEx(0, "BUTTON", "提交", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 20, 250, 100, 30, hwnd, (HMENU)5, GetModuleHandle(NULL), NULL);
			
			// 添加一根分割线
			HWND hSeparator = CreateWindowEx(0, "STATIC", "", WS_CHILD | WS_VISIBLE | SS_ETCHEDHORZ, 0, 300, 640, 10, hwnd, NULL, GetModuleHandle(NULL), NULL);
			
			// 消息输出框
			hStatic5 = CreateWindowEx(0, "STATIC", "消息输出", WS_CHILD | WS_VISIBLE | SS_NOTIFY | SS_CENTERIMAGE, 20, 325, 75, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
			MsgBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL | ES_READONLY, 20, 360, 580, 200, hwnd, (HMENU)6, GetModuleHandle(NULL), NULL);
			
			
			SendMessage(hStatic1, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hStatic2, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hStatic3, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hStatic4, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hStatic5, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hEdit1, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hEdit2, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hEdit3, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hEdit4, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(hSubmitButton, WM_SETFONT, (WPARAM)hFont, TRUE);
			SendMessage(MsgBox, WM_SETFONT, (WPARAM)hFont, TRUE);

			// input HMENUL: 2,4,6,8
			break;
		}
		
		// 处理控件消息
		case WM_COMMAND: {
			int m, n, k, *d, re[1024];
			if(LOWORD(wParam) == 5) { 
				// 如果是提交按钮被点击
				// 在这里执行提交操作，比如获取输入框内容并处理
				HWND outputBox = GetDlgItem(hwnd, 6);
				
				// 处理 m，n，k 输入
				char mchar[256], nchar[256], kchar[256], dchar[2048];
				std::string mstr, nstr, kstr, dstr, eachd;
				HWND inputBox1 = GetDlgItem(hwnd, 1);
				HWND inputBox2 = GetDlgItem(hwnd, 2);
				HWND inputBox3 = GetDlgItem(hwnd, 3);
				HWND inputBox4 = GetDlgItem(hwnd, 4);
				
				GetWindowText(inputBox1, mchar, sizeof(mchar));
				GetWindowText(inputBox2, nchar, sizeof(nchar));
				GetWindowText(inputBox3, kchar, sizeof(kchar));
				GetWindowText(inputBox4, dchar, sizeof(dchar));
				m = atoi(mchar);	
				n = atoi(nchar);
				k = atoi(kchar);
				mstr.assign(mchar);
				nstr.assign(nchar);
				kstr.assign(kchar);
				dstr.assign(dchar);
				
				// 处理 d 数组输入
				d = new int[k + 1];
				std::istringstream dstrstream(dstr);
				int index = 0;
				while(dstrstream >> eachd){
					d[index++] = std::stoi(eachd);
				}
				std::string end = "INPUT:\r\nm = " + mstr + "\r\n" + "n = " + nstr + "\r\n" + "k = " + kstr + "\r\n" + "D0,……,Dk = " + dstr + "\r\n\r\n";
				// 将参数交给算法执行
				int result = algorithm(m, n, k, d, re);
				std::string refuelI = "";
				if(result == -1){
					end += "OUTPUT:\r\nNo Soluction";
				}else {
					for(int i = 0; i < result; i++){
						refuelI = refuelI + "第" +std::to_string(re[i]) + "个加油站,";
					}
					end += "OUTPUT:\r\nrefuelTimes = " + std::to_string(result) + "\r\nRefuel At: " + refuelI;
				}
				SetWindowText(outputBox, end.c_str());
				delete []d;
				break;
			}
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
	HICON hIcon = (HICON)LoadImageW(NULL, L"E:\\desktop\\postgraduate-LEARNING\\算法设计与分析\\hw2\\hw2\\app.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	
	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon = hIcon;
	wc.hIconSm = hIcon;
	// wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	// wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","GUI界面",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);
	
	// HICON hIcon = LoadIconW(NULL, MAKEINTRESOURCEW(B));
	

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); 	/* Send it to WndProc */
	}
	return msg.wParam;
}
