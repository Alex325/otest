#include <shader/Shader.h>

#include <glad/gl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    const char *vertexCode;
    const char *fragCode;

    std::stringstream vStream;
    std::stringstream fStream;

    {
        std::ifstream vertexFile;
        std::ifstream fragFile;
        
        vertexFile.open(vertexPath);
        fragFile.open(fragmentPath);
        
        if ((vertexFile.bad() || vertexFile.fail()) || (fragFile.bad() || fragFile.fail()))
        {
            printf("Erro ao abrir os arquivos de shader.\n");
        }

        vStream << vertexFile.rdbuf();
        fStream << fragFile.rdbuf();
        
        vertexFile.close();
        fragFile.close();

    }

    vertexCode = vStream.str().c_str();
    fragCode = fStream.str().c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        fprintf(stderr, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    };

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragCode, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        fprintf(stderr, "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    };

    ID = glCreateProgram();

    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);

    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);

    if(!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        fprintf(stderr, "ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

Shader::~Shader() {
    glDeleteProgram(ID);
}

void Shader::use() const {
    glUseProgram(ID);
}

void Shader::setBool(const char *name, bool value) const
{         
    glUniform1i(glGetUniformLocation(ID, name), (int)value); 
}

void Shader::setInt(const char *name, int value) const
{ 
    glUniform1i(glGetUniformLocation(ID, name), value); 
}

void Shader::setFloat(const char *name, float value) const
{ 
    glUniform1f(glGetUniformLocation(ID, name), value); 
}

void Shader::setVec4(const char *name, float v1, float v2, float v3, float v4) const
{ 
    glUniform4f(glGetUniformLocation(ID, name), v1, v2, v3, v4);
}