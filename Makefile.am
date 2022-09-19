bin_PROGRAMS = index.js
index_js_SOURCES = pages/index.c
index_js_LDFLAGS = -s EXPORTED_RUNTIME_METHODS=[cwrap] \
		   -s EXPORTED_FUNCTIONS=[_main,_index_getproducts] \
		   -s FETCH
