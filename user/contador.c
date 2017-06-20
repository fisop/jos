#include <inc/lib.h>

static void contador(int linea, int color, int delay);

void
umain(int argc, char **argv)
{
	int lineas[] = { 0, 3, 7 };
	int delays[] = { 1, 4, 7 };
	int colores[] = { 0x2f, 0x6f, 0x4f };

	int i = (sys_getenvid() - 1) % 3;
	contador(lineas[i], colores[i], delays[i]);
}

static void
contador(int linea, int color, int delay)
{
	char counter[40] = { '0' };  // Our ASCII digit counter (RTL).

	while (1) {
		char *buf = (void *) VGA_USER + linea * 160;
		char *c = &counter[40];

		unsigned p = 0;
		unsigned long long int i = 1ULL << (delay + 15);

		// Cambiar por una llamada a sleep_ticks() una vez implementado.
		while (i--)
			;

		while (counter[p] == '9') {
			counter[p++] = '0';
		}

		if (!counter[p]++) {
			counter[p] = '1';
		}

		while (c-- > counter) {
			*buf++ = *c;
			*buf++ = color;
		}
	}
}
