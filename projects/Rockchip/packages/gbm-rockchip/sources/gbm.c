
/* Enable 64-bit mmap also when compiling for 32 bit */
#define _FILE_OFFSET_BITS 64

#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <xf86drm.h>
#include "gbm.h"

void *
gbm_bo_map(struct gbm_bo *bo,
           uint32_t x, uint32_t y, uint32_t width, uint32_t height,
           uint32_t flags, uint32_t *stride, void **map_data)
{
    struct drm_mode_map_dumb mreq = {};
    struct gbm_device *device = gbm_bo_get_device(bo);
    int fd = gbm_device_get_fd(device);

    mreq.handle = gbm_bo_get_handle(bo).u32;
    int ret = drmIoctl(fd, DRM_IOCTL_MODE_MAP_DUMB, &mreq);
    if (ret)
        return MAP_FAILED;

    void *map = mmap(NULL, gbm_bo_get_stride(bo) * gbm_bo_get_height(bo), PROT_READ | PROT_WRITE, MAP_SHARED, fd, mreq.offset);
    if (map != MAP_FAILED) {
        *map_data = map;
        *stride = gbm_bo_get_stride(bo);
    }

    return map;
}

void
gbm_bo_unmap(struct gbm_bo *bo, void *map_data)
{
    if (map_data)
        munmap(map_data, gbm_bo_get_stride(bo) * gbm_bo_get_height(bo));
}
