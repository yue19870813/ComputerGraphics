//
//  b002_BaseLightExercises.cpp
//  GL
//
//  Created by yuebinbin on 2020/6/3.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#include "b002_BaseLightExercises.hpp"
#include "common.hpp"
#include "camera.h"

const char *color_vs_b002_exercises1 = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aNormal;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"out vec3 Normal;\n"
"out vec3 FragPos;\n"
"void main()\n"
"{\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"    FragPos = vec3(model * vec4(aPos, 1.0));\n"
"    Normal = aNormal;\n"
"}\n";

const char *color_fs_b002_exercises1 = "#version 330 core\n"
"in vec3 Normal;\n"
"in vec3 FragPos;\n"
"out vec4 FragColor;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 objectColor;\n"
"uniform vec3 lightColor;\n"
"uniform vec3 viewPos;\n"
"void main()\n"
"{\n"
"    float specularStrength = 0.5;\n"
"    float ambientStrength = 0.1;\n"
"    vec3 ambient = ambientStrength * lightColor;\n"
"    vec3 norm = normalize(Normal);\n"
"    vec3 viewDir = normalize(viewPos - FragPos);\n"
"    vec3 lightDir = normalize(lightPos - FragPos);\n"
"    vec3 reflectDir = reflect(-lightDir, norm);\n"
"    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);"
"    vec3 specular = specularStrength * spec * lightColor;"
"    float diff = max(dot(norm, lightDir), 0.0);\n"
"    vec3 diffuse = diff * lightColor;\n"
"    vec3 result = (ambient + diffuse + specular) * objectColor;\n"
"    FragColor = vec4(result, 1.0);\n"
"}\n";

const char *lamp_vs_b002_exercises = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

const char *lamp_fs_b002_exercises = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0);\n"
"}\n";

void framebuffer_size_callback_b002_exercises(GLFWwindow* window, int width, int height);
void mouse_callback_b002_exercises(GLFWwindow* window, double xpos, double ypos);
void scroll_callback_b002_exercises(GLFWwindow* window, double xoffset, double yoffset);
void processInput_b002_exercises(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH_b002_exercises = 800;
const unsigned int SCR_HEIGHT_b002_exercises = 600;

// camera
Camera camera_b002_exercises(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX_b002_exercises = SCR_WIDTH_b002_exercises / 2.0f;
float lastY_b002_exercises = SCR_HEIGHT_b002_exercises / 2.0f;
bool firstMouse_b002_exercises = true;

// timing
float deltaTime_b002_exercises = 0.0f;
float lastFrame_b002_exercises = 0.0f;

// lighting
glm::vec3 lightPos_b002_exercises(1.2f, 1.0f, 2.0f);

void processInput_b002_exercises(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera_b002_exercises.ProcessKeyboard(FORWARD, deltaTime_b002_exercises);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera_b002_exercises.ProcessKeyboard(BACKWARD, deltaTime_b002_exercises);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera_b002_exercises.ProcessKeyboard(LEFT, deltaTime_b002_exercises);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera_b002_exercises.ProcessKeyboard(RIGHT, deltaTime_b002_exercises);
}

void framebuffer_size_callback_b002_exercises(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback_b002_exercises(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse_b002_exercises)
    {
        lastX_b002_exercises = xpos;
        lastY_b002_exercises = ypos;
        firstMouse_b002_exercises = false;
    }

    float xoffset = xpos - lastX_b002_exercises;
    float yoffset = lastY_b002_exercises - ypos; // reversed since y-coordinates go from bottom to top

    lastX_b002_exercises = xpos;
    lastY_b002_exercises = ypos;

    camera_b002_exercises.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback_b002_exercises(GLFWwindow* window, double xoffset, double yoffset) {
    camera_b002_exercises.ProcessMouseScroll(yoffset);
}

// 1. 目前，我们的光源时静止的，你可以尝试使用sin或cos函数让光源在场景中来回移动。观察光照随时间的改变能让你更容易理解冯氏光照模型。
int b002_moveLight() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH_b002_exercises, SCR_HEIGHT_b002_exercises, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback_b002_exercises);
    glfwSetCursorPosCallback(window, mouse_callback_b002_exercises);
    glfwSetScrollCallback(window, scroll_callback_b002_exercises);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    
    Shader lightingShader(color_vs_b002_exercises1, color_fs_b002_exercises1);
    Shader lampShader(lamp_vs_b002_exercises, lamp_fs_b002_exercises);
    
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    // first, configure the cube's VAO (and VBO)
    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightVAO;
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime_b002_exercises = currentFrame - lastFrame_b002_exercises;
        lastFrame_b002_exercises = currentFrame;

        processInput_b002_exercises(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // be sure to activate shader when setting uniforms/drawing objects
        lightingShader.use();
        lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        lightingShader.setVec3("lightColor",  1.0f, 1.0f, 1.0f);
        lightingShader.setVec3("lightPos", sin(glfwGetTime()) * lightPos_b002_exercises.r, lightPos_b002_exercises.g, cos(glfwGetTime()) * lightPos_b002_exercises.b);
        lightingShader.setVec3("viewPos", camera_b002_exercises.Position.r, camera_b002_exercises.Position.g, camera_b002_exercises.Position.b);

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera_b002_exercises.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera_b002_exercises.GetViewMatrix();
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);

        // world transformation
        glm::mat4 model = glm::mat4(1.0f);
        lightingShader.setMat4("model", model);

        // render the cube
        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // also draw the lamp object
        lampShader.use();
        lampShader.setMat4("projection", projection);
        lampShader.setMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(sin(glfwGetTime()) * lightPos_b002_exercises.r, lightPos_b002_exercises.g, cos(glfwGetTime()) * lightPos_b002_exercises.b));
        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
        lampShader.setMat4("model", model);

        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightVAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return EXIT_SUCCESS;
}

