import phonetisaurus from './phonetisaurus.mjs';

export async function initialize(wasm) {
	return phonetisaurus({
		instantiateWasm(info, receive) {
			WebAssembly.instantiate(wasm, info).then((instance) => {
				if (instance instanceof WebAssembly.Instance) {
					receive(instance);
				} else {
					receive(instance.instance);
				}
			});
		}
	})
}