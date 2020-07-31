#include "Application.h"

UIParameters Application::uiParams = { Vec3{1.0,1.0,1.0}, Vec3{1.0,1.0,1.0} ,
0.7,
390.0,
790.0,
400.0,
5.0,
75.0,

Vec3{1.0,1.0,1.0},
0.7,
390.0,
790.0,
400.0,
5.0,
75.0,

true,
90.0,
90.0,
1.56,
1.0,
4.75,//2.5,
5,
0,
90.0,
90.0,
1.56,
1.0,
4.75,//2.5,
5,
0,
3.5,//2.0,
false,
false,
28.0,
0.3,
1.5,
1.0,
true,
true,
true,
true,
true,
false,
0.0,
0.0
};

void DrawUI()
{

	float lightColor[3] = { Application::uiParams.inputLightColor.x, Application::uiParams.inputLightColor.y, Application::uiParams.inputLightColor.z };
	if (ImGui::CollapsingHeader("Spectral Config"))
	{
		ImGui::SliderFloat("Minimum Wavelength", &Application::uiParams.minWavelength, 390.0, 790.0);
		ImGui::SliderFloat("Maximum Wavelength", &Application::uiParams.maxWavelength, Application::uiParams.minWavelength, 790.0);
		ImGui::SliderInt("No of Spectral Values", &Application::uiParams.noOfSpectralValues, 50, 400);
		ImGui::SliderFloat("Hybrid Threshold", &Application::uiParams.hybridThreshold, 0.0, 1.0);
		ImGui::SliderFloat("Minimum Gaussian Width", &Application::uiParams.gaussianMinWidth, 1.0, Application::uiParams.maxWavelength - Application::uiParams.minWavelength);
		ImGui::SliderFloat("Maximum Gaussian Width", &Application::uiParams.gaussianMaxWidth, Application::uiParams.gaussianMinWidth, Application::uiParams.maxWavelength - Application::uiParams.minWavelength);
		ImGui::ColorEdit3("Light Color", lightColor);
		Application::uiParams.inputLightColor.x = lightColor[0];
		Application::uiParams.inputLightColor.y = lightColor[1];
		Application::uiParams.inputLightColor.z = lightColor[2];
		if (Application::uiParams.previnputLightColor.x != Application::uiParams.inputLightColor.x
			|| Application::uiParams.previnputLightColor.y != Application::uiParams.inputLightColor.y
			|| Application::uiParams.previnputLightColor.z != Application::uiParams.inputLightColor.z
			|| Application::uiParams.prevhybridThreshold != Application::uiParams.hybridThreshold
			|| Application::uiParams.prevminWavelength != Application::uiParams.minWavelength
			|| Application::uiParams.prevmaxWavelength != Application::uiParams.maxWavelength
			|| Application::uiParams.prevnoOfSpectralValues != Application::uiParams.noOfSpectralValues
			|| Application::uiParams.prevgaussianMaxWidth != Application::uiParams.gaussianMaxWidth
			|| Application::uiParams.prevgaussianMinWidth != Application::uiParams.gaussianMinWidth)
		{
			Application::uiParams.shouldRegenerateTexture = true;
			
			Application::uiParams.previnputLightColor = Application::uiParams.inputLightColor;
			Application::uiParams.prevhybridThreshold = Application::uiParams.hybridThreshold;
			Application::uiParams.prevminWavelength = Application::uiParams.minWavelength;
			Application::uiParams.prevmaxWavelength = Application::uiParams.maxWavelength;
			Application::uiParams.prevnoOfSpectralValues = Application::uiParams.noOfSpectralValues;
			Application::uiParams.prevgaussianMaxWidth = Application::uiParams.gaussianMaxWidth;
			Application::uiParams.prevgaussianMinWidth = Application::uiParams.gaussianMinWidth;
		}
	}
	if (ImGui::CollapsingHeader("Iridescent Config"))
	{
		float filmDensity = Application::uiParams.filmDensity;
		float airDensity = Application::uiParams.airDensity;
		float filmIOR = Application::uiParams.filmIOR;
		float airIOR = Application::uiParams.airIOR;
		float interferencePower = Application::uiParams.interferencePower;
		float interferenceConstant = Application::uiParams.interferenceConstant;
		float prevFilmDensity = Application::uiParams.filmDensity;

		ImGui::SliderFloat("Film Density", &Application::uiParams.filmDensity, 50.0, 500.0);
		ImGui::SliderFloat("Air Density", &Application::uiParams.airDensity, 50.0, 500.0);
		ImGui::SliderFloat("Film Index of Refraction", &Application::uiParams.filmIOR, 1.0, 3.0);
		ImGui::SliderFloat("Air Index of Refraction", &Application::uiParams.airIOR, 1.0, 3.0);
		ImGui::SliderFloat("Interference Power", &Application::uiParams.interferencePower, 1.0, 100.0);
		ImGui::SliderFloat("Interference Constant", &Application::uiParams.interferenceConstant, 1.0, 20.0);

		if (Application::uiParams.prevfilmDensity != Application::uiParams.filmDensity
			|| Application::uiParams.prevairDensity != Application::uiParams.airDensity
			|| Application::uiParams.prevfilmIOR != Application::uiParams.filmIOR
			|| Application::uiParams.prevairIOR != Application::uiParams.airIOR
			|| Application::uiParams.previnterferencePower != Application::uiParams.interferencePower
			|| Application::uiParams.previnterferenceConstant != Application::uiParams.interferenceConstant
			
			|| Application::uiParams.previnputLightColor.x != Application::uiParams.inputLightColor.x
			|| Application::uiParams.previnputLightColor.y != Application::uiParams.inputLightColor.y
			|| Application::uiParams.previnputLightColor.z != Application::uiParams.inputLightColor.z
			|| Application::uiParams.prevminWavelength != Application::uiParams.minWavelength
			|| Application::uiParams.prevmaxWavelength != Application::uiParams.maxWavelength
			|| Application::uiParams.prevnoOfSpectralValues != Application::uiParams.noOfSpectralValues
			|| Application::uiParams.prevgaussianMaxWidth != Application::uiParams.gaussianMaxWidth
			|| Application::uiParams.prevgaussianMinWidth != Application::uiParams.gaussianMinWidth)
		{
			Application::uiParams.shouldRegenerateTexture = true;
			Application::uiParams.prevfilmDensity = Application::uiParams.filmDensity;
			Application::uiParams.prevairDensity = Application::uiParams.airDensity;
			Application::uiParams.prevfilmIOR = Application::uiParams.filmIOR;
			Application::uiParams.prevairIOR = Application::uiParams.airIOR;
			Application::uiParams.previnterferencePower = Application::uiParams.interferencePower;
			Application::uiParams.previnterferenceConstant = Application::uiParams.interferenceConstant;

			Application::uiParams.previnputLightColor = Application::uiParams.inputLightColor;
			Application::uiParams.prevminWavelength = Application::uiParams.minWavelength;
			Application::uiParams.prevmaxWavelength = Application::uiParams.maxWavelength;
			Application::uiParams.prevnoOfSpectralValues = Application::uiParams.noOfSpectralValues;
			Application::uiParams.prevgaussianMaxWidth = Application::uiParams.gaussianMaxWidth;
			Application::uiParams.prevgaussianMinWidth = Application::uiParams.gaussianMinWidth;
		}
	}
	if (ImGui::CollapsingHeader("Light Properties"))
	{

		if (Application::uiParams.isMTLFileAvailable)
		{
			ImGui::Checkbox("Use light properties from MTL File", &Application::uiParams.useMTLFile);
		}
		if (!Application::uiParams.useMTLFile)
		{
			ImGui::SliderFloat("Spectral Exponent", &Application::uiParams.spectralExponent, 1.0, 300.0);
		}

		ImGui::SliderFloat("Ambient Intensity", &Application::uiParams.ambientIntensity, 0.0, 1.0);
		ImGui::SliderFloat("Iridescence Intensity", &Application::uiParams.iridescenceIntensity, 0.0, 5.0);
	}
	lightColor[0] = Application::uiParams.outputLightColor.x;
	lightColor[1] = Application::uiParams.outputLightColor.y;
	lightColor[2] = Application::uiParams.outputLightColor.z;
	ImGui::SliderInt("", &Application::uiParams.noOfButterflies, 0, 6);
	int noOfButterflies = pow(10, Application::uiParams.noOfButterflies);
	ImGui::Text(" No of Butterflies = %d", noOfButterflies);
	if (ImGui::Button("Redraw Butterflies"))
	{
		Application::uiParams.shouldUpdateNoOfButterflies = true;
		Application::uiParams.prevnoOfButterflies = Application::uiParams.noOfButterflies;
	}
	ImGui::ColorEdit3("Output Light Color", lightColor);
	ImGui::Checkbox("Ambient Enabled", &Application::uiParams.ambientEnabled);
	ImGui::Checkbox("Iridescence Enabled", &Application::uiParams.iridescenceEnabled);
	ImGui::Checkbox("Specular Enabled", &Application::uiParams.specularEnabled);
	ImGui::Checkbox("Use Normal Map", &Application::uiParams.useNormalMap);
	ImGui::Checkbox("Use Opacity Map", &Application::uiParams.useOpacityMap);
	ImGui::SliderFloat("Scale", &Application::uiParams.scale, 0.1, 50.0);
	ImGui::SliderFloat("Transparency", &Application::uiParams.transparency, 0.1, 1.0);
	ImGui::SliderInt("Incidence Angle to verify", &Application::uiParams.IncidencAngleToVerify, 0, 89);
	ImGui::Text("Peak Wavelength at %d = %f",
		Application::uiParams.IncidencAngleToVerify,
		Application::uiParams.peakWavelength);
	ImGui::Text("Spectral Error (RGB) %.3f %.3f %.3f",
		Application::uiParams.inputLightColor.x - Application::uiParams.outputLightColor.x,
		Application::uiParams.inputLightColor.y - Application::uiParams.outputLightColor.y,
		Application::uiParams.inputLightColor.z - Application::uiParams.outputLightColor.z
	);

	ImGui::Text("Light Position %.3f %.3f %.3f",
		Application::uiParams.lightPosition.x,
		Application::uiParams.lightPosition.y,
		Application::uiParams.lightPosition.z
	);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}


