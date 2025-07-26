#include <Window.h>
#include <glad/gl.h>
#include <glfw/glfw3.h>
#include <stdio.h>

extern unsigned int VAO;
extern unsigned int shader;

void onFramebufferSizeChange(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

void onKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

Window::Window(int width, int height, const char* title) {

    if(!glfwInit())
    {
        fprintf(stderr, "Failed init\n");
    }
    
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    this->window = glfwCreateWindow(width, height, title, NULL, NULL);
    
    
    if (!window)
    {
        printf("Failed create window\n");        
        
    }
    
    fprintf(stderr, "Failed create window\n");
    
    glfwSetKeyCallback(window, onKeyPressed);
    glfwSetFramebufferSizeCallback(window, onFramebufferSizeChange);
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);
    
    

}

void Window::run() {
     while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        draw(shader, VAO);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::draw(int shader, int VAO) {
    glUseProgram(shader);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}