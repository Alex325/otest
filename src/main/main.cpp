#include <stdio.h>
#include <math.h>
#include <glad/gl.h>
#include <window/Window.h>




const float_t vertices[] = {
    -.5f, -.5f, .0f,
    .5f, -.5f, .0f,
    -.5f,  .5f, .0f,
    .5f,  .5f, .0f
};

const uint32_t indices[] = {
    0, 1, 2,
    1, 3, 2
};

const float_t texCoords[] = {
    0.0f, 0.0f,
    1.f, 0.0f,
    1.f, 1.0f,
    0.0f, 1.0f
};

uint32_t VAO;

int main() {

    Window window(800, 800, "Teste");
    
    uint32_t VBO;
    uint32_t EBO;
    
    glGenVertexArrays(1, &VAO); 
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    window.run();
    
    
    
}