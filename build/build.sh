#!/usr/bin/env bash

set -o pipefail

em++ openfst/src/script/*.cc \
  openfst/src/lib/*.cc binding.cc \
	Phonetisaurus/src/lib/util.cc \
 	-I openfst/src/include \
	-I Phonetisaurus/src \
	-I Phonetisaurus/src/3rdparty/utfcpp \
 --bind -O3 --memory-init-file 0 -g0 \
  -s WASM=1 \
  -s WASM_ASYNC_COMPILATION=1 \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s DISABLE_EXCEPTION_CATCHING=1 \
  -s AGGRESSIVE_VARIABLE_ELIMINATION=1 \
  -s NO_EXIT_RUNTIME=1 \
  -s ASSERTIONS=0 \
  -s ERROR_ON_UNDEFINED_SYMBOLS=1 \
  -s NODEJS_CATCH_EXIT=0 \
	-s DYNAMIC_EXECUTION=0 \
	-s TEXTDECODER=0 \
	-s ENVIRONMENT='web' \
	-s FETCH_SUPPORT_INDEXEDDB=0 \
  -s EXPORT_ES6=1 \
	-s USE_ES6_IMPORT_META=0 \
  -s EXPORTED_RUNTIME_METHODS=['FS'] \
	-s EXPORT_NAME="phonetisaurus" \
  -s MODULARIZE=1 \
	-s INCOMING_MODULE_JS_API=['instantiateWasm'] \
  -w \
  -o phonetisaurus.mjs