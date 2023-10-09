## Phonetisaurus.js

Grapheme to Phoneme on the Web powered by WebAssembly.

```js
import phonetisaurus from 'phonetisaurus'

// download the remote model file
const res = await fetch("https://example.com/model.fst")
const buffer = await res.arrayBuffer();

// write to a virtual file system
phonetisaurus.FS.writeFile("/model.fst", buffer)

// create phonemizer instance
const phonemizer = new phonetisaurus.Phonemizer("/model.fst", "")
const result = phonemizer.phoneticize("hello", 10, 500, 10, false, false, 0.0)

// => [[ 'h', 'ɛɛ', 'l', 'oo' ]]
```

### Examples

- [phonetisaurus-js-khmer](https://github.com/seanghay/phonetisaurus-js-khmer)

---

### Building

We are using Emscripten to compile to WebAssembly. Here is the version info:

```
emcc (Emscripten gcc/clang-like replacement + linker emulating GNU ld) 3.1.33 (c1927f22708aa9a26a5956bab61de083e8d3e463)
Copyright (C) 2014 the Emscripten authors (see AUTHORS.txt)
This is free and open source software under the MIT license.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

To compile the project, run

```shell
cd build/

./build.sh
```

This will output two files such as 
- `phonetisaurus.mjs` 
- `phonetisaurus.wasm`

## Reference

- [Phonetisaurus](https://github.com/AdolfVonKleist/Phonetisaurus)
- [OpenFst](https://www.openfst.org/)
