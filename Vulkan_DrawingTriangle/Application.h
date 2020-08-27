#pragma once

// Include Files
#include "Constants.h"
#include "Swapchain.h"
#include "Vertex.h"
#include "Buffer.h"
#include "CommandPool.h"
#include "TextureImage.h"
#include "ImGuiHelper.h"
#include "Dependencies\ImGUI\imgui.h"
#include "MathHelper.h"
#include <map>
#include <string>
#include "Ball.h"
#include <glm/gtc/type_ptr.hpp>
#include <cstdlib>

// Maximum no of frames processed concurrently
const int MAX_FRAMES_IN_FLIGHT = 2;

// Width and Height of the Window
const int WIDTH = 800;
const int HEIGHT = 600;


// Uniforms for model, view, projection transformations
struct UniformBufferObject {
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
};

// Spectral Paramters
struct SpectralPipelineParameters
{
	Vec3 FourierCoefficients;
	int textureWidth;
	int textureHeight;
	float maxSpectralValue;
	float minWavelength;
	float maxWavelength;
	int noOfSpectralValues;
	float dominantWavelength;
	float saturation;
	float gaussianMinWidth;
	float gaussianMaxWidth;
	float hybridThreshold;
	float filmDensity;
	float airDensity;
	float filmIOR;
	float airIOR;
	float interferencePower;
	float interferenceConstant;
};

// Uniform for Lighting Constants
struct LightingConstants
{
	Vec4 lightPosition;
	Vec4 lightAmbient;
	Vec4 lightDiffuse;
	Vec4 lightSpecular;
	float ambientIntensity;
	float specularIntensity;
	float diffuseIntensity;
	float lightSpecularExponent;
	float ambientEnabled = 1;
	float specularEnabled = 1;
	float DiffuseEnabled = 1;
	float textureEnabled = 1;
	float transparency;
	float useNormalMap;
	float useOpacityMap;
};

// Iridescent Colours for different angle of incidence
struct IridescentColors
{
	Vec4 colors[90];
};

// Pixel data of the image generated in the compute shader
struct Pixel {
	float r, g, b, a;
};

// Values of for UI elements
struct UIParameters
{
	Vec3 inputLightColor;
	Vec3 outputLightColor;
	float hybridThreshold;
	float minWavelength;
	float maxWavelength;
	int  noOfSpectralValues;
	float gaussianMinWidth;
	float gaussianMaxWidth;

	Vec3 previnputLightColor;
	float prevhybridThreshold;
	float prevminWavelength;
	float prevmaxWavelength;
	int  prevnoOfSpectralValues;
	float prevgaussianMinWidth;
	float prevgaussianMaxWidth;

	bool shouldRegenerateIridescentColours;
	float filmDensity;
	float airDensity;
	float filmIOR;
	float airIOR;
	float interferencePower;
	float interferenceConstant;
	int noOfButterflies;

	float prevfilmDensity;
	float prevairDensity;
	float prevfilmIOR;
	float prevairIOR;
	float previnterferencePower;
	float previnterferenceConstant;
	int prevnoOfButterflies;

	float scale;
	bool isMTLFileAvailable;
	bool useMTLFile;
	float spectralExponent;
	float ambientIntensity;
	float iridescenceIntensity;
	float transparency;
	bool iridescenceEnabled;
	bool specularEnabled;
	bool ambientEnabled;
	bool useNormalMap;
	bool useOpacityMap;
	Vec4 lightPosition;
	bool shouldUpdateNoOfButterflies;
	float peakWavelength;
	int IncidencAngleToVerify;
};

// Mesh
struct Mesh
{
	// Vertices of the mesh
	std::vector<Vertex> vertices;

	// Indices of the faces of the mesh
	std::vector<int> indices;

	// Lighting Constants of the mesh
	LightingConstants lightingConstants;
};

class Application
{
private:

	// Mesh loaded
	Mesh m;

	// Instance to GLFW Window
	GLFWwindow* window;

	// Vulkan Instance - Connection between the application and the Vulkan Library
	VkInstance instance;

	// Handle to manage the Debug Callback
	VkDebugUtilsMessengerEXT debugMessenger;

	// Device
	Device *device;

	// Handle to Swap chain
	Swapchain *swapChain;

	// Handle to ImGUI elements
	ImGuiHelper *imGui;
	
	// Render pass
	VkRenderPass renderPass;

	// Descriptor Set Layout
	VkDescriptorSetLayout descriptorSetLayout;

	// Pipeline layout - uniforms
	VkPipelineLayout pipelineLayout;

	// Graphics pipeline
	VkPipeline graphicsPipeline;
	
	// Swap chain frame buffers
	std::vector<VkFramebuffer> swapChainFramebuffers;

	// Command Pool
	CommandPool *commandPool;