// Function to create VkDebugUtilsMessengerEXT object from Debug Messenger Info structure
// 1st Parameter - Vulkan Instance for the debug messenger to be created
// 2nd Parameter - structure of create info parameters used while creating the Debug Messenger
// 3rd Parameter - optional allocator callback
// 4th Parameter - the Debug Messenger created in this function
VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {

	// Look up the address of the extension function to create Debug Utils Messenger EXT
	auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
	if (func != nullptr) {
		// Call the found extension function
		return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
	}
	else {
		// Return error as the extension function is not found
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

// Function to destroy VkDebugUtilsMessengerEXT object
void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {

	// Look up the address of the extension function to destroy Debug Utils Messenger EXT
	auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
	if (func != nullptr) {
		// Call the found extension function
		func(instance, debugMessenger, pAllocator);
	}
}


Application::Application()
{
	// initialise arcballs to 80% of the widget's size
	Ball_Init(&lightBall);		Ball_Place(&lightBall, qOne, 0.80);
	Ball_Init(&objectBall);		Ball_Place(&objectBall, qOne, 0.80);
	isMouseDragged = false;
	whichButton = -1;
}


Application::~Application()
{
}


void Application::run() {

	// Initialize a Window
	initWindow();

	// Initializes Vulkan resources
	initVulkan();

	// Main Loop where every frame is rendered
	mainLoop();

	// Cleanup and deallocate allocate resources
	cleanup();
}
/////////////////////
// Run Functions ///
///////////////////

// Function to initializes a Window to render the objects
void Application::initWindow() {

	// Initialize the GLFW Library
	glfwInit();

	// Specify GLFW not to create an OpenGL Context
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	// Restrict Window resizing
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	// Create a Window
	// 1st Parameter - Width of the Window
	// 2nd Parameter - Height of the Window
	// 3rd Parameter - Title of the Window
	// 4th Parameter - Monitor to open the window
	// 5th Parameter - Only relevant to OpenGL
	window = glfwCreateWindow(WIDTH, HEIGHT, WINDOW_TITLE, nullptr, nullptr);
	// Set the pointer to window in callback functions
	glfwSetWindowUserPointer(window, this);

	// Initialize the callback function for window resize
	glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);

	// Initialize the callback function for mouse events
	glfwSetMouseButtonCallback(window, mouse_callback);

	glfwSetCursorPosCallback(window, cursor_position_callback);

	// Initialize the callback function for keyboard events
	glfwSetKeyCallback(window, key_callback);

	// Set initial translate and rotation
	translate_x = translate_y = 0.0;
	rotate_x = rotate_y = 0.0;
}

// Function to initialize the Vulkan objects
void Application::initVulkan() {
	// Create the Instance
	// An  instance is the connection between the application and Vulkan library
	createInstance();

	// Setup the Debug Messenger
	setupDebugMessenger();

	// Create Device
	device = new Device(&instance, window);

	ReadColorMatchingXMLFile(COLOR_MATCH_FUNCTIONS);

	FindMatrixA();

	ReadChromaticityXMLFile(CHROMATICITY_COORDS);

	//FindFourierCoefficients(Vec3{ 0.18,0.27,0.53 });
	//
	//std::vector<double> spectra = ConstructSpectraGaussian(ConvertXYZtoHSV(Vec3{ 0.18,0.27,0.53 }));
	//
	//std::vector iridescentSpectra = ConstructIridescentSpectra(spectra);
	//
	//Vec3 color = GetXYZColorFromSpectra(iridescentSpectra);
	//color = ConvertXYZtoRGB(color);

	// Create Command Pool
	commandPool = new CommandPool(device);

	// Set the compute buffer size
	ComputeBufferSize = sizeof(Pixel) * WIDTH * HEIGHT;

	// Create descriptor set layout for compute pipeline
	createComputeDescriptorSetLayout();

	// Create compute pipeline
	createComputePipeline();

	// Create command pool for compute pipeline
	createComputeCommandPool();

	// Create buffers for compute pipeline
	createComputeBuffers();

	// Create the Descriptor Pool to create descriptor sets for compute pipeline
	createComputeDescriptorPool();

	// Create descriptor sets
	createComputeDescriptorSet();


	UpdateSpectralParameters();

	//CreateIridescentImage();

	// Create command buffers for compute pipeline
	createComputeCommandBuffers();

	// Run the compute pipeline to compute the volumetric texture
	//runComputeCommandBuffer();

	//createTextureImageFromComputeBuffer();

	// Create Swap chain
	swapChain = new Swapchain(device, window);

	// Create render pass
	createRenderPass();

	// Create Descriptor Set layout
	createDescriptorSetLayout();

	// Create Shadow Map Descriptor Set layout
	createQuadDescriptorSetLayout();

	// Create the graphics pipeline
	createGraphicsPipeline();

	createQuadGraphicsPipeline();

	// Init ImGUI
	imGui = new ImGuiHelper(&instance, window, device, swapChain, commandPool);

	createDepthResources();

	// Create Frame Buffers
	createFramebuffers();

	InitQuad();

	// Parse the Object file
	m = ParseObjFile(MODEL);

	// Create texture image
	textureImage = new TextureImage(device, commandPool, OPACITY_MAP);

	normalImage = new TextureImage(device, commandPool, NORMAL_MAP);

	refImage = new TextureImage(device, commandPool, "ref_image.ppm");

	// Create Vertex Buffer
	createVertexBuffer();

	InstanceBuffer = new Buffer(device, pow(10, 6) * sizeof(InstanceData), VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	prepareInstanceData();

	// Create Index Buffer
	createIndexBuffer();

	createQuadVertexBuffer();

	createQuadIndexBuffer();

	// Create the Uniform Buffers
	createUniformBuffers();

	// Create the Descriptor Pool to create descriptor sets
	createDescriptorPool();

	// Create descriptor sets
	createDescriptorSets();

	// Create the Descriptor Pool to create descriptor sets
	createQuadDescriptorPool();

	// Create descriptor sets
	createQuadDescriptorSets();

	// Create Command Buffers
	createCommandBuffers();

	// Create the semaphores and fences
	createSyncObjects();
}

// Function in which every frame is rendered
// Iterates until window is closed
void Application::mainLoop() {

	// Event loop to keep the application running until there is an error or window is closed
	while (!glfwWindowShouldClose(window)) {

		// Checks for events like Window close by the user
		glfwPollEvents();
		if (uiParams.shouldUpdateNoOfButterflies)
		{
			prepareInstanceData();

			createCommandBuffers();

			uiParams.shouldUpdateNoOfButterflies = false;
		}
		if (uiParams.shouldRegenerateTexture)
		{

			UpdateSpectralParameters();

			createComputeCommandBuffers();

			runComputeCommandBuffer();

			createTextureImageFromComputeBuffer();

			uiParams.shouldRegenerateTexture = false;
		}
		// Update ImGUI Min Image Count if resized
		if (framebufferResized)
		{
			imGui->UpdateMinImageCount();
		}

		// draw the frame
		drawFrame();
	}

	// Wait for the logical device to complete operations
	vkDeviceWaitIdle(device->logicalDevice);
}

// Function to destroy all Vulkan objects and free allocated resources
void Application::cleanup() {

	cleanupSwapChain();


	// Destroy the compute pipeline
	vkDestroyPipeline(device->logicalDevice, ComputePipeline, nullptr);

	// Destroy the compute pipeline layout
	vkDestroyPipelineLayout(device->logicalDevice, computePipelineLayout, nullptr);

	// Destroy the descriptor pool
	vkDestroyDescriptorPool(device->logicalDevice, computeDescriptorPool, nullptr);

	textureImage->Cleanup(device);

	normalImage->Cleanup(device);

	refImage->Cleanup(device);

	vkDestroyDescriptorSetLayout(device->logicalDevice, descriptorSetLayout, nullptr);

	vkDestroyDescriptorSetLayout(device->logicalDevice, computeDescriptorSetLayout, nullptr);

	vkDestroyDescriptorSetLayout(device->logicalDevice, quadDescriptorSetLayout, nullptr);

	SpectralParametersBuffer->Cleanup(device);

	ComputeBuffers->Cleanup(device);

	// Destroy the index buffer
	IndexBuffer->Cleanup(device);

	// Destroy the vertex buffer
	VertexBuffer->Cleanup(device);

	InstanceBuffer->Cleanup(device);

	quadIndexBuffer->Cleanup(device);

	quadVertexBuffer->Cleanup(device);


	// Destroy the semaphores and fences
	for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
	{
		// Destroy the render finished semaphore
		vkDestroySemaphore(device->logicalDevice, renderFinishedSemaphores[i], nullptr);

		// Destroy the image available semaphore
		vkDestroySemaphore(device->logicalDevice, imageAvailableSemaphores[i], nullptr);

		// Destroy the fence
		vkDestroyFence(device->logicalDevice, inFlightFences[i], nullptr);
	}

	// Destroy command pool
	commandPool->Cleanup(device);

	vkDestroyCommandPool(device->logicalDevice, computeCommandPool, nullptr);

	// Check whether validation layers are enabled
	if (enableValidationLayers) {
		// Destroy the Debug Utils Messenger Extension
		DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	}

	// Cleanup the device
	device->Cleanup(&instance);

	// Destroy the Vulkan instance
	// 1st Parameter - instance to be destoyed
	// 2nd Parameter - optional allocator callback
	vkDestroyInstance(instance, nullptr);

	// Destroy and cleanup the GLFW Window
	glfwDestroyWindow(window);

	// Terminate GLFW
	glfwTerminate();
}

////////////////////////////
// Init Window Functions //
//////////////////////////

// Callback function called when window is resized
void Application::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	// Get the pointer to the application
	auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
	// Set the frame buffer resized flag to true
	app->framebufferResized = true;
	app->width = width;
	app->height = height;
}

void Application::cursor_position_callback(GLFWwindow* window, double x, double y) {
	auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
	HVect vNow;
	// scale both coordinates from that
	float size = (app->width > app->height) ? app->height : app->width;

	if (app->isMouseDragged)
	{
		if (app->whichButton == GLFW_MOUSE_BUTTON_RIGHT)
		{
			vNow.x = (2.0 * x - size) / size;
			vNow.y = (size - 2.0 * y) / size;

			// pass it to the arcball code	
			Ball_Mouse(&app->objectBall, vNow);
			// start dragging
			Ball_Update(&app->objectBall);
		}
		if (app->whichButton == GLFW_MOUSE_BUTTON_MIDDLE)
		{
			vNow.x = 0.0;// (2.0 * x - size) / size;
			vNow.y = (size - 2.0 * y) / size;

			// pass it to the arcball code	
			Ball_Mouse(&app->lightBall, vNow);
			// start dragging
			Ball_Update(&app->lightBall);
		}
		if (app->whichButton == GLFW_MOUSE_BUTTON_LEFT) {
			vNow.x = (2.0 * x - size) / size;
			vNow.y = (size - 2.0 * y) / size;
			app->translate_x += vNow.x - app->last_x;
			app->translate_y += vNow.y - app->last_y;
			app->last_x = vNow.x;
			app->last_y = vNow.y;
		}
	}
}

// Mouse callback function
void Application::mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (ImGui::GetIO().WantCaptureMouse)
		return;
	double x;
	double y;
	glfwGetCursorPos(window, &x, &y);
	auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
	Vec4 vNow;
	HVect vNow2;
	float size = (app->width > app->height) ? app->height : app->width;
	vNow.x = (2.0 * x - size) / size;
	vNow.y = (size - 2.0 * y) / size;
	// scale both coordinates from that

	if (button == GLFW_MOUSE_BUTTON_LEFT) {

		if (GLFW_PRESS == action)
		{
			app->last_x = vNow.x;
			app->last_y = vNow.y;
			app->isMouseDragged = true;
			app->whichButton = GLFW_MOUSE_BUTTON_LEFT;
		}
		else if (GLFW_RELEASE == action)
		{
			app->translate_x += vNow.x - app->last_x;
			app->translate_y += vNow.y - app->last_y;
			app->last_x = vNow.x;
			app->last_y = vNow.y;
			app->isMouseDragged = false;
			app->whichButton = -1;
		}
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
		vNow2.x = 0.0;//(2.0 * x - size) / size;
		vNow2.y = (size - 2.0 * y) / size;
		if (GLFW_PRESS == action)
		{
			app->last_rotate_x = vNow.x;
			app->last_rotate_y = vNow.y;
			// pass it to the arcball code	
			Ball_Mouse(&app->lightBall, vNow2);
			// start dragging
			Ball_BeginDrag(&app->lightBall);
			app->isMouseDragged = true;
			app->whichButton = GLFW_MOUSE_BUTTON_MIDDLE;
		}
		else if (GLFW_RELEASE == action)
		{
			app->rotate_x += vNow.x - app->last_rotate_x;
			app->rotate_y += vNow.y - app->last_rotate_y;
			app->last_rotate_x = vNow.x;
			app->last_rotate_y = vNow.y;
			// end the drag
			Ball_EndDrag(&app->lightBall);
			app->isMouseDragged = false;
			app->whichButton = -1;
		}

	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT) {
		vNow2.x = (2.0 * x - size) / size;
		vNow2.y = (size - 2.0 * y) / size;
		if (GLFW_PRESS == action)
		{
			app->last_rotate_x = vNow.x;
			app->last_rotate_y = vNow.y;
			// pass it to the arcball code	
			Ball_Mouse(&app->objectBall, vNow2);
			// start dragging
			Ball_BeginDrag(&app->objectBall);
			app->isMouseDragged = true;
			app->whichButton = GLFW_MOUSE_BUTTON_RIGHT;
		}
		else if (GLFW_RELEASE == action)
		{
			app->rotate_x += vNow.x - app->last_rotate_x;
			app->rotate_y += vNow.y - app->last_rotate_y;
			app->last_rotate_x = vNow.x;
			app->last_rotate_y = vNow.y;
			// end the drag
			Ball_EndDrag(&app->objectBall);
			app->isMouseDragged = false;
			app->whichButton = -1;
		}

	}
}

// Keyboard callback functions
void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
		uiParams.ambientEnabled = !uiParams.ambientEnabled;
	//app->m.lightingConstants.ambientEnabled = !app->m.lightingConstants.ambientEnabled;
	if (key == GLFW_KEY_I && action == GLFW_PRESS)
		uiParams.iridescenceEnabled = !uiParams.iridescenceEnabled;
	//app->m.lightingConstants.DiffuseEnabled = !app->m.lightingConstants.DiffuseEnabled;
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		uiParams.specularEnabled = !uiParams.specularEnabled;
	//app->m.lightingConstants.specularEnabled = !app->m.lightingConstants.specularEnabled;
	if (key == GLFW_KEY_N && action == GLFW_PRESS)
		uiParams.useNormalMap = !uiParams.useNormalMap;
	//app->m.lightingConstants.textureEnabled = !app->m.lightingConstants.textureEnabled;
	if (key == GLFW_KEY_O && action == GLFW_PRESS)
		uiParams.useOpacityMap = !uiParams.useOpacityMap;

}


////////////////////////////
// Init Vulkan Functions //
//////////////////////////

// Function to create an  instance - the connection between the application and the Vulkan library
void Application::createInstance()
{
	// Check whether validation layers requested are supported
	if (enableValidationLayers && !checkValidationLayerSupport()) {
		throw std::runtime_error("validation layers requested, but not available!");
	}

	// Structure to specify optional information about the application.
	// This provides useful information to the driver to optimize for the application
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; // specifies the type of the information stored in the structure
	appInfo.pApplicationName = "Hello Triangle"; // Name of the application
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0); // Version of the application
	appInfo.pEngineName = "No Engine"; // Name of the engine used to create the engine
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0); // Version of engine used to create the engine
	appInfo.apiVersion = VK_API_VERSION_1_0; // Highest version of Vulkan that the application must use

	// Structure to specify which global extensions and validation layers should be used in the application
	// This is applied to the entire program and not to specific device
	VkInstanceCreateInfo createInfo = {};
	// Type of inforamtion stored in the structure
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	// Specify the application info
	createInfo.pApplicationInfo = &appInfo;

	// Retrieve the number of supported extensions and store in extensionCount
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	// An array to hold the supported extension details
	std::vector<VkExtensionProperties> extensions(extensionCount);

	// Query the supported extension details
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	// Print the supported extension details
	std::cout << "available extensions:" << std::endl;

	// Loop through the extensions and print
	for (const auto& extension : extensions) {
		std::cout << "\t" << extension.extensionName << std::endl;
	}

	// Stores the reference to the extensions
	auto glfwExtensions = getRequiredExtensions();

	// Specifies the no of extensions and the extensions to use in the application
	createInfo.enabledExtensionCount = static_cast<uint32_t>(glfwExtensions.size());
	createInfo.ppEnabledExtensionNames = glfwExtensions.data();

	// Stores the Debug Create Info
	VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;

	// Check whether Validation layers are enabled
	if (enableValidationLayers)
	{
		// Specifies the no of validation layers to use in the application
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());

		// Specifies the validation layers to use in the application
		createInfo.ppEnabledLayerNames = validationLayers.data();

		// Populate the Debug Messenger Create Info
		populateDebugMessengerCreateInfo(debugCreateInfo);

		// Set the Debug Messenger to pNext
		createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
	}
	else
	{
		// Set the no of validation layers as zero
		createInfo.enabledLayerCount = 0;

		// Set pNext to null
		createInfo.pNext = nullptr;
	}
	// Creates an Vulkan instance
	// 1st parameter - pointer to creation info
	// 2nd parameter - pointer to custom allocator callbacks
	// 3rd parameter - pointer to Vulkan instance
	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {

		// Throw runtime error exception if the Vulkan instance creation fails
		throw std::runtime_error("failed to create instance!");
	}
}

