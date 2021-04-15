module findsubstring_mod
    implicit none
    contains
    subroutine findsubstring_final(lineToSearch, line)
        character (len=256) line
        character (len=20) lineToSearch   !# line precisa ser ponteiro
        integer i, len, deslocator
        integer count
        common /args/ count
        len = len_trim(lineToSearch)
        deslocator = 0
        count = 0


        i = index(line(deslocator:),lineToSearch(:len))        ! Procura se lineToSearch é uma substring de line, se não for, i recebe 0
        if (i.NE.0) then                    ! se i é diferente de 0, ou seja, lineToSearch é uma substring de line
            count = count + 1
            deslocator = deslocator + i + 1
            do while (i.NE.0)
                i = index(line(deslocator:),lineToSearch(:len))
                if (i.NE.0) then
                    count = count + 1
                    deslocator = deslocator + i + 1
                end if
            end do
        end if
        return
    end subroutine
end module