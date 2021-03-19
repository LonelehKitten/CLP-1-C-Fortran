program code
    integer count/0/, unit/1/, i
    character (len=20) lineToSearch, (len=size) line = arg ! Colocar isto aqui como argumentos de entrada

    i = index(line,lineToSearch)        ! Procura se lineToSearch é uma substring de line, se não for, i recebe 0
    if (i.NE.0) then                    ! se i é diferente de 0, ou seja, lineToSearch é uma substring de line
        count = count + 1           
        line = line + i + 1            ! Verificar essa aritmética de ponteiros
        do while (i.NE.0)
            i = index(line,lineToSearch)
            if (i.NE.0) then
                count = count + 1
                line = line + i + 1    ! Verificar essa aritmética de ponteiros
            end if
        end do
    end if

    !return count
end