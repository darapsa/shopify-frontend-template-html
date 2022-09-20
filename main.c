#include <stdio.h>
#include <string.h>
#include <emscripten/fetch.h>

static void handle_success(emscripten_fetch_t *fetch)
{
	printf("Finished downloading %llu bytes of %s from URL %s.\n",
			fetch->numBytes, fetch->data, fetch->url);
	emscripten_fetch_close(fetch);
}

static void handle_error(emscripten_fetch_t *fetch)
{
	printf("Downloading %s failed, HTTP failure status code: %d.\n",
			fetch->url, fetch->status);
	emscripten_fetch_close(fetch);
}

void getproducts(const char *token, const char *app_url)
{
	emscripten_fetch_attr_t attr;
	emscripten_fetch_attr_init(&attr);
	strcpy(attr.requestMethod, "GET");
	attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
	attr.onsuccess = handle_success;
	attr.onerror = handle_error;
	static const char *schema = "Bearer ";
	char auth[strlen(schema) + strlen(token) + 1];
	sprintf(auth, "%s%s", schema, token);
	attr.requestHeaders = (const char *[]){ "Authorization", auth, NULL };
	static const char *path = "/products";
	char url[strlen(app_url) + strlen(path) + 1];
	sprintf(url, "%s%s", app_url, path);
	emscripten_fetch(&attr, url);
}

int main(int argc, char *argv[])
{
	EM_ASM(getToken());
	return 0;
}