	// Vertex Buffer
	Buffer *VertexBuffer;

	// Instance Buffer to generate many copies of the mesh
	Buffer *InstanceBuffer;

	// Index Buffer
	Buffer *IndexBuffer;
	
	// Uniform Buffers
	std::vector<Buffer*> uniformBuffers;

	// Lighting Buffers
	std::vector<Buffer*> lightingBuffers;

	// Lighting Buffers
	std::vector<Buffer*> iridescentBuffers;

	Buffer *SpectralParametersBuffer;

	// Descriptor Pool to create descriptor sets
	VkDescriptorPool descriptorPool;

	// Descriptor sets to bind each VkBuffer to the uniform buffer descriptor
	std::vector<VkDescriptorSet> descriptorSets;

	// Texture Image
	TextureImage *opacityImage;

	// Normal Image
	TextureImage *normalImage;

	// Depth Image
	Image *depthImage;
	
	// Command Buffers
	std::vector<VkCommandBuffer> commandBuffers;

	// Semaphores to signal image is acquired for rendering
	std::vector<VkSemaphore> imageAvailableSemaphores;

	// Semaphores to signal rendering is complete and presentation can start
	std::vector<VkSemaphore> renderFinishedSemaphores;

	// Fences to prevent from more than Max frames getting submitted
	std::vector<VkFence> inFlightFences;

	// Fences to prevent images in flight getting rendered
	std::vector<VkFence> imagesInFlight;

	// Index of current frame
	size_t currentFrame = 0;

	// Flag to indicate whether frame buffer is resized due to window resizing
	bool framebufferResized = false;

	// Current translation and last translation values
	GLfloat translate_x, translate_y;
	GLfloat last_x, last_y;

	// Current rotation and last rotation values
	GLfloat rotate_x, rotate_y;
	GLfloat last_rotate_x, last_rotate_y;

	// Current Width and Heigth
	GLfloat width = WIDTH, height = HEIGHT;

	// Descriptor Set Layout for Compute Pipeline
	VkDescriptorSetLayout computeDescriptorSetLayout;

	// Pipeline layout - compute pipeline
	VkPipelineLayout computePipelineLayout;

	// Compute pipeline
	VkPipeline ComputePipeline;

	// Command Pool
	VkCommandPool computeCommandPool;

	// Descriptor Pool to create descriptor sets in compute pipeline
	VkDescriptorPool computeDescriptorPool;

	// Descriptor sets to bind each VkBuffer to descriptor for compute pipeline
	VkDescriptorSet computeDescriptorSet;

	// Compute Command Buffers
	VkCommandBuffer computeCommandBuffer;

	// Buffers for compute pipeline
	Buffer *ComputeBuffers;

	// Buffer size for compute pipeline
	uint32_t ComputeBufferSize; // size of buffer in bytes.

	// Map of wavelength and colour matching functions
	std::map<double, Vec3> ColorMatchingFunctionMap;

	// Map of hue angle and wavelength
	std::map<std::string, double> HueAngleWavelengthMap;

	// Map of hue angle and chromaticity coordinates
	std::map<std::string, Vec3> HueAngleCoordMap;

	// Fourier Matrix
	Matrix3 FourierMatrix;

	// Fourier Coefficients
	Vec3 FourierCoeffs;

	// Spectral Parameters value
	SpectralPipelineParameters spectralParameters;

	// Iridescent colours generated in the compute shader
	IridescentColors iridescentColors;

	// arcball for storing light rotation
	BallData lightBall;

	// arcball for storing object rotation
	BallData objectBall;

	// Bool to check whether mouse is currently in drag event
	bool isMouseDragged;

	// variable to specify which button is clicked now
	int whichButton;

	// Vertices for Quad
	std::vector<Vertex> QuadVertices;

	// Indices for Quad
	std::vector<int> QuadIndices;

	// Descriptor Set Layout
	VkDescriptorSetLayout quadDescriptorSetLayout;

	// Quad Pipeline layout - uniforms
	VkPipelineLayout quadPipelineLayout;

	// Quad Graphics pipeline
	VkPipeline quadGraphicsPipeline;

	// Quad Vertex Buffer
	Buffer *quadVertexBuffer;

	// Quad Index Buffer
	Buffer *quadIndexBuffer;

	// Descriptor Pool to create descriptor sets for quad pipeline
	VkDescriptorPool quadDescriptorPool;

	// Descriptor sets to bind each VkBuffer to the uniform buffer descriptor of quad pipeline
	std::vector<VkDescriptorSet> quadDescriptorSets;

	// Reference Image
	TextureImage *refImage;

	// Collection of peak wavelengths
	std::vector<float> peakWavelengths;

public:
	
	// Value of GUI elements
	static UIParameters uiParams;
	
	// Constructor
	Application();
	
	// Destructor
	~Application();