// Function to set up the Debug Messenger
// Debug Messender - provides an explicit callback to print debug message in standard output
void Application::setupDebugMessenger() {

	// Return if the validation layers are disabled
	if (!enableValidationLayers) return;

	// Create and populate the Debug Messenger Create Info
	VkDebugUtilsMessengerCreateInfoEXT createInfo;
	populateDebugMessengerCreateInfo(createInfo);

	// Create the Debug Messenger Extension
	if (CreateDebugUtilsMessengerEXT(instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
		// Throw runtime error if the extension creation fails
		throw std::runtime_error("failed to set up debug messenger!");
	}
}

// Function to create render pass
// Render Pass - Information on no of color and depth buffers, no of samples to use and how the contents should be handled
void Application::createRenderPass() {
	// Color buffer attachment information
	VkAttachmentDescription colorAttachment = {};
	// format of colour buffer attachment
	colorAttachment.format = swapChain->swapChainImageFormat;
	// Number of samples
	colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
	// Specify what to do with the data in the attachment before rendering
	colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	// Specify what to do with the data in the attachment after rendering
	colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	// Specify what to do with the stencil data in the attachment before rendering
	colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	// Specify what to do with the stencil data in the attachment after rendering
	colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	// Specify layout the image will have before the render pass
	colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	// Specify layout the image should transition to after render pass
	colorAttachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

	VkAttachmentDescription depthAttachment = {};
	depthAttachment.format = findDepthFormat();
	depthAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
	depthAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	depthAttachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	depthAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	depthAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	depthAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	depthAttachment.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

	// Attachment Reference for subpass
	VkAttachmentReference colorAttachmentRef = {};
	// Specify the attachment to refer
	colorAttachmentRef.attachment = 0;
	// Specify the layout to transition to when this subpass is started
	colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

	VkAttachmentReference depthAttachmentRef = {};
	depthAttachmentRef.attachment = 1;
	depthAttachmentRef.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

	// Subpass desciption
	// Subpass desciption
	std::array<VkSubpassDescription, 2> subpasses = {};

	// Specify where the subpass has to be executed
	subpasses[0].pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	// Specify the number of color attachment references
	subpasses[0].colorAttachmentCount = 1;
	// Specify the pointer to the color attachment reference
	subpasses[0].pColorAttachments = &colorAttachmentRef;
	subpasses[0].pDepthStencilAttachment = &depthAttachmentRef;

	subpasses[1].pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	// Specify the number of color attachment references
	subpasses[1].colorAttachmentCount = 1;
	// Specify the pointer to the color attachment reference
	subpasses[1].pColorAttachments = &colorAttachmentRef;
	subpasses[1].pDepthStencilAttachment = &depthAttachmentRef;

	// Subpass dependency to make the render pass wait for the color attachment output bit stage
	std::array<VkSubpassDependency, 2> dependencies = {};
	// Specify the dependency and dependent subpasses
	dependencies[0].srcSubpass = VK_SUBPASS_EXTERNAL;
	dependencies[0].dstSubpass = 0;
	// Specify the operation to wait for. i.e, wait for the swap chain to read the image
	dependencies[0].srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependencies[0].srcAccessMask = 0;
	// Specify the operation that should wait
	dependencies[0].dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependencies[0].dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

	// Specify the dependency and dependent subpasses
	dependencies[1].srcSubpass = 0;
	dependencies[1].dstSubpass = 1;
	// Specify the operation to wait for. i.e, wait for the swap chain to read the image
	dependencies[1].srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependencies[1].srcAccessMask = 0;
	// Specify the operation that should wait
	dependencies[1].dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependencies[1].dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;


	//// Subpass dependency to make the render pass wait for the color attachment output bit stage
	//VkSubpassDependency dependency = {};
	//// Specify the dependency and dependent subpasses
	//dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
	//dependency.dstSubpass = 0;
	//// Specify the operation to wait for. i.e, wait for the swap chain to read the image
	//dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	//dependency.srcAccessMask = 0;
	//// Specify the operation that should wait
	//dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	//dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

	std::array<VkAttachmentDescription, 2> attachments = { colorAttachment, depthAttachment };

	// Render pass create info
	VkRenderPassCreateInfo renderPassInfo = {};
	// Type of information stored in the structure
	renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	// No of attachments in the render pass
	renderPassInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
	// Pointer to the attachment
	renderPassInfo.pAttachments = attachments.data();
	// No of subpasses
	renderPassInfo.subpassCount = static_cast<uint32_t>(subpasses.size());; //1;
	// Pointer to the subpass
	renderPassInfo.pSubpasses = subpasses.data();// &subpass;
	// No of subpass dependencies
	renderPassInfo.dependencyCount = static_cast<uint32_t>(dependencies.size());;// 1;
	// Pointer to the subpass dependency
	renderPassInfo.pDependencies = dependencies.data();// &dependency;

	// Create render pass
	// 1st Parameter - GPU
	// 2nd Parameter - Render pass create info
	// 3rd Parameter - Custom Allocator
	// 4th Parameter - Pointer to the created render pass
	if (vkCreateRenderPass(device->logicalDevice, &renderPassInfo, nullptr, &renderPass) != VK_SUCCESS) {
		// Throw runtime error exception as render pass creation failed
		throw std::runtime_error("failed to create render pass!");
	}
}

// Function to create the Graphics pipeline
// Graphics Pipeline - Sequence of operations with vertices & textures as input and pixels to render as output
void Application::createGraphicsPipeline() {
	// Fetch the byte code of vertex shader
	auto vertShaderCode = readFile("shaders/vert.spv");

	// Fetch the byte code of fragment shader
	auto fragShaderCode = readFile("shaders/frag.spv");

	// Create Vertex shader module
	VkShaderModule vertShaderModule = createShaderModule(vertShaderCode);

	// Create Fragment shader module
	VkShaderModule fragShaderModule = createShaderModule(fragShaderCode);

	// Vertex shader stage create info
	VkPipelineShaderStageCreateInfo vertShaderStageInfo = {};
	// Type of information stored in the structure
	vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	// Specify the vertex shader stage in the pipeline
	vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
	// Specify the vertex shader module
	vertShaderStageInfo.module = vertShaderModule;
	// Specify the entry point
	vertShaderStageInfo.pName = "main";

	// Fragment shader stage create info
	VkPipelineShaderStageCreateInfo fragShaderStageInfo = {};
	// Type of information stored in the structure
	fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	// Specify the fragment shader stage in the pipeline
	fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
	// Specify the fragment shader module
	fragShaderStageInfo.module = fragShaderModule;
	// Specify the entry point
	fragShaderStageInfo.pName = "main";

	// Create an array to store vertex shader stage create info and fragment shader stage create info
	VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

	// Binding description
	auto bindingDescription = getBindingDescription();

	// Attribute description
	auto attributeDescriptions = getAttributeDescriptions();

	// Information of format of the vertex data passed to the vertex shader
	VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
	// Type of information stored in the structure
	vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	// Details for loading vertex data
	vertexInputInfo.vertexBindingDescriptionCount = 2;
	vertexInputInfo.pVertexBindingDescriptions = bindingDescription.data();
	vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
	vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();

	// Information of kind of geometry drawn
	VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
	// Type of information stored in the structure
	inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	// Specify kind of geometry drawn
	inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	// Specify that it is not possible to break lines and triangles by using special index
	inputAssembly.primitiveRestartEnable = VK_FALSE;

	// Viewport information
	// Viewport - region of framebuffer where the output will be rendereds
	VkViewport viewport = {};
	// starting x of viewport
	viewport.x = 0.0f;
	// starting y of viewport
	viewport.y = 0.0f;
	// width of viewport
	viewport.width = (float)swapChain->swapChainExtent.width;
	// height of viewport
	viewport.height = (float)swapChain->swapChainExtent.height;
	// min depth of viewport
	viewport.minDepth = 0.0f;
	// max depth of viewport
	viewport.maxDepth = 1.0f;

	// Scissor information
	// Scissor - a specification of the pixels that will be stored
	VkRect2D scissor = {};
	// Scissor offset
	scissor.offset = { 0, 0 };
	// Scissor extent
	scissor.extent = swapChain->swapChainExtent;

	// Viewport State create info
	VkPipelineViewportStateCreateInfo viewportState = {};
	// Type of information stored in the structure
	viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	// No of viewports
	viewportState.viewportCount = 1;
	// Specify the pointer to the viewports
	viewportState.pViewports = &viewport;
	// No of scissors
	viewportState.scissorCount = 1;
	// Specify the pointer to the scissors
	viewportState.pScissors = &scissor;

	// Rasterization State create info
	// Rasterizer - turns the geometry into fragments
	VkPipelineRasterizationStateCreateInfo rasterizer = {};
	// Type of information stored in the structure
	rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	// Specify whether the fragments beyond the near and far planes has to be clamped or discarded
	rasterizer.depthClampEnable = VK_FALSE;
	// Specify whether the geometry should pass through the rasterizer stage
	rasterizer.rasterizerDiscardEnable = VK_FALSE;
	// Specify how fragments are generated
	rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
	// Specify the thickness of the lines
	rasterizer.lineWidth = 1.0f;
	// Specify the type of culling to use
	rasterizer.cullMode = VK_CULL_MODE_NONE;
	// Specify the vertex order
	rasterizer.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
	// Should the rasterizer alter the depth values by adding a constant value or biasing them
	rasterizer.depthBiasEnable = VK_FALSE;
	rasterizer.depthBiasConstantFactor = 0.0f; // Optional
	rasterizer.depthBiasClamp = 0.0f; // Optional
	rasterizer.depthBiasSlopeFactor = 0.0f; // Optional

	// Information to configure multisampling to perform anti-aliasing
	VkPipelineMultisampleStateCreateInfo multisampling = {};
	// Type of information stored in the structure
	multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	multisampling.sampleShadingEnable = VK_FALSE;
	multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	multisampling.minSampleShading = 1.0f; // Optional
	multisampling.pSampleMask = nullptr; // Optional
	multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
	multisampling.alphaToOneEnable = VK_FALSE; // Optional

	VkPipelineDepthStencilStateCreateInfo depthStencil = {};
	depthStencil.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	depthStencil.depthTestEnable = VK_TRUE;
	depthStencil.depthWriteEnable = VK_TRUE;
	depthStencil.depthCompareOp = VK_COMPARE_OP_LESS;
	depthStencil.depthBoundsTestEnable = VK_FALSE;
	depthStencil.stencilTestEnable = VK_FALSE;

	// Colour blending configuration per attached framebuffer
	// Colour blending - way to combine with colour already in framebuffer
	VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
	colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	colorBlendAttachment.blendEnable = VK_TRUE;
	colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;
	colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;
	colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
	colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
	colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;

	// Global colour blending setting information
	VkPipelineColorBlendStateCreateInfo colorBlending = {};
	// Type of information stored in the structure
	colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	colorBlending.logicOpEnable = VK_FALSE;
	colorBlending.logicOp = VK_LOGIC_OP_COPY;
	colorBlending.attachmentCount = 1;
	colorBlending.pAttachments = &colorBlendAttachment;
	colorBlending.blendConstants[0] = 0.0f;
	colorBlending.blendConstants[1] = 0.0f;
	colorBlending.blendConstants[2] = 0.0f;
	colorBlending.blendConstants[3] = 0.0f;

	// Dynamic states which can be changed without recreating the pipeline
	VkDynamicState dynamicStates[] = {
VK_DYNAMIC_STATE_VIEWPORT,
VK_DYNAMIC_STATE_LINE_WIDTH
	};

	// Dynamic state create info
	VkPipelineDynamicStateCreateInfo dynamicState = {};
	// Type of information stored in the structure
	dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	// No of dynamic states
	dynamicState.dynamicStateCount = 2;
	// Specify the array of dynamic states
	dynamicState.pDynamicStates = dynamicStates;

	// Pipeline layout create info
	// Pipeline layout - Uniform values/Push constants specified during pipeline creation
	VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
	// Type of information stored in the structure
	pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	// Number of uniforms
	pipelineLayoutInfo.setLayoutCount = 1;

	pipelineLayoutInfo.pSetLayouts = &descriptorSetLayout;
	// Number of push constants
	pipelineLayoutInfo.pushConstantRangeCount = 0;

	// Create the pipeline layout
	if (vkCreatePipelineLayout(device->logicalDevice, &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
		// Throw runtime error exception as pipeline layout creation failed
		throw std::runtime_error("failed to create pipeline layout!");
	}

	// Graphics pipeline create info
	VkGraphicsPipelineCreateInfo pipelineInfo = {};
	// Type of information stored in the structure
	pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	// No of shader stages
	pipelineInfo.stageCount = 2;
	// Pointer to shader stages
	pipelineInfo.pStages = shaderStages;
	// Specify the vertex input state
	pipelineInfo.pVertexInputState = &vertexInputInfo;
	// Specify the input assembly state
	pipelineInfo.pInputAssemblyState = &inputAssembly;
	// Specify the viewport state
	pipelineInfo.pViewportState = &viewportState;
	// Specify the rasterization state
	pipelineInfo.pRasterizationState = &rasterizer;
	// Specify the Multisampling state
	pipelineInfo.pMultisampleState = &multisampling;
	// Specify Depth stencil state
	pipelineInfo.pDepthStencilState = &depthStencil;
	// Specify the color blend state
	pipelineInfo.pColorBlendState = &colorBlending;
	// Specify the dynamic state
	pipelineInfo.pDynamicState = nullptr; // Optional
	// Specify the pipeline layout
	pipelineInfo.layout = pipelineLayout;
	// Specify the render pass
	pipelineInfo.renderPass = renderPass;
	// Specify the index of the render pass where this graphics pipeline will be used
	pipelineInfo.subpass = 0;
	// Specify the base pipeline to derive from
	pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
	// Specify the index of base pipeline to derive from
	pipelineInfo.basePipelineIndex = -1; // Optional

	// Create the graphics pipeline
	// 1st Parameter - GPU
	// 2nd Parameter - Pipeline cache to store and reuse data for pipeline creation
	// 3rd Parameter - Pipeline create info
	// 4th Parameter - Custom allocator
	// 5th Parameter - Pointer to the created graphics pipeline
	if (vkCreateGraphicsPipelines(device->logicalDevice, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &graphicsPipeline) != VK_SUCCESS) {
		// Throw runtime error exception as graphics pipeline creation failed
		throw std::runtime_error("failed to create graphics pipeline!");
	}

	// Destroy the fragment shader module
	vkDestroyShaderModule(device->logicalDevice, fragShaderModule, nullptr);

	// Destroy the vertex shader module
	vkDestroyShaderModule(device->logicalDevice, vertShaderModule, nullptr);
}

// Function to create Frame buffers
// Frame buffers - Frame buffers represent a group of memory attachments used by a render pass instance
void Application::createFramebuffers() {
	// Resize the collection of frame buffers
	swapChainFramebuffers.resize(swapChain->swapChainImageViews.size());

	// Loop through the image views
	for (size_t i = 0; i < swapChain->swapChainImageViews.size(); i++) {

		// Attachments for current image view
		std::array<VkImageView, 2> attachments = {
swapChain->swapChainImageViews[i],
depthImage->imageView
		};

		// Frame buffer create info
		VkFramebufferCreateInfo framebufferInfo = {};
		// Type of information stored in the structure
		framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		// Specify the render pass
		framebufferInfo.renderPass = renderPass;
		// Specify the no of attachments for image view
		framebufferInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
		// Specify the attachment for the image view
		framebufferInfo.pAttachments = attachments.data();
		// Specify width
		framebufferInfo.width = swapChain->swapChainExtent.width;
		// Specify height
		framebufferInfo.height = swapChain->swapChainExtent.height;
		// Specify the no of layers in the image
		framebufferInfo.layers = 1;

		// Create the frame buffer
		// 1st Parameter - GPU
		// 2nd Parameter - Frame buffer create info
		// 3rd Parameter - Custom Allocator
		// 4th Parameter - Pointer to the created frame buffer
		if (vkCreateFramebuffer(device->logicalDevice, &framebufferInfo, nullptr, &swapChainFramebuffers[i]) != VK_SUCCESS) {
			// Throw runtime error exception as framebuffer creation failed
			throw std::runtime_error("failed to create framebuffer!");
		}
	}
}

// Function to find the suitable depth format
VkFormat Application::findDepthFormat() {
	return findSupportedFormat(
		{ VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT },
		VK_IMAGE_TILING_OPTIMAL,
		VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
	);
}

// Function to find the supported depth format
VkFormat Application::findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features) {

	for (VkFormat format : candidates) {
		VkFormatProperties props;
		vkGetPhysicalDeviceFormatProperties(device->physicalDevice, format, &props);
		if (tiling == VK_IMAGE_TILING_LINEAR && (props.linearTilingFeatures & features) == features) {
			return format;
		}
		else if (tiling == VK_IMAGE_TILING_OPTIMAL && (props.optimalTilingFeatures & features) == features) {
			return format;
		}
	}

	throw std::runtime_error("failed to find supported format!");
}

// Function to create descriptor pool to create descriptor sets
void Application::createDescriptorPool() {
	std::array<VkDescriptorPoolSize, 5> poolSizes = {};
	poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	poolSizes[0].descriptorCount = static_cast<uint32_t>(swapChain->swapChainImages.size());
	poolSizes[1].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	poolSizes[1].descriptorCount = static_cast<uint32_t>(swapChain->swapChainImages.size());
	poolSizes[2].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	poolSizes[2].descriptorCount = static_cast<uint32_t>(swapChain->swapChainImages.size());
	poolSizes[3].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;// VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	poolSizes[3].descriptorCount = static_cast<uint32_t>(swapChain->swapChainImages.size());
	poolSizes[4].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	poolSizes[4].descriptorCount = static_cast<uint32_t>(swapChain->swapChainImages.size());

	VkDescriptorPoolCreateInfo poolInfo = {};
	poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
	poolInfo.pPoolSizes = poolSizes.data();
	poolInfo.maxSets = static_cast<uint32_t>(swapChain->swapChainImages.size());

	if (vkCreateDescriptorPool(device->logicalDevice, &poolInfo, nullptr, &descriptorPool) != VK_SUCCESS) {
		throw std::runtime_error("failed to create descriptor pool!");
	}
}

// Function to create descriptor sets for each Vk Buffer
void Application::createDescriptorSets() {
	std::vector<VkDescriptorSetLayout> layouts(swapChain->swapChainImages.size(), descriptorSetLayout);
	VkDescriptorSetAllocateInfo allocInfo = {};
	allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	allocInfo.descriptorPool = descriptorPool;
	allocInfo.descriptorSetCount = static_cast<uint32_t>(swapChain->swapChainImages.size());
	allocInfo.pSetLayouts = layouts.data();

	descriptorSets.resize(swapChain->swapChainImages.size());
	if (vkAllocateDescriptorSets(device->logicalDevice, &allocInfo, descriptorSets.data()) != VK_SUCCESS) {
		throw std::runtime_error("failed to allocate descriptor sets!");
	}

	for (size_t i = 0; i < swapChain->swapChainImages.size(); i++) {
		VkDescriptorBufferInfo bufferInfo = {};
		bufferInfo.buffer = uniformBuffers[i]->buffer;
		bufferInfo.offset = 0;
		bufferInfo.range = sizeof(UniformBufferObject);

		VkDescriptorBufferInfo lightingBufferInfo = {};
		lightingBufferInfo.buffer = lightingBuffers[i]->buffer;
		lightingBufferInfo.offset = 0;
		lightingBufferInfo.range = sizeof(LightingConstants);

		VkDescriptorImageInfo imageInfo = {};
		imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
		imageInfo.imageView = textureImage->textureImage->imageView;
		imageInfo.sampler = textureImage->textureSampler;

		VkDescriptorBufferInfo iridescentBufferInfo = {};
		iridescentBufferInfo.buffer = iridescentBuffers[i]->buffer;
		iridescentBufferInfo.offset = 0;
		iridescentBufferInfo.range = sizeof(IridescentColors);

		VkDescriptorImageInfo normalImageInfo = {};
		normalImageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
		normalImageInfo.imageView = normalImage->textureImage->imageView;
		normalImageInfo.sampler = normalImage->textureSampler;

		std::array<VkWriteDescriptorSet, 5> descriptorWrites = {};

		descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[0].dstSet = descriptorSets[i];
		descriptorWrites[0].dstBinding = 0;
		descriptorWrites[0].dstArrayElement = 0;
		descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		descriptorWrites[0].descriptorCount = 1;
		descriptorWrites[0].pBufferInfo = &bufferInfo;

		descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[1].dstSet = descriptorSets[i];
		descriptorWrites[1].dstBinding = 1;
		descriptorWrites[1].dstArrayElement = 0;
		descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		descriptorWrites[1].descriptorCount = 1;
		descriptorWrites[1].pBufferInfo = &lightingBufferInfo;

		descriptorWrites[2].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[2].dstSet = descriptorSets[i];
		descriptorWrites[2].dstBinding = 2;
		descriptorWrites[2].dstArrayElement = 0;
		descriptorWrites[2].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorWrites[2].descriptorCount = 1;
		descriptorWrites[2].pImageInfo = &imageInfo;

		descriptorWrites[3].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[3].dstSet = descriptorSets[i];
		descriptorWrites[3].dstBinding = 6;
		descriptorWrites[3].dstArrayElement = 0;
		descriptorWrites[3].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;// VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorWrites[3].descriptorCount = 1;
		descriptorWrites[3].pBufferInfo = &iridescentBufferInfo;

		descriptorWrites[4].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[4].dstSet = descriptorSets[i];
		descriptorWrites[4].dstBinding = 7;
		descriptorWrites[4].dstArrayElement = 0;
		descriptorWrites[4].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorWrites[4].descriptorCount = 1;
		descriptorWrites[4].pImageInfo = &normalImageInfo;

		vkUpdateDescriptorSets(device->logicalDevice, static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
	}
}

// Function to create Uniform Buffers
void Application::createUniformBuffers() {
	VkDeviceSize bufferSize = sizeof(UniformBufferObject);

	uniformBuffers.resize(swapChain->swapChainImages.size());

	VkDeviceSize lightingBufferSize = sizeof(LightingConstants);

	lightingBuffers.resize(swapChain->swapChainImages.size());

	VkDeviceSize iridescentBufferSize = sizeof(IridescentColors);

	iridescentBuffers.resize(swapChain->swapChainImages.size());

	for (size_t i = 0; i < swapChain->swapChainImages.size(); i++) {
		uniformBuffers[i] = new Buffer(device, bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
		lightingBuffers[i] = new Buffer(device, lightingBufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
		iridescentBuffers[i] = new Buffer(device, iridescentBufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
	}
}

// Function to create Index Buffer
void Application::createIndexBuffer() {
	VkDeviceSize bufferSize = sizeof(m.indices[0]) * m.indices.size();

	Buffer *stagingBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	stagingBuffer->SetData(device, m.indices.data(), bufferSize);

	IndexBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

	IndexBuffer->copyBuffer(device, commandPool, stagingBuffer, bufferSize);

	stagingBuffer->Cleanup(device);
}

// Function to create Vertex Buffer
void Application::createVertexBuffer() {

	VkDeviceSize bufferSize = sizeof(m.vertices[0]) * m.vertices.size();

	Buffer *stagingBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	stagingBuffer->SetData(device, m.vertices.data(), bufferSize);

	VertexBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

	VertexBuffer->copyBuffer(device, commandPool, stagingBuffer, bufferSize);

	stagingBuffer->Cleanup(device);
}

// Function to parse obj file and generate a mesh
Mesh Application::ParseObjFile(const char* filename)
{
	std::vector<Vec3> positions;
	std::vector<Vec3> normals;
	std::vector<Vec3> texCoords;
	Mesh mesh;
	std::ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile.is_open())
	{
		throw std::runtime_error("failed to open obj file!");
	}


	std::string tempString = "";
	int i;
	while (true)
	{
		inputFile >> tempString;
		if (tempString == "mtllib")
		{
			std::string materialFilename;
			inputFile >> materialFilename;
			mesh.lightingConstants = LoadMaterial(materialFilename.c_str());
		}
		if (tempString == "v")
		{
			float x, y, z;
			inputFile >> x >> y >> z;
			Vec3 v;
			v.x = x;
			v.y = y;
			v.z = z;

			positions.push_back(v);
		}
		else if (tempString == "vn")
		{
			float x, y, z;
			inputFile >> x >> y >> z;
			Vec3 v;
			v.x = x;
			v.y = y;
			v.z = z;

			normals.push_back(v);
		}
		else if (tempString == "vt")
		{
			float x, y, z;
			inputFile >> x >> y >> z;
			Vec3 v;
			v.x = x;
			v.y = 1 - y;
			v.z = z;
			texCoords.push_back(v);
		}

		else if (tempString == "f")
		{
			for (int j = 0; j < 3; j++)
			{
				int position_index, tex_index, normal_index;
				inputFile >> tempString;
				std::string tstring = tempString;
				position_index = atoi(strtok(&tempString[0], "/"));
				tex_index = atoi(strtok(NULL, "/"));
				normal_index = atoi(strtok(NULL, "/"));
				Vertex v;
				v.position = positions[position_index - 1];
				Vec3 color;
				color.x = 1.0f;
				color.y = 1.0f;
				color.z = 1.0f;

				v.color = color;
				v.tex = texCoords[tex_index - 1];
				v.normal = normals[normal_index - 1];

				mesh.vertices.push_back(v);
			}
			int vertex_index = mesh.vertices.size();
			//mesh.indices.push_back(vertex_index - 4);
			mesh.indices.push_back(vertex_index - 3);
			mesh.indices.push_back(vertex_index - 2);
			//mesh.indices.push_back(vertex_index - 4);
			//mesh.indices.push_back(vertex_index - 2);
			mesh.indices.push_back(vertex_index - 1);

		}
		else if (inputFile.eof())
			break;
	}

	return mesh;
}

// Function to load material
LightingConstants Application::LoadMaterial(const char* filename)
{
	LightingConstants lightingConstants;
	std::ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile.is_open())
	{
		uiParams.isMTLFileAvailable = false;
		uiParams.useMTLFile = false;
	}
	else
	{
		uiParams.isMTLFileAvailable = true;
		uiParams.useMTLFile = true;
		std::string tempString = "";
		while (true)
		{
			inputFile >> tempString;
			if (tempString == "Ns")
			{
				inputFile >> lightingConstants.lightSpecularExponent;
			}
			else if (tempString == "Ka")
			{
				float r, g, b;
				inputFile >> r >> g >> b;
				lightingConstants.lightAmbient = Vec4{ r, g, b, 1.0 };
			}
			else if (tempString == "Ks")
			{
				float r, g, b;
				inputFile >> r >> g >> b;
				lightingConstants.lightSpecular = Vec4{ r, g, b, 1.0 };
			}
			else if (tempString == "Kd")
			{
				float r, g, b;
				inputFile >> r >> g >> b;
				lightingConstants.lightDiffuse = Vec4{ r, g, b, 1.0 };
			}
			else if (inputFile.eof())
				break;
		}
	}
	// Set the intensities of the light
	lightingConstants.ambientIntensity = uiParams.ambientIntensity;
	lightingConstants.specularIntensity = uiParams.iridescenceIntensity;
	lightingConstants.diffuseIntensity = 0.3;

	// Set the position of the light
	lightingConstants.lightPosition = Vec4{ 0.0f, -200.0f, 260.0f, 1.0f };
	return lightingConstants;
}

// function to create descriptor set layout to  provide the details about descriptor bindings in every shader
void Application::createDescriptorSetLayout() {
	VkDescriptorSetLayoutBinding uboLayoutBinding = {};
	uboLayoutBinding.binding = 0;
	uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	uboLayoutBinding.descriptorCount = 1;
	uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
	uboLayoutBinding.pImmutableSamplers = nullptr; // Optional

	VkDescriptorSetLayoutBinding lightingLayoutBinding = {};
	lightingLayoutBinding.binding = 1;
	lightingLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	lightingLayoutBinding.descriptorCount = 1;
	lightingLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
	lightingLayoutBinding.pImmutableSamplers = nullptr; // Optional

	VkDescriptorSetLayoutBinding samplerLayoutBinding = {};
	samplerLayoutBinding.binding = 2;
	samplerLayoutBinding.descriptorCount = 1;
	samplerLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	samplerLayoutBinding.pImmutableSamplers = nullptr;
	samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

	VkDescriptorSetLayoutBinding iridescentLayoutBinding = {};
	iridescentLayoutBinding.binding = 6;
	iridescentLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	iridescentLayoutBinding.descriptorCount = 1;
	iridescentLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
	iridescentLayoutBinding.pImmutableSamplers = nullptr; // Optional

	VkDescriptorSetLayoutBinding normalSamplerLayoutBinding = {};
	normalSamplerLayoutBinding.binding = 7;
	normalSamplerLayoutBinding.descriptorCount = 1;
	normalSamplerLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	normalSamplerLayoutBinding.pImmutableSamplers = nullptr;
	normalSamplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

	std::array<VkDescriptorSetLayoutBinding, 5> bindings = { uboLayoutBinding, lightingLayoutBinding, samplerLayoutBinding,iridescentLayoutBinding,normalSamplerLayoutBinding };

	VkDescriptorSetLayoutCreateInfo layoutInfo = {};
	layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
	layoutInfo.pBindings = bindings.data();

	if (vkCreateDescriptorSetLayout(device->logicalDevice, &layoutInfo, nullptr, &descriptorSetLayout) != VK_SUCCESS) {
		throw std::runtime_error("failed to create descriptor set layout!");
	}
}

// Function to create command buffers
// Command Buffers - All drawing operations are recorded in a command buffer
void Application::createCommandBuffers() {
	// resize the command buffers collection
	commandBuffers.resize(swapChainFramebuffers.size());

	// Command Buffer Allocate Info
	VkCommandBufferAllocateInfo allocInfo = {};
	// Type of information stored in the structure
	allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	// Specify the command pool
	allocInfo.commandPool = commandPool->commandPool;
	// Specify the command buffer is primary command buffer - can be submitted to queue for execution, but cannot be called from another other command buffer
	allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	// Specify the no of buffers to allocate
	allocInfo.commandBufferCount = (uint32_t)commandBuffers.size();

	// Allocate command buffers
	// 1st Parameter - GPU
	// 2nd Parameter - Command Buffer allocate info
	// 3rd Parameter - Pointer to Command Buffers
	if (vkAllocateCommandBuffers(device->logicalDevice, &allocInfo, commandBuffers.data()) != VK_SUCCESS) {
		// Throw runtime error exception as allocation for command buffers failed
		throw std::runtime_error("failed to allocate command buffers!");
	}

	// Loop through the command buffers
	for (size_t i = 0; i < commandBuffers.size(); i++) {
		// Command buffer begin info to start command buffer recording
		VkCommandBufferBeginInfo beginInfo = {};
		// Type of information stored in the structure
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		// Specify how the command buffer is used
		beginInfo.flags = 0; // Optional
		// Specify which state to inherit from, in case of secondary command buffer
		beginInfo.pInheritanceInfo = nullptr; // Optional

		// Start record the command buffer
		// 1st Parameter - command buffer to start recording
		// 2nd Parameter - Begin info
		if (vkBeginCommandBuffer(commandBuffers[i], &beginInfo) != VK_SUCCESS) {
			// Throw runtime error exception
			throw std::runtime_error("failed to begin recording command buffer!");
		}

		// Render pass begin info to start the render pass
		VkRenderPassBeginInfo renderPassInfo = {};
		// Type of information stored in the structure
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		// Specify the render pass to start
		renderPassInfo.renderPass = renderPass;
		// Specify the swap chain frame buffers
		renderPassInfo.framebuffer = swapChainFramebuffers[i];
		// Specify the area where shader loads and stores take place
		renderPassInfo.renderArea.offset = { 0, 0 };
		renderPassInfo.renderArea.extent = swapChain->swapChainExtent;
		// Set the clear colour for the background
		// Set the number of clear colours
		// Specify the pointer to the clear colour

		std::array<VkClearValue, 2> clearValues = {};
		clearValues[0].color = { 0.8f, 0.6f, 0.0f, 1.0f };
		clearValues[1].depthStencil = { 1.0f, 0 };

		renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
		renderPassInfo.pClearValues = clearValues.data();

		// Start the render pass
		// 1st Parameter - command buffer to record the commands to
		// 2nd Parameter - render pass begin info
		// 3rd Parameter - whether the drawing commands are executed inline or executed from a secondary command buffers
		vkCmdBeginRenderPass(commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

		// Bind the graphics pipeline
		// 1st Parameter - command buffer 
		// 2nd Parameter - whether the pipeline object is graphics pipeline or compute pipeline
		// 3rd Parameter - graphics pipeline
		vkCmdBindPipeline(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, graphicsPipeline);

		VkBuffer vertexBuffers[] = { VertexBuffer->buffer };
		VkBuffer instanceBuffers[] = { InstanceBuffer->buffer };
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffers[i], 0, 1, vertexBuffers, offsets);

		vkCmdBindVertexBuffers(commandBuffers[i], 1, 1, instanceBuffers, offsets);

		vkCmdBindIndexBuffer(commandBuffers[i], IndexBuffer->buffer, 0, VK_INDEX_TYPE_UINT32);

		// Draw the polygon - triangle
		// 1st Parameter - command buffer
		// 2nd Parameter - vertex count
		// 3rd Parameter - instance count
		// 4th Parameter - first vertex
		// 5th Parameter - first instance
		//vkCmdDraw(commandBuffers[i], static_cast<uint32_t>(vertices.size()), 1, 0, 0);

		vkCmdBindDescriptorSets(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout, 0, 1, &descriptorSets[i], 0, nullptr);
		vkCmdDrawIndexed(commandBuffers[i], static_cast<uint32_t>(m.indices.size()), pow(10, uiParams.noOfButterflies), 0, 0, 0);

		// Move to next subpass
		vkCmdNextSubpass(commandBuffers[i], VK_SUBPASS_CONTENTS_INLINE);

		// Render the Quad
		if (true)
		{
			VkBuffer quadVertexBuffers[] = { quadVertexBuffer->buffer };

			vkCmdBindDescriptorSets(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, quadPipelineLayout, 0, 1, &quadDescriptorSets[i], 0, nullptr);

			vkCmdBindVertexBuffers(commandBuffers[i], 0, 1, quadVertexBuffers, offsets);

			vkCmdBindIndexBuffer(commandBuffers[i], quadIndexBuffer->buffer, 0, VK_INDEX_TYPE_UINT32);

			vkCmdBindPipeline(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, quadGraphicsPipeline);

			// Draw the Quad
			vkCmdDrawIndexed(commandBuffers[i], static_cast<uint32_t>(QuadIndices.size()), 1, 0, 0, 0);
		}
		// End the render pass recording
		vkCmdEndRenderPass(commandBuffers[i]);

		// End the command buffer recording
		if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS) {
			// Throw runtime error exception as command buffer recording cannot be ended
			throw std::runtime_error("failed to record command buffer!");
		}
	}
}


// Function to create semaphores and fences
// Semaphores - A synchronization method where operations are synchronized within or across command queues
// Fences - A synchronization method where the entire application is synchronized with the rendering operation
void Application::createSyncObjects() {

	// Resize the collection of image available semaphores
	imageAvailableSemaphores.resize(MAX_FRAMES_IN_FLIGHT);

	// Resize the collection of render finished semaphores
	renderFinishedSemaphores.resize(MAX_FRAMES_IN_FLIGHT);

	// Resize the collection of in-flight fences
	inFlightFences.resize(MAX_FRAMES_IN_FLIGHT);

	// Resize the collection of images in-flight fences
	imagesInFlight.resize(swapChain->swapChainImages.size(), VK_NULL_HANDLE);


	// create info for semaphores
	VkSemaphoreCreateInfo semaphoreInfo = {};
	// Type of information stored in the structure
	semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

	// Create info for fences
	VkFenceCreateInfo fenceInfo = {};
	// Type of information stored in the strucuture
	fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	// Specify the flag to start the fences with signaled state
	fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

	// Create all the semaphores and fences
	for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
	{
		// Create semaphores and fences

		// Create the semaphores
		// 1st Parameter - GPU
		// 2nd Parameter - create info for semaphores
		// 3rd Parameter - Custom allocator
		// 4th Parameter - pointer to the created semaphore

		// Create the fence
		// 1st Parameter - GPU
		// 2nd Parameter - create info for fence
		// 3rd Parameter - Custom allocator
		// 4th Parameter - pointer to the created fence
		if (vkCreateSemaphore(device->logicalDevice, &semaphoreInfo, nullptr, &imageAvailableSemaphores[i]) != VK_SUCCESS ||
			vkCreateSemaphore(device->logicalDevice, &semaphoreInfo, nullptr, &renderFinishedSemaphores[i]) != VK_SUCCESS ||
			vkCreateFence(device->logicalDevice, &fenceInfo, nullptr, &inFlightFences[i]) != VK_SUCCESS) {
			// Any one or both the semaphore creation failed, so throw runtime error exception
			throw std::runtime_error("failed to create semaphores!");
		}
	}
}

// Function to check whether all the requested validation layers are available
// Validation layer - optional components hooked into Vulkan function calls to add validation check operations
bool Application::checkValidationLayerSupport() {

	// Find the number of available layers
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	// Find the list of all available layers
	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	// Loop through the requested validation layers
	for (const char* layerName : validationLayers) {

		// flag to set when the requested validation layer is there in the list of available validation layers
		bool layerFound = false;

		// Loop through all the available validation layers
		for (const auto& layerProperties : availableLayers) {

			// Compare the layer name of the requested layer and layer in available layers 
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				// The requested layer is there in the available layers list
				layerFound = true;
				break;
			}
		}

		if (!layerFound) {
			// The requested layer is not there in the available layers list
			return false;
		}
	}

	return true;
}

// Function that returns the list of extenstions based on whether validation layers are enabled or not
std::vector<const char*> Application::getRequiredExtensions() {

	// Stores the no of extensions
	uint32_t glfwExtensionCount = 0;

	// Stores the reference to the extensions
	const char** glfwExtensions;

	// GLFW function to fetch the extensions required
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	// A list of extensions
	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	// Check whether validation layers are enabled
	if (enableValidationLayers) {
		// Add Debug Utils Extension
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	// Return the extensions
	return extensions;
}

// Function to populate the Debug Messenger Create Info
void Application::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
	createInfo = {};
	// Specify the structure type
	createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	// Specify all types of severities for the callback
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	// Specify the types of messages for the callback to be called
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	// Pointer to the callback function to be called
	createInfo.pfnUserCallback = debugCallback;
}

// Debug callback function
// VKAPI_ATTR and VKAPI_CALL ensures the right signature for Vulkan to call it
// 1st Parameter - Severity of message - Diagnostic, Information, Warning or Error
// 2nd Parameter - Message Type - General, Validation or Performance
// 3rd Parameter - Contains the details of the message with members pMessage,pObjects and objectsCount
// 4th Parameter - Used to pass data
// Return value - Should the Vulkan call that triggered the validation layer message should be aborted
VKAPI_ATTR VkBool32 VKAPI_CALL Application::debugCallback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData) {

	// Print the validation error
	std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

	// Do not abort the Vulkan call that triggered the validation layer message
	return VK_FALSE;
}

