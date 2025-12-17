#pragma once
#include "pch.h"
class utilities
{
public:
	static bool IsGameFocused() {
		DWORD ProcessID = GetCurrentProcessId();
		DWORD FocusedProcessID;

		GetWindowThreadProcessId(GetForegroundWindow(), &FocusedProcessID);

		if (ProcessID == FocusedProcessID) {
			return true;
		}
		else {
			return false;
		}
	}
};

