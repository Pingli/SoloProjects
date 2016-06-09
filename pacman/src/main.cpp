#include <GLFW/glfw3.h>
#include <cstdio>

void Update(GLFWwindow* window)
{
	int state = glfwGetKey(window, GLFW_KEY_E);
	if (state == GLFW_PRESS)
	{
		printf("pressed E\n");
	}
}

void RenderStuff(GLFWwindow* window)
{
	glClearColor(1, 0, 0, 1);
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	//glfwSwapInterval();

	printf(glfwGetVersionString());


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		RenderStuff(window);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		Update(window);
	}

	glfwTerminate();
	return 0;
}