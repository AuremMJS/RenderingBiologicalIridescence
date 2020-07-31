#pragma once

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

#define NO_OF_SHELLS 8
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

struct IridescentColors
{
	Vec4 colors[90];
};


struct Pixel {
	float r, g, b, a;
};

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

	bool shouldRegenerateTexture;
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
	TextureImage *textureImage;

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

	std::map<double, Vec3> ColorMatchingFunctionMap;

	std::map<std::string, double> HueAngleWavelengthMap;

	std::map<std::string, Vec3> HueAngleCoordMap;

	Matrix3 AMatrix;

	Vec3 FourierCoeffs;

	SpectralPipelineParameters spectralParameters;

	IridescentColors iridescentColors;

	// arcball for storing light rotation
	BallData lightBall;

	// arcball for storing object rotation
	BallData objectBall;

	bool isMouseDragged;

	int whichButton;

	// Vertices for Quad
	std::vector<Vertex> QuadVertices;

	// Indices for Quad
	std::vector<int> QuadIndices;

	// Descriptor Set Layout
	VkDescriptorSetLayout quadDescriptorSetLayout;

	// Pipeline layout - uniforms
	VkPipelineLayout quadPipelineLayout;

	// Graphics pipeline
	VkPipeline quadGraphicsPipeline;

	// Vertex Buffer
	Buffer *quadVertexBuffer;

	// Index Buffer
	Buffer *quadIndexBuffer;

	// Descriptor Pool to create descriptor sets for quad pipeline
	VkDescriptorPool quadDescriptorPool;

	// Descriptor sets to bind each VkBuffer to the uniform buffer descriptor of quad pipeline
	std::vector<VkDescriptorSet> quadDescriptorSets;

	// Reference Image
	TextureImage *refImage;

	std::vector<float> peakWavelengths;
public:
	static UIParameters uiParams;
	Application();
	~Application();
	void run();
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
	static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double x, double y);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void createInstance();
	void setupDebugMessenger();
	void createRenderPass();
	void createGraphicsPipeline();
	void createFramebuffers();
	void createDepthResources();
	VkFormat findDepthFormat();
	VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
	void createDescriptorPool();
	void createDescriptorSets();
	void createUniformBuffers();
	void createIndexBuffer();
	void createVertexBuffer();
	Mesh ParseObjFile(const char* filename);
	LightingConstants LoadMaterial(const char* filename);
	void createDescriptorSetLayout();
	void createCommandBuffers();
	void createSyncObjects();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
	static std::vector<char> readFile(const std::string& filename);
	VkShaderModule createShaderModule(const std::vector<char>& code);
	void drawFrame();
	void updateUniformBuffer(uint32_t currentImage);
	void updateLightingConstants(uint32_t currentImage);
	void recreateSwapChain();
	void cleanupSwapChain();
	void createComputePipeline();
	void createComputeDescriptorSet();
	void createComputeDescriptorPool();

	// function to create descriptor set layout for compute pipeline to  provide the details about descriptor bindings in every shader
	void createComputeDescriptorSetLayout();
	void createComputeCommandPool();
	void createComputeBuffers();
	void createComputeCommandBuffers();
	void runComputeCommandBuffer();
	void createTextureImageFromComputeBuffer();
	void FindMatrixA();
	void ReadColorMatchingXMLFile(const char* filename);
	void FindFourierCoefficients(Vec3 colorInXYZ);
	std::vector<double> ConstructSpectra();
	Vec3 GetXYZColorFromSpectra(std::vector<double> spectra);
	void ReadChromaticityXMLFile(const char* filename);
	Vec3 ConvertRGBtoXYZ(Vec3 colorInRGB);
	Vec3 ConvertRGBtoHSV(Vec3 colorInRGB);
	Vec3 ConvertXYZtoRGB(Vec3 colorInXYZ);
	Vec3 ConvertXYZtoHSV(Vec3 colorInXYZ);
	double getHueFromXYZ(Vec3 colorInXYZ);
	std::vector<double> ConstructSpectraGaussian(Vec3 hsv);
	void UpdateSpectralParameters();
	std::vector<double> ConstructIridescentSpectra(std::vector<double> inputSpectra);
	
	void InitQuad();
	void createQuadGraphicsPipeline();

	// Function to create descriptor pool to create descriptor sets
	void createQuadDescriptorPool();

	// Function to create descriptor sets for each Vk Buffer
	void createQuadDescriptorSets();

	// Function to create Index Buffer
	void createQuadIndexBuffer();
	// Function to create Vertex Buffer
	void createQuadVertexBuffer();
	// function to create descriptor set layout to  provide the details about descriptor bindings in every shader
	void createQuadDescriptorSetLayout();


	void prepareInstanceData();
};

