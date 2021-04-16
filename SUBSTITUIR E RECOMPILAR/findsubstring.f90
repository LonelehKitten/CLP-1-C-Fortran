subroutine findsubstring (lineToSearch, line, lineToSearch_length, line_length)
    character line
    character lineToSearch
    integer lineToSearch_length, line_length
    integer i, deslocator
    integer count
    common/args/ count
    deslocator = 1

    i = index(line(deslocator:line_length),lineToSearch(:lineToSearch_length))        ! Procura se lineToSearch é uma substring de line, se não for, i recebe 0
    if (i.NE.0) then                    ! se i é diferente de 0, ou seja, lineToSearch é uma substring de line
        count = count + 1
        deslocator = deslocator + i
        do while (i.NE.0)
            i = index(line(deslocator:line_length),lineToSearch(:lineToSearch_length))
            if (i.NE.0) then
                count = count + 1
                deslocator = deslocator + i
            end if
        end do
    end if
    return
end
