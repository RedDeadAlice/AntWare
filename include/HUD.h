#pragma once
#include<GLES2/gl2.h>
#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#define HUD aw::Hud::instance()
namespace aw
{
    enum Status
    {
        WIN,
        LOSE,
        ONGOING,
        LOADING
    };
    class Hud
    {
    private:
        enum
        {
            MODEL_MAT,
            COLOR_VEC,
            NumUniforms
        };
        Hud();
        GLuint shaderProgram;
        GLuint uniformsLocations[NumUniforms];
        GLuint quadVBO,quadEBO;
        GLuint crosshair;
        GLuint digits[10];
        GLuint backSlash, plus, ammo;
        GLuint hurt;
        GLuint lose, win, loading;
        GLuint positionModelAttribLocation;
        void drawHP();
        void drawAmmo();
        void drawHurtEffect();
        int hp;
        int inHandAmmo, totalAmmo;
        bool isHurting = false;
        Status status;

        void createQuadBuffers();

    public:
        static Hud &instance();
        void setShaderProgram(GLuint program);
        GLuint getShaderProgram();
        static void loadTexture(const char *path, GLuint &tex);
        void drawQuad(GLuint texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = {1, 1, 1});
        void draw();
        void setHP(unsigned hp);
        void setInHandAmmo(unsigned ammo);
        void setTotalAmmo(unsigned ammo);
        void setStatus(Status);
        void setIsHurting(bool isHurting);
    };
}