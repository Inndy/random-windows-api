#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winternl.h>

void NTAPI A_SHAInit(LPVOID Context);
void NTAPI A_SHAUpdate(LPVOID Context, LPCVOID Data, ULONG Size);
void NTAPI A_SHAFinal(LPVOID Context, LPVOID Hash);

void sha1(const void *data, size_t len) {
	BYTE ctx[0x5c];
	A_SHAInit(&ctx);
	A_SHAUpdate(ctx, data, len);

	BYTE h[20] = {};
	A_SHAFinal(ctx, h);

	for (int i = 0; i < sizeof(h); i++)
		printf("%.2x", h[i]);
	printf("\n");
}

int main() {
	const char *s = "123456";
	sha1(s, strlen(s));
}
