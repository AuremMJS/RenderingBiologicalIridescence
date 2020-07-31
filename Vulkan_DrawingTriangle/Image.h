#pragma once
#include "Device.h"
#include "CommandPool.h"
#include "Buffer.h"
class Image
{
public:
	// Texture Image
	VkImage image;

	// Memory for Texture Image
	VkDeviceMemory memory;

	// Texture Image View
	VkImageView imageView;

	Image(Device *device, uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImageAspectFlags aspectFlags, VkImageType type);
	~Image();

	void createImage(Device *device, uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImageType type);
	void createImageView(Device *device, VkFormat format, VkImageAspectFlags aspectFlags);
	void transitionImageLayout(Device *device, CommandPool *commandPool, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
	void copyBufferToImage(Device *device, CommandPool *commandPool, Buffer *buffer, uint32_t width, uint32_t height);
	void Cleanup(Device *device);
};

