#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

using namespace std;

int main() {

	int windowWidth = 1280, windowHeight = 720;
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL are being used
	// In this case, OpenGL 3.3 is being used so the value is gonna be 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW that CORE profile is being used
	// This also means that only modern functions will be use
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of windowWidth by windowHeight pixels, naming it "OpenGL"
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0 (0;0) to x = windowWidth, y = windowHeight (windowWidth; windowHeight)
	glViewport(0, 0, windowWidth, windowHeight);

	// Put in loop so that it will keep going without stop unless the window receive the command to close
	while (!glfwWindowShouldClose(window)) {
		// Specify the background color
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Swap place of the back and front buffer
		glfwSwapBuffers(window);

		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}