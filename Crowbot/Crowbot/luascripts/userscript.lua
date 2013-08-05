__totalcount=0
function userscript()
    __totalcount=__totalcount+1
    if __totalcount>=240 then
        __game:spawn_batbot(0, 62.5, -6.25, 10)
        __game:spawn_batbot(0, 125, -6.25, 10)
        __game:spawn_batbot(0, 187.5, -6.25, 10)
        __totalcount=0
    end
end
