// @ts-nocheck bun
import { dlopen, FFIType, suffix } from "bun:ffi";

const path = `build/libcore.${suffix}`;

const lib = dlopen(path, {
    createDB: {
        args: [],
        returns: FFIType.ptr
    },
    setNumber: {
        args: [FFIType.ptr, FFIType.cstring, FFIType.i32],
    },
    getNumber: {
        args: [FFIType.ptr, FFIType.cstring],
        returns: FFIType.i32
    }
});

const { symbols } = lib;
const { createDB, setNumber, getNumber } = symbols;

const DB = createDB();

setNumber(DB, Buffer.from("hyro"), 77);
const now = performance.now();
getNumber(DB, Buffer.from("hyro"));

console.log(performance.now() - now + "ms");
