import { readFile } from "node:fs/promises";
import { createRequire } from "node:module";
import { initialize } from "./loader.js";

const Phonetisaurus = await initialize(
  await readFile(createRequire(import.meta.url).resolve("./phonetisaurus.wasm"))
);

export default Phonetisaurus;