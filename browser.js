import { initialize } from "./loader.js";

const Phonetisaurus = await initialize(
	await fetch(new URL("./phonetisaurus.wasm", import.meta.url)).then((res) =>
		res.arrayBuffer()
	)
);

export default Phonetisaurus;