// Function to read a file
std::vector<char> Application::readFile(const std::string& filename) {
	// Open the file as a binary and start reading at the end of file
	std::ifstream file(filename, std::ios::ate | std::ios::binary);

	// Check whether file opening failed
	if (!file.is_open()) {
		// Throw runtime error exception if file opening failed
		throw std::runtime_error("failed to open file!");
	}

	// Find the file size
	size_t fileSize = (size_t)file.tellg();

	// Initialize a buffer with file size
	std::vector<char> buffer(fileSize);

	// Seek to the beginning of the file
	file.seekg(0);

	// Read all the bytes
	file.read(buffer.data(), fileSize);

	// Close the file
	file.close();

	// Return the buffer
	return buffer;
}

// Function to create shader module
// This function takes byte code of the shader as paramter and returns the shader module
VkShaderModule Application::createShaderModule(const std::vector<char>& code) {
	// Create info for shader module
	VkShaderModuleCreateInfo createInfo = {};
	// Type of information stored in the structure
	createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	// Size of byte code
	createInfo.codeSize = code.size();
	// Assign the byte code. Cast it uint32_t pointer from char pointer
	createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

	// Create the shader module
	// 1st Parameter - GPU
	// 2nd Parameter - Create Info
	// 3rd Parameter - optional custom allocator
	// 4th Parameter - pointer to shader module
	VkShaderModule shaderModule;
	if (vkCreateShaderModule(device->logicalDevice, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
		// Throw runtime error exception as the shader module creation failed
		throw std::runtime_error("failed to create shader module!");
	}

	// Return shader module
	return shaderModule;
}

//////////////////////////
// Main Loop Functions //
////////////////////////

// Function to draw the frame on the screen
// Acquires the image from the swap chain and executes command buffer and returns the image to swap chain for presentation
void Application::drawFrame() {
	uiParams.peakWavelength = peakWavelengths[uiParams.IncidencAngleToVerify];
	imGui->DrawImGUI(device, DrawUI);

	// Wait for frame to finish
	vkWaitForFences(device->logicalDevice, 1, &inFlightFences[currentFrame], VK_TRUE, UINT64_MAX);

	// index of swap chain image
	uint32_t imageIndex;
	// Acquire image from swap chain
	// 1st Parameter - GPU
	// 2nd Parameter - Swap chain
	// 3rd Parameter - timeout in nanoseconds for an image to become available
	// 4th & 5th Parameter - synchronization object to signal when presentation engine used this image
	// 6th Parameter - index of swap chain image
	VkResult result = vkAcquireNextImageKHR(device->logicalDevice, swapChain->swapChain, UINT64_MAX, imageAvailableSemaphores[currentFrame], VK_NULL_HANDLE, &imageIndex);

	// Check whether swap chain has become incompatible with the surface
	if (result == VK_ERROR_OUT_OF_DATE_KHR) {
		// Recreate swap chain
		recreateSwapChain();
		return;
	}
	else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
		// Throw runtime error exception as acquiring image from swap chain failed
		throw std::runtime_error("failed to acquire swap chain image!");
	}

	// Check if a previous frame is using this image (i.e. there is its fence to wait on)
	if (imagesInFlight[imageIndex] != VK_NULL_HANDLE) {
		// Wait for the fences
		vkWaitForFences(device->logicalDevice, 1, &imagesInFlight[imageIndex], VK_TRUE, UINT64_MAX);
	}
	// Mark the image as now being in use by this frame
	imagesInFlight[imageIndex] = inFlightFences[currentFrame];

	// Update the uniform buffer to have the current model view projection matrices
	updateUniformBuffer(imageIndex);

	// Update the uniform buffer to have the current ambient, specular, diffuse values
	updateLightingConstants(imageIndex);

	imGui->RenderImGUI(device, swapChain->swapChainExtent, imageIndex);

	std::array<VkCommandBuffer, 2> submitCommandBuffers =
	{
		commandBuffers[imageIndex]
		,
		imGui->imGuiCommandBuffers[imageIndex]
	};

	// Submit info to submit to command buffer
	VkSubmitInfo submitInfo = {};
	// Type of information stored in the structure
	submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	// Semaphores to wait for
	VkSemaphore waitSemaphores[] = { imageAvailableSemaphores[currentFrame] };
	// Pipeline stage to wait
	VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
	// Set the no of semaphores
	submitInfo.waitSemaphoreCount = 1;
	// Set the semaphores to wait for
	submitInfo.pWaitSemaphores = waitSemaphores;
	// Set the stages to wait
	submitInfo.pWaitDstStageMask = waitStages;
	// Set the no of command buffers to submit
	submitInfo.commandBufferCount = static_cast<uint32_t>(submitCommandBuffers.size()); //1;
	// Set the pointer to command buffers to submit
	submitInfo.pCommandBuffers = submitCommandBuffers.data();// &commandBuffers[imageIndex];
	// Semaphores to signal after command buffer execution
	VkSemaphore signalSemaphores[] = { renderFinishedSemaphores[currentFrame] };
	// Set the no of semaphores to signal
	submitInfo.signalSemaphoreCount = 1;
	// Set the semaphores to signal
	submitInfo.pSignalSemaphores = signalSemaphores;

	// Reset the fence to unsignaled state
	vkResetFences(device->logicalDevice, 1, &inFlightFences[currentFrame]);

	// Submit the command buffer to graphics queue
	// 1st Parameter - graphics queue
	// 2nd Parameter - No of submit infos
	// 3rd Parameter - pointer to submit infos
	// 4th Parameter - optional fence signaled when command buffer is executed
	if (vkQueueSubmit(device->graphicsQueue, 1, &submitInfo, inFlightFences[currentFrame]) != VK_SUCCESS) {
		// Throw runtime error exception as the submission of command buffer to graphics queue failed
		throw std::runtime_error("failed to submit draw command buffer!");
	}

	// Configuring the presentation using present info
	VkPresentInfoKHR presentInfo = {};
	// Type of information stored in the structure
	presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
	// no of semaphores to wait for before presentation
	presentInfo.waitSemaphoreCount = 1;
	// semaphores to wait for before presentation
	presentInfo.pWaitSemaphores = signalSemaphores;
	// Array of swap chains
	VkSwapchainKHR swapChains[] = { swapChain->swapChain };
	// Set the no of swap chains
	presentInfo.swapchainCount = 1;
	// Specify the swap chains
	presentInfo.pSwapchains = swapChains;
	// Specify the index of image for each swap chain	
	presentInfo.pImageIndices = &imageIndex;
	// Result values to check in each swap chain
	presentInfo.pResults = nullptr;

	// Submit a request to present the image to swap chain
	result = vkQueuePresentKHR(device->presentQueue, &presentInfo);

	// Check whether the swap chain has become incompatible with the surface or the surface properties no longer match or frame buffer is resized
	if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || framebufferResized) {

		// Set frame buffer resized flag to false
		framebufferResized = false;

		// Recreate swap chain
		recreateSwapChain();
	}
	else if (result != VK_SUCCESS) {
		// Throw runtime error exception as request to present the image to swap chain failed
		throw std::runtime_error("failed to present swap chain image!");
	}

	// Update the current frame index
	currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT;
}

