#include <Windows.h>
#include <iostream>
#include <WinReg.hpp>
namespace RegEdit {
	void SetReg() {
		std::cout << "Hello, It is My First Cpp Disabler UAC... So Enjoy to use!!!" << std::endl;
		winreg::RegKey key{ HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", KEY_ALL_ACCESS };
		if (!key) {
			std::cout << "Failed to Opened This Folder!!!" << std::endl;
			Sleep(4300);
			exit(3200);
		}
		winreg::RegResult res = key.TryOpen(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", KEY_ALL_ACCESS);
		if (!res) {
			std::cout << "Failed To Opened Current Regedit Folder" << std::endl;
			Sleep(7000);
			exit(323);
		}
		key.TryDeleteValue(L"EnableLUA");
		key.TrySetDwordValue(L"EnableLUA", 0);
		std::cout << "Successfully Disabled UAC..." << std::endl;
	}
}

int main() 
{
	RegEdit::SetReg();
	return 0;
}