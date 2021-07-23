#include "../../../include/Graphics/Window/Window.h"

void XenoEngine::Graphics::XEWindow::framebuffer_size_callback(GLFWwindow* window, int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
}

void XenoEngine::Graphics::XEWindow::Initialise()
{
  if (!glfwInit())
  {
    std::cout << "Error during glfwInit" << std::endl;
    return;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), NULL, NULL);
  if (!m_window)
  {
    std::cout << "Error during glfwCreateWindow" << std::endl;
    Exit();
    return;
  }

  glfwMakeContextCurrent(m_window);

  glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

#if Win32
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      std::cout << "Failed to initialize GLAD" << std::endl;
      Exit();
      return;
  }
#endif

  glViewport(0, 0, m_windowWidth, m_windowHeight);


  while (!glfwWindowShouldClose(m_window))
  {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(m_window);
    glfwPollEvents();
  }
}

void XenoEngine::Graphics::XEWindow::Exit()
{
  glfwTerminate();
}
