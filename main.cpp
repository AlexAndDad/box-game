#include <cstdlib>
#include<GL/glew.h>
#include <glm/glm.hpp>
#if __has_include(<OpenGL/gl.h>)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <GLFW/glfw3.h>
#include <iostream>


int SCR_WIDTH = 200;
int SCR_HEIGHT = 200;


void getInput(GLFWwindow* window,int key, int scancode , int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}


int main()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

    auto window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOPenGlMofo", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window";
        glfwTerminate();
    }
    else {
        glfwMakeContextCurrent(window);
    }

    glewInit();

    glfwSetKeyCallback(window, getInput);





    while (!glfwWindowShouldClose(window))
    {


        glfwSwapBuffers(window);
        glfwPollEvents();

    }








}