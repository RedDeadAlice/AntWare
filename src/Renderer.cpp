#include <Renderer.h>
using namespace aw;
Renderer::Renderer() {}
Renderer &Renderer::instance()
{
    static Renderer renderer;
    return renderer;
}
void Renderer::init()
{
    glewExperimental = true;
    glewInit();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    gluPerspective(45.0f, WINDOW.internal.getSize().x / WINDOW.internal.getSize().y, 0.1f, 100.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Renderer::terminate()
{
}