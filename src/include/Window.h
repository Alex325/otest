#include <glfw/glfw3.h>

class Window
{
    private:
        GLFWwindow *window; 
        
        void draw(int shader, int VAO);
        
    public:
        Window(int width, int height, const char* title);
        ~Window();
        void run();
};
