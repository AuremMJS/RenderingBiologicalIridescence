#pragma once
#include "Device.h"
#include "CommandPool.h"
#include "Swapchain.h"
class ImGuiHelper
{
public:
	// Descriptor Pool to create descriptor sets
	VkDescriptorPool imGUIDescriptorPool;

	int imGUI_MinImageCount = 2;

	// ImGUI Render pass
	VkRenderPass imGUIRenderPass;

	VkCommandPool imGuiCommandPool;

	std::vector<VkCommandBuffer> imGuiCommandBuffers;


	std::vector<VkFramebuffer> imGUIFramebuffers;

	ImGuiHelper(VkInstance *instance, GLFWwindow *window, Device *device, Swapchain *swapChain, CommandPool *commandPool);
	~ImGuiHelper();
	void InitImGUI(VkInstance *instance, GLFWwindow *window, Device *device, Swapchain *swapChain,CommandPool *commandPool);
	void createimGuiCommandPool(Device *device,  VkCommandPoolCreateFlags flags);
	void createimGuiCommandBuffers(Device *device, uint32_t commandBufferCount);
	void createImGUIRenderPass(Device *device, VkFormat swapChainImageFormat);
	void CreateImGuiFrameBuffer(Device *device, Swapchain *swapChain);

	void CreateImGUIDescriptorPool(Device *device);
	void CleanupImGUI(Device *device);
	void DrawImGUI(Device *device, void(*drawFunc)());
	void RenderImGUI(Device *device, VkExtent2D swapChainExtent, uint32_t imageIndex);
	void UpdateMinImageCount();
	static void check_vk_result(VkResult err);
};

