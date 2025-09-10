#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winternl.h>

NTSYSAPI NTSTATUS NTAPI RtlIdnToAscii(ULONG Flags, PCWSTR SourceString, LONG SourceStringLength, PWSTR DestinationString, PLONG DestinationStringLength);

int main() {
	const wchar_t *s = L"🍊.神.tw";
	wchar_t buf[256] = {0};
	ULONG l = ARRAYSIZE(buf);
	NTSTATUS result = RtlIdnToAscii(0, s, wcslen(s) + 1, buf, &l);
	printf("0x%.8x; %d\n", result, l); // beware that l includes null byte
	printf("converted: %S\n", buf);
}
