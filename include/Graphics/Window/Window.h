#include <GLFW/glfw3.h>
#if WIN32
#include <glad/glad.h>
#else
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#endif

#include <iostream>
#include <string>

namespace XenoEngine::Graphics
{
  class XEWindow
  {
  public:
    XEWindow(std::string windowTitle, uint32_t width, uint32_t height)
    :
    m_windowTitle(windowTitle),
    m_windowWidth(width),
    m_windowHeight(height)
    {

    }

    void Initialise();
    void Exit();
    static void framebuffer_size_callback(GLFWwindow* window, int newWidth, int newHeight);
  private:
    GLFWwindow* m_window;


    std::string m_windowTitle;
    uint32_t m_windowWidth;
    uint32_t m_windowHeight;
    };
}
