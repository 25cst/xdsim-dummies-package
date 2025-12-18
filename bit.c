#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define XDSIM_DATA
#include "xdsim-v0.h"

#include "bit.h"

void noop_drop(char *_) {}

void drop_single(void *ptr, uint64_t _) { free(ptr); }

struct ComponentHeader component_header(void) {
    return (struct ComponentHeader){
        .ident =
            {
                .package = {.first = "dummies", .drop = noop_drop},
                .component = {.first = "bit", .drop = noop_drop},
                .major = 0,
                .minor = 1,
                .patch = 0,
            },
        .component_type = ComponentType_Data,
        .description = {.first = "A dummy bit type.", .drop = noop_drop},
        .homepage = {.first = "https://github.com/25cst/xdsim-dummies-v0",
                     .drop = noop_drop}};
}

Slice data_serialize(Data data) {
    bool *ptr = malloc(1);
    *ptr = ((struct Bit *)data)->content;

    return (Slice){.first = ptr, .length = 1, .drop = drop_single};
}

Data data_deserialize(struct Slice bytes) {
    struct Bit *ptr = malloc(sizeof(*ptr));
    ptr->content = *((uint8_t *)bytes.first);
    return ptr;
}

void data_drop(DataMut data) { free(data); }

Data data_default() {
    struct Bit *ptr = malloc(sizeof(*ptr));
    ptr->content = false;
    return ptr;
}

uint32_t schema_version() {
    return 0;
}