// 2. 在观察空间（而不是世界空间）中计算冯氏光照.
int b002_lightInViewport() {
    
    return EXIT_SUCCESS;
}

// 3. 尝试实现一个Gouraud着色（而不是冯氏着色）。如果你做对了话，立方体的光照应该会看起来有些奇怪，尝试推理为什么它会看起来这么奇怪.
const char *color_vs_b002_exercises3 = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aNormal;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 lightColor;\n"
"uniform vec3 viewPos;\n"
"out vec3 LightingColor;\n"
"void main()\n"
"{\n"
"    vec3 Position = vec3(model * vec4(aPos, 1.0));\n"
"    vec3 Normal = mat3(transpose(inverse(model))) * aNormal;\n"
    // ambient
"    float ambientStrength = 0.1;\n"
"    vec3 ambient = ambientStrength * lightColor;\n"
    // diffuse
"    vec3 norm = normalize(Normal);\n"
"    vec3 lightDir = normalize(lightPos - Position);\n"
"    float diff = max(dot(norm, lightDir), 0.0);\n"
"    vec3 diffuse = diff * lightColor;\n"
    // specular
"    float specularStrength = 1.0; // this is set higher to better show the effect of Gouraud shading\n"
"    vec3 viewDir = normalize(viewPos - Position);\n"
"    vec3 reflectDir = reflect(-lightDir, norm);\n"
"    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);\n"
"    vec3 specular = specularStrength * spec * lightColor;\n"
"    LightingColor = ambient + diffuse + specular;\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

const char *color_fs_b002_exercises3 = "#version 330 core\n"
"uniform vec3 objectColor;\n"
"out vec4 FragColor;\n"
"in vec3 LightingColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(LightingColor * objectColor, 1.0);\n"
"}\n";

int b002_ligthByGourand() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH_b002_exercises, SCR_HEIGHT_b002_exercises, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback_b002_exercises);
    glfwSetCursorPosCallback(window, mouse_callback_b002_exercises);
    glfwSetScrollCallback(window, scroll_callback_b002_exercises);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    
    Shader lightingShader(color_vs_b002_exercises3, color_fs_b002_exercises3);
    Shader lampShader(lamp_vs_b002_exercises, lamp_fs_b002_exercises);
    
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    // first, configure the cube's VAO (and VBO)
    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightVAO;
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime_b002_exercises = currentFrame - lastFrame_b002_exercises;
        lastFrame_b002_exercises = currentFrame;

        processInput_b002_exercises(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // be sure to activate shader when setting uniforms/drawing objects
        lightingShader.use();
        lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        lightingShader.setVec3("lightColor",  1.0f, 1.0f, 1.0f);
        lightingShader.setVec3("lightPos", lightPos_b002_exercises.r, lightPos_b002_exercises.g, lightPos_b002_exercises.b);
        lightingShader.setVec3("viewPos", camera_b002_exercises.Position.r, camera_b002_exercises.Position.g, camera_b002_exercises.Position.b);

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera_b002_exercises.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera_b002_exercises.GetViewMatrix();
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);

        // world transformation
        glm::mat4 model = glm::mat4(1.0f);
        lightingShader.setMat4("model", model);

        // render the cube
        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // also draw the lamp object
        lampShader.use();
        lampShader.setMat4("projection", projection);
        lampShader.setMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos_b002_exercises);
        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
        lampShader.setMat4("model", model);

        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightVAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return EXIT_SUCCESS;
}
