function onSay(player, words, param)
    for _, summon in ipairs(player:getSummons()) do
        local move = summon:getMove(8)
        if move then
            summon:castMove(move:getId())
        end
        return false
    end
end