	// run functions
	void run();

	// Function to initialize the window
	void initWindow();

	// Function to initialize the Vulkan API
	void initVulkan();

	// Main Loop functions that is run in every frame
	void mainLoop();

	// Cleanup function to destroy all elements
	void cleanup();

	// Function to handle window resize
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
	
	// Function callback for mouse click
	static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	
	// Function callback for mouse position change
	static void cursor_position_callback(GLFWwindow* window, double x, double y);
	
	// Function callback for keyboard keys
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	// Function to create Vulkan Instance
	void createInstance();

	// Function to setup debug messenger
	void setupDebugMessenger();

	// To create render pass
	void createRenderPass();

	// To create main graphics pipeline
	void createGraphicsPipeline();

	// Creating frame buffers
	void createFramebuffers();

	// Function to create depth resources
	void createDepthResources();

	// Function to find the format of depth image
	VkFormat findDepthFormat();

	// Function to find the format supported for a config
	VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

	// Functions to create descriptor sets
	void createDescriptorPool();
	void createDescriptorSets();
	void createDescriptorSetLayout();

	// Function to create uniform buffer
	void createUniformBuffers();

	// Function to create index buffer
	void createIndexBuffer();

	// Function to create vertex buffer
	void createVertexBuffer();

	// Function to parse a obj file
	Mesh ParseObjFile(const char* filename);

	// Function to load properties from a MTL file
	LightingConstants LoadMaterial(const char* filename);
	
	// Function to create command buffers
	void createCommandBuffers();

	// Function to create synchronisation objects
	void createSyncObjects();

	// Function to check whether validation layers are supported
	bool checkValidationLayerSupport();

	// Function to fetch the extensions
	std::vector<const char*> getRequiredExtensions();

	// Function to populate the debug messenger info
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	// Callback function for debug message
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);

	// Function to read a file
	static std::vector<char> readFile(const std::string& filename);

	// Function to create a shader file
	VkShaderModule createShaderModule(const std::vector<char>& code);

	// Function to submit a command buffer to queue
	void drawFrame();

	// Function to update the uniform buffer values
	void updateUniformBuffer(uint32_t currentImage);

	// Function to update light parameter values
	void updateLightingConstants(uint32_t currentImage);

	// Function to recreate the swap chain and related elements
	void recreateSwapChain();

	// Function to destroy swap chain and related elements
	void cleanupSwapChain();

	// Function to create a compute pipeline
	void createComputePipeline();

	//function to create descriptor sets for compute pipeline to  provide the details about descriptor bindings in every shader
	void createComputeDescriptorSet();
	void createComputeDescriptorPool();

	// function to create descriptor set layout for compute pipeline to  provide the details about descriptor bindings in every shader
	void createComputeDescriptorSetLayout();

	// Functions to create compute command buffers
	void createComputeCommandPool();
	void createComputeCommandBuffers();

	// Function to create buffers used in compute pipeline
	void createComputeBuffers();

	// Function to run the compute command buffer
	void runComputeCommandBuffer();

	// Function to fetch the iridescent colours from the generated iridescent spectra
	void FetchIridescentColoursFromSpectra();

	// Function to calculate the fourier matrix
	void FindFourierMatrix();

	// Function to read the colour matching functions file
	void ReadColorMatchingXMLFile(const char* filename);

	// Function to compute fourier coefficients
	void FindFourierCoefficients(Vec3 colorInXYZ);

	// Function to get the XYZ colour from a spectra
	Vec3 GetXYZColorFromSpectra(std::vector<double> spectra);

	// Function to read the chromaticity coordinates file
	void ReadChromaticityXMLFile(const char* filename);

	// Conversion functions
	Vec3 ConvertRGBtoXYZ(Vec3 colorInRGB);
	Vec3 ConvertXYZtoRGB(Vec3 colorInXYZ);

	// Function to calculate saturation and dominant wavelength
	Vec3 CalculateSaturationAndDominantWavelength(Vec3 colorInXYZ);

	// Function to get the hue value
	double getHueFromXYZ(Vec3 colorInXYZ);

	// Function to update the spectral parameters
	void UpdateSpectralParameters();

	// Function to init the quad 
	void InitQuad();

	// Function to create the quad pipeline
	void createQuadGraphicsPipeline();

	// Function to create quad descriptor pool to create descriptor sets
	void createQuadDescriptorPool();

	// Function to create quad descriptor sets for each Vk Buffer
	void createQuadDescriptorSets();

	// Function to create quad Index Buffer
	void createQuadIndexBuffer();

	// Function to create quad Vertex Buffer
	void createQuadVertexBuffer();
	
	// function to create quad descriptor set layout to  provide the details about descriptor bindings in every shader
	void createQuadDescriptorSetLayout();

	// Function to generate instance data
	void GenerateInstanceData();
};

