    program FortranTeste
        implicit none
            character (len = 20) :: str =  "fortran"
            character (len = 256) :: str_2
            
            integer :: error_sts, count
            character(256) :: error_iomsg
            
            open(11, file='Teste.txt', status='old', iostat= error_sts, iomsg= error_iomsg)
            if(error_sts /= 0) then
                write(*,*) 'ERRO', trim(error_iomsg)
                stop
            end if
            read (11, '(A)') str_2
            close(11)
            
            call findsubstring(str, str_2, count);
            print *, count
    end program FortranTeste

    subroutine findsubstring (lineToSearch,line,count)
        character (len=256) line
        character (len=20) lineToSearch   !# line precisa ser ponteiro
        integer count
        integer i, len, deslocator
        len = len_trim(lineToSearch)
        deslocator = 0
        count = 0
    
        i = index(line(deslocator:),lineToSearch(:len))        ! Procura se lineToSearch é uma substring de line, se não for, i recebe 0
        if (i.NE.0) then                              ! se i é diferente de 0, ou seja, lineToSearch é uma substring de line
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
    end
        


    ! Rährk:    Ae ja terminei la no C :3, só falta vcs, de novo....