#include <stdint.h>
#include <stdlib.h>

#define XDSIM_GATE
#include "xdsim-v0.h"

#include "bit.h"

void noop_drop(char *_) {}

void drop_single(void *ptr, uint64_t _) { free(ptr); }

struct TFlipFlop {
    bool state;
};

Slice gate_tick(GateMut gate, const struct GateTickRequest *request) {
    bool t = *(bool *)request->inputs.first;
    struct TFlipFlop *self = (struct TFlipFlop *)gate;

    if (t)
        self->state = !self->state;

    struct Bit *q = malloc(sizeof(*q));
    struct Bit *q_bar = malloc(sizeof(*q_bar));

    q->content = self->state;
    q_bar->content = !self->state;

    Data *outputs = malloc(sizeof(*outputs) * 2);
    outputs[0] = q;
    outputs[1] = q_bar;

    return (Slice){.first = outputs, .length = 2, .drop = drop_single};
}

Graphic gate_draw(Gate gate, const struct GateDrawRequest *request) {
    Element *elements = malloc(sizeof(*elements) * 2);

    // outline
    elements[0] = (Element){.tag = Element_Rect,
                            .rect = {
                                .pos =
                                    {
                                        .x = 0.0,
                                        .y = 0.0,
                                    },
                                .size =
                                    {
                                        .x = 1.0,
                                        .y = 1.0,
                                    },
                                .stroke = {.colour = {Colour_Black}},
                                .fill = {.colour = {Colour_Transparent}},
                            }};

    // yellow box indicating state
    elements[1] = (Element){.tag = Element_Rect,
                            .rect = {
                                .pos =
                                    {
                                        .x = 0.3,
                                        .y = 0.3,
                                    },
                                .size =
                                    {
                                        .x = 0.4,
                                        .y = 0.4,
                                    },
                                .stroke = {.colour = {Colour_Black}},
                                .fill = {.colour = {Colour_Yellow}},
                            }};

    return (Graphic){.elements = {elements}};
}

GateDefinition gate_def(Gate gate) {
    GateIOEntry *inputs = malloc(sizeof(*inputs));
    GateIOEntry *outputs = malloc(sizeof(*outputs) * 2);

    inputs[0] = (GateIOEntry){
        .name = {.first = "T", .drop = noop_drop},
        .data_type =
            {
                .package = {.first = "dummies", .drop = noop_drop},
                .component = {.first = "bit", .drop = noop_drop},
                .major = 0,
                .minor = 1,
                .patch = 0,
            },
        .position = {.x = 0, .y = 0.5},
    };

    outputs[0] = (GateIOEntry){
        .name = {.first = "Q", .drop = noop_drop},
        .data_type =
            {
                .package = {.first = "dummies", .drop = noop_drop},
                .component = {.first = "bit", .drop = noop_drop},
                .major = 0,
                .minor = 1,
                .patch = 0,
            },
        .position = {.x = 1, .y = 0.7},
    };
    outputs[1] = (GateIOEntry){
        .name = {.first = "QBar", .drop = noop_drop},
        .data_type =
            {
                .package = {.first = "dummies", .drop = noop_drop},
                .component = {.first = "bit", .drop = noop_drop},
                .major = 0,
                .minor = 1,
                .patch = 0,
            },
        .position = {.x = 1, .y = 0.3},
    };

    return (GateDefinition){
        .inputs = {inputs},
        .outputs = {outputs},
        .bounding_box = {.x = 1, .y = 1},
    };
}

PropertiesMut gate_props(GateMut gate) { return NULL; }

Slice gate_serialize(Gate gate) {
    bool *ptr = malloc(1);
    *ptr = ((struct TFlipFlop *)gate)->state;

    return (Slice){.first = ptr, .length = 1, .drop = drop_single};
}

GateMut gate_deserialize(const struct Slice *bytes) {
    struct TFlipFlop *ptr = malloc(sizeof(*ptr));
    ptr->state = *((uint8_t *)bytes->first);
    return ptr;
}

void gate_drop(GateMut gate) { free(gate); }

uint32_t schema_version() { return 0; }
