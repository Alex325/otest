#ifndef WINDOW_H
#define WINDOW_H

#include <glfw/glfw3.h>
#include <shader/Shader.h>

class Window
{
    private:
        GLFWwindow *window; 
        
        void draw(const Shader& shader, uint32_t VAO) const;
        
    public:
        Window(int width, int height, const char* title);
        ~Window();
        void run() const;
};

#endif