/*
 * Copyright © 2015 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef V3DVK_QUEUE_H
#define V3DVK_QUEUE_H

#include <vulkan/vk_icd.h>
#include "v3dvk_fence.h"


/* queue types */
#define V3DVK_QUEUE_GENERAL 0

#define V3DVK_MAX_QUEUE_FAMILIES 1

struct v3dvk_device;

struct v3dvk_queue {
    VK_LOADER_DATA                              _loader_data;

    struct v3dvk_device *                       device;

    VkDeviceQueueCreateFlags                    flags;
    struct v3dvk_fence                          submit_fence;
};

void
v3dvk_queue_init(struct v3dvk_device *device, struct v3dvk_queue *queue);

void
v3dvk_queue_finish(struct v3dvk_queue *queue);

#endif
