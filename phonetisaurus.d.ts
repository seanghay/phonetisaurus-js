declare class Phonemizer {
  constructor(modelFile: string, delimiter: string);
  phoneticize(
    word: string,
    nbest: number,
    beam: number,
    threshold: number,
    write_fsts: boolean,
    accumulate: boolean,
    pmass: number
  ): string;
}

declare type Root = {
	Phonemizer: typeof Phonemizer;
	FS: FileSystem;
};

declare const Phonetisaurus: Root;
export default Phonetisaurus;