#include "BaseApplication.h"

extern BaseApplication *app;

int main( int argc, char** argv )
{
    glfwInit();
    
    app->preSetup();
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow( 1280,720, "OpenGL Tutorial", nullptr, nullptr);
    
    glfwMakeContextCurrent(window);
    gl3wInit();
    
    app->setup(window);
    
    while (!glfwWindowShouldClose(window)) {
        app->draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    
    glfwTerminate();
}
