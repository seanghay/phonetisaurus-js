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

### Reference

- [Phonetisaurus](https://github.com/AdolfVonKleist/Phonetisaurus)
- [OpenFst](https://www.openfst.org/)
