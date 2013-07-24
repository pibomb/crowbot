-- call the registered C-function
io.write('[Lua] Calling the C function')
a,b = displayLuaFunction(12, 3.141592, 'hola')

-- print the return values
io.write('[Lua] The C function returned <' .. a .. '> and <' .. b .. '>\n')