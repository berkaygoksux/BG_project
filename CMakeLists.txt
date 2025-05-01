cmake_minimum_required(VERSION 3.20)
project(1306220126_with_draw)

set(CMAKE_CXX_STANDARD 11)

# OpenGL paketini bul
find_package(OpenGL REQUIRED)

# GLAD kütüphanesini ekle
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC ${PROJECT_SOURCE_DIR}/include)

# GLFW - Homebrew yolu (Mac için önemli)
include_directories(/usr/local/opt/glfw/include)
link_directories(/usr/local/opt/glfw/lib)

# Çalıştırılabilir dosya ve kaynaklar
add_executable(1306220126 
    main.cpp 
    draw_functions.cpp 
    loadShader.cpp
)

# include yolu
target_include_directories(1306220126 PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Kütüphaneleri bağla
target_link_libraries(1306220126 
    glad 
    glfw 
    OpenGL::GL
)
