#pragma once

#include "Device.h"

class CommandPool
{
public:
	// Command Pool
	VkCommandPool commandPool;

	CommandPool(Device *device);
	~CommandPool();

	void createCommandPool(Device *device);
	VkCommandBuffer beginSingleTimeCommands(Device *device);
	void endSingleTimeCommands(Device *device, VkCommandBuffer commandBuffer);
	void Cleanup(Device *device);
};

