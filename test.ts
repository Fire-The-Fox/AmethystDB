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

const { createDB, setNumber, getNumber } = lib.symbols;

const DB = createDB();

setNumber(DB, Buffer.from("test"), 77);
console.log(getNumber(DB, Buffer.from("test")));