// Function to update uniform buffer values
void Application::updateUniformBuffer(uint32_t currentImage) {

	UniformBufferObject ubo = {};
	float mNow[16];
	Ball_Value(&objectBall, mNow);
	glm::mat4 rot = glm::make_mat4(mNow);// *glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	ubo.model = glm::scale(glm::mat4(1.0), glm::vec3(uiParams.scale / (float)pow(2, uiParams.prevnoOfButterflies))) *  glm::translate(glm::mat4(1.0f), glm::vec3(-10.0f, 0.0f + translate_x * 2, -15.0f + translate_y * 2))*rot;// glm::rotate(glm::mat4(1.0f), glm::radians(10.0f) * rotate_y, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(glm::mat4(1.0f), glm::radians(10.0f) * rotate_x, glm::vec3(0.0f, 0.0f, 1.0f)); //glm::scale(glm::mat4(1.0), glm::vec3(uiParams.scale)) *
	//ubo.view = glm::lookAt(glm::vec3(0.0f, -100.0f, 100.0f), glm::vec3(0.0f, 0.0f, 40.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	ubo.view = glm::lookAt(glm::vec3(85.0f, 2.0f, 100.0f), glm::vec3(0.0f, 0.0f, 40.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	ubo.proj = glm::perspective(glm::radians(45.0f), swapChain->swapChainExtent.width / (float)swapChain->swapChainExtent.height, 0.1f, 1000.0f);
	ubo.proj[1][1] *= -1;
	uniformBuffers[currentImage]->SetData(device, &ubo, sizeof(ubo));
}

// Function to update lighting constant values
void Application::updateLightingConstants(uint32_t currentImage) {
	LightingConstants lightConstants = m.lightingConstants;
	float mNow[16];
	Ball_Value(&lightBall, mNow);
	//glm::mat4 rot = glm::make_mat4(mNow);
	Matrix4 rot(mNow);
	lightConstants.lightSpecularExponent = uiParams.useMTLFile ? m.lightingConstants.lightSpecularExponent : uiParams.spectralExponent;
	lightConstants.ambientIntensity = uiParams.ambientIntensity;
	lightConstants.specularIntensity = uiParams.iridescenceIntensity;
	lightConstants.lightPosition = rot * Vec4{ 0.0, 10.0, 100.0, 1.0 };// glm::vec4(85.0f, 2.0f, 100.0f, 1.0)* rot;//;
	uiParams.lightPosition = lightConstants.lightPosition;
	lightConstants.transparency = uiParams.transparency;
	lightConstants.ambientEnabled = uiParams.ambientEnabled;
	lightConstants.specularEnabled = uiParams.specularEnabled;
	lightConstants.DiffuseEnabled = uiParams.iridescenceEnabled;
	lightConstants.useNormalMap = uiParams.useNormalMap;
	lightConstants.useOpacityMap = uiParams.useOpacityMap;
	lightingBuffers[currentImage]->SetData(device, &lightConstants, sizeof(lightConstants));
	iridescentBuffers[currentImage]->SetData(device, &iridescentColors, sizeof(iridescentColors));
}

// Function to recreate swap chain and other components when window is resized
void Application::recreateSwapChain() {

	// Get the width and height of the window to check whether it is minimized
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);
	// Check whether the window is minimized
	while (width == 0 || height == 0) {
		// Update the width and height
		glfwGetFramebufferSize(window, &width, &height);
		// Wait for the window to be maximized
		glfwWaitEvents();
	}
	// Wait for the device to complete its operations
	vkDeviceWaitIdle(device->logicalDevice);

	// Cleanup existing swap chain and dependent components
	cleanupSwapChain();

	swapChain = new Swapchain(device, window);

	// Create Render Pass
	createRenderPass();
	// Create Graphics pipeline
	createGraphicsPipeline();

	createQuadGraphicsPipeline();

	createDepthResources();

	// Create frame buffers
	createFramebuffers();

	//createComputeBuffers();

	createUniformBuffers();

	createDescriptorPool();

	createDescriptorSets();

	createQuadDescriptorPool();

	createQuadDescriptorSets();

	// Create command buffers
	createCommandBuffers();

	imGui->InitImGUI(&instance, window, device, swapChain, commandPool);
}

////////////////////////
// Cleanup Functions //
//////////////////////

// Cleanup function to destroy swap chain and related components
void Application::cleanupSwapChain() {

	// Destroy the depth image view, depth image and depth memory
	depthImage->Cleanup(device);

	// Destroy the frame buffers
	for (auto framebuffer : swapChainFramebuffers) {
		vkDestroyFramebuffer(device->logicalDevice, framebuffer, nullptr);
	}

	// Destroy the graphics pipeline
	vkDestroyPipeline(device->logicalDevice, graphicsPipeline, nullptr);

	// Destroy the pipeline layout
	vkDestroyPipelineLayout(device->logicalDevice, pipelineLayout, nullptr);

	// Destroy the graphics pipeline
	vkDestroyPipeline(device->logicalDevice, quadGraphicsPipeline, nullptr);

	// Destroy the pipeline layout
	vkDestroyPipelineLayout(device->logicalDevice, quadPipelineLayout, nullptr);

	// Destroy the render pass
	vkDestroyRenderPass(device->logicalDevice, renderPass, nullptr);

	swapChain->Cleanup(device);

	// Cleanup the uniform buffer and lighting constants buffer
	for (size_t i = 0; i < swapChain->swapChainImages.size(); i++) {

		uniformBuffers[i]->Cleanup(device);

		lightingBuffers[i]->Cleanup(device);
		iridescentBuffers[i]->Cleanup(device);
	}
	//SpectralParametersBuffer->Cleanup(device);
	//
	//ComputeBuffers->Cleanup(device);

	// Destroy the descriptor pool
	vkDestroyDescriptorPool(device->logicalDevice, descriptorPool, nullptr);


	// Destroy the descriptor pool
	vkDestroyDescriptorPool(device->logicalDevice, quadDescriptorPool, nullptr);

	imGui->CleanupImGUI(device);
}

