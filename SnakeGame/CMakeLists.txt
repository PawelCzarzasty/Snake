cmake_minimum_required(VERSION 3.26)
project(SNAKE)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

# Windows specific config
# To możecie zmienić jeśli zainstalujecie SFML-a w innym miejscu
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/lib/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)
add_executable(SNAKE main.cpp
        SNAKEBoard.cppCMake: Delete Cache and Reconfigure
        SNAKEBoard.h
        SNAKEView.cpp
        SNAKEView.h
        SNAKEController.cpp
        SNAKEController.h
)


target_link_libraries(SNAKE sfml-system sfml-audio sfml-window sfml-graphics)