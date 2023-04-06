/**
 * @file main.cpp
 * @author Piotr UjemnyGH Plombon
 * @brief App about Starogard Gdanski
 * @version 0.1
 * @date 2023-04-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

/**
 * @brief Function called on window resize
 * 
 * @param wnd 
 * @param w 
 * @param h 
 */
void framebuffer(GLFWwindow* wnd, int w, int h) {
    glViewport(0, 0, w, h);
}

/**
 * @brief Main function, for everything in it go lern glfw, opengl, imgui
 * 
 * @return int 
 */
int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(300, 160, "App", nullptr, nullptr);

    if(!window) {
        exit(1);
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        exit(2);
    }

    glfwSetFramebufferSizeCallback(window, framebuffer);
    framebuffer(window, 300, 160);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsClassic(NULL);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 450 core");

    while(!glfwWindowShouldClose(window)) {
        glClear(0x4000 | 0x100);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        const ImGuiViewport* viewport = ImGui::GetMainViewport();

        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
        ImGui::SetNextWindowSize(viewport->WorkSize, ImGuiCond_Always);

        if(ImGui::Begin("Info", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings)) {
            ImGui::Text("Starogard Gdanski: \nLiczba ludnosci (30.06.2021) - 47,272\nWspolrzedne geograficzne: \n- 53o57'47''N\n- 18o31'33''E\nPowierzchnia - 25,28km2\n");

            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}