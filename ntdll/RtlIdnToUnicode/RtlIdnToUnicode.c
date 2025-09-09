#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winternl.h>

NTSYSAPI NTSTATUS NTAPI RtlIdnToUnicode(ULONG Flags, PCWSTR SourceString, LONG SourceStringLength, PWSTR DestinationString, PLONG DestinationStringLength);

int main() {
	const wchar_t *s = L"xn--abcdefgh-km2m84qs1yttfgvynjmy7det9a8b.xn--network-zk3sf38i.xn--tw-4k6c029h";
	wchar_t buf[256] = {0};
	ULONG l = ARRAYSIZE(buf);
	NTSTATUS result = RtlIdnToUnicode(0, s, wcslen(s), buf, &l);
	printf("0x%.8x; %d\n", result, l);
	buf[l < ARRAYSIZE(buf) ? l : ARRAYSIZE(buf) - 1] = 0;

	// workaround for output unicode in WSL
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), buf, l, NULL, NULL);
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"\n", 1, NULL, NULL);
}
