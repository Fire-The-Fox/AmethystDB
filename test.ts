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
    },
    setDB: {
        args: [FFIType.ptr, FFIType.cstring, FFIType.ptr],
    },
    getDB: {
        args: [FFIType.ptr, FFIType.cstring],
        returns: FFIType.ptr
    }
});

const { createDB, setNumber, getNumber, setDB, getDB } = lib.symbols;

const DB = createDB();
const json = createDB();

setDB(DB, Buffer.from("json is nice~"), json);
setNumber(json, Buffer.from("kek"), 77);

const out = getDB(DB, Buffer.from("json is nice~"));

if (out) {
    console.log(getNumber(out, Buffer.from("kek")));
}
