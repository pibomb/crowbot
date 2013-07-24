-- call the registered C-function
io.write("[Lua] Calling the C function\n")
sum=addition(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
-- print the return values
io.write("[Lua] The C function returned <"..sum..">\n")