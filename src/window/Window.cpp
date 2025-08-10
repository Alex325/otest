#include <window/Window.h>
#include <glad/gl.h>
#include <glfw/glfw3.h>
#include <stdio.h>
#include <cmath>
#include <shader/Shader.h>

extern uint32_t VAO;
extern Shader shader;

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
        printf("Failed init\n");
    }
    
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    this->window = glfwCreateWindow(width, height, title, NULL, NULL);
    
    if (!window)
    {
        printf("Failed create window\n");        
    }
    
    
    glfwSetKeyCallback(window, onKeyPressed);
    glfwSetFramebufferSizeCallback(window, onFramebufferSizeChange);
    glfwMakeContextCurrent(window);

    gladLoadGL(glfwGetProcAddress);

    glfwSwapInterval(1);
    
    

}

void Window::run() const {

    Shader shader{"shaders/v1.vert", "shaders/f1.frag"};

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        draw(shader, VAO);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::draw(const Shader& shader, uint32_t VAO) const {
    float timeValue = glfwGetTime();

    float redValue = (sin(timeValue - M_PI/2) / 2.0f) + 0.5f;
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    float blueValue = (sin(timeValue + M_PI/2) / 2.0f) + 0.5f;

    shader.use();
    shader.setVec4("myColor", redValue, greenValue, blueValue, 1.0f);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}