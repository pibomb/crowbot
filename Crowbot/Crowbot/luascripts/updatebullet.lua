function updatebullet(x, y)
    if y > -0.2 and x <= 11 then
        if x < 0.2 then
            activeBullet:move(0.01, 0.01)
        else
            activeBullet:move(0.01, 0)
        end
    elseif x > 11 and y >= -8.2 then
        if y > -0.2 then
            activeBullet:move(0.01, -0.01)
        else
            activeBullet:move(0, -0.01)
        end
    elseif y < -8.2 and x >= 0.2 then
        if x > 11 then
            activeBullet:move(-0.01, -0.01)
        else
            activeBullet:move(-0.01, 0)
        end
    elseif x < 0.2 and y <= -0.2 then
        if y < -8.2 then
            activeBullet:move(-0.01, 0.01)
        else
            activeBullet:move(0, 0.01)
        end
    end
end
