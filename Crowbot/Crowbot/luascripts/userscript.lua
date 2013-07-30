function userscript()
    for i=0, 11, 1 do
        if i > 6 then
            the_robot:shoot((11-i)*30, 75)
        else
            the_robot:shoot(i*30, 75)
        end
    end
end
