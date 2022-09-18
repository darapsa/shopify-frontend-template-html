#include <emscripten/fetch.h>

int main(int argc, char *argv[])
{
	EM_ASM(authenticatedFetch("/products"));
}
