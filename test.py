import datetime
from ctypes import cdll, c_char_p, c_int, POINTER, c_void_p

lib = cdll.LoadLibrary("./build/libcore.so")
lib.createDB.restype = POINTER(c_void_p)
lib.setNumber.argtypes = [POINTER(c_void_p), c_char_p, c_int]
lib.getNumber.argtypes = [POINTER(c_void_p), c_char_p]
lib.getNumber.restype = c_int

tree = lib.createDB()
lib.setNumber(tree, b"hyro", 77)

a = datetime.datetime.now()
lib.getNumber(tree, b"hyro")
b = datetime.datetime.now()

print((b - a).microseconds)
