#ifndef SHADER_H
#define SHADER_H

struct Shader
{

    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    void use() const;
    void setBool(const char *name, bool value) const;
    void setInt(const char *name, int value) const;
    void setFloat(const char *name, float value) const;
    void setVec4(const char *name, float v1, float v2, float v3, float v4) const;
};

#endif