cmake_minimum_required(VERSION 3.9)
project(srcs)

set(CMAKE_CXX_STANDARD 11)

add_executable(srcs
        drw_line.c
        ft_countchr.c
        ft_strjoin_free.c
        get_pixel_arr.c
        get_point_arr.c
        main.c
        main2.c
        print_fdf.c
        pxl_new.c)
