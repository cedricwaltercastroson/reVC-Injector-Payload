#pragma warning(disable: 4200)

// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>

#define A 0x41
#define B 0x42
#define C 0x43
#define D 0x44
#define E 0x45
#define F 0x46
#define G 0x47
#define H 0x48
#define I 0x49
#define J 0x4A
#define K 0x4B
#define L 0x4C
#define M 0x4D
#define N 0x4E
#define O 0x4F
#define P 0x50
#define Q 0x51
#define R 0x52
#define S 0x53
#define T 0x54
#define U 0x55
#define V 0x56
#define W 0x57
#define X 0x58
#define Y 0x59
#define Z 0x5A

float MAX_HP = 100.0f;
float MAX_ARMOUR = 100.0f;
unsigned long int MAX_MONEY= 999999999;
unsigned int MAX_FPS = 165;

struct resource1 {
	float HP;
	float ARMOUR;
};

struct resource2 {
	float HP;
	float ARMOUR;
};

struct money_resource {
	int MONEY;
};

struct fps {
	int FPS;
};

struct memory_ptr {
	DWORD base_address;
	int total_offsets;
	int offsets[];
};

memory_ptr hp_hack_ptr = {
		0x002F608C,
			1,
	{0x354}
};

memory_ptr armour_hack_ptr = {
		0x002F608C,
			1,
	{0x358}
};

memory_ptr loaded_hp_hack_ptr = {
		0x002F6014,
			1,
	{0x354}
};

memory_ptr loaded_armour_hack_ptr = {
		0x002F6014,
			1,
	{0x358}
};

memory_ptr money_hack_ptr = {
		0x00523CE0,
			0,
	{0x0}
};

memory_ptr fps_hack_ptr = {
		0x0068187C,
			0,
	{0x0}
};

//pointer to resource struct
resource1* resource_hack1;
resource2* resource_hack2;
money_resource* money_resource_hack;
fps* fps_hack;


// get module base address
HMODULE getBaseAddress() {
	return GetModuleHandle(NULL);
}

DWORD* trace_pointer(memory_ptr* hack) {
	DWORD* location = (DWORD*)((DWORD)getBaseAddress() + (DWORD)hack->base_address);
	for (int i = 0; i < hack->total_offsets; i++) {
		location = (DWORD*)(*location + (int)hack->offsets[i]);
	}
	return location;
}

void init_pointers() {
	resource_hack1 = (resource1*)(trace_pointer(&hp_hack_ptr));
	resource_hack1 = (resource1*)(trace_pointer(&armour_hack_ptr));
	resource_hack2 = (resource2*)(trace_pointer(&loaded_hp_hack_ptr));
	resource_hack2 = (resource2*)(trace_pointer(&loaded_armour_hack_ptr));
	money_resource_hack = (money_resource*)(trace_pointer(&money_hack_ptr));
	fps_hack = (fps*)(trace_pointer(&fps_hack_ptr));
}

void GODMODE() {
	resource_hack1->HP = (float)MAX_HP;
	resource_hack1->ARMOUR = (float)MAX_ARMOUR;
	resource_hack2->HP = (float)MAX_HP;
	resource_hack2->ARMOUR = (float)MAX_ARMOUR;
}

void IHAVETHEMONEYSONNY() {
	money_resource_hack->MONEY = (long int)MAX_MONEY;
}

void FIXFPS() {
	fps_hack->FPS = (int)MAX_FPS;
}

DWORD WINAPI MainThread(LPVOID param) {
	while (true) {
		if (GetAsyncKeyState(VK_NUMPAD0) & 0x80000) {  //enables the goodstuff.. godmode, higher fps, money
			if (fps_hack == NULL) {
				init_pointers();
				Beep(1000, 500);
			}
		}
		if (GetAsyncKeyState(VK_NUMPAD1) & 0x80000) {  // triggers health refill via key combo.. redundant but mainly used to fix vehicles..
			
			const int max_input = 16;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = A;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = A;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = S;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = S;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = P;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = P;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = I;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = I;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = R;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = R;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = I;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = I;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = N;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = N;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			in[14].type = INPUT_KEYBOARD;
			in[14].ki.wVk = E;

			in[15].type = INPUT_KEYBOARD;
			in[15].ki.wVk = E;
			in[15].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (GetAsyncKeyState(VK_NUMPAD2) & 0x80000) {  //bigbang cheat triggers a keycombo..

			const int max_input = 14;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = B;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = B;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = I;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = I;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = G;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = G;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = B;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = B;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = A;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = A;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = N;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = N;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = G;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = G;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (GetAsyncKeyState(VK_NUMPAD3) & 0x80000) {  //LeaveMeAlone Cheat! very helpful when you want things to cooldown..

			const int max_input = 24;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = L;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = L;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = E;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = E;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = A;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = A;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = V;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = V;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = E;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = E;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = M;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = M;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = E;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = E;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			in[14].type = INPUT_KEYBOARD;
			in[14].ki.wVk = A;

			in[15].type = INPUT_KEYBOARD;
			in[15].ki.wVk = A;
			in[15].ki.dwFlags = KEYEVENTF_KEYUP;

			in[16].type = INPUT_KEYBOARD;
			in[16].ki.wVk = L;

			in[17].type = INPUT_KEYBOARD;
			in[17].ki.wVk = L;
			in[17].ki.dwFlags = KEYEVENTF_KEYUP;

			in[18].type = INPUT_KEYBOARD;
			in[18].ki.wVk = O;

			in[19].type = INPUT_KEYBOARD;
			in[19].ki.wVk = O;
			in[19].ki.dwFlags = KEYEVENTF_KEYUP;

			in[20].type = INPUT_KEYBOARD;
			in[20].ki.wVk = N;

			in[21].type = INPUT_KEYBOARD;
			in[21].ki.wVk = N;
			in[21].ki.dwFlags = KEYEVENTF_KEYUP;

			in[22].type = INPUT_KEYBOARD;
			in[22].ki.wVk = E;

			in[23].type = INPUT_KEYBOARD;
			in[23].ki.wVk = E;
			in[23].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (resource_hack1 != NULL || resource_hack2 != NULL || money_resource_hack != NULL || fps_hack != NULL) {  //this gets triggered when the pointers are valid via pressing Numpad0
			GODMODE();
			IHAVETHEMONEYSONNY();
			FIXFPS();
		}
	}
	return 0;
}

//DllMain entry and create MainThread
BOOL APIENTRY DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, MainThread, hInstDLL, 0, 0);
		Beep(1000, 1000);
	}
	return true;
}