// Function to create depth resources for depth buffer
void Application::createDepthResources() {
	VkFormat depthFormat = findDepthFormat();
	depthImage = new Image(device, swapChain->swapChainExtent.width, swapChain->swapChainExtent.height, depthFormat, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, VK_IMAGE_ASPECT_DEPTH_BIT, VK_IMAGE_TYPE_2D);
}

// Function to create the Graphics pipeline
	// Graphics Pipeline - Sequence of operations with vertices & textures as input and pixels to render as output
void Application::createComputePipeline() {
	// Fetch the byte code of compute shader
	auto computeShaderCode = readFile("shaders/Comp.spv");

	// Create compute shader module
	VkShaderModule computeShaderModule = createShaderModule(computeShaderCode);

	// compute shader stage create info
	VkPipelineShaderStageCreateInfo computeShaderStageInfo = {};
	// Type of information stored in the structure
	computeShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	// Specify the vertex shader stage in the pipeline
	computeShaderStageInfo.stage = VK_SHADER_STAGE_COMPUTE_BIT;
	// Specify the vertex shader module
	computeShaderStageInfo.module = computeShaderModule;
	// Specify the entry point
	computeShaderStageInfo.pName = "main";

	// Create an array to store vertex shader stage create info and fragment shader stage create info
	VkPipelineShaderStageCreateInfo shaderStages[] = { computeShaderStageInfo };

	// Pipeline layout create info
	// Pipeline layout - Uniform values/Push constants specified during pipeline creation
	VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
	// Type of information stored in the structure
	pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	// Number of uniforms
	pipelineLayoutInfo.setLayoutCount = 1;
	// Set the descriptor set layout
	pipelineLayoutInfo.pSetLayouts = &computeDescriptorSetLayout;
	// Number of push constants
	pipelineLayoutInfo.pushConstantRangeCount = 0;

	// Create the pipeline layout
	if (vkCreatePipelineLayout(device->logicalDevice, &pipelineLayoutInfo, nullptr, &computePipelineLayout) != VK_SUCCESS) {
		// Throw runtime error exception as pipeline layout creation failed
		throw std::runtime_error("failed to create pipeline layout!");
	}

	// Compute pipeline create info
	VkComputePipelineCreateInfo pipelineCreateInfo = {};
	pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
	pipelineCreateInfo.stage = computeShaderStageInfo;
	pipelineCreateInfo.layout = computePipelineLayout;

	// Create the compute pipeline
	// 1st Parameter - GPU
	// 2nd Parameter - Pipeline cache to store and reuse data for pipeline creation
	// 3rd Parameter - Pipeline create info
	// 4th Parameter - Custom allocator
	// 5th Parameter - Pointer to the created compute pipeline
	if (vkCreateComputePipelines(device->logicalDevice, VK_NULL_HANDLE, 1, &pipelineCreateInfo, nullptr, &ComputePipeline) != VK_SUCCESS) {
		// Throw runtime error exception as compute pipeline creation failed
		throw std::runtime_error("failed to create compute pipeline!");
	}

	// Destroy the compute shader module
	vkDestroyShaderModule(device->logicalDevice, computeShaderModule, nullptr);
}


// Function to create descriptor pool for compute pipeline to create descriptor sets
void Application::createComputeDescriptorPool() {

	std::array<VkDescriptorPoolSize, 2> poolSizes = {};
	poolSizes[0].type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	poolSizes[0].descriptorCount = 1;
	poolSizes[1].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	poolSizes[1].descriptorCount = 1;

	VkDescriptorPoolCreateInfo poolInfo = {};
	poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
	poolInfo.pPoolSizes = poolSizes.data();
	poolInfo.maxSets = 1;

	if (vkCreateDescriptorPool(device->logicalDevice, &poolInfo, nullptr, &computeDescriptorPool) != VK_SUCCESS) {
		throw std::runtime_error("failed to create descriptor pool!");
	}
}

