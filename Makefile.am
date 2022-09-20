bin_PROGRAMS = main.js
main_js_SOURCES = main.c
main_js_LDFLAGS = -s EXPORTED_RUNTIME_METHODS=[cwrap] \
		   -s EXPORTED_FUNCTIONS=[_main,_getproducts] \
		   -s FETCH
