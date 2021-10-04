#include "Buffer.h"

Buffer::Buffer(Device *device, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties) {
	VkBufferCreateInfo bufferInfo = {};
	bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	bufferInfo.size = size;
	bufferInfo.usage = usage;
	bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

	if (vkCreateBuffer(device->logicalDevice, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
		throw std::runtime_error("failed to create buffer!");
	}

	VkMemoryRequirements memRequirements;
	vkGetBufferMemoryRequirements(device->logicalDevice, buffer, &memRequirements);

	VkMemoryAllocateInfo allocInfo = {};
	allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	allocInfo.allocationSize = memRequirements.size;
	allocInfo.memoryTypeIndex = device->findMemoryType(memRequirements.memoryTypeBits, properties);

	if (vkAllocateMemory(device->logicalDevice, &allocInfo, nullptr, &memory) != VK_SUCCESS) {
		throw std::runtime_error("failed to allocate buffer memory!");
	}

	vkBindBufferMemory(device->logicalDevice, buffer, memory, 0);
}

Buffer::~Buffer()
{
	
}

void Buffer::Cleanup(Device * device)
{
	// Destroy the index buffer
	vkDestroyBuffer(device->logicalDevice, buffer, nullptr);

	// Free index buffer memory
	vkFreeMemory(device->logicalDevice, memory, nullptr);
}

void Buffer::SetData(Device *device, void *value,VkDeviceSize bufferSize)
{
	void* data;
	vkMapMemory(device->logicalDevice, memory, 0, bufferSize, 0, &data);
	memcpy(data, value, (size_t)bufferSize);
	vkUnmapMemory(device->logicalDevice, memory);
}

// Function to copy the contents from one buffer to another
void Buffer::copyBuffer(Device *device, CommandPool *commandPool, Buffer *srcBuffer, VkDeviceSize size) {
	VkCommandBuffer commandBuffer = commandPool->beginSingleTimeCommands(device);

	VkBufferCopy copyRegion = {};
	copyRegion.size = size;
	vkCmdCopyBuffer(commandBuffer, srcBuffer->buffer, buffer, 1, &copyRegion);

	commandPool->endSingleTimeCommands(device,commandBuffer);
}