// Function to create descriptor sets of compute pipeline for each Vk Buffer
void Application::createComputeDescriptorSet() {
	VkDescriptorSetAllocateInfo allocInfo = {};
	allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	allocInfo.descriptorPool = computeDescriptorPool;
	allocInfo.descriptorSetCount = 1;
	allocInfo.pSetLayouts = &computeDescriptorSetLayout;

	if (vkAllocateDescriptorSets(device->logicalDevice, &allocInfo, &computeDescriptorSet) != VK_SUCCESS) {
		throw std::runtime_error("failed to allocate descriptor sets!");
	}

	VkDescriptorBufferInfo ComputeBufferInfo = {};
	ComputeBufferInfo.buffer = ComputeBuffers->buffer;
	ComputeBufferInfo.offset = 0;
	ComputeBufferInfo.range = ComputeBufferSize;

	VkDescriptorBufferInfo spectralParametersBufferInfo = {};
	spectralParametersBufferInfo.buffer = SpectralParametersBuffer->buffer;
	spectralParametersBufferInfo.offset = 0;
	spectralParametersBufferInfo.range = sizeof(SpectralPipelineParameters);

	std::array<VkWriteDescriptorSet, 2> descriptorWrites = {};

	descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
	descriptorWrites[0].dstSet = computeDescriptorSet;
	descriptorWrites[0].dstBinding = 4;
	descriptorWrites[0].dstArrayElement = 0;
	descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	descriptorWrites[0].descriptorCount = 1;
	descriptorWrites[0].pBufferInfo = &ComputeBufferInfo;

	descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
	descriptorWrites[1].dstSet = computeDescriptorSet;
	descriptorWrites[1].dstBinding = 5;
	descriptorWrites[1].dstArrayElement = 0;
	descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	descriptorWrites[1].descriptorCount = 1;
	descriptorWrites[1].pBufferInfo = &spectralParametersBufferInfo;

	vkUpdateDescriptorSets(device->logicalDevice, static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
}

// function to create descriptor set layout for compute pipeline to  provide the details about descriptor bindings in every shader
void Application::createComputeDescriptorSetLayout() {

	VkDescriptorSetLayoutBinding ComputeLayoutBinding = {};
	ComputeLayoutBinding.binding = 4;
	ComputeLayoutBinding.descriptorCount = 1;
	ComputeLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	ComputeLayoutBinding.stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;

	VkDescriptorSetLayoutBinding SpectralParametersLayoutBinding = {};
	SpectralParametersLayoutBinding.binding = 5;
	SpectralParametersLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	SpectralParametersLayoutBinding.descriptorCount = 1;
	SpectralParametersLayoutBinding.stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;

	std::array<VkDescriptorSetLayoutBinding, 2> bindings = { ComputeLayoutBinding, SpectralParametersLayoutBinding };

	VkDescriptorSetLayoutCreateInfo layoutInfo = {};
	layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
	layoutInfo.pBindings = bindings.data();

	if (vkCreateDescriptorSetLayout(device->logicalDevice, &layoutInfo, nullptr, &computeDescriptorSetLayout) != VK_SUCCESS) {
		throw std::runtime_error("failed to create descriptor set layout!");
	}
}

// Function to create command pool for compute pipeline
	// Command Pool - Manage the memory used to store the buffers. Command buffers are allocated from Command Pools
void Application::createComputeCommandPool() {
	// Query the queue family indices
	QueueFamilyIndices queueFamilyIndices = device->findQueueFamilies();

	// Command pool create info
	VkCommandPoolCreateInfo poolInfo = {};
	// Type of information stored in the structure
	poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	// Specify the graphics queue family index as the commands are for drawing
	poolInfo.queueFamilyIndex = queueFamilyIndices.computeFamily.value();
	// Set the flag to zero as command buffers will be recorded only at the program start
	poolInfo.flags = 0; // Optional

	// Create command pool
	// 1st Parameter - GPU
	// 2nd Parameter - command pool create info
	// 3rd Parameter - Custom allocator
	// 4th Parameter - pointer to created command pool
	if (vkCreateCommandPool(device->logicalDevice, &poolInfo, nullptr, &computeCommandPool) != VK_SUCCESS) {
		// Throw runtime error exception as compute command pool creation failed
		throw std::runtime_error("failed to compute create command pool!");
	}
}

// Function to create Compute Uniform Buffers
void Application::createComputeBuffers() {

	VkDeviceSize bufferSize = ComputeBufferSize;

	ComputeBuffers = new Buffer(device, bufferSize, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	VkDeviceSize spectraBufferSize = sizeof(SpectralPipelineParameters);

	SpectralParametersBuffer = new Buffer(device, spectraBufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
}

// Function to create command buffers
	// Command Buffers - All drawing operations are recorded in a command buffer
void Application::createComputeCommandBuffers() {

	// Command Buffer Allocate Info
	VkCommandBufferAllocateInfo allocInfo = {};
	// Type of information stored in the structure
	allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	// Specify the command pool
	allocInfo.commandPool = computeCommandPool;
	// Specify the command buffer is primary command buffer - can be submitted to queue for execution, but cannot be called from another other command buffer
	allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	// Specify the no of buffers to allocate
	allocInfo.commandBufferCount = 1;

	// Allocate command buffers
	// 1st Parameter - GPU
	// 2nd Parameter - Command Buffer allocate info
	// 3rd Parameter - Pointer to Command Buffers
	if (vkAllocateCommandBuffers(device->logicalDevice, &allocInfo, &computeCommandBuffer) != VK_SUCCESS) {
		// Throw runtime error exception as allocation for command buffers failed
		throw std::runtime_error("failed to allocate command buffers!");
	}

	// Command buffer begin info to start command buffer recording
	VkCommandBufferBeginInfo beginInfo = {};
	// Type of information stored in the structure
	beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	// Specify how the command buffer is used
	beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT; // Optional
	// Specify which state to inherit from, in case of secondary command buffer
	beginInfo.pInheritanceInfo = nullptr; // Optional

	// Start record the command buffer
	// 1st Parameter - command buffer to start recording
	// 2nd Parameter - Begin info
	if (vkBeginCommandBuffer(computeCommandBuffer, &beginInfo) != VK_SUCCESS) {
		// Throw runtime error exception
		throw std::runtime_error("failed to begin recording command buffer!");
	}


	// Bind the graphics pipeline
	// 1st Parameter - command buffer 
	// 2nd Parameter - whether the pipeline object is graphics pipeline or compute pipeline
	// 3rd Parameter - graphics pipeline
	vkCmdBindPipeline(computeCommandBuffer, VK_PIPELINE_BIND_POINT_COMPUTE, ComputePipeline);


	vkCmdBindDescriptorSets(computeCommandBuffer, VK_PIPELINE_BIND_POINT_COMPUTE, computePipelineLayout, 0, 1, &computeDescriptorSet, 0, nullptr);

	int workgroups_x = (uint32_t)ceil(spectralParameters.textureWidth / float(32));
	int workgroups_y = (uint32_t)ceil(spectralParameters.textureHeight / float(32));
	vkCmdDispatch(computeCommandBuffer, workgroups_x, workgroups_y, 1);

	// End the command buffer recording
	if (vkEndCommandBuffer(computeCommandBuffer) != VK_SUCCESS) {
		// Throw runtime error exception as command buffer recording cannot be ended
		throw std::runtime_error("failed to record command buffer!");
	}

}

void Application::runComputeCommandBuffer() {
	/*
	Now we shall finally submit the recorded command buffer to a queue.
	*/

	VkSubmitInfo submitInfo = {};
	submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submitInfo.commandBufferCount = 1; // submit a single command buffer
	submitInfo.pCommandBuffers = &computeCommandBuffer; // the command buffer to submit.

	/*
	  We create a fence.
	*/
	VkFence fence;
	VkFenceCreateInfo fenceCreateInfo = {};
	fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	fenceCreateInfo.flags = 0;
	vkCreateFence(device->logicalDevice, &fenceCreateInfo, NULL, &fence);

	/*
	We submit the command buffer on the queue, at the same time giving a fence.
	*/
	vkQueueSubmit(device->computeQueue, 1, &submitInfo, fence);
	/*
	The command will not have finished executing until the fence is signalled.
	So we wait here.
	We will directly after this read our buffer from the GPU,
	and we will not be sure that the command has finished executing unless we wait for the fence.
	Hence, we use a fence here.
	*/
	vkWaitForFences(device->logicalDevice, 1, &fence, VK_TRUE, 100000000000);

	vkDestroyFence(device->logicalDevice, fence, NULL);
}

// Function to create texture image
void Application::createTextureImageFromComputeBuffer() {

	VkDeviceSize imageSize = spectralParameters.textureWidth*spectralParameters.textureHeight;

	void* mappedMemory = NULL;
	// Map the buffer memory, so that we can read from it on the CPU.
	vkMapMemory(device->logicalDevice, ComputeBuffers->memory, 0, ComputeBufferSize, 0, &mappedMemory);

	Pixel* pmappedMemory = (Pixel *)mappedMemory;

	std::vector<double> spectra;

	Vec3 xyz;
	Vec3 rgb;
	Vec3 outColor;
	int peakWavelengthIndex = 0;
	float peakWavelength = 0;
	peakWavelengths.clear();
	for (int i = 0; i < imageSize; i++) {
		double value = pmappedMemory[i].r;
		spectra.push_back(value);
		int j = i / (int)spectralParameters.textureWidth;

		if (peakWavelengthIndex == 0 || spectra[peakWavelengthIndex] < spectra[i % (int)spectralParameters.textureWidth])
		{
			peakWavelengthIndex = i % (int)spectralParameters.textureWidth;
			peakWavelength = pmappedMemory[i].b;
		}
		if (i % (int)spectralParameters.textureWidth == spectralParameters.textureWidth - 1)
		{
			xyz = GetXYZColorFromSpectra(spectra);
			rgb = ConvertXYZtoRGB(xyz);
			iridescentColors.colors[j].x = rgb.x;
			iridescentColors.colors[j].y = rgb.y;
			iridescentColors.colors[j].z = rgb.z;
			iridescentColors.colors[j].w = 1.0;

			peakWavelengths.push_back(peakWavelength);
			peakWavelength = 0;
			peakWavelengthIndex = 0;
			spectra.clear();
		}
	}
	spectra.clear();
	for (int i = 0; i < spectralParameters.noOfSpectralValues; i++) {
		double value = pmappedMemory[i].g;
		spectra.push_back(value);
	}
	xyz = GetXYZColorFromSpectra(spectra);
	rgb = ConvertXYZtoRGB(xyz);
	uiParams.outputLightColor = rgb;
	m.lightingConstants.lightAmbient = Vec4{ uiParams.inputLightColor.x, uiParams.inputLightColor.y, uiParams.inputLightColor.z, 1.0 };
	spectra.clear();

	// Done reading, so unmap.
	vkUnmapMemory(device->logicalDevice, ComputeBuffers->memory);

}

void Application::FindMatrixA()
{
	double minWavelength = 390.0;
	double maxWavelength = 790.0;
	double diffWavelength = maxWavelength - minWavelength;
	int n = 400;
	double del = (maxWavelength - minWavelength) / n;
	double k = 1;
	std::vector<double> vals;
	for (int i = 0; i < 9; i++)
	{
		vals.clear();
		for (int j = 0; j < n; j++)
		{
			double wavelength = minWavelength + j;
			double x, b;
			double angle = 2 * 3.14 * ((wavelength - minWavelength) / diffWavelength);
			Vec3 colorMatchFunc = ColorMatchingFunctionMap.at(wavelength);
			if (i / 3 == 0)
			{
				x = colorMatchFunc.x;
			}
			else if (i / 3 == 1)
			{
				x = colorMatchFunc.y;
			}
			else if (i / 3 == 2)
			{
				x = colorMatchFunc.z;
			}

			if (i % 3 == 0)
			{
				b = 1;
			}
			else if (i % 3 == 1)
			{
				b = cos(angle);
			}
			else if (i % 3 == 2)
			{
				b = sin(angle);
			}
			double val = x * b;
			vals.push_back(val);
		}
		double integralValue = MathHelper::IntegrateValues(vals);
		AMatrix.values[i / 3][i % 3] = k * integralValue;
	}
}

// Function to create texture image
void Application::ReadColorMatchingXMLFile(const char* filename) {

	int texWidth, texHeight, texChannels;

	std::ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile.is_open())
	{
		throw std::runtime_error("failed to open obj file!");
	}

	std::string tempString = "";

	//Read the header
	int tempInt = 0;


	while (tempString != "<Record>")
	{
		inputFile.ignore(200, '\n');
		inputFile >> tempString;
	}

	while (tempString != "</Records>")
	{
		double key = 0.0;
		double x, y, z;
		inputFile >> tempString;
		int startIndex = tempString.find('>');
		int lastIndex = tempString.find_last_of('<');
		std::string valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		key = std::stod(valString);

		inputFile >> tempString;
		startIndex = tempString.find('>');
		lastIndex = tempString.find_last_of('<');
		valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		x = std::stod(valString);

		inputFile >> tempString;
		startIndex = tempString.find('>');
		lastIndex = tempString.find_last_of('<');
		valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		y = std::stod(valString);

		inputFile >> tempString;
		startIndex = tempString.find('>');
		lastIndex = tempString.find_last_of('<');
		valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		z = std::stod(valString);

		Vec3 ColorMatchValue = { x,y,z };
		ColorMatchingFunctionMap.emplace(key, ColorMatchValue);
		inputFile >> tempString;
		inputFile >> tempString;
	}

	inputFile.close();
}

// Function to create texture image
void Application::ReadChromaticityXMLFile(const char* filename) {

	int texWidth, texHeight, texChannels;
	Vec3 White = { 0.31271 ,0.32902 ,0.35827 };
	Vec3 VioletVec = { 0.71819 ,0.28181 ,0.0 };
	std::ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile.is_open())
	{
		throw std::runtime_error("failed to open obj file!");
	}

	std::string tempString = "";

	//Read the header
	int tempInt = 0;


	while (tempString != "<Record>")
	{
		inputFile.ignore(200, '\n');
		inputFile >> tempString;
	}

	while (tempString != "</Records>")
	{
		std::string key = "";
		double x, y, z;
		double wavelength;
		inputFile >> tempString;
		int startIndex = tempString.find('>');
		int lastIndex = tempString.find_last_of('<');
		std::string valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		wavelength = std::stod(valString);

		inputFile >> tempString;
		startIndex = tempString.find('>');
		lastIndex = tempString.find_last_of('<');
		valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		x = std::stod(valString);

		inputFile >> tempString;
		startIndex = tempString.find('>');
		lastIndex = tempString.find_last_of('<');
		valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		y = std::stod(valString);

		inputFile >> tempString;
		startIndex = tempString.find('>');
		lastIndex = tempString.find_last_of('<');
		valString = tempString.substr(startIndex + 1, lastIndex - startIndex - 1);
		z = std::stod(valString);

		Vec3 Coord = { x,y,z };
		double hue = getHueFromXYZ(Coord);
		key = std::to_string((double)hue);
		key = key.substr(0, key.find('.') + 3);
		//Vec3 vec1 = White - Coord;
		//if (HueAngleWavelengthMap.size() == 0)
		//{
		//	//VioletVec = vec1;
		//	key = 0.0;
		//}
		//else
		//{
		//	key = VioletVec.Angle(&vec1);
		//}
		HueAngleWavelengthMap.emplace(key, wavelength);
		HueAngleCoordMap.emplace(key, Coord);
		inputFile >> tempString;
		inputFile >> tempString;
	}

	inputFile.close();
}

Vec3 Application::ConvertRGBtoXYZ(Vec3 colorInRGB)
{
	Vec3 XYZ;
	Matrix3 M;
	M.values[0][0] = 0.412453;
	M.values[0][1] = 0.357580;
	M.values[0][2] = 0.180423;
	M.values[1][0] = 0.212671;
	M.values[1][1] = 0.715160;
	M.values[1][2] = 0.072169;
	M.values[2][0] = 0.019334;
	M.values[2][1] = 0.119193;
	M.values[2][2] = 0.950227;
	XYZ = M * colorInRGB;

	return XYZ;
}

Vec3 Application::ConvertRGBtoHSV(Vec3 colorInRGB)
{
	Vec3 HSV;
	double max = std::max(std::max(colorInRGB.x, colorInRGB.y), colorInRGB.z);
	double min = std::min(std::min(colorInRGB.x, colorInRGB.y), colorInRGB.z);
	HSV.z = (max + min) / 2.0;
	HSV.y = max != 0.0 ? (max - min) / (max) : 0.0;// (max - min) / (2.0 - (max + min));// (max != 0.0) ? ((max - min) / max) : 0.0;
	if (HSV.y == 0.0)
		HSV.x = 0.0;
	else
	{
		double delta = max - min;
		if (colorInRGB.x == max)
			HSV.x = (colorInRGB.y - colorInRGB.z) / delta;
		else if (colorInRGB.y == max)
			HSV.x = 2.0 + (colorInRGB.z - colorInRGB.x) / delta;
		else if (colorInRGB.z == max)
			HSV.x = 4.0 + (colorInRGB.x - colorInRGB.y) / delta;

		HSV.x *= 60.0;
		if (HSV.x < 0.0)
			HSV.x += 360.0;
	}

	return HSV;
}

Vec3 Application::ConvertXYZtoRGB(Vec3 colorInXYZ)
{
	Vec3 RGB;
	Matrix3 M;
	M.values[0][0] = 0.4124564;
	M.values[0][1] = 0.3575761;
	M.values[0][2] = 0.1804375;
	M.values[1][0] = 0.2126729;
	M.values[1][1] = 0.7151522;
	M.values[1][2] = 0.0721750;
	M.values[2][0] = 0.0193339;
	M.values[2][1] = 0.1191920;
	M.values[2][2] = 0.9503041;
	RGB = M.Inverse() * colorInXYZ;
	RGB.x = RGB.x < 0.0 ? 0.0 : RGB.x;
	RGB.y = RGB.y < 0.0 ? 0.0 : RGB.y;
	RGB.z = RGB.z < 0.0 ? 0.0 : RGB.z;
	RGB.x = RGB.x > 1.0 ? 1.0 : RGB.x;
	RGB.y = RGB.y > 1.0 ? 1.0 : RGB.y;
	RGB.z = RGB.z > 1.0 ? 1.0 : RGB.z;
	//double sum = RGB.x + RGB.y + RGB.z;
	//if (sum != 0 && sum > 1.0)
	//{
	//	RGB.x = RGB.x / sum;// (x + y + z);
	//	RGB.y = RGB.y / sum;// (x + y + z);
	//	RGB.z = RGB.z / sum;// (x + y + z);
	//}


	return RGB;
}


void Application::FindFourierCoefficients(Vec3 colorInXYZ)
{
	Matrix3 AInverse = AMatrix.Inverse();
	FourierCoeffs = AInverse * colorInXYZ;
}

std::vector<double> Application::ConstructSpectra()
{
	double minWavelength = 390.0;
	double maxWavelength = 790.0;
	double diffWavelength = maxWavelength - minWavelength;
	int n = 400;
	double del = (maxWavelength - minWavelength) / n;

	std::vector<double> vals;
	for (int j = 0; j < n; j++)
	{
		double wavelength = minWavelength + j * del;

		double angle = 2 * 3.14 * ((wavelength - minWavelength) / diffWavelength);
		double val = FourierCoeffs.x + FourierCoeffs.y * cos(angle) + FourierCoeffs.z * sin(angle);
		vals.push_back(val);
	}
	return vals;
}

Vec3 Application::GetXYZColorFromSpectra(std::vector<double> spectra)
{
	double minWavelength = uiParams.minWavelength;
	double maxWavelength = uiParams.maxWavelength;
	double diffWavelength = maxWavelength - minWavelength;
	int n = uiParams.noOfSpectralValues;// *diffWavelength;
	double del = (maxWavelength - minWavelength) / n;
	double k = 1;
	std::vector<double> xvals, yvals, zvals;
	for (int j = 0; j < n; j++)
	{
		double wavelength = minWavelength + j * del;
		Vec3 colorMatchValue;
		if (ColorMatchingFunctionMap.count(wavelength) > 0)
			colorMatchValue = ColorMatchingFunctionMap.at(wavelength);
		else
			colorMatchValue = ColorMatchingFunctionMap.lower_bound(wavelength)->second;
		double val = spectra[j] * colorMatchValue.x;
		xvals.push_back(val);
		val = spectra[j] * colorMatchValue.y;
		yvals.push_back(val);
		val = spectra[j] * colorMatchValue.z;
		zvals.push_back(val);
	}
	double x = k * MathHelper::IntegrateValues(xvals);
	double y = k * MathHelper::IntegrateValues(yvals);
	double z = k * MathHelper::IntegrateValues(zvals);
	double sum = x + y + z;
	//if (sum != 0 && sum > 1.0)
	//{
	//	x = x / sum;// (x + y + z);
	//	y = y / sum;// (x + y + z);
	//	z = z / sum;// (x + y + z);
	//	//z = 1 - x - y;
	//}
	//z = 1 - x - y;
	return { (float)x,(float)y,(float)z };
}

std::vector<double> Application::ConstructSpectraGaussian(Vec3 hsv)
{
	std::string key = std::to_string((double)hsv.x);
	key = key.substr(0, key.find('.') + 3);
	double dominantWavelength;
	if (HueAngleWavelengthMap.count(key) <= 0)
	{
		key = std::to_string((int)hsv.x);
		dominantWavelength = HueAngleWavelengthMap.lower_bound(key)->second;
	}
	else
		dominantWavelength = HueAngleWavelengthMap.at(key);
	double minWidth = 5.0;
	double maxWidth = 74.0;
	double width = hsv.y * minWidth + (1 - hsv.y) * maxWidth;
	double minWavelength = 390.0;
	double maxWavelength = 790.0;
	double h = hsv.z;
	int n = 400;
	double del = (maxWavelength - minWavelength) / n;

	std::vector<double> vals;
	for (int j = 0; j < n; j++)
	{
		double wavelength = minWavelength + j * del;
		double wavelengthDiff = (wavelength - dominantWavelength);
		double pow = -1 * (wavelengthDiff * wavelengthDiff) / (2 * width * width);
		double val = exp(pow);
		//val = val > std::numeric_limits<double>::max() ? std::numeric_limits<double>::max() : val;
		//val = val < std::numeric_limits<double>::min() ? std::numeric_limits<double>::min() : val;
		//val = val < 0 ? 0 : val;
		vals.push_back(val);
	}
	return vals;
}

void Application::UpdateSpectralParameters()
{
	Vec3 colorInXyz = ConvertRGBtoXYZ(uiParams.inputLightColor);

	FindFourierCoefficients(colorInXyz);

	Vec3 hsv;
	hsv.x = colorInXyz.x / (colorInXyz.x + colorInXyz.y + colorInXyz.z);
	hsv.y = colorInXyz.y / (colorInXyz.x + colorInXyz.y + colorInXyz.z);
	hsv.z = colorInXyz.z / (colorInXyz.x + colorInXyz.y + colorInXyz.z);
	hsv = ConvertXYZtoHSV(hsv);
	hsv.y = hsv.y > 1.0 ? 1.0 : hsv.y;
	std::string key = std::to_string((double)hsv.x);
	key = key.substr(0, key.find('.') + 3);
	double dominantWavelength;
	if (HueAngleWavelengthMap.count(key) <= 0)
	{
		key = std::to_string((int)hsv.x);
		dominantWavelength = HueAngleWavelengthMap.lower_bound(key)->second;
	}
	else
		dominantWavelength = HueAngleWavelengthMap.at(key);


	spectralParameters.textureHeight = 90.0;
	spectralParameters.textureWidth = uiParams.noOfSpectralValues;
	spectralParameters.maxSpectralValue = 1.0;// To do: Get from UI
	spectralParameters.FourierCoefficients = FourierCoeffs;
	spectralParameters.dominantWavelength = dominantWavelength;
	spectralParameters.gaussianMaxWidth = uiParams.gaussianMaxWidth;
	spectralParameters.gaussianMinWidth = uiParams.gaussianMinWidth;
	spectralParameters.hybridThreshold = uiParams.hybridThreshold;
	spectralParameters.maxWavelength = uiParams.maxWavelength;
	spectralParameters.minWavelength = uiParams.minWavelength;
	spectralParameters.noOfSpectralValues = uiParams.noOfSpectralValues;
	spectralParameters.saturation = hsv.y;
	spectralParameters.filmDensity = uiParams.filmDensity;
	spectralParameters.airDensity = uiParams.airDensity;
	spectralParameters.filmIOR = uiParams.filmIOR;
	spectralParameters.airIOR = uiParams.airIOR;
	spectralParameters.interferencePower = uiParams.interferencePower;
	spectralParameters.interferenceConstant = uiParams.interferenceConstant;

	SpectralParametersBuffer->SetData(device, &spectralParameters, sizeof(spectralParameters));
}

std::vector<double> Application::ConstructIridescentSpectra(std::vector<double> inputSpectra)
{
	std::vector<double> iridescentSpectra;
	double theta = 158.0 *(3.14 / 180.0);
	double filmDensity = 150.0;// 90.0;
	double airDensity = 100.0;// 90.0;
	double filmIOR = 1.50;// 1.56;

	// Snell's law
	double theta_1 = asin(sin(theta) / filmIOR);

	double val = 4 * 3.14 * (filmIOR * filmDensity * cos(theta_1) + airDensity * cos(theta));
	double delB = 0.0;
	double minWavelength = 390.0;
	double maxWavelength = 790.0;
	int n = inputSpectra.size();
	double del = (maxWavelength - minWavelength) / n;
	double interferencePower = 3;
	double m = 8;
	for (int i = 0; i < n; i++)
	{
		double wavelength = minWavelength + i * del;
		delB = (val / wavelength);// *(3.14 / 180.0);
		double cosDelB = cos(delB);
		double R = 0.0;
		if (cosDelB > 0)
			R = inputSpectra[i] * interferencePower * pow(cosDelB, m);

		iridescentSpectra.push_back(R);
	}

	return iridescentSpectra;
}

Vec3 Application::ConvertXYZtoHSV(Vec3 colorInXYZ)
{
	Vec3 hsv;
	Vec3 White = { 0.31271 ,0.32902 ,0.35827 };
	//Vec3 White = { 0.33 ,0.33 ,0.33 };
	Vec3 VioletVec = { 0.16638 ,0.01830 ,0.81532 };
	Vec3 dominantWavelengthCoord;
	Vec3 vec1 = White - colorInXYZ;
	Vec3 vec2 = White - VioletVec;
	if (vec1.Magnitude() == 0)
		hsv.x = 0;
	else
		hsv.x = vec1.Angle(&vec2);
	std::string key = std::to_string((double)hsv.x);
	key = key.substr(0, key.find('.') + 3);

	if (HueAngleCoordMap.count(key) <= 0)
	{
		key = std::to_string((int)hsv.x);
		dominantWavelengthCoord = HueAngleCoordMap.lower_bound(key)->second;
	}
	else
		dominantWavelengthCoord = HueAngleCoordMap.at(key);

	Vec3 vec3 = White - dominantWavelengthCoord;
	hsv.y = vec1.Magnitude() / vec3.Magnitude();
	hsv.z = 0.0;
	return hsv;
}

double Application::getHueFromXYZ(Vec3 colorInXYZ)
{
	Vec3 White = { 0.31271 ,0.32902 ,0.35827 };
	//Vec3 White = { 0.33 ,0.33 ,0.33 };
	Vec3 VioletVec = { 0.16638 ,0.01830 ,0.81532 };

	Vec3 vec1 = White - colorInXYZ;
	Vec3 vec2 = White - VioletVec;

	return vec1.Angle(&vec2);
}

void Application::prepareInstanceData()
{
	std::vector<InstanceData> instanceData;
	int noOfButterflies = pow(10, uiParams.noOfButterflies);
	instanceData.resize(noOfButterflies);

	int random = 0;
	for (auto i = 0; noOfButterflies != 1 && i < noOfButterflies; i++) {
		float x = (float)(rand() % 50 - 25);
		float y = (float)(rand() % 50 - 25);
		float z = (float)(rand() % 50 - 25);
		instanceData[i].instancePosition = Vec3{ x, y, z };
		instanceData[i].scale = 1.0 / 10.0;// (float)noOfButterflies;
		x = (float)(rand() % 50 - 25);
		y = (float)(rand() % 50 - 25);
		z = (float)(rand() % 50 - 25);
		instanceData[i].rotation = Vec3{ x, y, z };
	}


	InstanceBuffer->SetData(device, instanceData.data(), instanceData.size() * sizeof(InstanceData));

}

void Application::InitQuad()
{
	Vertex v;
	Vec3 pos;
	pos.x = -1.0;
	pos.y = -0.55;
	pos.z = 0;
	v.position = pos;

	Vec3 tex;
	tex.x = 0.0;
	tex.y = 1.0;
	v.tex = tex;

	Vertex v2;
	Vec3 pos2;
	pos2.x = -0.55;
	pos2.y = -0.55;
	pos2.z = 0;
	v2.position = pos2;

	Vec3 tex2;
	tex2.x = 1.0;
	tex2.y = 1.0;
	v2.tex = tex2;

	Vertex v3;
	Vec3 pos3;
	pos3.x = -1.0;
	pos3.y = -1.0;
	pos3.z = 0.0;
	v3.position = pos3;

	Vec3 tex3;
	tex3.x = 0.0;
	tex3.y = 0.0;
	v3.tex = tex3;

	Vertex v4;
	Vec3 pos4;
	pos4.x = -0.55;
	pos4.y = -1.0;
	pos4.z = 0;
	v4.position = pos4;


	Vec3 tex4;
	tex4.x = 1.0;
	tex4.y = 0.0;
	v4.tex = tex4;

	QuadVertices.push_back(v);
	QuadVertices.push_back(v2);
	QuadVertices.push_back(v3);
	QuadVertices.push_back(v4);

	QuadIndices.push_back(0);
	QuadIndices.push_back(1);
	QuadIndices.push_back(2);

	QuadIndices.push_back(2);
	QuadIndices.push_back(1);
	QuadIndices.push_back(3);

}

// Function to create the Graphics pipeline
// Graphics Pipeline - Sequence of operations with vertices & textures as input and pixels to render as output
void Application::createQuadGraphicsPipeline() {
	// Fetch the byte code of vertex shader
	auto vertShaderCode = readFile("shaders/quad_vert.spv");

	// Fetch the byte code of fragment shader
	auto fragShaderCode = readFile("shaders/quad_frag.spv");

	// Create Vertex shader module
	VkShaderModule vertShaderModule = createShaderModule(vertShaderCode);

	// Create Fragment shader module
	VkShaderModule fragShaderModule = createShaderModule(fragShaderCode);

	// Vertex shader stage create info
	VkPipelineShaderStageCreateInfo vertShaderStageInfo = {};
	// Type of information stored in the structure
	vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	// Specify the vertex shader stage in the pipeline
	vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
	// Specify the vertex shader module
	vertShaderStageInfo.module = vertShaderModule;
	// Specify the entry point
	vertShaderStageInfo.pName = "main";

	// Fragment shader stage create info
	VkPipelineShaderStageCreateInfo fragShaderStageInfo = {};
	// Type of information stored in the structure
	fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	// Specify the fragment shader stage in the pipeline
	fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
	// Specify the fragment shader module
	fragShaderStageInfo.module = fragShaderModule;
	// Specify the entry point
	fragShaderStageInfo.pName = "main";

	// Create an array to store vertex shader stage create info and fragment shader stage create info
	VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

	// Binding description
	auto bindingDescription = getBindingDescription();

	// Attribute description
	auto attributeDescriptions = getAttributeDescriptions();

	// Information of format of the vertex data passed to the vertex shader
	VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
	// Type of information stored in the structure
	vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	// Details for loading vertex data
	vertexInputInfo.vertexBindingDescriptionCount = static_cast<uint32_t>(bindingDescription.size());
	vertexInputInfo.pVertexBindingDescriptions = bindingDescription.data();
	vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
	vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();

	// Information of kind of geometry drawn
	VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
	// Type of information stored in the structure
	inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	// Specify kind of geometry drawn
	inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	// Specify that it is not possible to break lines and triangles by using special index
	inputAssembly.primitiveRestartEnable = VK_FALSE;

	// Viewport information
	// Viewport - region of framebuffer where the output will be rendereds
	VkViewport viewport = {};
	// starting x of viewport
	viewport.x = 0.0f;
	// starting y of viewport
	viewport.y = 0.0f;
	// width of viewport
	viewport.width = (float)swapChain->swapChainExtent.width;
	// height of viewport
	viewport.height = (float)swapChain->swapChainExtent.height;
	// min depth of viewport
	viewport.minDepth = 0.0f;
	// max depth of viewport
	viewport.maxDepth = 1.0f;

	// Scissor information
	// Scissor - a specification of the pixels that will be stored
	VkRect2D scissor = {};
	// Scissor offset
	scissor.offset = { 0, 0 };
	// Scissor extent
	scissor.extent = swapChain->swapChainExtent;

	// Viewport State create info
	VkPipelineViewportStateCreateInfo viewportState = {};
	// Type of information stored in the structure
	viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	// No of viewports
	viewportState.viewportCount = 1;
	// Specify the pointer to the viewports
	viewportState.pViewports = &viewport;
	// No of scissors
	viewportState.scissorCount = 1;
	// Specify the pointer to the scissors
	viewportState.pScissors = &scissor;

	// Rasterization State create info
	// Rasterizer - turns the geometry into fragments
	VkPipelineRasterizationStateCreateInfo rasterizer = {};
	// Type of information stored in the structure
	rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	// Specify whether the fragments beyond the near and far planes has to be clamped or discarded
	rasterizer.depthClampEnable = VK_FALSE;
	// Specify whether the geometry should pass through the rasterizer stage
	rasterizer.rasterizerDiscardEnable = VK_FALSE;
	// Specify how fragments are generated
	rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
	// Specify the thickness of the lines
	rasterizer.lineWidth = 1.0f;
	// Specify the type of culling to use
	rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
	// Specify the vertex order
	rasterizer.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
	// Should the rasterizer alter the depth values by adding a constant value or biasing them
	rasterizer.depthBiasEnable = VK_FALSE;
	rasterizer.depthBiasConstantFactor = 4.0f; // Optional
	rasterizer.depthBiasClamp = 0.0f; // Optional
	rasterizer.depthBiasSlopeFactor = 1.5f; // Optional

	// Information to configure multisampling to perform anti-aliasing
	VkPipelineMultisampleStateCreateInfo multisampling = {};
	// Type of information stored in the structure
	multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	multisampling.sampleShadingEnable = VK_FALSE;
	multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	multisampling.minSampleShading = 1.0f; // Optional
	multisampling.pSampleMask = nullptr; // Optional
	multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
	multisampling.alphaToOneEnable = VK_FALSE; // Optional

	VkPipelineDepthStencilStateCreateInfo depthStencil = {};
	depthStencil.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	depthStencil.depthTestEnable = VK_TRUE;
	depthStencil.depthWriteEnable = VK_TRUE;
	depthStencil.depthCompareOp = VK_COMPARE_OP_LESS;
	depthStencil.depthBoundsTestEnable = VK_FALSE;
	depthStencil.stencilTestEnable = VK_TRUE;

	// Colour blending configuration per attached framebuffer
	// Colour blending - way to combine with colour already in framebuffer
	VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
	colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	colorBlendAttachment.blendEnable = VK_FALSE;

	// Global colour blending setting information
	VkPipelineColorBlendStateCreateInfo colorBlending = {};
	// Type of information stored in the structure
	colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	colorBlending.logicOpEnable = VK_FALSE;
	colorBlending.logicOp = VK_LOGIC_OP_COPY;
	colorBlending.attachmentCount = 1;
	colorBlending.pAttachments = &colorBlendAttachment;
	colorBlending.blendConstants[0] = 0.0f;
	colorBlending.blendConstants[1] = 0.0f;
	colorBlending.blendConstants[2] = 0.0f;
	colorBlending.blendConstants[3] = 0.0f;

	// Dynamic states which can be changed without recreating the pipeline
	VkDynamicState dynamicStates[] = {
VK_DYNAMIC_STATE_VIEWPORT,
VK_DYNAMIC_STATE_LINE_WIDTH
	};

	// Dynamic state create info
	VkPipelineDynamicStateCreateInfo dynamicState = {};
	// Type of information stored in the structure
	dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	// No of dynamic states
	dynamicState.dynamicStateCount = 2;
	// Specify the array of dynamic states
	dynamicState.pDynamicStates = dynamicStates;

	// Pipeline layout create info
	// Pipeline layout - Uniform values/Push constants specified during pipeline creation
	VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
	// Type of information stored in the structure
	pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	// Number of uniforms
	pipelineLayoutInfo.setLayoutCount = 1;

	pipelineLayoutInfo.pSetLayouts = &quadDescriptorSetLayout;
	// Number of push constants
	pipelineLayoutInfo.pushConstantRangeCount = 0;

	// Create the pipeline layout
	if (vkCreatePipelineLayout(device->logicalDevice, &pipelineLayoutInfo, nullptr, &quadPipelineLayout) != VK_SUCCESS) {
		// Throw runtime error exception as pipeline layout creation failed
		throw std::runtime_error("failed to create pipeline layout!");
	}

	// Graphics pipeline create info
	VkGraphicsPipelineCreateInfo pipelineInfo = {};
	// Type of information stored in the structure
	pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	// No of shader stages
	pipelineInfo.stageCount = 2;
	// Pointer to shader stages
	pipelineInfo.pStages = shaderStages;
	// Specify the vertex input state
	pipelineInfo.pVertexInputState = &vertexInputInfo;
	// Specify the input assembly state
	pipelineInfo.pInputAssemblyState = &inputAssembly;
	// Specify the viewport state
	pipelineInfo.pViewportState = &viewportState;
	// Specify the rasterization state
	pipelineInfo.pRasterizationState = &rasterizer;
	// Specify the Multisampling state
	pipelineInfo.pMultisampleState = &multisampling;
	// Specify Depth stencil state
	pipelineInfo.pDepthStencilState = &depthStencil;
	// Specify the color blend state
	pipelineInfo.pColorBlendState = &colorBlending;
	// Specify the dynamic state
	pipelineInfo.pDynamicState = nullptr; // Optional
	// Specify the pipeline layout
	pipelineInfo.layout = quadPipelineLayout;
	// Specify the render pass
	pipelineInfo.renderPass = renderPass;
	// Specify the index of the render pass where this graphics pipeline will be used
	pipelineInfo.subpass = 1;
	// Specify the base pipeline to derive from
	pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
	// Specify the index of base pipeline to derive from
	pipelineInfo.basePipelineIndex = -1; // Optional

	// Create the graphics pipeline
	// 1st Parameter - GPU
	// 2nd Parameter - Pipeline cache to store and reuse data for pipeline creation
	// 3rd Parameter - Pipeline create info
	// 4th Parameter - Custom allocator
	// 5th Parameter - Pointer to the created graphics pipeline
	if (vkCreateGraphicsPipelines(device->logicalDevice, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &quadGraphicsPipeline) != VK_SUCCESS) {
		// Throw runtime error exception as graphics pipeline creation failed
		throw std::runtime_error("failed to create graphics pipeline!");
	}

	// Destroy the fragment shader module
	vkDestroyShaderModule(device->logicalDevice, fragShaderModule, nullptr);

	// Destroy the vertex shader module
	vkDestroyShaderModule(device->logicalDevice, vertShaderModule, nullptr);
}

// Function to create descriptor pool to create descriptor sets
void Application::createQuadDescriptorPool() {
	std::array<VkDescriptorPoolSize, 1> poolSizes = {};
	poolSizes[0].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	poolSizes[0].descriptorCount = static_cast<uint32_t>(swapChain->swapChainImages.size());

	VkDescriptorPoolCreateInfo poolInfo = {};
	poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
	poolInfo.pPoolSizes = poolSizes.data();
	poolInfo.maxSets = static_cast<uint32_t>(swapChain->swapChainImages.size());

	if (vkCreateDescriptorPool(device->logicalDevice, &poolInfo, nullptr, &quadDescriptorPool) != VK_SUCCESS) {
		throw std::runtime_error("failed to create descriptor pool!");
	}
}

// Function to create descriptor sets for each Vk Buffer
void Application::createQuadDescriptorSets() {
	std::vector<VkDescriptorSetLayout> layouts(swapChain->swapChainImages.size(), quadDescriptorSetLayout);
	VkDescriptorSetAllocateInfo allocInfo = {};
	allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	allocInfo.descriptorPool = quadDescriptorPool;
	allocInfo.descriptorSetCount = static_cast<uint32_t>(swapChain->swapChainImages.size());
	allocInfo.pSetLayouts = layouts.data();

	quadDescriptorSets.resize(swapChain->swapChainImages.size());
	if (vkAllocateDescriptorSets(device->logicalDevice, &allocInfo, quadDescriptorSets.data()) != VK_SUCCESS) {
		throw std::runtime_error("failed to allocate descriptor sets!");
	}

	for (size_t i = 0; i < swapChain->swapChainImages.size(); i++) {

		VkDescriptorImageInfo imageInfo = {};
		imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
		imageInfo.imageView = refImage->textureImage->imageView;
		imageInfo.sampler = refImage->textureSampler;

		std::array<VkWriteDescriptorSet, 1> descriptorWrites = {};

		descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[0].dstSet = quadDescriptorSets[i];
		descriptorWrites[0].dstBinding = 0;
		descriptorWrites[0].dstArrayElement = 0;
		descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorWrites[0].descriptorCount = 1;
		descriptorWrites[0].pImageInfo = &imageInfo;

		vkUpdateDescriptorSets(device->logicalDevice, static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
	}
}

// Function to create Index Buffer
void Application::createQuadIndexBuffer() {

	VkDeviceSize bufferSize = sizeof(int) * QuadIndices.size();

	Buffer *stagingBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	stagingBuffer->SetData(device, QuadIndices.data(), bufferSize);

	quadIndexBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

	quadIndexBuffer->copyBuffer(device, commandPool, stagingBuffer, bufferSize);

	stagingBuffer->Cleanup(device);
}

// Function to create Vertex Buffer
void Application::createQuadVertexBuffer() {


	VkDeviceSize bufferSize = sizeof(Vertex) * QuadVertices.size();

	Buffer *stagingBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	stagingBuffer->SetData(device, QuadVertices.data(), bufferSize);

	quadVertexBuffer = new Buffer(device, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

	quadVertexBuffer->copyBuffer(device, commandPool, stagingBuffer, bufferSize);

	stagingBuffer->Cleanup(device);

}

// function to create descriptor set layout to  provide the details about descriptor bindings in every shader
void Application::createQuadDescriptorSetLayout() {

	VkDescriptorSetLayoutBinding samplerLayoutBinding = {};
	samplerLayoutBinding.binding = 0;
	samplerLayoutBinding.descriptorCount = 1;
	samplerLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	samplerLayoutBinding.pImmutableSamplers = nullptr;
	samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

	std::array<VkDescriptorSetLayoutBinding, 1> bindings = { samplerLayoutBinding, };

	VkDescriptorSetLayoutCreateInfo layoutInfo = {};
	layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
	layoutInfo.pBindings = bindings.data();

	if (vkCreateDescriptorSetLayout(device->logicalDevice, &layoutInfo, nullptr, &quadDescriptorSetLayout) != VK_SUCCESS) {
		throw std::runtime_error("failed to create descriptor set layout!");
	}
}

