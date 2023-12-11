#pragma once

#include <vector>
#include <string>
#include <map>
#include <optional>
#include <set>
#include <cstdint> // Necessary for uint32_t

#include <fmt/core.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_vulkan.h>
#include <SDL2/SDL_image.h>

#include <vulkan/vk_platform.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>
#include <array>

void init();

void run();

void close();
